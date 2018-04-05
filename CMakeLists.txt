cmake_minimum_required(VERSION 2.6)
project(simple-game-engine)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

if (WIN32)
set(SDL2_PATH "${PROJECT_SOURCE_DIR}/dependencies/SDL2-2.0.5")
set(SDL2_TTF_PATH "${PROJECT_SOURCE_DIR}/dependencies/SDL2_ttf-2.0.14")
set(SDL2_IMAGE_PATH "${PROJECT_SOURCE_DIR}/dependencies/SDL2_image-2.0.1")
endif(WIN32)

find_package(SDL2_ttf REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} 
                    ${SDL2_TTF_INCLUDE_DIR} 
                    ${SDL2_IMAGE_INCLUDE_DIR} 
                    ${PROJECT_SOURCE_DIR}/include)


file(GLOB src_files src/*.cpp src/*/*.cpp)
add_library(game_engine_lib ${src_files})


add_executable(game main.cpp)
target_link_libraries(game game_engine_lib)
target_link_libraries(game ${SDL2_LIBRARY})
target_link_libraries(game ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(game ${SDL2_TTF_LIBRARIES})

#install(TARGETS game RUNTIME DESTINATION bin)

file(COPY "${PROJECT_SOURCE_DIR}/assets" DESTINATION "./")
