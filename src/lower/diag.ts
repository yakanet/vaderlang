import { BACKEND, MIR_LOWER } from "../diagnostics/codes.ts";
import { makeErr } from "../diagnostics/emit.ts";

export const err = makeErr({ ...MIR_LOWER, ...BACKEND });
