####################################################################################################
### Setting up versioning with CMake, the version is chosen based on modern cmake.               ###
### It is important to keep the minimum version above 3.12 as this project uses CMake features   ###
### from this release, and also because it might cause linker errors on lower versions on MacOS. ###
###                                                                                              ###
### See: https://cliutils.gitlab.io/modern-cmake/chapters/basics.html                            ###
####################################################################################################
cmake_minimum_required(VERSION 3.12...3.18)


#####################################################################################################
### Set library name to: http_client                                                              ###
### Set c++ standard to: C++17                                                                    ###
###                                                                                               ###
### See: https://cliutils.gitlab.io/modern-cmake/chapters/features/cpp11.html                     ###
#####################################################################################################
set(LIBRARY_NAME http_client)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


####################################################################################################
### Using CMake 3.12+ GLOB feature for finding source files                                      ###
### Create the tests executable with the modules included to tests them                          ###
####################################################################################################
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS ./include/*.hpp)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ./src/*.cpp)


####################################################################################################
### Create the library with the following and do the following:                                  ###
### - Link all the conan libraries                                                               ###
### - Publicly include the ./include folder, this enforces only exposing the .hpp files          ###
### - Set the c++ standard to 17, so consuming libraries know this library is build with c++17.  ###
### Create the tests executable with the modules included to tests them                          ###
####################################################################################################
add_library(${LIBRARY_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${LIBRARY_NAME} ${CONAN_LIBS})
target_include_directories(${LIBRARY_NAME} PUBLIC ./include)
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_17)