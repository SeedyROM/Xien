cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME Xien)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp src/Engine.cpp src/Engine.h)
include_directories(src)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Add SFML
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

# Add libyaml
include_directories(${CMAKE_SOURCE_DIR}/lib/libyaml/include)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lib/libyaml/libyaml-cpp.a)

# Add boost
find_package(Boost 1.55.0 REQUIRED COMPONENTS system filesystem)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

# Add selene
include_directories(${CMAKE_SOURCE_DIR}/lib/selene/include)