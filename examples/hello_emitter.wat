(module
 (type $0 (func (param i32)))
 (type $1 (func (param i32 i32 i32 i32) (result i32)))
 (type $2 (func (param i32) (result i32)))
 (type $3 (func (result i32)))
 (type $4 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (param i32)))
 (import "wasi_snapshot_preview1" "fd_write" (func $wasi_snapshot_preview1:fd_write (param i32 i32 i32 i32) (result i32)))
 (global $return_code (mut i32) (i32.const 32))
 (memory $0 1)
 (data $0 (i32.const 0) "Hello world\n")
 (data $3 (i32.const 36) "Hello world2\n")
 (data $6 (i32.const 72) "Hello 3\n")
 (export "add" (func $add))
 (export "main" (func $main))
 (export "memory" (memory $0))
 (start $_start)
 (func $add (param $0 i32) (result i32)
  (i32.add
   (local.get $0)
   (i32.const 3)
  )
 )
 (func $main (result i32)
  (i32.store
   (i32.const 16)
   (i32.const 0)
  )
  (i32.store
   (i32.const 20)
   (i32.const 12)
  )
  (drop
   (call $wasi_snapshot_preview1:fd_write
    (i32.const 1)
    (i32.const 16)
    (i32.const 1)
    (i32.const 28)
   )
  )
  (i32.store
   (i32.const 52)
   (i32.const 36)
  )
  (i32.store
   (i32.const 56)
   (i32.const 13)
  )
  (drop
   (call $wasi_snapshot_preview1:fd_write
    (i32.const 1)
    (i32.const 52)
    (i32.const 1)
    (i32.const 64)
   )
  )
  (i32.store
   (i32.const 84)
   (i32.const 72)
  )
  (i32.store
   (i32.const 88)
   (i32.const 8)
  )
  (drop
   (call $wasi_snapshot_preview1:fd_write
    (i32.const 1)
    (i32.const 84)
    (i32.const 1)
    (i32.const 96)
   )
  )
  (global.set $return_code
   (i32.const 0)
  )
  (call $add
   (i32.const 0)
  )
 )
 (func $_start
  (call $wasi_snapshot_preview1:proc_exit
   (call $main)
  )
 )
)
