// Preload: registers ensureCliBuilt as a global beforeAll so every test file
// asserts a prebuilt, up-to-date ./build/vader exists before spawning it.
// The harness no longer builds the compiler, see tests/cli-bin.ts.
//
// Every test may spawn the compiler, whose time on a CI runner is many times the
// local one, so the default test timeout is a build budget rather than bun's 5 s.
// A test that needs longer still declares `LONG_BUILD` or `HEAVY_BUILD`.
import { setDefaultTimeout } from "bun:test";
import { ensureCliBuilt, MEDIUM_BUILD } from "./cli-bin.ts";

ensureCliBuilt();
setDefaultTimeout(MEDIUM_BUILD);
