cmake_minimum_required(VERSION 3.30)

project(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(cube_class)
add_subdirectory(cube_mode)
add_subdirectory(SDL2-Utilites)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(main main.cpp)
add_executable(Algorithm_Maker main.cpp Images/icon.rc)

target_link_libraries(main
    lib_cube_class
    lib_cube_mode
    lib_SDL2
)

target_link_libraries(main
    "-l mingw32"
)

target_link_libraries(Algorithm_Maker
    lib_cube_class
    lib_cube_mode
    lib_SDL2
)

target_link_libraries(Algorithm_Maker
    "-l mingw32"
    "-mwindows"
    "-static-libgcc"
    "-static-libstdc++"
)
