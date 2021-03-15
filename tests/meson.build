test_src = files(
  'test.c',
  'common.c',
)

test_inc = include_directories('.')

tests = [
  'tetrimino',
  'field',
  'eval',
  'strategy',
]

foreach test : tests
  test_name = 'test_' + test
  test_file = join_paths(meson.source_root(), 'tests', test_name + '.c')
  message(test_file)

  bin = executable(
    test_name,
    test_src,
    test_file,
    src,
    include_directories: [ test_inc, inc, ],
    c_args: flags,
  )

 run_target(
   test_name,
   command: [ bin.full_path() ],
   depends: bin,
 )

 test(test_name, bin)

endforeach
