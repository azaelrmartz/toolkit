cmake_minimum_required(VERSION 2.6)

project (common)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# The version number.
set (Common_VERSION_MAJOR 0)
set (Common_VERSION_MINOR 1)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file ("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_BINARY_DIR}/config.h")



find_package(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
if(CUnit_FOUND)
	include_directories(${CUNIT_INCLUDE_DIR})
	set(LIBS ${LIBS} ${CUNIT_LIBRARY})
endif()

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# add the executable
add_library(business-common Business.hpp Business.cpp)
