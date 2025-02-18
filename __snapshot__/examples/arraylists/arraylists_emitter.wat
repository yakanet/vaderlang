(module
 (type $0 (array (mut i32)))
 (type $1 (struct (field (mut (ref $0))) (field (mut i32))))
 (type $2 (func (param i32)))
 (type $3 (func (param (ref $1) i32)))
 (type $4 (func))
 (import "wasi_snapshot_preview1" "proc_exit" (func $wasi_snapshot_preview1:proc_exit (type $2) (param i32)))
 (memory $0 1)
 (export "memory" (memory $0))
 (start $_start)
 (func $push (type $3) (param $0 (ref $1)) (param $1 i32)
  (local $2 i32)
  (local $3 (ref $0))
  (local $4 i32)
  (if
   (i32.le_u
    (local.tee $4
     (array.len
      (struct.get $1 0
       (local.get $0)
      )
     )
    )
    (struct.get $1 1
     (local.get $0)
    )
   )
   (then
    (local.set $3
     (array.new_default $0
      (i32.shl
       (local.get $4)
       (i32.const 1)
      )
     )
    )
    (loop $outer_0
     (if
      (i32.lt_u
       (local.get $2)
       (struct.get $1 1
        (local.get $0)
       )
      )
      (then
       (array.set $0
        (local.get $3)
        (local.get $2)
        (array.get $0
         (struct.get $1 0
          (local.get $0)
         )
         (local.get $2)
        )
       )
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
    (struct.set $1 0
     (local.get $0)
     (local.get $3)
    )
   )
  )
  (array.set $0
   (struct.get $1 0
    (local.get $0)
   )
   (struct.get $1 1
    (local.get $0)
   )
   (local.get $1)
  )
  (struct.set $1 1
   (local.get $0)
   (i32.add
    (struct.get $1 1
     (local.get $0)
    )
    (i32.const 1)
   )
  )
 )
 (func $_start (type $4)
  (local $0 (ref $1))
  (call $push
   (local.tee $0
    (struct.new $1
     (array.new_default $0
      (i32.const 2)
     )
     (i32.const 0)
    )
   )
   (i32.const 3)
  )
  (call $push
   (local.get $0)
   (i32.const 4)
  )
  (call $push
   (local.get $0)
   (i32.const 5)
  )
  (call $wasi_snapshot_preview1:proc_exit
   (array.get $0
    (struct.get $1 0
     (local.get $0)
    )
    (i32.const 2)
   )
  )
 )
)
