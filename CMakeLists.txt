project(supports)

cmake_minimum_required(VERSION 3.19)

set (SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compute_supports.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Endpoint.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Raceway.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Segment.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Vector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/TestData.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp
)

set (HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/compute_supports.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Endpoint.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Raceway.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Segment.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Vector.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/TestData.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/catch.hpp
)

add_executable (supports main.cpp ${SOURCES} ${HEADERS})

target_include_directories (supports
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/tests
)

target_compile_features( supports
    PRIVATE
    cxx_std_14
)
