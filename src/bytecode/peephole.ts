// Bytecode peephole optimizations.
//
// Run as a single linear scan after each fn body is emitted. All transforms
// here are sound because:
//   - Vader's `br` / `br_if` use depth (label-stack relative), not absolute
//     op indices, so removing or rewriting ops never invalidates branch
//     targets.
//   - Each transform preserves the value-stack shape across the rewrite,
//     so downstream verifier / VM / C-emit see the same effective operation.
//
// All transforms are gated by a single `optimize` flag plumbed through
// `emitBytecode` (default on; CLI exposes `--no-bytecode-opt`).
//
// Current rules:
//   1. `local.set N; local.get N`            → `local.tee N`
//   2. `<num>.<cmp>; bool.not`               → `<num>.<inverse cmp>`
//   3. `bool.const X; bool.not`              → `bool.const !X`
//   4. `bool.not; bool.not`                  → ε

import type { Op } from "./ops.ts";
import type { DebugPos } from "./module.ts";

const INVERSE_VERB: Record<string, string> = {
  lt: "ge", le: "gt", gt: "le", ge: "lt",
  eq: "ne", ne: "eq",
};

interface MutFn {
  body: Op[];
  debug: (DebugPos | null)[];
}

export function runPeepholes(fn: MutFn): void {
  const out: Op[] = [];
  const dbg: (DebugPos | null)[] = [];
  for (let i = 0; i < fn.body.length; i++) {
    const op = fn.body[i]!;
    const span = fn.debug[i]!;

    // Bool-folding rules (2/3/4) all fire on `bool.not` paired with the
    // previous op. Single guard, dispatch on `prev.kind`.
    if (op.kind === "bool.not" && out.length > 0) {
      const prev = out[out.length - 1]!;
      if (prev.kind === "bool.not") {                                 // Rule 4
        out.pop(); dbg.pop(); continue;
      }
      if (prev.kind === "bool.const") {                               // Rule 3
        out[out.length - 1] = { kind: "bool.const", value: !prev.value };
        continue;
      }
      const inv = invertCmp(prev);                                    // Rule 2
      if (inv !== null) { out[out.length - 1] = inv; continue; }
    }

    // Rule 1 — `local.set N; local.get N` → `local.tee N`.
    if (op.kind === "local.set") {
      const next = fn.body[i + 1];
      if (next?.kind === "local.get" && next.slot === op.slot) {
        out.push({ kind: "local.tee", slot: op.slot });
        dbg.push(span);
        i++;
        continue;
      }
    }

    out.push(op);
    dbg.push(span);
  }
  fn.body.length = 0;
  fn.body.push(...out);
  fn.debug.length = 0;
  fn.debug.push(...dbg);
}

/** If `op` is a `<type>.<verb>` shape with `verb ∈ {lt,le,gt,ge,eq,ne}`,
 *  return the inverse-verb op. Returns null otherwise. The `as Op` cast is
 *  safe because `<type>` came from a real `CmpOpKind` (every numeric width
 *  has all 6 inverses; `bool`/`string`/`char`/`ref` only have eq/ne — both
 *  closed under inversion in INVERSE_VERB). */
function invertCmp(op: Op): Op | null {
  const kind = op.kind;
  const dot = kind.indexOf(".");
  if (dot < 0) return null;
  const verb = kind.slice(dot + 1);
  const inv = INVERSE_VERB[verb];
  if (inv === undefined) return null;
  return { kind: `${kind.slice(0, dot)}.${inv}` } as Op;
}
