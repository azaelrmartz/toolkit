CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(toolkit-common VERSION 1.0.0)


execute_process(COMMAND date +"%Y%m%d%H%I" OUTPUT_VARIABLE toolkit-common_VERSION_BUILD)

if(${LANG} STREQUAL "CXX")
	MESSAGE("Generando componete en C++ ...")	
	INCLUDE(CMakeLists-CXX)
elseif(${LANG} STREQUAL "C")
	MESSAGE("Generando componete en C ...")	
	INCLUDE(CMakeLists-C)
else()
	MESSAGE(FATAL_ERROR "Indique el lenguaje, por ejemlo LANG=CXX")
endif()
