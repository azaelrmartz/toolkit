cmake_minimum_required(VERSION 3.0)

project (toolkit-common VERSION 0.2.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
 
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
add_library(toolkit-common toolkit.hpp toolkit.cpp)

include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE  
     "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${toolkit-common_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${toolkit-common_VERSION_MINOR}")
include (CPack)
