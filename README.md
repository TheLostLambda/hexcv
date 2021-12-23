# Running Demos
Should be in the `build` directory and can be run like any other program.
OpenCV is a little strange and requires arguments to be passed using `=`, like the following:
```
./east --dmp=../models/frozen_east_text_detection.pb --rmp=../models/crnn.onnx --vp=../models/alphabet_36.txt
```

# Toolchain
  - C++20 (no real excuse to use old standards)
  - C++ Modules (header files are disgusting)
  - Meson (less abhorrent than Make or CMake)
  - OpenCV (most mature computer vision library around)
  - Clang (has better linting, formatting, and module support)
  - Mold (because even linkers need to be specified...)
  - ccache (for some reason this isn't the default?)

# Learning Resources
  - [Meson Example](https://mesonbuild.com/GuiTutorial.html)

## Character Recognition
  - [Rotation Invariant Pooling](https://stats.stackexchange.com/questions/239076/about-cnn-kernels-and-scale-rotation-invariance)
  - [CRAFT](https://arxiv.org/pdf/1904.01941.pdf)
  - [Modern Text Detection](https://medium.com/technovators/scene-text-detection-in-python-with-east-and-craft-cbe03dda35d5)
