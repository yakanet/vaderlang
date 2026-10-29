# Errors

There are no exceptions. A function that can fail says so in its return type, a union of its result and an error, and the caller handles the error like any other value.

## Errors are values

An error is a value of a type that implements the `Error` trait: its `message` says what went wrong. A function returns either its result or the error.

```vader
# module "main"
# import "std/io"
NotFound :: struct { name: string }

NotFound implements Error -> "no user named ${self.name}"

age_of :: fn(name: string) -> i32 | NotFound {
    if name == "ada" {
        return 36
    }
    return NotFound { .name = name }
}
# main :: fn() -> i32 {
#     for name in ["ada", "linus"] {
#         result :: age_of(name)
#         if result is NotFound {
#             println(result.message())
#         } else {
#             println("${name} is ${result}")
#         }
#     }
#     return 0
# }
```

```text
ada is 36
no user named linus
```

The rules: §10 *Error unions* and §10 *`Error` trait*.

## Passing an error on

A test with `is` and a `return` hand the error to the caller. Past the test, the value has its success type.

```vader
# module "main"
# import "std/io"
# import "std/string"
total :: fn(a: string, b: string) -> i32 | ParseError {
    x :: parse_int(a)
    if x is ParseError {
        return x
    }
    y :: parse_int(b)
    if y is ParseError {
        return y
    }
    return x + y
}
# main :: fn() -> i32 {
#     sum :: total("20", "22")
#     if sum is i32 {
#         println("${sum}")
#     }
#     failed :: total("20", "twenty-two")
#     if failed is ParseError {
#         println("not a number")
#     }
#     return 0
# }
```

```text
42
not a number
```

The rules: §10 *Error propagation*.

## Handling every case

A `match` handles the result and each kind of error in place. `Error` in a union stands for any type that implements it.

```vader
# module "main"
# import "std/io"
# import "std/string"
describe :: fn(text: string) -> string = match result :: parse_int(text) {
    is i32   -> "the number ${result}"
    is Error -> "an error: ${result.message()}"
}
# main :: fn() -> i32 {
#     println(describe("12"))
#     println(describe("twelve").starts_with("an error"))
#     return 0
# }
```

```text
the number 12
true
```

The rules: §10 *Explicit match*.

## A value instead of `null`

`??` gives the value on its left unless it is `null`, and otherwise the fallback: a value, or a `return`, `break` or `continue` that leaves.

```vader
# module "main"
# import "std/io"
first_long_word :: fn(words: string[]) -> string | null {
    for word in words {
        if word.byte_len() > 5 {
            return word
        }
    }
    return null
}

shout :: fn(words: string[]) -> string {
    word :: first_long_word(words) ?? return "nothing to shout"
    return "${word}!"
}
# main :: fn() -> i32 {
#     println(first_long_word(["a", "be"]) ?? "none")
#     println(shout(["short", "brilliant"]))
#     println(shout(["tiny"]))
#     return 0
# }
```

```text
none
brilliant!
nothing to shout
```

The rules: §4 *Null-coalescing `??`*.
