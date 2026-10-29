# Compile time

`@comptime` runs ordinary Vader code while the program compiles, and keeps what it computes: tables, checks, and code repeated for each field of a type.

## Values computed by the compiler

`@comptime` above a constant runs its right-hand side during the build: the program starts with the value already there.

```vader
# module "main"
# import "std/io"
squares :: fn(n: i32) -> i32[] {
    out: i32[]: []
    for i in 0..<n {
        out.push(i * i)
    }
    return out
}

@comptime
SQUARES :: squares(10)

FIZZ :: @comptime {
    words: string[]: []
    for i in 1..=5 {
        if i % 3 == 0 {
            words.push("fizz")
        } else {
            words.push("${i}")
        }
    }
    words
}
# main :: fn() -> i32 {
#     println("${SQUARES[9]} ${SQUARES.len()}")
#     println("${FIZZ}")
#     return 0
# }
```

```text
81 10
[1, 2, fizz, 4, 5]
```

A block after `@comptime` runs like a function body: its last expression gives the value. The rules: §14 *`@comptime`*.

## Asking about types

`@size_of`, `@type_name`, `@satisfies` and most of the other `@` built-ins answer questions about a type, as constants.

```vader
# module "main"
# import "std/io"
Point :: struct { x: f64, y: f64 }
Secret :: struct { key: string }

Point implements Display -> "(${self.x}, ${self.y})"

facts :: fn() -> string[] = [
    "${@size_of(u8)} byte for a u8, ${@size_of(Point)} for a ${@type_name(Point)}",
    "${@type_name(Point)} prints: ${@satisfies(Point, Display)}",
    "${@type_name(Secret)} prints: ${@satisfies(Secret, Display)}",
]
# main :: fn() -> i32 {
#     for line in facts() {
#         println(line)
#     }
#     return 0
# }
```

```text
1 byte for a u8, 8 for a Point
Point prints: true
Secret prints: false
```

A struct is a reference, so `@size_of` gives the size of the reference: 8 bytes. The rules: §14 *Reflection / comptime intrinsics*.

## Code repeated for each field

`@comptime for` over `@fields(T)` copies its body once per field of a struct, and `@field(x, f.name)` reads that field.

```vader
# module "main"
# import "std/io"
Config :: struct {
    name:    string
    retries: i32
    verbose: bool
}

dump :: fn(c: Config) {
    @comptime for f in @fields(Config) {
        println("${f.name} = ${@field(c, f.name)}")
    }
}
# main :: fn() -> i32 {
#     dump(Config { .name = "server", .retries = 3, .verbose = false })
#     return 0
# }
```

```text
name = server
retries = 3
verbose = false
```

The rules: §14 *`@comptime for` over reflected fields*.

## Checks at compile time

`@assert` stops the build when a condition on the program does not hold.

```vader
# module "main"
# import "std/io"
Header :: struct { tag: u8, size: u32 }

@assert(@field_count(Header) == 2, "Header has two fields")
# main :: fn() -> i32 {
#     println("${@field_count(Header)} fields")
#     return 0
# }
```

```text
2 fields
```

Here the condition holds and the program runs; had it failed, the build would have stopped with the message. The rules: §12 *`@assert`* and §14 *Reflection / comptime intrinsics*.
