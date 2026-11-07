# Generators and tasks

A function that uses `yield` gives its values one at a time, as they are asked for. A task runs a function beside the code that launched it, and waits without blocking the program.

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

## Tasks

`launch`, from `std/task`, starts a task that runs a function; `join` waits for its result, and `join_all` for the results of several.

```vader
# module "main"
# import "std/io"
# import "std/task"
# import "std/time"
fetch :: fn(name: string, delay: i64) -> string {
    sleep(delay.millis())
    println("${name} done")
    return name
}
# main :: fn() -> i32 {
#     results :: join_all([launch(() -> fetch("slow", 30)), launch(() -> fetch("fast", 10))])
#     println("${results}")
#     return 0
# }
```

```text
fast done
slow done
[slow, fast]
```

The two tasks run together: the fast one finishes first, yet the results keep the order of the array. `fetch` is an ordinary function: a task waits wherever it is in its calls. A value one task reads cannot be written beside it while it runs; the compiler says so, and proposes a copy. The rules: §16 *Tasks*, §16 *Values shared between tasks* and §16 *Combinators*.

## Racing and timeouts

`race` gives the result of the first task to finish and cancels the others. `timeout` gives a `TimeoutError` when its delay passes first.

```vader
# module "main"
# import "std/io"
# import "std/task"
# import "std/time"
answer :: fn(delay: i64) -> i64 {
    sleep(delay.millis())
    return delay
}
# main :: fn() -> i32 {
#     winner :: race([launch(() -> answer(50)), launch(() -> answer(5))])
#     println("${winner}")
#     late :: timeout(launch(() -> answer(100)), 10.millis())
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
