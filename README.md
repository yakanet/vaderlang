# vaderlang

## Syntax

### Primitive Types

- boolean: true/false
- u8: 0-255
- u16
- u32
- u64
- s8:
- s16:
- s32:
- s64
- f8
- f16
- f32
- f64

### Variables
- declared via `::` = immutable variable (value will never change)
- declared via `:=` = variable value can change

### Strutures
```
MyStruct :: struct {
    a: u32
    b: f16
}
```

### Function
```
maFunc :: proc (a: u32, b: f16): u32 {

}

main :: proc (): i32 {
    
}

MyStruct.myFunc :: proc(a: u32, b: f16): void {
    // this refer to MyStruct
}
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
