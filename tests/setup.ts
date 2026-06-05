// Preload: registers ensureCliBuilt as a global beforeAll so every test file
// asserts a prebuilt, up-to-date ./build/vader exists before spawning it.
// The harness no longer builds the compiler — see tests/cli-bin.ts.
import { ensureCliBuilt } from "./cli-bin.ts";

ensureCliBuilt();
