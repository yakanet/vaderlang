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
  ;;@ examples/fibonacci.vader:3:5
  (local.set $2
   ;;@ examples/fibonacci.vader:3:10
   (i32.const 1)
  )
  ;;@ examples/fibonacci.vader:4:9
  (local.set $1
   ;;@ examples/fibonacci.vader:4:14
   (i32.const 1)
  )
  ;;@
  (loop $outer_0
   (if
    ;;@ examples/fibonacci.vader:4:18
    (i32.le_u
     (local.get $1)
     ;;@ examples/fibonacci.vader:4:22
     (i32.const 10)
    )
    (then
     ;;@ examples/fibonacci.vader:5:9
     (local.set $3
      ;;@ examples/fibonacci.vader:5:14
      (local.get $0)
     )
     ;;@ examples/fibonacci.vader:7:9
     (local.set $2
      ;;@ examples/fibonacci.vader:7:13
      (i32.add
       (local.get $3)
       ;;@ examples/fibonacci.vader:6:9
       (local.tee $0
        ;;@ examples/fibonacci.vader:6:13
        (local.get $2)
       )
      )
     )
     ;;@ examples/fibonacci.vader:4:27
     (local.set $1
      ;;@ examples/fibonacci.vader:4:31
      (i32.add
       (local.get $1)
       ;;@ examples/fibonacci.vader:4:35
       (i32.const 1)
      )
     )
     ;;@
     (br $outer_0)
    )
   )
  )
  ;;@
  (call $wasi_snapshot_preview1:proc_exit
   ;;@ examples/fibonacci.vader:9:12
   (local.get $0)
  )
 )
)
