cmake_minimum_required(VERSION 3.5)

project(catbot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_custom_target(catbot_version
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/version.sh
    ${CMAKE_CURRENT_BINARY_DIR}/version.h)

add_executable(catbot main.cpp commands.cpp
    millipic.cpp catmessage.cpp catbot.h)

target_include_directories(catbot PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
add_dependencies(catbot catbot_version)

target_link_libraries(catbot PUBLIC
    TgBot
    boost_system
    boost_filesystem
    ssl
    crypto
    pthread
)
