cmake_minimum_required(VERSION 3.11)

set(PROJECT_NAME "pamsi")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CXX_GNU_COMPILE_FLAGS "-Wall -pedantic")
set(CXX_CLANG_COMPILE_FLAGS "-Wall -pedantic")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  list(APPEND CMAKE_CXX_FLAGS  ${CXX_GNU_COMPILE_FLAGS})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  list(APPEND CMAKE_CXX_FLAGS  ${CXX_CLANG_COMPILE_FLAGS})
endif()

add_library(List INTERFACE)
target_sources(List INTERFACE List.hpp)

target_include_directories(List INTERFACE
"${PROJECT_SOURCE_DIR}/include")

add_library(Stack INTERFACE)
target_sources(Stack INTERFACE Stack.hpp)
target_include_directories(Stack INTERFACE
"${PROJECT_SOURCE_DIR}/include")

add_library(Queue INTERFACE)
target_sources(Queue INTERFACE Queue.hpp)
target_include_directories(Queue INTERFACE
"${PROJECT_SOURCE_DIR}/include")

# add_library(pamsi_list_test src/List.cpp)

# target_include_directories(pamsi_list_test PRIVATE
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#   $<INSTALL_INTERFACE:include>)

add_executable(pamsi_list src/main.cpp)

target_include_directories(pamsi_list PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)


target_link_libraries(pamsi_list INTERFACE List)
target_link_libraries(pamsi_list INTERFACE Stack)
target_link_libraries(pamsi_list INTERFACE Queue)
