(module
 (type $0 (func (param i32)))
 (type $1 (func (param i32 i32 i32 i32) (result i32)))
 (type $2 (func (result i32)))
 (type $3 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (param i32)))
 (import "wasi_snapshot_preview1" "fd_write" (func $wasi_snapshot_preview1:fd_write (param i32 i32 i32 i32) (result i32)))
 (memory $0 1)
 (data $0 (i32.const 0) "equals\n")
 (data $3 (i32.const 28) "second equals\n")
 (data $6 (i32.const 64) "equals\n")
 (data $9 (i32.const 92) "not equals\n")
 (export "main" (func $main))
 (export "memory" (memory $0))
 (start $_start)
 (func $main (result i32)
  (local $0 i32)
  (if
   (i32.eq
    (local.tee $0
     (i32.const 32)
    )
    (i32.const 32)
   )
   (then
    (i32.store
     (i32.const 8)
     (i32.const 0)
    )
    (i32.store
     (i32.const 12)
     (i32.const 7)
    )
    (drop
     (call $wasi_snapshot_preview1:fd_write
      (i32.const 1)
      (i32.const 8)
      (i32.const 1)
      (i32.const 20)
     )
    )
   )
  )
  (if
   (i32.eq
    (local.get $0)
    (i32.const 32)
   )
   (then
    (i32.store
     (i32.const 44)
     (i32.const 28)
    )
    (i32.store
     (i32.const 48)
     (i32.const 14)
    )
    (drop
     (call $wasi_snapshot_preview1:fd_write
      (i32.const 1)
      (i32.const 44)
      (i32.const 1)
      (i32.const 56)
     )
    )
   )
  )
  (if
   (i32.ne
    (local.get $0)
    (i32.const 32)
   )
   (then
    (i32.store
     (i32.const 72)
     (i32.const 64)
    )
    (i32.store
     (i32.const 76)
     (i32.const 7)
    )
    (drop
     (call $wasi_snapshot_preview1:fd_write
      (i32.const 1)
      (i32.const 72)
      (i32.const 1)
      (i32.const 84)
     )
    )
   )
   (else
    (i32.store
     (i32.const 104)
     (i32.const 92)
    )
    (i32.store
     (i32.const 108)
     (i32.const 11)
    )
    (drop
     (call $wasi_snapshot_preview1:fd_write
      (i32.const 1)
      (i32.const 104)
      (i32.const 1)
      (i32.const 116)
     )
    )
   )
  )
  (i32.const 0)
 )
 (func $_start
  (call $wasi_snapshot_preview1:proc_exit
   (call $main)
  )
 )
)
