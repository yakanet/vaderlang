# Calling with a dot

Vader has no methods. `a.f(b)` is another way to write `f(a, b)`: any function can be called on its first argument, wherever it is declared.

## `a.f(b)` is `f(a, b)`

A function declared next to a struct reads as a method of it, and the call can take either form.

```vader
# module "main"
# import "std/io"
Point :: struct { x: f64, y: f64 }

moved :: fn(p: Point, dx: f64, dy: f64) -> Point = Point { .x = p.x + dx, .y = p.y + dy }

describe :: fn(p: Point) -> string = "(${p.x}, ${p.y})"
# main :: fn() -> i32 {
#     start :: Point { .x = 1.0, .y = 2.0 }
#     println(describe(moved(start, 3.0, 0.5)))
#     println(start.moved(3.0, 0.5).describe())
#     return 0
# }
```

```text
(4.0, 2.5)
(4.0, 2.5)
```

The rules: §6 *UFCS (Uniform Function Call Syntax)*.

## Chains

Calls read left to right, each on the result of the one before. The functions of `std/string` and `std/iter` are written to be chained.

```vader
# module "main"
# import "std/io"
# import "std/iter"
# import "std/string"
# main :: fn() -> i32 {
    println("  hello, world  ".trim().to_upper())
    total :: [3, 8, 2, 7].filter(n -> n > 2).map(n -> n * 10).sum()
    println("${total}")
#     return 0
# }
```

```text
HELLO, WORLD
180
```

The rules: §15 *Iteration*.

## Functions on any type

Since a function needs no class to live in, one written for a type it does not own reads like a method of that type, an integer included.

```vader
# module "main"
# import "std/io"
percent_of :: fn(part: i32, whole: i32) -> i32 = part * 100 / whole

is_even :: fn(n: i32) -> bool = n % 2 == 0
# main :: fn() -> i32 {
#     println("${30.percent_of(120)}%")
#     println("${7.is_even()} ${8.is_even()}")
#     return 0
# }
```

```text
25%
false true
```

A call `x.f()` sees the functions of the module and of the modules its file imports, like `f(x)`. The rules: §6 *Import requirement*.
