# Vaderlang

Vader is an experimental language, allowing me to learn compiler development.

This language compile into WASM bytecode.

Objective: Create a simple language to be able to implement [AOC](https://adventofcode.com/) exercises

This bytecode should be able to run using any WASI compliant runtime ([wasmtime](https://wasmtime.dev/) for instance)

## Getting started

```
// Simple hello world app
@load "modules/std"

main :: fn () -> u32 {
    print("Hello world\n")
    return 0
}

```

Compile the source to wasm using `bun src/index.ts [file location].vader`

Execute the wasm file with wasmtime using `wasmtime [file location].wasm`

> If wasmtime is in your path, you can directly compile and run with the following command :
`bun src/index.ts --run [file location].vader`

## Todo

- [x] simple parser
- [x] emit wasm
- [x] variable declaration & usage
- [x] conditions
- [x] function call
- [x] print function
- [x] shebang support
- [x] load instruction (simple instruction that concatenate tokens)
- [x] module resolver
- [x] implement snapshot testing (for tokenizer, parser, and emitter)
- [x] fix operator precedence
- [x] dot expression `a.b.c`
- [x] better VaderType (should be recursive to support array `:String[4]`)
- [x] rework on variable assignment identifier should be an expression to support dot expression & array assignment
- [ ] better number checking (for a given type should be in a range MIN..MAX)
- [x] for loop
- [x] structure declaration & usage
- [ ] import lib with namespace
- [x] read file (to simplify make it load file during compilation time)
- [x] function call equivalence (`print(a, b) <=> a.print(b)`)
- [ ] type checking
- [ ] operator overloading
- [ ] runtime memory allocation
- [ ] runtime memory de-allocation
- [ ] stdlib: arraylist, hashmap, number to string(2, 8, 10, 16), split
- [ ] iterators
- [ ] better error reporting (should not exit when parsing error occur)
- [ ] LSP for vader
- [x] if expression `x :: if (b > 2) 2 else 3`
- [ ] (Optional) allow to compile pure WASM without WASI
- [ ] (Optional) @export decorator on function to export a function with no mangling

## Syntax

### Primitive Types

- boolean: true/false
- u8: 0-255
- u16: 0-65_535
- u32: 0-4_294_967_295
- u64: 0-18_446_744_073_709_551_615
- f32
- f64

### Variables

- declared via `::` = immutable variable (value will never change)
- declared via `:=` = variable value can change
- affectation via `=`. Only variable declared with `:=` can be reassigned

### Strutures

#### Declaring a structure

```
MyStruct :: struct {
    a: u32
    b: f16
}
```

#### Creating a structure

```
x :: MyStruct {
    a = 12
    b = 12.43
}
```

### Function

Function is declared with an identifier and the keyword `fn` :

```
// Simple function declaration : 
// - no argument
// - return a u32
main :: fn () -> u32 {

}
```

#### Syntactic sugar

When calling a function with the dot expression, the first parameter can be omited :

```
plus :: fn(this: u32, other: u32) -> u32{
    return this + other;
}

// Those 2 expressions call are equivalents : 
2.plus(3)
plus(2, 3)

```

### Decorators

Decorator are compiler instruction.

#### @intrinsic

Applicable on a function. This decorator permit to define a function provided by the WASM runtime.

#### @file

Applicable on a string literal. Allow to embed during compilation time a file and convert it to a string literal.

#### @load

Applicable on a string literal. Allow to parse another vader file and concatenate it with the current parsed file.

## Duck-typing

## Backend

- binaryen (for wasm)
- qbe (for arm64 & amd64)

## Contribution

You need bun install on your computer
To install dependencies:

```bash
bun install
bun run src/index.ts
```
