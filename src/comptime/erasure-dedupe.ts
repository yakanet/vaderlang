// Erasure pass — option (b) post-process of `monomorphizeProject` output.
// See `docs/STDLIB_GENERIC_COLLAPSE_PHASE2.md` §11.
//
// `monomorphizeProject` produces concrete `MonoEntry` per `(decl,
// typeArgs)` instance. This pass groups entries by their origin `decl`,
// and for each non-`@specialize`d generic group collapses N entries into
// ONE representative whose `subst` sends every type-parameter to
// `TY.any`. The original `typeArgs` are kept (carrying the first
// instance's concrete args) for diagnostic / mangled-name purposes ; the
// `subst` is the source of truth the lower uses to substitute the body.
//
// Three lookup maps (`lookupByInstance`, `implMethodEntries`,
// `fnInstanceEntries`) are rebuilt to redirect every concrete-args query
// to the representative.

import type * as A from "../parser/ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import type { TypedProject } from "../typecheck/typed-ast.ts";
import { TY, type Substitution, type Type } from "../typecheck/types.ts";

import { ERASED_KEY, isSpecialized, type MonoEntry, type MonoProject } from "./specialize.ts";

/** Wraps a TypedProject + ResolvedProgram so the pass can resolve a
 *  member FnDecl back to its owning impl's host struct (needed to
 *  inherit `@specialize` from the host). */
interface DedupeCtx {
  /** Maps a member FnDecl → its owning ImplDecl. Populated once at the
   *  start of the pass by walking every module's decls. */
  readonly memberToImpl: Map<A.FnDecl, A.ImplDecl>;
  /** Maps a struct/trait NAME → the StructDecl carrying it. Used to
   *  resolve `impl.forType.name` to its host decl. */
  readonly structByName: Map<string, A.StructDecl>;
}

function buildDedupeCtx(project: TypedProject): DedupeCtx {
  const memberToImpl = new Map<A.FnDecl, A.ImplDecl>();
  const structByName = new Map<string, A.StructDecl>();
  for (const m of project.modules.values()) {
    for (const decl of m.resolved.source.decls) {
      if (decl.kind === "ImplDecl") {
        for (const member of decl.members) memberToImpl.set(member, decl);
      } else if (decl.kind === "StructDecl") {
        structByName.set(decl.name, decl);
      }
    }
  }
  return { memberToImpl, structByName };
}

/** True iff `entry`'s group of `(decl, typeArgs)` entries should be
 *  collapsed to a single Any-substituted representative. Criteria:
 *  - the decl carries no `@specialize` decorator (struct or fn decls
 *    carry it directly ; impl members inherit from their host struct),
 *  - the entry is genuinely generic (`typeArgs.length > 0`). */
function shouldErase(entry: MonoEntry, ctx: DedupeCtx): boolean {
  if (entry.typeArgs.length === 0) return false;
  const d = entry.decl;
  if (isSpecialized(d as { decorators?: readonly { name: string }[] })) return false;
  if (d.kind !== "FnDecl") return true;
  // Member FnDecls inherit @specialize from their owning impl's host
  // struct — `ArrayIterator[T] implements Iterator[T] { … }` member
  // methods stay specialised because the host `ArrayIterator` is tagged.
  const impl = ctx.memberToImpl.get(d);
  if (impl === undefined) return true;     // free generic fn
  const host = resolveHostStruct(impl, ctx);
  if (host !== null && isSpecialized(host)) return false;
  return true;
}

function resolveHostStruct(impl: A.ImplDecl, ctx: DedupeCtx): A.StructDecl | null {
  const t = impl.forType;
  if (t.kind === "IdentExpr") return ctx.structByName.get(t.name) ?? null;
  if (t.kind === "GenericInstExpr" && t.callee.kind === "IdentExpr") {
    return ctx.structByName.get(t.callee.name) ?? null;
  }
  return null;
}

/** Build a Substitution mapping each of `decl`'s type-parameters to
 *  `TY.any`. Mirrors `anySubst` in `specialize.ts` (kept private there
 *  for the in-pass erasure path ; replicated here to avoid an extra
 *  cross-module export). */
