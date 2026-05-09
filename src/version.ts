// Single source of truth for compiler-wide versioning.
//
// Two independent version axes are tracked here :
//
//   * `CLI_VERSION` — surfaced by `vader --version`. Semantic-version string ;
//     bumped whenever the user-facing CLI / language behaviour changes
//     in a way users would notice.
//
//   * `BYTECODE_VERSION` — packed into the binary `.vir` header (`major<<16
//     | minor<<8 | patch`). Bumped every time the wire format changes ;
//     readers reject any other value with a clear diagnostic. No backwards
//     compatibility is supported pre-1.0 — bump the patch byte for any
//     additive change, the minor byte for incompatible-yet-evolutionary
//     changes, and the major byte at 1.0 freeze.
//
// The two axes evolve independently : a CLI bump that doesn't touch the
// bytecode (e.g. a new `--target` flag) leaves `BYTECODE_VERSION` alone,
// and vice versa.

export const CLI_VERSION = "0.0.0-pre-mvp";

export const BYTECODE_VERSION_MAJOR = 0;
export const BYTECODE_VERSION_MINOR = 1;
export const BYTECODE_VERSION_PATCH = 0;

export const BYTECODE_VERSION =
  (BYTECODE_VERSION_MAJOR << 16) |
  (BYTECODE_VERSION_MINOR << 8) |
  BYTECODE_VERSION_PATCH;

export function formatBytecodeVersion(v: number): string {
  return `${(v >>> 16) & 0xFF}.${(v >>> 8) & 0xFF}.${v & 0xFF}`;
}
