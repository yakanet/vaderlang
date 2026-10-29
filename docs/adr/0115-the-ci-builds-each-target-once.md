# 0115: The CI builds each target once

## Status

Accepted (2026-10-29). Amends ADR 0006: the fixed-point gate still runs on every
push, as a step of the Linux job.

## Context

On the push of `bc586b78b`, Linux built the same compiler from the seed three
times, about 2 min 20 each: in the test job, in the fixed-point job (`verify.sh`
starts with `build.sh`), and in the separate `Docs` workflow. On a tag, the bundle
jobs built it once more per OS. Those bundle jobs ran only on a tag or a manual
run, so their first real test would have been the first release; a manual run on
2026-10-29 (run 40848742995) was in fact their first.

A job that `needs` a matrix waits for every leg of it: GitHub offers no dependency
on a single leg.

The Linux bundle was built on `ubuntu-22.04` for its old glibc. That image is
deprecated: brownouts in March and April 2027, retirement on 2027-04-17. But a
binary needs the newest glibc symbol version it calls, not the glibc it was
linked on. Built on Ubuntu 26.04 (glibc 2.43, gcc 15.2), `vader` needed
`GLIBC_2.38`, and only through three runtime calls, `strtoul`, `strtoull` and
`fscanf`: the `_GNU_SOURCE` the runtime took from `vader.h` also turns on
glibc's C23 bindings, which resolve them to `__isoc23_*` symbols from glibc 2.38
on. Without those it needs 2.34.

## Decision

- One workflow, `build.yml`; `docs.yml` goes.
- One matrix leg per target builds the compiler once (`verify.sh --dist` on
  Linux, which checks the fixed point on that build; `build.sh --dist`;
  `build.ps1 -Dist`), runs hello world with the bundle away from the checkout,
  and uploads the archive: a composite action, `.github/actions/bundle`. The
  same leg then runs the suite (Linux, Windows), so a target's tests start as
  soon as its compiler exists. Three jobs per target joined by YAML anchors
  would give the same order, plus an artifact transfer before each suite.
- macOS builds and bundles, without the suite: it runs locally on macOS before
  each push.
- Linux runs on `ubuntu-26.04`, so the suite compiles the emitted C with the
  newest gcc. The runtime compiles under `_DEFAULT_SOURCE` and declares the one
  GNU function it calls (`pthread_getattr_np`); emitted code keeps
  `_GNU_SOURCE`. A step fails when the binary needs a glibc newer than 2.34.
- The site is built from the Linux bundle once every leg is green, and published
  from `main` by the run whose commit is still the head of `main`. Runs of `main`
  no longer cancel each other: every push gets its fixed point and its suites.

## Consequences

- One build per target and per push, instead of three on Linux.
- Linux becomes the critical path, about 13 min with the fixed point; the site
  goes out about 14 min after a push, instead of about 3 min 30.
- The download page states glibc 2.34 or later: Ubuntu 22.04, Debian 12, RHEL 9.
- A fixed-point failure turns the Linux build step red and skips that leg's
  bundle; the suite still runs on the compiler it built.
