CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

if(NOT LANG)
	MESSAGE(FATAL_ERROR "Use la variable LANG para indicar el lenguaje.")	
elseif(${LANG} STREQUAL "CXX")
	MESSAGE("Generando Parser en C++ ...")	
	INCLUDE(CMakeLists-CXX.cmake)
elseif(${LANG} STREQUAL "C")
	MESSAGE("Generando Parser en C ...")	
	INCLUDE(CMakeLists-C.cmake)
elseif()
	MESSAGE(FATAL_ERROR "El valor de LANG es desconocido.")
endif()

