test_src = files(
  'test.c',
  'common.c',
)
test_inc = include_directories('.')

#############
# Tetrimino #
#############

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

#########
# Field #
#########

test_field_src = files(
  'test_field.c',
)

test_field_bin = executable(
  'test_field',
  test_src,
  test_field_src,
  src,
  include_directories: [
    test_inc,
    inc,
  ],
  c_args: flags,
)

run_target(
  'test-field',
  command: [
    test_field_bin.full_path()
  ],
  depends: test_field_bin,
)

test('test-field', test_field_bin)
