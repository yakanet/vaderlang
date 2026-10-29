# Control flow

`if` and `match` are expressions: they give a value. `for` is the only loop.

## `if` and `else`

`if` runs a block when its condition holds. With an `else`, it also gives a value.

```vader
# module "main"
# import "std/io"
# main :: fn() -> i32 {
    temperature :: 31
    if temperature > 30 {
        println("hot")
    } else if temperature < 10 {
        println("cold")
    }
    feeling :: if temperature > 25 { "warm" } else { "fresh" }
    println(feeling)
#     return 0
# }
```

```text
hot
warm
```

The rules: §7 *`if` / `else`*.

## Narrowing with `is`

`is` tests which type a union holds. In the branch where the test holds, the value has that type.

```vader
# module "main"
# import "std/io"
describe :: fn(value: i32 | string) -> string {
    if value is string {
        return "the word ${value}"
    }
    return "the number ${value + 1}"
}
# main :: fn() -> i32 {
#     println(describe("vader"))
#     println(describe(41))
#     return 0
# }
```

```text
the word vader
the number 42
```

The rules: §3 *Type tests and narrowing*.

## `match`

`match` tries patterns from top to bottom: values, ranges, several values at once, and `_` for the rest. It must cover every case.

```vader
# module "main"
# import "std/io"
season :: fn(month: i32) -> string = match month {
    12 | 1 | 2 -> "winter"
    3..=5      -> "spring"
    6..=8      -> "summer"
    _          -> "autumn"
}
# main :: fn() -> i32 {
#     println(season(1))
#     println(season(7))
#     println(season(10))
#     return 0
# }
```

```text
winter
summer
autumn
```

The rules: §4 *Pattern matching*.

## Matching on types

On a union, an arm tests a type with `is` and sees the value as that type. An `if` after the pattern, a guard, narrows the arm further.

```vader
# module "main"
# import "std/io"
Circle :: struct { radius: f64 }
Square :: struct { side: f64 }

area :: fn(shape: Circle | Square) -> f64 = match shape {
    is Circle -> 3.0 * shape.radius * shape.radius
    is Square -> shape.side * shape.side
}

count :: fn(n: i32 | null) -> string = match n {
    null           -> "none"
    is i32 if n < 0 -> "less than none"
    is i32         -> "${n}"
}
# main :: fn() -> i32 {
#     println("${area(Circle { .radius = 2.0 })}")
#     println("${area(Square { .side = 3.0 })}")
#     println(count(null))
#     println(count(-1))
#     println(count(5))
#     return 0
# }
```

```text
12.0
9.0
none
less than none
5
```

The rules: §4 *Type tests* and §4 *Guards*.

## `for` over values

`for x in ...` walks a range, an array or any iterator. A range written `a..<b` stops before `b`, `a..=b` includes it. A loop over pairs names both parts.

```vader
# module "main"
# import "std/io"
# main :: fn() -> i32 {
    for i in 1..=3 {
        println("${i}")
    }
    for name in ["ada", "grace"] {
        println(name)
    }
    people: [string, i32][]: [["ada", 36], ["grace", 85]]
    for [name, age] in people {
        println("${name} is ${age}")
    }
#     return 0
# }
```

```text
1
2
3
ada
grace
ada is 36
grace is 85
```

The rules: §7 *`for` (universal loop)*.

## `for` while a condition holds

With a condition instead of a variable, `for` loops while it holds. Without anything, it loops until a `break`.

```vader
# module "main"
# import "std/io"
# main :: fn() -> i32 {
    n := 27
    steps := 0
    for n != 1 {
        if n % 2 == 0 {
            n = n / 2
        } else {
            n = 3 * n + 1
        }
        steps += 1
    }
    println("${steps} steps")

    tries := 0
    for {
        tries += 1
        if tries == 3 {
            break
        }
    }
    println("${tries} tries")
#     return 0
# }
```

```text
111 steps
3 tries
```

The rules: §7 *`for` (universal loop)*.

## Leaving an outer loop

A bare `break` or `continue` acts on the innermost loop. Followed by the variable of an outer loop, it acts on that one.

```vader
# module "main"
# import "std/io"
# main :: fn() -> i32 {
    grid :: [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    for row in grid {
        for cell in row {
            if cell % 2 == 0 {
                continue
            }
            if cell > 5 {
                break row
            }
            println("${cell}")
        }
    }
#     return 0
# }
```

```text
1
3
5
```

A loop without a variable takes a label instead, `scan: for ...`, which `break scan` targets. The rules: §7 *Targeting an outer loop*.

## `defer`

`defer` runs a statement when its block is left, whatever the way out: the last one registered runs first.

```vader
# module "main"
# import "std/io"
work :: fn() -> void {
    println("open")
    defer println("close")
    defer println("flush")
    println("work")
}
# main :: fn() -> i32 {
#     work()
#     return 0
# }
```

```text
open
work
flush
close
```

The rules: §7 *`defer`*.
