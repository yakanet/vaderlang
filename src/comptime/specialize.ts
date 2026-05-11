// Specialisation pass driven by the comptime engine. Flattens the
// `InstanceRegistry` (populated during comptime evaluation) into a list of
// concrete `MonoEntry` items that the lowerer and downstream phases consume :
//
//   - every non-generic top-level decl gets one MonoEntry with empty substitution ;
//   - every concrete `(struct, type-args)` instance from the registry gets one
//     MonoEntry whose substitution maps the decl's type-params to the concrete args ;
//   - every concrete `(generic fn, type-args)` instance from a call site gets one
//     MonoEntry per impl member specialised against the call-site substitution.
//
// Layer 2 of the type-first redesign relocated this from a standalone pass
// into the comptime engine — `evaluateProject` calls `monomorphizeProject`
// at the end of bake, before returning the `EvaluatedProject` to the lowerer.

import type * as A from "../parser/ast.ts";
import type { ResolvedProgram } from "../resolver/resolved-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import { canonicalArgsKey, displayType, type Substitution, type Type } from "../typecheck/types.ts";
import type { EvaluatedProject } from "./evaluated-ast.ts";
import type { GenericInstance } from "./instances.ts";

// ============================================================================
// Specialised AST shape
// ============================================================================

export interface MonoEntry {
  /** Pipeline-stable numeric identity. Used by DCE root detection, VM
   *  entry-point lookup, and the C emitter's `main()` shim — none of
   *  them re-parse `mangled` to recover the entry's role. Assigned
   *  monotonically at construction ; preserved through every IR layer. */
  readonly id: number;
  /** True iff the origin decl is the top-level `main` fn. The
   *  pipeline-wide entry-point flag — replaces the older
   *  `mangled.endsWith("$main")` heuristic so the C-emit (or any other
   *  back-end) is free to rename the externalised symbol without
   *  breaking routing. */
  readonly isMain: boolean;
  /** External / human-readable name : `main`, `List$i32`, etc. Used by
   *  the C emitter for the C symbol, the binary writer for the section
   *  header, and `vader dump` for diagnostics. **Not** used as a
   *  routing identity by any compiler phase. */
  readonly mangled: string;
  /** Origin decl in the source AST. Multiple MonoEntry can share the same origin (different specialisations). */
  readonly decl: A.FnDecl | A.StructDecl | A.ImplDecl | A.ConstDecl;
  /** The decl's symbol, when applicable. ImplDecl has none — its members are emitted as separate entries. */
  readonly symbol: Symbol | null;
  /** Substitution mapping `TypeParam` symbol IDs to the concrete type-args. Empty for non-generic decls. */
  readonly subst: Substitution;
  /** When this entry comes from a generic instantiation, the concrete type-args (in source order). */
  readonly typeArgs: readonly Type[];
  /** Module the origin decl lives in — needed for resolver-table lookups. */
  readonly module: ResolvedProgram;
}

export interface MonoProject {
  readonly entries: readonly MonoEntry[];
  /** Lookup by `(declIdentity, typeArgsKey)` returning the entry's mangled name. */
  readonly lookupByInstance: ReadonlyMap<string, MonoEntry>;
  /** Lookup by impl member FnDecl, then by the struct args' canonical key.
   *  Inner key is `""` for non-generic impls ; for generic impls it's
   *  `canonicalArgsKey(args)` (structurally stable, insensitive to
   *  `displayType` rewrites, symbol-id-anchored). Each `(member, struct
   *  args)` pair resolves to its specialised entry. */
  readonly implMethodEntries: ReadonlyMap<A.FnDecl, ReadonlyMap<string, MonoEntry>>;
  /** Lookup by generic FnDecl, then by the concrete type-args canonical
   *  key. Populated by the fn-instance pass for call sites of the form
   *  `foo(T)(args)`. */
  readonly fnInstanceEntries: ReadonlyMap<A.FnDecl, ReadonlyMap<string, MonoEntry>>;
}

// ============================================================================
// Specialisation pass
// ============================================================================

