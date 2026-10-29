# Generators and async functions

A function that uses `yield` gives its values one at a time, as they are asked for. A function that uses `await` waits for others without blocking the program.

## Generators

A function whose body holds a `yield` is a generator: it returns an `Iterator<T>`, and each `yield` hands out the next value.

```vader
# module "main"
# import "std/io"
# import "std/iter"
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
# main :: fn() -> i32 {
#     println("${fibonacci().take(10).collect()}")
#     for n in fibonacci() {
#         if n > 1000 {
#             println("${n}")
#             break
#         }
#     }
#     return 0
# }
```

```text
[0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
1597
```

The loop never ends, yet nothing runs past what `take` or the `break` asks for. The rules: §15 *Generators*.

## Generators and chains

What a generator returns is an iterator like any other. Here it walks nested data and hands out a flat sequence, the words of several lines, to `count`, `filter` and `collect`; each call starts a new iterator.

```vader
# module "main"
# import "std/io"
# import "std/iter"
# import "std/string"
words_of :: fn(lines: string[]) -> Iterator<string> {
    for line in lines {
        for word in line.split(" ") {
            if word != "" {
                yield word
            }
        }
    }
}
# main :: fn() -> i32 {
#     lines :: ["the quick brown fox", "jumps over  the lazy dog"]
#     println("${words_of(lines).count()} words")
#     println("${words_of(lines).filter(w -> w.byte_len() > 4).collect()}")
#     return 0
# }
```

```text
9 words
[quick, brown, jumps]
```

The rules: §15 *Generators* and §15 *Iteration*.

## Async functions

A function that uses `await` declares `-> Async<T>`, and its body returns the `T`. `join_all`, from `std/async`, waits for several at once (delays are in milliseconds).

```vader
# module "main"
# import "std/async"
# import "std/io"
fetch :: fn(name: string, delay: i64) -> Async<string> {
    await sleep(delay)
    println("${name} done")
    return name
}
# main :: fn() -> i32 {
#     results :: await join_all([fetch("slow", 30), fetch("fast", 10)])
#     println("${results}")
#     return 0
# }
```

```text
fast done
slow done
[slow, fast]
```

The two calls run together: the fast one finishes first, yet the results keep the order of the array. The rules: §16 *async/await* and §16 *Combinators*.

## Racing and timeouts

`race` gives the result of the first call to finish and cancels the others. `timeout` gives a `TimeoutError` when its delay passes first.

```vader
# module "main"
# import "std/async"
# import "std/io"
answer :: fn(delay: i64) -> Async<i64> {
    await sleep(delay)
    return delay
}
# main :: fn() -> i32 {
#     winner :: await race([answer(50), answer(5)])
#     println("${winner}")
#     late :: await timeout(10, answer(100))
#     if late is TimeoutError {
#         println("too slow")
#     }
#     return 0
# }
```

```text
5
too slow
```

The rules: §16 *Combinators* and §16 *Cancellation*.
