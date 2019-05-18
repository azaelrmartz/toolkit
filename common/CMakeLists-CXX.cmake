
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)


CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_SOURCE_DIR}/config.h")
SET(target-common-c++ common-c++)

ADD_EXECUTABLE(main main.cpp common.cpp)

ADD_LIBRARY(${target-common-c++} STATIC common.cpp)
TARGET_LINK_LIBRARIES(${target-common-c++}) 

INSTALL(TARGETS ${target-common-c++} DESTINATION lib/toolkit/common/)
INSTALL(FILES common.hpp DESTINATION include/toolkit/common/)

