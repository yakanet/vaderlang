# Functions

A function is a constant whose value is `fn(...) { ... }`. It may give its parameters defaults, take them by name, and be passed around like any other value.

## Declaring a function

A body in braces returns its last expression, or what a `return` gives. A body that is a single expression is written after `=`. A function that returns nothing leaves out the arrow.

```vader
# module "main"
# import "std/io"
largest :: fn(a: i32, b: i32) -> i32 {
    if a > b {
        return a
    }
    b
}

square :: fn(x: i32) -> i32 = x * x

report :: fn(label: string, value: i32) {
    println("${label}: ${value}")
}
# main :: fn() -> i32 {
#     report("largest", largest(3, 8))
#     report("square", square(7))
#     return 0
# }
```

```text
largest: 8
square: 49
```

The rules: §6 *Declaration*.

## Defaults and named arguments

A parameter with a default may be left out. An argument may name its parameter, in any order.

```vader
# module "main"
# import "std/io"
greet :: fn(name: string, greeting: string = "Hello", mark: string = "!") -> string =
    "${greeting}, ${name}${mark}"
# main :: fn() -> i32 {
#     println(greet("Ada"))
#     println(greet("Grace", "Hi"))
#     println(greet("Barbara", mark = "."))
#     return 0
# }
```

```text
Hello, Ada!
Hi, Grace!
Hello, Barbara.
```

The rules: §6 *Default parameter values* and §6 *Named arguments at call site*.

## Lambdas

A lambda is written `parameters -> body`. A function type, `fn(i32) -> i32`, says what a parameter accepts, and the lambda takes its types from it.

```vader
# module "main"
# import "std/io"
twice :: fn(f: fn(i32) -> i32, x: i32) -> i32 = f(f(x))
# main :: fn() -> i32 {
#     println("${twice(x -> x + 3, 10)}")
#     println("${twice(x -> x * x, 3)}")
#     return 0
# }
```

```text
16
81
```

The rules: §6 *Closures / lambdas*.

## Closures

A lambda or a nested function sees the locals around it, and changes to them show on both sides.

```vader
# module "main"
# import "std/io"
# main :: fn() -> i32 {
    count := 0
    bump :: fn() {
        count += 1
    }
    bump()
    bump()
    println("${count}")
#     return 0
# }
```

```text
2
```

The rules: §6 *Closures / lambdas*.

## Functions as values

A function named without a call is a value: it goes into a local, a field or an array like any other.

```vader
# module "main"
# import "std/io"
Operation :: struct {
    name:  string
    apply: fn(i32, i32) -> i32
}

add :: fn(a: i32, b: i32) -> i32 = a + b
# main :: fn() -> i32 {
#     operations :: [
#         Operation { .name = "add", .apply = add },
#         Operation { .name = "max", .apply = (a, b) -> if a > b { a } else { b } },
#     ]
#     for op in operations {
#         println("${op.name} ${op.apply(4, 9)}")
#     }
#     return 0
# }
```

```text
add 13
max 9
```

The rules: §6 *Function values*.

## Overloading

Two functions may share a name when their first parameters have different types. A call takes the one its first argument fits.

```vader
# module "main"
# import "std/io"
describe :: fn(n: i32) -> string = "the number ${n}"
describe :: fn(s: string) -> string = "the text \"${s}\""
describe :: fn(flags: bool[]) -> string = "${flags.len()} flags"
# main :: fn() -> i32 {
#     println(describe(7))
#     println(describe("seven"))
#     println(describe([true, false]))
#     return 0
# }
```

```text
the number 7
the text "seven"
2 flags
```

The rules: §6 *Function overloading*.
