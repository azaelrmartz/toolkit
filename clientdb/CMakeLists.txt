CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(toolkit-clientdb VERSION 2.0.0 LANGUAGES ${LANG})

IF(NOT LANG)
	MESSAGE("Use la variable LANG para indicar el lenguaje.")	
ELSEIF(${LANG} STREQUAL "CXX")
	MESSAGE("Generando componetes en C++ ...")
	INCLUDE(CMakeLists-CXX)
ENDIF()

INSTALL(TARGETS ${targetName} DESTINATION lib/toolkit)
INSTALL(FILES clientdb.hpp DESTINATION include/toolkit)

include (InstallRequiredSystemLibraries)
SET(CPACK_PACKAGE_VERSION_MAJOR "${toolkit-clientdb_VERSION_MAJOR}")
SET(CPACK_PACKAGE_VERSION_MINOR "${toolkit-clientdb_VERSION_MINOR}")
SET(CPACK_PACKAGE_VERSION_PATCH "${toolkit-clientdb_VERSION_PATCH}")
include (CPack)
