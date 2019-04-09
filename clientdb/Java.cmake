
ENABLE_LANGUAGE(Java)
#CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/Version.java.in" "${PROJECT_SOURCE_DIR}/Version.java")
find_package(Java 1.8 REQUIRED)
if(JAVA_FOUND)
    include(UseJava)
else()
    message(FATAL_ERROR "Couldn't find Java")
endif()


FIND_JAR(TOOLKIT_COMMON_JAR "toolkit-common" PATHS "/usr/lib/toolkit")
message("-- Found jar at ${TOOLKIT_COMMON_JAR}")


set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.8" "-target" "1.8")

ADD_JAR(Main SOURCES Main.java Datasource.java INCLUDE_JARS ${TOOLKIT_COMMON_JAR} ENTRY_POINT Main)
ADD_JAR(toolkit-clientdb SOURCES Datasource.java INCLUDE_JARS ${TOOLKIT_COMMON_JAR})

INSTALL_JAR(toolkit-clientdb DESTINATION lib/toolkit)

