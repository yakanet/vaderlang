# Comptime

## tests/snippets/comptime_nested_array

- `@comptime CARD = Card { .either = [0_u8, 100_u8, 200_u8], .rows = [[0_i32, 0_i32], [1_i32, 10_i32], [2_i32, 20_i32]], .weights = [0_u8, 100_u8, 200_u8] }`, vm
- `@comptime GRID = [["a0", "b0"], ["a1", "b1"]]`, vm
- `@comptime MIXED = [[0_i32, 1_i32], "s0", [1_i32, 2_i32], "s1"]`, vm
