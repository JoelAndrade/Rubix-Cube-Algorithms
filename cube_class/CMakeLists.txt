file(GLOB SOURCES *.cpp)

add_library(lib_cube_class ${SOURCES})

target_link_libraries(lib_cube_class
    lib_SDL2
)
