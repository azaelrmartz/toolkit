CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

IF(NOT LANG)
	MESSAGE(FATAL_ERROR "Use la variable LANG para indicar el lenguaje.")	
ELSEIF(${LANG} STREQUAL "CXX")
	MESSAGE("El Lenguaje seleccionado es C++ ...")
	IF(NOT SERVER)
                MESSAGE(FATAL_ERROR "Use la variable SERVER para indicar el el typo de base de datos.")
	ELSEIF(${SERVER} STREQUAL "MYSQL")
                INCLUDE(CMakeLists-myc++.cmake)
        ELSEIF(${SERVER} STREQUAL "POSTGRESQL")
                INCLUDE(CMakeLists-pqc++.cmake)
        ENDIF()
ENDIF()


