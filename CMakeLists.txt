CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

if(${SELCTPK} STREQUAL "COMMON")
    add_subdirectory(common) 
elseif(${SELCTPK} STREQUAL "CLIENTDB")
    add_subdirectory(clientdb) 
endif()


