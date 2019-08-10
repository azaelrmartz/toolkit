PROJECT(octetos-toolkit-common-c++ VERSION 5.0.0.0 LANGUAGES ${LANG})
SET(${PROJECT_NAME}_DOCUMENTING TRUE)

EXECUTE_PROCESS(COMMAND date +"%Y%m%d%H%M%S" OUTPUT_VARIABLE ${PROJECT_NAME}_VERSION_BUILD)
if(NOT OTKCM_VERSION_STAGE)
        MESSAGE(FATAL_ERROR "Es necesario que indique una etapa de desasorrollo, use -DOTKC_VERSION_STAGE='etapa'.\nEn donde etapa puede ser .. snapshot,alpha,beta,rc,release.\nEn términos generales acepta cualquier miembro de la enumeración toolkit::Version::Stage para mas detalles vea la información de este paquete.")
elseif(${OTKCM_VERSION_STAGE} STREQUAL "release")
        if(NOT CMAKE_BUILD_TYPE)
                MESSAGE(FATAL_ERROR "La etapa del proyecto, es 'release', asigne tambien CMAKE_BUILD_TYPE=Release para mejor estabilidad.")
        endif()
endif()
if(NOT CMAKE_BUILD_TYPE)

elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
        if(NOT OTKCM_VERSION_STAGE)
                MESSAGE(FATAL_ERROR "Asigno CMAKE_BUILD_TYPE = Release para que los componentes de APIDB funcione correctamente es necesario que asigne OTKCM_VERSION_STAGE = release")
	elseif(NOT ${OTKCM_VERSION_STAGE} STREQUAL "release")
		MESSAGE(FATAL_ERROR "Asigno CMAKE_BUILD_TYPE = Release para que los componentes de APIDB funcione correctamente es necesario que asigne OTKCM_VERSION_STAGE = release")
        endif()
endif()

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/versionInfo-c++.h.in" "${PROJECT_SOURCE_DIR}/versionInfo-c++.h")


###############################################################################################
FIND_PACKAGE(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/)
IF(CUNIT_FOUND)
	INCLUDE_DIRECTORIES(${CUNIT_INCLUDE_DIR})
ENDIF()
FIND_PACKAGE(Doxygen)
IF(Doxygen_FOUND)
        SET(doxyfile_in "doxygen-public-c++")
ELSE()
        MESSAGE(FATAL_ERROR "No se encontro Doxygen.")
ENDIF()




#################################################################################################

INCLUDE_DIRECTORIES(version-reader-c++ ${CMAKE_CURRENT_BINARY_DIR}/version-reader-c++)
SET(LIBREADER "NULL")
ADD_SUBDIRECTORY(version-reader-c++)
ADD_LIBRARY(${PROJECT_NAME}-obj  OBJECT common.cpp Error.cpp Object.cpp Version.cpp Version-parser.cpp Message.cpp Object.cpp)
#target_include_directories(${PROJECT_NAME}-obj PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>  $<INSTALL_INTERFACE:.> )
set_target_properties(${PROJECT_NAME}-obj  PROPERTIES POSITION_INDEPENDENT_CODE 1 )


ADD_LIBRARY(${PROJECT_NAME} SHARED $<TARGET_OBJECTS:${PROJECT_NAME}-obj> $<TARGET_OBJECTS:${LIBREADER}-obj>)
set_target_properties(${PROJECT_NAME}  PROPERTIES POSITION_INDEPENDENT_CODE 1 )
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINK_FLAGS -Wl,-Bsymbolic)
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${LIBREADER})

ADD_EXECUTABLE(testing-v${${PROJECT_NAME}_VERSION_MAJOR} tests/v${${PROJECT_NAME}_VERSION_MAJOR}.cc)
ADD_DEPENDENCIES(testing-v${${PROJECT_NAME}_VERSION_MAJOR} ${PROJECT_NAME})
#MESSAGE(STATUS "In common PROJECT_NAME : " ${PROJECT_NAME})
TARGET_LINK_LIBRARIES(testing-v${${PROJECT_NAME}_VERSION_MAJOR} ${CUNIT_LIBRARIES} ${PROJECT_NAME})

IF(Doxygen_FOUND)
add_custom_target(
  doc ALL
  COMMAND ${DOXYGEN_EXECUTABLE} "${PROJECT_SOURCE_DIR}/${doxyfile_in}"
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  COMMENT "Generating API documentation with Doxygen"
  VERBATIM
)
ENDIF()

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION /lib)
INSTALL(FILES common.hpp DESTINATION include/octetos/toolkit/common/)
INSTALL(FILES Version.hpp DESTINATION include/octetos/toolkit/common/)
INSTALL(FILES Message.hpp DESTINATION include/octetos/toolkit/common/)
INSTALL(FILES Error.hpp DESTINATION include/octetos/toolkit/common/)
INSTALL(FILES Object.hpp DESTINATION include/octetos/toolkit/common/)


SET(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
INCLUDE (InstallRequiredSystemLibraries)
SET (CPACK_PACKAGE_VERSION_MAJOR "${${PROJECT_NAME}_VERSION_MAJOR}")
SET (CPACK_PACKAGE_VERSION_MINOR "${${PROJECT_NAME}_VERSION_MINOR}")
SET (CPACK_PACKAGE_VERSION_PATCH "${${PROJECT_NAME}_VERSION_PATCH}")
INCLUDE (CPack)
