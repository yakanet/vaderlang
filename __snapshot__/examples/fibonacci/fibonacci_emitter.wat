(module
 (type $0 (func (param i32)))
 (type $1 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (type $0) (param i32)))
 (memory $0 1)
 (export "memory" (memory $0))
 (start $_start)
 (func $_start (type $1)
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local.set $2
   (i32.const 1)
  )
  (local.set $1
   (i32.const 1)
  )
  (loop $outer_0
   (if
    (i32.le_u
     (local.get $1)
     (i32.const 10)
    )
    (then
     (local.set $3
      (local.get $0)
     )
     (local.set $2
      (i32.add
       (local.get $3)
       (local.tee $0
        (local.get $2)
       )
      )
     )
     (local.set $1
      (i32.add
       (local.get $1)
       (i32.const 1)
      )
     )
     (br $outer_0)
    )
   )
  )
  (call $wasi_snapshot_preview1:proc_exit
   (local.get $0)
  )
 )
)
