(module
 (type $0 (func (param i32)))
 (type $1 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (type $0) (param i32)))
 (memory $0 1)
 (export "memory" (memory $0))
 (start $_start)
 (func $_start (type $1)
  (call $wasi_snapshot_preview1:proc_exit
   (i32.const 24)
  )
 )
)
