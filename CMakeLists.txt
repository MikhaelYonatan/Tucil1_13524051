cmake_minimum_required(VERSION 3.10.0)

project(TucilStima1 VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(QueensGame
    src/main.cpp 
    src/fileproc.cpp 
    src/imgproc.cpp 
    src/queen.cpp
)

target_link_libraries( QueensGame ${OpenCV_LIBS} )