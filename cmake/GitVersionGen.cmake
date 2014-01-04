macro(GIT_VERSION_GEN _default_version)

include(FindGit)

find_program(_sort "sort")
mark_as_advanced(_sort)

find_program(_tail "tail")
mark_as_advanced(_tail)

if(GIT_FOUND AND _sort AND _tail)
  execute_process(
    COMMAND ${GIT_EXECUTABLE} tag -l -n0
    COMMAND ${_sort} -V
    COMMAND ${_tail} -n 1
    OUTPUT_VARIABLE _git_tag
    RESULT_VARIABLE _git_result
    OUTPUT_STRIP_TRAILING_WHITESPACE)
  if(NOT ${_git_result} EQUAL 0)
    message(FATAL_ERROR "Cannot fetch repository tag")
  endif()
  message(STATUS "Repository tag is: ${_git_tag}")

else(GIT_FOUND)
  set(_git_tag "${_default_version}")
endif()

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
