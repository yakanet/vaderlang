# Comptime

## tests/snippets/comptime_matches_run_time

- `@comptime EITHER = true`, tree-walk
- `@comptime GUARDED = false`, tree-walk
- `@comptime NAMED = "i32"`, vm
- `@comptime PICKED = "str"`, tree-walk
- `const PICKED_PLAIN = "int"`, folded
- `@comptime SAME = false`, vm
- `@comptime SHOWN = "[1, 2]"`, vm
- `@comptime TOP = "Blue"`, vm
- `@comptime ZERO = 0_i32`, tree-walk
- `@comptime ZEROS = [0_i32, 0_i32, 0_i32, 0_i32]`, vm
