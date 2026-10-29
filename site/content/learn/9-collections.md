# Collections and iteration

Arrays are built in; maps and sets come from `std/collections`. A chain of steps from `std/iter`, such as `filter` and `map`, walks any of them one value at a time and builds the result at the end.

## Arrays

An array grows with `push` and shrinks with `remove_last`. `x in array` tests whether it holds a value, and `a[i]` reads an element, checked against the length.

```vader
# module "main"
# import "std/io"
# main :: fn() -> i32 {
    primes :: [2, 3, 5]
    primes.push(7)
    primes.push_all([11, 13])
    println("${primes.len()} primes, the last is ${primes[primes.len() - 1]}")
    println("${5 in primes} ${6 in primes}")
    removed :: primes.remove_last() ?? 0
    println("${removed} removed, ${primes.len()} left")
#     return 0
# }
```

```text
6 primes, the last is 13
true false
13 removed, 5 left
```

A binding made with `::` only fixes the name: the array it names may still change. The rules: §4 *Arrays*, §4 *Mutation methods* and §5 *Mutability: two independent axes*.

## Maps and sets

`MutableMap<K, V>` maps keys to values, and `for [key, value] in` walks its entries. `MutableSet<T>` keeps each value once.

```vader
# module "main"
# import "std/collections"
# import "std/io"
# main :: fn() -> i32 {
    counts :: MutableMap<string, i32> {}
    for word in ["to", "be", "or", "not", "to", "be"] {
        counts[word] = (counts[word] ?? 0) + 1
    }
    for [word, n] in counts {
        println("${word}: ${n}")
    }
    seen :: MutableSet<i32> {}
    seen.add(4)
    seen.add(4)
    println("${seen.len()} ${4 in seen}")
#     return 0
# }
```

```text
to: 2
be: 2
or: 1
not: 1
1 true
```

Reading a key that is absent gives `null`, hence the `??`. Here the map walks its entries in the order they were added; removing one can change that order. The library: [`std/collections`](/lib/std/collections/).

## Lazy iterators

`filter`, `map`, `take` and the others build a lazy iterator: nothing runs until a step such as `collect`, `sum` or `count` asks for the values.

```vader
# module "main"
# import "std/io"
# import "std/iter"
# main :: fn() -> i32 {
    words :: ["vader", "is", "a", "small", "language"]
    long :: words.filter(w -> w.byte_len() > 2).map(w -> w.byte_len()).collect()
    println("${long}")
    println("${(1..=100).filter(n -> n % 7 == 0).take(3).collect()}")
    println("${(1..=10).map(n -> n * n).sum()}")
#     return 0
# }
```

```text
[5, 5, 8]
[7, 14, 21]
385
```

The rules: §15 *Iteration*.

## Sorting

`sort`, from `std/sort`, gives a sorted copy of an array. The function it takes answers true when its first argument must come strictly before the second; equal elements then keep their order.

```vader
# module "main"
# import "std/io"
# import "std/sort"
Person :: struct { name: string, age: i32 }

youngest_first :: fn(people: Person[]) -> Person[] = people.sort((a, b) -> a.age < b.age)
# main :: fn() -> i32 {
#     people :: [
#         Person { .name = "grace", .age = 85 },
#         Person { .name = "ada", .age = 36 },
#         Person { .name = "linus", .age = 55 },
#     ]
#     for p in youngest_first(people) {
#         println("${p.name} ${p.age}")
#     }
#     return 0
# }
```

```text
ada 36
linus 55
grace 85
```

The library: [`std/sort`](/lib/std/sort/).
