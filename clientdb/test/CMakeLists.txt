CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(toolkit-clientdb-test)
SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

FIND_PACKAGE(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
IF(CUnit_FOUND)
	INCLUDE_DIRECTORIES(${CUNIT_INCLUDE_DIR})
ENDIF()
FIND_PACKAGE(MySQL REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
IF(MySQL_FOUND)
	INCLUDE_DIRECTORIES(${MYSQL_INCLUDE_DIR})
ENDIF()
FIND_PACKAGE(toolkit-common REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
IF(TOOLKIT_COMMON_FOUND)
	INCLUDE_DIRECTORIES(${TOOLKIT_COMMON_INCLUDE_DIR})
ENDIF()
FIND_PACKAGE(toolkit-clientdb REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
IF(TOOLKIT_CLIENTDB_FOUND)
	INCLUDE_DIRECTORIES(${TOOLKIT_CLIENTDB_INCLUDE_DIR})
ENDIF()


ADD_EXECUTABLE(testing testing.cpp)
TARGET_LINK_LIBRARIES(testing ${TOOLKIT_COMMON_LIBRARY} ${TOOLKIT_CLIENTDB_LIBRARY} ${CUNIT_LIBRARY} ${MYSQL_LIBRARY})
