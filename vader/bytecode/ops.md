# The text bytecode (`.virt`)

A `.virt` file is a Vader module as the VM reads it: `vader dump --stage=bytecode`
and `vader build --emit=bytecode-text` write it, and `vader run x.virt` runs it. It is
line-oriented: module directives first, then one `fn … end` body per function, one op
per line. A `;` starts a comment that runs to the end of the line; `--annotate` uses
comments to name what an index points at.

The ops drive a value stack. An operand written after an op is an index into one of
the module's tables — `type N`, `string N`, `data N`, `import N`, `fn N` — or a local
slot: the function's parameters first, then its `local` declarations, in order.

This file is also what an editor shows when hovering an op: every `###` heading below
names the forms it documents, and the first word of each form is the key looked up.

## Module directives

### `module <name>`
Names the module. First line of the file.

### `type <index> <kind> …`
Declares entry `<index>` of the type table. Kinds:
`primitive <name>` (`i32`, `string`, `void`, …), `struct <name> { <field>:<type>, … }`,
`array <element type>`, `union <type>,<type>,…`, `fn (<param types>) -> <return type>`,
and `ref <trait>` / `ref _` — a reference whose concrete type is known only at run time.

### `string <index> "<text>"`
Declares entry `<index>` of the string table, read by `string.const`.

### `data <index> [mut] <kind> …`
Declares entry `<index>` of the data pool, read by `data.const`: a pre-built array.
`<kind> hex"…"` holds scalar elements as little-endian bytes, `str "a" "b" …` strings,
`structs` and `agg` structured elements. `mut` marks a writable global rather than
read-only data.

### `import <index> …`
Declares entry `<index>` of the import table, called by `call.import`: a function the
host provides (`extern` for a C function, with its header), with its signature.

### `impl <type> <trait>`
Records that the type implements the trait — what a run-time `is Trait` test reads.

### `vtable <trait>.<method> <type> <fn>`
Virtual dispatch row: a `virtual.call` of `<trait>.<method>` on a receiver of type
`<type>` runs function `<fn>`.

### `export main <fn>` `export <name> <fn>`
Exports function `<fn>`: `main` is the entry point; any other name keeps the function's
symbol unmangled for a host.

## Functions

### `fn <index> <name> (<param types>) -> <return type>`
Opens the body of function `<index>`. The body runs to the matching `end`.

### `local <name> <type>`
Declares a local slot at the top of a body. Slots number the parameters first, then the
locals in declaration order.

## Constants

### `i32.const <value>` `i64.const <value>`
Push an integer constant. Narrower and unsigned integers travel as `i32` / `i64`.

### `f64.const <decimal> <bits>` `f64.const inf` `f64.const nan`
Push a float. A finite value carries its exact `u64` bit pattern after the decimal, so
it reads back losslessly; `inf`, `-inf` and `nan` have no bits.

### `bool.const <value>`
Push `true` or `false`.

### `char.const <codepoint>`
Push a `char`, written as its base-10 codepoint.

### `null.const`
Push `null`.

### `string.const <string>`
Push entry `<string>` of the string table.

### `data.const <data> <type>`
Push the pre-built array at entry `<data>` of the data pool; `<type>` is its array type.

### `type.const <type>`
Push type `<type>` as a value — the run-time form of a `type`-typed expression.

## Locals

### `local.get <slot>`
Push the value of local `<slot>`.

### `local.set <slot>`
Pop a value into local `<slot>`.

### `local.tee <slot>`
Store the top of the stack into local `<slot>` without popping it.

### `local.field <slot> <type> <field>`
Push field `<field>` of the struct of type `<type>` held in local `<slot>` — a fused
`local.get` + `struct.get`.

### `drop`
Pop and discard the top of the stack.

## Control flow

### `block $L<n> <type>`
Open a block. A `br` to its label jumps past its `end`.

### `loop $L<n> <type>`
Open a loop. A `br` to its label jumps back to its first op.

### `if $L<n> <type>`
Pop a condition: non-zero runs the body, zero jumps to the matching `else`, or past the
matching `end` when there is none.

### `else`
Separates the two branches of an `if`; reached from the first branch, it jumps past
the matching `end`.

### `end`
Closes the innermost `block`, `loop`, `if` or `fn`.

### `br $L<n>`
Jump to the labelled scope: past the end of a `block` or `if`, to the start of a `loop`.

### `br_if $L<n>`
Pop a condition; non-zero jumps as `br` does, zero falls through.

### `return`
Return from the function, with the top of the stack as its result when it has one.

### `return.lit <constant op>`
Push a constant and return it — a fused `<type>.const …` + `return`.

