# Comptime

## tests/snippets/comptime_reads_vm_value

- `@comptime FROM_LIB = 11_i32`, vm
- `@comptime LIMIT = 70_i32`, vm
- `@comptime ROOT = 7_i32`, vm
- `@comptime SUM = 8_i32`, vm
- `@comptime TALLY = 5_i32`, vm
- `@comptime TWICE = 16_i32`, vm

## tests/snippets/comptime_reads_vm_value/lib

- `@comptime BASE = 6_i32`, tree-walk
- `@comptime CUBES = 5_i32`, vm
- `@comptime LIMIT = 10_i32`, vm
