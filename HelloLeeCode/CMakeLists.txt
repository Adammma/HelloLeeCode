cmake_minimum_required(VERSION 3.23)
project(HelloLeeCode)

set(CMAKE_CXX_STANDARD 14)
#include_directories(./glad/include)
#include_directories(/opt/homebrew/Cellar/glfw/3.3.8/include)
#include_directories(/opt/homebrew/Cellar/glew/2.2.0_1/include)
add_executable(HelloLeeCode Tree/rightSideView.cpp)
#        GLTest.cpp)
#target_link_libraries(HelloLeeCode
#        /opt/homebrew/Cellar/glfw/3.3.8/lib/libglfw.dylib
#        /opt/homebrew/Cellar/glew/2.2.0_1/lib/libGLEW.dylib
#        )
