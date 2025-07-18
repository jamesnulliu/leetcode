set(TARGET_NAME "main")

file(GLOB_RECURSE CXX_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${TARGET_NAME} ${CXX_SOURCES})

target_precompile_headers(
    ${TARGET_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/src/pch.hpp
)