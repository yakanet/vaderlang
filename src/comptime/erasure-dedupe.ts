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

import { isSpecialized, type MonoEntry, type MonoProject } from "./specialize.ts";

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

export function erasureDedupe(mono: MonoProject, project: TypedProject): MonoProject {
  const ctx = buildDedupeCtx(project);

  // Group entries by origin decl.
  const groups = new Map<MonoEntry["decl"], MonoEntry[]>();
  for (const entry of mono.entries) {
    let g = groups.get(entry.decl);
    if (g === undefined) { g = []; groups.set(entry.decl, g); }
    g.push(entry);
  }

  // For each erasable group, build the representative + a replacement map
  // (each member entry → representative).
  const replacements = new Map<MonoEntry, MonoEntry>();
  for (const [_decl, group] of groups) {
    const eraseGroup = group.some((e) => shouldErase(e, ctx));
    if (!eraseGroup) continue;
    if (group.length === 0) continue;
    const repr = makeRepresentative(group[0]!);
    for (const e of group) replacements.set(e, repr);
  }

  // Project the original `entries` list through `replacements`. Each
  // representative appears exactly once ; entries from non-erasable
  // groups pass through unchanged.
  const seen = new Set<MonoEntry>();
  const newEntries: MonoEntry[] = [];
  for (const entry of mono.entries) {
    const target = replacements.get(entry) ?? entry;
    if (seen.has(target)) continue;
    seen.add(target);
    newEntries.push(target);
  }

  // Rebuild the three lookup maps. Every concrete-args query that used
  // to land on one of the deduped entries now resolves to the
  // representative ; non-erased entries route through unchanged.
  const newLookupByInstance = new Map<string, MonoEntry>();
  for (const [key, entry] of mono.lookupByInstance) {
    newLookupByInstance.set(key, replacements.get(entry) ?? entry);
  }

  const newImplMethodEntries = new Map<A.FnDecl, Map<string, MonoEntry>>();
  for (const [fnDecl, inner] of mono.implMethodEntries) {
    const newInner = new Map<string, MonoEntry>();
    for (const [k, entry] of inner) {
      newInner.set(k, replacements.get(entry) ?? entry);
    }
    newImplMethodEntries.set(fnDecl, newInner);
  }

  const newFnInstanceEntries = new Map<A.FnDecl, Map<string, MonoEntry>>();
  for (const [fnDecl, inner] of mono.fnInstanceEntries) {
    const newInner = new Map<string, MonoEntry>();
    for (const [k, entry] of inner) {
      newInner.set(k, replacements.get(entry) ?? entry);
    }
    newFnInstanceEntries.set(fnDecl, newInner);
  }

  return {
    entries: newEntries,
    lookupByInstance: newLookupByInstance,
    implMethodEntries: newImplMethodEntries,
    fnInstanceEntries: newFnInstanceEntries,
  };
}
