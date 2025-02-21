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
   ;;@ modules/arraylist.vader:31:8
   (i32.le_u
    ;;@ modules/arraylist.vader:31:23
    (local.tee $4
     (array.len
      (struct.get $1 0
       (local.get $0)
      )
     )
    )
    ;;@ modules/arraylist.vader:31:8
    (struct.get $1 1
     (local.get $0)
    )
   )
   (then
    ;;@ modules/arraylist.vader:23:5
    (local.set $3
     ;;@ modules/arraylist.vader:23:13
     (array.new_default $0
      ;;@ modules/arraylist.vader:23:14
      (i32.shl
       (local.get $4)
       ;;@ modules/arraylist.vader:23:35
       (i32.const 1)
      )
     )
    )
    ;;@
    (loop $outer_0
     (if
      ;;@ modules/arraylist.vader:24:18
      (i32.lt_u
       (local.get $2)
       ;;@ modules/arraylist.vader:24:22
       (struct.get $1 1
        (local.get $0)
       )
      )
      (then
       ;;@ modules/arraylist.vader:25:9
       (array.set $0
        (local.get $3)
        ;;@ modules/arraylist.vader:25:14
        (local.get $2)
        ;;@ modules/arraylist.vader:25:19
        (array.get $0
         ;;@
         (struct.get $1 0
          ;;@ modules/arraylist.vader:25:19
          (local.get $0)
         )
         ;;@ modules/arraylist.vader:25:29
         (local.get $2)
        )
       )
       ;;@ modules/arraylist.vader:24:35
       (local.set $2
        ;;@ modules/arraylist.vader:24:39
        (i32.add
         (local.get $2)
         ;;@ modules/arraylist.vader:24:43
         (i32.const 1)
        )
       )
       ;;@
       (br $outer_0)
      )
     )
    )
    ;;@ modules/arraylist.vader:27:5
    (struct.set $1 0
     (local.get $0)
     ;;@ modules/arraylist.vader:27:17
     (local.get $3)
    )
   )
  )
  ;;@ modules/arraylist.vader:34:5
  (array.set $0
   ;;@
   (struct.get $1 0
    ;;@ modules/arraylist.vader:34:5
    (local.get $0)
   )
   ;;@ modules/arraylist.vader:34:15
   (struct.get $1 1
    (local.get $0)
   )
   ;;@ modules/arraylist.vader:34:30
   (local.get $1)
  )
  ;;@ modules/arraylist.vader:35:5
  (struct.set $1 1
   (local.get $0)
   ;;@ modules/arraylist.vader:35:19
   (i32.add
    (struct.get $1 1
     (local.get $0)
    )
    ;;@ modules/arraylist.vader:35:33
    (i32.const 1)
   )
  )
 )
 (func $_start (type $4)
  (local $0 (ref $1))
  ;;@ examples/arraylists.vader:5:5
  (call $push
   ;;@ examples/arraylists.vader:4:5
   (local.tee $0
    ;;@ modules/arraylist.vader:10:12
    (struct.new $1
     ;;@ modules/arraylist.vader:11:19
     (array.new_default $0
      ;;@ modules/arraylist.vader:11:20
      (i32.const 2)
     )
     ;;@ modules/arraylist.vader:12:19
     (i32.const 0)
    )
   )
   ;;@ examples/arraylists.vader:5:15
   (i32.const 3)
  )
  ;;@ examples/arraylists.vader:6:5
  (call $push
   (local.get $0)
   ;;@ examples/arraylists.vader:6:15
   (i32.const 4)
  )
  ;;@ examples/arraylists.vader:7:5
  (call $push
   (local.get $0)
   ;;@ examples/arraylists.vader:7:15
   (i32.const 5)
  )
  ;;@
  (call $wasi_snapshot_preview1:proc_exit
   ;;@ modules/arraylist.vader:18:12
   (array.get $0
    ;;@
    (struct.get $1 0
     ;;@ examples/arraylists.vader:8:12
     (local.get $0)
    )
    ;;@ modules/arraylist.vader:18:22
    (i32.const 2)
   )
  )
 )
)
