PROJECT(octetos-toolkit-clientdb-pqc++ VERSION 3.0.0 LANGUAGES ${LANG})

FIND_PACKAGE(CUnit REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/)
IF(CUNIT_FOUND)
	INCLUDE_DIRECTORIES(${CUNIT_INCLUDE_DIR})
ENDIF()

EXECUTE_PROCESS(COMMAND date +"%Y%m%d%H%M%S" OUTPUT_VARIABLE ${PROJECT_NAME}_VERSION_BUILD)
SET(${PROJECT_NAME}_VERSION_STAGE "snapshot")

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/versionInfo-pqc++.h.in" "${PROJECT_SOURCE_DIR}/versionInfo-pqc++.h")

FIND_PACKAGE(octetos-toolkit-common-c++ REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/toolkit/)
IF(OCTETOS_TOOLKIT_COMMON_CPP_FOUND)
   INCLUDE_DIRECTORIES(${OCTETOS_TOOLKIT_COMMON_CPP_INCLUDE_DIR})
ELSE()
        MESSAGE(FATAL_ERROR "No se encontro toolkit-common.")
ENDIF()

MESSAGE("El Servidor seleccionado es PostgreSQL ...")
FIND_PACKAGE(PostgreSQL REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../cmake/Modules/)
IF(POSTGRESQL_FOUND)
	   INCLUDE_DIRECTORIES(${POSTGRESQL_INCLUDE_DIR})
ENDIF()
#ADD_EXECUTABLE(developing-pq clientdb.cpp clientdb-postgresql.cpp postgresql.cpp)
ADD_EXECUTABLE(testing-pqc++-v${${PROJECT_NAME}_VERSION_MAJOR} clientdb.cpp clientdb-postgresql.cpp test/pqc++-v${${PROJECT_NAME}_VERSION_MAJOR}.cpp)
TARGET_LINK_LIBRARIES(testing-pqc++-v${${PROJECT_NAME}_VERSION_MAJOR} ${CUNIT_LIBRARY} ${OCTETOS_TOOLKIT_COMMON_CPP_LIBRARY} ${POSTGRESQL_LIBRARY})
#TARGET_LINK_LIBRARIES(developing-pq ${OCTETOS_TOOLKIT_COMMON_CPP_LIBRARY} ${POSTGRESQL_LIBRARY} )
ADD_LIBRARY(${PROJECT_NAME} STATIC clientdb.cpp clientdb-postgresql.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OCTETOS_TOOLKIT_COMMON_CPP_LIBRARY} ${POSTGRESQL_LIBRARY})
INSTALL(TARGETS ${PROJECT_NAME} DESTINATION lib/octetos/toolkit/clientdb)
INSTALL(FILES clientdb.hpp DESTINATION include/octetos/toolkit/clientdb)
INSTALL(FILES clientdb-postgresql.cpp DESTINATION include/octetos/toolkit/clientdb)

SET(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
INCLUDE (InstallRequiredSystemLibraries)
SET (CPACK_PACKAGE_VERSION_MAJOR "${${PROJECT_NAME}_VERSION_MAJOR}")
SET (CPACK_PACKAGE_VERSION_MINOR "${${PROJECT_NAME}_VERSION_MINOR}")
SET (CPACK_PACKAGE_VERSION_PATCH "${${PROJECT_NAME}_VERSION_PATCH}")
INCLUDE (CPack)
