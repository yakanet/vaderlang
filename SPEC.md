# Vader Language Reference

> **Status**: Draft, pre-1.0
> **Author**: Mathieu BROUTIN

This document describes the Vader language: its syntax, type system, execution model and standard library. The compiler is written in Vader and compiles itself: its internals are described in [`docs/ARCHITECTURE.md`](./docs/ARCHITECTURE.md), how it is rebuilt from a C seed in [`docs/BOOTSTRAP.md`](./docs/BOOTSTRAP.md), and the `vader` command in [`docs/TOOLING.md`](./docs/TOOLING.md).

---

## 1. Vision

### Mission

Vader is a general-purpose application language, strongly typed with type inference, and portable (Linux, macOS, Windows, WebAssembly). It is designed to stay simple to learn while allowing performant programs through a transparent compilation pipeline.

### Tagline

> *"Vader: applicative, simple, portable. The discipline of static typing, the ergonomics of a script."*

### Explicit non-goals

- **No OOP**: no inheritance, no classes, no methods. UFCS (`a.f(b)` is `f(a, b)`) gives the method-call syntax.
- **No visible pointers**: no pointer arithmetic, and memory layout is opaque.
- **No implicit `null`**: a nullable value has an explicit union type, `T | null`.
- **No exceptions**: errors are values, returned in a union with the success type.
- **No text macros and no runtime reflection**: metaprogramming goes through typed `@comptime`.

### Philosophy

- **Simplicity over exotic features**: no feature for its own sake.
- **Reading over writing**: code reads top to bottom. Generics use the familiar `<T>` of Java and C#; a local rule tells it apart from the comparison `<` (§4 *Generics*).
- **Compile-time errors over run-time errors**: string interpolation, for instance, is type-checked at compile time.
- **Rich diagnostics**: every phase reports structured diagnostics (`docs/TOOLING.md` *Diagnostics*), keeps going after an error when it can, and writes messages that read well in a terminal and in an editor.
- **Evolvability**: the pipeline is easy to extend, and every intermediate representation can be dumped.

### Vader 1.0, the bootstrap edition

The 1.0 edition is the set of features the compiler needs to compile itself ([`docs/BOOTSTRAP.md`](./docs/BOOTSTRAP.md)). It has not been declared yet; until then, the language changes without deprecation. From 1.0 on:

- v1.x: backward-compatible changes (new features, optimisations);
- v2.0: breaking changes, a new edition and a new bootstrap.

---

## 2. Compilation Model

A program is compiled as a whole. Every module is parsed, resolved and type-checked before any code runs, and `@comptime` values are computed at build time (§14).

### Exposed execution modes

The compiled program runs in one of two ways:

- on the Vader virtual machine, with `vader run` and `vader test`;
- as a native binary, through generated C and the system C compiler, with `vader build`.

A WebAssembly target is planned (§17). The command line is described in `docs/TOOLING.md`.

### Run-time checks

The program stops, in every build mode, when:

- an array index is out of bounds;
- an integer division or remainder has a zero divisor;
- a conversion into a range type, an enum or `char` gets a value outside the target type (`Hour(x)`, `E(x)`, `char(x)`).

`INT_MIN / -1` gives `INT_MIN`. A float division follows IEEE 754 and can give `inf` or `nan`.

An integer `+`, `-`, `*` or unary `-` that overflows also stops the program, except in a release build, where it wraps (§4 *Integer overflow*).

A check runs whether or not its value is used: `xs[i]` or `a / b` written as a statement still stops the program.

There is no null check at run time: narrowing settles nullability at compile time.

---

## 3. Lexical Structure

### Source encoding

Source files are UTF-8. A leading BOM is ignored and takes no column.

A byte sequence that is not valid UTF-8 is an error, reported once per file, at the first malformed run, with the number of runs. The lexer reads each run as one U+FFFD, one column wide, and continues (§4 *Strings*).

### Shebang

A `#!` line is allowed on the first line only, and the lexer skips it. Anywhere else, `#!` is a lexical error. With `#!/usr/bin/env -S vader run`, a script runs directly on Unix.

```vader
#!/usr/bin/env -S vader run
module "main"
main :: fn() -> i32 { return 0 }
```

### Comments

```vader
// line comment, terminates at the next newline

/* block comment */

/*
   /* nested block comments are allowed */
   the outer comment continues here
*/
```

Block comments nest: a block comment ends at the `*/` that matches its `/*`.

### VaderDoc

A doc comment starts with `///`. Consecutive `///` lines form one doc block, attached to the declaration that follows. `/** ... */` is an ordinary block comment.

After the description and a blank line, a doc block may use these tags, one per line:

| Tag        | Meaning                                                                    |
|------------|----------------------------------------------------------------------------|
| `@param`   | One parameter: `@param <name>  <description>`.                             |
| `@return`  | The return value. Omitted for `void`.                                      |
| `@error`   | Which error variants can be returned, and when.                            |
| `@example` | A usage example: the indented lines that follow, in runnable Vader.        |

```vader
/// Parse `s` as a base-10 `i32`. No prefix, no underscores, no leading
/// `+` sign; a leading `-` is accepted.
///
/// @param s  the digits-only input.
/// @return   the parsed integer.
/// @error    `ParseError` on empty input, malformed digit, or overflow.
/// @example
///   n :: parse_int("42")   // 42
export parse_int :: fn(s: string) -> i32 | ParseError
```

Every exported function of the standard library has a doc block in this form.

### Identifiers

`[a-zA-Z_][a-zA-Z0-9_]*`, case-sensitive. Identifiers are ASCII only.

### Reserved keywords

```
fn struct trait implements enum
if else match is for in return yield await defer break continue
import as
export
true false null
self
```

Also reserved:

- `const`, reserved: it cannot be used as an identifier.
- `module`, a keyword only at the start of a file's module declaration.
- `void`, which names the type of expressions that produce no value (§6 *Declaration*). It cannot name a function, struct, parameter, local, type parameter, pattern binding or namespace import.
- `Self`, a type name rather than a keyword. Inside a `trait` or `implements` body it denotes the implementing type. Using it elsewhere is an error. The receiver parameter `self` is a keyword.

### Literals

#### Integer literals

- Decimal: `42`, `1_000_000`
- Hexadecimal: `0xFF`, `0xff`, `0xFF_FF` (case-insensitive after `0x`)
- Binary: `0b1010`, `0b1010_1010`
- Octal: `0o755`, `0o7_5_5`

An integer literal is *free*: it takes the integer type its context requires, `i32` by default (§4 *Default integer*). There is no type suffix (`42i32` and `42_i32` are errors); give the type through the slot, an annotation or a cast.

Underscores separate digits, but never two in a row (`1__000`) and never at the start or end of the digits (`0x_FF`, `42_`).

#### Float literals

- Forms: `3.14`, `0.5`, `00.5` (leading zeros allowed), `1.0e-10`, `1.5E+3`.
- The point needs digits on both sides: `5.` and `.5` are errors; write `5.0` and `0.5`.
- A float literal is free like an integer literal, `f64` by default (§4 *Default integer*). There is no type suffix (`3.14f32` is an error); annotate the slot to get an `f32`.
- Underscores follow the integer rules.

#### Boolean / null

`true`, `false` and `null` are keywords.

#### Char literals

```vader
'a'        // ASCII codepoint
'é'        // any Unicode codepoint
'\n'       // escape sequence
'\u{1F600}'  // explicit codepoint
```

- Escapes: `\n`, `\t`, `\r`, `\\`, `\'`, `\0`, and `\u{H...}` with 1 to 6 hex digits. The value must be a Unicode scalar value: a surrogate (`D800` to `DFFF`) or a value above `10FFFF` is an error, in a char literal as in a string literal.
- A char literal holds exactly one code point: `''` and `'ab'` are lexical errors.
- A char literal is free. In an integer context, range types included, it takes that type and holds its code point, which must fit: with `b: u8`, `b == '/'` and `d: 48..=57: '5'` are valid, `b == '💩'` is an error. Elsewhere it is a `char`.
- Arithmetic on char literals works on their code points and gives an integer: `'a' - 'A'` is `32`.
- There is no `b'X'` byte literal: `'X'` does the job.
- A `char` variable keeps the type `char` and never converts implicitly. `u8(c)` converts it, truncating code points above `0xFF`.

#### String literals

Four forms:

```vader
"plain"                        // simple string, supports interpolation
r"raw"                         // raw string, no interpolation, no escape processing
"""
multi-line
"""                            // triple-quoted, supports interpolation, may span newlines
r"""raw multi-line"""          // raw and triple-quoted: may contain `"`, no interpolation, no escapes
```

- Escapes in `"..."` and `"""..."""`: `\n`, `\t`, `\r`, `\\`, `\"`, `\$` (a dollar sign), `\s` (a space), `\0`, `\u{H...}`.
- In a raw string, a backslash is an ordinary character (`\n` stays two characters) and `${...}` is plain text.
- A `"""` or `r"""` whose opening delimiter ends its line is a **text block**. That line break is not part of the text, and neither is the indentation that only lays the text out in the source:
  - every line loses the indentation all its lines share. The least indented line holding more than spaces and tabs sets it, and so does the closing `"""` when it stands alone on its line, so moving it left keeps that much indentation;
  - every line loses its trailing spaces and tabs, and a line of spaces and tabs only ends up empty;
  - a space and a tab count as one character each. An escape is text, never indentation: `\s` keeps a trailing space, `\t` a leading tab;
  - a line break inside `${...}` is no line of the text, and an interpolated value is never cut;
  - every line break in the text, CRLF or a lone CR, reads as `\n`.
- A `"""` with text after its opening delimiter, on the same line, keeps every character.

```vader
body :: fn(name: string) -> string = """
    fn ${name}
      return
    end
    """                        // "fn f\n  return\nend\n" for name = "f"
```

#### String interpolation

`${expr}` inside a non-raw string inserts the value of any expression. Interpolations nest: `"outer ${"inner ${x}"}"`.

A single identifier needs no braces: `"Hello, $name"` is `"Hello, ${name}"`. Anything longer (a field access, a call) needs `${...}`.

### Operators

```
Arithmetic   : + - * / %
Wrapping     : +% -% *%  (integers only: the result wraps around the operand's width)
Bitwise      : & | ^ ~ << >>  (a shift's count keeps its low 5 bits, 6 for a 64-bit type: `1 << 33` on an `i32` is 2, `u8(1) << 9` is 0)
Comparison   : == != < <= > >=
Identity     : === !==   (same object; references only, §4 *Identity*)
Membership   : in   (sugar for `right.contains(left)`)
              !in   (sugar for `!right.contains(left)`)
Type test    : is Type   (in `match` arms and in `if`/`else` conditions; narrows the scrutinee)
              !is Type   (same as `!(x is Type)`)
Logical      : && || !
Assignment   : =  (also compound : += -= *= /= %= +%= -%= *%=, each `lhs op= rhs` meaning `lhs = lhs op rhs`, `lhs` evaluated once)
Declaration  : x :: value   x := value   x: T: value   x: T = value   (§5 *Binding forms*)
Range        : 0..<10 (exclusive)  0..=10 (inclusive)
Cast         : Type(expr) (numeric ↔ numeric, char ↔ integer)
Field access : .name
Index access : [expr]
```

Characters compare by code point. Strings compare by bytes, which for UTF-8 is also code-point order.

#### Membership: `in`

`x in c` calls `c.contains(x)` from the `Contains<T>` trait (§4 *Operator overloading*), and `x !in c` negates it.

With a type on the right, `in` tests the values of that type:

- `x in Hour` checks an integer against the bounds of an integer type (§4 *Range types*);
- `x in Weekday` checks against the values of an enum (§4 *Enums*);
- `x in char` checks against the Unicode scalar values (§4 *Casts*).

The left operand must have the element type that `contains` expects. With `r: Range<i32>`, `n in r` is an error for `n: i64` and for an `i32 | null`, as `r.contains(n)` would be. A free literal on the left takes the element type: `4_000_000_000 in r` is valid for `r: Range<i64>`.

A literal range or array on the right takes the type of the left operand (its backing type, for a distinct type). A union on the left gives it no type.

```vader
n in 5_000_000_000..=6_000_000_000   // n: i64, the range is a Range<i64>
b in [' ', '\t']                     // b: u8, the array is a u8[]
b in -1..=3                          // b: u8, error: -1 is not a u8
s in "a"..="m"                       // error: Range<string> does not implement Contains
```

#### Assignment

A variable's type is fixed by its declaration. Every assignment (`x = v`, `arr[i] = v`, `m[k] = v`, `obj.f = v`, and the compound forms) must give a value assignable to the declared type, `Into` conversions included, as for the initializer.

The check uses the declared type even where the variable is narrowed. Inside `if x is A { ... }`, `x = b` is allowed when `b` fits the declaration of `x`, and it ends the narrowing.

### Operator precedence

From the tightest (level 1) to the loosest:

| Level | Operators                              | Associativity |
|-------|----------------------------------------|----------------|
| 1     | postfix `.`, `[]`, `()`                | left           |
| 2     | prefix `-`, `!`, `~`                   | right          |
| 3     | `*`, `/`, `%`, `*%`                    | left           |
| 4     | `+`, `-`, `+%`, `-%`                   | left           |
| 5     | `<<`, `>>`                             | left           |
| 6     | `&`                                    | left           |
| 7     | `^`                                    | left           |
| 8     | `\|`                                   | left           |
| 9     | `..<`, `..=`                           | non-assoc      |
| 10    | `<`, `<=`, `>`, `>=`, `==`, `!=`, `===`, `!==`, `is`, `!is`, `in`, `!in` | non-assoc      |
| 11    | `&&`                                   | left           |
| 12    | `\|\|`                                 | left           |
| 13    | `??` (null-coalescing)                 | left (non-chaining) |
| 14    | `=` (statement-level only)             | n/a            |

Non-associative operators do not chain: `a == b == c` is a parse error; write `(a == b) == c`.

A cast `Type(expr)` is a call, at level 1.

A `-` written directly against a number literal, where an operand is expected, belongs to the literal. A postfix then applies to the negative value: `-5.to_string()` is `"-5"` and `-5.abs()` is `5`. With anything in between, `-` is the prefix operator and negates the whole call: `-x.abs()`, `-(5).abs()`, `- 5.abs()`. After an operand, `-` is a subtraction: `a -5` is `a - 5`.

### Type tests and narrowing

`x is T` tests the run-time type of a value. In the branch where the test holds, `x` is narrowed to `T`.

With a union on the right, `is` tests membership: `x is A | B`, or `x is AB` for an alias `AB :: A | B`, holds when the value is an `A` or a `B`, and narrows `x` to that union. Given `U :: A | B | C`, a `U` holding a `B` satisfies `v is AB` and can then be passed where an `AB` is expected.

With a trait on the right, `x is Equals` holds when the value's type implements the trait. That covers the primitives' impls and an enum's built-in `Equals` and `Hash`, and a generic impl counts only where its bounds hold. The branch where the test fails no longer holds those types: after `if v is Equals { return }` on `v: i32 | Point`, `v` is a `Point` (when `Point` has no `Equals`). A value held as a trait or as `any` is tested by its struct's impls alone.

A test that can never hold is an error: `v is D` with `v: A | B`.

An `is` test binds no name. It narrows the name or field chain it tests, in place. To test a value without a name, bind it first:

```vader
r :: f()
if r is T {
    use(r)                 // `r` is a `T` here
}
```

`x is T as y` is a parse error.

#### Conditions with `&&`, `||` and `!`

- **`&&`**: in `if x is T && rest`, `x` is narrowed in `rest` and in the then-branch, so `if x is Circle && x.radius > 0` type-checks. The else-branch is not narrowed: a false `a && b` does not say which operand was false.
- **`||`**: the else-branch narrows every binding an operand tested. After `if x is A || x is B`, the else-branch sees `x` without `A` and `B`. The then-branch narrows only when every operand tests the same binding, to the union of the tested types: there `x` is `A | B`. `if x is A || flag` narrows nothing in the then-branch, and `x` in the else-branch.
- **Right operand**: it sees the outcome of the left one. The right of `&&` sees the left as true, the right of `||` sees it as false, so `y == null || y.a > 0` type-checks.
- **`!`** swaps the two branches. The rules compose at any depth: `if !(y is A || y is B)` sees `y` as neither `A` nor `B`.

A guard that leaves the block narrows the rest of the block like an else-branch:

```vader
if x is A || x is B {
    return
}
// `x` is neither an `A` nor a `B` here
```

A loop condition narrows the loop body. In `for cursor != null { ... cursor = cursor.next }`, `cursor` is non-null until the assignment. The code after the loop is not narrowed, since a `break` can leave while the condition still holds.

#### Guards

A *guard* is a function of the same module whose body is a single condition on its parameters: `= cond`, returning `bool`, not generic. Calling a guard in a condition narrows the arguments as `cond` narrows the parameters, in both branches.

```vader
Weekday :: Int in 0..=6
is_weekend :: fn(d: Weekday) -> bool = d >= 5
is_walk :: fn(a: Activity) -> bool = a is Walk
has_name :: fn(n: string | null) -> bool = n != null

if is_weekend(d) {
    // `d` is a `5..=6` here, and a `0..=4` in the else-branch
}
```

- Only an argument that is a binding or a field chain is narrowed.
- A guard can be declared after its call, called as `d.is_weekend()`, and built on another guard.
- In another module, a guard is an ordinary predicate and narrows nothing; `@returns` makes it narrow everywhere.
- A function with a block body is not a guard. A condition on a field of a parameter (`b.label != null`) does not narrow the argument.

#### Declared guards: `@returns`

`@returns(cond)` declares that a free function returns the value of `cond`. Its calls narrow their arguments as a guard's do, in every module.

The compiler checks the body against `cond` at each value it returns. Where the function returns true, `cond` must hold; where it returns false, `cond` must fail:

```vader
@returns(d in Weekend)
is_weekend :: fn(d: Weekday) -> bool = d >= 4   // error: true for d = 4
```

A block body is checked at each `return` and at its trailing value, with the narrowings in force there. An `if` value is checked branch by branch.

The following are errors:

- a function that is generic, does not return `bool`, or has no body;
- a body that assigns a parameter, directly or from a lambda;
- a condition that says nothing about the parameters;
- more than one condition, or `@returns` on anything but a free function.

#### Declared postconditions: `@ensures`

`@ensures(cond)` declares that `cond` holds once the function returns normally. After a call written as a statement, or as the initializer of a declaration (`r :: f(n)`), the arguments are narrowed as `cond` narrows the parameters, for the rest of the block, in every module.

```vader
@ensures(h in Hour)
require_hour :: fn(h: i64) -> void {
    if h !in Hour {
        panic("not an hour: ${h}")
    }
}

require_hour(n)
label(n)                   // `n` is an `Hour` here
```

- Only an argument that is a binding no lambda assigns is narrowed.
- Nothing is checked at run time. The compiler checks the body at each `return` and at its end: `cond` must hold there. Stopping the program where `cond` fails satisfies it, as `require_hour` does, and so does returning a call to a function that ensures the same condition.
- The function may return any type, but its body must have finished when a call returns: a generator, a function that uses `await` or a function without a body is an error.
- The other rules of `@returns` apply.

#### How long a narrowing lasts

A narrowing lasts as long as nothing can have changed what it tested. An assignment to the narrowed name or field ends it, unless the new value still fits (*Assignment*, above). It also ends:

- after a call, for every field narrowing (`a.s`, `self.items`) and for each local that some lambda assigns, since a call can write any object it reaches. Writing through a user `IndexSet` (`m[k] = v`), `await` and `yield` count as calls. A conversion `T(x)` does not.
- inside a loop, for what an earlier iteration can have changed: field narrowings, and locals the body assigns. The iterable of `for x in e` is evaluated once, before the loop, and keeps the narrowing.
- after a field assignment through any path (`b.s = v`, `xs[i].s = v`), for every narrowing through a field of that name: `b` may be the same object as `a`.
- after a call in the right operand of `&&` (or of `||`, on its false side), for what the left operand narrowed: in the rest of the condition and in the branch.
- in code that runs later than written (a lambda body, a `defer` body), which keeps only the narrowings of bindings that are never reassigned. Under `for c != null { ... c = c.next }`, `defer println(c.value)` is an error.

The narrowing of a local that nothing else assigns survives all of these. To keep a narrowing across a call, bind the field to a local first:

```vader
s :: a.s
if s is Circle {
    reset(a)
    use(s.r)               // `s` still holds the value that was tested
}
```

### Statement separators

Statements in a block are separated by newlines (*Newline-significant*, below). `;` is not a separator.

A newline right after `{` is ignored, so a block can start on the next line.

### Trailing commas

Trailing commas are allowed in every comma-separated list: function arguments, function parameters, struct literal fields, struct definition fields, array literals, match arms, generic argument lists, and import modifier lists (`import "p" { x as y, }`).

### Newline-significant

A newline ends a statement, except in these five cases, where it is ignored:

1. Inside an open `(` or `[`, and inside a `${...}` interpolation. Inside a `{ }` block, newlines still separate statements, even when the block is inside brackets (the body of a lambda passed as an argument).
2. After an operator that still needs its operand: `+`, `-`, `*`, `/`, `%`, `<`, `<=`, `>`, `>=`, `==`, `!=`, `===`, `!==`, `&&`, `||`, `&`, `|`, `^`, `<<`, `>>`, `+%`, `-%`, `*%`, `??`, `..<`, `..=`, and the spread `...`. A newline after `!` is not ignored.
3. After a comma.
4. After a token that needs a right-hand side: `=`, `:`, `->`, `::`, `:=`, and the compound assignments `+=` `-=` `*=` `/=` `%=` `+%=` `-%=` `*%=`.
5. Before an operator with no prefix form. When the next line starts with `+`, `*`, `/`, `%`, `+%`, `-%`, `*%`, `^`, `??`, `==`, `!=`, `===`, `!==`, `<`, `<=`, `<<`, `>`, `>=`, `>>`, `&&`, `||`, `&` or `|`, it continues the previous expression, in a `{ }` block too. Comment lines in between are skipped. A compound assignment (`+=`, `*=`, ...) does not continue the previous line, nor do `-`, `~`, `!` and `.`, which can start an expression.

There is no backslash continuation: a `\` at the end of a line is a lexical error. To break a long expression, use parentheses or break before or after a binary operator.

```vader
// OK: break inside parens
total :: (a +
          b +
          c)

// OK: break after operator
total :: a +
         b +
         c

// OK: break before a leading infix-only operator
if a == 1
    && b == 2
    && c == 3 {
    // ...
}
label :: if verbose {
    "value "
        + "${n}"
} else {
    "${n}"
}
name :: first_name(user)
    ?? return "anonymous"

// OK: break after comma
list :: [
    1,
    2,
    3,
]

// error: backslash is not a continuation
x :: a + \
     b           // lexer error: stray '\'
```

---

## 4. Type System

### Primitive types

| Category | Types |
|----------|-------|
| Boolean | `bool` |
| Unsigned integers | `u8`, `u16`, `u32`, `u64` |
| Signed integers | `i8`, `i16`, `i32`, `i64` |
| Floats | `f32`, `f64` |
| Text | `char` (a Unicode scalar value), `string` (UTF-8) |
| Foreign pointer | `CPointer` (§13) |
| Null | `null` |
| Metatype | `type` (compile time only, below) |

```vader
flag: bool: true
byte: u8: 255                    // u8 is Int in 0..=0xFF, declared in std/core
offset: i64: -9000000000
ratio: f32: 0.5
letter: char: 'é'                // one Unicode scalar value
name: string: "héllo"            // UTF-8
missing: string | null: null

name.len()                       // 5, an i64
@size_of(u16)                    // 2, an i64
count: int: 0                    // error: there is no type `int`
```

- The eight integer types are ranges of `Int` (*Range types*, below), declared in the `std/core` prelude: a program built without the standard library has none of them.
- Each numeric type has one name, giving its kind and width: no `int`, `long`, `float`, `double` or `byte`.
- No integer type takes the width of the target: a foreign `size_t` is a `u64` that `@c_type` spells for C (§13), and a `CPointer` reads as an `i64` or a `u64`.
- A length, an index and a size are an `i64` on every target: `len()`, `byte_len()`, `@size_of(T)`.

```vader
width :: fn<T: type>(x: T) -> i64 = @size_of(T)

