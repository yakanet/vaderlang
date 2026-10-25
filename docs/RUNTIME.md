# Runtime

How a Vader program holds its values and its memory while it runs, and what a
backend has to provide to run one. The language is described in
[`SPEC.md`](../SPEC.md) and the compiler in [`ARCHITECTURE.md`](ARCHITECTURE.md);
this document describes the implementation, which may change without the
language changing.

A program runs in one of two ways:

- **natively**: the C emitter writes C, and `cc` links it with the C runtime of
  `runtime/c/` (`vader.h`, `vader_runtime.c`);
- **on the VM** (`vader/vm/`), for `vader run`, `vader test` and the `@comptime`
  declarations the comptime interpreter cannot evaluate.

Both start from the same bytecode. The C emitter translates it to C; the VM
translates each function to register code when it loads the module
([ADR 0024](adr/0024-the-vm-runs-register-code-translated-at-load.md)).

The VM is itself a Vader program, compiled natively. Its values are values of
that host program, and its memory is the host's: it has no heap and no collector
of its own.

The C layouts below are excerpts: `runtime/c/vader.h` is the authority.

## Values

| Vader type | Native (C) | VM |
|---|---|---|
| `i8` ... `i64`, `u8` ... `u64` | the C integer of that width, `int8_t` ... `uint64_t` | `I32Val` up to 32 bits, `I64Val` beyond |
| `f32`, `f64` | `float`, `double` | `F64Val` |
| `bool` | `bool` | `BoolVal` |
| `char` | `uint32_t`, the codepoint | `CharVal` |
| enum | the narrowest integer its values fit in, or the width it declares (SPEC §4) | that integer |
| integer range type (`0..=9`) | the narrowest integer that holds its bounds | that integer |
| distinct type | its base type, down to the C struct of a distinct struct | its base type |
| `string` | `vader_string_t`, a 32-bit atom id | `StringVal`, a string of the host |
| struct, tuple | a pointer to a heap object | `StructVal` |
| `T[]` | a pointer to an array header | `ArrayVal` |
| function value | a pointer to a `vader_fn_t` | `FnVal` |
| union, `T \| null`, trait value, `any`, erased type parameter | a box (`vader_box_t`, 16 bytes) | the member's own value |
| `null` | the box of tag 0 | `NullVal` |

A generic instance follows the same table once its type arguments are known. A
mono instance is fully substituted. In a mixed or an erased one, a type parameter
bound to a primitive stays that primitive, and one bound to a reference type is
erased to a box ([`ARCHITECTURE.md`](ARCHITECTURE.md), *Instance flavors*).

On the VM, every integer up to 32 bits rides in an `I32Val`, unsigned ones as
their bits. A value of 8 or 16 bits is narrowed where it is stored (a local, a
field, a return), and an unsigned one is reinterpreted where it is printed or
widened.

## Boxes and tags

A box is what a slot holds when its static type does not fix the value's type.

```c
typedef struct {
    uint32_t tag;
    uint32_t _pad;
    union {
        int64_t        i;
        double         f;
        bool           b;
        vader_string_t s;
        void*          obj;
        uint8_t        packed[8];
    } payload;
} vader_box_t;
```

It is 16 bytes, so that it travels in two registers
([ADR 0018](adr/0018-a-box-was-24-bytes-for-a-payload-nothing-writes.md)). The
payload holds a scalar itself, widened to 64 bits (an `f32` as a `double`), a
string's atom id, or a pointer to an object.

The **tag** is the index, in the module's type table, of the value's own type:
the concrete struct, the integer type, never the union it sits in. Index 0 is
reserved for `null`, so a box of tag 0 is `null` whatever the slot's type. An
object's header carries the same index (*Objects*), which is how a pointer
taken out of a box gets its tag back. A scalar gets its tag where it enters a
boxed slot, from its own type (the `retag` op,
[ADR 0098](adr/0098-a-scalar-entering-any-boxed-slot-is-tagged-by-its-type.md)).

`x is T` compares the tag with the index of `T`; `x is A | B` compares it with
each. A test against a trait accepts the index of every type that implements it.
`f32` and `f64` share their test: `is f32` and `is f64` both accept either tag.

On the VM, a union slot holds the member's own `Value`, and the variant of the
`Value` union is the tag; the native build of the VM stores a scalar `Value`
without allocating ([ADR 0025](adr/0025-a-vm-scalar-rides-in-its-box.md)). That
tag is coarser than the native one: an `I32Val` is any integer up to 32 bits, and
the VM ignores `retag`, so a test on a union of integer widths can answer
differently (`TODO.md`). A struct or an array is tested by the index it carries.

