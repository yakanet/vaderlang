# Compile time

A `@comptime` constant runs ordinary Vader during the build: the program starts with the table already filled in.

```vader
module "main"

import "std/io"

squares :: fn(n: i32) -> i32[] {
    out: i32[]: []
    for i in 0..<n {
        out.push(i * i)
    }
    return out
}

// Computed by the compiler: the program holds the table, not the loop.
@comptime SQUARES :: squares(8)

main :: fn() -> i32 {
    println("${SQUARES}")
    return 0
}
```

```text
[0, 1, 4, 9, 16, 25, 36, 49]
```
