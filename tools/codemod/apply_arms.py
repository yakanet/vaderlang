"""The `match` half: `match <name> { is T as a -> … a … }` loses the arm alias.

Only arms whose enclosing match has an IDENTIFIER scrutinee — the alias then
names something that already has a name. An expression scrutinee keeps its alias
(the `match e as x { … }` header is the answer there, and that is a separate
rewrite).
"""
import io, os, re, sys, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from scan import ARM_RE, ROOT, norm, load

ARROW = re.compile(r'^(?P<head>\s*\S.*?)(?P<pad> +)(?P<arrow>->)(?=\s|$)')

def arm_block(lines, idx):
    """The run of single-line arm heads at `idx`'s indentation, as [lo, hi]."""
    if not ARROW.match(lines[idx]): return None
    ind = len(lines[idx]) - len(lines[idx].lstrip())
    def step(i, d):
        """Next arm HEAD in direction d, skipping an arm's own body and brace."""
        j = i + d
        while 0 <= j < len(lines):
            l = lines[j]
            if not l.strip(): return None
            li = len(l) - len(l.lstrip())
            if li > ind: j += d; continue          # inside an arm body
            if li == ind and l.strip() == "}": j += d; continue   # an arm's close
            if li == ind and ARROW.match(l): return j
            return None
        return None
    lo = hi = idx
    while True:
        j = step(lo, -1)
        if j is None: break
        lo = j
    while True:
        j = step(hi, 1)
        if j is None: break
        hi = j
    return (lo, hi)

def was_aligned(lines, lo, hi):
    """True when the block was column-aligned — either its `->` already share a
    column, or some line carries padding put there to line them up."""
    if hi <= lo: return False
    rows = [ARROW.match(lines[i]) for i in range(lo, hi + 1) if ARROW.match(lines[i])
            and len(lines[i]) - len(lines[i].lstrip()) == len(lines[lo]) - len(lines[lo].lstrip())]
    if len(rows) < 2: return False
    return len({r.end("pad") for r in rows}) == 1 or any(len(r.group("pad")) > 1 for r in rows)

def realign(lines, lo, hi):
    ind = len(lines[lo]) - len(lines[lo].lstrip())
    rows = [(i, ARROW.match(lines[i])) for i in range(lo, hi + 1)
            if ARROW.match(lines[i]) and len(lines[i]) - len(lines[i].lstrip()) == ind]
    width = max(len(r.group("head")) for _, r in rows)
    for i, r in rows:
        lines[i] = r.group("head") + " " * (width - len(r.group("head")) + 1) + lines[i][r.end("pad"):]

def main(table, arms_table, write=False):
    binds, uses = load(table)
    scrut = {}
    for ln in io.open(arms_table, encoding="utf-8"):
        f = ln.rstrip("\n").split("\t")
        if f[0] != "M": continue
        p = norm(f[1])
        if p: scrut[(p, int(f[2]), int(f[3]))] = (int(f[4]), int(f[5]), f[6] == "1")

    stats = collections.Counter()
    per_file = collections.defaultdict(list)
    for (path, line, col), (s0, s1, is_ident) in scrut.items():
        if not is_ident:
            stats["expression-scrutinee-kept"] += 1; continue
        src = io.open(path, encoding="utf-8").read()
        raw = src.encode()
        name = raw[s0:s1].decode()
        if not re.fullmatch(r'[A-Za-z_][A-Za-z0-9_]*', name):
            stats["scrutinee-not-a-plain-name"] += 1; continue
        lines = src.split("\n")
        m = ARM_RE.match(lines[line - 1])
        if not m: stats["arm-line-moved"] += 1; continue
        sym = binds.get((path, line, col))
        if not sym or sym[1] != m.group("alias"):
            stats["no-symbol"] += 1; continue
        offs, o = [], 0
        for l in lines:
            offs.append(o); o += len(l.encode()) + 1
        stats["rewritten"] += 1
        per_file[path].append(dict(line=line, alias=m.group("alias"), name=name,
                                   symid=sym[0],
                                   as_start=offs[line-1] + m.end("ty"),
                                   as_end=offs[line-1] + m.end("alias")))

    edits = collections.defaultdict(list)
    touched = collections.defaultdict(set)
    for f, items in per_file.items():
        raw = io.open(f, "rb").read()
        for it in items:
            edits[f].append((it["as_start"], it["as_end"], b""))
            touched[f].add(it["line"] - 1)
            for (uf, a, b) in uses.get(it["symid"], []):
                if uf != f: continue
                if raw[a:b].decode() != it["alias"]:
                    stats["use-text-mismatch"] += 1; continue
                edits[f].append((a, b, it["name"].encode()))
    for k, v in stats.most_common(): print(f"  {k}: {v}")
    print(f"  files: {len(edits)}  edits: {sum(len(v) for v in edits.values())}")
    if not write: return
    for f, es in edits.items():
        raw = bytearray(io.open(f, "rb").read())
        for a, b, t in sorted(es, key=lambda e: -e[0]):
            raw[a:b] = t
        before = io.open(f, encoding="utf-8").read().split("\n")
        blocks = set()
        for i in sorted(touched[f]):
            blk = arm_block(before, i)
            if blk and was_aligned(before, *blk): blocks.add(blk)
        lines = bytes(raw).decode().split("\n")
        for lo, hi in blocks:
            realign(lines, lo, hi)
        io.open(f, "w", encoding="utf-8").write("\n".join(lines))

if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2], write=("--write" in sys.argv))
