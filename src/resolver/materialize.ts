// Synthetic-member materialisation + AST substitution helpers used by the
// resolver when an impl block omits methods the trait declares.
//
// Three flavours of synthesis :
//   - `materializeIntrinsicMembers` : an `@intrinsic` impl with an empty
//     body — fill in stubs for each trait method so downstream phases see
//     the impl's full surface.
//   - `materializeDefaultMembers` : trait methods that carry a default
//     body — inject a deep-cloned copy into impls that didn't override.
//   - `materializeSamMembers` : single-method trait sugar
//     (`Foo implements Trait -> expr`) — fill in `name`/`params`/`returnType`
//     on the parser-fabricated synthetic FnDecl from the trait's single
//     required method.
//
// All three reuse the same `Self → forType` + trait-type-param → impl-arg
// substitution machinery (`substituteTypeExpr`, `substituteIdentsInBlock`).
// The substitution walker mutates the cloned tree in place ; callers pass
// `structuredClone(method.body)` for bodies so the trait's original AST
// stays untouched.

import type * as A from "../parser/ast.ts";
import { UNASSIGNED_NODE_ID } from "../parser/ast.ts";
import { err } from "./diag.ts";
import type { ResolveModuleInput } from "./resolve.ts";

export function materializeIntrinsicMembers(decl: A.ImplDecl, trait: A.TraitDecl): void {
  const isIntrinsic = decl.decorators.some((d) => d.name === "intrinsic");
  if (!isIntrinsic || decl.members.length > 0) return;
  const subst = new Map<string, A.TypeExpr>();
  subst.set("Self", decl.forType);
  for (let i = 0; i < trait.typeParams.length && i < decl.traitArgs.length; i++) {
    subst.set(trait.typeParams[i]!.name, decl.traitArgs[i]!);
  }
  // Mutate through the readonly slot — the AST keeps `members` readonly to
  // prevent accidental writes from typecheck/lower passes ; the resolver is
  // the only writer.
  const slot = decl.members as A.FnDecl[];
  for (const method of trait.members) {
    slot.push({
      kind: "FnDecl",
      id: UNASSIGNED_NODE_ID, span: decl.span,
      name: method.name,
      nameSpan: decl.traitNameSpan,
      visibility: "public",
      typeParams: [],
      params: method.params.map((mp) => ({
        id: UNASSIGNED_NODE_ID,
        span: decl.span,
        name: mp.name,
        type: mp.type !== null ? substituteTypeExpr(mp.type, subst) : null,
        defaultValue: mp.defaultValue,
        variadic: mp.variadic,
      })),
      returnType: method.returnType !== null
        ? substituteTypeExpr(method.returnType, subst) : null,
      body: null,
      decorators: [{ id: UNASSIGNED_NODE_ID, span: decl.span, name: "intrinsic", args: [] }],
    });
  }
}

/** Layer 8d — inject default-bearing trait methods the impl didn't override.
 *  For every trait member with a body, if no user-provided member with the
 *  same name lives in the impl yet, push a fresh FnDecl whose body is a deep
 *  clone of the trait's. The clone is `structuredClone`-based so the AST node
 *  identities are fresh — the resolver's per-node side-tables stay distinct
 *  between the trait's own resolution and each impl's injected copy.
 *
 *  Signature *and* body are substituted via the same `Self → forType` /
 *  trait-type-param → impl-trait-arg map. Body substitution rewrites every
 *  IdentExpr whose name is a key in the map ; this is safe in trait method
 *  bodies because trait type-params and `Self` only meaningfully appear in
 *  type-position uses (match patterns, struct lits, casts, typed lets) where
 *  collisions with value-level locals don't occur. References to other
 *  trait methods (`self.equals(other)` from a default `not_equals`) resolve
 *  through UFCS against the impl's scope, picking up the impl's own member
 *  when present. */
export function materializeDefaultMembers(decl: A.ImplDecl, trait: A.TraitDecl): void {
  // Trait has no defaults at all — common case, return without allocating.
  if (!trait.members.some((m) => m.body !== null)) return;
  const provided = new Set<string>();
  for (const m of decl.members) provided.add(m.name);
  const subst = new Map<string, A.TypeExpr>();
  subst.set("Self", decl.forType);
  for (let i = 0; i < trait.typeParams.length && i < decl.traitArgs.length; i++) {
    subst.set(trait.typeParams[i]!.name, decl.traitArgs[i]!);
  }
  const slot = decl.members as A.FnDecl[];
  for (const method of trait.members) {
    if (method.body === null) continue;
    if (provided.has(method.name)) continue;
    slot.push({
      kind: "FnDecl",
      id: UNASSIGNED_NODE_ID, span: decl.span,
      name: method.name,
      nameSpan: decl.traitNameSpan,
      visibility: "public",
      typeParams: [],
      params: method.params.map((mp) => ({
        id: UNASSIGNED_NODE_ID,
        span: decl.span,
        name: mp.name,
        type: mp.type !== null ? substituteTypeExpr(mp.type, subst) : null,
        defaultValue: mp.defaultValue,
        variadic: mp.variadic,
      })),
      returnType: method.returnType !== null
        ? substituteTypeExpr(method.returnType, subst) : null,
      body: substituteIdentsInBlock(structuredClone(method.body), subst),
      decorators: [],
      isExpressionBodied: method.isExpressionBodied,
    });
  }
}

