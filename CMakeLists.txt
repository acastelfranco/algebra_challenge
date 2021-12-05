cmake_minimum_required (VERSION 3.19)

project (supports)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compute_supports.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Endpoint.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Raceway.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Segment.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Vector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Utils.cpp
)

set (HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/compute_supports.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Endpoint.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Raceway.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Segment.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Vector.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Utils.h
)

set (TESTS
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/catch.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/test0001.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/test0002.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/test0003.cpp
)

add_library (raceway ${SOURCES} ${HEADERS})

add_executable (tests ${TESTS} ${HEADERS})
add_executable (supports main.cpp ${HEADERS})

target_link_libraries (tests PRIVATE raceway)
target_link_libraries (supports PRIVATE raceway)

target_include_directories (raceway
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories (tests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/tests
)

target_include_directories (supports
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

option (BUILD_DOC "Build documentation" ON)

find_package (Doxygen)
if (DOXYGEN_FOUND)
    set (DOXYGEN_IN  ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set (DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)

    configure_file (${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message ("Doxygen build started")

    add_custom_target ( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
	    WORKING_DIRECTORY ${CMAKE_CURRENT_SRC_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
    message ("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
