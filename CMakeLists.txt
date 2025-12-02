cmake_minimum_required(VERSION 4.0)
project(taste_game2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(taste_game2 src/main.cpp
        include/Customer.h
        include/Food.h
        include/Palate.h
        src/main.cpp
        include/Game.h
        src/Game.cpp
        src/Palate.cpp
        src/Food.cpp
        src/Customer.cpp
        src/Game.cpp
)
