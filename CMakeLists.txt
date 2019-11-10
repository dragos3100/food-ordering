cmake_minimum_required(VERSION 3.15)
project(food_ordering)

set(CMAKE_CXX_STANDARD 14)

add_executable(food_ordering login.c login.h main.c preference.c preference.h print.c print.h choice.c choice.h)