(module
 (type $0 (func (param i32 i32) (result i32)))
 (type $1 (func (param i32)))
 (type $2 (func (result i32)))
 (type $3 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (param i32)))
 (memory $0 1)
 (export "equals" (func $equals))
 (export "startWith" (func $startWith))
 (export "main" (func $main))
 (export "memory" (memory $0))
 (start $_start)
 (func $equals (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (if
   (i32.ne
    (i32.load
     (local.get $0)
    )
    (i32.load
     (local.get $1)
    )
   )
   (then
    (return
     (i32.const 0)
    )
   )
  )
  (loop $outer_0
   (if
    (i32.lt_u
     (local.get $2)
     (i32.load
      (local.get $0)
     )
    )
    (then
     (if
      (i32.ne
       (i32.load
        (i32.add
         (local.tee $3
          (i32.shl
           (local.get $2)
           (i32.const 2)
          )
         )
         (i32.load offset=4
          (local.get $0)
         )
        )
       )
       (i32.load
        (i32.add
         (local.get $3)
         (i32.load offset=4
          (local.get $1)
         )
        )
       )
      )
      (then
       (return
        (i32.const 0)
       )
      )
      (else
       (local.set $2
        (i32.add
         (local.get $2)
         (i32.const 1)
        )
       )
       (br $outer_0)
      )
     )
    )
   )
  )
  (i32.const 1)
 )
 (func $startWith (param $0 i32) (param $1 i32) (result i32)
  (local $2 i32)
  (local $3 i32)
  (if
   (i32.gt_u
    (i32.load
     (local.get $1)
    )
    (i32.load
     (local.get $0)
    )
   )
   (then
    (return
     (i32.const 0)
    )
   )
  )
  (loop $outer_1
   (if
    (i32.lt_u
     (local.get $2)
     (i32.load
      (local.get $1)
     )
    )
    (then
     (if
      (i32.ne
       (i32.load
        (i32.add
         (local.tee $3
          (i32.shl
           (local.get $2)
           (i32.const 2)
          )
         )
         (i32.load offset=4
          (local.get $0)
         )
        )
       )
       (i32.load
        (i32.add
         (i32.load offset=4
          (local.get $1)
         )
         (local.get $3)
        )
       )
      )
      (then
       (return
        (i32.const 0)
       )
      )
      (else
       (local.set $2
        (i32.add
         (local.get $2)
         (i32.const 1)
        )
       )
       (br $outer_1)
      )
     )
    )
   )
  )
  (i32.const 1)
 )
 (func $main (result i32)
  (i32.store
   (i32.const 0)
   (i32.const 85)
  )
  (i32.store
   (i32.const 4)
   (i32.const 90)
  )
  (i32.store
   (i32.const 8)
   (i32.const 23)
  )
  (i32.store
   (i32.const 16)
   (i32.const 0)
  )
  (i32.store
   (i32.const 28)
   (i32.const 3)
  )
  (i32.load
   (i32.add
    (i32.load
     (i32.const 20)
    )
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