function anySubstForEntry(entry: MonoEntry): Substitution {
  const map = new Map<number, Type>();
  const src = entry.subst.typeParams;
  if (src !== undefined) {
    for (const [sym, _] of src) {
      map.set(sym, TY.any);
    }
  }
  return { typeParams: map };
}

/** Produce the Any-substituted representative for a group. Reuses the
 *  first entry's `id`, `mangled`, `symbol`, `module` ; overrides `subst`
 *  with the all-Any mapping. `typeArgs` is replaced with `[Any, Any, …]`
 *  so downstream diagnostics see the erased shape. */
function makeRepresentative(first: MonoEntry): MonoEntry {
  const erasedArgs: Type[] = first.typeArgs.map(() => TY.any);
  return {
    id: first.id,
    isMain: first.isMain,
    mangled: first.mangled,
    decl: first.decl,
    symbol: first.symbol,
    subst: anySubstForEntry(first),
    typeArgs: erasedArgs,
    module: first.module,
  };
}

/** Rewrite a per-FnDecl-per-argsKey lookup map so every value that was
 *  collapsed into a representative points at the representative — but
 *  preserve the original `typeArgs` on each redirected entry. Downstream
 *  consumers (notably `collectVtableEntries` in `src/lower/lower.ts`)
 *  read `typeArgs` to materialise per-concrete-tag vtable rows ; if we
 *  replaced the entry with the representative wholesale, every row
 *  would be keyed on `(struct, [Any, Any, ...])` and runtime dispatch
 *  on a concrete receiver tag (Range(i32), MutableMap(string, User), …)
 *  would miss. Symbol is redirected to the representative's symbol so
 *  the bytecode `fnIndexBySymId` lookup resolves. */
function redirectInner(
  src: ReadonlyMap<A.FnDecl, ReadonlyMap<string, MonoEntry>>,
  replacements: ReadonlyMap<MonoEntry, MonoEntry>,
): Map<A.FnDecl, Map<string, MonoEntry>> {
  const out = new Map<A.FnDecl, Map<string, MonoEntry>>();
  for (const [fnDecl, inner] of src) {
    const newInner = new Map<string, MonoEntry>();
    let representative: MonoEntry | null = null;
    for (const [k, entry] of inner) {
      const target = replacements.get(entry);
      if (target !== undefined) {
        // Redirect symbol but keep this entry's typeArgs so the
        // vtable-entry collector can stamp a row per concrete shape.
        newInner.set(k, { ...entry, symbol: target.symbol });
        representative = target;
      } else {
        newInner.set(k, entry);
      }
    }
    if (representative !== null) newInner.set(ERASED_KEY, representative);
    out.set(fnDecl, newInner);
  }
  return out;
}

