{
  "targets": [
    {
      "target_name": "hello",
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
       ],
      "sources": [ "hello.cc" ]
    }
  ]
}