width(byte)                      // 1: T is u8, a value of type `type`
word :: u16                      // a local alias of a type written out
@size_of(word)                   // 2
@size_of(@type_of(offset))       // 8: the static type of offset, unevaluated
picked :: if flag { u8 } else { u16 }   // error: a local of type `type` is only a type written out
```

`type` is the **metatype**, whose values are Vader types, known only at compile time: in a generic head `<T: type>` and as the result of a reflection intrinsic such as `@type_of(x)`. A local of type `type` must be an alias of a type written out (`name :: <type-expr>`).

### Type aliases

A type alias, `Foo :: <type-expr>`, is a constant whose value is a type expression, built from type names and the operators `|`, `&`, `[]` and `fn(...) -> ...` (`type` is not a keyword). Its name stands wherever a type is expected. Some right-hand sides declare a distinct type instead (*Distinct types*, below).

A generic alias puts its type parameters in angle brackets between the name and `::`: `Foo<T> :: <body>`. There is no bracket or parenthesis form.

```vader
Mixed :: i32 | string        // alias: a constant whose value is a type
Maybe<T> :: T | null         // generic alias: type parameters after the name
Pair<A, B> :: A | B

opt: Maybe<i32>: 42
```

#### Distinct types

`Name :: <type-expr>` declares a **distinct type**, a nominal newtype, when the right-hand side is a primitive other than `void` and `null`, an array (`u32[]`), a struct (`Rgb`) or a tuple (`[i32, i32]`). A union, an intersection or a function type on the right gives a transparent alias.

On the right, a bracketed list of two or more types is a tuple; with a value among its elements (`["a", "b"]`), it is an array constant.

```vader
Celsius :: f64            // distinct, not interchangeable with f64
Handle  :: i32            // distinct
BigInt  :: u32[]          // distinct, over an array
Color   :: Rgb            // distinct, over a struct
Coord   :: [i32, i32]     // distinct, over a tuple
Mixed   :: i32 | string   // transparent alias (union)
```

A distinct type is held exactly as its backing type at run time.

- Conversions are explicit both ways and change nothing at run time: `Celsius(x)` wraps an `f64` and `f64(c)` unwraps it. An implicit one is an error.
- Structural operations forward to the backing, while trait impls stay nominal (`BigInt implements Mul<u32>` does not collide with the array repeat, `T[] implements Mul<i64>`):
  - array: indexing, the built-in array functions (`.len()`, `.push()`, ...), `for x in n`, and the conversion of a `[...]` literal;
  - struct: field access `c.r` and construction `Color { ... }`, with the backing's fields;
  - tuple: positional access `p.0`, construction from `[a, b]`, and destructuring `[a, b] :: p`.
- A distinct over an object is not a value of a trait it implements: passing a distinct over a struct, an array, a tuple or a function where its trait is expected (a `Color` for a `Display`) is an error, as an array element or into a union too. Its own impls are reached by a direct call (`c.to_string()`).
- Arithmetic uses the distinct's own impl first, then its backing's: `Instant implements Add<Duration>` drives `i + d`, while `+`, `-`, `*`, `/` and `%` on a `Meters :: i64` with no impl of its own are those of `i64`. A literal beside it is then a value of the backing: `m + -1` is an `i64` sum, and `c + -1` with `Code :: u32` is an error, as on a `u32`.
- A distinct that defines the operator for another right operand does not fall back to its backing: `instant + 5` is an error.
- A distinct combines only with itself and its backing. Any operator, `==` included, between two distinct types that are not one another's backing is an error: `Meters + Seconds`, although both are `i64`. A `Km :: Meters` combines with `Meters`. Against its backing, a distinct compares and computes as that backing (`path == ""`, `d < i64(3)`), or through its own impl (`Equals`, `Comparable`, operators) when it defines one.
- `@comptime Name :: <type>` is the exception: it declares a transparent alias, usable at compile time (`@size_of(Name)`), never a newtype.
- Reflection follows the backing: `@size_of`, `@align_of` and `@type_kind` of a distinct give those of its backing.

### Default integer

```vader
x :: 42                          // an i32: no context
y :: 2.5                         // an f64
big :: 9000000000                // error: does not fit an i32, the default
wide: i64: 9000000000            // the annotation gives the type
n + 9000000000                   // an i64, with n: i64

low: i8: -128                    // one literal, not a negation
over: u8: 300                    // error: 300 is not in u8
unsigned: u32: -1                // error: -1 is not in u32
```

An integer literal with no concrete context is an `i32`, a float literal an `f64`.

A literal in a concrete integer context is checked against that type at compile time, as a char literal is (§3 *Char literals*), and never truncates or wraps.

```vader
show :: fn(v: u8 | string) -> string = "${v}"
pick :: fn(v: i32 | i64 | string) -> string = "${v}"

show(5)                          // 5 is a u8, the union's only integer
5.show()                         // the same, as a UFCS receiver
show(300)                        // error: 300 is not in u8
pick(5)                          // 5 is an i32, the default
v: u8 | i16 | string: 5          // error: u8 or i16; write u8(5)
```

A literal into a union takes the default of its family (`i32`, `f64`, or `char` for a char literal) when the union has it, otherwise the union's only member of that family.

### Implicit numeric coercion

```vader
b: u8: 200
i: i32: 1000
w: i64: b                        // a u8 into an i64: nothing to write
n: u8: i                         // error: an i32 into a u8 takes u8(i)

b + i                            // 1200, an i32: the type that holds the other
u: u32: 7
u + i                            // error: neither u32 nor i32 holds the other

describe :: fn(x: i32) -> string = "i32"
describe :: fn(x: i64) -> string = "i64"
describe(b)                      // "i32": the tightest parameter wins
```

An integer type goes into any integer type that holds all its values, with no conversion written. This holds in every slot (an argument, a return value, a field, an initializer, an assignment, an array or tuple element) and into a union through such a member.

An operation or comparison between two integer types is computed in the type that holds the other; when neither holds the other, it is an error. Where paths join (the branches of a value `if` or `match`), the same rule applies.

Among overloads, the parameter that holds the argument most tightly, in the fewest bits, wins. Two parameters of as many bits tie.

```vader
bytes: u8[]: [1, 2]
ints: i32[]: bytes               // error: no widening inside an array
maybe: i32 | null: b             // a bare u8 goes into i32 | null
r: f64: i                        // error: an integer into a float takes f64(i)
```

The widening does not reach through a container, a function type or a union: a `u8 | null` is not an `i32 | null`. A float never widens: an `f32` into an `f64`, and an integer into a float, take a cast.

### Float bit patterns

A cast converts the value (`u64(3.7)` is `3`). The **IEEE 754 bit pattern** of a float, the same bits unconverted, is read with `to_bits` and `from_bits`:

```
x: f64: 3.0
bits :: x.to_bits()        // u64 0x4008000000000000, the exact IEEE bits
back :: bits.from_bits()   // f64 3.0, round-trips bit-for-bit
```

Both are in the prelude: `f64.to_bits() -> u64` (`FloatBits`), `u64.from_bits() -> f64` (`BitsFloat`), `f32.to_bits() -> u32` (`Float32Bits`) and `u32.from_bits() -> f32` (`Bits32Float`).

### Numeric-literal context-sensitivity

```vader
Page :: struct {
    size: u64 = 4096                    // a field default: a u64
}
larger :: fn<T: Comparable>(a: T, b: T) -> T = if a > b { a } else { b }

limit: u16: 1000                        // a typed declaration: a u16
mask: u64: ~0                           // through ~: 18446744073709551615
next :: limit + 1                       // the other operand: a u16
top :: larger(limit, 3)                 // T is u16, so 3 is a u16
size :: if flag { 0 } else { capacity } // the other branch: a u64, with flag: bool, capacity: u64
limit + 70000                           // error: 70000 is not in u16

zero :: fn<T>(x: T) -> T = 0            // error: T is not a numeric context
```

A free literal takes the type of the slot it lands in, with no conversion at run time. The type comes from:

- the slot: a typed declaration, a field default, a call argument, a struct literal field, a `return` under a declared return type, an index (the key type of the `Index` impl), and the other operand of a comparison or arithmetic operation when it has a concrete numeric type;
- the outer slot, through unary `-` and `~`;
- a generic call: the type substituted once the type parameters are inferred, in a plain call, a generic UFCS call and a call through a namespace import;
- the other branch of an `if`, when that one has a concrete numeric type.

### Type coercion via `Into`

A value of type `S` that reaches a slot of type `T` it is not assignable to is converted by a call to `into` when `S` implements the `std/core` trait `Into<T>`:

```vader
Into :: trait<Target> {
    into :: fn(self) -> Target
}
```

#### Sites of implicit coercion

- A call argument, when the parameter is annotated.
- A `return v`, or a block's trailing expression, under a declared return type.
- The initializer of a typed declaration `x: T = v`.
- A struct literal field whose declared type differs from the value's.
- The receiver of `a.f(...)`, when no function takes `a` as it is (§6 *UFCS (Uniform Function Call Syntax)*).

#### Explicit form

In `Target(value)`, a numeric or `char` target is a cast (`u32(x)`, `i64(c)`); any other target, or a numeric target given a non-numeric value, calls `into`.

#### Rules

- The target is a struct, an enum, a primitive or a trait, never a union or a type parameter. For a trait target, `Into` applies only when the type does not implement the trait (`T[]` into `Iterator<T>`).
- `T implements Into<T>` is an error at the impl.
- A conversion calls one `into`: `S` into `U` and `U` into `T` do not take an `S` into a `T`.
- A second impl for the same `(Source, Target)` is an error.
- Overload resolution comes first: `Into` is considered only when no overload matches as is.

#### Built-in coercions

- `T[]` into `Iterator<T>`, through `T[] implements<T> Into<Iterator<T>>` (`std/core`).
- `T` into `string` when `T: Display`, by its `to_string`, through `T implements<T: Display> Into<string>`. Interpolation (`"${value}"`) renders through `Display` without `Into`.

#### Resolution order at a coercion site

1. `S` is assignable to `T` (a subtype, a trait `S` implements, a free literal taking its type): nothing converts.
2. Otherwise, an impl `S implements Into<T>`, under the rules above.
3. Otherwise, it is an error.

### Integer overflow

```vader
b: u8: 250
b + 10                           // stops the program, or 4 in a release build
b.add(10)                        // the same as b + 10
b +% 10                          // 4 in every mode
0 -% b                           // 6: -b, wrapped

LIMIT: u8: 250
@comptime NEXT :: LIMIT + 10     // error: overflow while folding a constant
LATER :: LIMIT + 10              // computed at run time: stops the program, or 4 in a release build
```

An integer `+`, `-`, `*` or unary `-` whose result leaves its type, at that type's own bounds, stops the program, except in a release build, where it wraps, in two's complement at the type's width (`docs/TOOLING.md` *`vader build`*).

An overflow in a constant the compiler folds is a compile error.

The **wrapping operators** `+%`, `-%` and `*%` (and `+%=`, `-%=`, `*%=`) wrap in every mode and when a constant folds, at the width of their operands, 8 and 16 bits included. They take integer operands only, and no trait overloads them. There is no wrapping negation.

A division by zero stops the program in every mode (§2 *Run-time checks*). A narrowing cast truncates (*Casts*, below), and a shift never stops the program (§3 *Operators*).

### Range types

A **range type** holds the integers of an interval. It is declared over the abstract integer `Int`, or written in place of a type:

```vader
Hour :: Int in 0..=23
Offset :: Int in -12..=14

Clock :: struct {
    hour: Hour
    minute: 0..<60
}
```

- The bounds are integer literals, the least first, within `i64` (the greatest may reach `u64.max`). `Int in 5..=1`, a bound that is not a literal, and a base other than `Int` are errors.
- `Int` only names the base of a range: a value, a parameter or a field typed `Int` is an error.
- `Name :: Int in ...` is a transparent name for the range; `Slot :: Hour` declares a distinct type (*Distinct types*).
- In value position, `r :: 0..=23` is a `Range<i32>` value, not a type.

Each machine integer is the range of its values (`u8` is `Int in 0..=255`), and a range with the same bounds is that integer: `Octet :: Int in 0..=255` is a `u8` shown under its name, with the closed and checked arithmetic of a `u8` (*Integer overflow*).

A range is stored, in a field or an array alike, in the narrowest integer that holds it, unsigned when it has no negative value: `Hour` is a `u8`, `Offset` an `i8`. Its `Display`, `Equals` and `Hash` are that integer's.

A literal stored in a range must be one of its values, wherever it goes: `h: Hour = 30` is an error, and so is `30 ->` in a `match` on an `Hour`.

A range widens to any integer type that holds all its values (*Implicit numeric coercion*, above). Through a function type or a union, it widens only to the integer it is stored in: a `fn() -> Hour` is a `fn() -> u8`.

```vader
next_hour :: fn(h: Hour) -> Hour = (h + 1) % 24   // h + 1 is a 1..=24

part_of_day :: fn(h: Hour) -> string {
    if h < 12 {
        return "morning"                           // h is a 0..=11 here
    }
    return "afternoon"                             // and a 12..=23 here
}

parse_hour :: fn(n: i64) -> Hour | null {
    if n in Hour {
        return n                                   // n is an Hour: nothing left to check
    }
    return null
}
```

Arithmetic on ranges is computed over the integers, and its type is the interval of its possible results.

- Storing a result in a narrower range is an error: `next: Hour = h + 1` and `h += 1` are rejected.
- A local takes the type of its first value: after `next := h + 1`, `next = next % 24` is an error, since `0` is outside `1..=24`. Annotate it (`next: i32 = h + 1`).
- A primitive operand absorbs a range that fits in it: `h * x` with `x: i32` is an `i32`.
- A bitwise operation needs a machine integer: `h & 1` is an error, `u8(h) & 1` is not.

A comparison narrows a range where it holds, as `is` narrows a union (§3 *Type tests and narrowing*).

`@min(T)` and `@max(T)` are the bounds of an integer type (`@max(Hour)` is `23`). `x in T` tests an integer against them and, where it holds, narrows `x` to `T`, a primitive `x` too, with no check that could stop the program. `in`, `@min` and `@max` also take `char` and an enum without variant data; on any other type they are errors.

`Hour(x)` converts an integer into the range and stops the program, in every build, when `x` lies outside it. A literal outside the range, a float, and a source that holds none of its values are errors. A distinct over a range converts as the range does, and back (`Hour(s)`) with nothing to check.

In a generic function, a `T` bound to a range is checked as `Hour(x)` checks it wherever a call or an operator gives one back: `fn<T: Add>(a: T, b: T) -> T = a + b` stops at `Hour` values 20 and 10. There, inside a type argument, a range is read as its integer (a `Box<Hour>` is a `Box<u8>`), except as an array element (`Hour[]` binds `T` to `Hour`).

A function generic over integers declares `T: Int`, which takes any integer type within `i64`, range or primitive, alone or beside traits (`T: Int & Display`). In the body, `@min(T)`, `@max(T)`, `x in T` and `T(x)` work as on a range type, and a value of `T` computes as an `i64`. A computed value becomes a `T` again through `x in T` or `T(x)`:

```
clamp_to :: fn<T: Int>(n: i64) -> T {
    if n in T {
        return n
    }
    if n < @min(T) {
        return @min(T)
    }
    return @max(T)
}

wrap_next :: fn<T: Int>(x: T) -> T =
    T((x - @min(T) + 1) % (@max(T) - @min(T) + 1) + @min(T))
```

**Details.**

- Operations: `/` truncates toward zero and `%` takes the sign of the dividend, as at run time. A result past 64 bits is an `i64`, checked like any other. A `char` literal stands for its code point (`b - '0'` past `b in '0'..='9'` is a `0..=9`). A comparison gives a `bool`.
- A primitive beside a range that holds it reads as the range of its values (`b + r` with `b: u8` and `r: 0..=300` is a `0..=555`); a range that neither fits nor holds the primitive is an error. A shift's count may be a range.
- Narrowing applies to a binding or a field chain, with the logic of `!`, `&&`, `||` and a guard that leaves the block. The other side of the comparison is a literal or a range value, read by its bounds: `h < k` with `k: 1..=5` holds `h` within `0..=4`.
- `==` narrows to the compared values; `!=` removes a value only at an end (`h != 23` gives a `0..=22`, `h != 12` the whole `Hour`).
- Ranges join at a true `||` (`if h < 6 || h > 20` sees an `Hour`), at the branches of an `if` or a `match`, and at the `return`s of a function whose result type is inferred; a free literal branch stands for its value. A union written in the source keeps its ranges apart, and a side no value reaches is `never`.
- A write to a narrowed binding, a destructuring one included, ends the narrowing and is checked against its declared range (§3 *Assignment*): `x = 0` is legal where `x == 23` holds.
- A comparison does not narrow a machine integer, named or primitive. Where `x in T` fails, a range `x` is narrowed past the end `T` covers, a primitive `x` is not narrowed. When the type of `x` decides the test, it is a constant (`x` is still evaluated). `x !in T` negates it, and `x in 0..<12` with literal bounds narrows the same way, though the test stays the `contains` of `Range`.
- A narrowed value is a value of the range for what follows: past `if n !in Hour { return }` on an `i64`, `n * 1000` is a `0..=23000`, `a := n` an `Hour`, `[n, n]` an `Hour[]` of bytes, and `n << 8` an error. Narrowed to the bounds of a machine integer, it is that integer: past `n in u8`, `acc := n` is a `u8`, and `acc = acc * 2` stops the program once `acc` passes `127`.
- A comparison with `@min(T)` or `@max(T)` narrows as its literal does. The number of values of `T` is `@max(T) - @min(T) + 1`; `x in char` narrows nothing.
- `lo..=hi` on two `Hour` values is a `Range<Hour>`, and `h..=30` on an `Hour` a `Range<0..=30>`: the element is what the bounds join into.
- `Octet(x)` converts as `u8(x)` does (*Casts*), with no check that stops the program. A member returning `Self` returns the integer (`h.add(k)` is a `u8`), and is not checked inside another type (`Self | null`).
- In a `fn<T: Int>`, a non-integer source of `T(x)`, a value of a non-`Int` type parameter included, is an error; a value of `T` goes where an `i64` goes (`i64`, `i64 | null`), never into a narrower slot.

### Strings

```vader
greeting :: "héllo, wörld"

greeting.len()                    // 12: code points
greeting.byte_len()               // 14: bytes, since é and ö take two each
greeting[1]                       // 'é'
greeting[0..<5]                   // "héllo"
greeting == "héllo, " + "wörld"   // true: == compares the contents

for c in greeting {               // c: char, one code point at a time
    ...
}

bytes :: greeting.bytes()         // the UTF-8 bytes, a frozen u8[] view
copy :: bytes.clone()             // a u8[] of its own (std/iter), which may be written
greeting.byte_at(1)               // 195, the first byte of é
```

- A string is immutable UTF-8 text, and a value: an assignment copies it, `==` compares the contents, `+` gives a new string. Nothing writes into a string (there is no `IndexSet` impl).
- `s.len()` counts code points, in O(n); `s.byte_len()` counts bytes, in constant time.
- `s[i]` is the code point at index `i`, an `i64` or a free literal; an index past the last code point stops the program. `s[lo..<hi]` and `s[lo..=hi]` give the code points of the range: bounds past the end are clamped, and a range that ends before it starts gives `""`. Both reach index `i` in O(i). On an ASCII string (`s.is_ascii()`), `s.len()` and `s[i]` take constant time.
- `for c in s` walks the code points in place (`string implements Into<Iterator<char>>`), and `s.chars()` gives them as an iterator value. The byte loop is `for i in 0..<s.byte_len() { b :: s.byte_at(i) }`.
- `s.bytes()` is frozen (§5 *Frozen values*): writing it, lending it to a function that modifies it, or keeping it in a field is an error. `s.byte_at(i)`, `s.byte_slice(lo, hi)` and `s.codepoint_at_byte(i)` (the code point that starts at a byte offset, and its length in bytes) read the string in place.
- Nothing validates a string's bytes (`bytes_to_string`, `read_file_string`, a `byte_slice` that cuts a code point). Every walk over code points reads a malformed run as one `U+FFFD`: the longest prefix of a well-formed sequence, at least one byte, overlong forms, surrogates and code points past U+10FFFF included. So `s.len()`, `for c in s` and `s[i]` always agree, and a `char`, which never holds such a value, always encodes to UTF-8 that decodes back. The compiler reads source files the same way (§3 *Source encoding*).

### Arrays

```vader
xs :: [10, 20, 30, 40]
same :: xs                // the same array: an array is a reference
same[0] = 11              // xs is [11, 20, 30, 40]
copy :: xs.clone()        // a fresh array (std/iter)

h: Hour: 3
xs[h]                     // 40: any integer type indexes, a range too
xs[4]                     // stops the program: 4 is outside 0..<4

part :: xs[1..<3]         // [20, 30]: a view on xs
part[0] = 21              // xs is [11, 21, 30, 40]
part.push(50)             // part is [21, 30, 50], an array of its own
part[0] = 0               // xs is still [11, 21, 30, 40]
xs[2..<99]                // [30, 40]: the bounds are clamped
```

- `T[]` is an array whose length is known at run time; `i32[][]` is an array of `i32` arrays.
- `arr[r]`, for a range `r` of any integer type, is a slice of `arr`; its bounds, read as `i64`, are clamped at 0 too, and `arr[r].clone()` gives an independent copy.

```vader
a: i32 | string[]: 5             // an i32, or an array of strings
b: (i32 | string)[]: [1, "a"]    // an array of i32 | string
```

Postfix `[]` binds tighter than `|`, and parentheses group. An array type may be any member of a union (`A | T[] | B`).

#### Variance

An array's element type is **invariant** wherever the array is bound, stored or returned: an `i32[]` into a `(i32 | string)[]` local is an error, at the declaration as at a reassignment.

Passed as an argument, an array may widen its element, at any depth: a `Circle[]` passes for a `(Circle | null)[]` parameter, or for a `Shape[]` one when `Circle implements Shape`. The callee's body decides, with no annotation: it may read the array, remove elements, and keep or return an element, but not replace an element, grow the array, keep it past the call, return it, or hand it to a function value. Through a method, a trait or a bound, every function the call may run is checked. Otherwise the argument is an error naming what the callee does:

```vader
total :: fn(shapes: Shape[]) -> f64 { ... }      // reads only
add_square :: fn(shapes: Shape[]) -> void {      // grows the array
    shapes.push(Square { .side = 1.0 })
}

total(circles)        // OK: a `Circle[]` is read as a `Shape[]`
add_square(circles)   // error: `add_square` may grow `shapes`
```

The parameter's element must also take the argument's elements as they are stored, by group:

- **scalars**: integers, floats, `bool`, `char`, ranges, enums and type parameters;
- **references**: structs, arrays, tuples, functions, traits, `any`, and unions of structs, arrays, tuples, functions and `null`;
- **mixed** types: `string`, and every other union (one that holds a scalar, a `string` or a trait).

A distinct type is in the group of its backing. A reference element takes a reference or a mixed argument element, a mixed element only a mixed one, and a scalar element only its own type: `string[]` passes for `(string | null)[]`, but `i32[]` for `(i32 | string)[]` and `Circle[]` for `(Circle | string)[]` are errors.

A fresh literal is built with the slot's element type, so `xs: (i32 | string)[] = [1, 2, 3]` compiles.

#### Array constants

A module constant is frozen (§5 *Frozen values*): nothing can write it. A module keeps its state in a `@singleton` function (§12).

```vader
DIGITS: string[]: ["0", "1", "2"]   // frozen, built at compile time
LIMITS :: [10, 20, 30]              // same storage, inferred

@singleton
counts :: fn() -> i32[] = [0, 0, 0] // state: one instance, built on first call

