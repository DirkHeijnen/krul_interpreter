from conans import ConanFile, CMake
from conans.tools import os_info

class Cpp1Conan(ConanFile):
    name = "Cpp1"
    version = "0.1"
    url = "https://github.com/DirkHeijnen/krul_interpreter"
    description = "Eindopdracht cpp1"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def requirements(self):
        self.requires("libcurl/7.72.0")                         # Used for HTTP calls
        self.requires("gtest/1.10.0")                           # Used for unit testing


    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        cmake.test()