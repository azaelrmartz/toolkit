CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(${octetos-toolkit}-common LANGUAGES ${LANG})
set(${octetos-toolkit}-common_VERSION_MAJOR ${octetos-toolkit}_VERSION_MAJOR)


if(NOT LANG)
	MESSAGE(FATAL_ERROR "Use la variable LANG para indicar el lenguaje.")	
elseif(${LANG} STREQUAL "CXX")
	MESSAGE("Generando componetes en C++ ...")	
	INCLUDE(CMakeLists-CXX.cmake)
elseif(${LANG} STREQUAL "C")
	MESSAGE("Generando componetes en C ...")	
	set(OCTKCMC_VERSION_STAGE ${OCTKC_VERSION_STAGE})
	INCLUDE(CMakeLists-C.cmake)
elseif()
	MESSAGE(FATAL_ERROR "El valor de LANG es desconocido.")
endif()

