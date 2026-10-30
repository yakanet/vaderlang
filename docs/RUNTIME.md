# Runtime

How a running Vader program holds its values and its memory, and what a backend
must provide to run one. [`SPEC.md`](../SPEC.md) describes the language and
[`ARCHITECTURE.md`](ARCHITECTURE.md) the compiler; this document covers the
implementation, which may change without the language changing.

A program runs in one of two ways:

- **natively**: the C emitter writes C, and `cc` links it with the C runtime of
  `runtime/c/` (`vader.h`, `vader_runtime.c`);
- **on the VM** (`vader/vm/`), for `vader run`, `vader test` and the `@comptime`
  declarations the comptime interpreter cannot evaluate.

Both start from the same bytecode, which the VM translates to register code when it
loads a module
([ADR 0024](adr/0024-the-vm-runs-register-code-translated-at-load.md)).

The VM is itself a natively compiled Vader program: its values and its memory are
the host program's, with no heap and no collector of its own.

The C layouts below are excerpts of `runtime/c/vader.h`, the authority.

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

A generic instance follows the table with its type arguments substituted, except
that in a mixed or an erased instance a type parameter bound to a reference type
is erased to a box ([`ARCHITECTURE.md`](ARCHITECTURE.md), *Instance flavors*).

An enum with variant data stores its variant's **rank**, 0, 1, 2, ... in
declaration order, at the width SPEC §4 *Variant data* gives it. Its data is a
read-only array in the data pool (*Globals and constants*), one element per rank,
which `v.field` indexes. Only a conversion to an integer reads the written values
(`= 404`): it folds a constant rank, adds the first value to the rank when the
values are consecutive, and otherwise indexes a second table.

On the VM, an unsigned integer up to 32 bits rides in its `I32Val` as its bits. A
value of 8 or 16 bits is narrowed where it is stored (a local, a field, a return),
an unsigned one reinterpreted where it is printed or widened.

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

Its 16 bytes travel in two registers
([ADR 0018](adr/0018-a-box-was-24-bytes-for-a-payload-nothing-writes.md)). The
payload holds a scalar widened to 64 bits (an `f32` as a `double`), a string's atom
id, or a pointer to an object.

The **tag** is the index, in the module's type table, of the value's own type (the
concrete struct, the integer type), never of the union it sits in. Index 0 is
reserved for `null`, whatever the slot's type. An object's
header carries the same index (*Objects*), so a pointer taken out of a box gets its
tag back; a scalar gets its tag from its own type where it enters a boxed slot (the
`retag` op,
[ADR 0098](adr/0098-a-scalar-entering-any-boxed-slot-is-tagged-by-its-type.md)).

`x is T` compares the tag with the index of `T`, `x is A | B` with each. A test
against a trait accepts the index of every type that implements it: for a struct,
every instance of a declaration with an impl of the trait, whatever its type
arguments, without checking the impl's bounds. And `is f32` and `is f64`
both accept either tag. `TODO.md` lists both as bugs.

An enum, an integer range type and a distinct type have no index of their own: a
box holds an enum or a range under its integer's index, a distinct under its
backing's (over a struct, an array, a tuple or a function, a distinct is the
backing's object, header included). So `is` could not tell
`Color` from `u8` in a `Color | u8`, a union SPEC §4 *Unions* rejects, and a trait
call on such a box reaches the representation's impl, the type's own impl only
when the representation has none.

On the VM, a union slot holds the member's own `Value`, whose variant is the tag;
the native build of the VM stores a scalar `Value` without allocating
([ADR 0025](adr/0025-a-vm-scalar-rides-in-its-box.md)). That tag is coarser than the
native one (one `I32Val` for any integer up to 32 bits, `retag` ignored), so a test
on a union of integer widths can answer differently (`TODO.md`). A
struct or an array is tested by the index it carries.

## Strings

A string is an **atom**: a 32-bit index into a table holding every string of the
program once ([ADR 0109](adr/0109-a-string-is-an-atom.md)).

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

