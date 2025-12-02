cmake_minimum_required(VERSION 4.0)
#set( CMAKE_CXX_COMPILER "/mysys64/usr/bin/gcc" )
#set( CMAKE_C_COMPILER "/mysys64/usr/bin/gcc" )
project(taste_game)

set(CMAKE_CXX_STANDARD 20)

#enable_testing()

#add_executable(test_feature
#        tests/test_features.cpp
#        src/Game.cpp
#        src/Palate.cpp
#)

#add_test(NAME featureTests COMMAND test_feature)

#include_directories(include)

add_executable(taste_game src/main.cpp
        ../taste_game2/include/Customer.h
        ../taste_game2/include/Food.h
        ../taste_game2/include/Palate.h
        src/main.cpp
        ../taste_game2/src/Game.cpp
        ../taste_game2/src/Palate.cpp
        ../taste_game2/src/Food.cpp
        ../taste_game2/src/Customer.cpp
)

#set_target_properties(taste_game src/Main.cpp PROPERTIES LINKER_LANGUAGE CXX)
