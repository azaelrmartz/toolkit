#cmake_minimum_required (VERSION 2.6)
cmake_minimum_required(VERSION 3.5)
project (Testing)
# The version number.
set (Testing_VERSION_MAJOR 1)
set (Testing_VERSION_MINOR 0)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TestingConfig.h.in"
  "${PROJECT_BINARY_DIR}/TestingConfig.h"
)


#set(CMAKE_MODULE_PATH "/home/areyes/Sofdev/business/src/cmake/Modules/")
#list(CMAKE_MODULE_PATH APPEND FindMySQL.cmake)
find_package(MySQL REQUIRED)
if(MySQL_FOUND)
	include_directories(${MYSQL_INCLUDE_DIR})
	target_link_libraries(${MYSQL_LIB})
endif()
#execute_process(COMMAND mysql_config --cflags OUTPUT_VARIABLE MYSQL_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
#execute_process(COMMAND mysql_config --libs OUTPUT_VARIABLE MYSQL_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)
#target_compile_options(Testing PUBLIC ${MYSQL_CFLAGS})
#target_link_libraries(${MYSQL_LIBS})


# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# add the executable
add_executable(Testing conections.c DatabaseMySQL.c)
