
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
ADD_DEFINITIONS(-DFIELDS_NUMBER=3 -DFIELD_STAGE=true) 

#SET(toolkit-common_VERSION_STAGE "beta")
CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_SOURCE_DIR}/config.h")
SET(targetName toolkit-common-c++)

#FIND_PACKAGE(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/)
#IF(CUnit_FOUND)
#	INCLUDE_DIRECTORIES(${CUNIT_INCLUDE_DIR})
#ENDIF()

ADD_EXECUTABLE(main main.cpp common.cpp)

#ADD_EXECUTABLE(testing testing.cpp common.cpp)
#TARGET_LINK_LIBRARIES(testing ${CUNIT_LIBRARY})

ADD_LIBRARY(${targetName} STATIC common.cpp)
TARGET_LINK_LIBRARIES(${targetName}) 

INSTALL(TARGETS ${targetName} DESTINATION lib/toolkit)
INSTALL(FILES common.hpp DESTINATION include/toolkit)
