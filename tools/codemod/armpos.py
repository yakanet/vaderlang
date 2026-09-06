import io, os, re, sys, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from scan import ARM_RE, ROOT, norm

# raw B rows: keep the path string the tool itself printed, so the positions we
# hand back address the same files it knows.
raw = {}
for ln in io.open(sys.argv[1], encoding="utf-8"):
    f = ln.rstrip("\n").split("\t")
    if f[0] != "B": continue
    p = norm(f[1])
    if p: raw[(p, int(f[2]), int(f[3]))] = f[1]

allf = []
for base in ("vader", "lib"):
    for dp, _, fns in os.walk(os.path.join(ROOT, base)):
        for fn in fns:
            if fn.endswith(".vader"): allf.append(os.path.join(dp, fn))
out = []
for path in sorted(allf):
    try: src = io.open(path, encoding="utf-8").read()
    except OSError: continue
    for i, line in enumerate(src.split("\n"), start=1):
        m = ARM_RE.match(line)
        if not m: continue
        col = len(m.group("ind")) + 1
        rp = raw.get((path, i, col))
        if rp: out.append(f"{rp}\t{i}\t{col}")
io.open(sys.argv[2], "w").write("\n".join(out) + "\n")
print("arm positions:", len(out))
