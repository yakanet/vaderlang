import { BACKEND } from "../diagnostics/codes.ts";
import { makeErr } from "../diagnostics/emit.ts";

export const err = makeErr(BACKEND);
