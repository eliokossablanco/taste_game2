cmake_minimum_required(VERSION 4.0)
<<<<<<< HEAD
project(taste_game2)

set(CMAKE_CXX_STANDARD 20)
=======
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
>>>>>>> 71366b96cd8d9295a362d7815a6ab7436647d4e7

#include_directories(include)

<<<<<<< HEAD
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
=======
add_executable(taste_game src/main.cpp
        ../taste_game2/include/Customer.h
        ../taste_game2/include/Food.h
        ../taste_game2/include/Palate.h
        src/main.cpp
        ../taste_game2/src/Game.cpp
        ../taste_game2/src/Palate.cpp
        ../taste_game2/src/Food.cpp
        ../taste_game2/src/Customer.cpp
>>>>>>> 71366b96cd8d9295a362d7815a6ab7436647d4e7
)
