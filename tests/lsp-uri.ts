// tests/lsp-uri: build a `file://` URI the way the SERVER does.
//
// Mirrors `to_uri` in `lib/std/uri/uri.vader`, by which the server keys its
// documents: forward-slash the path, give a Windows drive path (`C:\...`) a
// leading slash and its letter in lower case (`file:///c:/...`), and
// percent-encode every byte a URI path does not take. The server makes every
// URI it receives canonical and answers with that spelling, so a test that
// compares a URI it reads back builds the same one.
//
// NOT `pathToFileURL` from `node:url`: it keeps a drive letter's case and
// leaves `[`, `]`, `^` and `|` bare.

/** `file://` URI for `p`, matching the server's `to_uri` byte for byte. */
export function pathToUri(p: string): string {
  return `file://${encodePath(rooted(p.replace(/\\/g, "/")))}`;
}

// `path` starting with `/`: a drive path takes one before its letter, which it
// brings down to lower case.
function rooted(path: string): string {
  if (/^[A-Za-z]:/.test(path)) {
    return `/${path.slice(0, 1).toLowerCase()}${path.slice(1)}`;
  }
  return path;
}

// The bytes a URI path holds as they are: unreserved, sub-delimiters, `:`, `@`
// and `/` (RFC 3986 section 3.3).
const PATH_BYTE = /[A-Za-z0-9\-._~!$&'()*+,;=:@\/]/;

function encodePath(path: string): string {
  let out = "";
  for (const b of new TextEncoder().encode(path)) {
    const c = String.fromCharCode(b);
    if (b < 0x80 && PATH_BYTE.test(c)) {
      out += c;
    } else {
      out += `%${b.toString(16).toUpperCase().padStart(2, "0")}`;
    }
  }
  return out;
}