const EMPTY_SUBST: Substitution = { typeParams: new Map() };

export function monomorphizeProject(evaluated: EvaluatedProject): MonoProject {
  const entries: MonoEntry[] = [];
  const byInstance = new Map<string, MonoEntry>();
  const implMethodEntries = new Map<A.FnDecl, Map<string, MonoEntry>>();
  const seenMangled = new Set<string>();
  const synthIds = { next: 1_000_000 };
  const entryIds = { next: 0 };

  // Pass 1: every non-generic top-level decl gets one entry. Generic impls
  // defer to pass 2 — one entry per `(impl member, concrete struct args)`.
  for (const typed of evaluated.typed.modules.values()) {
    for (const decl of typed.resolved.source.decls) {
      switch (decl.kind) {
        case "FnDecl":
          if (decl.typeParams.length === 0) {
            entries.push(makeEntry(decl, decl.name, typed.resolved, EMPTY_SUBST, [], seenMangled, entryIds));
          }
          break;
        case "StructDecl":
          if (decl.typeParams.length === 0) {
            entries.push(makeEntry(decl, decl.name, typed.resolved, EMPTY_SUBST, [], seenMangled, entryIds));
          }
          break;
        case "ConstDecl":
          entries.push(makeEntry(decl, decl.name, typed.resolved, EMPTY_SUBST, [], seenMangled, entryIds));
          break;
        case "ImplDecl":
          if (decl.forType.kind === "GenericInstExpr") break;     // handled per-instance in pass 2
          for (const member of decl.members) {
            const base = `${forTypeName(decl.forType)}$${decl.traitName}$${member.name}`;
            const entry = makeImplMemberEntry(member, base, typed.resolved, EMPTY_SUBST, [], seenMangled, synthIds, entryIds);
            entries.push(entry);
            putImplEntry(implMethodEntries, member, [], entry);
          }
          break;
        default:
          break;
      }
    }
  }

  // Index generic impls by their target struct name so pass 2 can lookup
  // matching impls in O(1) instead of scanning all modules' decls per instance.
  const genericImplsByStruct = new Map<string, Array<{ decl: A.ImplDecl; program: ResolvedProgram }>>();
  for (const m of evaluated.typed.modules.values()) {
    for (const d of m.resolved.source.decls) {
      if (d.kind !== "ImplDecl") continue;
      if (d.forType.kind !== "GenericInstExpr") continue;
      if (d.forType.callee.kind !== "IdentExpr") continue;
      const name = d.forType.callee.name;
      let bucket = genericImplsByStruct.get(name);
      if (bucket === undefined) { bucket = []; genericImplsByStruct.set(name, bucket); }
      bucket.push({ decl: d, program: m.resolved });
    }
  }

  // Pass 2: every concrete struct instance from the registry gets one entry.
  // Plus one entry per impl member for each generic impl on that struct.
  for (const inst of evaluated.instances) {
    const entry = makeInstanceEntry(inst, evaluated, seenMangled, entryIds);
    if (entry === null) continue;
    entries.push(entry);
    byInstance.set(inst.displayKey, entry);

    // Materialize generic-impl members for this struct instance.
    const program = evaluated.typed.modules.get(inst.symbol.module)?.resolved;
    if (program === undefined) continue;
    if (inst.symbol.source.kind !== "struct") continue;
    const structDecl = inst.symbol.source.decl;
    const matchingImpls = genericImplsByStruct.get(inst.symbol.name) ?? [];
    for (const { decl: d, program: implProgram } of matchingImpls) {
      // Skip impls whose for-type args don't match this instance — e.g.
      // `Range[char] implements Iterator` must not produce a member entry
      // for the `Range[i32]` instance.
      if (!implForTypeMatches(d.forType, inst.args, implProgram)) continue;
      // Two routes for building the call-site substitution :
      //   - Legacy form `Foo[T] implements ...` with no impl-level
      //     type-params : `T` aliases the *struct*'s type-param symbol, so
      //     we substitute against `structDecl.typeParams` (resolved in the
      //     struct's own program — `program` here).
      //   - Bounded form `[T: Bound] Foo[T] implements ...` : `T` is the
      //     impl's own type-param symbol (bound by `bindTypeParam` in
      //     `resolveImplDecl`). Substitute against `decl.typeParams`, and
      //     resolve symbols from `implProgram` since that's where the
      //     impl-side typeParam symbols live.
      const subst = d.typeParams.length > 0
        ? buildSubst(d.typeParams, inst.args, implProgram)
        : buildSubst(structDecl.typeParams, inst.args, program);
      for (const member of d.members) {
        const base = `${inst.symbol.name}$${d.traitName}$${member.name}`;
        const memberEntry = makeImplMemberEntry(
          member, base, implProgram, subst, inst.args, seenMangled, synthIds, entryIds,
        );
        entries.push(memberEntry);
        putImplEntry(implMethodEntries, member, inst.args, memberEntry);
      }
    }
  }

  // Pass 3: fn instances — one entry per (generic fn, concrete type-args) call site.
  // The instance registry already collected these via `observeFnCall` in evaluate.ts.
  const fnInstanceEntries = new Map<A.FnDecl, Map<string, MonoEntry>>();
  for (const inst of evaluated.instances) {
    if (inst.symbol.kind !== "fn" || inst.symbol.source.kind !== "fn") continue;
    const fnDecl = inst.symbol.source.decl;
    if (fnDecl.typeParams.length === 0 || fnDecl.typeParams.length !== inst.args.length) continue;
    const program = evaluated.typed.modules.get(inst.symbol.module)?.resolved ?? null;
    if (program === null) continue;
    const subst = buildSubst(fnDecl.typeParams, inst.args, program);
    const entry = makeImplMemberEntry(fnDecl, mangle(inst.symbol.name, program, []), program, subst, inst.args, seenMangled, synthIds, entryIds);
    entries.push(entry);
    putImplEntry(fnInstanceEntries, fnDecl, inst.args, entry);
  }

  return { entries, lookupByInstance: byInstance, implMethodEntries, fnInstanceEntries };
}