Every string the program makes is looked up when complete (concatenation and
`StringBuilder` assemble the bytes in a `Buffer` first), so two strings with
the same bytes are the same atom:

- `==` compares two integers;
- the hash is read from the entry;
- ordering compares the bytes, which is codepoint order for UTF-8.

**Owners and slices.** An atom that owns its bytes keeps them outside the GC heap,
in its own buffer, followed by a NUL byte. A slice (`byte_slice`, and the
codepoint slices built on it) points into its owner's bytes, copying nothing, and
keeps the owner alive; a slice of a slice points into the same owner, and a slice
covering its whole owner is the owner itself.

**Literals.** The C emitter writes the program's string literals into a table in
`.rodata`, which `main` loads at start-up: atom 0 is the empty string, atoms 1 to
*n* the other literals, and a literal in the code is its number. These atoms are
flagged `PERM` and never collected.

**ASCII.** An atom whose bytes are all below 0x80 is flagged `ASCII` when
created; `len`, `s[i]` and `s[lo..<hi]` then index its bytes instead of walking
its codepoints ([ADR 0065](adr/0065-an-ascii-string-is-indexed-by-its-bytes.md)).

**Collection.** Only a major collection collects atoms (*Memory*): every atom a
root, an object or the C stack can reach is marked, and every other atom not
flagged `PERM` loses its bytes, its index going on a free list for the next atom.
Indices are never compacted, so the table never shrinks.

**C strings.** An `@extern` parameter of type `string` receives the owner's
bytes as they are, or, for a slice, a NUL-terminated copy freed after the call. A
`string` result is interned like any new string before those copies are freed.
What C may do with these pointers is in SPEC
§13 *Allowed signature types*.

On the VM, a string, being the host's, is an atom of the VM's own process: `==`,
the hash and the order agree with a native build.

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
array, function), its size, the offsets of the fields the collector visits in
three lists (boxes, raw pointers to objects, strings), and the width of a slot of
that type, which `@size_of` answers for a type known only at run time.

**A struct** is the header followed by its fields, in declaration order, each in
the representation *Values* gives its type.

**A struct with no field** is one object per type, baked in the data pool
(*Globals and constants*), which every literal of it reads. Two exceptions
allocate at each literal: a generic struct, and a struct that a `===` or `!==` of
the program may compare, since it tells two literals apart
([ADR 0121](adr/0121-a-struct-with-no-field-is-shared-unless-compared-by-identity.md)).

**A tuple** is a struct the compiler declares for its shape, `__Tuple_<shape>`,
with fields `_0`, `_1`, ... A function returning a small tuple of scalars
(16 bytes at most), or an `S | null` of a small struct of scalars, may return its
elements separately, through out-parameters in C
([`MID_IR.md`](MID_IR.md)).

**A cell** holds a local that a closure captures and an assignment rebinds: a
struct `$Cell_<T>` with one field, `value`
([ADR 0030](adr/0030-a-capture-nothing-rebinds-is-copied-into-the-closure.md)).

**A struct on the stack.** In a native build, a struct that escape analysis proves
cannot outlive the function building it is a local of its C type, its header
initialised like any other. It never moves; the collector visits its fields
through the function's frame
(*Memory*, [ADR 0003](adr/0003-stack-allocated-gc-structs-are-rooted.md)).

On the VM, a struct, a tuple and a cell are each a `StructVal`: the type index and
one `Value` per field, in order.

## Arrays and views

A native array is two objects: a header, which a `T[]` slot points at, and a
buffer holding the elements. A new array allocates both as one block; a `push` that
outgrows the buffer allocates a larger one and points the header at it.

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

- **packed**, for an element of a primitive type: each element at its own width (a
  `u32[64]` in 256 bytes, a `bool` in a byte), all sharing the tag `element_tag`,
  which a read stamps on the value when it has to box it;
