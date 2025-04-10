cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

if(POLICY CMP0092)
    cmake_policy(SET CMP0092 NEW) # Don't add -W3 warning level by default.
endif()


file(READ "${CMAKE_CURRENT_SOURCE_DIR}/version.txt" VERSION_FILE_CONTENTS)
string(STRIP "${VERSION_FILE_CONTENTS}" VERSION_FILE_CONTENTS)
set(CPPLM_VERSION "${VERSION_FILE_CONTENTS}" CACHE STRING "Set version name")
set(CPPLM_PACKAGE "plugify-module-cpp" CACHE STRING "Set package name")
string(REPLACE "v" "" CPPLM_VERSION "${CPPLM_VERSION}")
string(REGEX REPLACE "[.+-]" ";" CPPLM_VERSION_LIST ${CPPLM_VERSION})
list(GET CPPLM_VERSION_LIST 0 CPPLM_VERSION_MAJOR)
list(GET CPPLM_VERSION_LIST 1 CPPLM_VERSION_MINOR)
list(GET CPPLM_VERSION_LIST 2 CPPLM_VERSION_PATCH)

project(plugify-module-cpp 
        VERSION "${CPPLM_VERSION_MAJOR}.${CPPLM_VERSION_MINOR}.${CPPLM_VERSION_PATCH}"
        DESCRIPTION "C++ Language Module" 
        HOMEPAGE_URL "https://github.com/untrustedmodders/plugify-module-cpp" 
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

#
# Plugify
#
set(PLUGIFY_BUILD_SHARED_LIB ON CACHE INTERNAL "")
set(PLUGIFY_BUILD_ASSEMBLY ON CACHE INTERNAL "")
set(PLUGIFY_BUILD_TESTS OFF CACHE INTERNAL "")
set(PLUGIFY_INTERFACE ON CACHE INTERNAL "")
set(PLUGIFY_DOWNLOADER OFF CACHE INTERNAL "")
if(LINUX)
    set(PLUGIFY_USE_STATIC_STDLIB ON CACHE INTERNAL "")
endif()
add_subdirectory(external/plugify)

#
# CPP Language Module for Plugify
#
file(GLOB_RECURSE CPPLM_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${CPPLM_SOURCES})

set(CPPLM_LINK_LIBRARIES plugify::plugify plugify::plugify-assembly)

if(NOT COMPILER_SUPPORTS_FORMAT)
    set(CPPLM_LINK_LIBRARIES ${CPPLM_LINK_LIBRARIES} fmt::fmt-header-only)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE ${CPPLM_LINK_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/plugify/api)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wextra -Wshadow -Wconversion -Wpedantic -Werror)
endif()

if(APPLE)
    target_link_options(${PROJECT_NAME} PRIVATE "-Wl,-exported_symbols_list,${CMAKE_CURRENT_SOURCE_DIR}/sym/exported_symbols.lds")
elseif(UNIX)
    target_link_options(${PROJECT_NAME} PRIVATE "-Wl,--version-script,${CMAKE_CURRENT_SOURCE_DIR}/sym/version_script.lds")
endif()

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME} EXPORT_MACRO_NAME CPPLM_EXPORT EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/module_export.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/exports)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        CPPLM_PLATFORM_WINDOWS=$<BOOL:${WIN32}>
        CPPLM_PLATFORM_APPLE=$<BOOL:${APPLE}>
        CPPLM_PLATFORM_LINUX=$<BOOL:${LINUX}>
        CPPLM_IS_DEBUG=$<STREQUAL:${CMAKE_BUILD_TYPE},Debug>
        CPPLM_LIBRARY_SUFFIX="${CMAKE_SHARED_LIBRARY_SUFFIX}"
        CPPLM_LIBRARY_PREFIX="${CMAKE_SHARED_LIBRARY_PREFIX}"
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.pmodule.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pmodule
)
