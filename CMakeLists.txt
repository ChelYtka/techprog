cmake_minimum_required(VERSION 3.10)
project(lab4)

set(CMAKE_CXX_STANDARD 11)

# Добавляем все исходные файлы
add_executable(main
    main.cpp
    dictionary.cpp
    word.cpp
    wordFactory.cpp
    consoleView.cpp
    consoleController.cpp
)

# Указываем включаемые директории
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})