### `unreachable`
Trap. The compiler emits it where it proved control cannot arrive.

## Calls

### `call <fn>`
Call function `<fn>`: pop its arguments, push its result.

### `call.import <import>`
Call host function `<import>`: pop its arguments, push its result.

### `call.indirect <type>`
Pop a function value and call it; `<type>` is its `fn` type, which gives the number of
arguments to pop. A closure's captured environment is passed first.

### `virtual.call <count> <trait>.<method>`
Call a trait method through a vtable: pop the receiver and `<count> - 1` arguments,
then run the function the `vtable` rows give for the receiver's type.

### `fn.ref <fn> <type>`
Push function `<fn>` as a value, with no captured environment.

### `fn.addr <fn>`
Push the machine address of function `<fn>` — for a C callback. Native code only: the
VM traps.

### `make_closure <fn> <env type>`
Pop an environment struct and push a closure of function `<fn>` over it.

### `defer.push`
Pop a closure and push it on the frame's defer stack.

### `defer.pop_exec <count>`
Run the `<count>` most recent deferred closures, last pushed first.

## Structs

### `struct.new <type>` `struct.new_stack <type>`
Pop one value per field, in declaration order, and push a new struct of type `<type>`.
`struct.new_stack` asks the native backend for a stack allocation; the VM treats the
two the same.

### `struct.get <type> <field>`
Pop a struct of type `<type>`, push its field `<field>`.

### `struct.set <type> <field>` `struct.set_stack <type> <field>`
Pop a value, then a struct of type `<type>`; store the value in field `<field>`.

## Arrays

### `array.new <type> <length>`
Pop `<length>` elements (the first pushed becomes element 0) and push a new array of
type `<type>`; with a length of 0, push an empty array.

### `array.len`
Pop an array, push its length.

### `array.get <type>`
Pop an index, then an array; push the element. Traps when the index is out of bounds.

### `array.set <type>`
Pop a value, an index and an array; store the value at the index. Traps when the index
is out of bounds.

### `array.push <type>` `array.push <type> <slot>`
Pop a value, then an array; append the value. The optional `<slot>` is the local holding
the array, written when the compiler proved the surrounding loop may keep the array's
length and capacity in locals — a hint the native backend uses.

### `array.slice <type>`
Pop `hi`, `lo` and an array; push the elements in `lo..<hi`.

### `array.repeat`
Pop a count `n`, then an array; push a new array repeating its elements `n` times —
`[] * n` keeps the length at 0 and reserves `n` slots.

### `array.push_all`
Pop a source array, then a destination; append every element of the source.

### `array.copy`
Pop `len`, `dst_start`, `dst`, `src_start` and `src`; copy `len` elements into `dst`.
Overlapping ranges are handled.

### `array.remove_last`
Pop an array; remove its last element and push it, or `null` when the array is empty.

### `array.clear`
Pop an array and set its length to 0, keeping its capacity.

### `load_slot_i32` `load_slot_i64` `load_slot_f64`
Pop an index, then an array of 4-byte integers, 8-byte integers or `f64`; push the
element. Bounds-checked, like `array.get`.

### `store_slot_i32` `store_slot_i64` `store_slot_f64`
Pop a value, an index and an array of the matching element width; store the value.
Bounds-checked, like `array.set`.

## Types and tags

### `type_check <type>`
Pop a value, push whether its run-time type is `<type>` — the test behind `is` and
`match`. A union type matches any of its variants.

### `ref.cast <type>`
Narrow the static type of the top of the stack to `<type>`. Nothing happens at run time.

### `retag <type>`
Name the precise type of the primitive on the stack as it enters a union or an erased
slot — a `u8` constant is pushed as an `i32`, and the tag is what a later `is u8` reads.

### `intrinsic size_of.type`
Pop a type value, push its size in bytes as a `usize`.

## Integers

`i32.*` carries every integer type up to 32 bits wide, `i64.*` the 64-bit ones, and
arithmetic wraps at 32 or 64 bits. Where signedness matters, the `u32.*` / `u64.*` forms
compare, divide and shift as unsigned.

### `i32.add` `i64.add`
Pop two integers (left, right); push `left + right`.

### `i32.sub` `i64.sub`
Pop two integers (left, right); push `left - right`.

### `i32.mul` `i64.mul`
Pop two integers (left, right); push `left * right`.

### `i32.div` `i64.div`
Pop two signed integers (left, right); push `left / right`, rounded toward zero. Traps
when `right` is 0.

### `i32.rem` `i64.rem`
Pop two signed integers (left, right); push the remainder of `left / right`, with the
sign of `left`. Traps when `right` is 0.

