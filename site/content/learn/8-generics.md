# Generics

A function or a struct may take types as parameters, written `<T>`. A bound, `<T: Comparable>`, says what the type must implement, and the body may use only that.

## Generic functions

`<T>` after `fn` names a type the call decides. Each call infers it, from its arguments or else from where its result goes.

```vader
# module "main"
# import "std/io"
last :: fn<T>(items: T[], fallback: T) -> T {
    if items.len() == 0 {
        return fallback
    }
    return items[items.len() - 1]
}
# main :: fn() -> i32 {
#     println("${last([1, 2, 3], 0)}")
#     println(last(["ada", "grace"], "nobody"))
#     println(last([], "nobody"))
#     return 0
# }
```

```text
3
grace
nobody
```

The rules: §4 *Generics* and §4 *Type arguments of a call*.

## Bounds

Inside a generic body, a value of type `T` can do only what its bound allows: `T: Comparable` gives it `<`, `<=`, `>` and `>=`.

```vader
# module "main"
# import "std/io"
largest :: fn<T: Comparable>(items: T[]) -> T | null {
    if items.len() == 0 {
        return null
    }
    best := items[0]
    for item in items {
        if item > best {
            best = item
        }
    }
    return best
}
# main :: fn() -> i32 {
#     println("${largest([3, 9, 4]) ?? 0}")
#     println(largest(["pear", "apple", "plum"]) ?? "none")
#     return 0
# }
```

```text
9
plum
```

The rules: §4 *Generics* and §4 *Operator overloading*.

## Generic structs

A struct may take type parameters too, and its literal names them: `Pair<string, i32> { ... }`.

```vader
# module "main"
# import "std/io"
Pair :: struct<A, B> {
    first:  A
    second: B
}

swapped :: fn<A, B>(p: Pair<A, B>) -> Pair<B, A> =
    Pair<B, A> { .first = p.second, .second = p.first }
# main :: fn() -> i32 {
#     p :: Pair<string, i32> { .first = "answer", .second = 42 }
#     q :: p.swapped()
#     println("${q.first} ${q.second}")
#     return 0
# }
```

```text
42 answer
```

The rules: §4 *Generics*.
