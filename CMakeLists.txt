cmake_minimum_required(VERSION 4.0)
project(SoLoud)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(SoLoudLib SHARED)

file(GLOB CORE_SRC SOURCES CONFIGURE_DEPENDS "core/*.cpp")
file(GLOB HEADER_SRC SOURCES CONFIGURE_DEPENDS "include/*.h")

target_sources(SoLoudLib
    PRIVATE
        ${CORE_SRC}
        src/c_api/soloud_c.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
            ${HEADER_SRC}
)

target_compile_features(SoLoudLib PRIVATE cxx_std_20)

# Hmmm...yes, for anuke, SDL2 as backends is needed.
find_package(SDL2 REQUIRED)

target_compile_definitions(SoLoudLib PRIVATE WITH_SDL2)
target_include_directories(SoLoudLib PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(SoLoudLib PRIVATE ${SDL2_LIBRARIES})