## Strings

A string is an **atom**: a 32-bit index into a table that holds every string of
the program once ([ADR 0109](adr/0109-a-string-is-an-atom.md)).

```c
typedef struct {
    uint32_t    parent;          /* 0 for an atom that owns its bytes, else the owner's id */
    uint32_t    parent_offset;   /* where a slice starts in its owner's bytes */
    uint32_t    len;             /* length in bytes */
    uint16_t    flags;           /* PERM, MARK, ASCII */
    uint16_t    _pad;
    const char* data;            /* the bytes */
    uint64_t    hash;            /* hash of the bytes, computed when the atom is created */
} vader_atom_entry_t;
```

Every string the program makes is looked up when it is complete (concatenation
and `StringBuilder` assemble the bytes in a `Buffer` first), so two strings with
the same bytes are the same atom:

- `==` compares two integers;
- the hash is read from the entry, where it was computed from the bytes;
- ordering compares the bytes, which is codepoint order for UTF-8.

**Owners and slices.** An atom that owns its bytes keeps them in a buffer of its
own, outside the GC heap, followed by a NUL byte so that C can read it without a
copy. A slice (`byte_slice`, and the codepoint slices built on it) points into
its owner's bytes and copies nothing; a slice of a slice points into the same
owner, and a slice covering its whole owner is the owner itself. A slice keeps
its owner alive.

**Literals.** The C emitter writes the program's string literals into a table in
`.rodata`, which `main` loads at start-up: the empty string is atom 0, the other
literals atoms 1 to *n*, and a literal in the code is its number. These atoms are
flagged `PERM` and never collected.

**ASCII.** An atom whose bytes are all below 0x80 is flagged `ASCII` when it is
created; `len`, `s[i]` and `s[lo..<hi]` then index its bytes instead of walking
its codepoints ([ADR 0065](adr/0065-an-ascii-string-is-indexed-by-its-bytes.md)).

**Collection.** Atoms are collected by a major collection, and only there
(*Memory*): every atom a root, an object or the C stack can reach is marked, and
every other atom that is not `PERM` loses its bytes. Its index goes on a free
list for the next atom; indices are never compacted, so the table never shrinks.
A program that never needs a major never frees an atom.

**C strings.** An `@extern` parameter of type `string` receives the owner's
bytes as they are, or, for a slice, a NUL-terminated copy freed after the call.

On the VM, a string is a string of the host program, so it is an atom of the VM's
own process: `==`, the hash and the order agree with a native build.

## Objects

Every heap object starts with the same 16-byte header:

```c
typedef struct {
    uint32_t type_index;   /* index in the type table: the object's layout and its tag */
    uint8_t  age;          /* collections survived in the young generation */
    uint8_t  mark;         /* the old generation's mark */
    uint16_t _reserved;    /* flags of an array header or buffer */
    void*    forward;      /* where a collection moved the object */
} vader_obj_header_t;
```

Allocations are rounded up to 8 bytes. The C emitter writes a table,
`vader_type_info_table`, with one row per type index: the kind of object (struct,
array, function), its size, and the offsets of the fields the collector has to
visit, in three lists: boxes, raw pointers to objects, and strings. The row also
gives the width of a slot of that type, which is what `@size_of` answers for a
type known only at run time.

**A struct** is the header followed by its fields, in declaration order, each at
the width of its type: a scalar as itself, a string as its atom id, a struct,
array, tuple or function as a raw pointer, a union or a trait value as a box.

**A tuple** is a struct the compiler declares for its shape, `__Tuple_<shape>`,
with fields `_0`, `_1`, ... A function that returns a small tuple of scalars
(16 bytes at most), or an `S | null` of a small struct of scalars, may return the
elements as separate values instead, through out-parameters in C
([`MID_IR.md`](MID_IR.md)).

**A cell** holds a local that a closure captures and an assignment rebinds: a
struct `$Cell_<T>` with one field, `value`
([ADR 0030](adr/0030-a-capture-nothing-rebinds-is-copied-into-the-closure.md)).

**A struct on the stack.** In a native build, escape analysis marks the structs
that cannot outlive the function that builds them. The C emitter declares such a
struct as a local of its C type and initialises its header like any other. It
never moves; the collector visits its fields through the function's frame
(*Memory*, [ADR 0003](adr/0003-stack-allocated-gc-structs-are-rooted.md)).

On the VM, a struct, a tuple and a cell are all a `StructVal`: the type index
and an array of `Value`, one per field, in order.

## Arrays and views

