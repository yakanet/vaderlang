(module
 (type $0 (func (param i32 i32 i32 i32) (result i32)))
 (type $1 (func))
 (import "wasi_snapshot_preview1" "fd_write" (func $wasi_snapshot_preview1:fd_write (type $0) (param i32 i32 i32 i32) (result i32)))
 (memory $0 1)
 (data $0 (i32.const 0) "Hello")
 (data $3 (i32.const 20) "\n")
 (export "memory" (memory $0))
 (start $main)
 (func $main (type $1)
  (local $0 i32)
  (local $1 i32)
  (loop $outer_0
   (if
    (i32.lt_u
     (local.get $0)
     (i32.const 10)
    )
    (then
     (local.set $1
      (i32.const 0)
     )
     (loop $outer_1
      (if
       (i32.lt_u
        (local.get $1)
        (i32.const 10)
       )
       (then
        (i32.store
         (i32.const 8)
         (i32.const 0)
        )
        (i32.store
         (i32.const 12)
         (i32.const 5)
        )
        (drop
         (call $wasi_snapshot_preview1:fd_write
          (i32.const 1)
          (i32.const 8)
          (i32.const 1)
          (i32.const 16)
         )
        )
        (local.set $1
         (i32.add
          (local.get $1)
          (i32.const 1)
         )
        )
        (br $outer_1)
       )
      )
     )
     (i32.store
      (i32.const 24)
      (i32.const 20)
     )
     (i32.store
      (i32.const 28)
      (i32.const 1)
     )
     (drop
      (call $wasi_snapshot_preview1:fd_write
       (i32.const 1)
       (i32.const 24)
       (i32.const 1)
       (i32.const 32)
      )
     )
     (local.set $0
      (i32.add
       (local.get $0)
       (i32.const 1)
      )
     )
     (br $outer_0)
    )
   )
  )
 )
)
