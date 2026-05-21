# vader/typecheck — TS → Vader port status

This doc tracks what's wired and what's still MVP-trimmed in the
self-host typechecker. The TS reference lives in `src/typecheck/`.

## Wired & functional

Every `Stmt` and `Expr` variant has typing. Bodies of fns get walked
end-to-end ; `expr_types` / `local_types` / `decl_types` get
populated.

| Vader file              | Covers                                                | Phase |
|-------------------------|-------------------------------------------------------|-------|
| `types.vader`           | Type IR (15 variants) + constructors + display_type   | 1.1   |
| `type_ops.vader`        | equals / assignable / union_of / default_if_free / narrow_for_expected | 1.2 |
| `typed_ast.vader`       | TypedProgram side-tables                              | 1.3   |
| `context.vader`         | FnContext + Globals                                   | 1.4   |
| `enum_pass.vader`       | EnumDecl variant index map                            | 2.1   |
| `type_expr.vader`       | TypeExpr → Type                                       | 2.2   |
| `decl.vader`            | Top-level type collection                             | 2.3   |
| `impls.vader`           | ImplRegistry                                          | 2.4   |
| `check.vader`           | Decl-pass orchestrator (cycle-free)                   | 2.5   |
| `orchestrate.vader`     | Full pipeline = decl + body walking                   | 2.5   |
| `dump.vader`            | Text dump for parity harness                          | 2.6   |
| `expr.vader`            | Bidirectional expression dispatcher                   | 3.x   |
| `expr_literals.vader`   | Int/Float/Bool/Null/Char/String                       | 3.1   |
| `expr_ident.vader`      | IdentExpr via resolver lookup                         | 3.2   |
| `call.vader`            | CallExpr                                              | 3.4   |
| `binary.vader`          | BinaryExpr                                            | 3.5   |
| `field.vader`           | FieldExpr + shared `find_struct_field_type`           | 3.6   |
| `stmt.vader`            | check_block + check_stmt + check_fn_body              | 4.1   |
| `expr_if.vader`         | IfExpr → union_of(branches)                           | 4.2   |
| `struct_lit.vader`      | StructLitExpr                                         | 5.5   |
| `match_expr.vader`      | MatchExpr → union_of(arm bodies) (no exhaustiveness)  | 6.1 MVP |
| `seq_lit.vader`         | SeqLitExpr (array vs tuple)                           | 5.x   |
| `expr_unary.vader`      | `-x` / `!x` / `~x`                                    | 5.x   |
| `expr_index.vader`      | `arr[i]` (array only ; no Index trait)                | 5.4 MVP |
| `expr_cast.vader`       | `T(x)` returns target type                            | 5.6 MVP |
| `expr_range.vader`      | `a..b` walks bounds (returns Unresolved)              | 5.x   |
| `expr_dot_variant.vader`| `.Variant` against expected EnumType                  | 5.x   |
| `expr_lambda.vader`     | `(x) -> body` → mk_fn(params, body)                   | 5.x   |
| `expr_try.vader`        | `e?` returns inner (no Error stripping)               | 8.2 MVP |
| `expr_intrinsic.vader`  | `@name(...)` static result spec                       | 5.x   |
| `expr_generic_inst.vader`| `fn[T]()` returns callee type                        | 5.x   |
| `expr_type_value.vader` | `T[]` / `fn(T)->R` in value position                  | 5.x   |
| `unify.vader`           | Structural `unify_type_param` + `type_contains_type_param` | 5.2 MVP |
| `narrow.vader`          | `push_narrow` / `pop_narrow` / `narrow_for_binding` API | 6.2 MVP |
| `traits.vader`          | Trait composition reader (API stub)                   | 7.1 MVP |
| `inherit_bounds.vader`  | Bound inheritance API (no-op)                         | 7.2 MVP |
| `struct_bounds.vader`   | Bound enforcement API (no-op)                         | 7.3 MVP |
| `coerce.vader`          | `try_into` API (always false)                         | 8.1 MVP |

## Diagnostic codes emitted

T3001 TypeMismatch · T3003 WrongArgCount · T3007 NotCallable · T3008
NotIndexable · T3009 FieldDoesNotExist · T3015 BreakContinueOutsideLoop ·
T3017 OperatorNotDefined · T3019 ConditionMustBeBool · T3020
BodyReturnIncompatible · T3024 FnSignatureMustBeAnnotated · T3027
UnknownEnumVariant · T3028 CannotInferEnumType · T3037
MissingRequiredFieldInStructLit · T3038 FieldAlreadyProvided

## Parity status against TS reference

The `tests/parity.test.ts::typecheck` stage diffs the Vader CLI's
`dump --stage=typed-ast` byte-for-byte against the TS-generated
`typecheck.snapshot` for every snippet under `tests/snippets/`.

**Current scoring : 251/251 (100 %) pass** (2026-05-22).

All four follow-up buckets that were tracked here previously
(B flow-sensitive narrowing, C mutation diagnostics, D Iterator-
trait dispatch, E self-referential / decorator / lambda corner
cases) have been closed in earlier sessions. The doc note about
"~51 % parity, 124 fails remaining" is historical ; the suite is
green end-to-end today.

What can still drift : new snippets added under `tests/snippets/`
that exercise typecheck behaviours not previously covered (rare —
most additions are codegen / native / vm tests). If a new typecheck
snippet fails parity, the gap typically lands in `expr_*.vader`
(per-expr inference) or `stmt.vader` (per-stmt checking) — fix in
those files, rerun parity, commit.

## Still deferred (next sessions)

The MVP modules above expose APIs but their producers / consumers
aren't wired. Each item below tracks **what needs to land first** to
make the corresponding behavior real.

1. **`infer_call` generic dispatch** — needs `typeParamSymbols` map
   on `TypedProgram` (Symbol per FnDecl.TypeParam). Once that's
   built by `decl.vader::declare_fn`, `infer_call` walks args
   through `unify.vader::unify_type_param`, then substitutes the
   resulting bindings into the callee's return type.

2. **`is T as a` binding narrowing** — resolver's body walker must
   mint a `Binding` Symbol when a `BinaryExpr.Is` carries `bind_as`.
   Once minted, `expr_if.vader::infer_if` pushes the RHS type into
   `typed.narrowed_bindings` for the then-block's lifetime.

3. **Exhaustiveness check (T3013)** in `match_expr.vader` — needs the
   pattern walker to enumerate covered variants per scrutinee, then
   compare against the scrutinee's enum/union shape.

4. **`Into` coercion + auto `T[] → Iterator(T)`** in `coerce.vader` —
   needs `ImplRegistry.find_for(type, trait_sym)` lookup. Today's
   registry only stores impls, no lookup API.

5. **Trait composition + bound enforcement** (`traits.vader`,
   `inherit_bounds.vader`, `struct_bounds.vader`) — needs the parser
   to surface trait bases (`= A & B`) and typeParam bounds
   (`Foo[T: Display]`) as AST nodes.

6. **W0002 dead-code warning** in `stmt.vader::check_block` — needs
   divergence analysis (`diverges_stmt` / `diverges_expr`) ; mostly
   mechanical port from TS once we want the warning.

7. **T3041 mutate-`::`-local check** in `stmt.vader::check_assign` —
   needs resolver to back-reference the `LetStmt.mutable` flag from
   the `Local` Symbol's source.
