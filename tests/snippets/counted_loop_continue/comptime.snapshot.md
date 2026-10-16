# Comptime

## tests/snippets/counted_loop_continue

- `const GUARD = 20_i32`, folded

# Diagnostics

- ``[126:12] warning[W0010] prefer targeting this loop by its iteration variable over a label ; a label is only needed for a `while` / infinite loop that has no variable: target this loop by its variable `r` instead of a label``
