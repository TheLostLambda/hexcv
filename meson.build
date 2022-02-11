project('hexcv', 'cpp')
opencv = dependency('opencv4')
clang_args = ['-std=c++20']

executable('showcam', 'showcam.cpp',
  dependencies : opencv,
  cpp_args : clang_args)

executable('east', 'east.cpp',
  dependencies : opencv,
  cpp_args : clang_args)


executable('shape-rec', 'shape-rec.cpp',
  dependencies : opencv,
  cpp_args : clang_args)
