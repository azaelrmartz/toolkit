CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(toolkit-common VERSION 1.1.0)


execute_process(COMMAND date +"%Y%m%d%H%I" OUTPUT_VARIABLE toolkit-common_VERSION_BUILD)

if(${LANG} STREQUAL "CXX")
	MESSAGE("Generando componetes en C++ ...")	
	INCLUDE(CMakeLists-CXX)
elseif(${LANG} STREQUAL "C")
	MESSAGE("Generando componetes en C ...")	
	INCLUDE(CMakeLists-C)
elseif(${LANG} STREQUAL "F")
	MESSAGE("Generando componetes en Fortran ...")	
	INCLUDE(CMakeLists-F)
else()
	MESSAGE(FATAL_ERROR "Indique el lenguaje, por ejemlo LANG=CXX")
endif()
