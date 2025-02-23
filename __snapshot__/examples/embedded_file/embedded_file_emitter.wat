(module
 (type $0 (func (param i32 i32 i32 i32) (result i32)))
 (type $1 (func))
 (import "wasi_snapshot_preview1" "fd_write" (func $wasi_snapshot_preview1:fd_write (type $0) (param i32 i32 i32 i32) (result i32)))
 (memory $0 1)
 (data $0 (i32.const 0) "@load \"std\"\n\nmain :: fn() {\n    print(@file(\"./embedded_file.vader\"))\n}")
 (export "memory" (memory $0))
 (start $main)
 (func $main (type $1)
  (i32.store
   (i32.const 72)
   (i32.const 0)
  )
  (i32.store
   (i32.const 76)
   (i32.const 71)
  )
  (drop
   (call $wasi_snapshot_preview1:fd_write
    (i32.const 1)
    (i32.const 72)
    (i32.const 1)
    (i32.const 80)
   )
  )
 )
)
