cmake_minimum_required(VERSION 2.8)

project(engine)

add_executable(engine ShipAI.cpp ShipSensor.cpp ShipInput.cpp Asteroid.cpp Bullet.cpp Math.cpp Ship.cpp Asteroids.cpp BreakoutLevel2.cpp BreakoutLevel1.cpp Brick.cpp Breakout.cpp Collider.cpp Component.cpp main.cpp Game.cpp Pong.cpp Scene.cpp GameObject.cpp Ball.cpp Paddle.cpp EnemyPaddle.cpp Wall.cpp GUI.cpp ShipAI.h ShipSensor.h ShipInput.h Asteroid.h Bullet.h Math.h Ship.h Asteroids.h BreakoutLevel2.h BreakoutLevel1.h Brick.h Breakout.h Collider.h Component.h Game.h Pong.h Scene.h GameObject.h Ball.h Paddle.h EnemyPaddle.h Wall.h GUI.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ggdb")


set(CMAKE_MODULE_PATH $(CMAKE_MODULE_PATH) "${CMAKE_SOURCE_DIR}/build")
find_package(SFML REQUIRED COMPONENTS graphics window system)

include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries (engine ${SFML_LIBRARIES})

install(TARGETS engine RUNTIME DESTINATION bin)

add_custom_target(run
    COMMAND engine
    DEPENDS engine
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
