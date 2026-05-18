// Preload: registers ensureCliBuilt as a global beforeAll so every test
// file builds ./build/vader before spawning it.
import { ensureCliBuilt } from "./cli-bin.ts";

ensureCliBuilt();
