# Comptime

## tests/snippets/comptime_decorator_form

- `@comptime ANSWER = 42_i32`, tree-walk
- `@comptime ORIGIN = Point { .label = "origin", .x = 0_i32, .y = 0_i32 }`, vm
- `@comptime ROOT = 7_i32`, vm
- `@comptime WIDE_ROOT = 9_i64`, vm
