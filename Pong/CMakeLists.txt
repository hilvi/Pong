cmake_minimum_required(VERSION 2.8)

project(engine)

add_executable(engine main.cpp Game.cpp Pong.cpp Scene.cpp GameObject.cpp Ball.cpp Paddle.cpp EnemyPaddle.cpp Wall.cpp GUI.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SFML REQUIRED COMPONENTS graphics window system)

include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries (engine ${SFML_LIBRARIES})

install(TARGETS engine RUNTIME DESTINATION bin)