/** Fill in `name`, `params`, and `returnType` on each SAM-synthetic member of
 *  `decl` from the trait's single method, applying the trait-arg substitution
 *  at the TypeExpr level so the body type-checks against concrete types. */
export function materializeSamMembers(
  decl: A.ImplDecl, trait: A.TraitDecl, input: ResolveModuleInput,
): void {
  const synthetics = decl.members.filter((m) => m.samSynthetic !== undefined);
  if (synthetics.length === 0) return;
  // Only methods *without* a default body count as "required" for the
  // single-method-trait gate — Layer 8d defaults fill the rest in. So a
  // trait like `Equals { equals ; not_equals = !self.equals }` still
  // accepts the SAM form for `equals`.
  const required = trait.members.filter((m) => m.body === null);
  if (required.length !== 1) {
    for (const fn of synthetics) {
      err(input.diags, "R2016", fn.span,
        `\`${decl.traitName}\` has ${required.length} required methods`);
    }
    if (required.length === 0) return;
    // Fall through with `required[0]` to keep the body resolvable and avoid
    // a T3020 cascade — the primary R2016 is already emitted.
  }
  const method = required[0]!;
  const subst = new Map<string, A.TypeExpr>();
  subst.set("Self", decl.forType);
  for (let i = 0; i < trait.typeParams.length && i < decl.traitArgs.length; i++) {
    subst.set(trait.typeParams[i]!.name, decl.traitArgs[i]!);
  }
  for (const fn of synthetics) {
    fn.name = method.name;
    fn.params = method.params.map((mp) => ({
      id: UNASSIGNED_NODE_ID,
      span: fn.span,
      name: mp.name,
      type: mp.type !== null ? substituteTypeExpr(mp.type, subst) : null,
      defaultValue: mp.defaultValue,
      variadic: mp.variadic,
    }));
    fn.returnType = method.returnType !== null
      ? substituteTypeExpr(method.returnType, subst) : null;
  }
}

// =============================================================================
// AST substitution machinery — walks a cloned tree and replaces every IdentExpr
// whose name is a key in the subst map. Mutates in place (caller passes a
// `structuredClone`). Type-position rewrites flow through `substituteTypeExpr`.
// =============================================================================

// Cast helper — strips the `readonly` modifier from AST node fields so the
// walker can mutate the cloned tree in place. structuredClone produces plain
// JS objects whose fields are runtime-mutable ; the `readonly` declaration
// only exists at the type level.
type Mut<T> = { -readonly [K in keyof T]: T[K] };
const mut = <T,>(v: T): Mut<T> => v as Mut<T>;

function substituteIdentsInBlock(block: A.BlockExpr, subst: ReadonlyMap<string, A.TypeExpr>): A.BlockExpr {
  for (const stmt of block.stmts) substituteIdentsInStmt(stmt, subst);
  if (block.trailing !== null) mut(block).trailing = substituteIdentsInExpr(block.trailing, subst);
  return block;
}

function substituteIdentsInStmt(stmt: A.Stmt, subst: ReadonlyMap<string, A.TypeExpr>): void {
  switch (stmt.kind) {
    case "LetStmt": {
      const m = mut(stmt);
      if (m.type !== null) m.type = substituteTypeExpr(m.type, subst);
      m.value = substituteIdentsInExpr(stmt.value, subst);
      return;
    }
    case "AssignStmt": {
      const m = mut(stmt);
      m.target = substituteIdentsInExpr(stmt.target, subst);
      m.value = substituteIdentsInExpr(stmt.value, subst);
      return;
    }
    case "ExprStmt":
      mut(stmt).expr = substituteIdentsInExpr(stmt.expr, subst);
      return;
    case "ReturnStmt":
      if (stmt.value !== null) mut(stmt).value = substituteIdentsInExpr(stmt.value, subst);
      return;
    case "ForStmt": {
      const f = mut(stmt.form);
      if (f.kind === "while") f.cond = substituteIdentsInExpr(f.cond, subst);
      else if (f.kind === "in")  f.iter = substituteIdentsInExpr(f.iter, subst);
      mut(stmt).body = substituteIdentsInBlock(stmt.body, subst);
      return;
    }
    case "DeferStmt": {
      // body is `Stmt | BlockExpr` — recurse appropriately.
      if (stmt.body.kind === "BlockExpr") {
        mut(stmt).body = substituteIdentsInBlock(stmt.body, subst);
      } else {
        substituteIdentsInStmt(stmt.body, subst);
      }
      return;
    }
    case "BreakStmt":
    case "ContinueStmt":
      return;
  }
}

