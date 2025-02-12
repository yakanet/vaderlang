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
  (local $1 i32)
  (i32.store
   (i32.const 16)
   (i32.const 2)
  )
  (i32.store
   (i32.const 20)
   (i32.const 4)
  )
  (i32.store
   (i32.const 0)
   (i32.const 16)
  )
  (i32.store
   (i32.const 8)
   (i32.const 10)
  )
  (i32.store
   (i32.const 28)
   (i32.const 6)
  )
  (i32.store
   (i32.const 32)
   (i32.const 8)
  )
  (local.set $1
   (i32.const 28)
  )
  (i32.add
   (i32.load offset=4
    (i32.load
     (local.get $0)
    )
   )
   (i32.load offset=4
    (local.get $1)
   )
  )
 )
 (func $_start
  (call $wasi_snapshot_preview1:proc_exit
   (call $main)
  )
 )
)