A native array is two objects: a header, which is what a `T[]` slot points at,
and a buffer, which holds the elements. A new array allocates both as one block;
a `push` that outgrows the buffer allocates a larger one and points the header at
it.

```c
typedef struct {
    vader_obj_header_t      header;
    size_t                  length;
    size_t                  capacity;
    size_t                  offset;
    struct vader_array_buf* buf;
} vader_array_t;

typedef struct vader_array_buf {
    vader_obj_header_t header;
    size_t             capacity;
    size_t             length;
    uint32_t           element_tag;
    uint8_t            element_kind;
    uint8_t            _pad[3];
    uint8_t            slots[];
} vader_array_buf_t;
```

The buffer's `element_kind` says how its slots are stored:

- **packed**, for an element of a primitive type: each element at its own width,
  a `u32[64]` in 256 bytes. A `bool` takes a byte. All the elements share the
  tag `element_tag`, which a read stamps on the value when it has to box it;
- **raw pointers** (`REF`), for an element whose every value is an object or
  `null`: a struct, an array, a function, or a union of those (`Expr[]`). A read
  that needs a box takes the tag from the object's header;
- **boxed**, for everything else: strings, unions holding a scalar, trait
  values. An array built by erased generic code is boxed too, whatever its
  element type, and so is an array of structs baked into the data pool (*Globals
  and constants*), so a read checks the buffer's kind rather than assume it.

**A slice** `arr[r]` is a second header over the same buffer, with its own
`offset` and `length`. A write through it reaches the parent; a push detaches it
into a buffer of its own first: a slice is created with a capacity equal to its
length, so its first push takes the growing path
([ADR 0108](adr/0108-a-slice-shares-its-parents-buffer-and-a-push-detaches-it.md)).
Slicing marks a young buffer as shared, for the foreign-call path (*Memory*).

**The bytes of a string**, `s.bytes()`, are a header with no buffer: flagged
*borrowed*, it reads the string's interned bytes in place, and the field
`capacity`, which such a view never needs, holds the string's atom id and the
`u8` tag. The language forbids writing it (SPEC §5, *Frozen values*), so nothing
can reach those bytes.

An index is checked against `length` before every access. A release build drops
the checks the range analysis proves useless
([ADR 0058](adr/0058-a-release-build-drops-the-index-checks-the-range-analysis-proves.md)).

On the VM, an `ArrayVal` holds its elements as an array of `Value`, always boxed,
with `offset` and `length` for a view. A push detaches a view first; a write
reaches the parent. `s.bytes()` gives an `ArrayVal` whose `raw` field holds the
string itself, read in place
([ADR 0029](adr/0029-the-vm-reads-a-strings-bytes-in-place.md)).

A slice of the whole array breaks these rules today, on the VM and natively
(`TODO.md`).

## Functions and closures

A function value is an object: the header, then two pointers.

```c
typedef struct { vader_obj_header_t header; void* code; void* env; } vader_fn_t;
```

`code` takes the environment as its first argument and every other argument as
a box, and returns a box: a call through a function value does not know the
callee's signature, so it uses this one. A function used as a value gets a static
`vader_fn_t` with no environment, whose `code` is a trampoline: it drops the
environment, unboxes the arguments, calls the function and boxes its result.

**A closure** is a `vader_fn_t` whose `env` points at a struct the compiler
declares for it, with one field per captured local, `cap_0`, `cap_1`, ... A local
nothing rebinds after the capture is copied into the environment; one an
assignment rebinds lives in a cell (*Objects*). A lambda that captures nothing is
a plain function value. The environment always lives on the heap.

**A trait call** on a trait value or on the receiver of an erased instance goes
through a dispatcher the C emitter writes per trait method: a `switch` on the
receiver's tag with one case per implementing type, which unboxes the arguments
and calls that type's impl member. The result comes back unboxed, unless the
implementations disagree on its type. A tag no case covers ends the program
(`vtable miss`).

On the VM, a function value is a `FnVal`: the index of the function in the
module, and its environment. A call through it puts the environment in the
callee's first register. A trait call looks up the receiver's type index in the
module's vtable rows. `fn_addr`, the address of a function handed to C, has no
meaning there and traps.

## Globals and constants

A program's only global slots are those the compiler adds for `@singleton`: a
state and the instance it built, per singleton. Natively each is a C global,
zero-initialised, rooted by a frame `main` installs (*Memory*). On the VM they are
an array of `Value`.

A module constant has no storage at run time:

- a scalar is folded into the code;
- an array or a struct the compiler can build at compile time is baked into the
  **data pool**: in C, a `const` static (header, buffer and elements), which the
  collector treats as immortal since it lies outside the heap; on the VM, a value
  built once when the module loads. A struct is baked as a one-element array;
