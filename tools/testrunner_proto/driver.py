#!/usr/bin/env python3
# Measures the `vader dump-worker` prototype against one `vader dump` process per
# stage, on the snippets under tests/snippets.
#
#   baseline: one `vader dump --stage=<S>` process per stage, as tests/snapshot.ts runs them;
#   worker:   K long-lived `vader dump-worker` processes, one case per line on stdin.
#
# Both draw the cases from one queue, K at a time. Each stage text is compared to
# the committed snapshot and, when both forms ran, the worker's to the baseline's.
# A worker that dies is replaced on the rest of its case, the crashed stage
# recorded as the harness records a failed run.
#
# Usage, from the repository root:
#   python3 -I tools/testrunner_proto/driver.py <vader> <baseline|worker|both> <every-nth> <report.json>
#       [k] [phases, comma list, `vm` included on request] [reverse]
#
# The `vm` phase runs the snippet's source as `vader run <path>` does, formatted
# as `formatRun` in tests/snapshot.ts formats a run (a signal counts as a stop);
# the baseline runs `vader run <path>`. tests/vader_vm.test.ts runs the pinned
# `.virt` or a built image instead, so a few snapshots differ in both forms.

import json
import os
import queue
import resource
import re
import shutil
import subprocess
import tempfile
import sys
import threading
import time

STAGES = [
    # (phase, dump stage, snapshot file, takes --module)
    ("lexer", "lexer", "lexer.snapshot", False),
    ("parser", "ast", "parser.snapshot.json", False),
    ("typecheck", "typed-ast", "typecheck.snapshot", True),
    ("comptime", "evaluated-ast", "comptime.snapshot.md", True),
    ("lower", "lowered-ast", "lower.snapshot", True),
    ("bytecode", "bytecode", "bytecode.snapshot.virt", False),
    ("emit_c", "c", "emit-c.snapshot.c", False),
]
VM_STAGE = ("vm", "vm", "vm.snapshot", False)
STOP_LINE = re.compile(r"^vader: (?:trap|panic): ", re.M)
VM_STOP = re.compile(r"^vader vm: (.*?)(?: at pc=\d+)?$", re.M)
CASE_TIMEOUT_S = 300


def vm_excluded(cfg, d):
    vm = cfg.get("vm") or {}
    if vm.get("skip") or (vm.get("skip_on") or {}).get(sys.platform):
        return True
    return any(f.startswith("helper") and f.endswith(".c") for f in os.listdir(d))


def snippets(every, phases):
    root = "tests/snippets"
    names = sorted(
        n for n in os.listdir(root)
        if os.path.isdir(os.path.join(root, n)) and os.path.isfile(os.path.join(root, n, "_main.vader"))
    )
    out = []
    for i, name in enumerate(names):
        if i % every:
            continue
        d = os.path.join(root, name)
        p = os.path.join(d, "_config.json")
        cfg = json.load(open(p)) if os.path.exists(p) else {}
        allowed = cfg.get("phases")
        stages = [s for s in STAGES if s[0] in phases and (allowed is None or s[0] in allowed)]
        if "vm" in phases and os.path.exists(os.path.join(d, VM_STAGE[2])) and not vm_excluded(cfg, d):
            stages.append(VM_STAGE)
        if stages:
            out.append({"name": name, "dir": d, "path": os.path.join(d, "_main.vader"),
                        "stages": stages, "modules": cfg.get("modules") or []})
    return out


def nested(text):
    return text.replace("\n", "\n  ")


def ast_as_json(dump):
    head = "# AST\n"
    if not dump.startswith(head):
        return dump
    parts = dump[len(head):].split("\n# Diagnostics\n")
    tree = parts[0] if parts else ""
    diags = parts[1] if len(parts) > 1 else ""
    lines = [l for l in diags.split("\n") if l != ""]
    return ('{\n  "ast": ' + nested(tree.strip()) + ',\n'
            + '  "diagnostics": ' + nested(json.dumps(lines, indent=2, ensure_ascii=False)) + '\n}\n')


