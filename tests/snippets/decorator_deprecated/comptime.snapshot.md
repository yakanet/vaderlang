# Comptime

## tests/snippets/decorator_deprecated

- `const KING = 42_i32`, folded

# Diagnostics

- ``[21:10] warning[W0001] use of deprecated declaration: `old_helper`: use new_helper instead``
- ``[21:21] warning[W0001] use of deprecated declaration: `KING`: KING is too dramatic, prefer THE_BEST``
- ``[23:10] warning[W0001] use of deprecated declaration: `old_helper`: use new_helper instead``
