import { TYPECHECK } from "../diagnostics/codes.ts";
import { makeErr } from "../diagnostics/emit.ts";

export const err = makeErr(TYPECHECK);