bump :: fn(i: i64) -> void { counts()[i] += 1 }   // persists across calls
```

`DIGITS.clone()` is a fresh array that can be written.

A type is printed as written (`i32[]`, `Box<Cfg>`), and `@type_name` gives the same text.

#### Repeat / preallocate: `[lhs] * n`

`[lhs] * n` builds a fresh array that repeats the elements of the array literal `lhs` `n` times, the array always on the left. The result has `len(lhs) * n` elements, a count below 0 counting as 0.

```vader
zeros :: [0] * 3          // [0, 0, 0]
pair  :: [7, 9] * 2       // [7, 9, 7, 9]
```

`[] * n` is an empty array with room reserved for `n` elements, the way to preallocate (there is no `with_capacity`).

```vader
buf: i32[]: [] * 1024    // capacity 1024
for x in src { buf.push(x) }   // no reallocation up to 1024 elements
```

- `([] * n)[0]` stops the program: the reserved room becomes readable only as `push` and `push_all` grow the length. `[v] * n` gives `n` readable elements.
- The element type comes from the left side, or from the slot when the left side is empty or a free literal (`[] * n` or `[0] * n` into an annotated `T[]`).
- The left side is evaluated once, so a reference element is shared by every slot: after `rows :: [[]] * 3`, `rows[0].push(x)` grows all three. The compiler warns when that element is freshly allocated (an array or struct literal, a constructor call). `filled(n, make)` (`std/core`, in the prelude) calls `make` once per slot, in order, and `filled_indexed(n, make)` passes it each slot's index:

```vader
rows: i32[][]: filled(3, () -> [])            // 3 distinct arrays
seen :: filled(n, new_visited_set)             // `make` may be any `fn() -> T`
squares :: filled_indexed(n, (i) -> i32(i * i))   // per-slot index
grid :: 3.filled(() -> [])                     // UFCS on the count reads fine too
```

#### Mutation methods

```vader
dst :: [1, 2]
dst.push_all([3, 4])              // [1, 2, 3, 4]
[7, 8, 9].copy_to(0, dst, 1, 2)   // [1, 7, 8, 4]: 2 elements, from index 0 to index 1
dst.copy_to(0, dst, 1, 2)         // [1, 1, 7, 4]: the two ranges may overlap
dst.remove_last()                 // 4, and dst is [1, 1, 7]
dst.clear()                       // []
dst.remove_last()                 // null: dst is empty
[9].copy_to(0, dst, 0, 1)         // stops the program: dst is too short

buf: u8[]: []
buf.push_all("hé".bytes())        // [104, 195, 169]: a string's bytes may be read
"hé".bytes().clear()              // error: a string's bytes cannot be written
```

Besides `push(v)`, arrays have:

| Method | Effect |
|---|---|
| `dst.push_all(src)` | Appends the elements of `src`, which it only reads. |
| `src.copy_to(src_start, dst, dst_start, len)` | Copies `len` elements from `src_start` in `src` to `dst_start` in `dst`. |
| `arr.remove_last()` | Removes and returns the last element. |
| `arr.clear()` | Sets the length to 0 and keeps the reserved room. |

### Tuples

A tuple is a sequence of fixed length whose elements may have different types. Its type is `[T1, T2, ...]`, with two elements or more; there is no 1-tuple.

```vader
divmod :: fn(a: i32, b: i32) -> [i32, i32] { return [a / b, a % b] }

pair: [i32, string]: [42, "answer"]
println(pair.0)      // 42
println(pair.1)      // answer
```

- `t.0`, `t.1`, ... access the elements, numbered in source order.
- Elements are read-only: `t.0 = x`, `t.0 += 1` and a destructuring target `[t.0, n] = ...` are errors, through a distinct over a tuple too. A struct held in an element can still be written (`t.0.x = 5`).
- A `[...]` literal is an array or a tuple by context: without an annotation, `[1, 2, 3]` (one element type) is an array and `[1, "x"]` a tuple; with one, the annotation decides (`p: [i32, string] = [1, "x"]`).
- A tuple is not an array: `[i32, i32]` is not assignable to `i32[]`.
- Element types are invariant: `[i32, i32]` does not pass as `[i32 | string, i32]`, but a fresh literal is built with the slot's element types (`p: [i32 | string, i32]: [1, 2]`).
- `==` compares the elements, not the references, each as it would alone (a struct through its `Equals`, a union by variant, a bounded type parameter through `Equals`), and `!=` is its negation. A distinct type over a tuple compares through its backing unless it implements `Equals` itself.
- A tuple is only as comparable as its elements: `==` is an error when an element has no working `==` (an array, a struct without `Equals`, a function or trait value, a type parameter whose bound does not name `Equals`), and the error names that element's type. The operands must have the same type, nested tuples included: `[i32, string] == [string, i32]` is an error.

### Destructuring

A local declaration (`::` or `:=`) destructures a tuple. Patterns nest, and `_` skips an element.

```vader
[k, v] := key_value()                  // mutable bindings
[k, v] :: key_value()                  // immutable bindings
[a, _, c] :: triple()                  // ignore middle slot
[[x, y], z] :: nested_pair()           // nested destructure
```

A `match` arm does not destructure (`[a, b] ->` is a parse error): it tests the tuple type, and its body destructures what it narrowed:

```vader
match found :: lookup(key) {
    is null          -> println("no result")
    is [i32, string] -> {
        [n, s] :: found
        println("n=${n} s=${s}")
    }
}
```

#### Array sources

A `[...]` pattern also destructures an array, whose length is not checked against the pattern: elements past it are dropped, and a missing one stops the program (an index out of bounds).

```vader
parts :: "a-b-c".split("-")
[x, y] :: parts                        // x = "a", y = "b", "c" is dropped
solo  :: "a".split("-")
[p, q] :: solo                         // stops the program: index 1 is out of bounds
```

#### Spread destructuring (arrays only)

A destructuring declaration may end with `...rest`, which collects the rest of an array source into a fresh array:

```vader
arr :: [10, 20, 30, 40, 50]
[first, ...rest] :: arr                // first: i32, rest: i32[] = [20,30,40,50]
[a, b, ...tail] :: arr                 // a, b consume the head; tail = [30,40,50]
[_, _, ...short] :: arr                // wildcards combine with rest
```

`...rest` on a source that is not an array, or anywhere but in last position, is an error. A tuple source keeps its exact arity: `[a, b] := pair` requires a tuple of two elements.

#### Destructuring via `Into<[...]>`

A `[...]` pattern destructures a value that is neither a tuple nor an array when its type implements `Into<[...]>` with a tuple of the pattern's arity, each name taking the matching element with its type. Without such an impl, it is an error.

```vader
[n, s] :: p                            // p implements Into<[i32, string]>: n is an i32, s a string
```

#### Destructuring assignment

On the left of `=`, the same `[...]` shape writes targets that already exist instead of declaring names. Each element is an assignment target (a name, a field or an index) and follows every rule of a plain assignment (§3 *Assignment*).

```vader
a := 1
b := 2
[a, b] = [10, 20]                      // a = 10, b = 20
[a, b] = [b, a]                        // swap: a = 20, b = 10
[cfg.width, sizes[0]] = dimensions()   // fields and indices are targets too
```

Every element is read before any is written, which makes the swap work; the source is evaluated once.

`_` skips an element: nothing is read or written for it, but it counts toward a tuple's arity. A trailing `...place` writes a fresh array of the elements the other targets left, built while the elements are read.

```vader
[_, name] = lookup(id)                 // lookup runs once, its first element is dropped
[head, ...queue] = queue               // head = queue[0], queue = a copy of the rest
[x, _, ...tail] = coords               // tail = coords[2..], empty when there is none
```

The following are errors:

- an element that is not an assignment target, such as a literal;
- a tuple source whose arity differs from the number of targets;
- a literal source of the wrong length, although other array sources are not checked;
- a `...place` on a source that is not an array, or anywhere but last;
- a nested target (`[[a, b], c] = ...`);
- a source that destructures only through `Into<[...]>`.

Nesting and `Into` belong to a destructuring declaration, where a pattern declares names.

### Structs

```vader
Point :: struct {
    x: i32
    y: i32
}

p :: Point { .x = 1, .y = 2 }
```

A struct is a reference type: `p2 :: p` names the same object as `p`.

- `==` calls the structs' `Equals` impl (*Equality*, below), and `===` tests whether two names reach the same object (*Identity*, below).
- The layout of a struct cannot be observed: there is no `@offset_of` and no unsafe cast.

A literal may list its fields in any order; their values are evaluated in the order the struct declares them. Listing a field twice is an error.

#### Field defaults

A field declaration may give a default value, used when a literal omits the field:

```vader
Settings :: struct {
    name:    string
    timeout: i32  = 30
    debug:   bool = false
}

s :: Settings { .name = "loud", .debug = true }        // timeout=30
```

- A default is type-checked once, at its declaration, against the field's type, before any type argument is substituted.
- It is evaluated at each literal that omits its field. A module constant in it is copied where a write could reach it (§5 *Frozen values*).
- Omitting a field that has no default, in a literal without a spread, is an error.

A struct literal inside a default fills its own omitted fields in turn. It is an error for defaults to fill one another in without end, and for a constant to read itself through the defaults its literal fills in:

```vader
A :: struct { b: B = B {} }      // error: A and B fill each other in
B :: struct { a: A = A {} }

D :: Q {}.n                      // error: D reads itself through Q's default
Q :: struct { n: i32 = D }
```

#### Spread (functional update)

`{ ...other, .field = v }` copies every field of `other` and overrides the listed ones:

```vader
base :: P { .a = 1, .b = 2, .c = 3 }
upd  :: P { ...base, .b = 99 }                          // a=1, b=99, c=3
mix  :: P { ...base, ...other, .b = 7 }                 // 'other' wins for non-named
```

- The spread source must be assignable to the literal's struct type.
- It is evaluated once, before the values of the fields.
- With several spreads, the last one fills every field the literal does not name.

#### Struct literals in `if` / `for` / `match` conditions

A struct literal is not allowed at the top level of an `if`, `for` or `match` condition. Parentheses make it valid. Inside a bracket of the condition (call arguments, an index, a `[...]` literal, an interpolation, parentheses, a block), it needs none:

```vader
if Point { .x = 1, .y = 2 } == p { ... }       // error
if (Point { .x = 1, .y = 2 }) == p { ... }     // OK
if is_origin(Point { .x = 0, .y = 0 }) { ... } // OK
```

### Unions

```vader
Result :: string | i32 | null

show :: fn(r: Result) -> string {
    match r {
        is string -> r
        is i32    -> r.to_string()
        is null   -> "(none)"
    }
}
```

A union is written `A | B | C`, in place or named by an alias. A value that may be absent is typed `T | null` (*Nullability*, below).

A union value, like a trait value, carries the run-time type of what it holds (`docs/RUNTIME.md` *Boxes and tags*): for an enum or an integer range type, the integer that stores it; for a distinct type, its backing. A union of two variants that carry the same run-time type is an error: `Direction | u8` (an enum and its backing), `Fruit | Direction` (two enums with one backing), `Path | string` (a distinct type and its backing).

The instances of a generic struct that differ only in reference-type arguments carry one type (`Box<Foo>` and `Box<Bar>` look alike), but may share a union (*Type tests*, below).

A union implements a trait exactly when each of its variants does.

#### Common-field access

A field common to every variant of a union of structs can be read on the union directly:

```vader
Cat :: struct { name: string, age: i32 }
Dog :: struct { name: string, age: i32 }
Animal :: Cat | Dog

animal_name :: fn(a: Animal) -> string = a.name
```

A field is common when it, and every field before it, has the same position and the same type in every variant. The names of the earlier fields may differ:

```vader
Badge  :: struct { id: i32, label: string }
Ticket :: struct { rank: i32, label: string }
label_of :: fn(x: Badge | Ticket) -> string = x.label   // OK

Kitten :: struct { name: string, age: i32 }
Puppy  :: struct { name: string, age: i64 }
age_of :: fn(a: Kitten | Puppy) = a.age     // error: `age` is `i32` in one, `i64` in the other
```

Reading any other field on the union is an error, which names the first disagreement. This holds for an alias too.

#### Flow-narrowing on `T | null`

A comparison with `null`, on either side, narrows as an `is` test does (§3 *Type tests and narrowing*): where `x != null` holds, or `x == null` fails, `x` has its type without `null`:

```vader
must_greet :: fn(a: Animal | null) -> string {
    if a == null {
        return "missing"
    }
    return a.name                  // `a` is an `Animal` for the rest of the block
}
```

Comparing with `null` a value that can never be `null` is an error, as `n is null` would be.

#### Null-coalescing `??`

`left ?? fallback` evaluates `left` once and gives its value when it is not `null`; otherwise it evaluates `fallback`. The result has the type of `left` without `null`. A `left` that cannot hold `null` is an error, a `T | Error` included.

The fallback is one of:

- a value, assignable to the type of the result;
- a divergent statement, typed `never`: `return`, `return <expr>`, `break` or `continue`;
- a block `{ ... }`, whose trailing expression or divergence gives the value.

```vader
port :: settings["port"] ?? 8080
node :: resolve(sym) ?? return null
v    :: cache[k] ?? {
    log("miss ${k}")
    continue
}
```

`??` can appear wherever a value can. It binds looser than every other binary operator, `||` included (§3 *Operator precedence*): `a ?? b + c` is `a ?? (b + c)`.

`or_else` in `std/option` takes the fallback as a function, which receives the error on a `T | Error`.

### Enums

```vader
Direction :: enum {
    North,
    South,
    East,
    West,
}
```

An enum is a closed set of named variants, each a constant of the enum's type, which may carry data (*Variant data*, below).

#### Access

A variant is named `EnumName.VariantName`:

```vader
d :: Direction.North
```

#### Dot-shorthand inference

`.Variant` stands for a variant of the enum the context gives:

```vader
is_north :: fn(d: Direction) -> bool = d == .North
move_towards(.South)        // parameter type is Direction
```

The context gives an enum in:

- a slot typed by the enum: a declaration, an assignment, a struct field or its default, an argument, a `return` value or expression body, an element of an array literal in a typed slot;
- the value of a `match` arm or an `if` branch that fills such a slot;
- an operand of `==` or `!=` whose other operand is an enum, and an element of an array literal on the right of `in`.

Two enums may share a variant name: the shorthand takes the enum the slot names, or, in a slot typed by a union of enums, the first of them that has the name. A shorthand is an error where the context names no enum (`x :: .Red`), and as an argument that several overloads accept under different enums.

The compiler warns about `Enum.Variant` in a slot that already names that enum, a nullable one (`Direction | null`) included. It does not warn where the prefix matters:

- an unannotated local (`d :: Direction.North`);
- a slot typed by a union of two enums that share the variant name;
- any argument of an overloaded call, where the prefix can select the overload (`pick(Fruit.Red)`).

#### Variant patterns

An arm on an enum variant is written `.Variant`, without `is`; the qualified form `Direction.North` does not parse in a pattern. A `match` on an enum must give every variant an arm, or have a `_` arm.

```vader
match d {
    .North -> "north"
    .South -> "south"
    .East  -> "east"
    .West  -> "west"
}
```

#### Equality and hashing

`==` and `!=` compare enum values by variant (*Equality*, below). Every enum implements `Equals` and `Hash` without a written impl, and `c.equals(d)` is `c == d`. Writing an `Equals` or a `Hash` impl for an enum is an error.

#### Values

```vader
Level :: enum { Low, Mid, High }   // values 0, 1, 2

@min(Level)                        // Level.Low
@max(Level)                        // Level.High
i32(Level.Mid)                     // 1
Level(2)                           // Level.High
Level(n)                           // stops the program unless n is 0, 1 or 2
Level(5)                           // error: 5 is no value of Level
Level.Mid + 1                      // error: an enum has no arithmetic
for l in Level { ... }             // Low, then Mid, then High

if n in Level {                    // n: i64
    return Level(n)                // n is a 0..=2 here
}
```

An enum without variant data is a named set of integers, the values of its variants. It stays nominal: no widening into an integer.

- `@min(E)` and `@max(E)` give its variants of least and greatest value.
- `x in E` tests an integer against its values (`x !in E` negates it), and is a constant where the type of `x` decides it. When the values are consecutive, it narrows `x` to them, as a range test would; an enum with a gap in its values narrows nothing.
- `E(x)` converts as `Hour(x)` does (*Range types*, above); a non-integer `x` is an error.
- `for d in E` walks its variants in declaration order.

**Details.**

- On an enum with no variant, `x in E` is `false`, `for` takes no turn, and `@min`, `@max` and `E(x)` are errors.
- On an enum with variant data, each of these forms is an error.
- They work the same through a namespace or a renamed import.

#### Representation

##### Backing type

An enum value is held as an integer, its **backing type**. Without a written width, it is the narrowest integer that holds every variant value: unsigned when none is negative (`u8` to `u64`), signed otherwise (`i8` to `i64`). A `(type)` after `enum` writes it:

```vader
Direction :: enum(i32) { North, South, East, West }
```

- The written type is one of `i8` to `i64` and `u8` to `u64`, or a distinct type over one of them.
- `@size_of`, a field and an array element of the enum take the width of its backing type.
- An inferred width grows with the values. An `@extern` function takes only an enum whose width is written (§13 *Allowed signature types*).
- An enum with variant data is sized by its number of variants instead (*Variant data*, below).

##### Variant indices

Each variant has an integer value: `0` for the first, the previous plus one for the others, unless `= value` writes it:

```vader
Priority :: enum(u8) {
    Low    = 10,   // 10
    Medium,        // 11
    High   = 20,   // 20
    Critical,      // 21
}
```

Two variants with the same value are an error, and so is a value that does not fit the written backing type.

##### Memory model

An enum value is a value, copied on assignment as a `bool` is.

#### Variant data

An enum header may name a struct, alone (`enum(Info)`) or before the width of the values (`enum(Info, i32)`). Each variant then carries a constant value of that struct, its **data**, written as the struct's fields after the variant's name:

```vader
StatusInfo :: struct {
    code:   i32
    reason: string
    retry:  bool = false
}

HttpStatus :: enum(StatusInfo) {
    Ok          { .code = 200, .reason = "OK" },
    NotFound    { .code = 404, .reason = "Not Found" },
    Unavailable { .code = 503, .reason = "Service Unavailable", .retry = true },
}

line :: "HTTP/1.1 ${s.code} ${s.reason}"   // s : HttpStatus
info :: StatusInfo(s)                       // a copy of the whole value
```

A lone header argument is the width when it is an integer type or a distinct type over one, and the data when it is a struct. Any other argument is an error: `enum(string)`, `enum(string, i32)`.

- Each block is checked as a literal of the data struct, its errors reported on the variant. A variant may omit its block when every field has a default. A block on an enum without data is an error.
- The data holds only scalars, strings and enums; a field that holds a reference (a struct, an array) is an error.
- Every value in the data must be computable at compile time.
- Each variant also has an integer value, written after its block (`Ok { ... } = 200`) and numbered as in any enum (*Variant indices*, above). A written width bounds the values.
- `v.field` reads a field of `v`'s data, and `Info(v)` the whole value. The data is frozen, as a module constant is (§5 *Frozen values*): writing it or lending it to a function that modifies it is an error, and a name bound to it holds a copy. `HttpStatus.code` stays a variant lookup.
- An enum value is stored in the narrowest unsigned integer that can number the variants, whatever width the header writes.
- `i32(s)` gives the written value, and so does an `@extern` parameter of the enum, through a function value too (§13 *Allowed signature types*). Interpolating renders through `Display`, never the written value.

#### `Display`

An enum implements `Display` only on request: interpolating one that does not is an error. `@displayable` generates an ordinary impl that renders each variant as its name; writing one as well is an error:

```vader
@displayable
Direction :: enum { North, South, East, West }

"${Direction.East}"   // "East"
```

For any other text, implement the trait:

```vader
Direction implements Display -> match self {
    .North -> "N"
    .South -> "S"
    .East  -> "E"
    .West  -> "W"
}
```

- In a generic, a `T` bound to an enum renders through the enum's `Display`, in a generic impl too (`Box<Direction>`). A generic function renders a `T` bound to a distinct type through the distinct's `Display`.
- Interpolating a union that holds an enum, or a distinct type with a `Display` of its own, is an error, and so is interpolating an array of such unions: narrow first. A distinct type without its own `Display` renders through its backing type's, inside a union too.

---

### Pattern matching

A `match` tests its scrutinee against the pattern of each arm, in order, and takes the first arm that matches (§7 *`match`*).

```vader
match value {
    is Point { x: 0, y } -> "Y axis at $y"
    is Point { x, y }    -> "($x, $y)"
    is null              -> "nothing"
    42                   -> "the answer"
    1 | 2 | 3            -> "small"
    is i32 if value > 0  -> "positive"
    is i32               -> "negative or zero"
    'A'                  -> "letter A"
    "ok"                 -> "literal ok"
    _                    -> "wildcard catch-all"
}
```

#### Header binding

`match x :: e { ... }` evaluates `e` once and names it `x` in every arm and every guard. The scope of `x` is the match: after it, `x` is whatever it named before.

`x` is one constant name, typed as the scrutinee. Assigning it is an error, and so is any other form of header (`match x := e`, `match e as x`).

A scrutinee that is already a name needs no header: each arm narrows it in place. An arm cannot bind a name of its own (`is T as x ->` is an error):

```vader
match s :: shape_at(n) {        match shape {
    is Circle -> s.radius           is Circle -> shape.radius
    is Square -> s.side             is Square -> shape.side
}                               }
```

#### Type tests

```vader
Box :: struct<T> { value: T }

kind :: fn(b: Box<Direction> | Box<u8>) -> string = match b {
    is Box<Direction> -> "a direction"   // never matches a Box<u8>
    is Box<u8>        -> "a byte"
}

holds :: fn<U>(x: i32 | string) -> bool = x is U
holds<i32>(5)                        // true
holds<string>(5)                     // false
```

`is Type` tests the type of the scrutinee and narrows it in the arm (§3 *Type tests and narrowing*).

- On a generic struct, the test tells instances apart when every type argument is a primitive or an enum.
- A test on an instance whose type argument is a reference type, or a type parameter a reference type may bind, is an error (*Unions*, above): test the field that holds it instead.
- A generic function may test its own type parameters, against what the call binds them to, through generic callers too.
- An impl member may test its own type parameters, but not those of its impl: testing one, or handing one to a function that tests it, is an error.
- An arm whose `is T` can never hold is an error, as in an `if`.

```vader
match boxed {                        // boxed: Box<Circle> | Box<Square>
    is Box<Circle> -> ...            // error: Circle is a reference type; test boxed.value
    ...
}

Probe :: trait { probe :: fn(self) -> bool }

Box<T> implements<T> Probe {
    probe :: fn(self) -> bool = self.value is T   // error: T is a parameter of the impl
}
```

#### Literal patterns

```vader
classify :: fn(v: i64 | string | null) -> string = match v {
    5         -> "five"              // 5 is an i64: the variant it can fill
    "ok"      -> "ok"
    null      -> "nothing"
    is i64    -> "another number"
    is string -> "another string"
}

match x {                            // x: f64
    0.0 -> "zero"                    // and -0.0: floats compare by IEEE 754
    _   -> "nonzero"
}
```

A literal (`42`, `'A'`, `"ok"`, `null`) matches a scalar value when `scrutinee == literal` holds, the literal typed as the right operand of that `==`:

- a union compares by variant, and a float by IEEE 754;
- the literal is compared with what the arms above leave of the scrutinee;
- a literal whose variant an arm above already took (`"a"` after `is string ->`) draws a warning.

```vader
label :: fn(v: Point | string | null) -> string = match v {
    is Point  -> "a point"
    "a"       -> "the letter a"      // v is a string | null here: Point needs no Equals
    is string -> "another string"
    null      -> "nothing"
}

match b {                            // b: u8
    300 -> "big"                     // error: no u8 equals 300
    _   -> "small"
}
```

A literal in a struct pattern (`is Holder { v: 5 }`) follows the same rules against its field.

#### Range patterns

`'a'..='z' -> ...` and `0..<10 -> ...` match a `char` or integer scrutinee that falls in the range, `..=` and `..<` as in a range expression.

- The bounds are literals, typed as the scrutinee: `-1..=3` over a `u8` is an error.
- Over a distinct type, the bounds take its backing type, as `<` does.
- Over a union, they take its integer or `char` variant, which the arm tests first. Once arms above have taken that variant, the compiler warns.
- A scrutinee with no integer or `char` to order is an error.

#### Or-patterns

Alternatives separated by `|` share one arm, which matches when any of them does. Each alternative is checked against the scrutinee, and every enum variant listed counts toward exhaustiveness. A struct pattern in an alternative may constrain a field: `is A { x: 1 } | is B { x: 2 }`.

`is A | B -> ...` is one `is` over the union type `A | B`, written without parentheses: it narrows to `A | B` and covers both.

#### Struct patterns

The first two arms of the example in *Pattern matching* bind `y`, then `x` and `y`; the first matches only where `x == 0`.

```vader
match q {                                  // q: Point | Other | null
    name                            -> ... // error: the catch-all is _
    is Point { x } | is Other { x } -> ... // error: an alternative binds no field
    [a, b]                          -> ... // error: an arm does not destructure a tuple
}
```

- Each name must be a field of the struct, and a literal takes the type of its field: either mismatch is an error, and so are braces after a type that is not a struct.
- The field tests run after the type test, on the narrowed value.

Only the fields of a struct pattern bind names. The following are errors:

- a bare identifier arm: the catch-all is `_`, and the header names the scrutinee;
- a field binding inside an alternative of an or-pattern;
- a tuple destructuring arm: test a tuple with `is [T, U]`, and destructure it in the arm (`[a, b] :: x`).

#### Guards

`if cond` after a pattern is a guard: the arm matches only when it holds. It may read the pattern's bindings and the header's name.

- At the guard's own level, `->` belongs to the arm: a bare lambda (`x -> ...`, `(x) -> ...`) is parsed only inside a bracket (`xs.any_match(x -> x > 0)`), its own parentheses included.
- A struct literal can appear in a guard.

#### Narrowing in the arms

Each arm narrows the scrutinee (a name, a field chain or the header name) to what its pattern matched.

- After `is X` arms that constrain no field, the `_` arm sees what those arms left: after `is null ->`, a `Pet | null` is a `Pet`.
- Literal and range arms narrow an integer scrutinee to their values, as `if h in 1..=11` would. An or-pattern narrows to the range that holds its alternatives, and `_` to the values left when they form one interval. A `char` and a distinct type are not narrowed to a range.

#### Exhaustiveness

`part_of_day` of *Range types*, written as a `match`, needs no `_`:

```vader
part_of_day :: fn(h: Hour) -> string = match h {
    0..<12  -> "morning"
    12..=23 -> "afternoon"
}

