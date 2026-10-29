# Types

Structs group values, enums name a fixed set of cases, and unions say a value is one of several types, `null` included.

## Structs

A struct declares named fields; a literal sets them with `.field = value`. A field may have a default, and `...other` copies the fields a literal does not name.

```vader
# module "main"
# import "std/io"
Settings :: struct {
    name:    string
    retries: i32  = 3
    verbose: bool = false
}
# main :: fn() -> i32 {
#     quiet :: Settings { .name = "quiet" }
#     loud :: Settings { ...quiet, .name = "loud", .verbose = true }
#     println("${quiet.name} ${quiet.retries} ${quiet.verbose}")
#     println("${loud.name} ${loud.retries} ${loud.verbose}")
#     return 0
# }
```

```text
quiet 3 false
loud 3 true
```

A struct is a reference: binding it to another name shares the same object. The rules: §4 *Structs*.

## Enums

An enum lists its variants. Where the type is known, `.Name` stands for the variant, and `for` walks them all. `@displayable` lets a string show a variant by its name.

```vader
# module "main"
# import "std/io"
@displayable
Direction :: enum { North, East, South, West }

turn_right :: fn(d: Direction) -> Direction = match d {
    .North -> .East
    .East  -> .South
    .South -> .West
    .West  -> .North
}
# main :: fn() -> i32 {
#     println("${turn_right(.West)}")
#     for d in Direction {
#         println("${d}")
#     }
#     return 0
# }
```

```text
North
North
East
South
West
```

The rules: §4 *Enums*.

## Unions

`A | B` holds a value of either type, and a test with `is` tells which. A type that may be absent is a union with `null`, and `??` gives a value for the `null` case.

```vader
# module "main"
# import "std/io"
find :: fn(names: string[], wanted: string) -> i32 | null {
    for i in 0..<names.len() {
        if names[i] == wanted {
            return i32(i)
        }
    }
    return null
}
# main :: fn() -> i32 {
#     names :: ["ada", "grace", "barbara"]
#     println("${find(names, "grace") ?? -1}")
#     println("${find(names, "linus") ?? -1}")
#     return 0
# }
```

```text
1
-1
```

The rules: §4 *Unions* and §4 *Nullability*.

## Tuples

A tuple holds a fixed number of values of different types. `t.0`, `t.1` read them, and a binding can take them apart.

```vader
# module "main"
# import "std/io"
divide :: fn(a: i32, b: i32) -> [i32, i32] = [a / b, a % b]
# main :: fn() -> i32 {
#     result :: divide(17, 5)
#     println("${result.0} ${result.1}")
#     [quotient, remainder] :: divide(9, 4)
#     println("${quotient} ${remainder}")
#     return 0
# }
```

```text
3 2
2 1
```

The rules: §4 *Tuples* and §4 *Destructuring*.

## Distinct types

`Name :: f64` declares a new type held as an `f64` but not mixed up with one: crossing over takes an explicit conversion. A union on the right gives a plain alias instead.

```vader
# module "main"
# import "std/io"
Celsius :: f64
Fahrenheit :: f64
Reading :: Celsius | string

to_fahrenheit :: fn(c: Celsius) -> Fahrenheit = Fahrenheit(f64(c) * 9.0 / 5.0 + 32.0)

show :: fn(r: Reading) -> string {
    if r is string {
        return r
    }
    return "${f64(to_fahrenheit(r))} F"
}
# main :: fn() -> i32 {
#     println(show(Celsius(100.0)))
#     println(show("sensor offline"))
#     return 0
# }
```

```text
212.0 F
sensor offline
```

The rules: §4 *Distinct types* and §4 *Type aliases*.
