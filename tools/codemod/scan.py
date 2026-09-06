import io, os, re, sys, collections

ROOT = "/Users/mbroutin/Developments/default/vaderlang2"

def norm(p):
    if p.startswith("<clone>:"): return None
    return os.path.normpath(os.path.join(ROOT, p))

def load(path):
    binds = {}            # (file, line, col) -> (symid, name)
    uses  = collections.defaultdict(list)   # symid -> [(file, s, e)]
    for ln in io.open(path, encoding="utf-8"):
        f = ln.rstrip("\n").split("\t")
        if f[0] == "B":
            p = norm(f[1])
            if p: binds[(p, int(f[2]), int(f[3]))] = (int(f[4]), f[5])
        elif f[0] == "U":
            p = norm(f[1])
            if p: uses[int(f[4])].append((p, int(f[2]), int(f[3])))
    return binds, uses

# `<scrutinee> is <TypeExpr> as <name>` inside an if/while condition.
IF_RE = re.compile(r'\bis\s+(?P<ty>[A-Za-z_][A-Za-z0-9_.]*(?:\s*\|\s*[A-Za-z_][A-Za-z0-9_.]*)*)\s+as\s+(?P<alias>[a-z_][A-Za-z0-9_]*)\b')
# a match arm: `is <TypeExpr> as <name> ->` (or `|` for or-patterns) at line start
ARM_RE = re.compile(r'^(?P<ind>\s*)is\s+(?P<ty>[A-Za-z_][A-Za-z0-9_.]*(?:\s*\|\s*[A-Za-z_][A-Za-z0-9_.]*)*)\s+as\s+(?P<alias>[a-z_][A-Za-z0-9_]*)\b')
IDENT_TAIL = re.compile(r'([A-Za-z_][A-Za-z0-9_]*(?:\.[A-Za-z_][A-Za-z0-9_]*)*)\s*$')

def scan(files, binds):
    sites = []
    for path in files:
        try: src = io.open(path, encoding="utf-8").read()
        except OSError: continue
        offs, o = [], 0
        for line in src.split("\n"):
            offs.append(o); o += len(line.encode()) + 1
        for i, line in enumerate(src.split("\n"), start=1):
            arm = ARM_RE.match(line)
            for m in IF_RE.finditer(line):
                ty_col = m.start("ty") + 1
                is_col = line.rfind("is", 0, m.start("ty")) + 1
                if arm and m.start("ty") == arm.start("ty"):
                    key, kind = (path, i, arm.start("ind") + len(arm.group("ind")) + 1), "arm"
                else:
                    key, kind = (path, i, ty_col), "if"
                got = binds.get(key)
                # what precedes the `is` — the scrutinee, textually
                head = line[:is_col - 1]
                mt = IDENT_TAIL.search(head)
                scrut = mt.group(1) if mt else None
                sites.append(dict(
                    file=path, line=i, kind=kind, alias=m.group("alias"),
                    symid=got[0] if got else None, name=got[1] if got else None,
                    scrut=scrut, text=line,
                    as_start=offs[i-1] + m.end("ty"), as_end=offs[i-1] + m.end("alias"),
                ))
    return sites

def bucket(sites):
    import collections
    c = collections.Counter()
    ex = collections.defaultdict(list)
    for s in sites:
        if s["kind"] != "if" or s["symid"] is None or s["name"] != s["alias"]: continue
        sc = s["scrut"]
        if sc is None:                b = "no-scrutinee-text"
        elif "." in sc:               b = "field-chain"
        elif s["text"].strip().startswith("//"): b = "comment"
        else:
            # is the token before `is` really the whole scrutinee?
            head = s["text"][:s["text"].rfind(sc + " is")] if (sc + " is") in s["text"] else ""
            b = "bare-ident" if re.search(r'(?:^\s*(?:\}\s*)?(?:else )?(?:if|while|for)\s+|\(\s*|&&\s*|\|\|\s*|!\s*)$', head) else "embedded"
        c[b] += 1
        if len(ex[b]) < 4: ex[b].append(s)
    for k, v in c.most_common():
        print(f"\n{k}: {v}")
        for s in ex[k]:
            print(f"    {os.path.relpath(s['file'], ROOT)}:{s['line']}  scrut={s['scrut']!r} alias={s['alias']!r}")
            print(f"      | {s['text'].strip()[:100]}")


if __name__ == "__main__":
    binds, uses = load(sys.argv[1])
    files = sorted({f for (f, _, _) in binds})
    # every .vader under vader/ and lib/, not only those that declare a binding
    allf = []
    for base in ("vader", "lib"):
        for dp, _, fns in os.walk(os.path.join(ROOT, base)):
            for fn in fns:
                if fn.endswith(".vader"): allf.append(os.path.join(dp, fn))
    sites = scan(sorted(allf), binds)
    tot = collections.Counter()
    for s in sites:
        matched = s["symid"] is not None and s["name"] == s["alias"]
        tot[(s["kind"], "joined" if matched else "MISS")] += 1
    print("sites:", len(sites))
    for k, v in sorted(tot.items()): print("  ", k, v)
    bucket(sites)
