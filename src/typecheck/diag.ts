import { TYPECHECK, WARNING } from "../diagnostics/codes.ts";
import { makeErr, makeWarn } from "../diagnostics/emit.ts";

export const err = makeErr(TYPECHECK);
export const warn = makeWarn(WARNING);
