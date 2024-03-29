cmake_minimum_required(VERSION 2.6.4 FATAL_ERROR)
project(dutils)
enable_testing()
add_custom_target(check COMMAND ctest) # Define "make check" as an alias for "make test."
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "cmccabe daemon-utils")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "0")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_CONTACT "cmccabe@alumni.cmu.edu")
SET(CPACK_GENERATOR "TGZ")
INCLUDE(CPack)

set(CMAKE_BUILD_TYPE, Release) # can also be Debug
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -fno-strict-aliasing")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_REENTRANT -D_FILE_OFFSET_BITS=64")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
# Enable -rdynamic to get readable backtraces in the signal handlers.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -rdynamic")

set(CMAKE_C_FLAGS_RELEASE "-O3 -Wuninitialized")
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -fstack-protector -Werror")
set(CMAKE_CURRENT_BINARY_DIR, builds)
SET(CMAKE_INSTALL_PREFIX /usr)

# Find libjson-c
find_path(JSON_C_INCLUDE_DIR "json/json.h")
find_library(JSON_C_LIBRARY json)
IF(JSON_C_INCLUDE_DIR AND JSON_C_LIBRARY)
ELSE(JSON_C_INCLUDE_DIR AND JSON_C_LIBRARY)
    MESSAGE(FATAL_ERROR "Failed to find libjson-c. Try installing libjson-c with apt-get or yum, or install it manually from http://oss.metaparadigm.com/json-c/")
ENDIF(JSON_C_INCLUDE_DIR AND JSON_C_LIBRARY)

# Set up include paths
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${JSON_C_INCLUDE_DIR}
)

add_subdirectory(core)
add_subdirectory(jorm)
add_subdirectory(util)
