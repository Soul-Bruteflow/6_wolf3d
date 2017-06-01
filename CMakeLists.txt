cmake_minimum_required(VERSION 3.6)
project(wolf3d)

file(GLOB SOURCES ./src/*.c)

set(LIB_PATH libft)

set(HOME_FLAGS "-I /usr/X11/include -g -L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit -pthread")
set(MACOS_FLAGS "-I ./inc -I ./frameworks/SDL2/Versions/A/Headers -F ./frameworks -framework SDL2")
set(CMAKE_C_FLAGS ${MACOS_FLAGS})
set(SOURCE_FILES ${SOURCES})
include_directories("./libft/" "./inc")
add_executable(wolf3d ${SOURCE_FILES})


file(GLOB SOURCES_LIB ${LIB_PATH}/*.c)
add_library(ft STATIC ${SOURCES_LIB}/)

target_link_libraries(wolf3d ft)