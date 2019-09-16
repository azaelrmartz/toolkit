CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(octetos-version-reader-c C)

#set (CMAKE_C_FLAGS "-std=gnu99 ${CMAKE_C_FLAGS}")

FIND_PACKAGE(BISON REQUIRED)
FIND_PACKAGE(FLEX REQUIRED)
BISON_TARGET(parserVersion parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.c)
if(BISON_parserVersion_DEFINED)
	#MESSAGE(STATUS "Target de Bions 'parserVersion' creado.")
else()
	MESSAGE(FATAL_ERROR "Fallo al constuir el componente de Bions 'parserVersion'")
endif()
FLEX_TARGET(lexerVersion lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.yy.c)
IF(FLEX_lexerVersion_DEFINED)
	#MESSAGE(STATUS "Target de Flexer 'lexerVersion' creado.")
ELSE()
	MESSAGE(FATAL_ERROR "Fallo al constuir el componente de Flexer 'lexerVersion'")
ENDIF()
ADD_FLEX_BISON_DEPENDENCY(lexerVersion parserVersion)
include_directories(${octetos-toolkit-common-c_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR})

SET(LIBREADER ${PROJECT_NAME} PARENT_SCOPE)
ADD_LIBRARY(${PROJECT_NAME}-obj  OBJECT ${FLEX_lexerVersion_OUTPUTS} ${BISON_parserVersion_OUTPUTS})
set_target_properties(${PROJECT_NAME}-obj  PROPERTIES POSITION_INDEPENDENT_CODE 1 )

ADD_LIBRARY(${PROJECT_NAME} SHARED $<TARGET_OBJECTS:${PROJECT_NAME}-obj>)
set_target_properties(${PROJECT_NAME}  PROPERTIES POSITION_INDEPENDENT_CODE 1 )

add_executable(develop develop.c ${FLEX_lexerVersion_OUTPUTS} ${BISON_parserVersion_OUTPUTS})
