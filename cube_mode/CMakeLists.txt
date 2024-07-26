file(GLOB SOURCES *.cpp)

add_library(lib_cube_mode ${SOURCES})

target_include_directories(lib_cube_mode PUBLIC 
    ..
    ../cube_class
)

target_link_libraries(lib_cube_mode PUBLIC
    lib_SDL2
    lib_cube_class
)

