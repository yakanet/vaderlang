(module
 (type $0 (func (param i32)))
 (type $1 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (param i32)))
 (memory $0 1)
 (export "memory" (memory $0))
 (start $_start)
 (func $_start
  (i32.store
   (i32.const 40)
   (i32.const 2)
  )
  (i32.store
   (i32.const 44)
   (i32.const 3)
  )
  (i32.store
   (i32.const 48)
   (i32.const 4)
  )
  (call $wasi_snapshot_preview1:proc_exit
   (i32.load
    (i32.const 48)
   )
  )
 )
)
