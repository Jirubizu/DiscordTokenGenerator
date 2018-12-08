cmake_minimum_required(VERSION 2.8)

project(DiscordTokenGenerator)
file (GLOB_RECURSE HEADERS src/*.h src/*.hpp)
file (GLOB_RECURSE SOURCES src/*.cpp)

add_executable(DiscordTokenGenerator ${HEADERS} ${SOURCES})

set(CMAKE_EXE_LINKER_FLAGS " -static")
target_link_libraries(DiscordTokenGenerator -static-libgcc -static-libstdc++)

set_target_properties (
    DiscordTokenGenerator PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_FLAGS "-std=c++17 -Wall"
)
