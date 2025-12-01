cmake_minimum_required(VERSION 4.0)
set( CMAKE_CXX_COMPILER "/mysys64/usr/bin/gcc" )
set( CMAKE_C_COMPILER "/mysys64/usr/bin/gcc" )
project(taste_game)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_executable(test_feature
        tests/test_features.cpp
        src/Game.cpp
        src/Palate.cpp
)

add_test(NAME featureTests COMMAND test_feature)

include_directories(include)

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

#set_target_properties(taste_game src/Main.cpp PROPERTIES LINKER_LANGUAGE CXX)
