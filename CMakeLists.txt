cmake_minimum_required(VERSION 3.5)

project(catbot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(catbot main.cpp commands.cpp
    millipic.cpp catmessage.cpp catbot.h)

target_link_libraries(catbot PUBLIC TgBot boost_system
    boost_filesystem ssl crypto pthread)