- **raw pointers** (`REF`), for an element whose every value is an object or `null`
  (a struct, an array, a function, or a union of those, like `Expr[]`): a read that
  needs a box takes the tag from the object's header;
- **boxed**, for everything else: strings, unions holding a scalar, trait values.
  An array built by erased generic code is boxed too, whatever its element type, as
  is an array of structs in the data pool, so a read checks the buffer's kind
  rather than assume it.

**A repeated array**, `[...] * n`, is one block with a capacity of `n` times the
literal's length, and at least `n` and 4, so `[] * n` is an empty array whose
first `n` pushes do not reallocate. Its slots past the length stay uninitialised
until a push writes them: the collector reads a buffer's slots only up to its own
`length`.

**A slice** `arr[r]` is a second header over the same buffer, with its own
`offset` and `length`. A write through it reaches the parent, while its first push
detaches it into a buffer of its own, since a slice is created with a capacity
equal to its length
([ADR 0108](adr/0108-a-slice-shares-its-parents-buffer-and-a-push-detaches-it.md)).
Slicing marks a young buffer as shared, for the foreign-call path (*Memory*).

**The bytes of a string**, `s.bytes()`, are a header with no buffer, flagged
*borrowed*, that reads the string's interned bytes in place; its `capacity` field
holds the string's atom id and the `u8` tag. The
language forbids writing it (SPEC §5, *Frozen values*).

An index is checked against `length` before every access; a release build drops
the checks the range analysis proves useless
([ADR 0058](adr/0058-a-release-build-drops-the-index-checks-the-range-analysis-proves.md)).

On the VM, an `ArrayVal` holds its elements as an array of `Value`, always boxed,
with `offset` and `length` for a view; a push detaches a view first, a write
reaches the parent. `s.bytes()` gives an `ArrayVal` whose `raw` field holds the
string, read in place
([ADR 0029](adr/0029-the-vm-reads-a-strings-bytes-in-place.md)).

A slice of the whole array breaks these rules, on the VM and natively (`TODO.md`).

## Functions and closures

A function value is an object: the header, then two pointers.

```c
typedef struct { vader_obj_header_t header; void* code; void* env; } vader_fn_t;
```

`code` takes the environment, then every other argument as a box, and returns a
box. A function used as a value gets a static `vader_fn_t` with no environment,
whose `code` is a trampoline that drops the environment, unboxes the arguments,
calls the function and boxes its result.

**A closure** is a `vader_fn_t` whose `env` points at a struct the compiler
declares for it, one field per captured local, `cap_0`, `cap_1`, ... A local
nothing rebinds after the capture is copied into the environment; one an
assignment rebinds lives in a cell (*Objects*). A lambda that captures nothing is
a plain function value. The environment always lives on the heap.

**A trait call** on a trait value or on the receiver of an erased instance goes
through a dispatcher the C emitter writes per trait method: a `switch` on the
receiver's tag, one case per implementing type, which unboxes the arguments and
calls that type's impl member. The result comes back unboxed unless the
implementations disagree on its type. A tag no case covers ends the program
(`vtable miss`).

On the VM, a function value is a `FnVal`: the function's index in the module and
its environment, which a call through it puts in the callee's first register. A
trait call looks up the receiver's type index in the module's vtable rows.
`fn.addr`, the address of a function handed to C, has no meaning there and traps.

## Globals and constants

A program's only global slots are those the compiler adds: for `@singleton`, a
state and the instance it built, per singleton; for a constant whose value calls a
function, whether that value is being computed. Natively each is a C global,
zero-initialised, rooted by a frame `main` installs (*Memory*); on the VM they
are an array of `Value`.

A module constant has no storage at run time:

- a scalar is folded into the code;
- an array or a struct the compiler can build at compile time is baked into the
  **data pool**: in C, a `const` static (header, buffer and elements) outside the
  heap, which the collector treats as immortal; on the VM, a value
  built once when the module loads. A struct is baked as a one-element array, and
  only when the constant is declared at the struct's own type;
