cmake_minimum_required(VERSION 2.6)
project(breakout)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} 
                    ${SDL2_TTF_INCLUDE_DIR} 
                    ${SDL2_IMAGE_INCLUDE_DIR} 
                    ${PROJECT_SOURCE_DIR}/include)


file(GLOB src_files src/*.cpp src/*/*.cpp)
add_library(breakout_lib ${src_files})


add_executable(breakout main.cpp)
target_link_libraries(breakout breakout_lib)
target_link_libraries(breakout ${SDL2_LIBRARY})
target_link_libraries(breakout ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(breakout ${SDL2_TTF_LIBRARIES})

install(TARGETS breakout RUNTIME DESTINATION bin)
