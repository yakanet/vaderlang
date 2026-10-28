# Generators

A function with a `yield` produces its values lazily, so an endless sequence can be filtered and cut as an iterator.

```vader
module "main"

import "std/io"
import "std/iter"

// A function with a `yield` is a generator: it produces its values
// one at a time, as the consumer asks for them.
fibonacci :: fn() -> Iterator<i64> {
    a: i64 = 0
    b: i64 = 1
    for {
        yield a
        next :: a + b
        a = b
        b = next
    }
}

main :: fn() -> i32 {
    evens :: fibonacci().filter(n -> n % 2 == 0).take(6).collect()
    println("${evens}")
    return 0
}
```

```text
[0, 2, 8, 34, 144, 610]
```