- a value that calls a function becomes a function, `__const_<name>`, that
  builds it and stops the program if the constant is read again before it
  returns, which only a function the value calls can do
  ([ADR 0119](adr/0119-a-constant-read-while-its-value-is-computed-stops-the-program.md));
- a large array the compiler cannot bake becomes such a function too, without the
  stop;
- anything else is rebuilt where it is read.

Every read of a baked constant shares that one value, except a read whose value a
write could reach: one that is stored, returned, handed to a function value, or
bound to a name that is written. Such a read gets a fresh value from an accessor
function, unless nothing in the program writes a value of a type it can reach.

## Memory

A native build uses a generational collector: objects are born in a young
generation collected often, and the survivors move to an old generation collected
rarely
([ADR 0007](adr/0007-generational-gc-copying-young-non-moving-old.md)). The sizes
below are the defaults of `runtime/c/vader.h`.

- **Young** is a pair of semi-spaces, 32 MB each to start with, where allocation
  bumps a pointer. A **minor** collection copies every live young object into the
  old generation at its first collection
  ([ADR 0104](adr/0104-a-young-survivor-is-promoted-at-its-first-collection.md)),
  and leaves it young only when the old generation is full. Young grows to fit an
  object larger than a semi-space (up to 2 GB), and with the old live set (up to
  192 MB).
- **Old** is one address-space reservation, committed as it fills: half the
  machine's memory by default, less what young may take, kept between 256 MB and
  4 GB. It never moves an object: objects up to 1 KB take a slot of their size
  class, larger ones a region of their own.
- **The card table** records the old objects a pointer was written into, one
  byte per 512 bytes of old space. The C emitter writes the barrier after every
  store of a pointer into an object, and a minor visits only the dirty cards, not
  the whole old generation
  ([ADR 0105](adr/0105-a-major-leaves-the-card-table-as-its-minor-left-it.md)).

**Collections.** A **major** marks what is live in the old generation and frees
the rest in place. It runs after a minor once the old generation holds one and a
half times what the last major left, and at least 64 MB; when a minor cannot make
room for an allocation; and when `std/runtime.collect()` asks. It starts with a
minor and ends by collecting the atoms.

**Roots.** A function whose locals must survive a collection pushes a frame on a
shadow stack when it starts: the addresses of its boxes, raw pointers, structs on
the stack and string locals. A function the C emitter proves cannot allocate
pushes none unless it builds a struct on the stack
([ADR 0003](adr/0003-stack-allocated-gc-structs-are-rooted.md)), nor does a
function that only forwards its arguments to a call in tail position
([ADR 0106](adr/0106-a-tail-forwarder-pushes-no-frame.md)). The global slots and
the defer stack are roots too. A major also scans the
C stack conservatively, as a backstop for what no frame lists
([ADR 0008](adr/0008-precise-shadow-stack-with-conservative-backstops.md)).

**Moving objects.** A minor moves young objects, so a pointer must sit in a frame
across anything that may allocate. A foreign call is the exception: C may keep a
pointer into an array it was lent, and calls back into Vader may collect. Once a
Vader function's address has been handed to C, an array lent to C is first moved
to the old generation, which does not move, and so is a young buffer that a slice
shares ([ADR 0023](adr/0023-a-header-never-points-at-a-moved-buffer.md)).

The collector reads its settings and diagnostics from the environment at start-up,
in every build ([ADR 0002](adr/0002-gc-diagnostics-are-runtime-flags.md)):

