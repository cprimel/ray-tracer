cmake_minimum_required(VERSION 3.17)
project(ray_tracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ray_tracer src/main.cpp src/vec3.h src/color.h src/ray.h)