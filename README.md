# vaderlang

Objective: Create a simple language to be able to implement [AOC](https://adventofcode.com/) exercises

This language compile into WASM bytecode.

This bytecode should be able to run using any WASI compliant runtime ([wasmtime](https://wasmtime.dev/) for instance)

## Getting started

```
// Simple hello world app
@intrinsic
print :: fn(message: String) -> void

main :: fn () -> u32 {
    print("Hello world\n")
    return 0
}

```

Compile the source to wasm using `bun src/index.ts [file location].vader`

Execute the wasm file with wasmtime using `wasmtime [file location].wasm`

> If wasmtime is in your path, you can directly compile and run with the following command : 
`bun src/index.ts --run [file location].vader`

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