export function erasureDedupe(mono: MonoProject, project: TypedProject): MonoProject {
  const ctx = buildDedupeCtx(project);

  // Group entries by origin decl, separating struct entries from the rest.
  // Struct entries get a different treatment : their LAYOUT is unified to
  // all-Any fields (so the lower emits a single uniform shape), but their
  // IDENTITY is preserved (each concrete instantiation keeps its own
  // MonoEntry and mangled name → distinct BcType tag at runtime). This is
  // what lets virtual dispatch on `Repeat(i32)` find the right vtable row
  // : the receiver carries the Repeat(i32) tag, vtable maps Repeat(i32) →
  // representative fn (via the per-shape rows kept by `redirectInner`).
  const groups = new Map<MonoEntry["decl"], MonoEntry[]>();
  for (const entry of mono.entries) {
    let g = groups.get(entry.decl);
    if (g === undefined) { g = []; groups.set(entry.decl, g); }
    g.push(entry);
  }

  // For each erasable FN group, build a single representative + replacement
  // map (each member entry → representative). Struct groups don't dedupe ;
  // they get a per-entry subst rewrite below, plus one extra Repeat(Any)
  // representative so the shared fn body (which substitutes self : T → Any)
  // can intern a `Struct(Repeat, [Any])` BcType when accessing fields.
  const replacements = new Map<MonoEntry, MonoEntry>();
  const structAnyRewrites = new Map<MonoEntry, MonoEntry>();     // entry → rewritten copy
  const extraStructEntries: MonoEntry[] = [];
  for (const [_decl, group] of groups) {
    if (group.length === 0) continue;
    const eraseGroup = group.some((e) => shouldErase(e, ctx));
    if (!eraseGroup) continue;
    if (group[0]!.decl.kind === "StructDecl") {
      // Per-instance shape rewrite : keep mangled / typeArgs for distinct
      // identity at the BcType level, override subst to K→Any so the
      // lowered struct has all-Any fields (single shared shape under
      // multiple tags).
      for (const e of group) {
        if (!shouldErase(e, ctx)) continue;
        structAnyRewrites.set(e, { ...e, subst: anySubstForEntry(e) });
      }
      // Extra Repeat(Any)-flavoured entry. The fn-side representative
      // body substitutes `self : Repeat(T)` to `Repeat(Any)` ; without
      // this entry, `internType(Struct(Repeat, [Any]))` misses → field
      // access emits `unreachable`. Distinct mangled name so it doesn't
      // collide with the rewritten `Repeat__i32` / `Repeat__string` /
      // ... entries that retain their original mangling.
      const first = group[0]!;
      const erasedArgs: Type[] = first.typeArgs.map(() => TY.any);
      extraStructEntries.push({
        id: first.id,
        isMain: first.isMain,
        // Strip the per-instance suffix and append `__Any` — same convention
        // the legacy `monomorphizeProject` would have used had this entry
        // come through the regular instance pass.
        mangled: first.mangled.replace(/__[^_]+(_\d+)?$/, "") + "__Any",
        decl: first.decl,
        symbol: first.symbol,
        subst: anySubstForEntry(first),
        typeArgs: erasedArgs,
        module: first.module,
      });
    } else {
      const repr = makeRepresentative(group[0]!);
      for (const e of group) replacements.set(e, repr);
    }
  }

  // Project the original `entries` list. Fn entries route through
  // `replacements` (collapsed to one representative). Struct entries swap
  // for their all-Any-subst rewrite when present. Non-erasable entries
  // pass through unchanged. Finally append the extra Repeat(Any)-flavoured
  // struct entries so they materialise in the lowered IR.
  const seen = new Set<MonoEntry>();
  const newEntries: MonoEntry[] = [];
  for (const entry of mono.entries) {
    const target = replacements.get(entry) ?? structAnyRewrites.get(entry) ?? entry;
    if (seen.has(target)) continue;
    seen.add(target);
    newEntries.push(target);
  }
  for (const extra of extraStructEntries) newEntries.push(extra);

  // Rebuild the three lookup maps. Every concrete-args query that used
  // to land on one of the deduped entries now resolves to the
  // representative ; non-erased entries route through unchanged.
  const newLookupByInstance = new Map<string, MonoEntry>();
  for (const [key, entry] of mono.lookupByInstance) {
    newLookupByInstance.set(key, replacements.get(entry) ?? entry);
  }

  const newImplMethodEntries = redirectInner(mono.implMethodEntries, replacements);
  const newFnInstanceEntries = redirectInner(mono.fnInstanceEntries, replacements);

  // Build the symbol-id redirect table : for every redirected entry, map
  // its old `symbol.id` to the representative's `symbol.id`. The bytecode
  // emit uses this to redirect any `LoweredCall` that still references
  // the original entry's symbol (left over in the lowered IR from before
  // dedupe) to the representative's fnIndex.
  const symbolRedirects = new Map<number, number>();
  for (const [oldEntry, repr] of replacements) {
    if (oldEntry.symbol === null || repr.symbol === null) continue;
    if (oldEntry.symbol.id === repr.symbol.id) continue;
    symbolRedirects.set(oldEntry.symbol.id, repr.symbol.id);
  }

  return {
    entries: newEntries,
    lookupByInstance: newLookupByInstance,
    implMethodEntries: newImplMethodEntries,
    fnInstanceEntries: newFnInstanceEntries,
    symbolRedirects,
  };
}
