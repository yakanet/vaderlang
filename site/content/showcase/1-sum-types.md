# Sum types

A `Shape` is a circle or a rectangle, and the `match` must handle both: forget one and the program does not compile.

```vader
module "main"

import "std/io"
import "std/math"

// A sum type: `match` must cover every variant.
Shape :: Circle | Rect

Circle :: struct { radius: f64 }
Rect   :: struct { w: f64, h: f64 }

area :: fn(s: Shape) -> f64 = match s {
    is Circle -> pi * s.radius * s.radius
    is Rect   -> s.w * s.h
}

main :: fn() -> i32 {
    shapes: Shape[]: [
        Circle { .radius = 2.0 },
        Rect { .w = 3.0, .h = 4.0 },
    ]
    total := 0.0
    for s in shapes {
        total += s.area()          // UFCS: s.area() is area(s)
    }
    println("${shapes.len()} shapes, total area ${total}")
    return 0
}
```

```text
2 shapes, total area 24.566370614359172
```
