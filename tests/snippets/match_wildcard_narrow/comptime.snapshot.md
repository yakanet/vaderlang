# Comptime

## tests/snippets/match_wildcard_narrow

# Diagnostics

- `` [28:12] warning[W0005] wildcard arm on a closed union silences exhaustiveness checking ; enumerate the variants or mark the match `@partial`: wildcard arm on closed union `Cat | Dog | null` — enumerate its variants or mark the match `@partial` ``
- `` [41:12] warning[W0005] wildcard arm on a closed union silences exhaustiveness checking ; enumerate the variants or mark the match `@partial`: wildcard arm on closed union `Cat | Dog | null` — enumerate its variants or mark the match `@partial` ``
