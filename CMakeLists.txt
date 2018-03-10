cmake_minimum_required(VERSION 2.6)
project(breakout)


find_package(SDL2 REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(SDL_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)


file(GLOB src_files src/*.cpp src/*/*.cpp)
add_library(breakout_lib ${src_files})


add_executable(breakout main.cpp)
target_link_libraries(breakout breakout_lib)
target_link_libraries(breakout ${SDL2_LIBRARIES})
target_link_libraries(breakout ${SDLIMAGE_LIBRARY})
target_link_libraries(breakout ${SDLTTF_LIBRARY})

install(TARGETS breakout RUNTIME DESTINATION bin)
