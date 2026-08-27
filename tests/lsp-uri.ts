// tests/lsp-uri — build a `file://` URI the way the SERVER does.
//
// Mirrors `vader/lsp/protocol/uri.vader::path_to_uri`: forward-slash the path, and
// give a Windows drive path (`C:\…`) the extra leading slash so it becomes
// `file:///C:/…`. On POSIX the path already starts with `/`, so this is
// byte-identical to a naive `file://${p}` — which is why the naive form survives
// review on macOS and Linux and only ever breaks on Windows.
//
// It exists because two suites need it and the second one to need it re-typed the
// naive form at four sites. `file://C:\…` is malformed: `uri_to_path` leaves the
// `\` separators in place while the loader normalises spans to `/` (`to_posix`),
// so path-dependent behaviour silently takes the wrong branch. Observed twice —
// the publish filter dropped every diagnostic and the server looked silent, and
// the project-root probe was skipped so a shipped namespace outranked the
// project's own module of the same name.
//
// NOT `pathToFileURL` from `node:url`: that percent-encodes, so it would diverge
// from what the server itself produces, which is the thing under test.

/** `file://` URI for `p`, matching the server's `path_to_uri` byte for byte. */
export function pathToUri(p: string): string {
  const posix = p.replace(/\\/g, "/");
  return posix.startsWith("/") ? `file://${posix}` : `file:///${posix}`;
}
