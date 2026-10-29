# Modules

Every file opens with `module "name"`, and the files directly inside one folder form one module. An `import` brings in the names another module exports, in one of three forms.

## A module and its imports

The plain form, `import "path"`, makes every export of the module visible as if declared in the file. A name declared without `export` stays inside its module.

```vader
module "main"

import "std/io"
import "std/math"

export circle_area :: fn(radius: f64) -> f64 = pi * radius * radius

main :: fn() -> i32 {
    println("${circle_area(1.0) > 3.14}")
    return 0
}
```

```text
true
```

This plain form is the usual one; the next two show where a name comes from, or settle a name two imports share. The rules: §11 *Module declaration*, §11 *Granularity and location* and §11 *Imports*.

## Importing under a name

`name :: import "path"` binds the module to a name and nothing else: its members are reached through it, which says where each one comes from.

```vader
# module "main"
# import "std/io"
math :: import "std/math"

hypotenuse :: fn(a: f64, b: f64) -> f64 = math.sqrt(a * a + b * b)
# main :: fn() -> i32 {
#     println("${hypotenuse(3.0, 4.0)} ${math.floor(math.pi)}")
#     return 0
# }
```

```text
5.0 3.0
```

The rules: §11 *Imports*.

## Renaming and leaving out

A list after the path adjusts the plain form: `x as y` takes `x` under another name, and `x as _` leaves it out, which settles a name that two imports both export.

```vader
# module "main"
# import "std/io"
import "std/math" { sqrt as root, floor as round_down }
# main :: fn() -> i32 {
#     println("${root(81.0)} ${round_down(2.7)}")
#     return 0
# }
```

```text
9.0 2.0
```

The rules: §11 *Imports* and §11 *Resolution rules*.

## Visibility

Only exported names reach other modules, and `@internal` keeps one field of an exported struct inside its module.

```vader
# module "main"
# import "std/io"
export Counter :: struct {
    @internal
    count: i32 = 0
}

export bump :: fn(c: Counter) -> i32 {
    c.count += 1
    return c.count
}
# main :: fn() -> i32 {
#     c :: Counter {}
#     c.bump()
#     println("${c.bump()}")
#     return 0
# }
```

```text
2
```

Another module can create a `Counter` and call `bump`, but not read or write `count`. The rules: §11 *Visibility* and §12 *`@internal`*.
