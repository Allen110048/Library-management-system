cmake_minimum_required(VERSION 3.16)

project(library)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-fdump-rtl-expand")

add_executable(library main.c interface1.c Login_and_register.c User.c book_management1.c)

install(TARGETS library RUNTIME DESTINATION bin)