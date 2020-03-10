cmake_minimum_required(VERSION 3.15)
project(Matrix3D)

set(CMAKE_CXX_STANDARD 14)

add_executable(Matrix3D main.cpp Vector3D.cpp Vector3D.h Matrix3D.cpp Matrix3D.h)