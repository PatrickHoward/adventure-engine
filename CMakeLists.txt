cmake_minimum_required(VERSION 3.1)
project(adventure-engine)

set(CMAKE_CXX_FLAGS "-Wall")

add_executable( adventure

                src/adventure.cpp
                src/rooms/rooms.cpp
                src/player/player.cpp
                src/command/command.cpp
                src/actions/actions.cpp
              )