- a large array the compiler cannot bake becomes a function, `__const_<name>`,
  that builds it;
- anything else is rebuilt where it is read.

## Memory

A native build uses a generational collector: objects are born in a young
generation that is collected often, and those that survive move to an old
generation that is collected rarely
([ADR 0007](adr/0007-generational-gc-copying-young-non-moving-old.md)). The sizes
below are the defaults of `runtime/c/vader.h`.

- **Young** is a pair of semi-spaces, 32 MB each to start with, where allocation
  bumps a pointer. A **minor** collection copies every live young object into the
  old generation: an object is promoted at its first collection
  ([ADR 0104](adr/0104-a-young-survivor-is-promoted-at-its-first-collection.md)),
  and stays young only when the old generation is full. Young grows to fit an
  object larger than a semi-space (up to 2 GB), and with the old live set (up to
  192 MB).
- **Old** is one address-space reservation, committed as it fills: half the
  machine's memory by default, less what young may take, kept between 256 MB and
  4 GB. It never moves an object: objects up to 1 KB take a slot of their size
  class, larger ones a region of their own.
- **The card table** records the old objects a pointer was written into, one
  byte per 512 bytes of old space. The C emitter writes the barrier after every
  store of a pointer into an object, and a minor visits only the dirty cards
  instead of the whole old generation
  ([ADR 0105](adr/0105-a-major-leaves-the-card-table-as-its-minor-left-it.md)).

**Collections.** A **major** marks what is live in the old generation and frees
the rest in place. It runs after a minor once the old generation holds one and a
half times what the last major left, and at least 64 MB; when a minor cannot make
room for an allocation; and when `std/runtime.collect()` asks. It starts with a
minor and ends by collecting the atoms.

**Roots.** A function whose locals must survive a collection pushes a frame on a
shadow stack when it starts: the addresses of its boxes, of its raw pointers, of
its structs on the stack, and of its string locals. A function the C emitter
proves cannot allocate pushes none unless it builds a struct on the stack
([ADR 0003](adr/0003-stack-allocated-gc-structs-are-rooted.md)), and neither does
a function that only forwards its arguments to a call in tail position
([ADR 0106](adr/0106-a-tail-forwarder-pushes-no-frame.md)). A frame set up by
`main` holds the global slots, and the defer stack is a root too. A major also
scans the C stack conservatively, as a backstop for what no frame lists
([ADR 0008](adr/0008-precise-shadow-stack-with-conservative-backstops.md)).

**Moving objects.** A minor moves young objects, so a pointer must sit in a frame
across anything that may allocate. A foreign call is the exception: C may keep a
pointer into an array it was lent, and calls back into Vader may collect. Once a
Vader function's address has been handed to C, an array lent to C is first moved
to the old generation, which does not move, and so is a young buffer that a
slice shares ([ADR 0023](adr/0023-a-header-never-points-at-a-moved-buffer.md)).

The collector reads its settings and its diagnostics from the environment, at
start-up, in every build ([ADR 0002](adr/0002-gc-diagnostics-are-runtime-flags.md)):

| Variable | Effect |
|---|---|
| `VADER_GC_RAM_PERCENT` | the share of physical memory the old reservation is computed from, 50 by default |
| `VADER_GC_OLD_MAX` | the size of the old reservation, in bytes, in place of the share |
| `VADER_GC_YOUNG_BYTES`, `VADER_GC_YOUNG_CAP`, `VADER_GC_YOUNG_MAX`, `VADER_GC_YOUNG_RATIO` | the initial size of a semi-space, the ceiling of its adaptive growth, its hard limit, and the ratio that growth targets |
| `VADER_GC_STRESS` | a minor at every allocation |
| `VADER_GC_STRESS_MAJOR` | a major at every allocation: the only stress mode that collects atoms |
| `VADER_GC_CHECK_BOX` | traps on a box whose tag is out of range |
| `VADER_GC_POISON` | fills the abandoned semi-space after each minor |
| `VADER_GC_SCAN_ALL_OLD` | every card counts as dirty |
| `VADER_GC_NO_CSTACK_SCAN` | skips the conservative scan for objects, to find what only it keeps alive (the scan for atoms stays) |
| `VADER_GC_HISTOGRAM` | after a major, the old live set, whenever it reaches a new high |
| `VADER_GC_PROFILE`, `VADER_ALLOC_BY_TYPE`, `VADER_ATOM_PROFILE` | reports at exit: the live set by type, allocations by type, the atom table |

