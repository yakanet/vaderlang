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
- val = immutable variable (value will never change)
- var = variable value can change

### Strutures
```
val MyStruct = struct {
    a: u32
    b: f16
}
```

### Function
```
fn maFunc (a: u32, b: f16): u32 {

}

fn main (): int {
    
}

fn MyStruct.myFunc(a: u32, b: f16) {
    // this refer to MyStruct
}
```

## Duck-typing

## Contribution

You need bun install on your computer
To install dependencies:

```bash
bun install
bun run src/index.ts
```
