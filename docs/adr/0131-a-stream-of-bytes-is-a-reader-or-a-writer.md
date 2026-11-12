# 0131: A stream of bytes is a `Reader` or a `Writer`, and a buffer is a struct set on it

## Status

Accepted (2026-11-12).

## Context

Each source of bytes had its own reads and its own buffer. A `File` returned an
array, empty at the end, read ahead in a private buffer, and kept the error of
its `lines` in a field. `std/console` returned strings and said the end with an
`IOError` of kind `.EndOfInput`. The pipes of a child were read a third way.
Nothing let one piece of code read a line or an exact count from a file, a
socket and an array in memory alike, which a protocol parser and its tests
need.

## Decision

- **Two traits of one method** (`std/io`). `Reader.read(into: u8[])` fills room
  the caller lends: a slice writes its parent (0108), so a buffer reads into its
  own tail with no copy. `Writer.write(content: u8[] | string)` writes all of
  `content`, waiting as long as it takes.
- **The end of a source is `null`.** `read` gives a count of at least 1, `null`
  at the end, or an `IOError`; 0 only for an empty `into`. An end that comes too
  early (`read_exact`) is an `IOError` of kind `.EndOfInput`.
- **A read gives bytes, never a string.** A read stops anywhere, inside a code
  point included, and only the caller knows the stream is text. Strings come
  from the buffered reader, where the boundary is known (`read_line`).
- **The buffer is a concrete struct**, `BufferedReader` or `BufferedWriter`, set
  on any `Reader` or `Writer`. What reading a text or a protocol needs
  (`read_line`, `lines`, `read_until`, `read_exact`, `read_to_end`, `peek`) is
  written once, on the struct, and the trait is called once per refill.
- **Every read that grows is bounded**: a line and a run by a `max`, `peek` by
  the capacity of the buffer, which does not grow.
- **Nothing flushes for the program**: `flush` is called, before the close of
  what the writer writes to. A trait has neither `flush` nor `close`.
- **A `File` is the handle alone**: it implements both traits, keeps one
  position, and asks the system at each call. A file read through a buffer is
  not sought or written directly: the buffer has read ahead.
- **In-memory streams are exported** (`BytesReader`, `BytesWriter`,
  `FragmentedReader`, `FailingReader`, `FailingWriter`): a parser is tested with
  its source whole, then cut at every byte.
- **A stream has one task at a time.** A call through a trait counts the effects
  of every impl of the program, so the task check refuses a `Writer` written by
  two tasks, and a read through a trait under a lock once some impl parks.
  Tasks that write one destination send to the task that owns it. An impl hands
  back nothing it keeps, an error it stores included.

Set aside:

- **A read that returns an array** (`read(max) -> u8[]`): an allocation and a
  copy per read, and nothing to look ahead with.
- **One large trait** with `read_line` and the rest as default methods: every
  source would carry a buffer, and every call would go through the trait.
- **The end as a count of 0**, as POSIX has it: a loop that forgets the test
  spins. **The end as `.EndOfInput` everywhere**: every loop would read the kind
  of an error to tell the end from a failure.
- **Two types of file by mode**, or adapters (`f.reader()`): a file open for
  both and sought needs a third type, and two adapters are two positions.
- **A generic buffer** (`BufferedReader<S: Reader>`): the task check would see
  the effects of the one source, but every signature that takes a reader would
  carry the type parameter.
- **`write` and `write_text`**: two names where a union takes both.

## Consequences

- `File` loses `read(max)`, `lines`, its `error` field and
  `OpenOptions.buffer_size`.
- `std/console` and the pipes of `std/process` keep their own reads: a buffer on
  stdin would take what the next read, or a child, expects to find there.
- A `Writer` shared by several tasks goes through a `Channel`.
