# Comptime

## tests/snippets/const_array_bad

- `const DIGITS = [10_i32, 20_i32, 30_i32]`, folded

# Diagnostics

- ``[14:5] error[T3070] a frozen value cannot be modified: `DIGITS` is a module constant, and `DIGITS[]` is assigned ; a name bound to it holds a copy to modify``
- ``[15:25] error[T3072] a frozen value cannot be lent to a function that modifies it: `DIGITS` is a module constant, and `write_through_param` modifies it (`a[]` is assigned) ; a name bound to it holds a copy to modify``
