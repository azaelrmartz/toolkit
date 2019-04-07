
ENABLE_LANGUAGE(Java)

find_package(Java 1.8 REQUIRED)
#find_package(SWIG REQUIRED)
include(UseJava)

enable_testing()

set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.8" "-target" "1.8")

add_jar(Main SOURCES Main.java ENTRY_POINT Main)

get_target_property(_jarFile Main JAR_FILE)
get_target_property(_classDir Main CLASSDIR)

message(STATUS "Jar file ${_jarFile}")
message(STATUS "Class compiled to ${_classDir}")

add_test(NAME TestHelloWorld COMMAND ${Java_JAVA_EXECUTABLE} -cp ${_jarFile} Main)
