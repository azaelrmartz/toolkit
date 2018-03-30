cmake_minimum_required(VERSION 2.6)

project (Developing)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# The version number.
set (Developing_VERSION_MAJOR 0)
set (Developing_VERSION_MINOR 1)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file ("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_BINARY_DIR}/config.h")


find_package(MySQL REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
if(MySQL_FOUND)
	include_directories(${MYSQL_INCLUDE_DIR})
	set(LIBS ${LIBS} ${MYSQL_LIBRARY})
endif()

find_package(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
if(CUnit_FOUND)
	include_directories(${CUNIT_INCLUDE_DIR})
	set(LIBS ${LIBS} ${CUNIT_LIBRARY})
endif()

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# add the executable
add_executable(developing SerdataMySQL.cpp SerdataERMySQL.cpp SerdataER.hpp SerdataER.cpp Serdata.hpp Serdata.cpp Business.hpp Business.cpp developing.cpp)
target_link_libraries(developing mysqlclient)
add_library(business-client-connector SerdataMySQL.cpp Serdata.hpp Serdata.cpp Business.hpp Business.cpp)
target_link_libraries(business-client-connector mysqlclient)
