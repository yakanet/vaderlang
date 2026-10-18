# Comptime

## tests/snippets/_diag_union_common_field

# Diagnostics

- ``[24:45] error[T3008] expression is not indexable: `.label` does not read the same in every variant of `Back | Front` (`Back` declares it at 0, `Front` at 1); narrow with `if`/`match` first``
- ``[30:42] error[T3008] expression is not indexable: `.age` does not read the same in every variant of `Kitten | Puppy` (it is `i32` in `Kitten`, `i64` in `Puppy`); narrow with `if`/`match` first``
- ``[36:50] error[T3008] expression is not indexable: `.name` does not read the same in every variant of `Narrow | Wide` (field 0, before it, is `u8` in `Narrow` and `i64` in `Wide`); narrow with `if`/`match` first``
