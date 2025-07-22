cmake_minimum_required(VERSION 3.16)
project(opkm VERSION 0.1.0 LANGUAGES C)

find_package(LibGit2 CONFIG QUIET)

if(NOT TARGET LibGit2::LibGit2)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LIBGIT2 REQUIRED IMPORTED_TARGET libgit2)
    add_library(LibGit2::LibGit2 INTERFACE IMPORTED)
    target_link_libraries(LibGit2::LibGit2 INTERFACE PkgConfig::LIBGIT2)
endif()

find_package(CURL CONFIG QUIET)

if(NOT TARGET CURL::libcurl)
    pkg_check_modules(LIBCURL REQUIRED IMPORTED_TARGET libcurl)
    add_library(CURL::libcurl INTERFACE IMPORTED)
    target_link_libraries(CURL::libcurl INTERFACE PkgConfig::LIBCURL)
endif()

file(GLOB SRC CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/source/*.c")
add_executable(opkm ${SRC})
target_include_directories(opkm PRIVATE ${CMAKE_SOURCE_DIR}/headers)
target_compile_features(opkm PRIVATE c_std_99)
target_compile_options(opkm PRIVATE -Wall -Werror -Wpedantic)

target_compile_definitions(opkm PRIVATE
    OPKM_MAJOR=${PROJECT_VERSION_MAJOR}
    OPKM_MINOR=${PROJECT_VERSION_MINOR}
    OPKM_PATCH=${PROJECT_VERSION_PATCH}
    OPKM_VERSION_STR=\"${PROJECT_VERSION}\"
)

target_link_libraries(opkm PRIVATE LibGit2::LibGit2 CURL::libcurl)