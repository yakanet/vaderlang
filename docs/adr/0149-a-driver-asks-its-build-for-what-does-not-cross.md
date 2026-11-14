# 0149: A driver asks its build for what does not cross

## Status

Accepted (2026-11-14). Opens the questions that
[0145](0145-a-build-driver-is-a-thin-client-that-re-reads-the-sources.md) left
for later; the first one is the vaderdoc of a node.

## Context

A driver receives the surface of each declaration
([0147](0147-a-driver-is-handed-the-surface-of-the-elaborated-declarations.md)),
opened a little at a time. The vaderdoc was next, and a build does not keep it:
only `vader doc` and the language server parse with the `///` comments.

Three ways were weighed: a driven build always keeps the vaderdoc and sends it
with every declaration; the driver declares in its configuration that it wants
it; the driver asks for the vaderdoc of a node when it needs it. Measured on
2026-11-14: parsing `lib/` with the comments takes as long as without (26 ms
against 26 ms, 78 ms against 76 ms for `vader/`), and the whole vaderdoc of
`lib/` weighs 358 KB.

## Decision

- **A driver asks; `vader` answers at once.** A question is a request among the
  others, sent while the stream is open; `vader` answers it before it reads the
  next request, so the exchange stays in lock step. A driver that receives
  anything else than its answer lost its build: the stream ends on a failure.
- **The first question is the vaderdoc of a node**, named by its span: a
  declaration, a field, a variant or a member the driver received. The span is
  the same on both sides, and every node that crosses has one.
- **A driven build loads with the vaderdoc**, and answers from the files it
  delivered, each version an entry was sent: a node the driver did not receive
  has no answer.
- **One function per kind of node** (`doc_of`, `doc_of_field`,
  `doc_of_variant`): overloads are chosen by their first parameter, here the
  context, so they cannot tell a field from a variant.
- Before the stream is pulled, no build is there to answer: the answer is null.

## Consequences

A plugin pays for what it reads, one round trip per node, and nothing crosses
for a plugin that never asks. The build keeps the files it delivered, their
text and tree, until it ends. The typed view (the type of an expression, the
callee of a call) can take the same path: a question, named by a span, answered
from what the build holds.

A driver whose build is older than its `lib/toolchain` hears a refusal for a
question that build does not know; the fingerprint of the contract
([0148](0148-vader-serves-a-driver-process-one-build-at-a-time.md)) is read from
the disk and does not see it.
