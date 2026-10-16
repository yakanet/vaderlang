# Comptime

## tests/snippets/vm_trait_dispatch

# Diagnostics

- `` [34:5] warning[W0005] wildcard arm on a closed union silences exhaustiveness checking ; enumerate the variants or mark the match `@partial`: wildcard arm on closed union `Cat | Dog` — enumerate its variants or mark the match `@partial` ``
- `` [41:5] warning[W0005] wildcard arm on a closed union silences exhaustiveness checking ; enumerate the variants or mark the match `@partial`: wildcard arm on closed union `Cat | Wrapper<i32>` — enumerate its variants or mark the match `@partial` ``
