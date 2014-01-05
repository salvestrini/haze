cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH      "${CMAKE_SOURCE_DIR}/cmake")
#set(CMAKE_VERBOSE_MAKEFILE ON)

project(Haze)

include(GitVersionGen)
GIT_VERSION_GEN("0.0.0")
set(PACKAGE_URL       "http://an-url-here.org" CACHE STRING "Package URL")              
set(PACKAGE_BUGREPORT "an-email-address-here"  CACHE STRING "Packaged bug-report email")

message(STATUS "Package version is:         ${PACKAGE_VERSION_MAJOR}.${PACKAGE_VERSION_MINOR}.${PACKAGE_VERSION_MICRO}")
message(STATUS "Package URL is:             ${PACKAGE_URL}")
message(STATUS "Package bug-report address: ${PACKAGE_BUGREPORT}")

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/haze/version.hh.in"
  "${CMAKE_CURRENT_BINARY_DIR}/haze/version.hh")

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The HAZE library")
set(CPACK_PACKAGE_VENDOR              "Francesco Salvestrini")
set(CPACK_PACKAGE_DESCRIPTION_FILE    "${CMAKE_CURRENT_SOURCE_DIR}/README")
set(CPACK_RESOURCE_FILE_LICENSE       "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR       ${PACKAGE_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR       ${PACKAGE_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH       ${PACKAGE_VERSION_MICRO})
set(CPACK_PACKAGE_INSTALL_DIRECTORY   "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
include(CPack)

#include(CMakePrintSystemInformation)

include(FeatureSummary)
print_enabled_features()

add_subdirectory(haze)
add_subdirectory(pkg-config)
add_subdirectory(tests)
