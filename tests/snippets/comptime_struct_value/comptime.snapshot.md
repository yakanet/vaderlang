# Comptime

## tests/snippets/comptime_struct_value

- `@comptime CARD = Card { .big = 4000000000_u64, .either = "text", .label = Label { .hue = 2_i32, .text = "card" }, .weights = [0_u8, 100_u8, 200_u8] }`, vm
- `@comptime LABELS = [Label { .hue = 1_i32, .text = "label 0" }, Label { .hue = 1_i32, .text = "label 1" }]`, vm
- `@comptime PAIR = [i32, string] { ._0 = 6_i32, ._1 = "six" }`, vm
- `@comptime SLOT = Slot { .hour = 7_i32, .note = "seven" }`, vm
- `@comptime SQUARE = Box<i64> { .item = 5000000000_i64 }`, vm
- `@comptime WORD_BOX = Box<string> { .item = "012" }`, vm
