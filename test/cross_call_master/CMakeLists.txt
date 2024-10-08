cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

if(POLICY CMP0092)
    cmake_policy(SET CMP0092 NEW) # Don't add -W3 warning level by default.
endif()


project(cross_call_master VERSION 1.0.0.0  DESCRIPTION "Cross-call Master Plugin" HOMEPAGE_URL "https://github.com/untrustedmodders" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

#
# Format
#
include(cmake/compat_format.cmake)

#
# Plugin
#
set(PLUGIN_SOURCES "plugin.cpp" "simple_tests.h" "simple_tests.cpp")

add_library(${PROJECT_NAME} SHARED ${PLUGIN_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wextra -Wshadow -Wconversion -Wpedantic -Werror)
endif()

if(LINUX)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _GLIBCXX_USE_CXX11_ABI=0)
    target_link_libraries(${PROJECT_NAME} PRIVATE -static-libstdc++ -static-libgcc)
endif()

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME} EXPORT_MACRO_NAME PLUGIN_API EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/plugin_export.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/exports)

target_compile_definitions(${PROJECT_NAME} PRIVATE 
        PLUGIFY_FORMAT_SUPPORT=$<BOOL:${COMPILER_SUPPORTS_FORMAT}>
        PLUGIFY_IS_DEBUG=$<STREQUAL:${CMAKE_BUILD_TYPE},Debug>)
if(NOT COMPILER_SUPPORTS_FORMAT)
    target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)
endif()