| Variable | Effect |
|---|---|
| `VADER_GC_RAM_PERCENT` | the share of physical memory the old reservation is computed from |
| `VADER_GC_OLD_MAX` | the old reservation's size in bytes, in place of the share |
| `VADER_GC_YOUNG_BYTES`, `VADER_GC_YOUNG_CAP`, `VADER_GC_YOUNG_MAX`, `VADER_GC_YOUNG_RATIO` | a semi-space's initial size, adaptive-growth ceiling and hard limit, and the ratio that growth targets |
| `VADER_GC_STRESS` | a minor at every allocation |
| `VADER_GC_STRESS_MAJOR` | a major at every allocation |
| `VADER_GC_CHECK_BOX` | traps on a box whose tag is out of range |
| `VADER_GC_POISON` | fills the abandoned semi-space after each minor |
| `VADER_GC_SCAN_ALL_OLD` | every card counts as dirty |
| `VADER_GC_NO_CSTACK_SCAN` | skips the conservative scan for objects (not atoms), to find what only it keeps alive |
| `VADER_GC_HISTOGRAM` | the old live set after a major, at each new high |
| `VADER_GC_PROFILE`, `VADER_ALLOC_BY_TYPE`, `VADER_ATOM_PROFILE` | reports at exit: the live set by type, allocations by type, the atom table |

On the VM, `std/runtime` reports zero bytes: the program's values belong to the
host and its collector.

## Traps and defer

A failed run-time check (SPEC §2 *Run-time checks*) or a `panic` stops the
program. Natively, `vader_trap` (`vader_panic` for a panic) prints
the message on stderr, runs the pending defers, and aborts the process
(`SIGABRT`). On the VM a trap is a value the interpreter returns: the pending
defers run, and `vader run` prints the message and exits with status 1. The
arithmetic traps print the same message on both. The VM also stops a call chain
deeper than 1024 frames and, at compile time, an evaluation that runs out of
steps.

An `unreachable` instruction, which the compiler also emits for a few failures at
run time, aborts natively without running the defers (`TODO.md`).

The `i32` that `main` returns is the exit status (SPEC §6 *`main` entry point*).

**The defer stack.** The closures a `defer` registers
([`ARCHITECTURE.md`](ARCHITECTURE.md), *Lowered AST*) live on one stack per
program, a global in the C runtime and a field of the machine on the VM; an async
function keeps its own in its frame.

**The scheduler** behind `std/async` (SPEC §16) parks on the nearest deadline: in
real time natively, by jumping its clock to it on the VM or when
`VADER_ASYNC_VIRTUAL_CLOCK` is set. The order of its heap of deadlines decides
what runs next, so the output does not depend on the clock.

## What a backend provides

The standard library is written in Vader over a small set of primitives, which the
code's comments call the Target ABI, so a backend that provides them runs every
program; a WASM backend, when one exists, starts from this list.

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
bytes and no references, whose ops allocate one, read and write a byte, copy a
range, copy a string's bytes in, and intern a prefix as a string. Number
formatting, string concatenation (a `concat_N` function per number of pieces,
which the compiler writes), interpolation and `StringBuilder` are Vader over
these. The bytecode also has 32-bit, 64-bit and float reads and writes at a byte
offset, which nothing in the library calls yet.

**The host intrinsics** listed in `vader/core/bytecode/intrinsic_manifest.vader`:
the string functions above, the counters of `std/runtime`, the scheduler behind
`std/async`, `panic`, and the OS and architecture the process runs on. A few
entries only the VM serves: primitive equality and `Display`, which a native
build compiles as ops or Vader, and the VM's foreign calls. [`ARCHITECTURE.md`](ARCHITECTURE.md)
*Intrinsics* says how both backends keep up with the list. The program's arguments
reach `main` through the runtime too.

**Foreign calls.** The platform is reached through `@extern` declarations
written in Vader, `lib/system/posix/`, `darwin/` and `windows/`, which `std/io`,
`std/process`, `std/time` and `std/tty` select with `@target`; `std/math` takes
`sqrt`, `pow` and the trigonometric functions from libm the same way. How each
backend calls them is in [`ARCHITECTURE.md`](ARCHITECTURE.md), *Foreign calls*. A
few accessors stay in the C runtime, for what a foreign call cannot express, such
as a member of a C struct or `errno`
([ADR 0013](adr/0013-what-the-ffi-boundary-cannot-express.md)).