### `u32.div` `u64.div`
Pop two unsigned integers (left, right); push `left / right`. Traps when `right` is 0.

### `u32.rem` `u64.rem`
Pop two unsigned integers (left, right); push `left % right`. Traps when `right` is 0.

### `i32.neg` `i64.neg`
Pop an integer, push its negation.

### `i32.bitand` `i64.bitand`
Pop two integers, push their bitwise AND.

### `i32.bitor` `i64.bitor`
Pop two integers, push their bitwise OR.

### `i32.bitxor` `i64.bitxor`
Pop two integers, push their bitwise XOR.

### `i32.bitnot` `i64.bitnot`
Pop an integer, push its bitwise complement.

### `i32.shl` `i64.shl`
Pop two integers (left, right); push `left << right`.

### `i32.shr` `i64.shr`
Pop two integers (left, right); push `left >> right`, copying the sign bit in.

### `u32.shr` `u64.shr`
Pop two integers (left, right); push `left >> right`, shifting zeros in.

### `i32.eq` `i64.eq`
Pop two integers, push whether they are equal.

### `i32.ne` `i64.ne`
Pop two integers, push whether they differ.

### `i32.lt` `i64.lt` `u32.lt` `u64.lt`
Pop two integers (left, right); push `left < right`, signed or unsigned per the prefix.

### `i32.le` `i64.le` `u32.le` `u64.le`
Pop two integers (left, right); push `left <= right`, signed or unsigned per the prefix.

### `i32.gt` `i64.gt` `u32.gt` `u64.gt`
Pop two integers (left, right); push `left > right`, signed or unsigned per the prefix.

### `i32.ge` `i64.ge` `u32.ge` `u64.ge`
Pop two integers (left, right); push `left >= right`, signed or unsigned per the prefix.

## Floats

### `f64.add`
Pop two floats (left, right); push `left + right`.

### `f64.sub`
Pop two floats (left, right); push `left - right`.

### `f64.mul`
Pop two floats (left, right); push `left * right`.

### `f64.div`
Pop two floats (left, right); push `left / right`.

### `f64.neg`
Pop a float, push its negation.

### `f64.eq`
Pop two floats, push whether they are equal. `nan` equals nothing.

### `f64.ne`
Pop two floats, push whether they differ.

### `f64.lt`
Pop two floats (left, right); push `left < right`.

### `f64.le`
Pop two floats (left, right); push `left <= right`.

### `f64.gt`
Pop two floats (left, right); push `left > right`.

### `f64.ge`
Pop two floats (left, right); push `left >= right`.

### `f64_to_bits` `f32_to_bits`
Pop a float, push its IEEE 754 bit pattern (`u64` / `u32`) — a reinterpretation, not a
numeric conversion.

### `bits_to_f64` `bits_to_f32`
Pop a bit pattern (`u64` / `u32`), push the float it encodes.

## Conversions

### `<from>.to_<to>`
Pop a number (or `char`) of type `<from>`, push it converted to `<to>` — `i32.to_i64`,
`usize.to_i32`, `i64.to_f64`, `u32.to_char`, …

## Booleans

### `bool.not`
Pop a bool, push its negation.

### `bool.and`
Pop two bools, push their AND. Both operands are already evaluated.

### `bool.or`
Pop two bools, push their OR. Both operands are already evaluated.

### `bool.eq`
Pop two bools, push whether they are equal.

### `bool.ne`
Pop two bools, push whether they differ.

## Strings

### `string.eq`
Pop two strings, push whether their bytes are equal.

### `string.ne`
Pop two strings, push whether their bytes differ.

### `string.slice_codepoints`
Pop `hi`, `lo` and a string; push the codepoints in `lo..<hi`. Out-of-range bounds are
clamped.

### `ref.eq`
Pop two references, push whether they are the same object.

### `ref.ne`
Pop two references, push whether they are different objects.

## Buffers

A buffer is a zero-filled byte region the GC moves; it is addressed as
`(buffer, byte offset)`, never by machine address.

### `buffer.new`
Pop a size in bytes, push a new zero-filled buffer.

### `load_u8` `load_i32` `load_i64` `load_f64`
Pop a byte offset, then a buffer; push the value stored there.

### `store_u8` `store_i32` `store_i64` `store_f64`
Pop a value, a byte offset and a buffer; store the value there.

### `memory_copy`
Pop `n`, `src_off`, `src`, `dst_off` and `dst`; copy `n` bytes from `src` to `dst`.

### `buffer_to_string`
Pop a length, then a buffer; push a string of its first `length` bytes.

### `buffer_write_string`
Pop a string, a byte offset and a buffer; copy the string's bytes into the buffer at
that offset.
