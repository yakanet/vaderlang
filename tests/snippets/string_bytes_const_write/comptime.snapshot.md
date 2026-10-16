# Comptime

## tests/snippets/string_bytes_const_write

# Diagnostics

- ``[9:5] error[T3070] a frozen value cannot be modified: `bytes()` returns a view of a string's bytes, and `bs[]` is assigned ; `.clone()` makes a copy to modify``