def canonical_exit(code, stderr):
    if code != 0 and (code < 0 or code >= 128 or STOP_LINE.search(stderr)):
        return 134
    return code


def format_run(stdout, stderr, code):
    shared = VM_STOP.sub(lambda m: "vader: " + m.group(1) if m.group(1).startswith("panic: ")
                         else "vader: trap: " + m.group(1), stderr)
    parts = []
    if stdout:
        parts.append("# stdout\n" + stdout)
    if shared:
        parts.append("# stderr\n" + shared)
    stopped = STOP_LINE.search(shared) or code < 0
    parts.append(f"# exit\n{134 if stopped else code}\n")
    return "".join(parts)


def failed_text(code, stderr, stdout):
    return f"# vader CLI failed (exit {canonical_exit(code, stderr)})\n{stderr}{stdout}"


def finish(stage, text):
    return ast_as_json(text) if stage[0] == "parser" else text


def dump_args(binary, stage, case):
    args = [binary, "dump", f"--stage={stage[1]}", "--target=linux-x86_64"]
    if stage[3] and case["modules"]:
        args.append("--module=" + ",".join(case["modules"]))
    if stage[1] == "bytecode":
        args.append("--annotate")
    args.append(case["path"])
    return args


def pool(cases, k, body, finish_thread=None):
    """Run `body(case, state)` for each case on `k` threads pulling from one queue."""
    q = queue.Queue()
    for case in cases:
        q.put(case)

    def loop():
        state = {}
        while True:
            try:
                case = q.get_nowait()
            except queue.Empty:
                break
            body(case, state)
        if finish_thread:
            finish_thread(state)

    threads = [threading.Thread(target=loop) for _ in range(k)]
    for t in threads:
        t.start()
    for t in threads:
        t.join()


def run_baseline(binary, cases, env, k):
    texts = {}

    def body(case, _state):
        for stage in case["stages"]:
            if stage is VM_STAGE:
                p = subprocess.run([binary, "run", case["path"]], capture_output=True, env=env,
                                   stdin=subprocess.DEVNULL, timeout=CASE_TIMEOUT_S)
                texts[(case["name"], stage[0])] = format_run(
                    p.stdout.decode("utf-8", "replace"), p.stderr.decode("utf-8", "replace"), p.returncode)
                continue
            p = subprocess.run(dump_args(binary, stage, case), capture_output=True, env=env,
                               timeout=CASE_TIMEOUT_S)
            out = p.stdout.decode("utf-8", "replace")
            err = p.stderr.decode("utf-8", "replace")
            if p.returncode != 0:
                out = failed_text(p.returncode, err, out)
            texts[(case["name"], stage[0])] = finish(stage, out)

    began = time.monotonic()
    pool(cases, k, body)
    return texts, time.monotonic() - began


