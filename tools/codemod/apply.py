"""Phase 1 of the `is T as x` migration: `if <name> is T as a { … a … }`.

Only sites whose scrutinee is a BARE identifier, and whose alias the resolver
bound (so the edit is anchored on a symbol, never on text). Everything else is
reported and left alone.
"""
import io, os, re, sys, collections

ROOT = "/Users/mbroutin/Developments/default/vaderlang2"
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from scan import load, scan, IF_RE, ARM_RE

HEAD_OK = re.compile(r'(?:^\s*(?:\}\s*)?(?:else\s+)?(?:if|while)\s+)$')
DECL_RE = lambda n: re.compile(r'(?<![A-Za-z0-9_])' + re.escape(n) + r'\s*(?:::|:=|:\s*[A-Za-z_])')

def block_end(lines, i):
    """Last line index of the block opened on line i (0-based), by indentation."""
    ind = len(lines[i]) - len(lines[i].lstrip())
    j = i + 1
    while j < len(lines):
        s = lines[j].strip()
        if s and (len(lines[j]) - len(lines[j].lstrip())) <= ind:
            return j
        j += 1
    return len(lines)

def main(table, only=None, write=False):
    binds, uses = load(table)
    allf = []
    for base in ("vader", "lib"):
        for dp, _, fns in os.walk(os.path.join(ROOT, base)):
            for fn in fns:
                if fn.endswith(".vader"): allf.append(os.path.join(dp, fn))
    if only: allf = [f for f in allf if only in f]
    sites = scan(sorted(allf), binds)

    per_file = collections.defaultdict(list)
    stats = collections.Counter()
    for s in sites:
        if s["kind"] != "if" or s["symid"] is None or s["name"] != s["alias"]:
            stats["not-phase-1"] += 1; continue
        sc = s["scrut"]
        if not sc or "." in sc:
            stats["hoist-needed"] += 1; continue
        head = s["text"][: s["text"].rfind(sc + " is")]
        if not HEAD_OK.search(head):
            stats["embedded-or-nested"] += 1; continue
        src = io.open(s["file"], encoding="utf-8").read()
        lines = src.split("\n")
        end = block_end(lines, s["line"] - 1)
        body = "\n".join(lines[s["line"]: end])
        if DECL_RE(sc).search(body):
            stats["scrutinee-shadowed-in-body"] += 1; continue
        us = [u for u in uses.get(s["symid"], []) if u[0] == s["file"]]
        stats["rewritten"] += 1
        per_file[s["file"]].append((s, us, sc))

    edits = collections.defaultdict(list)
    for f, items in per_file.items():
        src = io.open(f, encoding="utf-8").read().encode()
        for s, us, sc in items:
            edits[f].append((s["as_start"], s["as_end"], b""))
            for (_, a, b) in us:
                if src[a:b].decode() != s["alias"]:
                    stats["use-text-mismatch"] += 1; continue
                edits[f].append((a, b, sc.encode()))
    for k, v in stats.most_common(): print(f"  {k}: {v}")
    print(f"  files: {len(edits)}  edits: {sum(len(v) for v in edits.values())}")
    if not write: return edits
    for f, es in edits.items():
        src = bytearray(io.open(f, "rb").read())
        for a, b, t in sorted(es, key=lambda e: -e[0]):
            src[a:b] = t
        io.open(f, "wb").write(bytes(src))
    return edits

if __name__ == "__main__":
    rest = [a for a in sys.argv[2:] if not a.startswith("--")]
    main(sys.argv[1], only=(rest[0] if rest else None), write=("--write" in sys.argv))
