# 0173: An iterator hands its views out from where it is built

## Status

Accepted (2026-11-22). Extends 0067: the rules of a view of a string's bytes
reach the calls the compiler inserts, and the values an iterator hands out.

## Context

0067 recognises a view at the call that makes it: `bytes()`, or a function
found to return one. Only a call written in the source was looked at. A call
the compiler inserts went through the same summary, which saw what it did to
its arguments, but its result was never a view: a view returned by an `into`,
by the `next` a `for` calls, by an `Index` or by an operator could be written,
and the native build then wrote into a string's read-only bytes.

Treating those calls as the calls they are closes the hole for concrete code,
but not for generic code. A call through a trait is judged by every function it
may run, so one impl of `Iterator` whose `next` returns a view made every
generic body that keeps what it steps through an error: `collect`, written
`for x in it { out.push(x) }`, would no longer compile in a program that holds
such an iterator, whatever it collects. A `next` written by hand already did
this to `peekable`.

## Decision

- **Every call makes the view it returns**, written or inserted: an `into`, a
  `for`'s `next`, an `Index`, an operator. A conversion's value is judged at the
  type it converts to.
- **The `next` of `Iterator` makes no view.** It returns the part of its
  receiver an iterator hands out (`ITEM`), through the trait or through an impl.
  What a body does with that part is a fact on the parameter that holds the
  iterator: `collect` keeps the items of `it`.
- **An iterator whose `next` returns a view holds the views it hands out from
  where it is built**: a literal of its type, a generator that yields a view, a
  call of a function that returns such an iterator. The view is a root held at
  `ITEM` below the iterator, and it goes wherever the iterator goes. A write or a
  keep of what a step hands out is an error, wherever it happens: in a loop over
  the iterator, or in a function it is lent to, at the call that lends it.
- **A body that builds an iterator is walked again** once the `next` of its type
  is found to return a view, as a body that calls a view-returning function is.
- **Keeping the iterator itself keeps what it hands out**: a field or an element
  that holds it is an error. The summary takes a keep of a value as a keep of
  every part below it, which a constant an iterator walks needs.

## Consequences

- An iterator of integers is judged by its own `next`: a generic body is no
  longer refused because another impl of the program returns a view.
- The error names where the iterator is built (`Chunks { ... }`, `pieces()`),
  and lands on the write, the keep, or the call that lends it.
- An adapter that keeps its source in a field (`peekable`) is refused over an
  iterator of views, though it keeps the iterator, not a view.
- The calls through a trait other than `next` (`into`, `Index`, an operator on a
  trait value) are still judged by every impl.
- Not followed: an iterator of views built in a struct field's default. The
  initialisers are walked once, before any `next` is found to return a view, and
  are not walked again.