class Worker:
    def __init__(self, binary, env):
        self.capture = tempfile.mkdtemp(prefix="vader-worker-")
        self.p = subprocess.Popen([binary, "dump-worker", self.capture], stdin=subprocess.PIPE,
                                  stdout=subprocess.PIPE, stderr=subprocess.PIPE, env=env)
        self.err = bytearray()
        self.lock = threading.Lock()
        self.drain = threading.Thread(target=self._drain, daemon=True)
        self.drain.start()

    def _drain(self):
        for chunk in iter(lambda: self.p.stderr.read1(65536), b""):
            with self.lock:
                self.err += chunk

    def take_err(self):
        with self.lock:
            e = bytes(self.err)
            self.err.clear()
        return e.decode("utf-8", "replace")

    def peak_rss_kb(self):
        try:
            with open(f"/proc/{self.p.pid}/status") as f:
                for line in f:
                    if line.startswith("VmHWM:"):
                        return int(line.split()[1])
        except OSError:
            pass
        r = subprocess.run(["ps", "-o", "rss=", "-p", str(self.p.pid)], capture_output=True, text=True)
        return int(r.stdout.strip() or 0)

    # Run `stages` of `case`, adding each stage's time to `stage_micros`:
    # (results, crashed stage or None, partial stdout, micros or None).
    def run(self, case, stages, stage_micros):
        line = f"{case['path']}\t{','.join(case['modules'])}\t{','.join(s[1] for s in stages)}\n"
        self.p.stdin.write(line.encode())
        self.p.stdin.flush()
        results = {}
        current = None
        buf = bytearray()
        watchdog = threading.Timer(CASE_TIMEOUT_S, self.p.kill)
        watchdog.start()
        try:
            while True:
                raw = self.p.stdout.readline()
                if not raw:
                    return results, current, bytes(buf), None
                i = raw.find(b"\x1e")
                if i < 0:
                    buf += raw
                    continue
                buf += raw[:i]
                marker = raw[i + 1:].rstrip(b"\n").decode()
                if marker == "stderr":
                    vm_out = bytes(buf)
                    buf = bytearray()
                elif marker.startswith("end "):
                    code, micros = marker[4:].split(" ")
                    if current == "vm":
                        results[current] = ((vm_out, bytes(buf)), int(code))
                    else:
                        results[current] = (bytes(buf), int(code))
                    stage_micros[current] = stage_micros.get(current, 0) + int(micros)
                    current = None
                    buf = bytearray()
                elif marker.startswith("done "):
                    return results, None, b"", int(marker[5:])
                else:
                    current = marker
                    buf = bytearray()
        finally:
            watchdog.cancel()


def run_worker(binary, cases, env, k):
    texts = {}
    crashes = []
    peaks = []
    stage_micros = {}
    lock = threading.Lock()

    def body(case, state):
        todo = list(case["stages"])
        while todo:
            worker = state.get("worker")
            if worker is None:
                worker = Worker(binary, env)
                state["worker"] = worker
            worker.take_err()
            results, crashed, partial, micros = worker.run(case, todo, state.setdefault("micros", {}))
            by_dump = {s[1]: s for s in todo}
            for dump_stage, (out, code) in results.items():
                stage = by_dump[dump_stage]
                if stage is VM_STAGE:
                    texts[(case["name"], stage[0])] = format_run(
                        out[0].decode("utf-8", "replace"), out[1].decode("utf-8", "replace"), code)
                    continue
                text = out.decode("utf-8", "replace")
                if code != 0:
                    text = failed_text(code, "", text)
                texts[(case["name"], stage[0])] = finish(stage, text)
            if micros is not None:
                return
            code = worker.p.wait()
            worker.drain.join(timeout=5)
            err = worker.take_err()
            if crashed is None:
                crashed = next(s[1] for s in todo if s[1] not in results)
            stage = by_dump[crashed]
            texts[(case["name"], stage[0])] = finish(
                stage, failed_text(code, err, partial.decode("utf-8", "replace")))
            crashes.append({"case": case["name"], "stage": stage[0], "exit": code,
                            "stderr": err[-400:]})
            state["worker"] = None
            todo = todo[[s[1] for s in todo].index(crashed) + 1:]

    def finish_thread(state):
        worker = state.get("worker")
        with lock:
            if worker is not None:
                peaks.append(worker.peak_rss_kb())
            for stage, micros in state.get("micros", {}).items():
                stage_micros[stage] = stage_micros.get(stage, 0) + micros
        if worker is not None:
            worker.p.stdin.close()
            worker.p.wait()
            shutil.rmtree(worker.capture, ignore_errors=True)

    began = time.monotonic()
    pool(cases, k, body, finish_thread)
    return texts, time.monotonic() - began, crashes, peaks, stage_micros


def snapshot(case_dir, stage):
    p = os.path.join(case_dir, stage[2])
    if not os.path.exists(p):
        return None
    with open(p, encoding="utf-8", errors="replace") as f:
        return f.read()