On the VM, `std/runtime` reports zero bytes: the program's values belong to the
host and its collector.

## Traps and defer

A failure at run time stops the program: one of the checks of SPEC §2, *Run-time
checks*, or a `panic`. Natively, `vader_trap` (`vader_panic` for a panic) prints
the message on stderr, runs the pending defers, and aborts the process
(`SIGABRT`). On the VM a trap is a value the interpreter returns: the pending
defers run, and `vader run` prints the message and exits with status 1. The
arithmetic traps print the same message on both. The VM also stops a call chain
deeper than 1024 frames and, at compile time, an evaluation that runs out of
steps.

An `unreachable` instruction, which the compiler also emits for a few failures at
run time, aborts natively without running the defers (`TODO.md`).

A program that returns from `main` exits with the `i32` it returned, or 0.

**The defer stack.** The closures a `defer` registers
([`ARCHITECTURE.md`](ARCHITECTURE.md), *Lowered AST*) live on one stack per
program: a global in the C runtime, a field of the machine on the VM, and a root
for the collector. An async function keeps its own in its frame, since the global
stack would mix the defers of coroutines suspended at the same time.

**The scheduler** behind `std/async` (SPEC §16) parks on the nearest deadline: in
real time natively, unless `VADER_ASYNC_VIRTUAL_CLOCK` is set, and on the VM by
jumping its clock to it. The order of its heap of deadlines decides what runs
next, so the output does not depend on the clock.

## What a backend provides

A backend runs the bytecode. The standard library is written in Vader over a
small set of primitives, which the code's comments call the Target ABI, so a
backend that provides them runs every program; a WASM backend, when one exists,
starts from this list.

**The opcode set**, `vader/core/bytecode/op.vader`:

- arithmetic in three classes: 32-bit integers, which every narrower integer
  type uses too; 64-bit integers; 64-bit floats, which `f32` uses too; and the
  checked `+`, `-` and `*` on integers;
- constants, locals and globals;
- calls: direct, to an import, through a function value, on a trait receiver;
- structs, unions, arrays, type tests, conversions, `defer`;
- structured control flow: blocks, loops, `if`, and branches out of an enclosing
  block.

**The representation of values** of the previous sections: boxes and their tags,
heap objects that a collector can trace, and the collector itself, which cannot
be written in Vader.

**Strings as atoms.** The atom table is a primitive of the backend. Over a
string's bytes the backend provides `byte_len`, `byte_at`, `byte_slice`,
`is_ascii`, the hash, `bytes()` and its inverse; equality and ordering are ops.
Everything else about strings is Vader: `len`, `s[i]` and `s[lo..<hi]` walk the
codepoints in `std/core/utf8.vader`
([ADR 0061](adr/0061-a-strings-codepoints-are-read-in-vader.md)).

**Byte buffers.** `Buffer` (`lib/std/core/buffer.vader`) is a GC object holding
bytes and no references. Its ops allocate one, read and write a byte, copy a
range, copy a string's bytes in, and intern a prefix as a string. Number
formatting, string concatenation (a `concat_N` function per number of pieces,
which the compiler writes), interpolation and `StringBuilder` are Vader over
these. The bytecode also has 32-bit, 64-bit and float reads and writes at a byte
offset, which nothing in the library calls yet.

**The host intrinsics** listed in `vader/core/bytecode/intrinsic_manifest.vader`:
the string functions above, the counters of `std/runtime`, the scheduler behind
`std/async`, `panic`, and the OS and architecture the process runs on. A few
entries only the VM serves: primitive equality and `Display`, which a native
build compiles as ops or Vader, and the VM's foreign calls. How both backends
keep up with the list is in [`ARCHITECTURE.md`](ARCHITECTURE.md), *Intrinsics*.
The program's arguments reach `main` through the runtime too.

**Foreign calls.** The platform is reached through `@extern` declarations
written in Vader, `lib/system/posix/`, `darwin/` and `windows/`, which `std/io`,
`std/process`, `std/time` and `std/tty` select with `@target`; `std/math` takes
`sqrt`, `pow` and the trigonometric functions from libm the same way. A native
build calls them as C functions. The VM calls them dynamically
(`runtime/c/vader_ffi.h`): it opens the library, looks the symbol up, and passes
the arguments through a trampoline per shape, or, for a signature no trampoline
covers, through a C adapter that `vader run` compiles beforehand. A few
accessors stay in the C runtime, for what a foreign call cannot express, such as
a member of a C struct or `errno`
([ADR 0013](adr/0013-what-the-ffi-boundary-cannot-express.md)).
