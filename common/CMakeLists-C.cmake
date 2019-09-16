PROJECT(octetos-toolkit-common-c VERSION 0.1.0.1 LANGUAGES ${LANG})

EXECUTE_PROCESS(COMMAND date +"%Y%m%d%H%M%S" OUTPUT_VARIABLE ${PROJECT_NAME}_VERSION_BUILD)
if(NOT OCTKCMC_VERSION_STAGE)
        MESSAGE(FATAL_ERROR "Es necesario que indique una etapa de desasorrollo, use -DOCTKCMC_VERSION_STAGE='etapa'.\nEn donde etapa puede ser .. snapshot,alpha,beta,rc,release.\nEn términos generales acepta cualquier miembro de la enumeración toolkit::Version::Stage para mas detalles vea la información de este paquete.")
elseif(${OCTKCMC_VERSION_STAGE} STREQUAL "release")
        if(NOT CMAKE_BUILD_TYPE)
                MESSAGE(FATAL_ERROR "La etapa del proyecto, es 'release', asigne tambien CMAKE_BUILD_TYPE=Release para mejor estabilidad.")
        endif()
endif()
if(NOT CMAKE_BUILD_TYPE)

elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
	if(NOT OCTKCMC_VERSION_STAGE)
		MESSAGE(FATAL_ERROR "Asigno CMAKE_BUILD_TYPE = Release para que los componentes de toolkit-common-c funcione correctamente es necesario que asigne OCTKCMC_VERSION_STAGE = release")
	elseif(NOT ${OCTKCMC_VERSION_STAGE} STREQUAL "release")
		MESSAGE(FATAL_ERROR "Asigno CMAKE_BUILD_TYPE = Release para que los componentes de toolkit-common-c funcione correctamente es necesario que asigne OCTKCMC_VERSION_STAGE = release")
	endif()
endif()

CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/packInfo.h.in" "${PROJECT_BINARY_DIR}/packInfo.h")


###############################################################################################


FIND_PACKAGE(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/)
IF(CUNIT_FOUND)
	INCLUDE_DIRECTORIES(${CUNIT_INCLUDE_DIR})
ENDIF()

INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR})
INCLUDE_DIRECTORIES(version-reader ${CMAKE_CURRENT_BINARY_DIR}/version-reader)

<<<<<<< HEAD
<<<<<<< HEAD

set(OCTKCO_SRC_DIR ${PROJECT_SOURCE_DIR})
=======
INCLUDE_DIRECTORIES(version-reader ${CMAKE_CURRENT_BINARY_DIR}/version-reader)
set(OCTKCM_DIR_SRC ${CMAKE_CURRENT_SRC_DIR})
>>>>>>> [inclompleto] simplemete para guardar los cambion locales
=======
INCLUDE_DIRECTORIES(version-reader ${CMAKE_CURRENT_BINARY_DIR}/version-reader)
set(OCTKCM_DIR_SRC ${CMAKE_CURRENT_SRC_DIR})
>>>>>>> a5aace4aae9d343e9cba4cc0cf504678318bd629
#################################################################################################

SET(LIBREADER "NULL")
ADD_SUBDIRECTORY(version-reader)

ADD_LIBRARY(${PROJECT_NAME}-obj  OBJECT common.c)
set_target_properties(${PROJECT_NAME}-obj  PROPERTIES POSITION_INDEPENDENT_CODE 1 )
ADD_DEPENDENCIES(${PROJECT_NAME}-obj ${LIBREADER})

ADD_LIBRARY(${PROJECT_NAME} SHARED $<TARGET_OBJECTS:${PROJECT_NAME}-obj> $<TARGET_OBJECTS:${LIBREADER}-obj>)
set_target_properties(${PROJECT_NAME}  PROPERTIES POSITION_INDEPENDENT_CODE 1 )
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINK_FLAGS -Wl,-Bsymbolic)

ADD_EXECUTABLE(testing-v${${PROJECT_NAME}_VERSION_MAJOR} tests/v${${PROJECT_NAME}_VERSION_MAJOR}.c)
ADD_DEPENDENCIES(testing-v${${PROJECT_NAME}_VERSION_MAJOR} ${PROJECT_NAME}-obj)
TARGET_LINK_LIBRARIES(testing-v${${PROJECT_NAME}_VERSION_MAJOR} ${CUNIT_LIBRARIES} ${PROJECT_NAME})
ADD_DEPENDENCIES(testing-v${${PROJECT_NAME}_VERSION_MAJOR} ${LIBREADER})

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION lib)
INSTALL(FILES common.h DESTINATION include/octetos/toolkit/common/)


SET(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
INCLUDE (InstallRequiredSystemLibraries)
SET (CPACK_PACKAGE_VERSION_MAJOR "${${PROJECT_NAME}_VERSION_MAJOR}")
SET (CPACK_PACKAGE_VERSION_MINOR "${${PROJECT_NAME}_VERSION_MINOR}")
SET (CPACK_PACKAGE_VERSION_PATCH "${${PROJECT_NAME}_VERSION_PATCH}")
INCLUDE (CPack)