match h {                                    // error: the value 12 is not covered
    0..<12  -> "morning"
    13..=23 -> "afternoon"
}

match p {                                    // p: Point | null
    is Point { x: 0 } -> "on the axis"       // error: Point is not covered,
    null              -> "nothing"           // since the arm constrains x
}
```

A `match` must cover every value of its scrutinee; the error names the first value missing.

- A union is covered when every variant is, or by `_`.
- An integer type (a range, an integer primitive or `char`, a distinct type over one included) needs no `_` once its unguarded literal and range arms take every value. The integer variant of a union is covered the same way. A `u64` still needs `_`, since no literal reaches past `i64`.
- Any other scrutinee (`string`, `f64`) needs `_`.
- Guarded arms and arms that constrain a field cover nothing.

`@partial` and `@unreachable` lift the check (§12 *`@partial` and `@unreachable`*).

```vader
name :: fn(d: Direction) -> string = match d {
    .North -> "north"
    _      -> "other"                        // warning: a bare _ in a match that gives a value
}
```

The compiler warns about a bare `_` arm in a `match` over a union or an enum that produces a value, a match whose every arm leaves (`return`, `break`) included. Listing every variant, or marking the match `@partial`, removes the warning. A statement match (`_ -> {}`) does not warn.

#### Unreachable arms

The compiler warns about an arm whose values the arms above already take: after a `_`, the same variant, the same `is T` test, or literals and ranges that cover it. The warning applies to a `@partial` match too.

### Type inference

Inference is bidirectional: from the value (`x :: 12` infers `x: i32`), and from the context (the function type a slot expects gives a lambda the types of its parameters).

There is no Hindley-Milner inference across the program: the parameters of a function declaration must be annotated (`self` excepted). An expression-bodied function may leave out its return type, which its expression gives; a block body without one returns nothing. The compiler warns when an exported function leaves its return type out: its public type would then change with its body.

#### Type arguments of a call

```vader
first :: fn<T>(xs: T[]) -> T = xs[0]
empty_of :: fn<T>() -> T[] = []
tag :: fn<T>() -> string = "tag"

first([1, 2])                 // T = i32, from the argument
first(["a"])                  // T = string: each call binds afresh
rows: i32[]: empty_of()       // T = i32, from the slot the result fills
empty_of<string>()            // T = string, written
tag()                         // error: nothing binds T

repeat :: fn<T>(x: T) -> T[] {
    out: T[]: empty_of()      // binds empty_of's T to this body's T
    out.push(x)
    return out
}
```

A generic call binds its type arguments from its arguments first, then from the slot its result fills.

- Inside a generic body, the body's own `T` is fixed: met in an argument or the result slot, it binds the callee's parameter to `T` itself.
- Written type arguments `<...>` fix the callee's parameters in the order it declares them, wherever it is declared.
- On a call with the wrong number of arguments, only the count is reported.

#### Generic functions as values

```vader
id :: fn<T>(x: T) -> T = x
name_of :: fn<T: Display>(x: T) -> string = "<${x}>"
apply :: fn(f: fn(i32) -> string, x: i32) -> string = f(x)

