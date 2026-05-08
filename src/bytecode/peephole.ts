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
//   5. Dead-store elimination on tail-slots — if a local is never read after
//      every rule above settles, drop its writes (`local.set` → `drop`,
//      `local.tee` → ε) and remove the slot from the locals list. Slots are
//      renumbered so surviving `local.{get,set,tee}` indices stay dense.
//      Massive savings on the CFG-emit path which materialises every sub-
//      expression into a tmp slot — most of those become dead after rule 1.

import type { Op } from "./ops.ts";
import type { BcLocal, DebugPos } from "./module.ts";

const INVERSE_VERB: Record<string, string> = {
  lt: "ge", le: "gt", gt: "le", ge: "lt",
  eq: "ne", ne: "eq",
};

interface MutFn {
  body: Op[];
  debug: (DebugPos | null)[];
  locals: BcLocal[];
  signature: { readonly params: readonly unknown[] };
}

export function runPeepholes(fn: MutFn): void {
  applyLocalRules(fn);
  dropDeadStores(fn);
}

function applyLocalRules(fn: MutFn): void {
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

/** Rule 5 — eliminate locals whose only references are writes. After
 *  `applyLocalRules` collapses every `set N ; get N` adjacency into a tee,
 *  the CFG-emit path leaves long tails of dead `local.tee N` (the value
 *  stays on stack for the next op, but the local itself is never read).
 *  We drop those writes and shrink the locals table so the C emit stops
 *  declaring slots no one consumes. */
function dropDeadStores(fn: MutFn): void {
  const paramCount = fn.signature.params.length;
  const totalSlots = paramCount + fn.locals.length;
  const reads = new Array<number>(totalSlots).fill(0);
  for (const op of fn.body) {
    if (op.kind === "local.get") reads[op.slot]!++;
  }

  // Param slots stay alive even when unread — the ABI keeps their slot index
  // pinned at 0..N-1. Local slots become "dead" iff reads === 0.
  const dead = new Array<boolean>(totalSlots).fill(false);
  let anyDead = false;
  for (let s = paramCount; s < totalSlots; s++) {
    if (reads[s] === 0) { dead[s] = true; anyDead = true; }
  }
  if (!anyDead) return;

  // Build slot remap : surviving slots stay dense from 0 upward.
  const remap = new Array<number>(totalSlots).fill(-1);
  let next = 0;
  for (let s = 0; s < totalSlots; s++) if (!dead[s]) remap[s] = next++;

  // Rewrite the body : drop dead writes, renumber surviving accesses.
  const out: Op[] = [];
  const dbg: (DebugPos | null)[] = [];
  for (let i = 0; i < fn.body.length; i++) {
    const op = fn.body[i]!;
    const span = fn.debug[i]!;
    if (op.kind === "local.set" && dead[op.slot]) {
      out.push({ kind: "drop" });
      dbg.push(span);
      continue;
    }
    if (op.kind === "local.tee" && dead[op.slot]) {
      // tee = set + push. With set dead, we just leave the value on stack —
      // the consumer reads it directly.
      continue;
    }
    if (op.kind === "local.get" || op.kind === "local.set" || op.kind === "local.tee") {
      out.push({ kind: op.kind, slot: remap[op.slot]! });
      dbg.push(span);
      continue;
    }
    out.push(op);
    dbg.push(span);
  }
  fn.body.length = 0;
  fn.body.push(...out);
  fn.debug.length = 0;
  fn.debug.push(...dbg);

  // Compact the locals list. Param slots are not in `fn.locals` (they live
  // in `signature.params`), so we only filter the per-fn locals tail.
  const newLocals: BcLocal[] = [];
  for (let s = paramCount; s < totalSlots; s++) {
    if (!dead[s]) newLocals.push(fn.locals[s - paramCount]!);
  }
  fn.locals.length = 0;
  fn.locals.push(...newLocals);
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
