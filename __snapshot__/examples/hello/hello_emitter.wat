(module
 (type $0 (func (param i32)))
 (type $1 (func (param i32 i32 i32 i32) (result i32)))
 (type $2 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (type $0) (param i32)))
 (import "wasi_snapshot_preview1" "fd_write" (func $wasi_snapshot_preview1:fd_write (type $1) (param i32 i32 i32 i32) (result i32)))
 (global $return_code (mut i32) (i32.const 32))
 (memory $0 1)
 (data $0 (i32.const 0) "Hello world\n")
 (data $3 (i32.const 24) "Hello world2\n")
 (data $6 (i32.const 52) "Hello 3\n")
 (export "memory" (memory $0))
 (start $_start)
 (func $_start (type $2)
  (i32.store
   (i32.const 12)
   (i32.const 0)
  )
  (i32.store
   (i32.const 16)
   (i32.const 12)
  )
  (drop
   (call $wasi_snapshot_preview1:fd_write
    (i32.const 1)
    (i32.const 12)
    (i32.const 1)
    (i32.const 20)
   )
  )
  (i32.store
   (i32.const 40)
   (i32.const 24)
  )
  (i32.store
   (i32.const 44)
   (i32.const 13)
  )
  (drop
   (call $wasi_snapshot_preview1:fd_write
    (i32.const 1)
    (i32.const 40)
    (i32.const 1)
    (i32.const 48)
   )
  )
  (i32.store
   (i32.const 60)
   (i32.const 52)
  )
  (i32.store
   (i32.const 64)
   (i32.const 8)
  )
  (drop
   (call $wasi_snapshot_preview1:fd_write
    (i32.const 1)
    (i32.const 60)
    (i32.const 1)
    (i32.const 68)
   )
  )
  (global.set $return_code
   ;;@ examples/hello.vader:15:19
   (i32.const 0)
  )
  ;;@
  (call $wasi_snapshot_preview1:proc_exit
   ;;@ examples/hello.vader:7:12
   (i32.const 3)
  )
 )
)
