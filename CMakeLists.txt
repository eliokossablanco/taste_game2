cmake_minimum_required(VERSION 4.0)
project(taste_game)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
#set_target_properties(main.cpp PROPERTIES LINKER_LANGUAGE CXX)

add_executable(taste_game src/main.cpp
        include/Customer.h
        include/Food.h
        include/Palate.h
        src/main.cpp
        src/Game.cpp
        src/Palate.cpp
        src/Food.cpp
        src/Customer.cpp
)
