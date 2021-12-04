project(supports)

cmake_minimum_required(VERSION 3.19)

set (SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/compute_supports.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Endpoint.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Raceway.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Segment.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TestData.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp
)

set (HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/compute_supports.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Endpoint.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Raceway.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Segment.h
    ${CMAKE_CURRENT_SOURCE_DIR}/TestData.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/tests.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector.h
)

add_executable (supports main.cpp ${SOURCES} ${HEADERS})

target_include_directories (supports
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
