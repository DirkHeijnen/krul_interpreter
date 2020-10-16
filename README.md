
# Modular Magic

[![YourActionName Actions Status](https://github.com/DirkHeijnen/krul_interpreter/workflows/ci/badge.svg)](https://github.com/DirkHeijnen/krul_interpreter/actions)


## Features

- Libcurl wrapper for more modern feel with HttpClient.
- Using Conan package manager for a modern and easy way of third party dependency management.
- Use of modern [CMake](https://cliutils.gitlab.io/modern-cmake/) 
- Testing with gtest
- Continuous Integration with Github Actions


### Setup

To work with this repository you need:

- Conan package manager: [conan](https://conan.io/downloads.html)
- Cmake: [cmake](https://cmake.org/install/)


The conan profile used:
```text
[settings]
arch=x86_64
arch_build=x86_64
build_type=Debug
compiler=Visual Studio
compiler.version=16
os=Windows
os_build=Windows
[options]
[build_requires]
[env]
```


To get the code on your machine simply use:

```shell
$ git clone https://github.com/DirkHeijnen/krul_interpreter
```

### Building

You can choose to build it manually using the following commands:
```shell
$ mkdir build && cd build
$ conan install .. --build=missing
$ cmake -DCMAKE_BUILD_TYPE=Debug
$ cmake ..
$ cmake --build .
```

But modern IDE's usually have their own cmake support, so for example,
Clion will make a cmake-build-debug or cmake-build-release folder.

