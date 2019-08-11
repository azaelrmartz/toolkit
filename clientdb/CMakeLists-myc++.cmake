PROJECT(octetos-toolkit-clientdb-myc++ VERSION 5.4.0.1 LANGUAGES ${LANG})

MESSAGE("El Servidor seleccionado es MySQL ...")
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)



EXECUTE_PROCESS(COMMAND date +"%Y%m%d%H%M%S" OUTPUT_VARIABLE ${PROJECT_NAME}_VERSION_BUILD)
if(NOT OTKCLMCPP_VERSION_STAGE)
        MESSAGE(FATAL_ERROR "Es necesario que indique una etapa de desasorrollo, use -DOTKC_VERSION_STAGE='etapa'.\nEn donde etapa puede ser .. snapshot,alpha,beta,rc,release.\nEn términos generales acepta cualquier miembro de la enumeración toolkit::Version::Stage para mas detalles vea la información de este paquete.")
elseif(${OTKCLMCPP_VERSION_STAGE} STREQUAL "release")
        if(NOT CMAKE_BUILD_TYPE)
                MESSAGE(FATAL_ERROR "La etapa del proyecto, es 'release', asigne tambien CMAKE_BUILD_TYPE=Release para mejor estabilidad.")
        endif()
endif()
if(NOT CMAKE_BUILD_TYPE)

elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
        if(NOT OTKCLMCPP_VERSION_STAGE)
                MESSAGE(FATAL_ERROR "Asigno CMAKE_BUILD_TYPE = Release para que los componentes de APIDB funcione correctamente es necesario que asigne OTKCLMCPP_VERSION_STAGE = release")
	elseif(NOT ${OTKCLMCPP_VERSION_STAGE} STREQUAL "release")
		MESSAGE(FATAL_ERROR "Asigno CMAKE_BUILD_TYPE = Release para que los componentes de APIDB funcione correctamente es necesario que asigne OTKCLMCPP_VERSION_STAGE = release")
        endif()
endif()

CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/versionInfo-myc++.h.in" "${PROJECT_SOURCE_DIR}/versionInfo-myc++.h")






FIND_PACKAGE(octetos-toolkit-common-c++ REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/toolkit/)
IF(OCTETOS_TOOLKIT_COMMON_CPP_FOUND)
   INCLUDE_DIRECTORIES(${OCTETOS_TOOLKIT_COMMON_CPP_INCLUDE_DIR})
ELSE()
        MESSAGE(FATAL_ERROR "No se encontro toolkit-common.")
ENDIF()
FIND_PACKAGE(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/)
IF(CUNIT_FOUND)
	INCLUDE_DIRECTORIES(${CUNIT_INCLUDE_DIR})
ENDIF()
FIND_PACKAGE(MySQL REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/)
IF(MySQL_FOUND)
	   INCLUDE_DIRECTORIES(${MYSQL_INCLUDE_DIR})
ELSE()
        MESSAGE(FATAL_ERROR "No se encontro MySQL Client.")
ENDIF()





ADD_EXECUTABLE(developing clientdb.cpp clientdb-mysql.cpp developing.cpp)
ADD_EXECUTABLE(testing-myc++-v${${PROJECT_NAME}_VERSION_MAJOR} clientdb.cpp clientdb-mysql.cpp test/myc++-v${${PROJECT_NAME}_VERSION_MAJOR}.cpp)
TARGET_LINK_LIBRARIES(testing-myc++-v${${PROJECT_NAME}_VERSION_MAJOR} ${CUNIT_LIBRARY} ${OCTETOS_TOOLKIT_COMMON_CPP_LIBRARY} ${MYSQL_LIBRARY})
TARGET_LINK_LIBRARIES(developing ${OCTETOS_TOOLKIT_COMMON_CPP_LIBRARY} ${MYSQL_LIBRARY} )


ADD_LIBRARY(${PROJECT_NAME}-obj  OBJECT clientdb.cpp clientdb-mysql.cpp)
set_target_properties(${PROJECT_NAME}-obj  PROPERTIES POSITION_INDEPENDENT_CODE 1 )
ADD_LIBRARY(${PROJECT_NAME} SHARED $<TARGET_OBJECTS:${PROJECT_NAME}-obj>)
set_target_properties(${PROJECT_NAME}  PROPERTIES POSITION_INDEPENDENT_CODE 1 )

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION /lib )
INSTALL(FILES clientdb.hpp DESTINATION /usr/include/octetos/toolkit/clientdb)
INSTALL(FILES clientdb-mysql.hpp DESTINATION /usr/include/octetos/toolkit/clientdb)

SET(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
INCLUDE (InstallRequiredSystemLibraries)
SET (CPACK_PACKAGE_VERSION_MAJOR "${${PROJECT_NAME}_VERSION_MAJOR}")
SET (CPACK_PACKAGE_VERSION_MINOR "${${PROJECT_NAME}_VERSION_MINOR}")
SET (CPACK_PACKAGE_VERSION_PATCH "${${PROJECT_NAME}_VERSION_PATCH}")
INCLUDE (CPack)
