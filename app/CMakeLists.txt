####################################################################################################
### Setting up versioning with CMake, the version is chosen based on modern cmake.               ###
### It is important to keep the minimum version above 3.12 as this project uses CMake features   ###
### from this release, and also because it might cause linker errors on lower versions on MacOS. ###
###                                                                                              ###
### See: https://cliutils.gitlab.io/modern-cmake/chapters/basics.html                            ###
####################################################################################################
cmake_minimum_required(VERSION 3.12...3.18)

####################################################################################################
### Create the executable with:                                                                  ###
### - Only need to include main.cpp                                                              ###
### - Set the c++ standard to 17.                                                                ###
### - Link the http_client library for internal use only (PRIVATE).                              ###
####################################################################################################
set(EXECUTABLE_NAME ${APPLICATION_NAME})
add_executable(${EXECUTABLE_NAME} main.cpp)
target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_17)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE http_client)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE krul_interpreter)