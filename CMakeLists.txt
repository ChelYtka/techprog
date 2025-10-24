cmake_minimum_required(VERSION 3.10)
project(TechProg)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление исполняемого файла со всеми исходными файлами
add_executable(main
    main.cpp
    Necklace.cpp
    Gemstone.cpp
    PreciousGemstone.cpp    # Добавьте это
    SemiPreciousGemstone.cpp # Добавьте это
    Diamond.cpp
    Ruby.cpp
    Amethyst.cpp
    Topaz.cpp
)

# Если используете C++17 функции
target_compile_features(main PRIVATE cxx_std_17)