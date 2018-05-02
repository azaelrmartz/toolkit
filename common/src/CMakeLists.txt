CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(toolkit-common VERSION 0.2.1.1 LANGUAGES CXX)
SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
 
# configure a header file to pass some of the CMake settings
# to the source code
SET(toolkit-common_VERSION_STAGE "alpha")
configure_file ("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_BINARY_DIR}/config.h")

FIND_PACKAGE(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
if(CUnit_FOUND)
	include_directories(${CUNIT_INCLUDE_DIR})
	set(LIBS ${LIBS} ${CUNIT_LIBRARY})
endif()

# add static library
ADD_LIBRARY(toolkit-common STATIC toolkit.hpp toolkit.cpp)
#ADD_LIBRARY(toolkit-common SHARED toolkit.hpp toolkit.cpp)
#ADD_LIBRARY(toolkit-common.${toolkit-common_VERSION_MAJOR} SHARED toolkit.hpp toolkit.cpp)
#ADD_LIBRARY(toolkit-common.${toolkit-common_VERSION_MAJOR}.${toolkit-common_VERSION_MINOR} SHARED toolkit.hpp toolkit.cpp)
ADD_LIBRARY(toolkit-common.${toolkit-common_VERSION_MAJOR}.${toolkit-common_VERSION_MINOR}.${toolkit-common_VERSION_PATCH}  SHARED toolkit.hpp toolkit.cpp)


include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${toolkit-common_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${toolkit-common_VERSION_MINOR}")
include (CPack)
