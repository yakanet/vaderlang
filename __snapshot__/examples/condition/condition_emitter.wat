(module
 (type $0 (func (param i32)))
 (type $1 (func (param i32 i32 i32 i32) (result i32)))
 (type $2 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (type $0) (param i32)))
 (import "wasi_snapshot_preview1" "fd_write" (func $wasi_snapshot_preview1:fd_write (type $1) (param i32 i32 i32 i32) (result i32)))
 (memory $0 1)
 (data $0 (i32.const 0) "equals\n")
 (data $3 (i32.const 20) "second equals\n")
 (data $6 (i32.const 48) "equals\n")
 (data $9 (i32.const 68) "not equals\n")
 (data $12 (i32.const 92) "x == 0\n")
 (data $15 (i32.const 112) "x == 32\n")
 (data $18 (i32.const 132) "x == 30\n")
 (data $21 (i32.const 152) "not equals\n")
 (export "memory" (memory $0))
 (start $_start)
 (func $_start (type $2)
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
     (i32.const 16)
    )
   )
  )
  (i32.store
   (i32.const 36)
   (i32.const 20)
  )
  (i32.store
   (i32.const 40)
   (i32.const 14)
  )
  (drop
   (call $wasi_snapshot_preview1:fd_write
    (i32.const 1)
    (i32.const 36)
    (i32.const 1)
    (i32.const 44)
   )
  )
  (i32.store
   (i32.const 80)
   (i32.const 68)
  )
  (i32.store
   (i32.const 84)
   (i32.const 11)
  )
  (drop
   (call $wasi_snapshot_preview1:fd_write
    (i32.const 1)
    (i32.const 80)
    (i32.const 1)
    (i32.const 88)
   )
  )
  (i32.store
   (i32.const 120)
   (i32.const 112)
  )
  (i32.store
   (i32.const 124)
   (i32.const 8)
  )
  (drop
   (call $wasi_snapshot_preview1:fd_write
    (i32.const 1)
    (i32.const 120)
    (i32.const 1)
    (i32.const 128)
   )
  )
  (call $wasi_snapshot_preview1:proc_exit
   (i32.const 35)
  )
 )
)
