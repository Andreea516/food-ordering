cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 11)

add_executable(food_ordering main.c customer.h customer.c order.c order.h)