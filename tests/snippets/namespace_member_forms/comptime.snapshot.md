# Comptime

## tests/snippets/namespace_member_forms

## tests/snippets/namespace_member_forms/helper

- `const GREETING = "hi"`, folded
- `const MAX_RETRIES = 3_i64`, folded
- `const Meters = i32`, folded

# Diagnostics

- `` [27:13] warning[W0016] the enum name adds nothing here — the slot already pins it, so the bare variant reads the same: write `.Red` ``
- `` [28:13] warning[W0016] the enum name adds nothing here — the slot already pins it, so the bare variant reads the same: write `.Green` ``
- `` [36:42] warning[W0016] the enum name adds nothing here — the slot already pins it, so the bare variant reads the same: write `.Blue` ``
