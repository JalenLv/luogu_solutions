add_executable(my_app
  main.cpp
  print.cpp
)

target_compile_options(my_app
  PUBLIC
    -std=c++11
    -Wall
    -Wextra
)

target_include_directories(my_app
  PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
