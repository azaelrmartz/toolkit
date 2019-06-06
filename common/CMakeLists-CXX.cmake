
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)


CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/versionInfo.h.in" "${PROJECT_SOURCE_DIR}/versionInfo.h")
SET(libst-common-c++ common-c++)
SET(libdy-common-c++ common-c++)


FIND_PACKAGE(BISON REQUIRED)
FIND_PACKAGE(FLEX REQUIRED)
BISON_TARGET(parser version-c++.yy ${PROJECT_SOURCE_DIR}/parser.tab.cc)
FLEX_TARGET(lexer version-c++.l ${PROJECT_SOURCE_DIR}/lexer.yy.cc)
ADD_FLEX_BISON_DEPENDENCY(lexer parser)

ADD_EXECUTABLE(main main.cpp common.cpp ${FLEX_lexer_OUTPUTS} ${BISON_parser_OUTPUTS}) 
ADD_EXECUTABLE(parserVersion
    parser.cpp
    driver.cpp
    common.cpp
    ${FLEX_lexer_OUTPUTS}
    ${BISON_parser_OUTPUTS}
)

#ADD_LIBRARY(versionParser STATIC  ${FLEX_lexer_OUTPUTS} ${BISON_parser_OUTPUTS})

ADD_LIBRARY(${libst-common-c++} STATIC  common.cpp ${FLEX_lexer_OUTPUTS} ${BISON_parser_OUTPUTS})
#TARGET_LINK_LIBRARIES(${libst-common-c++} versionParser)

INSTALL(TARGETS ${libst-common-c++} DESTINATION lib/toolkit/common/)
INSTALL(FILES common.hpp DESTINATION include/toolkit/common/)
