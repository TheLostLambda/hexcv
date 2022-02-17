project('hexcv', 'cpp')
opencv = dependency('opencv4')
clang_args = ['-std=c++20', '-fmodules', '-fbuiltin-module-map']

executable('showcam', 'bin/showcam.cpp',
  dependencies : opencv,
  cpp_args : clang_args)

executable('east', 'bin/east.cpp',
  dependencies : opencv,
  cpp_args : clang_args)

executable('picam', 'bin/picam.cpp',
  include_directories : 'lib',
  dependencies : opencv,
  cpp_args : clang_args)

executable('shape-rec', 'bin/shape-rec.cpp',
  dependencies : opencv,
  cpp_args : clang_args)
