macro(GIT_VERSION_GEN)

include(FindGit)
if(NOT GIT_FOUND)
  message(FATAL_ERROR "This is not a git repository")
endif()

find_program(SORT "sort")
mark_as_advanced(SORT)
if (${SORT} STREQUAL "")
  message(FATAL_ERROR "Cannot find the sort executable")
endif()

find_program(TAIL "tail")
mark_as_advanced(TAIL)
if (${TAIL} STREQUAL "")
  message(FATAL_ERROR "Cannot find the tail executable")
endif()

execute_process(
    COMMAND ${GIT_EXECUTABLE} tag -l -n0
    COMMAND ${SORT} -V
    COMMAND ${TAIL} -n 1
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE _git_tag
    RESULT_VARIABLE _git_result
    OUTPUT_STRIP_TRAILING_WHITESPACE)
if(NOT ${_git_result} EQUAL 0)
  message(FATAL_ERROR "Cannot fetch repository tag")
endif()
#message(STATUS "Repository tag is: ${_git_tag}")

string(REGEX REPLACE
  "[^0-9]*([0-9]+)\\.[0-9]+\\.[0-9]+.*" "\\1"
  _version_major "${_git_tag}")
string(REGEX REPLACE
  "[^0-9]*[0-9]+\\.([0-9]+)\\.[0-9]+.*" "\\1"
  _version_minor "${_git_tag}")
string(REGEX REPLACE
  "[^0-9]*[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1"
  _version_micro "${_git_tag}")

set(PACKAGE_VERSION_MAJOR "${_version_major}")
set(PACKAGE_VERSION_MINOR "${_version_minor}")
set(PACKAGE_VERSION_MICRO "${_version_micro}")

endmacro(GIT_VERSION_GEN)
