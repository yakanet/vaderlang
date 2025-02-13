(module
 (type $0 (func (param i32)))
 (type $1 (func (result i32)))
 (type $2 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (param i32)))
 (memory $0 1)
 (export "main" (func $main))
 (export "memory" (memory $0))
 (start $_start)
 (func $main (result i32)
  (i32.const 1234234)
 )
 (func $_start
  (call $wasi_snapshot_preview1:proc_exit
   (i32.const 1234234)
  )
 )
)
