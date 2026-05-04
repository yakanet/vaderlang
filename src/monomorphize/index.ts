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
import { displayType, type Substitution, type Type } from "../typecheck/types.ts";
import type { MonoEntry, MonoProject } from "./mono-ast.ts";

export type { MonoEntry, MonoProject } from "./mono-ast.ts";

const EMPTY_SUBST: Substitution = { typeParams: new Map() };

export function monomorphizeProject(evaluated: EvaluatedProject): MonoProject {
  const entries: MonoEntry[] = [];
  const byInstance = new Map<string, MonoEntry>();
  const seenMangled = new Set<string>();

  // Pass 1: every non-generic top-level decl gets one entry.
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
          // Generic impls (`T(U) implements Trait`) don't exist in the grammar yet;
          // emit one entry per member with the empty subst.
          for (const member of decl.members) {
            const base = `${forTypeName(decl.forType)}$${decl.traitName}$${member.name}`;
            entries.push(makeEntry(member, base, typed.resolved, EMPTY_SUBST, [], seenMangled));
          }
          break;
        default:
          break;     // ImportDecl, TraitDecl, TypeAliasDecl: no codegen output
      }
    }
  }

  // Pass 2: every concrete struct instance from the registry gets one entry.
  for (const inst of evaluated.instances) {
    const entry = makeInstanceEntry(inst, evaluated, seenMangled);
    if (entry === null) continue;
    entries.push(entry);
    byInstance.set(inst.displayKey, entry);
  }

  return { entries, lookupByInstance: byInstance };
}

function makeEntry(
  decl: MonoEntry["decl"], baseName: string, program: ResolvedProgram,
  subst: Substitution, typeArgs: readonly Type[], seen: Set<string>,
): MonoEntry {
  const sym = "name" in decl ? program.module.symbols.get(decl.name) ?? null : null;
  return {
    mangled: uniq(seen, mangle(baseName, program, typeArgs)),
    decl, symbol: sym, subst, typeArgs, module: program,
  };
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

function mangle(name: string, program: ResolvedProgram, typeArgs: readonly Type[]): string {
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
