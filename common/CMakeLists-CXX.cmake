PROJECT(octetos-toolkit-common-c++ VERSION 4.2.0 LANGUAGES ${LANG})

EXECUTE_PROCESS(COMMAND date +"%Y%m%d%H%M%S" OUTPUT_VARIABLE ${PROJECT_NAME}_VERSION_BUILD)
SET(${PROJECT_NAME}_VERSION_STAGE "snapshot")
SET(${PROJECT_NAME}_VERSION_NAME "reader")

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/versionInfo-c++.h.in" "${PROJECT_SOURCE_DIR}/versionInfo-c++.h")


FIND_PACKAGE(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/)
IF(CUNIT_FOUND)
	INCLUDE_DIRECTORIES(${CUNIT_INCLUDE_DIR})
ENDIF()

FIND_PACKAGE(BISON REQUIRED)
FIND_PACKAGE(FLEX REQUIRED)
BISON_TARGET(parser parserVersion-C++/parser.yy  ${PROJECT_SOURCE_DIR}/parserVersion-C++/parser.cc)
FLEX_TARGET(lexer parserVersion-C++/scanner.ll  ${PROJECT_SOURCE_DIR}/parserVersion-C++/scanner.cc)
ADD_FLEX_BISON_DEPENDENCY(lexer parser)

#ADD_EXECUTABLE(main main.cpp common.cpp) 
#ADD_EXECUTABLE(parserVersionTest common.cpp parserVersion-C++/version-c++.cc parserVersion-C++/driver.cc ${FLEX_lexer_OUTPUTS} ${BISON_parser_OUTPUTS})
ADD_EXECUTABLE(testing-v${${PROJECT_NAME}_VERSION_MAJOR} tests/v${${PROJECT_NAME}_VERSION_MAJOR}.cc common.cpp parserVersion-C++/driver.cc ${FLEX_lexer_OUTPUTS} ${BISON_parser_OUTPUTS})
TARGET_LINK_LIBRARIES(testing-v${${PROJECT_NAME}_VERSION_MAJOR} ${CUNIT_LIBRARY})

ADD_LIBRARY(${PROJECT_NAME}  STATIC common-parser.cpp common.cpp parserVersion-C++/driver.cc ${FLEX_lexer_OUTPUTS} ${BISON_parser_OUTPUTS})

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION lib/octetos/toolkit/common/)
INSTALL(FILES common.hpp DESTINATION include/octetos/toolkit/common/)


SET(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
INCLUDE (InstallRequiredSystemLibraries)
SET (CPACK_PACKAGE_VERSION_MAJOR "${${PROJECT_NAME}_VERSION_MAJOR}")
SET (CPACK_PACKAGE_VERSION_MINOR "${${PROJECT_NAME}_VERSION_MINOR}")
SET (CPACK_PACKAGE_VERSION_PATCH "${${PROJECT_NAME}_VERSION_PATCH}")
INCLUDE (CPack)