function substituteIdentsInExpr(expr: A.Expr, subst: ReadonlyMap<string, A.TypeExpr>): A.Expr {
  switch (expr.kind) {
    case "IdentExpr": {
      const repl = subst.get(expr.name);
      return repl !== undefined ? cloneTypeExpr(repl) : expr;
    }
    case "GenericInstExpr": {
      const m = mut(expr);
      m.callee = substituteIdentsInExpr(expr.callee, subst);
      m.typeArgs = expr.typeArgs.map((ta) => substituteTypeExpr(ta, subst));
      return expr;
    }
    case "CallExpr": {
      const m = mut(expr);
      m.callee = substituteIdentsInExpr(expr.callee, subst);
      for (const a of expr.args) mut(a).value = substituteIdentsInExpr(a.value, subst);
      return expr;
    }
    case "FieldExpr":
      mut(expr).target = substituteIdentsInExpr(expr.target, subst);
      return expr;
    case "IndexExpr": {
      const m = mut(expr);
      m.target = substituteIdentsInExpr(expr.target, subst);
      m.index = substituteIdentsInExpr(expr.index, subst);
      return expr;
    }
    case "UnaryExpr":
      mut(expr).operand = substituteIdentsInExpr(expr.operand, subst);
      return expr;
    case "BinaryExpr": {
      const m = mut(expr);
      m.left = substituteIdentsInExpr(expr.left, subst);
      m.right = substituteIdentsInExpr(expr.right, subst);
      return expr;
    }
    case "IfExpr": {
      const m = mut(expr);
      m.cond = substituteIdentsInExpr(expr.cond, subst);
      m.then = substituteIdentsInBlock(expr.then, subst);
      if (m.else !== null) {
        m.else = m.else.kind === "BlockExpr"
          ? substituteIdentsInBlock(m.else, subst)
          : substituteIdentsInExpr(m.else, subst) as A.IfExpr;
      }
      return expr;
    }
    case "MatchExpr": {
      const m = mut(expr);
      m.scrutinee = substituteIdentsInExpr(expr.scrutinee, subst);
      for (const arm of expr.arms) {
        substituteIdentsInPattern(arm.pattern, subst);
        const am = mut(arm);
        if (arm.guard !== null) am.guard = substituteIdentsInExpr(arm.guard, subst);
        am.body = substituteIdentsInExpr(arm.body, subst);
      }
      return expr;
    }
    case "BlockExpr":
      return substituteIdentsInBlock(expr, subst);
    case "LambdaExpr": {
      const m = mut(expr);
      if (m.returnType !== null) m.returnType = substituteTypeExpr(m.returnType, subst);
      for (const p of expr.params) {
        const pm = mut(p);
        if (p.type !== null) pm.type = substituteTypeExpr(p.type, subst);
        if (p.defaultValue !== null) pm.defaultValue = substituteIdentsInExpr(p.defaultValue, subst);
      }
      m.body = substituteIdentsInBlock(expr.body, subst);
      return expr;
    }
    case "StructLitExpr": {
      const m = mut(expr);
      m.typeName = substituteTypeExpr(expr.typeName, subst);
      for (const it of expr.items) {
        if (it.kind === "field") mut(it).value = substituteIdentsInExpr(it.value, subst);
        else mut(it).expr = substituteIdentsInExpr(it.expr, subst);
      }
      return expr;
    }
    case "SeqLitExpr":
      mut(expr).elements = expr.elements.map((e) => substituteIdentsInExpr(e, subst));
      return expr;
    case "RangeExpr": {
      const m = mut(expr);
      m.lower = substituteIdentsInExpr(expr.lower, subst);
      m.upper = substituteIdentsInExpr(expr.upper, subst);
      return expr;
    }
    case "TryExpr":
      mut(expr).inner = substituteIdentsInExpr(expr.inner, subst);
      return expr;
    case "CastExpr": {
      const m = mut(expr);
      m.target = substituteTypeExpr(expr.target, subst);
      m.value = substituteIdentsInExpr(expr.value, subst);
      return expr;
    }
    case "IntrinsicCallExpr":
      mut(expr).args = expr.args.map((a) => substituteIdentsInExpr(a, subst));
      return expr;
    case "StringLitExpr":
      for (const part of expr.parts) {
        if (part.kind === "interp") mut(part).expr = substituteIdentsInExpr(part.expr, subst);
      }
      return expr;
    // Leaves — no children to recurse into.
    case "IntLitExpr":
    case "FloatLitExpr":
    case "BoolLitExpr":
    case "NullLitExpr":
    case "CharLitExpr":
    case "DotVariantExpr":
    case "ArrayTypeExpr":
    case "FnTypeExpr":
      return expr;
  }
}

