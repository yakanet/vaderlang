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
  (local $0 i32)
  (i32.store
   (i32.const 0)
   (i32.const 2)
  )
  (i32.store
   (i32.const 4)
   (i32.const 4)
  )
  (i32.store
   (i32.const 12)
   (i32.const 6)
  )
  (i32.store
   (i32.const 16)
   (i32.const 8)
  )
  (local.get $0)
 )
 (func $_start
  (call $wasi_snapshot_preview1:proc_exit
   (call $main)
  )
 )
)
