cmake_minimum_required(VERSION 3.28)
project(openglproject)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp
        share/stb/stb_image.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(share)
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} logger)
target_link_libraries(${PROJECT_NAME} shader)
target_link_libraries(${PROJECT_NAME} glm::glm-header-only)
#target_link_libraries(${PROJECT_NAME} math)
#target_link_libraries(${PROJECT_NAME} stb)
target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_SOURCE_DIR}/src/logger"
#        "${PROJECT_SOURCE_DIR}/share/stb"
        "${PROJECT_SOURCE_DIR}/src/shader"
)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

