// Lowers string literals with `${...}` segments into a chain of builder
// intrinsics. Primitive segments keep the dedicated `builder.append_display`
// fast path (one bytecode op per primitive type — no allocation for the
// stringified form, and side-steps any recursion when a user overrides a
// primitive's Display impl with a body that itself interpolates `self`).
// Non-primitive segments route through `<T>.Display.to_string` (resolved
// statically) followed by `builder.append_str`, so user structs and enums
// share a single source of truth with explicit `.to_string()` calls.

import type * as A from "../../parser/ast.ts";
import type { Span } from "../../diagnostics/diagnostic.ts";
import type { Type } from "../../typecheck/types.ts";
import { TY, isPrimitive } from "../../typecheck/types.ts";

import type { FnLowerCtx } from "../ctx.ts";
import type { LoweredExpr, LoweredStmt } from "../lowered-ast.ts";
import { INTRINSICS } from "../lowered-ast.ts";

import { wrapAsDisplay } from "./display-coerce.ts";
import { lowerExpr } from "./expr.ts";
import { freshSyntheticSymbol } from "./helpers.ts";

/** True when `t` is one of the unsigned integer widths whose value range
 *  exceeds the signed `i64` carrier the Vader VM relies on. Routing these
 *  through an explicit `Display.to_string` call lets the VM dispatch to
 *  an unsigned stringifier instead of misreading the bit pattern as
 *  signed. The narrow `u8` / `u16` widths fit signed `i64` losslessly,
 *  so they keep the cheaper `builder.append_display` shortcut. */
function isWideUnsignedPrimitive(t: Type): boolean {
  return isPrimitive(t, "u32") || isPrimitive(t, "u64") || isPrimitive(t, "usize");
}

export function lowerStringLit(ctx: FnLowerCtx, expr: A.StringLitExpr): LoweredExpr {
  if (expr.parts.every((p) => p.kind === "text")) {
    let value = "";
    for (const part of expr.parts) if (part.kind === "text") value += part.value;
    return { kind: "LoweredStringLit", span: expr.span, type: TY.string, value };
  }

  // Build a chain of @builder.* intrinsics. The StringBuilder runtime type
  // isn't modelled in the type system yet; the bytecode emitter resolves the
  // concrete type when wiring `std/builder`.
  const sbSym = freshSyntheticSymbol(ctx, "sb");
  const sbType: Type = TY.unresolved;
  const sbRef = (span: Span): LoweredExpr =>
    ({ kind: "LoweredIdent", span, type: sbType, symbol: sbSym });

  const stmts: LoweredStmt[] = [{
    kind: "LoweredLet", span: expr.span, name: sbSym.name, symbol: sbSym, type: sbType,
    value: { kind: "LoweredIntrinsicCall", span: expr.span, type: sbType, name: INTRINSICS.builderNew, args: [] },
  }];

  for (const part of expr.parts) {
    if (part.kind === "text") {
      const lit: LoweredExpr = { kind: "LoweredStringLit", span: part.span, type: TY.string, value: part.value };
      stmts.push({
        kind: "LoweredExprStmt", span: part.span,
        expr: {
          kind: "LoweredIntrinsicCall", span: part.span, type: TY.void,
          name: INTRINSICS.builderAppendStr,
          args: [sbRef(part.span), lit],
        },
      });
    } else {
      const inner = lowerExpr(ctx, part.expr);
      const innerKind = inner.type.kind;
      // Primitives (incl. string) keep the per-type fast path. Everything
      // else routes through Display.to_string + builder.append_str so user
      // impls on structs / enums are honoured.
      //
      // Exception : unsigned wide widths whose range exceeds i64. The
      // Vader VM collapses all integer widths onto `I32Val` / `I64Val`,
      // both signed carriers — a `u64` literal whose bit pattern doesn't
      // fit signed-i64 (e.g. `18446744073700000000`) would print as a
      // negative i64. Routing `u64` through the explicit
      // `<u64>.Display.to_string` call gives the VM a mangled-name hook
      // (`std_core$u64$Display$to_string`) to choose the unsigned
      // stringifier ; native C-emit still inlines via the @intrinsic
      // impl so this is free at the C target.
      if (innerKind === "Primitive" && isWideUnsignedPrimitive(inner.type)) {
        const stringValue = wrapAsDisplay(ctx, inner, inner.type, part.span) ?? inner;
        stmts.push({
          kind: "LoweredExprStmt", span: part.span,
          expr: {
            kind: "LoweredIntrinsicCall", span: part.span, type: TY.void,
            name: INTRINSICS.builderAppendStr,
            args: [sbRef(part.span), stringValue],
          },
        });
        continue;
      }
      if (innerKind === "Primitive" || innerKind === "FreeInt" || innerKind === "FreeFloat") {
        stmts.push({
          kind: "LoweredExprStmt", span: part.span,
          expr: {
            kind: "LoweredIntrinsicCall", span: part.span, type: TY.void,
            name: INTRINSICS.builderAppendDisplay,
            args: [sbRef(part.span), inner],
            displayFor: inner.type,
          },
        });
        continue;
      }
      const stringValue = wrapAsDisplay(ctx, inner, inner.type, part.span) ?? inner;
      stmts.push({
        kind: "LoweredExprStmt", span: part.span,
        expr: {
          kind: "LoweredIntrinsicCall", span: part.span, type: TY.void,
          name: INTRINSICS.builderAppendStr,
          args: [sbRef(part.span), stringValue],
        },
      });
    }
  }

  return {
    kind: "LoweredBlock", span: expr.span, type: TY.string,
    stmts,
    trailing: {
      kind: "LoweredIntrinsicCall", span: expr.span, type: TY.string,
      name: INTRINSICS.builderFinish, args: [sbRef(expr.span)],
    },
  };
}
