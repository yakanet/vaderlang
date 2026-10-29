# Values and bindings

A name is bound with `::` when it never changes and with `:=` when it does. Types are inferred; a literal takes the type its place asks for.

## Binding a name

`::` binds a name for good; assigning it again is an error. `:=` binds a name the code may rebind, and the compiler warns about one it never does.

```vader
# module "main"
# import "std/io"
# main :: fn() -> i32 {
    name :: "Vader"
    count := 0
    count += 2
    count = count * 10
    println("${name} ${count}")
#     return 0
# }
```

```text
Vader 20
```

The rules: §5 *Binding forms*.

## Writing the type

A type goes after the name: `name: T: value` binds for good, `name: T = value` may be rebound. Without one, an integer is an `i32` and a float an `f64`.

```vader
# module "main"
# import "std/io"
# main :: fn() -> i32 {
    small: u8: 200
    big: i64 = 3_000_000_000
    big += 1
    ratio :: 1.5
    println("${small} ${big} ${ratio * 2.0}")
#     return 0
# }
```

```text
200 3000000001 3.0
```

The rules: §5 *Binding forms* and §4 *Default integer*.

## Numbers

Integers are written in decimal, hexadecimal, binary or octal, with `_` between digits. Dividing two integers gives an integer.

```vader
# module "main"
# import "std/io"
# main :: fn() -> i32 {
    println("${0xFF} ${0b1010} ${0o17} ${1_000_000}")
    println("${7 / 2} ${7 % 2} ${7.0 / 2.0}")
    println("${i64(2_000_000_000) * 2}")
#     return 0
# }
```

```text
255 10 15 1000000
3 1 3.5
4000000000
```

A conversion is written as a call to the type, `i64(x)`. The rules: §3 *Literals* and §4 *Casts*.

## Strings

`$name` or `${expression}` inserts a value into a string. A raw string, `r"..."`, keeps its text as written. A `"""` block spans lines, without the indentation that lays it out in the source.

```vader
# module "main"
# import "std/io"
# main :: fn() -> i32 {
    who :: "world"
    println("Hello, $who!")
    println("${who.byte_len()} bytes")
    println(r"raw: ${who} \n stays")
    poem :: """
        roses are red
          violets are blue
        """
    print(poem)
#     return 0
# }
```

```text
Hello, world!
5 bytes
raw: ${who} \n stays
roses are red
  violets are blue
```

The rules: §3 *String literals* and §3 *String interpolation*.

## Characters

A `char` holds one code point, written between single quotes. Next to an integer, it counts as its code point. A `for` over a string walks its code points (with `std/string` imported).

```vader
# module "main"
# import "std/io"
# import "std/string"
# main :: fn() -> i32 {
    letter :: 'A'
    println("${letter} ${'a' - 'A'}")
    for c in "été" {
        println("${c}")
    }
#     return 0
# }
```

```text
A 32
é
t
é
```

The rules: §3 *Char literals*.

## Constants

At the top of a file, `::` declares a constant. The order does not matter: a constant may read one declared below it.

```vader
# module "main"
# import "std/io"
GREETING :: "Hello from ${NAME}"
NAME :: "Vader"
# main :: fn() -> i32 {
#     println(GREETING)
#     return 0
# }
```

```text
Hello from Vader
```

The rules: §5 *Binding forms*.