function putImplEntry(
  map: Map<A.FnDecl, Map<string, MonoEntry>>,
  member: A.FnDecl, args: readonly Type[], entry: MonoEntry,
): void {
  let inner = map.get(member);
  if (inner === undefined) {
    inner = new Map();
    map.set(member, inner);
  }
  inner.set(argsKey(args), entry);
}

function argsKey(args: readonly Type[]): string {
  return canonicalArgsKey(args);
}

/** Build an impl-member entry. Synthesises a `fn` symbol so the bytecode
 *  emitter's `fnIndexBySymId` lookup works (impl members aren't visible at
 *  the module level so the resolver doesn't create symbols for them). */
function makeImplMemberEntry(
  member: A.FnDecl, baseName: string, program: ResolvedProgram,
  subst: Substitution, typeArgs: readonly Type[],
  seen: Set<string>, synthIds: { next: number }, entryIds: { next: number },
): MonoEntry {
  const sym: Symbol = {
    id: synthIds.next++,
    kind: "fn",
    name: member.name,
    module: program.module.id,
    visibility: "private",
    definedAt: member.span,
    source: { kind: "fn", decl: member },
  };
  return {
    id: entryIds.next++,
    isMain: false,         // impl members can't be the program entry-point
    mangled: uniq(seen, mangle(baseName, program, typeArgs)),
    decl: member, symbol: sym, subst, typeArgs, module: program,
  };
}

function makeEntry(
  decl: MonoEntry["decl"], baseName: string, program: ResolvedProgram,
  subst: Substitution, typeArgs: readonly Type[],
  seen: Set<string>, entryIds: { next: number },
): MonoEntry {
  const sym = symbolForDecl(decl, program);
  return {
    id: entryIds.next++,
    isMain: decl.kind === "FnDecl" && decl.name === "main",
    mangled: uniq(seen, mangle(baseName, program, typeArgs)),
    decl, symbol: sym, subst, typeArgs, module: program,
  };
}

