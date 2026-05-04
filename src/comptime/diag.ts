import { COMPTIME } from "../diagnostics/codes.ts";
import { makeErr } from "../diagnostics/emit.ts";

export const err = makeErr(COMPTIME);