// in a function body:
apply(name_of, 3)             // "<3>": name_of is taken at T = i32
named :: name_of<f64>         // fixed by its type argument: named(1.5) is "<1.5>"
g :: id                       // an alias: g(1) and g("a") each instantiate id
m := id                       // error: neither a function-typed slot nor a type argument
```

A generic function named as a value is instantiated against the function type of the slot it fills.

- Writing fewer type arguments fixes the first parameters, and the slot binds the rest.
- A module constant is not such an alias: it needs an annotation (`h: fn(i32) -> i32: id`).
- An argument is no exception: `keep(id)` with `keep :: fn<T>(x: T) -> T` is an error.

#### Members with type parameters of their own

A trait or impl member with type parameters of its own (`conv :: fn<U>(self, x: U) -> string`) is instantiated at each call, as a generic function is: on a concrete receiver, as a static member, through a bound in a generic function, and on a generic impl, whose own parameters the receiver binds.

Calling such a member where its impl is picked at run time is an error: on a trait value, or, inside the members of a generic impl, through a bound of that impl's type parameter.

#### Union parameters

Against a union parameter, the variants the argument shares with it pair off first (`T | null` never binds `T = null`), and a variant the argument lacks binds nothing (`T | null` given an `i32` binds `T = i32`).

A type parameter left alone then takes every variant left: `T | null` against `i32 | string | null` binds `T = i32 | string`. Several variants left on both sides pair by position.

### Casts

A conversion is written as a call to the target type:

```vader
x: i32: 42
y: i64: x                  // widening, no cast needed
z: u8: u8(x)               // narrowing cast, keeps the low bits (300 -> 44)
```

A conversion that can fail, such as parsing, is a function returning a union:

```vader
n: i32 | ParseError: parse_int("42")
```

#### `char` and integers

A `char` is a Unicode scalar value: a code point from U+0000 to U+10FFFF, the surrogates `D800` to `DFFF` excluded, held as a `u32`.

- An integer conversion reads its code point (`u32(c)`).
- `char(x)` converts an integer, checked in every build: the program stops on a value that is not a scalar value.
- A distinct type over an integer converts as its backing type does, and one over `char` (`Glyph :: char`) is checked as `char`.
- A type that implements `Into<char>` converts through it.
- A UTF-16 surrogate is a code unit, an integer (`is_surrogate(unit: u32)` in `std/string`).

The following are errors:

- a literal that is not a scalar value (`char(0xD800)`);
- a source type none of whose values is a scalar value;
- a float or an enum: convert it to an integer first.

```vader
c    :: 'A'
n    :: u32(c)            // 65
back :: char(n + 1)       // 'B', checked
```

### Generics

Type parameters are declared `<T>` (never `[T]` or `(T)`) at the declaration site, and are in scope across the whole declaration.

A type parameter may declare a **default** after its bound: `<Rhs: Numeric = Self>`. Trailing arguments an impl or a bound leaves out take their defaults, a `Self` default being the implementing or receiver type: `i32 implements Add` and `T: Add` both read `Add<Rhs = Self, Out = Self>` as `Add<Self, Self>`. A default on a struct, function or type-alias parameter is accepted but not applied: with `Pair :: struct<A, B = i32>`, `Pair<string>` is an error.

In expression position, after a name (`f`, or the member in `x.f`, `M.f`), a `<` opens a type argument list when a matching `>` on the line is followed by `(`, `{`, `.name` (`Bag<f64>.make(1)`), or what ends a value: a `,`, a closing bracket, the end of the line (`f :: id<i32>`, `apply(name_of<i32>, 5)`). Otherwise the `<` is a comparison (`assert(v < 20, "msg")`). In `Box<Box<T>>`, `>>` closes both levels.

A call writes explicit type arguments after the callee's name, in any call form (`f<i64>(x)`, `x.f<i64>(y)`, `M.f<i64>(y)`), and they fix the callee's parameters in declaration order.

- Fewer than declared leaves the rest inferred (`pair<i64>(5, "x")` fixes `A` and infers `B`); more, or any on a function that takes none, is an error.
- A static member takes its type's arguments on the type and its own after its name: `Bag<f64>.make<i64>(1)`, or `Bag.make<i64>(1)` with those of `Bag` inferred.
- A generic type written with type arguments in a struct literal, as the owner of a static member or as a conversion target (`Box<i64>(x)`) writes all of them: with `Pair :: struct<A, B>`, `Pair<i32> { ... }` and `Pair<f64>.make(1)` are errors.

Generic functions and structs:

```vader
map :: fn<T, U>(items: T[], f: fn(T) -> U) -> U[] {
    result: U[]: []
    for x in items {
        result.push(f(x))
    }
    return result
}

List :: struct<T> {
    items: T[]
    len: u32
}
```

A bound follows the parameter after `:` and names traits, or `Int` (§4 *Range types*), joined by `&` and all required. A union is an error as a bound, as in a trait's composition: `null` goes where the parameter is used, `fn<T: Bump>(x: T | null)`, never `fn<T: Bump | null>(x: T)`.

```vader
put :: fn<K: Hash & Equals, V>(self: MutableMap<K, V>, key: K, value: V) {
    // ...
}
```

A type parameter's bound applies in the generic body and at every call:

- In a generic body, a method call or an operator on a value typed by a type parameter resolves through its bound: `key.hash()` under `K: Hash`, `a < b` under `T: Comparable` (*Operator overloading*).
- At every call, wherever the callee is declared and however it is called (through UFCS, the receiver alone may bind the parameter: `m.println()`), each type argument must implement every trait of its parameter's bound, at the bound's arguments: a `string[]` (`Contains<string>`) does not meet `C: Contains<i32>`.
- A type argument that is itself a type parameter meets a bound its own bound names.

Type parameters are opaque in their body. A generic body knows nothing of `T` beyond its bound: only a `T` fits a slot typed `T`, and a `T` fits only a slot that names it (`T`, `T | null`). Each of these is an error:

```vader
widen :: fn<T>(x: T) -> i64 {
    n: i64: x            // a T is no i64
    return n
}

narrow :: fn<T>(x: T) -> T {
    y: i64: 5
    return y             // nor is an i64 a T
}

zero :: fn<T: Add>(x: T) -> T {
    s: T: 0              // nor is a free literal
    return s.add(x)
}
```

So is a free literal as a `T` argument or operand: `pick(x, 0)` with `pick` taking two `T`, `f(2.5)` through `f: fn(T) -> T`, `x == 0` under `T: Equals`.

The body of a generic function or impl binds none of its own type parameters at a call: `keep("s")` on a local `keep :: (y: T) -> ...` is an error, as is `t.visit((y: Inner) -> ...)` under `T: Visit`. A callee's own parameters are still bound (`g :: identity`), and in a type's impl a receiver or the type name binds the impl's parameters to the instance it names (`other.put(4)` on a `Box<i32>`, `Bag.make(5)`).

A generic recursion may not grow its type argument. On a cycle of calls, passing a type parameter on inside a larger type is an error: `wrap<T>` calling `wrap([x, x], n - 1)`, `ping<A>` calling `pong([a], n)` when `pong` calls `ping`, `[self].depth(n - 1)` in an impl on `T[]`. These are accepted:

- passing the parameters on unchanged (`count_down(x, n - 1)`);
- a call to itself at a fixed type (`fixed(n, n - 1)` inside `fixed<T>`);
- in the impl of a generic struct, a call on a larger instance of it (a `Box<T[]>` inside the impl of `Box<T>`).

An argument is matched against a signature's free type parameters when choosing an overload or the UFCS function for a receiver (`Iterator<i32>` fits `self: Iterator<T>`). A free literal binds no type parameter: write `Box<i32> { .value = 0 }`, not `Box { .value = 0 }`.

A static function belongs to a trait (*Static members*), never to a type alone: there are no inherent associated functions. A factory outside a trait is a free function (`new_rng(42)` in `random`); a struct is built by its literal (`MutableMap<K, V> {}`).

The primitive impls are listed in §15 *`std/core`*.

### Traits

A trait is a contract of methods a type implements, called on it through UFCS. Members, in a trait as in an impl, are declared `name :: fn(...)`, never `fn name(...)`.

```vader
Display :: trait {
    to_string :: fn(self) -> string
}

u32 implements Display {
    to_string :: fn(self) -> string {
        // ... implementation
    }
}

print_it :: fn<T: Display>(x: T) {
    println(x.to_string())
}
```

- **Declaration**: `Name :: trait { ... }`.
- **Implementation**: `T implements Trait { ... }`, in three forms (*Single-method trait sugar (SAM)*). `T` and `Trait` resolve like any other name, and the impl belongs to the declarations they name: of two modules' `Foo` types, or `Animal` traits, an impl of one says nothing of the other.
- An impl defines its trait's members and nothing else, each with its trait method's parameters and return type, `Self` read as the impl's type and the trait's parameters as the impl's arguments, their defaults filled in (*Generics*, above). Any other member or signature is an error.
- **`self` and `Self`**: in a trait or an impl, a first parameter named `self` has the type `Self` with no annotation, and `Self` is the implementing type (`Foo` in `Foo implements Trait { ... }`, a written `-> Self` included). Elsewhere, `Self` is an error.

A union calls the members of a trait all its variants implement: `u.area()` on `u: Sq | Circle`, like `k in u`, `u + 5` or `u[k] = v`, dispatches by the value's run-time type, as on a trait value. Each trait argument must be one type for all the variants, or each variant itself (`Out = Self`, read as the union: `a + 5` on `a: i32 | Money` is an `i32 | Money`).

These are errors (narrow the union first):

- a member that two traits offer every variant;
- a variant that implements the trait more than once;
- a variant that is an enum, a distinct type implementing the trait itself, or an array of either (*Unions*, above);
- a member taking another `Self` (`compare`, `Add<Self>`), except in `Equals`, whose parameter checks the other operand's type;
- a member returning `Self` inside another type (`Self[]`), unless every variant is a struct.

A generic member, or an `@intrinsic` array member (`push`), is not dispatched through a union.

#### Static members

A trait member whose first parameter is not named `self` is **static**, whatever its types (`combine :: fn(a: Self, b: Self) -> Self`). It is called on a type: a concrete type, a type parameter whose bound names the trait, or a type reached through a namespace alias (`M.Point.origin()`). `Type.member(args)` runs the member of `Type`'s impl.

```vader
Zero :: trait {
    zero :: fn() -> Self
}

i64 implements Zero -> 0

sum :: fn<T: Add & Zero>(xs: T[]) -> T {
    s := T.zero()
    for x in xs {
        s += x
    }
    return s
}
```

A value of the trait reaches only its instance members, even in a trait that also has static ones. These are errors:

- a static member called on a value, or on the trait itself (`Zero.zero()`);
- an instance member called on a type;
- a static member named without being called (`f :: i64.zero`).

`std/core` declares `Zero` and `One` (§15 *`std/core`*), and `BigInt` implements `Zero`. `std/iter` has `sum :: fn<T: Add & Zero>(self: Iterator<T>) -> T` and `product :: fn<T: Mul & One>(self: Iterator<T>) -> T`.

#### Coherence: one impl per (type, trait, arguments)

A second impl of the same type, trait and trait arguments is an error, across the whole program, the `std/core` prelude included (`i32 implements Display`, `Hash` for the primitives). Impls of one trait at other arguments are allowed (*Several impls of one trait*).

```vader
i32 implements Display {           // error: std/core already implements
    to_string :: fn(self) -> string = "n=${self}"
}
```

Two generic impls of one trait on one base (`Wrapper<T>`, `T[]`) may not both cover an instance, whatever their bounds: `Wrapper<T> implements<T: A> Poke` beside `Wrapper<T> implements<T: B> Poke` is an error. The same check on a bare type-parameter receiver (`T implements<T: A> ...`) is planned.

An impl is declared in the module of its type or of its trait (the **orphan rule**). An array type belongs to the module of its element type: `MonType[]` to that of `MonType`, `i32[]` to `std/core`.

#### Specialization: the instance wins

An impl on one instance of a generic base (`Wrapper<MonType> implements Poke`, `MonType[] implements Poke`) is not a second generic impl: it wins over the base's generic impl for that instance, whatever the order of declaration.

```vader
Wrapper<T> implements<T> Poke {
    poke :: fn(self) -> string = "generic"
}

Wrapper<MonType> implements Poke {      // wins for `Wrapper<MonType>` alone
    poke :: fn(self) -> string = "mon"
}
```

- Every route to the impl agrees: a method call, a bounded type parameter, a trait-typed value, an instance built in a generic body (`fn<T>(x: T) -> Wrapper<T>` called with a `MonType`).
- It replaces only the generic impls of its trait at arguments that can coincide with its own: `MonType[] implements Into<Label>` leaves `T[] implements<T> Into<Iterator<T>>` to an array of `MonType`. The base's other traits still reach the instance through their generic impls.

An array type takes impls on `T[]` and on a concrete array (`i32[] implements Tag`). An impl on a partly generic array (`T[][]`, `[T, i32][]`) is an error.

#### Several impls of one trait

```vader
Vec2 implements Mul<f64> -> Vec2 { .x = self.x * other, .y = self.y * other }
Vec2 implements Mul<Vec2> -> Vec2 { .x = self.x * other.x, .y = self.y * other.y }

v :: Vec2 { .x = 1.0, .y = 2.0 }
v * 2.0                       // Mul<f64>: (2.0, 4.0)
v * v                         // Mul<Vec2>: (1.0, 4.0)
v.mul(3.0)                    // Mul<f64>, by the argument: (3.0, 6.0)

MonType implements Into<Label> -> Label { .text = "mon ${self.id}" }
MonType implements Into<Serial> -> Serial { .n = self.id }

m :: MonType { .id = 7 }
t: Serial: m.into()           // Into<Serial>, by the type of the result
println("${m.into()}")        // error: two `into` fit, give the result a type
f :: m.into                   // error: two `into` fit
```

A type may implement one trait at several arguments. Each use site picks the impl:

- an operator, by its right operand;
- a method call, by its first argument, or, without one, by the type its result must have;
- `x in c`, by the element; `c[k]` and `c[k] = v`, by the key;
- `[a, b] :: r`, by the arity of the tuple an `Into<[...]>` builds;
- a static member, by its argument (`Vec2.make(1.5)`);
- a call, a static member or an operator on a bounded `T`, in a generic function or a generic impl, by the bound's arguments (`fn<T: Mul<f64>>(v: T) -> T = v * 2.0`);
- inside one of the impls, a member of the trait called on the impl's type, by that impl: a default method's `self.tag()` runs its own impl's `tag`.

These are errors:

- two impls that fit a use site equally;
- a member without an argument whose result the site leaves untyped;
- the member taken as a value without a function type to pick it (`f :: m.into`; `f: fn() -> Serial: m.into` is fine);
- a use that does not name the trait's arguments: a `for` over a type implementing `Iterator` twice, or converting into two `Iterator`s without being one itself;
- a trait value of a trait its type implements twice (`v: Into<Serial>: m`).

A type that is an `Iterator` and also converts into one is walked through its own `next`.

#### Bounded-generic impls

An impl declares its own type parameters after `implements`, bounded as on a function (`<T: A & B>`), in scope across the whole impl, for-type and trait arguments included. Without a list (`Foo<T> implements Trait<T>`), `T` is borrowed from the struct head; with one, the impl's `T` is its own, its bounds holding in this impl only.

```vader
// Borrowing T from the struct head: no list after `implements`.
Countdown<T> implements Iterator<T> {
    next :: fn(self) -> T | Stop { /* ... */ }
}

// Bounded blanket impl: Range<T> coerces into an Iterator when T
// satisfies both Comparable and Step.
Range<T> implements<T: Comparable & Step> Iterator<T> {
    next :: fn(self) -> T | Stop { /* ... */ }
}

// Blanket on a structural source (any array, any Display-bound type).
T[] implements<T>          Into<Iterator<T>> { /* ... */ }
T   implements<T: Display> Into<string>      { /* ... */ }
```

Every parameter the list declares appears in the for-type: `T[] implements<T, U> Tagged<T, U>` and `Box<T> implements<T, U> Add<U>` are errors.

A bounded impl holds only for the arguments its bounds admit. With `Box<T> implements<T: Display> Display`, `Box<Point>` has no `Display` while `Point` has none: interpolating it, or passing it to a `T: Display` parameter, is an error naming the unmet bound.

- An argument meets a bound as at a call (*Generics*); a union, when every variant does; a distinct type, through its own impl or its backing's. An array does not meet a `Display` bound there.
- A member of a bounded impl is reached only through an instance its bounds admit, in every form: with `Wrapper<T> implements<T: Bump> Poke`, `w.poke()` on a `Wrapper<Plain>` is an error, as are `for`, `w[i]`, `w[i] = v` and an operator through such an impl.
- An `is Trait` test still matches by the type's base, whatever the bounds.

A struct's bounds hold at its literal. With `Wrapper :: struct<T: Bump>`, `Wrapper<X> { ... }` is an error when `X` does not meet the bound; a type written elsewhere (`w: Wrapper<Plain>`) is not checked. An impl borrowing the struct's parameters (`Wrapper<T> implements Poke`) holds only for what the struct admits.

A generic function states the bounds it relies on: `fn<K>(m: MutableMap<K, V>)` indexing `m` is an error without `K: Hash & Equals`. A generic struct literal without type arguments (`Box { .value = p }`) is typed `Box`, and its bounds are not checked.

#### Trait composition

A trait can compose other traits, which its implementor must all satisfy: with `=` and no body, or with `:` and a body for its own methods.

```vader
// Pure alias: Numeric is Add & Sub & Mul; no own methods.
Numeric :: trait<T> = Add & Sub & Mul

// With own methods: Hashable requires Hash and Equals, plus declares its own.
Hashable :: trait<T> : Hash & Equals {
    fingerprint :: fn(self: T) -> u64
}
```

The composition is an `&`-chain in type position, with the precedence of a type intersection; a single trait makes an alias (`Foo :: trait<T> = Bar`). A bound `T: Foo` requires every composed trait.

#### Method dispatch on trait values

A call on a receiver typed by a trait runs the impl of the value's run-time type, primitive and enum impls included. The receiver's trait arguments are substituted into the method's signature: with `it: Iterator<i32>`, `it.next()` returns `i32 | Stop`.

```vader
report :: fn(e: Error) -> string {
    return e.message()       // dispatches on `e`'s actual struct tag
}
```

#### Single-method trait sugar (SAM)

When a trait has exactly one required method (one without a body, *Default methods* aside), an impl may leave out the `name :: fn(...) -> RetType` line and write the body directly, with the trait's signature and parameter names (`self`, `other`, ...) in scope.

```vader
// Arrow form: single-expression body.
i32   implements Hash   -> u64(self)
i32   implements Equals -> self == other

// With generic trait args.
Tutu  implements Toto<i32, i64> -> i64(self + other)

// Block form: multi-statement body.
Point implements Hash {
    h: u64 = u64(self.x)
    h = h *% 31 +% u64(self.y)
    return h
}

// Classic form: required for traits with two or more methods.
Countdown<T> implements Iterator<T> {
    next :: fn(self) -> T | Stop { ... }
}
```

- An impl body is a short form when it starts with `->` (the arrow form), or with a `{` whose first significant token does not start a member declaration (`name :: fn`), the block form.
- The classic form (`{ name :: fn(...) ... }`) is always valid. A short form on a trait with no required method, or with several, is an error.

#### Default methods

A trait method may carry a body. An impl without that method gets the body, read as its own members are (*Traits*); a call in it to another member (`self.area()`) reaches the impl's own when it defines one.

```vader
Shape :: trait {
    area     :: fn(self) -> f64
    describe :: fn(self) -> string { return "a shape of area ${self.area()}" }
}

Square implements Shape -> self.side * self.side
// Square gets `describe` from the trait.
```

A default body is checked once, in the trait, for every type that will implement it. `Self` is then any implementing type, and a type parameter of the trait has only its bounds:

- an error in the body is reported once, at the body, even when no type implements the trait;
- an operation on a type parameter needs its bound, as in a generic function: `a + b` on two `T` needs `T: Add`;
- a test on `Self` or on a type parameter (`self is Square`, `x is Box<T>`) is answered for each impl, by the type it implements the trait for.

A default with an expression body may leave out its return type, as a function may (§4 *Type inference*): its expression gives it, to the trait and to every impl. The compiler warns when the trait is exported, since its public type would then change with the body.

```vader
Shape :: trait {
    area  :: fn(self) -> f64
    twice :: fn(self) = self.area() * 2.0   // returns f64
}
```

In the standard library, `Async` has one default method: `cancel`, which does nothing.

#### Operator overloading

An operator on operands other than primitive numerics calls the method of a standard-library trait (equality: *Equality*, below):

```vader
// with Point of §4 *Structs*
Point implements Add -> Point { .x = self.x + other.x, .y = self.y + other.y }

a :: Point { .x = 1, .y = 2 }
p := a + Point { .x = 10, .y = 20 }   // a.add(...): (11, 22)
p += a                                // p = p + a: (12, 24)
p * p                                 // error: `*` is not defined for Point
p < a                                 // error: Point does not implement Comparable
```

| Operator        | Trait              | Method                                      |
|-----------------|--------------------|---------------------------------------------|
| `a + b` (`-`, `*`, `/`, `%`) | `Add<Rhs = Self, Out = Self>` (`Sub`, `Mul`, `Div`, `Rem`) | `add :: fn(self, other: Rhs) -> Out` (`sub`, `mul`, `div`, `rem`) |
| `a == b`        | `Equals`           | `equals :: fn(self, other: Self) -> bool`   |
| `a < b` / `<=` / `>` / `>=` | `Comparable` | `compare :: fn(self, other: Self) -> i32` |
| `a[i]`          | `Index<I, T>`      | `at :: fn(self, i: I) -> T`                 |
| `a[i] = v`      | `IndexSet<I, T>`   | `set_at :: fn(self, i: I, v: T)`            |
| `v in a`        | `Contains<T>`      | `contains :: fn(self, v: T) -> bool`        |

- Each operator trait declares only the member its operator calls, with no default method: `a != b` is `!a.equals(b)` and `a <= b` is `a.compare(b) <= 0`.
- A compound assignment (`+=`, `-=`, `*=`, `/=`, `%=`) is `lhs = lhs <op> rhs`, dispatched as `<op>`, with the place `lhs` evaluated once. `Out` must be assignable to `lhs`.
- A missing `Equals`, `Comparable` or `Contains` is an error naming that trait. Missing arithmetic, like any operands an operator does not accept (`i32 && bool`), is an operator not defined for those types.

```vader
// std/time: Instant implements Add<Duration, Instant> and Sub<Instant, Duration>
later :: now() + seconds(5)        // an Instant
later - now()                      // a Duration
t := later
t -= now()                         // error: a Duration does not go into an Instant

twice :: fn<T: Add>(v: T) -> T = v + v
twice(p)                           // (24, 48): through the bound
twice(3)                           // 6: the built-in +
twice("ab")                        // "abab": through string implements Add
```

Resolution rule for arithmetic operators (`+ - * / %`):

1. Two primitive numeric operands use the built-in operator.
2. `string + string` concatenates, as `a.add(b)` and a `T: Add` bound do through `string implements Add`.
3. Otherwise, the impl on the left operand's type runs, the right operand picking among several (*Several impls of one trait*) and being assignable to its `Rhs`; the result has its `Out` type.
4. A left operand typed by a type parameter whose bound names the operator's trait dispatches through that bound (*Generics*): the right operand must be a `T`, the result is a `T`, and a primitive `T` uses the built-in operator.
5. A value of the operator's trait (`a: Add<i32>`) or a union of its implementors dispatches as its method form does (*Traits*), and so does `in` on `Contains`, with the union's errors: `a < b` on two `Comparable` values is an error.
6. Any other operands are an error.

Resolution rule for ordering (`< <= > >=`):

1. Primitive numerics and `char` use the built-in comparison, a float by IEEE 754 (every comparison with `nan` is false). A distinct type orders as its backing (*Distinct types*). `string` orders through its `Comparable` impl, by bytes: code-point order, a proper prefix first.
2. Two struct operands call `Comparable`. A type parameter bounded by `Comparable` dispatches as in arithmetic rule 4.
3. Any other operand is an error: `bool`, enums, arrays, tuples and unions have no `Comparable` impl.

```vader
Ring :: i32[]

Ring implements Index<i64, i32> {
    at :: fn(self, i: i64) -> i32 {
        cells :: i32[](self)
        return cells[i % cells.len()]
    }
}

r :: Ring([1, 2, 3])
r[4]                    // 2: through at
r[0] = 9                // no IndexSet: writes the backing array
r[0..<2]                // [9, 2]: a Range slices the backing
```

`a[i]`, `a[i] = v` and `in` use the built-in array or range first, then their trait, for structs and primitives alike: `string implements Index<i64, char>`, so `s[i]` needs no import.

- A type's own impl wins over the array it is backed by, trait by trait.
- A write with neither an `IndexSet` impl nor an array to store into is an error.
- Outside an array, the key has the trait's index type, for a read as for a write (`m["nope"]` on a `MutableMap<i64, i32>` is an error); a free literal key takes that type.

**Details.**

- `a[i()] += v()` runs `a` and `i()`, reads the element, runs `v()`, and writes the result back to that element.
- A distinct type over a struct indexes only through its own impls, never its struct's.
- A bounded type parameter, a value of the trait (`store: IndexSet<string, i32>`) and a union of implementors (`MutableMap<string, i32> | Log`) read and write through `at` and `set_at`.
- A destructuring place (`[m["a"], m["b"]] = ...`) is a write: it takes the value type of `IndexSet`, never what `Index` returns (`V | null` on a `MutableMap`).

### Nullability

There is no implicit `null`. A value that may be absent has a union type:

```vader
find_user :: fn(id: u32) -> User | null {
    // ...
}

u :: find_user(42)
match u {
    is User -> println("found ${u.name}")
    is null -> println("not found")
}
```

### Equality

```vader
// with Point of §4 *Structs*
Point implements Equals -> self.x == other.x && self.y == other.y

p :: Point { .x = 1, .y = 2 }
p == Point { .x = 1, .y = 2 }   // true: Point's equals
found: Point | null: null
found == p                      // false: another variant
0.0 == -0.0                     // true: IEEE 754
b == '/'                        // true for b: u8: 47: the literal takes the type of b

n == 1.5                        // error: n is an i32, 1.5 a float
Meters(5) == Seconds(5)         // error: two distinct types, though both are over i64
```

| Type | `==` |
|------|------|
| Integers, `bool`, `char` | By value. |
| Floats | By IEEE 754: `nan != nan`, `0.0 == -0.0`, in a union or a generic body too. |
| `string` | By contents. |
| Enum | By variant; every enum implements `Equals` and `Hash`. |
| Distinct type | Its own `Equals` impl, else its backing's `==`. |
| Tuple | Element by element (*Tuples*). |
| Union (`A \| B`, `T \| null`) | The same variant, then that variant's `==`; `null == null`. |
| Type parameter | Through `Equals`, which its bound must name. |
| Struct | Its `Equals` impl; without one, `==` is an error. |
| Array | An error: use a named comparison (below), or `===` for identity. |
| Trait value, function value | An error: narrow it first (`if d is Point`). |

- For a type parameter, this holds when the parameter is a union variant too (`T | null == T`); only `x == null` needs no bound. `x in xs` needs the bound too: `T[]` implements `Contains<T>` only for `T: Equals`.
- A union compares with another union or one of its members when the two sides share a variant, and each variant but `null` needs an `==` (the error names it).
- Comparing two integer types neither of which holds the other is an error (§4 *Implicit numeric coercion*). A distinct type compares with its own backing on either side (`"" == path` with `Path :: string`).

For arrays of a `T: Equals` element, `std/core` names the comparisons:

```vader
a :: [1, 2, 2]
a == [1, 2, 2]                  // error: use content_equals, is_permutation_of or ===
a.content_equals([1, 2, 2])     // true: the same length, equal elements in the same order
a.is_permutation_of([2, 1, 2])  // true: the same elements in some order, each as many times
a.contains_all([2, 2, 2])       // true: every element is in a, each counting once
a.is_disjoint([3, 4])           // true: no element in common
```

- `is_permutation_of` is quadratic.
- An array does not meet an `Equals` bound: `[1] in rows` (`rows: i32[][]`) and `same(a, b)` with `fn<T: Equals>` are errors, and an array of arrays has no `content_equals`.
- A distinct type over an array opts in by implementing `Equals` itself (`Row :: i32[]`); `i32[](row)` gives back the array for these methods.

**Details.**

- A generic `Equals` impl failing on a bound (`Box<T> implements<T: Equals> Equals` on a `Box<Raw>`) is an error naming the type argument that lacks it.
- A generic body compares a `T: Equals` with the impl of the receiver's run-time type. When the other operand holds another type (`T` is a union, or the values are typed `Equals`), `equals` returns `false` without running it, except for an enum or a distinct type, compared as their representation (*Unions*, above).
- A union variant that cannot be told apart at run time (*Unions*, above) may sit only beside `null`: a type parameter, or a generic struct instance with a type argument other than a primitive or an enum (`Box<Point>`). A union holding such an instance beside a variant other than `null` does not satisfy `Equals` either.
- A distinct type stands for its backing through any number of layers: two integers compare when one holds the other (`s == w` compares in `i64`, for `w: i64` and `s` of a distinct type over `Hour`), and two other scalars only when they are the same primitive. `h == INVALID_HANDLE` with `h: Handle` (`Handle :: CPointer`) against an `i64`, and `b == c` with `b: u8` and a `char` variable, are errors.

#### Identity: `===` and `!==`

```vader
a :: Point { .x = 1, .y = 2 }
b :: Point { .x = 1, .y = 2 }
a == b                 // true: equal fields
a === b                // false: two objects
a !== b                // true
found: Point | null: a
found === a            // true: compared by the object it holds
"x" === "x"            // error: a string has no identity, compare with ==
label :: Label { .text = "x" }
a === label            // error: a Point and a Label are never the same object
```

`===` asks whether two references are the same object, and `!==` is its negation.

- Only a reference has an identity: a struct, an array, a union of references (`Node | null` included), a distinct type over one of these.
- `===` on anything else is an error (narrow first, or use `==`): a number, `bool`, `char`, `string`, an enum, a tuple, a function, `null` alone, or a type that may hold one: a value typed by a trait (`i32` implements `Display`), `any`, a type parameter, `Self`.
- The two operands must be able to hold the same object, sharing a variant other than `null`: `Point | null === Label | null` is an error too.
- The compiler warns when both operands may hold a struct with no field: such a value carries only its type, which `is` tests.
- `===` goes through no trait and cannot be overloaded.

---

## 5. Variables and Bindings

### Binding forms

A binding takes one of four forms. The annotation `: T` gives a type inference cannot decide (`buffer: u8[] = []`), or makes it visible.

| Form              | Mutability | Type     | Example          |
|-------------------|------------|----------|------------------|
| `name :: value`   | immutable  | inferred | `pi :: 3.14`     |
| `name := value`   | mutable    | inferred | `total := 0`     |
| `name: T: value`  | immutable  | typed    | `cap: i64: 1024` |
| `name: T = value` | mutable    | typed    | `count: u64 = 0` |

```vader
n := 0          // mutable, inferred i32
n = n + 1       // OK
k :: 0          // immutable
k = 1           // error: cannot reassign immutable binding
```

Only a mutable local, a parameter or a name a pattern binds may be rebound. A declaration cannot be rebound, even renamed by an import or reached through a namespace (`P.SEP = 'x'`), and neither can a `for ... in` variable (§7 *`for` (universal loop)*) or a `match` header name (§4 *Pattern matching*).

The compiler warns about a mutable local never rebound: only an assignment to the bare name rebinds it, compound assignments included; `x.f = 1` and `x[0] = 1` do not. A destructuring `:=` draws no warning when one of its names is rebound.

At module level, only the immutable forms declare; module state lives in a `@singleton` (§12 *`@singleton`*).

The top level is not ordered. A constant or a function may read a module constant declared below it: `INNERS :: [ONE]` above `ONE :: Inner { .n = 7 }` is an `Inner[]`.

- A constant whose value reads itself, directly or through others (`A :: B + 1`, `B :: A + 1`), is an error. When the read sits in a function its value calls, a `@comptime` constant reports it when evaluated, and reading any other one stops the program.
- A read inside a lambda waits until the lambda runs, so an annotated constant may name itself there; an unannotated one may not.

```vader
fact: fn(i32) -> i32 : (n: i32) -> if n <= 1 { 1 } else { n * fact(n - 1) }
```

### Mutability: two independent axes

- **The binding.** `::` forbids rebinding the name, `:=` allows it (*Binding forms*, above). An assignment targets a name, a field or an element; any other target (`get() = 3`, `xs.len() = 5`, `Direction.North = .South`) is an error.
- **The referent.** A value may be modified through any name that reaches it: a parameter, a local, a field, an element. No signature says whether a function modifies what it is lent (*What a function does with what it is lent*, below).

Only two kinds of value are **frozen**, which the compiler forbids modifying in place: the value of a module constant, at every level, and a view of a string's bytes (`s.bytes()`).

```vader
CONFIG :: Config { .retries = 3 }

main :: fn() -> i32 {
    p :: Point { .x = 1, .y = 2 }
    p.x = 5                 // OK: `::` froze the name, not the contents
    // p = other_point      // error: that is the binding
    // CONFIG.retries = 5   // error: a module constant is frozen
    c :: CONFIG
    c.retries = 5           // OK: `c` holds a copy of the constant
    return c.retries
}
```

### Frozen values

A module constant cannot be modified, at any depth. These are errors:

- a write through it, directly or down a path (`CONFIG.retries = 5`, `TABLE[0].n = 1`, `[PAIR[1], y] = ...`);
- lending it to a function that modifies it, directly or down the calls it hands it to. A call through a trait, a bound or method syntax is judged by every function it may run.

Binding it to a name, storing it in a field or an element, returning it or handing it to a function value makes a copy the program owns. A write to such a copy, or to a copy of variant data, that the body never reads nor keeps draws a warning: `c.n = 0` in `for c in TABLE { ... }` changes nothing. A write below the name is no read of it, and a name that may hold another value (a parameter, a branch, a rebinding) draws none.

```vader
TABLE :: [1, 2, 3]

fill :: fn(buf: i32[], value: i32, n: i32) -> void {
    for 0..<n {
        buf.push(value)
    }
}

refill :: fn(buf: i32[]) -> void = fill(buf, 0, 4)

TABLE.fill(1, 2)           // error: `fill` modifies it (`buf` grows)
TABLE.refill()             // error: `refill` modifies it through `fill`
TABLE.clone().fill(1, 2)   // OK: a copy
```

A view of a string's bytes (§4 *Strings*) is the string's own bytes, never copied implicitly. It may be read, lent to a function that only reads it, and returned. Writing it, lending it to a function that modifies it, keeping it (in a field, an element or a module constant's value) or handing it to code the compiler cannot follow (a function value) is an error.

Only the view itself counts: a byte read from it is a value, and so is a name narrowed to a type no byte array is (`r: u8[] | Failure` in `if r is Failure { failures.push(r) }`). `.clone()` makes a copy the program owns. The result of a function that returns a view is a view, as that of `bytes()` is.

```vader
bytes_of :: fn(s: string) -> u8[] = s.bytes()   // OK: it returns the view

v :: "abc".bytes()
v[0] = 'x'                                      // error: written
bytes_of("abc").push(0)                         // error: `push` modifies it
p :: Packet { .payload = "abc".bytes() }        // error: kept
q :: Packet { .payload = bytes_of("abc").clone() }   // OK: a copy
```

### What a function does with what it is lent

The compiler reads from a function's body what it does with each parameter: which parts it assigns, grows or shrinks, keeps past the call or returns. Calls are followed over the whole program: a write at the end of a call chain counts at the call that lends a frozen value.

An intrinsic is described by the compiler, an `@extern` by its `@c_out` parameters (§13), and a function value may do anything. The same reading decides whether an array argument may widen its element (§4 *Variance*).

### No mutability marker

A type says nothing about what may be written: a `!` after a type is a syntax error, `const` before one an error.

### Scoping

Scopes are lexical (a function, a block), and a local is visible from its declaration on. A local may shadow an outer local or a parameter in a sub-block, or a name declared earlier in its own block; the compiler warns when it does.

---

## 6. Functions

### Declaration

```vader
add :: fn(a: i32, b: i32) -> i32 {
    return a + b   // explicit
}

double :: fn(x: i32) -> i32 {
    x * 2          // implicit (last expression)
}

// A function returning nothing may omit the arrow (`-> void` is the same).
log :: fn(message: string) {
    println(message)
}

// Expression-body form: `= expr` replaces a single-expression brace body.
add_one :: fn(x: i32) -> i32 = x + 1
```

`return` may appear anywhere in a body. A body that ends on an expression of the return type returns that value.

In a function with a return type, every path must produce a value of that type. Two cases are errors:

- the body reaches its closing brace without a trailing expression and without diverging: `f :: fn() -> i32 { n :: 1 }`;
- the trailing expression has the wrong type: `fn(c: bool) -> i32 { if c { return 7 } }` ends on an `if` with no value.

A body **diverges** when its last statement is a `return`, a `break`, a `continue`, a call to a `@no_return` function (`panic`, `todo`), or a loop that no `break` leaves, so `fn() -> i32 { for { ... } }` is valid. The same rule applies to a lambda whose result type is set by an annotation or by its slot.

A function that returns nothing omits the arrow or writes `-> void` (`void` is reserved, §3 *Reserved keywords*). A function type follows the same rule: `fn()` is `fn() -> void`. The last expression of such a function, or of a lambda in a slot that returns nothing, is evaluated and its value discarded: `remember :: fn(seen: MutableSet<string>, s: string) { seen.add(s) }` compiles although `add` returns a `bool`. A `return` with a value is an error there.

### `main` entry point

The program starts at the top-level function `main`. It has one of two signatures, and any other is an error:

```vader
main :: fn() -> i32                 // ignore argv
main :: fn(argv: string[]) -> i32   // receive process args
```

- `argv[0]` is implementation-defined: the script path under `vader run`, the binary path natively. The user's arguments start at `argv[1]`.
- The returned `i32` is the process exit status, and `0` reports success. The operating system decides how much of it the parent sees: on Linux and macOS, the low 8 bits (`300` reads as `44`).
- A program that stops, on a run-time check (§2 *Run-time checks*), a `panic` or otherwise, never exits with status 0.

### Default parameter values

A parameter may declare a default value, used when a call leaves the parameter out:

```vader
greet :: fn(name: string, prefix: string = "Hello") -> string {
    return "${prefix}, ${name}"
}

greet("Alice")                    // "Hello, Alice"
greet("Bob", "Hi")                // "Hi, Bob"
greet("Eve", prefix = "Hello")    // "Hello, Eve" (named parameter)
```

### Named arguments at call site

An argument may name its parameter, `f(a = 1, b = 2)`, in a bare call and through UFCS alike. Named arguments may come in any order. Arguments are evaluated in the order they are written, so `f(b = g(), a = h())` calls `g` first. These are errors:

- a positional argument after a named one;
- a name that is not a parameter of the function, or that names a parameter a positional argument already filled;
- a parameter without a default value that no argument fills.

### Variadics

Planned: a parameter written `...nums: i32[]` receives the remaining arguments of a call as an array.

```vader
sum :: fn(...nums: i32[]) -> i32 {
    total := 0
    for n in nums { total = total + n }
    return total
}

sum(1, 2, 3, 4)
```

### Closures / lambdas

A lambda is written `params -> body`, without the `fn` keyword.

```vader
// Single param: parens optional, expression body
items.map(x -> x * 2)
items.map((x) -> x * 2)

// Single param typed (parens required for the `:` annotation)
items.map((x: i32) -> x * 2)

// Multi-param (parens required)
arr.fold(0, (acc, x) -> acc + x)

// No-arg (empty parens required)
btn.on_click(() -> { count = count + 1 })

// Multi-statement via block-expr
items.map(x -> {
    tmp :: x * x
    tmp + 1
})
```

A parameter written without a type takes it from the function type of the slot the lambda fills (§6 *Function values*). Leaving it out with no such slot is an error.

The `->` form has no place for a return type: the type comes from the slot the lambda fills (a parameter, a field, a typed declaration) or from its body. To write the return type, use an anonymous function literal `fn(params) -> R { body }` or `fn(params) -> R = expr`, which is allowed wherever a value is expected and means the same thing, or a named function:

```vader
inc :: fn(x: i32) -> i32 { x + 1 }
items.map(inc)
```

A named function may be declared at the top level or inside a function body. Its parameter and return types follow §4 *Type inference*; a recursive function with an expression body must write its return type.

A closure captures variables by reference. An assignment to a captured variable, inside or outside the closure, is visible on both sides:

```vader
n := 0
inc :: fn() { n = n + 1 }
get :: fn() -> i32 { n }
inc()
get()                      // 1
```

### Function values

A function type `fn(T1, T2, ...) -> R` is an ordinary type. A function name that is not immediately called is a function value, and a lambda fills a function-typed slot directly:

```vader
add :: fn(a: i32, b: i32) -> i32 { return a + b }

main :: fn() -> i32 {
    f :: add               // f: fn(i32, i32) -> i32 (inferred from `add`)
    return f(2, 3)         // indirect call: same syntax as direct
}
```

```vader
cb: fn(i32) -> i32 : x -> x + 1
println(cb(41))                                       // 42

Handler :: struct { cb: fn(i32) -> i32 }
h :: Handler { .cb = (x) -> x * 2 }
println(h.cb(21))                                     // 42
```

A slot gives its function type to what fills it: the parameters of a lambda, the instance of a generic function, the member that several impls offer. A slot of a union type gives the one function type among its variants, as an optional callback `(fn(i32) -> void) | null` does; a union holding two function types gives none.

### UFCS (Uniform Function Call Syntax)

```vader
plus :: fn(this: i32, other: i32) -> i32 {
    return this + other
}

// Equivalent calls:
plus(2, 3)
2.plus(3)
```

`a.f(b)` is `f(a, b)`. Vader has no methods: any free function can be called this way on its first argument.

When the struct of `a` declares a field `f`, or every variant of its union reads `f` the same way (§4 *Common-field access*), `a.f` reads that field even if functions named `f` exist. `a.f(b)` then calls the field if it holds a function, and otherwise the functions named `f`.

Outside a call, `a.f` is a function value: `f` with `a` bound as its first argument, taking the other parameters. `a` is evaluated once, when the value is taken:

```vader
show :: p.label                // fn() -> string
p = q
show()                         // the first `p`'s label
twice(p.label)                 // as an argument
xs.map(p.scale)                // fn(i32) -> Point, each element a `k`
plus: fn(f64) -> f64: v.add    // several impls offer `add`: the slot picks one
```

Every kind of callee can be taken as a value: a free function, an impl member, the member of a trait value (dispatched on the value), of a union (on its tag) or of a bounded `T`, and an array member (`xs.len`, `xs.push`).

- A conversion of the receiver to the first parameter (an array reaching an `Iterator`) runs at each call.
- A member that several impls of one trait offer is picked by the function type of the slot; with no slot, it is an error.
- A generic free function is instantiated where it is taken, the receiver binding what its first parameter names and the slot the rest. A type parameter left unbound is an error.
- A static member cannot be taken as a value.

A free function is a candidate for `a.f(...)` when the receiver fits its first parameter in one of these ways:

- the receiver's type is assignable to the parameter's type, where a type parameter stands for any type: `m.size()` on a `MutableMap<string, i32>` reaches `size :: fn<K, V>(self: MutableMap<K, V>)`;
- the parameter is a trait the receiver implements: `s.chars().filter(p)` reaches `filter :: fn<T>(self: Iterator<T>, ...)`. An array fits an `Iterator<T>` parameter here too, through its own conversion (§15 *Iteration*);
- when no function fits by those two rules, an `Into` impl converts the receiver to the parameter's type (§4 *Type coercion via `Into`*): with `Celsius implements Into<Label>`, `c.shout()` calls `shout :: fn(l: Label)`.

On a union receiver, the first parameter may be the union itself. A field only some variants have is an error (§4 *Common-field access*), even when a function of that name exists. The most specific candidate wins (*Function overloading*, below).

#### Import requirement

`x.foo()` resolves the same way as `foo(x)`: its candidates are the functions of the calling module, of the modules its file imports and of the prelude `std/core` (§11 *Prelude*), and no others.

```vader
// file: app/geo/geo.vader
module "app/geo"

export Square :: struct { side: f64 }
export area :: fn(s: Square) -> f64 = s.side * s.side

// file: app/paint/paint.vader
module "app/paint"

import "app/geo"

export area :: fn(s: Square) -> f64 = 4.0 * s.side

// file: app/main.vader
module "app"

import "app/geo"
import "app/paint" { area as _ }          // without it, `area` is ambiguous here

square :: fn() -> Square = Square { .side = 3.0 }
total :: fn() -> f64 = square().area()    // 9.0: area(square()), from app/geo

// file: app/frame.vader
module "app"

P :: import "app/paint"

frame :: fn() -> f64 = P.area(square())   // 12.0
broken :: fn() -> f64 = square().area()   // error: `area` is in scope only as `P.area`
```

When two wildcard imports each offer a `foo` that fits the receiver equally well, both `x.foo()` and `foo(x)` are ambiguous.

#### Function overloading

Two free functions of one module may share a name when they differ in the type of their first parameter. A call picks one by the type of its first argument, which through UFCS is the receiver.

```vader
size :: fn(self: Path) -> i32 { ... }
size :: fn<K, V>(self: MutableMap<K, V>) -> i64 { ... }

p.size()            // resolves to the Path version
m.size()            // resolves to the MutableMap version
```

These are errors:

- two functions of one module with the same name and parameter types: a redefinition, reported at the declaration even when nothing calls them. A module spans every file of its folder, so two single-file programs in one folder, each with its own `main`, are a redefinition too;
- a call that reaches two candidates with the same first parameter type and the same number of parameters; declaring both is not an error.

Among the candidates whose first parameter accepts the first argument, the most specific candidate wins. These ranks decide, in order:

1. A parameter naming a concrete member of the argument's union beats a bare `T`: for an `i32 | Boom` argument, `T | Boom` beats `T | null`. A concrete overload beats a type-parameter receiver (`fn<T>(self: T)`) where it applies.
2. For an integer argument, its own type, then the narrowest integer type that holds it: `min(b, b)` on a `u8` takes the `i32` overload over the `i64` one.
3. On a direct call, the candidate whose number of parameters matches. Through UFCS this rank does not apply, and candidates with different numbers of parameters are never ambiguous with each other.
4. For a free literal, the candidate whose parameter is the literal's default type (§4 *Default integer*): `abs(-5)` reaches the `i32` overload whatever the declaration order.

If two candidates of one module are still tied after these ranks, the call is an error: `x.or(-1)` on `x: i32 | Error | null` fits `or(x: T | null, d: T)` and `or(x: T | Error, d: T)` equally. Narrow `x` first.

In a generic body, a call is resolved once, against the type parameters. A first argument typed by `T`, or by a type that mentions it (`T[]`), reaches only the candidates whose first parameter accepts `T` itself, never an overload on a concrete type, and every instance runs the candidate chosen. With `describe :: fn<T: Display>(self: T)` and `describe :: fn(self: i32)`, `show :: fn<T: Display>(v: T) -> string = v.describe()` runs the generic one for `show(1)`. Behaviour that must differ by type goes through a trait bound (§4 *Specialization: the instance wins*).

A function of the module and an imported function of the same name overload each other, and the local one wins a tie: `"".is_empty()` reaches the `is_empty` of `std/string`, and `b.is_empty()` a local `is_empty :: fn(self: Box) -> bool`. Two functions that two wildcard imports bring overload each other too.

### Visibility

The `export` keyword (§11 *Visibility*) is distinct from the `@export` decorator, which exposes a function to the host (§13 *`@export`: exposing a function*); a function may have both.

---

## 7. Control Flow

### `if` / `else`

```vader
x :: if b > 2 { 2 } else { 3 }

if cond {
    // ...
} else if other {
    // ...
} else {
    // ...
}
```

`if` is an expression; used as a value, its branches must give compatible types.

### `match`

```vader
result :: match value {
    42                  -> "literal int"
    is i32 if value > 0 -> "pos"
    is i32              -> "non-pos"
    is string           -> "str: $value"
    'A'                 -> "literal char"
    is char             -> "?"
}
```

A `match` must be exhaustive (§4 *Exhaustiveness*). §4 *Pattern matching* gives its full grammar.

### `for` (universal loop)

```vader
// Exclusive range
for i in 0..<10 {
    println("$i")
}

// Inclusive range
for i in 0..=10 { ... }

// Iterate over a collection (built-in array, Iterator, or an Into<Iterator> type)
for item in items {
    println(item)
}

// Tuple-destructuring binding: each yielded tuple is unpacked into the names.
for [key, value] in pairs {
    println("${key} = ${value}")
}

// While-like
for cond {
    // ...
}

// Infinite
for {
    if exit_condition { break }
}

// Iter without a binding (sugar for `for _ in <iter>`)
for 0..<GENERATIONS {
    step()
}
```

Without a variable, `for <expr> { body }` depends on the type of `<expr>`. A `bool` makes it loop while the expression holds; an iterable value (an array, an `Iterator<T>`, a `Range`, ...) makes it `for _ in <expr>`. Any other type is an error.

The variable of a `for x in ...` is a constant binding, bound anew at each turn, and so is each name of `for [k, v] in ...`. Assigning it is an error; modifying the value it designates, as `x.push(y)` does, is allowed. The condition form binds nothing: in `for i > 0 { i -= 1 }`, `i` is an ordinary local.

What a loop iterates over is evaluated once, before the first element. A range evaluates `lo`, then `hi`, when it is built, so `for i in 0..<n { n = 5 }` runs as many times as `n` held on entry. An array has its length read then: an element the body pushes is not visited, and a turn past the end of an array the body shortened stops the program, whether the loop names its element or not. A lazy chain evaluates its source, then the argument of each combinator, then that of the terminal, once each, even when the source is empty: `xs.map(f()).filter(p()).any_match(q())` evaluates `xs`, `f()`, `p()`, then `q()`.

`for x in expr` accepts four kinds of `expr`:

1. An array `T[]`: its elements, in index order.
2. An `Iterator<T>`, concrete or held as the trait (`it: Iterator<T>`), advanced until it stops (§15 *Iteration*).
3. A value implementing `Into<Iterator<T>>`, converted with no `.into()` written.
4. A type:
   - a range, an integer type within `i64` or a `T: Int`: its values, the least first (`for h in Hour`; `for b in u8` runs 256 turns);
   - an enum without variant data: its variants, in declaration order (`for d in Weekday`);
   - any other type is an error, `u64` and `char` included.

### Targeting an outer loop: `break <var>` / `continue <var>`

A bare `break` or `continue` acts on the innermost loop. `break <name>` and `continue <name>` act on the nearest enclosing loop whose iteration variable, or label (below), is `<name>`. The names of a destructuring loop (`for [k, v] in ...`) are not targets. Any other name is an error, the name of a local included.

```vader
for row in grid {
    for cell in row {
        if cell == 0    { continue }      // innermost: bare
        if cell == goal { break row }     // the row-loop, by its variable
    }
}
```

A loop with no variable to target takes a label, a `name:` prefix: a condition loop (`for <cond>`), an infinite loop (`for {}`), a destructuring loop, or one whose variable is `_`.

```vader
scan: for !done {
    for cell in row {
        if cell == goal { break scan }
    }
}
```

The compiler warns about a label on a loop that has an iteration variable: target that loop by its variable instead.

### `defer`

`defer` registers a statement or a block to run when its block is left, the last registered first.

```vader
process :: fn(path: string) -> string | Error {
    file :: open(path)
    if file is Error { return file }
    defer close(file)

    {
        tmp :: allocate_temp()
        defer free(tmp)
        // tmp freed at the end of this sub-block
    }

    // file closed at the end of the function
    return read_all(file)
}
```

A `return`, like the trailing value of a block, computes its value before the defers run, so a defer that writes to a local the value reads does not change the value.

A `defer` body cannot `return`, `yield` or `await`, nor `break` or `continue` a loop it is not inside; a `return` in a lambda written there returns from that lambda. A `defer` in a generator is an error.

When the program stops (a `panic`, a failed run-time check, `unreachable`), the pending defers of every frame run, innermost first, before the process ends. A stop inside a deferred body ends the program at once, without running the defers still pending. There is no `recover`.

### Unreachable code

The compiler warns on the first dead statement of each block: one that follows, in the same block, a `return`, a `break`, a `continue`, or a `for` loop that no `break` leaves.

---

## 8. Memory Model

### GC

Every value that is not a primitive (a struct, an array, the contents of a string, and the standard library types built from them) is managed by a garbage collector. A program never frees memory: a value stays alive as long as the program can reach it.

### GC backends

Each backend provides the collector. A native binary carries its own, described in [`docs/RUNTIME.md`](./docs/RUNTIME.md) *Memory*. On the WebAssembly backend (planned, §17), the WebAssembly host is to collect the values, through the WebAssembly GC proposal.

### Storage semantics

- Primitives (`i32`, `f64`, `bool`, ...) are values, copied on assignment.
- A `string` is an immutable value, copied on assignment. Copies share their content.
- Structs and arrays live on the heap and are reached through implicit references. A function a struct or an array is passed to reaches the caller's value, and can modify it unless it is frozen (§5 *Frozen values*).

### No visible pointers

There is no address-of or dereference operator and no pointer type. Memory is managed implicitly. Explicit allocators are planned for performance-critical code (*Explicit allocators*, below).

### Escape analysis

The compiler may allocate a struct on the stack when it proves that the struct does not escape. It is never required to, and a program cannot observe the difference.

### Explicit allocators

An API is planned to allocate into an arena, a buffer and the like in performance-critical code, alongside the garbage collector. It is not specified yet.

### Finalizers

There are none. A resource other than memory (a file, a socket, a handle) is released explicitly, with `defer` (§7 *`defer`*):

```vader
file :: open("a.txt")
defer close(file)
```

---

## 9. Strings

This chapter covers rendering a value into a string (the type: §4 *Strings*; its literals: §3 *String literals*, §3 *String interpolation*).

### Compile-time verification

Each `${...}` is type-checked with the program and renders through its type's `Display` impl. An unknown name, a malformed expression or a value whose type lacks `Display` (an enum with neither `@displayable` nor an impl, a struct without an impl, an array of such a type, a type parameter without a `Display` bound) is an error.

### `Display` trait

Every primitive and `null` (rendered `"null"`) implement `Display`.

An array renders its elements through their own `Display`, separated by `, ` between brackets (`"${[[1], [2, 3]]}"` is `"[[1], [2, 3]]"`), but does not satisfy a `T: Display` bound: `show(xs)` is an error for `show :: fn<T: Display>(x: T)`.

An enum gets `Display` from `@displayable` (§4 *Enums*), any other user type from an impl:

```vader
Point implements Display {
    to_string :: fn(self) -> string {
        return "(${self.x}, ${self.y})"
    }
}
```

---

## 10. Errors

### "Errors as values" model

Errors are ordinary values (*Error unions*, below).

```vader
read_file :: fn(path: string) -> string | IOError {
    // ...
}
```

### Error unions

A function that can fail returns its success type in a union with one or more error types, written out (`parse_int :: fn(s: string) -> i32 | ParseError`): there is no shorthand such as a postfix `!`.

### `Error` trait

```vader
Error :: trait {
    message :: fn(self) -> string
}
```

The standard library's errors (`IOError`, `ParseError`, ...) implement it. In a union such as `T | Error`, the member `Error` holds a value of any type implementing it.

### Error propagation

An error propagates by a test and a `return`; past the test, the value is narrowed to its success type (§3 *Type tests and narrowing*):

```vader
process :: fn(path: string) -> string | Error {
    raw :: read_file(path)
    if raw is Error { return raw }    // raw is `string` below
    return parse(raw)
}
```

### Explicit match

An error handled in place is matched like any other union:

```vader
r :: read_file("a.txt")
match r {
    is string -> println("got: ${r}")
    is Error  -> println("error: ${r.message()}")    // virtual dispatch
}
```

---

## 11. Modules

### Module declaration

Every `.vader` file declares its module first: the keyword `module`, then the module's name as a string literal.

```vader
#!/usr/bin/env -S vader run     // optional shebang
// optional leading comments

module "std/string"             // mandatory
```

Only a shebang line and comments may precede it. The following are errors:

- a file without a `module` declaration, or with an `import` or a declaration before it;
- a second `module` declaration in the same file.

### Module name grammar

```
module-name ::= segment ('/' segment)*
segment     ::= [a-z] [a-z0-9_]*
```

Valid names: `main`, `std/string`, `std/string/utf8`, `vader/front/lexer`, `my_app/util_2`.

Invalid names: `Std/String` (uppercase), `std/1string` (a segment starts with a digit), `std//string` (an empty segment), `std/string/` (a trailing slash), `./relative` (other characters).

A `/` is an ordinary character of the name.

### Granularity and location

A module is the set of `.vader` files directly inside one folder, and its name decides where that folder is: `import "a/b/c"` looks for the folder `a/b/c` under each search root in turn (*Include paths*, below).

- A folder holds at most one module: files of one folder that declare different names are an error. Its sub-folders hold other modules.
- A folder at a module's location that declares another name does not provide that module.
- Modules are independent of each other: `std/string` and `std/string/utf8` are unrelated. A shared prefix gives no parent-child relation, no implicit re-export and no visibility.

### Imports

```vader
import "std/string"                                 // wildcard: every export, unqualified
str :: import "std/string"                          // namespace, reached as `str.trim(...)`
import "std/string" { trim as strip, split as _ }   // wildcard + modifiers: rename / exclude
```

An import takes one of three forms:

- **Wildcard**, `import "path"`: every export of the module (functions, types, structs, enums, traits and constants) is visible unqualified in the importing file, as if declared there. It is the usual form.
- **Namespace**, `name :: import "path"`: binds the alias and nothing else. Every member is reached through it: `str.trim`, `str.Builder`, and `is str.Type` in a test or a `match` arm.
- **Wildcard with modifiers**, `import "path" { x as y, z as _ }`: the wildcard of `path`, with a few names changed. `x as y` renames `x` to `y`, and `z as _` leaves `z` out.

An alias names a module, not a value: `x :: str` and `f(str)` are errors. A member the module does not export is an error, as the same name would be unqualified; the module's own imports are not members.

There is no implicit binding of the path's last segment, and no `as` after the path.

#### Resolution rules

```vader
// file: app/report.vader, with app/geo and app/paint of §6 *Import requirement*
module "app"

import "app/geo"
import "app/paint" { area as border }

both_areas :: fn(s: Square) -> f64 = area(s) + border(s)   // 21.0 for a side of 3.0
```

```vader
import "./geo"                          // error: an import names a module, never a file
import "app"                            // error: a file of `app` imports its own module
import "app/geo"
import "app/geo" { area as _ }          // error: `app/geo` is imported twice in this file
import "app/paint" { area }             // error: the wildcard already brings `area`
```

- The string of an `import` is a module name, resolved against the search roots (*Include paths*, below).
- Imports are file-scoped: each file of a module declares its own, and sees none of its siblings'.
- A type or a constant that two wildcard imports export is an error only where it is used unqualified, and the error names every module that provides it. A declaration of the module or a rename binding of that name shadows the wildcards, and a name the prelude or a builtin provides always refers to that one. A namespace import, a rename or an exclusion settles an ambiguity.
- Functions of one name overload instead, across wildcard imports and with the module's own (§6 *Function overloading*). Named without being called, a function that two wildcard imports export is still an error.
- A rename or a namespace alias cannot take the name of a type or constant the module declares, in any of its files. It can take a function's: the module's function keeps the unqualified name, and the imported one stays reachable by UFCS (§6 *Function overloading*); with the same signature, the two are a redefinition, an error. Either error is reported on the import. Two files of a module may import the same name.
- There are no re-exports: a module publishes only what it declares. A module that fronts another wraps each binding it republishes.

**Details.**

- An import cycle, direct or through other modules, is an error.
- A path is imported once per file, in any form: one import holds all its modifiers.
- Two rename modifiers that bind one name in one file (`import "a" { x as p }` and `import "b" { y as p }`) are an error.
- `import "p" {}` is the bare wildcard: the compiler warns, toward `import "p"`.

#### Prelude

`std/core` is an implicit prelude: every export of `std/core` is in scope in every other module without an import, so `Range`, `Field`, `Display`, `Iterator` and the rest are usable directly. A declaration of the module, or a rename in an import (`import "std/string" { trim as Range }`), hides a prelude name of the same spelling. The prelude does not apply inside `std/core` itself. An explicit `import "std/core"` in another module is an error.

### Visibility

A top-level declaration has one of two levels:

- **private**, the default (no keyword): visible to every file of the module without an import, and invisible to any other module. There is no file-private level.
- **`export`**: visible to the modules that import this one. `main` is always public, with or without `export`.

```vader
helper :: fn(x: i32) -> i32 = x + 1           // visible to every file of this module, invisible outside

export api :: fn(x: i32) -> i32 = helper(x)   // visible to every module that imports this one
```

#### Intra-module collisions

The files of a module share its namespace:

- Two structs, type aliases, constants, enums or traits with the same name are an error, in one file or across files.
- Functions with the same name join one overload set, across files as within one file (§6 *Function overloading*). An ambiguity shows at a call where their parameters overlap.

#### Exported declarations cannot expose a non-exported type

An exported declaration cannot name a non-exported type in the parameter or return types of a function, or the fields of an exported struct. The right-hand side of a type alias and the type of an exported constant are not checked.

```vader
Secret :: struct { value: i32 }          // private to this module

export reveal :: fn() -> Secret { ... }   // error: Secret is not exported
```

### Configuration: `vader.json`

A project is a folder described by its `vader.json` or by its `build.vader` (*Programmable build API*, below); a file can also be compiled without one. Which project a command takes is described in `docs/TOOLING.md` *Projects*.

```json
{
  "name": "myapp",
  "version": "0.1.0",
  "includePaths": ["lib"],
  "entries": { "myapp": "src/main.vader" },
  "assets": ["sprite.png"]
}
```

| Key | Meaning |
|-----|---------|
| `includePaths` | Extra module roots, each a folder relative to the project root or under `$VADER_HOME` (*Include paths*, below). |
| `entries` | The programs of the project, each binary's name mapped to its entry file. |
| `assets` | The files and folders copied beside the binaries. |
| `name`, `version` | A description of the project, which no build uses. |

The paths of `entries` and `assets` are relative to the project root. An asset path that is absolute, or that leaves the project through `..`, is an error, and so is any other key, or a key of the wrong shape.

An entry's name is its binary's file name, so it must be one on every platform: ASCII letters, digits, `_` and `-`, not starting with `-`, and none of the names Windows reserves for a device (`con`, `prn`, `aux`, `nul`, `com0` to `com9`, `lpt0` to `lpt9`), whatever its case. Any other name is an error, and so are two names that differ only in case: a file system that ignores case gives them one binary.

#### Include paths

```vader
// file: shop/cli/main.vader     the entry: its namespace `shop` is rooted at shop/
module "shop/cli"

import "shop/cart"               // shop/cart/
import "shop/cli/args"           // shop/cli/args/
import "std/string"              // the library root
import "tools/log"               // error without a project: tools/ lies beside shop/
```

```vader
// file: tool/main.vader         a single segment: `app` is rooted at tool/
module "app"

import "app/util"                // tool/util/
```

An import is resolved against an ordered list of module roots. The first root whose folder at the module's location declares that module provides it; a later folder that declares the same name is ignored.

- The entry's namespace comes first: the first segment of its declared name, rooted at the folder that segment names, and no folder beside it.
- When the entry's folder does not end with its name, or the name has a single segment, the name is rooted at the entry's own folder.
- The command's roots, the library root (*Library root*, below) and the project's roots follow, in the order `docs/TOOLING.md` *Search roots* gives. Generated modules come last, and extend a module instead of shadowing it (*Generated modules*, below).

#### Library root

`std/` lives under the toolchain's **library root**, a module root that holds every namespace the toolchain ships. How a command finds it is described in `docs/TOOLING.md` *Toolchain*.

External packages are planned.

### Resolution

A program is resolved from its entry outward: its modules are the entry's module and the modules it imports, directly or not. A module that nothing imports is never read.

### What appears at the top level of a `.vader` file

```vader
module "shapes"                                  // first

import "std/io"

Circle :: struct { radius: f64 }                 // a struct
Square :: struct { side: f64 }
Figure :: Circle | Square                        // a type
Shape :: trait { area :: fn(self) -> f64 }       // a trait
PI :: 3.14159                                    // a constant

@displayable                                     // a decorator
Unit :: enum { Metre, Inch }                     // an enum

Circle implements Shape {                        // a trait implementation
    area :: fn(self) -> f64 = PI * self.radius * self.radius
}

@assert(PI > 3.0)                                // a compile-time check (§12)

square_area :: fn(s: Square) -> f64 = s.side * s.side    // a function

println("loaded")                                // error: a statement belongs in a function body
```

Nothing else appears at the top level: code with an effect lives in a function body, usually `main`. Importing a module runs no code.

### Generated modules

A module's files live in one folder: the first root that provides it wins (*Include paths*). The exception is the generated modules of a project, which its driver writes (*Generating code*, below): a generated file joins a module that an earlier root provides instead of shadowing it.

A driver's `ctx.emit_module("app", ...)` can therefore extend the project's own `app`. The generated file becomes one more file of the module: it sees the module's declarations, and they see its own, with no `import` either way. The module's identity remains its primary folder.

### Programmable build API: `build.vader`

A project drives its own build with a `build.vader` at its root, which the command compiles and runs (`docs/TOOLING.md` *Build drivers*). The driver decides what to compile: the compiler is part of its import closure. Its folder is the project of the entries it adds.

`build.vader` declares `module "build"` and `build :: fn(args: string[]) -> i32`. The name is reserved, as `main` is in a program. A `build.vader` that declares another module is an ordinary source file of its folder, not a driver.

```vader
module "build"

import "toolchain/build"

build :: fn(args: string[]) -> i32 {
    ctx :: new_build_context(args)
    ctx.add_entry("myapp", "src/main.vader")
    return ctx.emit_native()
}
```

#### What a driver declares

A driver describes in code what a `vader.json` declares:

- `ctx.add_entry(name, path)` adds a program, as a key of `entries` does, its name under the same rule;
- `ctx.add_asset(path)` adds a file or folder to copy beside the binaries, as `assets` does;
- module search roots go in `ctx.include_paths`, and are resolved and ranked as `includePaths` are.

An entry or an asset that breaks its rule is an error. When the driver starts draining `ctx.messages()` with an error already reported, one of its own reports included, nothing is described or compiled: the stream yields only a `CompleteMessage` of code 1.

The end of the stream prints the diagnostics of the build, the driver's reports included, and an error among them makes the build's code 1. What a driver reports once the build is over, or when it leaves the loop before the end, prints when `build` returns, and fails the build the same way.

#### What the command decides

What the command asked reaches the driver in `args`, and the driver does not change it. `ctx.mode()` names it: `.Build`, `.Check`, `.Prepare` or `.Describe` (`docs/TOOLING.md` *Build drivers*). Only `.Build` writes outputs: otherwise `ctx.emit_native()` links nothing and returns 0. A step after the build, such as installing or packaging, first checks `ctx.mode() == .Build`.

#### The message stream

A driver reaches the compiler through `toolchain/build`, and names AST types through `toolchain/ast`. Draining `ctx.messages()` is the build: it yields each module's typed declarations, then the phase boundaries, and last a `CompleteMessage` whose `code` is the build's exit code. `Phase.BeforeEmit` is the last point where leaving the loop writes nothing, which is how a driver that only lints declines to build.

#### Plugins

A plugin is a type that implements `BuildPlugin`. `ctx.use(p)` plugs it into the build: it hears each message of the stream, in the order the plugins were plugged, before the driver's own loop does. Its members do nothing unless it overrides them:

- `on_module(ctx, msg)` receives the typed declarations of one module;
- `on_phase(ctx, phase)` receives a phase boundary;
- `on_complete(ctx, code)` receives the end of the build, where a report still fails it.

```vader
module "build"

import "std/string"
import "toolchain/build"
AST :: import "toolchain/ast"

StructNames :: struct {}

StructNames implements BuildPlugin {
    on_module :: fn(self, ctx: BuildContext, msg: TypecheckedMessage) -> void {
        if msg.module_name != "app" {
            return
        }
        for d in msg.declarations {
            if d is AST.StructDecl && d.name[0..<1].to_upper() != d.name[0..<1] {
                ctx.report(d.name_span, "struct `${d.name}` should be PascalCase")
            }
        }
    }
}

build :: fn(args: string[]) -> i32 {
    ctx :: new_build_context(args)
    ctx.add_entry("myapp", "src/main.vader")
    ctx.use(StructNames {})
    return ctx.emit_native()    // 1 when a struct breaks the rule
}
```

- A plugin reports and generates as a driver does.
- A library can ship a plugin: `ctx.use(JsonDerive { .modules = ["app"] })`, from `json/derive`, gives each struct of `app` a `to_json`.
- Plugins are read when the stream starts, like the rest of the configuration.
- In `.Describe` mode the stream builds nothing, and the plugins hear nothing.
- Starting a build from inside a plugin is an error.

#### Generating code

```vader
// file: build.vader, in `build`, with AST :: import "toolchain/ast"
for msg in ctx.messages() {
    if msg is TypecheckedMessage && msg.module_name == "app" {
        for d in msg.declarations {
            if d is AST.StructDecl {          // once per build, however many rounds run
                text :: "describe :: fn(v: ${d.name}) -> string = \"a ${d.name}\""
                ctx.emit_module("app", text)  // joins `app`
            }
        }
    }
}

// what it writes for Point:
describe :: fn(v: Point) -> string = "a Point"

// file: src/main.vader, with Point of §4 *Structs*
main :: fn() -> i32 {
    println(describe(Point { .x = 1, .y = 2 }))   // a Point
    return 0
}
```

- `ctx.emit_module(name, source)` writes `source` as an ordinary `.vader` file of the project (`docs/TOOLING.md` *Search roots*), compiled like a hand-written module: it has real spans, can be read and formatted, and every command finds it.
- `name` is a new module that the project imports, or an existing one, which the file joins (*Generated modules*, above).
- The program is then checked again and the generated declarations come back through the stream, so generation can be transitive; each declaration is still delivered once per build.
- Generation stops at a fixed point, a round that writes nothing new. A driver whose output never settles is an error.
- A generated module that no round writes is an error: one emitted after the last `Phase.BeforeEmit`, or before the driver leaves the loop there.
- A failure of the driver contract is a build-driver diagnostic (`docs/TOOLING.md` *Diagnostics*). A driver reports the violations of its own rules through `ctx.report`.

---

## 12. Decorators

Decorators are compiler instructions prefixed with `@`. They act at compile time, never at run time. Placing `@target`, `@singleton`, `@returns`, `@ensures`, a `@c_*` decorator, `@displayable` or `@assert` where it does not apply is an error.

| Decorator | Target | Purpose |
|-----------|--------|---------|
| `@comptime` | fn / value | Evaluates at compile time (§14) |
| `@extern`, `@extern("symbol")`, `@extern(LIBRARY, "symbol")` | fn without body | Declares a foreign function (§13) |
| `@c_pointer` | parameter of an `@extern` fn | Passes the parameter's address (§13) |
| `@c_out` | parameter of an `@extern` fn | C writes through the parameter (§13) |
| `@c_type("size_t")` | parameter or result of an `@extern` fn | The C spelling of an integer type (§13) |
| `@c_header("<header.h>")` | `@extern` fn | Takes the prototype from a C header (§13) |
| `@c_struct`, `@c_struct("struct name")` | struct | Mirrors a C struct (§13), named by an optional C type name |
| `@c_variadic(N)` | `@extern` fn | The C function is variadic after `N` fixed parameters (§13) |
| `@intrinsic` | fn or impl without body | The host runtime provides the body (*`@intrinsic`*, below) |
| `@export`, `@export("name")` | fn | Exposes the function under an unmangled name (§13) |
| `@test` | fn | Marks a test, run by `vader test` (`docs/TOOLING.md` *Tests*) |
| `@deprecated("reason")` | any declaration | Warns at every use; the code still compiles |
| `@assert(cond)`, `@assert(cond, "message")` | top level | Fails the build unless `cond` is true at compile time |
| `@partial` | `match` | Lifts the exhaustiveness check (below) |
| `@unreachable` | `match` | Lifts the exhaustiveness check and traps on the missing cases (below) |
| `@no_return` | fn | The function never returns (below) |
| `@internal` | struct field | The field is visible only in its module (below) |
| `@target`, `@target(.Os, ...)` | top-level fn | Selects the body for the target OS (§17 *Target selection*) |
| `@displayable` | enum | Generates `Display`: each variant renders as its name (§4 *Enums*) |
| `@singleton` | top-level fn without parameters | Runs the body once and returns the same instance to every call (below) |
| `@returns(cond)` | top-level fn returning `bool` | The function returns the value of `cond` (§3 *Declared guards*) |
| `@ensures(cond)` | top-level fn | `cond` holds when the function returns (§3 *Declared postconditions*) |
| `@allow_unused` | any top-level declaration | Exempts the declaration from the dead-code warning (below) |

### `@intrinsic`

`@intrinsic` and `@extern` both mark a function whose body is not written in Vader. `@extern` is for user code that calls a foreign library. `@intrinsic` is for the standard library, whose body the host runtime provides (`collect`, the members of `string implements Hash`).

A free function without a body must carry one of the two. A named function type is therefore written inline where it is used, never as a bodiless declaration. A build fails if an intrinsic has no host implementation.

`@intrinsic` applies to a function or to a whole impl:

```vader
// Standalone fn: a free-function host import (I/O, GC, builders...).
@intrinsic
export collect :: fn() -> void

// Trait impl: every method of the impl is provided by the host.
@intrinsic
string implements Hash
```

### `@assert`

The condition must evaluate to `true` at compile time; otherwise the build fails. The optional message must be a string literal without interpolation, and is added to the error.

### `@partial` and `@unreachable`

Both lift the exhaustiveness check on a `match`.

- `@partial` is for "everything else does X". Pair it with a `_` arm; the compiler then does not warn about that wildcard.
- `@unreachable` is for "the other cases cannot happen". The arms handle the possible cases explicitly, with no `_` arm, and a value that reaches no arm stops the program (`reached unreachable`).

The two cannot be combined.

### `@no_return`

The function never returns to its caller: it stops the program or loops forever. A call to it has type `never`, so it fits any slot (`_ -> todo("x")` where a value is expected), ends control flow, and satisfies a non-`void` function's obligation to return. `panic`, `todo` and `unreachable` in `std/abort` use it.

### `@internal`

Struct fields are public by default. `@internal` restricts one field to the module that declares the struct: another module cannot read it, write it, set it in a literal or bind it in a pattern.

Give an `@internal` field a default value, so that other modules can still build the struct with `T {}`. Without a default, only the declaring module can build it.

### `@singleton`

A module holds constants and functions, no variables. Its state lives in a `@singleton` function, which runs its body once per program and returns the same instance to every call:

```vader
@singleton
log :: fn() -> string[] = []

log().push("x")            // every later `log()` sees "x"
```

- The instance is ordinary heap state, not a frozen value: writes to it persist. One built from a module constant is a copy of it.
- A module constant cannot call a singleton: the constant would change with the instance. A lambda the constant holds may call one, since it runs only when called.
- A singleton takes no parameters, has no type parameters, and cannot use `yield`.
- An `async` singleton hands every call one task, the `share` (§16) of its body: concurrent and later awaits all get the same result, and the body runs once. A cancelled await leaves the task to the others, and a body that awaits its own task stops the program. The program must import `std/async`.
- A call that reaches the singleton again while its body is still running stops the program.
- A singleton cannot run at compile time: only the running program builds it.
- Only a free function can be a singleton.

### `@allow_unused`

`@allow_unused` exempts a private declaration from the dead-code warning. Use it for deliberate dead code: an API not wired yet, a helper kept for symmetry, a decoy in a test fixture. The declaration counts as reachable, and so does everything it uses.

---

## 13. FFI / External Functions

A program calls a C function by declaring it with `@extern`: a signature without a body, whose types say what crosses to C. Decorators on the declaration and its parameters say how a value crosses when its type does not. A native build calls the function as C does; `vader run` looks it up when the call runs (*VM behaviour*).

### `@extern`: declaring imports

```vader
import "std/ffi"

LIBM: CLibrary: CLibrary { .name = "m" }

@extern add_i32 :: fn(a: i32, b: i32) -> i32                    // C symbol: add_i32
@extern("puts") c_puts :: fn(s: string) -> i32                  // C symbol: puts
@extern(LIBM, "cbrt") cube_root :: fn(x: f64) -> f64            // C symbol: cbrt, from LIBM
```

`@extern` takes 0 to 2 arguments:

- without arguments, the symbol is the function's own name;
- the last argument, a string, is the symbol: the C linker symbol, or the `field` of a WASM import on the planned WASM target (*Future WASM target*);
- the first of two is the library, a `CLibrary` constant (below). Without one, the symbol is one the program links anyway, such as a C library function.

The following are errors:

- a body;
- more than two arguments;
- a symbol that is not a plain string literal, an interpolated string included;
- a library that is not a constant of type `CLibrary`;
- two `@extern` declarations of one C symbol, even in two modules, unless both take their prototype from a header (*`@c_header`*).

#### `CLibrary`: the library a binding calls

```vader
import "std/ffi"
import "std/target"

export RAYLIB: CLibrary: CLibrary {
    .name     = "raylib",
    .header   = "raylib.h",
    .include  = "include",
    .archives = ["lib/${VADER_OS}-${VADER_ARCH}/libraylib.a"],
    .system   = match VADER_OS {
        .Darwin          -> ["Cocoa.framework", "IOKit.framework", "OpenGL.framework"]
        .Linux           -> ["GL", "m", "pthread", "dl", "rt", "X11"]
        .Windows         -> ["opengl32", "gdi32", "winmm"]
        .Wasi | .Browser -> []
    },
}

@extern(RAYLIB, "InitWindow")
export init_window :: fn(width: i32, height: i32, title: string) -> void
```

A `CLibrary` (`std/ffi`) names a C library once; each `@extern` from it names the constant. The compiler evaluates the constant at compile time for the build target, without `@comptime`, so its fields may depend on `VADER_OS` and `VADER_ARCH`. It may use:

- literals, struct literals and enum variants;
- a `match` with variant and `_` arms;
- constants and single-expression functions, from any module;
- the interpolation of an enum whose `Display` impl is one expression over `self`.

Anything else is an error, reported where the evaluation stopped. The fields:

- `name`: the library `vader run` opens (`lib<name>.dylib` on macOS, `lib<name>.so` on Linux, `<name>.dll` on Windows), unless `archives` is set, whose functions go through adapters (*VM behaviour*). A native build links only `archives` and `system`.
- `header`: the header declaring the library's functions, written as the argument of `@c_header`. It serves each `@extern` of the library without a `@c_header` of its own.
- `include`: a header folder searched by every compilation, relative to the declaring module. A quoted header (`"raylib.h"`) is found there.
- `archives`: static archives shipped with the binding, relative to the declaring module. A missing one stops the build before the C compiler runs, naming the path.
- `system`: platform libraries by name (`"GL"` links `-lGL`) and Apple frameworks by bundle name (`"Cocoa.framework"` links `-framework Cocoa`).

A native build adds a library's flags only when the program reaches one of its functions, and compiles each library's calls with its own header alone, so headers declaring the same names (`Rectangle` in `raylib.h` and `<windows.h>`) bind in one program.

### `@c_pointer`: a parameter crossing as an address

A C function often takes a pointer where the value would do (`localtime(const time_t *)`). `@c_pointer` on the parameter passes C the address of a copy of the argument, valid for the call; no pointer type appears in Vader.

```vader
TimeT :: i64

@extern("localtime")
localtime :: fn(@c_pointer t: TimeT) -> CPointer
```

`@c_pointer` applies to a scalar (a number, `bool`, `char`, `CPointer`, or a distinct type over one), which crosses read-only as a `const T*` (*`@c_out`*), or to a `@c_struct` mirror (below).

The following are errors:

- any other decorator on a parameter;
- `@c_pointer` or `@c_out` on a parameter of a function that is not `@extern`;
- an argument to `@c_pointer` or `@c_out`;
- `@c_pointer` on any other type, a `string` or an array included, which already cross as pointers.

### `@c_out`: C writes through the parameter

```vader
@extern("read")
sys_read :: fn(fd: i32, @c_out buf: u8[], count: i64) -> i64
```

Without `@c_out`, C only reads what it is lent: an array crosses as a `const void*`, and a mirror lent with `@c_pointer` is not read back. With it, an array crosses as a `void*` whose elements C writes in place, and a mirror is copied back after the call.

`@c_out` needs storage that outlives the call, an array or a mirror lent with `@c_pointer`: on a scalar, a `string` or a mirror passed by value, it is an error. To read a scalar back on both backends, lend a one-element array (`@c_out written: u32[]`), the shape of every `T*` out-parameter (`WriteFile`'s `lpNumberOfBytesWritten`).

Passing a frozen value (§5 *Frozen values*) to a `@c_out` parameter is an error, as to any parameter its callee modifies.

### `@c_header`: letting the header own the prototype

Without a header, the compiler declares the C function from its Vader signature, which fails the build when the C compiler already sees a prototype (`clock_gettime` in `<time.h>`). `@c_header` includes the header instead, and the compiler declares nothing:

```vader
@c_header("<time.h>")
@extern("clock_gettime")
sys_clock_gettime :: fn(clock_id: i32, @c_out ts: i64[]) -> i32
```

The C compiler then checks every argument against the real declaration. Without a header nothing does: `isatty` declared as `fn(fd: i64) -> i64` compiles, links, and passes its argument wrongly.

The argument is written as in a C `#include`:

- `"<time.h>"` is a system header;
- `"\"my_header.h\""`, or a name without delimiters (`"raylib.h"`), is a local header, searched in the directory of the entry file wherever `--out` writes the C: `"\"include/my.h\""` is one folder below the entry.

### `@c_variadic`: a variadic C function

A variadic C function (`fcntl`, `ioctl`) is declared once per argument list the program calls it with, each declaration taking its prototype from a header (`@c_header` or its library's `header`) to share one symbol (*`@extern`*). `@c_variadic(N)` gives the number of fixed parameters, those before the `...` of the C prototype:

```vader
@c_header("<fcntl.h>")
@c_variadic(2)
@extern("fcntl")
set_flags :: fn(fd: i32, command: i32, flags: i32) -> i32
```

A native build reads the prototype from the header, `vader run` reads `N`: without it, `vader run` calls the function as a fixed one, and on some systems (darwin-arm64) the function then reads its variadic arguments from the wrong place.

### `@c_type`: the C spelling of an integer

Without a header, the compiler spells a number by its Vader type (a `u64` is a `uint64_t`), which conflicts with a header that uses another name for the same width (`size_t`, `off_t`, `DWORD`). `@c_type` names the C type:

```vader
@c_type("size_t")
@extern("strnlen")
c_strnlen :: fn(s: string, @c_type("size_t") max: u64) -> u64
```

On a parameter, `@c_type` spells that parameter; on the declaration, the result. The value is converted to the C type and back, and the C type must be an integer exactly as wide as the Vader one, or a native build fails. With `@c_header`, the header gives the prototype and `@c_type` only adds the conversions.

The following are errors:

- `@c_type` without exactly one argument, a plain string;
- `@c_type` on a parameter or a result that is not an integer, or a distinct type over one;
- `@c_type` outside an `@extern` declaration.

### `@c_struct`: mirroring a C struct

A struct marked `@c_struct` mirrors a C struct, and can cross an `@extern` call as a parameter or as the result.

```vader
@c_struct("div_t")
Div :: struct { quot: i32, rem: i32 }

@extern fill_div :: fn(@c_pointer @c_out d: Div, quot: i32, rem: i32) -> void

@c_header("<stdlib.h>")
@extern("div") c_div :: fn(numerator: i32, denominator: i32) -> Div
```

`@c_struct` takes at most one argument, a plain string naming the C type (`"struct pollfd"`, `"div_t"`); without it, the C type is the struct's own name, read as a `typedef` name.

Each field is copied to and from the C member of the same name, which the C compiler places from the real header:

- by address, for a parameter with `@c_pointer`, C receives a C struct filled from the mirror, copied back after the call with `@c_out`;
- by value otherwise, C receives a copy passed as the platform's ABI wants, and a result is copied into a new Vader struct, nested mirrors included.

A mirrored field is a number, `bool`, `char`, `CPointer`, an enum with a written width and no variant data, or another `@c_struct`. Any other field type, a plain struct included, is an error when the mirror crosses an `@extern`.

A mirror is a contiguous leading prefix of the C struct: its members in order, from the first, none skipped. Lent by address, it may stop early, and the rest is ignored. Crossing by value, it names every member; the check misses only a member small enough to hide in the struct's tail padding.

A native build checks each mirror against the header, and fails when:

- a field names no member of the C struct;
- a field's width or signedness differs from its member's (*A mirrored field's width*);
- a field is not at its member's offset, as when a member is skipped;
- a mirror lent by address is larger than the C struct, or one crossing by value is not exactly its size.

Under `vader run` alone, nothing reports a mirror breaking these rules, which can hand C its fields at the wrong offsets.

A member that is itself a struct takes a nested mirror, a field whose type is another `@c_struct`: C holds it inline, Vader as a struct of its own, and each leaf is copied by its path (`.srWindow.Right`). A mirror nests at most 16 levels deep.

```vader
@c_struct("SMALL_RECT")
SmallRect :: struct { Left: i16, Top: i16, Right: i16, Bottom: i16 }

// Whole, not `{ srWindow: SmallRect }`: `srWindow` is the fourth member, and a
// mirror that skipped the three before it would fail the offset check.
@c_struct("CONSOLE_SCREEN_BUFFER_INFO")
ScreenBufferInfo :: struct {
    dwSize:              Coord
    dwCursorPosition:    Coord
    wAttributes:         u16
    srWindow:            SmallRect
    dwMaximumWindowSize: Coord
}
```

A C struct whose member order or offsets differ between systems (`struct stat`) cannot be mirrored; `docs/adr/0013-what-the-ffi-boundary-cannot-express.md` gives what to use instead.

### A mirrored field's width

A field's width is that of its Vader type, and must match its C member's exactly, signedness included, whichever way the copy runs. A type whose width differs between systems (`suseconds_t`: 4 bytes on Darwin, 8 on Linux) takes one mirror and one `@extern` per system, chosen with `@target` at the call (§17 *Target selection*), not the wider of the two.

### The opaque buffer, when there is no mirror to write

A C struct whose members Vader never reads can cross as a lent `u8[]` that nothing interprets, the same array handed back each time: `termios` in `lib/system/posix` (`tcgetattr` fills it, `tcsetattr` applies it).

Nothing checks the buffer: the callee writes `sizeof(struct ...)` bytes whatever the reserved size, so that size must cover the largest system in scope, or the write goes out of bounds unreported. Use it only when no mirror can exist: no member Vader needs to name, or no stable public layout.

### Allowed signature types

These scalars cross as their C counterparts (`void` as a result only, `null` never):

```
i8 i16 i32 i64    u8 u16 u32 u64
f32 f64    bool   char    void    string
```

The shapes below cross too, only in the direction given. Any other type in an `@extern` signature (a plain struct, a trait, a type parameter) is an error.

| Shape | Crosses as | Direction |
|---|---|---|
| `CPointer` | An address C hands out | Both |
| A distinct type | Its backing type | Both |
| `CPointer \| null` | An address, with `null` as `NULL` | Both |
| `string \| null` | A C string, with `null` as `NULL` | Result only |
| An array of scalars other than `string` | A pointer to its first element | Argument only |
| A `@c_struct` mirror | A C struct, by address or by value | Both |
| An enum with a written width | The integer value of its variant | Argument only |
| A function type | The address of a named function | Argument only |

A `string` argument reaches C as a NUL-terminated UTF-8 `const char*`, valid for the call only: nothing reports a callee that keeps it. A `string` result is copied before the arguments are released, so one pointing into an argument (`strstr`) reads correctly. Vader never frees the pointer C returns, which is right for one the library owns (`getenv`) and a leak for one the caller should free. A `NULL` `string` result is `""`, or `null` for a `string | null` result, telling "absent" from "empty" (`getenv`).

`CPointer` (§4 *Primitive types*) is an address C hands out: a program receives it, passes it back and compares it, but cannot read through it or build one. `Handle :: CPointer`, a distinct type, names a kind of handle. `CPointer | null` narrows on `NULL` alone: a sentinel that is not `NULL` (`INVALID_HANDLE_VALUE`, `MAP_FAILED`, both `-1`) is tested through `i64(p)` or `u64(p)`, which hold an address on every target. Converting a `CPointer` to a narrower integer or a float, or an integer to a `CPointer`, is an error.

An array crosses as a pointer to its first element; a length the callee wants is a parameter of its own.

An enum with a written width (§4 *Representation*) crosses as its variant's integer at that width; an enum with variant data crosses as the value written after its `=` (§4 *Variant data*). The following are errors:

- an enum whose width is inferred;
- an `@extern` that takes both an enum with variant data and a callback.

### Callbacks

A parameter of function type is a C callback: C receives the function's address and calls it with its signature's types.

```vader
double_it :: fn(x: i32) -> i32 = x * 2

@extern call_twice :: fn(f: fn(i32) -> i32) -> i32

call_twice(double_it)                 // ok
call_twice((x: i32) -> x * 2)         // error: a lambda is not a named function
```

- The argument names a function of a module, directly or through a namespace alias (`M.double_it`). A lambda, a closure, or a local or parameter holding a function is an error, whatever its type.
- A callback runs only in a native build: under `vader run`, a call that passes one stops the program.
- A callback's signature holds only numbers, `bool`, `char`, `CPointer`, distinct types over those, and a `void` result; any other type, `string` and arrays included, is an error. `qsort`'s comparator `int (*)(const void *, const void *)` is `fn(CPointer, CPointer) -> i32`.

### Native target: code generation

A native build calls each `@extern` as a C function linked into the binary (*Linking*). The compiler writes every conversion the call needs, and the prototype when no header gives it (*`@c_header`*), so a program never writes C glue.

### Linking

A native build links what the program's `CLibrary` constants declare. Anything else, an object file or a library no `CLibrary` declares, goes to the linker on the command line (`docs/TOOLING.md` *`vader build`*).

### VM behaviour

```vader
// with c_puts and cube_root of *`@extern`*
NOPE: CLibrary: CLibrary { .name = "nosuchlib" }

@extern(NOPE, "f") f :: fn() -> i32
@extern("no_such_fn") missing :: fn() -> i32

c_puts("hi")       // prints hi: puts, from the running process
cube_root(27.0)    // 3.0: cbrt, from libm, opened at the call
f()                // stops the program, naming `f` and the library
missing()          // stops the program, naming the symbol
```

`vader run` looks an `@extern` up when the call runs, in the library its `CLibrary`'s `name` gives, or without one in the running process (on Windows, the C runtime); nothing has to be registered. The program stops, naming the `@extern` and the reason, when the library does not open, the symbol is missing, or an array argument's elements are not integers.

At compile time (§14), a call that needs an adapter (`docs/TOOLING.md` *`vader run`*) fails, naming the reason.

### Future WASM target

A WASM target is planned (§17 *Compilation Targets*). There, `@extern` will also give a WASM import, a `(module, field)` pair whose module is `"env"` without a library: `@extern("console_log") log` becomes `(import "env" "console_log" (func ...))`. How to name another module is not designed yet.

### `@export`: exposing a function

`@export` is planned: it exposes a function to the host under an unmangled name, its own or the argument. Accepted today, it keeps the function in the program but does not change its name yet. On the WASM target, the host is JavaScript:

```vader
@export("addNumbers")
add_numbers :: fn(a: i32, b: i32) -> i32 {
    return a + b
}
```

JS side:

```javascript
const { instance } = await WebAssembly.instantiateStreaming(fetch("app.wasm"));
console.log(instance.exports.addNumbers(2, 3));
```

---

## 14. Compile-time Execution

### `@comptime`

`@comptime` computes a value at compile time:

```vader
build_lookup_table :: fn() -> u32[] {
    result: u32[]: []
    for i in 0..<256 {
        result.push(u32(i * i))
    }
    return result
}

@comptime
TABLE :: build_lookup_table()
```

The call runs during compilation, and `TABLE` is a constant computed once. The value is a scalar, a string, an array, a struct or a tuple, nested at will; a function value, a map, a set, or a value depending on itself (directly or through other constants) is an error.

In its inline form, `@comptime` prefixes the right-hand side of a constant:

```vader
TABLE :: @comptime {
    result: u32[]: []
    for i in 0..<256 {
        result.push(u32(i * i))
    }
    return result
}

// typed form: built at compile time
SQUARES: u32[]: @comptime { ... }
```

A block runs as a function body, where `return` or a trailing expression gives the value. The typed form `NAME: T: @comptime <expr>` gives the value the type `T`.

In its decorator form, `@comptime` above `NAME :: <expr>` computes what `NAME :: @comptime <expr>` does, unless `<expr>` has the shape of a type (a name, `Mod.T`, `Box<T>`, `T[]`, `A | B`, `[A, B]`, a function type, `Int in 0..=23`). Such an `<expr>` runs no function body:

- naming a type, the declaration is a type alias (§4 *Distinct types*);
- naming a value, such as a constant, it is folded and cannot read a constant computed by running code (a loop, a statement body), which the inline form can.

### Sandbox

A `@comptime` value can:

- compute, allocate and build data structures;
- print with `println`. The output is not part of the value.
- read the clock, the environment and the filesystem. The build is then no longer reproducible.
- read a file relative to its own source. A `@comptime` value runs with the directory of the file that declares it as working directory: `read_file_bytes("sprite.png", ...)` reads the file next to that source, and `current_working_directory()` returns that directory.

In a cross build, a `@comptime` value runs the `@target` bodies of the build machine, while `VADER_OS` and `VADER_ARCH` keep the target's values.

A `@comptime` value cannot:

- ask which machine the compiler runs on (`current_os`, `current_arch`, the dynamic FFI: `ffi_open`, `ffi_symbol`, `ffi_call`), or drive the async scheduler, which only runs with the program: both are rejected;
- call a `@singleton` function, or anything that reaches one, such as spawning a process.

### Reflection / comptime intrinsics

A **reflection intrinsic** `@name(args)` is an expression answered from the types of the program, a constant once its type arguments are known, except `@field`.

An argument `T: type` is a type, a value of the metatype `type` (§4), fixed at the call site; only `@size_of` also accepts one known at run time, such as a parameter `t: type`. A wrong argument count or unknown name is an error.

| Signature | Result |
|-----------|--------|
| `@size_of(T: type) -> i64`, `@align_of(T: type) -> i64` | Width and alignment in bytes of a slot holding a `T`. |
| `@type_name(T: type) -> string` | Name of `T` as diagnostics print it: `"i32 \| string"`. |
| `@type_kind(T: type) -> string` | Shape of `T`. |
| `@min(T: type) -> T`, `@max(T: type) -> T` | Least and greatest value of `T`. |
| `@field_count(T: type) -> i64` | Number of fields of a struct or elements of a tuple, else 0. |
| `@variant_count(T: type) -> i64` | Number of variants of a union (nested unions flattened) or an enum, else 0. |
| `@field_index(T: type, name: string) -> i64` | Position of a field in the struct `T`. |
| `@satisfies(T: type, Trait: type) -> bool` | Whether `T` implements `Trait`. |
| `@type_of(x) -> type` | Static type of `x`, unevaluated. |
| `@fields(T: type) -> Field[]` | Fields of the struct `T`. |
| `@type_args(T: type) -> type[]` | Type arguments of a generic struct or trait instance, else `[]`. |
| `@field(x, name: string) -> <field type>` | Field `name` of `x`. |

`@assert` checks them at build time:

```vader
@assert(@size_of(MyHotStruct) <= 64,
        "MyHotStruct must fit in a cache line")
@assert(@type_kind(KeyType) == "primitive" || @type_kind(KeyType) == "struct",
        "KeyType is not hashable")
```

#### `@size_of` and `@align_of`

`@size_of(T)` measures the slot (a field, a local, a parameter), not the object a reference points at:

- 1 for `i8`, `u8`, `bool`; 2 for `i16`, `u16`; 4 for `i32`, `u32`, `f32`, `char`, `string`; 8 for `i64`, `u64`, `f64`;
- for an enum, an integer range type or a distinct type, the size of its representation (§4 *Representation*, *Range types*, *Distinct types*);
- 8 for the references: a struct, an array, a tuple, a function value;
- 16 for a union, a trait value and `any` (a value and its type);
- 0 for `null`, `void`, `type` and any type without a value at run time.

`@align_of(T)` is a scalar's width, 8 for a 16-byte slot.

#### `@type_kind`

`@type_kind(T)` is one of `"primitive"`, `"struct"`, `"enum"`, `"union"`, `"array"`, `"tuple"`, `"fn"`, `"trait"`, `"type"`, `"any"` and `"unknown"`, a fixed set compared as a whole. A range type is `"primitive"`, and a distinct type has the kind of its backing type (§4 *Distinct types*).

#### `@min` and `@max`

`@min(T)` and `@max(T)` are constants of `T`, for an integer type, a range, `char`, a type parameter bounded by `Int` (§4 *Range types*) or an enum without variant data (§4 *Values*); any other `T` is an error.

#### `@satisfies`

`@satisfies(T, Trait)` is true when `T` implements `Trait` by an impl the calling module sees or a built-in one (an enum's `Equals` and `Hash`), the same under `@assert` and in a function body.

- A generic impl counts only for the arguments its bounds admit: under `Box<T> implements<T: Display> Display`, `Box<Point>` satisfies `Display` only when `Point` does.
- Arguments written on `Trait` are compared, its defaults filled in: `Money implements Add<Money, Money>` satisfies `Add<Money, Money>`, not `Add<i32, i32>`.
- A `Trait` that is not a trait gives false.

#### Fields: `@fields`, `@field_index` and `@field`

`@fields` and `@field_index` take a struct; a `T` known to be another type is an error.

- `@fields(T)` gives a `Field[]` (`std/core`), each with a `name: string` and a `type: type`.
- `@field_index(T, "name")` counts from 0, and `name` is a string literal naming a field of `T`.
- `@field(x, "name")` reads `x.name`, under the same type, `@internal` and narrowing rules; `name` is a string literal, or `f.name` in `@comptime for f in @fields(T)`.

### `@comptime for` over reflected fields

`@comptime for x in e { ... }` copies its body at compile time once per element of `e`, with `x` bound to it. `e` is an array known at compile time, of at most 256 elements, such as an array literal, `@fields(T)` or `@type_args(T)`.

In `@comptime for f in @fields(T)`, `f.name` and `f.type` are constants in each copy, and `@field(x, f.name)` is a plain field access.

```vader
Pair :: struct<K, V> {
    key:   K
    value: V
}

print_sizes :: fn() -> void {
    @comptime for f in @fields(Pair<u8, i64>) {
        println("${f.name}: ${@size_of(f.type)}")    // "key: 1", then "value: 8"
    }
}
```

- `continue` goes on with the next copy, `break` leaves every copy, and a copy's defers run when it is left.
- A destructuring binding (`[k, v]`) is an error.

---

## 15. Core Library

The library ships under the toolchain's library root (§11 *Library root*): the modules of `std/`, and libraries with namespaces of their own (`json`, `cli`, `regex`, ...). Every exported declaration carries its documentation (§3 *VaderDoc*), and that documentation is the reference for the library.

This chapter covers the part of the library the language relies on: the prelude and the traits that syntax forms call, generators, and the functions that stop the program.

### `std/core`

```vader
// with Point and its Display of §9; no import: every trait used here comes from std/core
p :: Point { .x = 1, .y = 2 }
"at ${p}"                        // "at (1, 2)": interpolation calls to_string
"vader" + "lang"                 // "vaderlang": string implements Add
7 in 1..=10                      // true: a Range<i32>, through Contains<i32>
```

`std/core` is the prelude: its exports are in scope in every module, with no import (§11 *Prelude*). It declares the eight integer types (§4 *Primitive types*) and the traits that syntax forms call:

| Form | Trait or type | Specified in |
|------|---------------|--------------|
| `a + b`, `a - b`, `a * b`, `a / b`, `a % b` | `Add`, `Sub`, `Mul`, `Div`, `Rem` | §4 *Operator overloading* |
| `a == b`, `a != b` | `Equals` | §4 *Equality* |
| `a < b`, `a <= b`, `a > b`, `a >= b` | `Comparable` | §4 *Operator overloading* |
| `a[i]`, `a[i] = v` | `Index<I, T>`, `IndexSet<I, T>` | §4 *Operator overloading* |
| `x in c`, `x !in c` | `Contains<T>` | §3 *Membership: `in`* |
| `lo..<hi`, `lo..=hi` | `Range<T>` | *Ranges*, below |
| `for x in e` | `Iterator<T>`, `Stop`, `Into<Iterator<T>>` | §7 *`for` (universal loop)* |
| `"${x}"` | `Display` | §9 *`Display` trait* |
| a conversion, implicit or `T(x)` | `Into<Target>` | §4 *Type coercion via `Into`* |
| `T \| Error` | `Error` | §10 *`Error` trait* |
| `await e` | `Async<T>`, `Suspended` | §16 *async/await* |
| `@fields(T)` | `Field` | §14 *Reflection / comptime intrinsics* |

It also declares:

- `Hash`, a hash code: `hash :: fn(self) -> u64`, the same for two values equal by `Equals`. Every enum implements it (§4 *Enums*); `MutableMap` and `MutableSet` key on it.
- `Step`, the next value of a discrete type: `step :: fn(self) -> Self`.
- `Clone`, an explicit copy: `clone :: fn(self) -> Self`.
- `Zero` and `One`, the additive and multiplicative identities, two static members (§4 *Static members*).
- `FloatBits`, `BitsFloat`, `Float32Bits` and `Bits32Float`, the bits of a float (§4 *Float bit patterns*).
- `ArrayOps<T>`, the built-in methods of arrays: `len`, `push`, `push_all`, `copy_to`, `remove_last` and `clear` (§4 *Mutation methods*).
- `Stop`, what an iterator returns at its end (*Iteration*, below).
- Functions on arrays: `filled` and `filled_indexed` (§4 *Repeat / preallocate: `[lhs] * n`*), `content_equals`, `is_permutation_of`, `contains_all` and `is_disjoint` (§4 *Equality*).
- Functions on strings: `len`, `byte_len`, `byte_at`, `byte_slice`, `is_ascii`, `codepoint_at_byte`, `bytes` and `bytes_to_string` (§4 *Strings*).

#### Implementations on primitive types

```vader
[1, 2] + [3]                     // [1, 2, 3]: a new array
2 in [1, 2, 3]                   // true: T[] implements Contains<T>
'x'.step()                       // 'y'
(42).hash()                      // called like any other impl
i32.zero()                       // 0: a static member

remainder :: fn<T: Rem>(a: T, b: T) -> T = a % b
remainder(7, 2)                  // error: i32 does not implement Rem
"ell" in "hello"                 // error without import "std/string"
```

| Trait | Implemented by |
|-------|----------------|
| `Display` | Every primitive, and `null` (§9 *`Display` trait*). |
| `Equals` | Every primitive: the integers, the floats, `bool`, `char` and `string`. |
| `Hash`, `Comparable` | The integers, `char` and `string`. |
| `Step` | The integers and `char`. |
| `Add`, `Sub`, `Mul`, `Div` | Every numeric primitive. |
| `Add` | Also `string` and `T[]`, for concatenation. |
| `Zero`, `One` | Every numeric primitive. |
| `FloatBits`, `Float32Bits` | `f64` and `f32`. |
| `BitsFloat`, `Bits32Float` | `u64` and `u32`. |
| `Index` | `string`, at an `i64` and at a `Range<i64>` (§4 *Strings*). |
| `Contains<T>` | `Range<T>`, and `T[]` when `T: Equals`. |
| `Mul<i64>` | `T[]`, for `[x] * n`. |
| `Into<Iterator<T>>` | `T[]`. |
| `Into<string>` | Every type that implements `Display`. |

- No primitive implements `Rem`: `%` on numbers is built in.
- `a + b` on two strings or two arrays is a new value, `a`'s elements then `b`'s; neither operand changes.
- Two equal strings have the same hash on every backend. The hash value is not otherwise specified.
- A primitive's impl is also reached through a bound `T: Hash` (§4 *Method dispatch on trait values*).
- The substring test `sub in s` comes from `string implements Contains<string>`, in `std/string`, not in the prelude.

#### Ranges

`lo..<hi` and `lo..=hi` build a `Range<T>` from `lo` up to `hi`, `hi` excluded or included. Over an integer type or `char`, a range is an `Iterator<T>` and a `Contains<T>`, through the `Step` and `Comparable` impls of `T`. A `char` range skips the surrogates. `s in "a"..="m"` is an error, since `string` has no `Step`.

```vader
Contains :: trait<T> {
    contains :: fn(self, value: T) -> bool
}
```

### Iteration

```vader
Stop :: struct {}

Iterator :: trait<T> {
    next :: fn(self) -> T | Stop
}
```

`next` returns the next element, or `Stop {}` once there is none. Only `Stop` ends the iteration, so an iterator over a nullable type yields `null` as an ordinary element.

- An element type that can hold `Stop` (`Iterator<Stop>`, `Iterator<A | Stop>`) is an error: `next` could no longer say the iteration is over. In a generic function, the error is at the use that gives the type parameter such a type.
- `next` changes the state of the iterator. Advancing a frozen iterator, such as a module constant, is an error (§5 *Frozen values*).
- An implementation provides `next` and nothing else. What consumes an iterator (`count`, `last`, `collect`, ...) is a free function over `Iterator<T>`, called with the method syntax: `it.count()`. `std/iter` provides the lazy combinators (`map`, `filter`, `take`, ...) and the terminals (`collect`, `fold`, `sum`, ...).
- There is no `Iterable` trait. A type that can be iterated implements `Into<Iterator<T>>` (§7 *`for` (universal loop)*).

`T[]` implements `Into<Iterator<T>>`, so an array goes wherever an `Iterator<T>` is expected, as the receiver of a function over `Iterator<T>` too (§6 *UFCS (Uniform Function Call Syntax)*). Each conversion gives a fresh iterator, and an impl on the array's own type, such as `i32[] implements Into<Iterator<i32>>`, comes before the generic one (§4 *Specialization: the instance wins*). `arr.map(f)` returns an `Iterator<U>`, not an array; `.collect()` builds the array:

```vader
arr.map(f).filter(p).take(10).collect()     // arr : T[] ; `arr.map(f)` is lazy, `.collect()` yields the T[]
for x in arr.filter(p) { ... }              // a lazy chain also drives for-in directly
```

### Generators

A **generator** is a function whose body contains a `yield`. It returns an `Iterator<T>` and produces its elements one at a time, as they are asked for. No decorator marks it: the `yield` does.

```vader
concat_file_decls :: fn(files: SourceFile[]) -> Iterator<Decl> {
    for f in files {
        for d in f.program.decls { yield d }     // flatten = a nested `for`
    }
}

// consumed lazily: no intermediate array is built
for d in concat_file_decls(files) { process(d) }
```

- The declared return type must be `Iterator<T>`, `T` being the type of the yielded elements. A function that yields and returns another type is an error.
- A function that returns `Iterator<T>` without a `yield` is an ordinary function that returns an iterator: an array, `arr.into()`, the result of a combinator. An empty array `[]` is an empty iterator.
- `yield e` is a statement, allowed directly in the generator's own body. A `yield` in a nested lambda or in a `defer` body is an error. `e` must be assignable to `T`, as a `return` value must be to the return type.
- `return v` in a generator is an error. A bare `return`, or the end of the body, ends the iteration: every later `next()` returns `Stop`.
- `break` and `continue` keep their meaning across a `yield`.
- `defer` in a generator is an error.
- A generator's result is an ordinary `Iterator<T>` value: it can be stored, passed, returned and given to any combinator.

There is no `yield from` or `yield*`: a nested `for` flattens, as in the example.

### `std/abort`

`std/abort` holds the functions that stop the program: `panic(msg)`, `todo(msg)` and `unreachable(msg)`. All three are `@no_return` (§12 *`@no_return`*), and the pending `defer` bodies run before the program stops (§7 *`defer`*). `todo("lexer")` stops with the message `not yet implemented: lexer`, and `unreachable("lexer")` with `entered unreachable code: lexer`. The module is not part of the prelude: a program that calls them imports it.

---

## 16. Concurrency

A program runs on one thread, with cooperative concurrency through `await`. I/O in `std/io` blocks. A child process started with `spawn_async` (`std/process`) runs while the program awaits it.

### async/await

A function that uses `await` is an **async function**.

- It declares `-> Async<T>` (`Async<void>` for no value), and its body returns a `T`.
- A call to it gives an `Async<T>`, and `await e` waits for `e` to complete and gives its `T`.
- A function that returns an `Async<T>` it builds, without awaiting, is an ordinary function, as `sleep(ms) -> Async<null>` (`std/async`) is.

```vader
import "std/io"
import "std/async"

mk :: fn(n: i32) -> Async<i32> {
    await sleep(i64(n))
    return n * 10
}

main :: fn() -> i32 {
    rs :: await join_all([mk(3), mk(1), mk(2)])
    for r in rs {
        println("${r}")                  // 30, 10, 20: input order
    }
    return 0
}
```

`await` is an error in a nested lambda, a `defer` body and, for now, the right operand of `&&`, `||` or `??`, a loop condition or a `match` guard.

Operands evaluate left to right even when a later one awaits: in `f(a(), await b())`, `a()` runs first. An assignment evaluates its target's operands (receiver, index), then its value; a compound assignment `place op= e` reads `place` only at the write.

`defer` works in an async function: the function's pending defers, those registered before an `await` included, run in reverse order when the function completes or is cancelled.

#### Running async code

- `main` may `await` and keep its `i32` return type; the program runs it to completion.
- When every task is suspended, the program waits for the nearest deadline, and stops on a deadlock when none is pending. Without `std/async`, a `main` whose `await` suspends stops the program.
- `sleep(ms)` suspends the async function until its deadline: in real time in a native program, while under `vader run` the scheduler's clock jumps to it.
- `block_on(x)` (`std/async`) runs an awaitable to completion from a function that is not async.

#### Combinators

`std/async` combines awaitables:

- `join_all(xs)` gives every result, in input order.
- `try_join_all(xs)` is the fallible join, giving the first error in input order.
- `race(xs)` completes with the first awaitable to settle, value or error.
- `join_any(xs)` completes with the first success, or the last error when all fail.
- `timeout(ms, x)` gives a `TimeoutError` when the deadline passes before `x` completes.
- `share(x)` lets several awaiters await `x`: the first `resume` drives it, and once it completes every later one returns its result (a finished async function answers `Suspended`). Cancelling a shared awaitable leaves `x` to the others; `x` awaiting its own shared awaitable stops the program.

#### Cancellation

`race`, `join_any` and `timeout` cancel the awaitables that lose, and nothing else cancels; only a suspended async function can be cancelled. It runs its pending defers in reverse order and cancels the awaitable it waits on, without finishing its body. Structured concurrency (`scope`, `spawn`) is planned.

#### Hand-written awaitables

An awaitable is a value whose type implements `Async<T>` (`std/core`). Its `resume` returns the `T` once complete, or a `Suspended` while it cannot progress; one that holds resources overrides `cancel` to release them.

- `Suspended { .wake_at = t }`: no progress before the scheduler clock (`sched_now`, in milliseconds) reaches `t`. `Suspended {}` (`wake_at` 0): the time is unknown.
- An async function reports the `wake_at` of the awaitable it waits on.

`join_all`, `race` and `join_any` resume an awaitable only once its `wake_at` has passed.

### Later: coroutines

Continuation-passing coroutines are planned.

### Native threads

Native threads are planned in `std/thread`; importing it will be a compile-time error on the WebAssembly targets.

---

## 17. Compilation Targets

### Target selection: `@target`

A build is made for a **target**, an operating system and an architecture written `<os>-<arch>` (`--target=darwin-arm64`), by default the machine the compiler runs on.

- The OS selects code: `@target` chooses the body of a function by OS.
- The architecture selects no code (no `@target` on it), and sets values such as the pointer width.

`Os` has the variants `Windows`, `Linux`, `Darwin`, `Wasi` and `Browser`; `Arch` has `X86_64`, `Arm64` and `Wasm32`. WebAssembly is an architecture, on which two OSes run: `Wasi` has a POSIX-shaped filesystem, `Browser` has none.

#### One declaration, several bodies

```vader
// path.vader: the declaration. Carries the signature, the export, the doc.
import "std/string"

/// True iff the path is absolute.
@target
export is_absolute :: fn(p: string) -> bool = p.starts_with("/")

// path-windows.vader: a body. Same module; the file name means nothing.
@target(.Windows)
is_absolute :: fn(p: string) -> bool { /* drive letter, UNC */ }
```

A bare `@target` marks the **declaration** of a function, carrying its signature, visibility, doc and decorators, and optionally a general body. `@target(.Os, ...)` marks a **body** for the OSes it lists, in any file of the module. A body may come from the linker (`@target(.Windows) @extern("CreateFileW")`): the bare form makes a declaration, not the presence of `{ ... }`.

A build keeps one body per declaration, the one listing the target's OS or else the general body, and gives it the parameters, return type and type parameters of the declaration. Bodies not selected are neither resolved nor type-checked; `vader check --target=<os>-<arch>` checks another platform's from any machine.

#### Rules

```vader
// beside the `is_absolute` above, each line is an error
@target(.Drawin) is_absolute :: fn(p: string) -> bool = false         // error: not an OS
@target(Os.Linux) is_absolute :: fn(p: string) -> bool = false        // error: write `.Linux`
@target(.Linux) is_relative :: fn(p: string) -> bool = false          // error: no such declaration
@target(.Linux) export is_absolute :: fn(p: string) -> bool = false   // error: exported body
@target(.Windows) is_absolute :: fn(p: string) -> bool = false        // error: two Windows bodies
@target(.Linux, .Linux) is_absolute :: fn(p: string) -> bool = false  // error: Linux twice
@target is_absolute :: fn(p: i32) -> bool = false                     // error: declared twice
@target(.Linux) is_absolute :: fn(path: string) -> bool = false       // error: `path`, not `p`
@target LIMIT :: 3                                                    // error: not a function
```

Whatever the target being built, each line above is an error, and so are: a body carrying a decorator other than `@extern` and `@intrinsic`; a body with another number of parameters (a body binds them by position, and their types are not compared); `@target` on anything but a top-level free function (a constant that depends on the target uses `VADER_OS`).

A declaration with no general body and no body for the OS being built is an error too.

#### `VADER_OS`: the target as a value

`VADER_OS` and `VADER_ARCH` are prelude constants, known at compile time, holding the target's OS and architecture. Their types `Os` and `Arch` live in `std/target`: comparing with a bare variant needs no import (`VADER_OS == .Windows`), naming the type does (`Os.Windows`, a parameter typed `Os`).

```vader
SEP :: if VADER_OS == .Windows { '\\' } else { '/' }
```

`VADER_OS` says what the build is for, and `current_os()` (`std/target`) what the program runs on: they differ in a cross build, and wherever code runs on another machine than it was built for. Code that resolves a path, spawns a process or otherwise acts on its host uses `current_os()`.

#### Tests are never targeted

A test is never selected away: `@test` goes on the bare `@target` declaration, never on a body (*Rules*). A test whose expectation depends on the platform computes it from `VADER_OS`:

```vader
@test
test_separator_matches_the_platform :: fn() -> void {
    want :: if VADER_OS == .Windows { '\\' } else { '/' }
    assert_eq(SEP, want)
}
```

### Native (Linux, macOS, Windows)

A native build writes portable C, compiles it with the system C compiler (`docs/TOOLING.md` *`vader build`*) and links the Vader C runtime, which provides the garbage collector (§8). Direct assembly backends, one per target, may come later.

### WebAssembly

A WebAssembly backend is planned. The `wasi-wasm32` and `browser-wasm32` targets select `@target` bodies, which `vader check --target=wasi-wasm32` checks, but no build emits a module yet. A module will declare its imports and exports with `@extern` and `@export` (§13).

---

## Appendices

### A. Deferred decisions / topics to revisit

- An explicit allocator API (arenas, buffers) for performance-critical code.
- Automatic string marshalling between WebAssembly and JavaScript.
- Continuation-passing coroutines.
- Native threads (`std/thread`).
- Networking.
- External packages.
- WebAssembly without WASI.

### B. Glossary

- **UFCS**: Uniform Function Call Syntax. `a.f(b)` is the call `f(a, b)` (§6).
- **Comptime**: compile-time execution, Vader code run during the build (§14).
- **SAM**: Single Abstract Method. A trait with exactly one required method, whose impl may be written as its body alone (`Foo implements Trait -> expr`) instead of the full `name :: fn(...) { ... }` declaration.
- **VM**: the Vader virtual machine, which runs the bytecode for `vader run` and `vader test` (§2).
- **Bootstrap**: compiling the Vader compiler with itself ([`docs/BOOTSTRAP.md`](./docs/BOOTSTRAP.md)).
