
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)


CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/versionInfo.h.in" "${PROJECT_SOURCE_DIR}/versionInfo.h")
SET(libst-common-c++ common-c++)
SET(libdy-common-c++ common-c++)

ADD_EXECUTABLE(main main.cpp common.cpp)

ADD_LIBRARY(${libst-common-c++} STATIC common.cpp)
TARGET_LINK_LIBRARIES(${libst-common-c++})

INSTALL(TARGETS ${libst-common-c++} DESTINATION lib/toolkit/common/)
INSTALL(FILES common.hpp DESTINATION include/toolkit/common/)

