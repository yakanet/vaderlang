# Errors as values

There are no exceptions. `sum_of` returns the sum or the error, and its caller cannot use the number before ruling the error out.

```vader
module "main"

import "std/io"
import "std/string"

// A failure is a value: `parse_int` returns `i32 | ParseError`,
// and the sum can be used only once the error is ruled out.
sum_of :: fn(text: string) -> i32 | ParseError {
    total := 0
    for field in text.split(",") {
        n :: parse_int(field.trim())
        if n is ParseError {
            return n
        }
        total += n
    }
    return total
}

main :: fn() -> i32 {
    for input in ["1, 2, 3", "4, five"] {
        result :: sum_of(input)
        if result is ParseError {
            println("${input}: ${result.msg}")
        } else {
            println("${input}: ${result}")
        }
    }
    return 0
}
```

```text
1, 2, 3: 6
4, five: parse_int: invalid digit
```
