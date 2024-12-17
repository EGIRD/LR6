cmake_minimum_required(VERSION 3.10)
project(LR6)

add_library(Task1 STATIC Task_1.cpp)
add_library(Task2 STATIC Task_2.cpp)
add_library(Task3 STATIC Task_3.cpp)

add_executable(main main.cpp)
target_link_libraries(main Task1 Task2 Task3)

add_executable(main_address main.cpp)
target_compile_options(main_address PRIVATE -fsanitize=address)
target_link_libraries(main_address PRIVATE Task1 Task2 Task3 -fsanitize=address)

add_executable(main_leak main.cpp)
target_compile_options(main_leak PRIVATE -fsanitize=leak)
target_link_libraries(main_leak PRIVATE Task1 Task2 Task3 -fsanitize=leak)

#add_executable(main_undefined main.cpp)
#target_compile_options(main_undefined PRIVATE -fsanitize=undefined)
#target_link_libraries(main_undefined PRIVATE Task1 Task2 Task3 -fsanitize=undefined)

#cmake --build . --target main_address
#./main_address