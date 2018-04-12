CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(toolkit-clientdb VERSION 0.2.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


FIND_PACKAGE(MySQL REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
IF(MySQL_FOUND)
	INCLUDE_DIRECTORIES(${MYSQL_INCLUDE_DIR})
ENDIF()

FIND_PACKAGE(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
IF(CUnit_FOUND)
	INCLUDE_DIRECTORIES(${CUNIT_INCLUDE_DIR})
ENDIF()

FIND_PACKAGE(toolkit-common REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../../cmake/Modules/)
IF(TOOLKIT_COMMON_FOUND)
	INCLUDE_DIRECTORIES(${TOOLKIT_COMMON_INCLUDE_DIR})
ENDIF()


# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# add the executable
ADD_EXECUTABLE(developing SerdataMySQL.cpp SerdataERMySQL.cpp SerdataER.cpp Serdata.cpp developing.cpp)
TARGET_LINK_LIBRARIES(developing ${TOOLKIT_COMMON_LIBRARY} ${MYSQL_LIBRARY})

ADD_LIBRARY(toolkit-clientdb STATIC SerdataMySQL.cpp SerdataERMySQL.cpp SerdataER.cpp Serdata.cpp)
TARGET_LINK_LIBRARIES(toolkit-clientdb ${TOOLKIT_COMMON_LIBRARY} ${MYSQL_LIBRARY})

#ADD_LIBRARY(toolkit-clientdb.so SHARED SerdataMySQL.cpp SerdataERMySQL.cpp SerdataER.cpp Serdata.cpp)
#TARGET_LINK_LIBRARIES(toolkit-clientdb.so ${TOOLKIT_COMMON_LIBRARY} ${MYSQL_LIBRARY})

include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE  
     "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${toolkit-clientdb_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${toolkit-clientdb_VERSION_MINOR}")
include (CPack)