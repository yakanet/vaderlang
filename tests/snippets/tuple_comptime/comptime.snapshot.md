# Comptime

## tests/snippets/tuple_comptime

- `@comptime DIM = [i32, i32] { ._0 = 10_i32, ._1 = 20_i32 }`, tree-walk
- `const FAR = 5000000000_i64`, folded
- `@comptime ORIGIN = [f64, f64, string] { ._0 = 0.0_f64, ._1 = 0.0_f64, ._2 = "origin" }`, tree-walk
- `const Reach = [i64, i32]`, folded
