project(
  'botTetris',
  'c',
  default_options : [
    'c_std=gnu11',
  ]
)

c_compiler = meson.get_compiler('c')
root_dir = meson.source_root()

flags = c_compiler.get_supported_arguments(
  [
    '-Wall',
    '-Werror',
    '-D_GNU_SOURCE',
    '-march=native',
    '-Wunused',
    '-Wunused-value',
    '-Wunused-variable',
    '-Wunused-parameter',
    '-Wbool-compare',
    '-Wformat-security',
    '-Winit-self',
    '-Wlogical-op',
    '-Wtrampolines',
    '-Wmissing-format-attribute',
    '-Wno-error=deprecated-declarations',
    '-Wno-format-zero-length',
    '-pipe',
    '-g3',
    '-pthread',
    '-fstack-protector',
    '-funwind-tables',
    '-fasynchronous-unwind-tables',
    '-fstack-protector-strong',
    '-fno-common',
    '-Wshadow',
    '-Wmissing-declarations',
    '-Wpointer-arith',
    '-Wformat=2',
    '-mpclmul',
    '-msse4.1',
  ]
)

inc = include_directories(
  'src',
)

src = files(
  'src/tetrimino.c',
  'src/field.c',
  'src/eval.c',
  'src/strategy.c',
)

# binary
botTetris = executable(
  'botTetris',
  src,
  'src/main.c',
  include_directories: inc,
  c_args: flags,
)

subdir('tests')