/** Look up the symbol that backs a top-level decl. For overloaded fn names
 *  the module's `symbols` map only stores the primary, so we need to scan
 *  `fnOverloads` to find the symbol whose `source.decl` matches this decl. */
function symbolForDecl(decl: MonoEntry["decl"], program: ResolvedProgram): Symbol | null {
  if (!("name" in decl)) return null;
  if (decl.kind === "FnDecl") {
    const bucket = program.module.fnOverloads.get(decl.name);
    if (bucket !== undefined) {
      for (const sym of bucket) {
        if (sym.source.kind === "fn" && sym.source.decl === decl) return sym;
      }
    }
  }
  return program.module.symbols.get(decl.name) ?? null;
}

function makeInstanceEntry(
  inst: GenericInstance, evaluated: EvaluatedProject,
  seen: Set<string>, entryIds: { next: number },
): MonoEntry | null {
  const sym = inst.symbol;
  if (sym.source.kind !== "struct") return null;     // trait instances aren't directly emitted
  const decl = sym.source.decl;
  const program = evaluated.typed.modules.get(sym.module)?.resolved ?? null;
  if (program === null) return null;
  if (decl.typeParams.length !== inst.args.length) return null;     // registry would have rejected
  return makeEntry(decl, decl.name, program, buildSubst(decl.typeParams, inst.args, program), inst.args, seen, entryIds);
}

function buildSubst(
  typeParams: readonly A.TypeParam[], args: readonly Type[], program: ResolvedProgram,
): Substitution {
  const map = new Map<number, Type>();
  for (let i = 0; i < typeParams.length; i++) {
    const arg = args[i];
    if (arg === undefined) continue;
    const symbol = program.typeParams.get(typeParams[i]!);
    if (symbol !== undefined) map.set(symbol.id, arg);
  }
  return { typeParams: map };
}

export function mangle(name: string, program: ResolvedProgram, typeArgs: readonly Type[]): string {
  const moduleStem = sanitise(program.module.displayPath);
  const head = moduleStem === "" || moduleStem === name ? name : `${moduleStem}$${name}`;
  return typeArgs.length === 0
    ? head
    : `${head}__${typeArgs.map(displayType).map(sanitise).join("__")}`;
}

function forTypeName(t: A.TypeExpr): string {
  if (t.kind === "IdentExpr") return t.name;
  if (t.kind === "GenericInstExpr" && t.callee.kind === "IdentExpr") return t.callee.name;
  return "?";
}

/** True when the impl's for-type args are compatible with `instArgs`.
 *  Concrete-arg impls (`Range[i32]`) match only their exact instance ;
 *  generic-arg impls (`Foo[T]`) match any concrete instantiation. */
function implForTypeMatches(
  forType: A.TypeExpr, instArgs: readonly Type[], program: ResolvedProgram,
): boolean {
  if (forType.kind !== "GenericInstExpr") return true;
  if (forType.typeArgs.length !== instArgs.length) return false;
  for (let i = 0; i < forType.typeArgs.length; i++) {
    const declArg = forType.typeArgs[i]!;
    const queryArg = instArgs[i]!;
    if (declArg.kind === "IdentExpr") {
      if (program.typeParamTypes.get(declArg) !== undefined) continue;
      const sym = program.types.get(declArg);
      if (sym?.kind === "type-param") continue;
      if (queryArg.kind === "Primitive" && queryArg.name === declArg.name) continue;
      if (queryArg.kind === "Struct" && queryArg.symbol.name === declArg.name) continue;
      return false;
    }
    return false;
  }
  return true;
}

function sanitise(raw: string): string {
  return raw.replace(/[^A-Za-z0-9_]/g, "_");
}

function uniq(seen: Set<string>, candidate: string): string {
  if (!seen.has(candidate)) { seen.add(candidate); return candidate; }
  let i = 1;
  while (seen.has(`${candidate}_${i}`)) i++;
  const fresh = `${candidate}_${i}`;
  seen.add(fresh);
  return fresh;
}
