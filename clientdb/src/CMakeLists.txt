cmake_minimum_required(VERSION 3.0)

project (toolkit-clientdb VERSION 0.2.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


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

find_package(toolkit-common REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
if(TOOLKIT_COMMON_FOUND)
	include_directories(${TOOLKIT_COMMON_INCLUDE_DIR})
	set(LIBS ${LIBS} ${TOOLKIT_COMMON_LIBRARY})
endif()


# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# add the executable
add_executable(developing SerdataMySQL.cpp SerdataERMySQL.cpp SerdataER.hpp SerdataER.cpp Serdata.hpp Serdata.cpp developing.cpp)
target_link_libraries(developing ${TOOLKIT_COMMON_LIBRARY} ${MYSQL_LIBRARY} )
#add_library(business-client-connector SerdataMySQL.cpp Serdata.hpp Serdata.cpp Business.hpp Business.cpp)
#target_link_libraries(business-client-connector mysqlclient)
