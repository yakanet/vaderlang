# 0012 — A materialised clone's span is deterministic, keyed to its impl

## Status

Accepted (2026-09-01). Implemented across `vader/resolver/materialize.vader` and
`vader/resolver/substitute_body.vader`.

## Context

Three entry points in `materialize.vader` expand an `ImplDecl.members` array with
declarations drawn from the trait: `@intrinsic` stubs, default-method bodies
deep-cloned from the trait, and single-abstract-method sugar. A clone starts life
carrying the *trait's* spans, and two resolver tables are keyed on spans:

- `ResolvedFile.idents` maps `AST.IdentExpr → Symbol` by `Span.hash()`;
- `impl_method_decl_types` is keyed on a member's `name_span`.

`expr_types` and `expr_kinds` are id-keyed and were never exposed to this.

A trait method's spans are shared by every impl of that trait, so leaving them on
the clones made distinct nodes collide. Three failures came out of that, each in a
different table:

1. **Body idents.** `std/core` implements `Comparable` for i8 … char; all those
   impls share one `gt` / `gte` / … default body. The cloned bodies hashed to one
   `idents` key per node, and `other` came out unresolved.

2. **Member return types.** Anchoring every synthesised member at the shared
   `impl_.trait_name_span` collapsed a multi-method trait's return types onto the
   last method's — `Buffer implements ByteAccess` had `load_u8 -> u8` degrade to
   `memory_copy`'s `void`.

3. **Param ↔ body agreement.** The resolver mints a param's Symbol at the param
   span and records the body's `self` / `other` use-sites by name. Anchoring
   `self` at the trait method's shared `name_span` made `build_impl_member_params`
   (lower, a span-keyed `idents` lookup) read the *last* impl's `self` Symbol
   while the body's `self` resolved to the right one; CFG build failed with
   `unresolved ident self`.

Uniqueness alone does not fix this, and that is the non-obvious part. Deriving the
span from the per-clone node id is unique and still wrong: `std/core`'s default
bodies are materialised **twice** — once for the typecheck phase, once for the
lower phase, on distinct `ImplDecl` copies — and node ids differ between the two
generations. An id-derived span would record `idents` under one key at resolve
time and read a different key at lower time.

So the requirement is not "unique per node" but **identical across two independent
materialisations of the same source**.

## Decision

One `StampCtx` per impl, threaded through every clone that impl produces:

```
base_line = impl_.trait_name_span.start.line * 1024 + column
counter   = 0, incremented once per cloned node
file      = CLONE_FILE_PREFIX + impl_.trait_name_span.start.file
```

Every cloned node draws its span from that one counter — block, stmt, expr, and
**every param including `self`**. The counter accumulates across all of the
impl's members rather than resetting per member.

Each ingredient answers one of the collisions above:

- **A traversal counter, not a node id.** Identical tree structure yields the
  identical counter per node in both generations, so resolve and lower agree.
- **`line * 1024 + column`, not the line alone.** Two impls on one source line
  are rare but not forbidden, and would otherwise share a base. Collision-free
  while columns stay well under 1024.
- **The source file folded into `file`.** `Span.hash` folds in `start.file`, so
  this is what separates two impls at the same `(line, column)` in different
  files of one module.
- **The `<clone>:` prefix.** Keeps every synthetic span clear of real source
  spans. Exported as `CLONE_FILE_PREFIX` because the consumer side
  (`typecheck/orchestrate.vader::file_overload_table`) has to map a cloned node
  back to the file whose imports it resolves against, and one definition beats
  two spellings of the literal.

## Consequences

The property to preserve is determinism, not uniqueness. A new clone-producing
path, or a new AST node kind reached by `stamp_block_spans` / `stamp_stmt_spans` /
`stamp_expr_spans`, must draw from the impl's existing `StampCtx`; a node missed
by the walk silently keeps its trait span and reintroduces failure 1 for whichever
trait has more than one impl.

`materialize_intrinsic_members` needs the same allocator even though a
single-method intrinsic trait was never affected — its lone member was already
unique — so that a second method added to such a trait does not resurrect
failure 2.

The spans are rendered `undefined:undefined` in the typecheck dump, which is what
marks a node as materialised when reading a dump.
