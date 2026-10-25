# Comptime

## tests/snippets/comptime_decorator_form

- `@comptime ANSWER = 42_i32`, tree-walk
- `@comptime NEXT_ROOT = 8_i32`, vm
- `@comptime ORIGIN = Point { .label = "origin", .x = 0_i32, .y = 0_i32 }`, vm
- `@comptime ROOT = 7_i32`, vm
- `@comptime ROOT_SIZE = "big"`, vm
- `@comptime ROOT_TEXT = "root 7"`, vm
- `@comptime WIDE_ROOT = 9_i64`, vm
