# 0073: A type is told apart by its identity, without interning

## Status

Accepted (2026-10-18). Step 5 of the type-system charter (D2, choice F7). Closes the
step.

## Context

The charter asked for one identity per type: keys built from a nominal type's
symbol rather than its printed name, then, if it paid, interning (one instance per
type, compared by id). Five ways of turning a type into a string were counted, and
the cost of rendering, keying and comparing types was measured at 8 to 10 % of a
build.

Looked at again on 2026-10-18:

- The five schemes do not all key identity. `display_type` renders a type for a
  reader; `qualified_display_type` and `mangle_type_arg` name instances in the
  emitted code; `type_intern_key` keys the bytecode's type table, where an enum is
  its integer and a distinct its backing, so it keys a representation. Only
  `canonical_key` and the comptime's instance key keyed identity, the second one
  modulo distincts.
- Instance names already carry the module of every nominal argument
  (`qualified_display_type`), so `Box<pa.Point>` and `Box<pb.Point>` no longer
  share one.
- Places still told types apart by their printed name or their bare name:
  - the order of a union's variants: two same-named types of two modules kept the
    order they arrived in;
  - the impl tables' key for a tuple, a fn or a union target (`impl_base_key`): the
    impls of one trait on `[pa.Point, i32]` and `[pb.Point, i32]` were ambiguous
    (T3032);
  - an impl member's name on a tuple, a fn or a union target, `()` for every tuple
    and nothing for the others: the impls of one trait on `[i32, i32]` and
    `[string, i32]`, on `[i32, i32]` and `[BlockId, i32]` over a distinct, on
    `fn(i32) -> i32` and `fn(string) -> i32`, shared one name, and one ran for both
    without a diagnostic;
  - core's `Range` recognised by its name: a struct of the program named `Range`
    passed as a slice index, and the build stopped in the backend;
  - the comparison of two tuple carriers in the midir, and the dedup of erased
    union variants in the lowering.
- The comptime's instance key was a second copy of `canonical_key`, distincts keyed
  as their backing.
- Sampling a self-build (`vader build vader/tools/cli/main.vader`, three runs, 1 ms
  interval): rendering, keying and comparing types take 40 to 60 samples of about
  2 300 on the CPU, 2 to 2.5 %. The garbage collector takes about 40 %.

## Decision

- **Identity is `canonical_key` and `equals_type`, by symbol id.** The impl tables
  key a tuple, a fn or a union target by `canonical_key`, and a concrete one names
  its impl members by its module-qualified shape, distincts kept; core's `Range` is
  told by its declared module and name (`is_core_struct`). Tuple carriers compare with `equals_type`, erased union variants dedup by
  `canonical_key`, and the comptime's instance key is `canonical_key` of the
  arguments with their distincts stripped.
- **A union sorts its variants by their printed name**, which keeps diagnostics
  readable; two that print alike by their module-qualified name, which stays the
  same across edits where symbol ids do not, then by `canonical_key`.
- **The other keys stay, each for its own job**: a printed name for readers, a
  qualified name for instances, a representation key for the bytecode's type table.
- **No interning.** At 2 % of a build, it would not pay for a change that touches
  every `match` on a type.

## Consequences

- A union's variant order no longer depends on the order its variants were met.
- Left as they are, named here so the next reader does not take them for identity
  keys by accident, and tracked in `TODO.md`:
  - `fn_instance_key` dedups a generic function's instances by the symbol id and
    the arguments' module-qualified names, which also orders their emission;
  - the C backend's `type_index_for_name` looks a baked array's element type up by
    its printed name against mangled struct names, a lookup that does not match a
    struct declared in a module;
  - `strip_distinct` rebuilds a union without normalising it, so a stripped union
    can key apart from the same union written without distincts;
  - `equals_type` holds the struct placeholder of an enum equal to the enum, which
    `canonical_key` keys apart;
  - `trait_key_of` keys a trait by its mangled module and name, and `mangle_module_id`
    turns `/` into `_`: two traits `Shout` of `main/x_y` and `main/x/y` count as one.
    The same goes for every key built on a mangled module id; refusing two loaded
    modules whose ids mangle alike would make them all sound.
- The 8 to 10 % measured at `460123991` is not found again at `01969767e`. Its
  largest single source, a comparison of printed names in `match_expr.vader`, has
  become `equals_type` since (`80c403bb6`). What a build spends now goes to the
  allocation the collector handles.
