import binaryen from "binaryen";

const WASI_VERSION = "wasi_snapshot_preview1";
export function addWasiFunction(module: binaryen.Module) {
  module.addFunctionImport(
    `${WASI_VERSION}:proc_exit`,
    WASI_VERSION,
    "proc_exit",
    binaryen.createType([binaryen.i32]),
    binaryen.none
  );

  module.addFunctionImport(
    `${WASI_VERSION}:fd_write`,
    WASI_VERSION,
    "fd_write",
    binaryen.createType([
      binaryen.i32,
      binaryen.i32,
      binaryen.i32,
      binaryen.i32,
    ]),
    binaryen.i32
  );
}
