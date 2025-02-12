(module
 (type $0 (func (param i32)))
 (type $1 (func (param i32 i32) (result i32)))
 (type $2 (func (param i32) (result i32)))
 (type $3 (func (result i32)))
 (type $4 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (param i32)))
 (memory $0 1)
 (export "dot" (func $dot))
 (export "plus1" (func $plus1))
 (export "main" (func $main))
 (export "memory" (memory $0))
 (start $_start)
 (func $dot (param $0 i32) (param $1 i32) (result i32)
  (i32.add
   (i32.mul
    (i32.load
     (local.get $0)
    )
    (i32.load
     (local.get $1)
    )
   )
   (i32.mul
    (i32.load offset=4
     (local.get $0)
    )
    (i32.load offset=4
     (local.get $1)
    )
   )
  )
 )
 (func $plus1 (param $0 i32) (result i32)
  (i32.add
   (local.get $0)
   (i32.const 1)
  )
 )
 (func $main (result i32)
  (i32.store
   (i32.const 0)
   (i32.const 2)
  )
  (i32.store
   (i32.const 4)
   (i32.const 3)
  )
  (i32.store
   (i32.const 12)
   (i32.const 4)
  )
  (i32.store
   (i32.const 16)
   (i32.const 5)
  )
  (call $plus1
   (call $dot
    (i32.const 0)
    (i32.const 12)
   )
  )
 )
 (func $_start
  (call $wasi_snapshot_preview1:proc_exit
   (call $main)
  )
 )
)