function substituteIdentsInPattern(pat: A.Pattern, subst: ReadonlyMap<string, A.TypeExpr>): void {
  switch (pat.kind) {
    case "IsPattern":
      mut(pat).type = substituteTypeExpr(pat.type, subst);
      if (pat.inner !== null) substituteIdentsInPattern(pat.inner, subst);
      return;
    case "StructPattern":
      for (const f of pat.fields) {
        if (f.value.kind === "literal") mut(f.value).value = substituteIdentsInExpr(f.value.value, subst);
      }
      return;
    case "TuplePattern":
      for (const e of pat.elements) substituteIdentsInPattern(e, subst);
      return;
    case "BindingPattern":
    case "WildcardPattern":
    case "EnumVariantPattern":
      return;
  }
}

/** Clone a TypeExpr tree, replacing any name-reference (`IdentExpr` at the
 *  type level) whose name matches a key in `subst` with a clone of the
 *  corresponding replacement. Cloning is required so the resolver records
 *  its own per-impl side-table entries rather than overwriting the trait's. */
export function substituteTypeExpr(expr: A.TypeExpr, subst: ReadonlyMap<string, A.TypeExpr>): A.TypeExpr {
  switch (expr.kind) {
    case "IdentExpr": {
      const replacement = subst.get(expr.name);
      if (replacement !== undefined) return cloneTypeExpr(replacement);
      return { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: expr.span, name: expr.name };
    }
    case "BinaryExpr":
      // Type-position `bitor` chain (1.B.5 union form). Recursively
      // substitute both operands, preserving the chain structure.
      return { kind: "BinaryExpr", id: UNASSIGNED_NODE_ID, span: expr.span, op: expr.op,
        left: substituteTypeExpr(expr.left as A.TypeExpr, subst),
        right: substituteTypeExpr(expr.right as A.TypeExpr, subst) };
    case "FnTypeExpr":
      return { kind: "FnTypeExpr", id: UNASSIGNED_NODE_ID, span: expr.span,
        params: expr.params.map((par) => substituteTypeExpr(par, subst)),
        returnType: expr.returnType !== null ? substituteTypeExpr(expr.returnType, subst) : null };
    case "ArrayTypeExpr":
      return { kind: "ArrayTypeExpr", id: UNASSIGNED_NODE_ID, span: expr.span,
        element: substituteTypeExpr(expr.element, subst) };
    case "SeqLitExpr":
      // Bracketed type tuple `[T1, T2, ...]` — same shape as the value-level
      // sequence literal since 1.B.3. In type position the elements are
      // guaranteed to be TypeExprs by the parser ; cast is safe.
      return { kind: "SeqLitExpr", id: UNASSIGNED_NODE_ID, span: expr.span,
        elements: expr.elements.map((e) => substituteTypeExpr(e as A.TypeExpr, subst)) };
    case "GenericInstExpr": {
      // In type position, the callee is always an IdentExpr (parser invariant).
      // The shape is widened to `Expr` because of the merge with the value-level
      // `GenericInstExpr`, but here it's safe to assume IdentExpr.
      const baseIdent = expr.callee.kind === "IdentExpr" ? expr.callee : null;
      return { kind: "GenericInstExpr", id: UNASSIGNED_NODE_ID, span: expr.span,
        callee: baseIdent !== null
          ? { kind: "IdentExpr", id: UNASSIGNED_NODE_ID, span: baseIdent.span, name: baseIdent.name }
          : expr.callee,
        typeArgs: expr.typeArgs.map((a) => substituteTypeExpr(a, subst)) };
    }
    default:
      // Layer 1.D — `TypeExpr` is now an alias for `Expr`, so this function
      // formally accepts any expression. Today the resolver only reaches this
      // helper through type-position walks where the parser produces only the
      // type-shaped variants above ; reaching the default is an internal bug.
      // Returning the input unchanged is a best-effort fallback that avoids a
      // hard crash if some future caller hits this path before Layer 4-sugar
      // generalises the substitution to arbitrary expressions.
      return expr;
  }
}

function cloneTypeExpr(expr: A.TypeExpr): A.TypeExpr {
  return substituteTypeExpr(expr, NO_SUBST);
}
const NO_SUBST: ReadonlyMap<string, A.TypeExpr> = new Map();
