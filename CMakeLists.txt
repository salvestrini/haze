cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

project(Haze)

add_subdirectory(haze)
add_subdirectory(tests)

include(FindGit)
if(GIT_FOUND)
  find_program(SORT "sort")
  if(NOT SORT)
    message(FATAL_ERROR "Program `sort' not found")
  endif()

  find_program(TAIL "tail")
  if(NOT TAIL)
    message(FATAL_ERROR "Program `tail' not found")
  endif()

  execute_process(
    COMMAND ${GIT_EXECUTABLE} tag -l -n0
    COMMAND ${SORT} -V
    COMMAND ${TAIL} -n 1
    OUTPUT_VARIABLE _command_output
    RESULT_VARIABLE _command_result
    OUTPUT_STRIP_TRAILING_WHITESPACE)
  if(NOT ${_command_result} EQUAL 0)
    message(FATAL_ERROR "Cannot fetch repository tag")
  endif()
  message(STATUS "Repository tag is: ${_command_output}")

  string(REGEX REPLACE
    "[^0-9]*([0-9]+)\\.[0-9]+\\.[0-9]+.*" "\\1"
    _major "${_command_output}")
  string(REGEX REPLACE
    "[^0-9]*[0-9]+\\.([0-9]+)\\.[0-9]+.*" "\\1"
    _minor "${_command_output}")
  string(REGEX REPLACE
    "[^0-9]*[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1"
    _micro "${_command_output}")

  set(PACKAGE_VERSION_MAJOR "${_major}")
  set(PACKAGE_VERSION_MINOR "${_minor}")
  set(PACKAGE_VERSION_MICRO "${_micro}")
else(GIT_FOUND)
  set(PACKAGE_VERSION_MAJOR -1)
  set(PACKAGE_VERSION_MINOR -1)
  set(PACKAGE_VERSION_MICRO -1)
endif()
message(STATUS "Package version is: ${PACKAGE_VERSION_MAJOR}.${PACKAGE_VERSION_MINOR}.${PACKAGE_VERSION_MICRO}")

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/haze/version.hh.in" "${CMAKE_CURRENT_BINARY_DIR}/haze/version.hh")

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
