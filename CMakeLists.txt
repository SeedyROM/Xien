cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME Xien)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp src/Engine.cpp src/Engine.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Add SFML
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

# Add libyaml
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libyaml-cpp.a)