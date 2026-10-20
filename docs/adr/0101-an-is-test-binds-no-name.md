# 0101: An `is` test binds no name

## Status

Accepted (2026-10-20). The `match e as x` header is the subject of its own
record.

## Context

`if x is T as e { … }` bound `e` to the tested value, narrowed to `T`, for the
then-block. It was the second way to name a value besides `::` and `:=`, with
scope rules of its own, and each pass had to know them: the binding lived on the
`BinaryExpr`, so the parser, the resolver, the typecheck, the effect summary,
closure analysis, the lowering, the formatter and four LSP features each carried
a path for it.

Those paths kept producing defects:

- The lowering evaluated the scrutinee twice, once for the test and once for the
  binding: `if f() is T as e` called `f` twice.
- The binding had no clear scope inside `&&` (R2029) and none at all after
  `!is`, so both were refused by special rules.
- Closure analysis and the LSP each needed a dedicated fix before the binding
  was captured, renamed and hovered like a local.
- Over a module constant it held a copy, an exception the style guide had to
  spell out.

Since flow narrowing works in place on a name and on a field chain, `as` was only
needed when the tested value had no name: in the tree, 20 of 208 sites tested a
call, and 78 aliased a value that already had a name.

## Decision

- **An `is` test binds no name.** `x is T as y` and `x !is T as y` are P1036.
  A value with no name of its own gets one first, `r :: f()`, which the test then
  narrows in place.
- **R2029 is retired**: there is no binding left for a `&&` to scope.

## Consequences

- The binding a test needed is now an ordinary local: it outlives the `if`, so
  two of them in one block need two names (`W0009` otherwise). No `else if`,
  `while` or `&&` site in the tree tested a call through `as`, the places where
  binding first would have changed the evaluation order.
- A field chain is narrowed in place until a call retires it. Code that read the
  narrowed value after a call binds it first, as the rewritten sites do.
- A use of the dropped name is also reported as R2006 next to the P1036.
