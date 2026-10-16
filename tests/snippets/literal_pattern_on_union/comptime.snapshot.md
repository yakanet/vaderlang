# Comptime

## tests/snippets/literal_pattern_on_union

- `@comptime BAKED = 5_i32`, tree-walk
- `@comptime BAKED_IS_A = false`, tree-walk
- `@comptime BAKED_IS_FIVE = true`, tree-walk
- `const Path = string`, folded
- `const STORED = 5_i32`, folded
