test_tetrimino_src = files(
  'test_tetrimino.c',
)

test_tetrimino_bin = executable(
  'test_tetrimino',
  test_src,
  test_tetrimino_src,
  src,
  include_directories: [
    test_inc,
    inc,
  ],
  c_args: flags,
)

run_target(
  'test-tetrimino',
  command: [
    test_tetrimino_bin.full_path()
  ],
  depends: test_tetrimino_bin,
)

test('test-tetrimino', test_tetrimino_bin)
