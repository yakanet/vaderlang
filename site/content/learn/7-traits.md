# Traits and operators

A trait names the functions a type must provide. Any type can implement one, a built-in type included, and the standard operators are traits too.

## Declaring and implementing a trait

A trait lists its members. `Type implements Trait { ... }` defines them, with `self` the value it is called on.

```vader
# module "main"
# import "std/io"
Shape :: trait {
    area :: fn(self) -> f64
    name :: fn(self) -> string
}

Circle :: struct { radius: f64 }
Square :: struct { side: f64 }

Circle implements Shape {
    area :: fn(self) -> f64 = 3.0 * self.radius * self.radius
    name :: fn(self) -> string = "circle"
}

Square implements Shape {
    area :: fn(self) -> f64 = self.side * self.side
    name :: fn(self) -> string = "square"
}
# main :: fn() -> i32 {
#     shapes: Shape[]: [Circle { .radius = 1.0 }, Square { .side = 2.0 }]
#     for s in shapes {
#         println("${s.name()}: ${s.area()}")
#     }
#     return 0
# }
```

```text
circle: 3.0
square: 4.0
```

An array of `Shape` holds values of every type that implements it, and each call reaches the right one. The rules: §4 *Traits*.

## One member, one line

A trait with a single member to define takes a short form: an arrow and the body.

```vader
# module "main"
# import "std/io"
Point :: struct { x: i32, y: i32 }

Point implements Display -> "(${self.x}, ${self.y})"
# main :: fn() -> i32 {
#     println("${Point { .x = 3, .y = 4 }}")
#     return 0
# }
```

```text
(3, 4)
```

`Display` is the trait string interpolation reads. The rules: §4 *Single-method trait sugar (SAM)*.

## Default members

A member may come with a body, which a type gets unless it defines its own.

```vader
# module "main"
# import "std/io"
Greeter :: trait {
    name  :: fn(self) -> string
    greet :: fn(self) -> string = "Hello, ${self.name()}!"
}

English :: struct {}
Pirate :: struct {}

English implements Greeter {
    name :: fn(self) -> string = "friend"
}

Pirate implements Greeter {
    name  :: fn(self) -> string = "matey"
    greet :: fn(self) -> string = "Ahoy, ${self.name()}!"
}
# main :: fn() -> i32 {
#     println(English {}.greet())
#     println(Pirate {}.greet())
#     return 0
# }
```

```text
Hello, friend!
Ahoy, matey!
```

The rules: §4 *Default methods*.

## Operators

`+`, `-`, `*`, `/`, `==`, `<` and the others call the member of a standard trait: implementing `Add` gives a type `+`, and `+=` with it.

```vader
# module "main"
# import "std/io"
Money :: struct { cents: i64 }

Money implements Add -> Money { .cents = self.cents + other.cents }
Money implements Equals -> self.cents == other.cents
Money implements Display -> "${self.cents} cents"
# main :: fn() -> i32 {
#     total := Money { .cents = 1250 }
#     total += Money { .cents = 375 }
#     println("${total}")
#     println("${total == Money { .cents = 1625 }}")
#     return 0
# }
```

```text
1625 cents
true
```

The rules: §4 *Operator overloading*.
