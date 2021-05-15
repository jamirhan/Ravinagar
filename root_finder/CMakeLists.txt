cmake_minimum_required(VERSION 2.8.3)

project(root_finder)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -fPIC")
# set(CMAKE_CXX_FLAGS "-std=c++11 -pg")

#set(EIGEN_DIR Eigen3)

#find_package(Eigen3 REQUIRED)

include_directories(
    include
    Eigen3
)

#add_library(Root_Finder SHARED "include/root_finder/root_finder.hpp")

add_executable(${PROJECT_NAME} example/root_finder_example.cpp example/JenkinsTraub/jt.cpp)
