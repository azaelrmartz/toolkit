
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)


CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_SOURCE_DIR}/config.h")
SET(targetName toolkit-common-c++)

ADD_EXECUTABLE(main main.cpp common.cpp)

ADD_LIBRARY(${targetName} STATIC common.cpp)
TARGET_LINK_LIBRARIES(${targetName}) 

INSTALL(TARGETS ${targetName} DESTINATION lib/toolkit)
INSTALL(FILES toolkit-common.hpp DESTINATION include/toolkit)

