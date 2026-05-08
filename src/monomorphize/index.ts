// Minimal monomorphization pass — implements the comptime-driven specialisation
// described in SPEC §2 ("Monomorphization"). For MVP, this means:
//
//   - every non-generic top-level decl gets one MonoEntry with empty substitution;
//   - every concrete `(struct, type-args)` instance from the comptime InstanceRegistry
//     gets one MonoEntry whose substitution maps the decl's type-params to the
//     concrete args;
//   - generic FnDecls aren't tracked yet — the registry only observes struct/trait
//     sites today; when generic-fn dispatch arrives this pass extends the same way.

import type * as A from "../parser/ast.ts";
import type { EvaluatedProject } from "../comptime/evaluated-ast.ts";
import type { GenericInstance } from "../comptime/instances.ts";
import type { ResolvedProgram } from "../resolver/resolved-ast.ts";
import type { Symbol } from "../resolver/symbol.ts";
import { displayType, type Substitution, type Type } from "../typecheck/types.ts";
import type { MonoEntry, MonoProject } from "./mono-ast.ts";

export type { MonoEntry, MonoProject } from "./mono-ast.ts";

const EMPTY_SUBST: Substitution = { typeParams: new Map() };

export function monomorphizeProject(evaluated: EvaluatedProject): MonoProject {
  const entries: MonoEntry[] = [];
  const byInstance = new Map<string, MonoEntry>();
  const implMethodEntries = new Map<A.FnDecl, Map<string, MonoEntry>>();
  const seenMangled = new Set<string>();
  const synthIds = { next: 1_000_000 };

  // Pass 1: every non-generic top-level decl gets one entry. Generic impls
  // defer to pass 2 — one entry per `(impl member, concrete struct args)`.
  for (const typed of evaluated.typed.modules.values()) {
    for (const decl of typed.resolved.source.decls) {
      switch (decl.kind) {
        case "FnDecl":
          if (decl.typeParams.length === 0) {
            entries.push(makeEntry(decl, decl.name, typed.resolved, EMPTY_SUBST, [], seenMangled));
          }
          break;
        case "StructDecl":
          if (decl.typeParams.length === 0) {
            entries.push(makeEntry(decl, decl.name, typed.resolved, EMPTY_SUBST, [], seenMangled));
          }
          break;
        case "ConstDecl":
          entries.push(makeEntry(decl, decl.name, typed.resolved, EMPTY_SUBST, [], seenMangled));
          break;
        case "ImplDecl":
          if (decl.forType.kind === "GenericInstType") break;     // handled per-instance in pass 2
          for (const member of decl.members) {
            const base = `${forTypeName(decl.forType)}$${decl.traitName}$${member.name}`;
            const entry = makeImplMemberEntry(member, base, typed.resolved, EMPTY_SUBST, [], seenMangled, synthIds);
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
      if (d.forType.kind !== "GenericInstType") continue;
      const name = d.forType.base.name;
      let bucket = genericImplsByStruct.get(name);
      if (bucket === undefined) { bucket = []; genericImplsByStruct.set(name, bucket); }
      bucket.push({ decl: d, program: m.resolved });
    }
  }

  // Pass 2: every concrete struct instance from the registry gets one entry.
  // Plus one entry per impl member for each generic impl on that struct.
  for (const inst of evaluated.instances) {
    const entry = makeInstanceEntry(inst, evaluated, seenMangled);
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
      const subst = buildSubst(structDecl.typeParams, inst.args, program);
      for (const member of d.members) {
        const base = `${inst.symbol.name}$${d.traitName}$${member.name}`;
        const memberEntry = makeImplMemberEntry(
          member, base, implProgram, subst, inst.args, seenMangled, synthIds,
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
    const entry = makeImplMemberEntry(fnDecl, mangle(inst.symbol.name, program, []), program, subst, inst.args, seenMangled, synthIds);
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
  return args.map(displayType).join(",");
}

/** Build an impl-member entry. Synthesises a `fn` symbol so the bytecode
 *  emitter's `fnIndexBySymId` lookup works (impl members aren't visible at
 *  the module level so the resolver doesn't create symbols for them). */
function makeImplMemberEntry(
  member: A.FnDecl, baseName: string, program: ResolvedProgram,
  subst: Substitution, typeArgs: readonly Type[],
  seen: Set<string>, synthIds: { next: number },
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
    mangled: uniq(seen, mangle(baseName, program, typeArgs)),
    decl: member, symbol: sym, subst, typeArgs, module: program,
  };
}

function makeEntry(
  decl: MonoEntry["decl"], baseName: string, program: ResolvedProgram,
  subst: Substitution, typeArgs: readonly Type[], seen: Set<string>,
): MonoEntry {
  const sym = symbolForDecl(decl, program);
  return {
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
  inst: GenericInstance, evaluated: EvaluatedProject, seen: Set<string>,
): MonoEntry | null {
  const sym = inst.symbol;
  if (sym.source.kind !== "struct") return null;     // trait instances aren't directly emitted
  const decl = sym.source.decl;
  const program = evaluated.typed.modules.get(sym.module)?.resolved ?? null;
  if (program === null) return null;
  if (decl.typeParams.length !== inst.args.length) return null;     // registry would have rejected
  return makeEntry(decl, decl.name, program, buildSubst(decl.typeParams, inst.args, program), inst.args, seen);
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
  if (t.kind === "NamedType") return t.name;
  if (t.kind === "GenericInstType") return t.base.name;
  return "?";
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
