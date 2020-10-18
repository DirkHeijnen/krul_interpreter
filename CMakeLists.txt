####################################################################################################
### Setting up versioning with CMake, the version is chosen based on modern cmake.               ###
### It is important to keep the minimum version above 3.12 as this project uses CMake features   ###
### from this release, and also because it might cause linker errors on lower versions on MacOS. ###
###                                                                                              ###
### See: https://cliutils.gitlab.io/modern-cmake/chapters/basics.html                            ###
####################################################################################################
cmake_minimum_required(VERSION 3.12...3.18)


####################################################################################################
### Set project to use c++ 17.                                                                   ###
### See: https://cliutils.gitlab.io/modern-cmake/chapters/features/cpp11.html                    ###
####################################################################################################
set(APPLICATION_NAME cpp1_eindopdracht)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


####################################################################################################
### Defining project specific fields                                                             ###
### See: https://cliutils.gitlab.io/modern-cmake/chapters/basics/example.html                    ###
####################################################################################################
project(${APPLICATION_NAME} VERSION 1.0 DESCRIPTION "CPP1 eindopdracht" LANGUAGES CXX)


####################################################################################################
### Defining command line options which can be set via cmake (-DENABLE_TESTING=[ON|OFF]          ###
####################################################################################################
set(ENABLE_TESTING_TEXT "Whether to generate unit test program and test")
option(ENABLE_TESTING ${ENABLE_TESTING_TEXT} ON)


####################################################################################################
### Add support for conan                                                                        ###
####################################################################################################
if (WIN32)
    if(CONAN_EXPORTED)
        include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
        conan_basic_setup()
    else()
        include("${CMAKE_SOURCE_DIR}/cmake/conan.cmake")
        conan_cmake_run(CONANFILE conanfile.py BASIC_SETUP BUILD missing)
    endif()
else()
    include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif()


####################################################################################################
### Add custom cmake scripts                                                                     ###
####################################################################################################
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/find" ${CMAKE_MODULE_PATH})
file(GLOB "${CMAKE_SOURCE_DIR}/cmake/*.cmake")
foreach(SCRIPT ${CMAKE_SCRIPTS})
    message(STATUS Adding custom cmake to the project: ${SCRIPT})
    include(${SCRIPT})
endforeach()


####################################################################################################
### Add the different modules are required for this app.                                          ###
####################################################################################################
add_subdirectory(app)
add_subdirectory(modules/HttpClient)
add_subdirectory(modules/KrulInterpreter)
if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()