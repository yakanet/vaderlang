# 0112: A module constant cannot call a singleton

## Status

Accepted (2026-10-25). Amends 0068, which left the case open.

## Context

A module constant initialised by a singleton, `TABLE :: names()`, cannot be
folded, so it was evaluated again at each read: it changed with the instance.
Copying the instance once was the first answer, but the language has no deep
copy. The copy a name bound to a frozen constant holds is made by evaluating the
initialiser again, which for `names()` is the live instance: even `x :: TABLE`
aliased it.

## Decision

A direct call to a singleton in a module constant's initialiser is T3119. A
lambda the constant holds may call one, since it runs only when called. A call
through an intermediate function (`T :: get()`, where `get` calls `names()`) is
not seen.

## Consequences

- Set aside: a structural deep copy generated per type, a large piece of work,
  and a copy through `Clone`, only as deep as the type's `clone` (an array's is
  shallow).
- Seeing a call through an intermediate would take the effect summary carrying
  "returns a singleton's instance" to its callers.