def compare(cases, texts):
    same, differ = 0, []
    for case in cases:
        for stage in case["stages"]:
            got = texts.get((case["name"], stage[0]))
            if got is None:
                continue
            if got == snapshot(case["dir"], stage):
                same += 1
            else:
                differ.append(f"{case['name']}/{stage[0]}")
    return same, differ


def cpu_seconds(who=resource.RUSAGE_CHILDREN):
    r = resource.getrusage(who)
    return r.ru_utime + r.ru_stime


def main():
    binary, mode, every, report_path = sys.argv[1], sys.argv[2], int(sys.argv[3]), sys.argv[4]
    k = int(sys.argv[5]) if len(sys.argv) > 5 else 1
    phases = sys.argv[6].split(",") if len(sys.argv) > 6 else [s[0] for s in STAGES]
    env = dict(os.environ)
    cases = snippets(every, phases)
    if len(sys.argv) > 7 and sys.argv[7] == "reverse":
        cases.reverse()
    report = {"cases": len(cases), "stage_checks": sum(len(c["stages"]) for c in cases), "k": k}
    base = work = None
    if mode in ("baseline", "both"):
        cpu = cpu_seconds()
        base, base_s = run_baseline(binary, cases, env, k)
        same, differ = compare(cases, base)
        report["baseline"] = {"seconds": round(base_s, 2), "cpu_seconds": round(cpu_seconds() - cpu, 1),
                              "snapshot_same": same, "snapshot_differ": differ}
    if mode in ("worker", "both"):
        cpu = cpu_seconds()
        own = cpu_seconds(resource.RUSAGE_SELF)
        work, work_s, crashes, peaks, stage_micros = run_worker(binary, cases, env, k)
        report["worker"] = {"seconds": round(work_s, 2), "cpu_seconds": round(cpu_seconds() - cpu, 1),
                            "driver_cpu_seconds": round(cpu_seconds(resource.RUSAGE_SELF) - own, 1),
                            "crashes": crashes, "peak_rss_kb": peaks,
                            "stage_seconds": {s: round(v / 1e6, 2) for s, v in stage_micros.items()}}
        same, differ = compare(cases, work)
        report["worker"].update({"snapshot_same": same, "snapshot_differ": differ})
    if base is not None and work is not None:
        report["worker_vs_baseline_differ"] = sorted(
            f"{c[0]}/{c[1]}" for c in base if base.get(c) != work.get(c))
    with open(report_path, "w") as f:
        json.dump(report, f, indent=1)
    for key in ("baseline", "worker"):
        r = report.get(key)
        if r:
            print(f"k={k} {key}: {r['seconds']} s wall, {r['cpu_seconds']} s cpu, "
                  f"snapshots same {r['snapshot_same']}, differ {len(r['snapshot_differ'])}")
    if "worker" in report:
        w = report["worker"]
        peaks = w["peak_rss_kb"]
        print(f"k={k} worker: {len(w['crashes'])} crashes, driver {w['driver_cpu_seconds']} s cpu, "
              f"peak rss {max(peaks, default=0)} kb per worker, {sum(peaks)} kb for {len(peaks)}")
        print(f"k={k} worker stage seconds: {w['stage_seconds']}")
    if "worker_vs_baseline_differ" in report:
        print(f"k={k} worker vs baseline differ: {len(report['worker_vs_baseline_differ'])}")
        for name in report["worker_vs_baseline_differ"][:20]:
            print(f"  worker != baseline: {name}")
    for key in ("baseline", "worker"):
        for name in report.get(key, {}).get("snapshot_differ", [])[:20]:
            print(f"  {key} != snapshot: {name}")
    for crash in report.get("worker", {}).get("crashes", [])[:5]:
        print(f"  crash: {crash['case']}/{crash['stage']} exit {crash['exit']}")


main()
