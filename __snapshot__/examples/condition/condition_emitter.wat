(module
 (type $0 (func (param i32)))
 (type $1 (func (param i32 i32 i32 i32) (result i32)))
 (type $2 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (param i32)))
 (import "wasi_snapshot_preview1" "fd_write" (func $wasi_snapshot_preview1:fd_write (param i32 i32 i32 i32) (result i32)))
 (memory $0 1)
 (data $0 (i32.const 0) "equals\n")
 (data $3 (i32.const 28) "second equals\n")
 (data $6 (i32.const 64) "equals\n")
 (data $9 (i32.const 92) "not equals\n")
 (data $12 (i32.const 124) "x == 0\n")
 (data $15 (i32.const 152) "x == 32\n")
 (data $18 (i32.const 184) "x == 30\n")
 (data $21 (i32.const 216) "not equals\n")
 (export "memory" (memory $0))
 (start $_start)
 (func $_start
  (block
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
  (i32.store
   (i32.const 164)
   (i32.const 152)
  )
  (i32.store
   (i32.const 168)
   (i32.const 8)
  )
  (drop
   (call $wasi_snapshot_preview1:fd_write
    (i32.const 1)
    (i32.const 164)
    (i32.const 1)
    (i32.const 176)
   )
  )
  (call $wasi_snapshot_preview1:proc_exit
   (i32.const 35)
  )
 )
)
