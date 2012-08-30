macro(GIT_VERSION_GEN)

include(FindGit)

find_program(SORT "sort")
find_program(TAIL "tail")

if(GIT_FOUND AND SORT AND TAIL)
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

endmacro(GIT_VERSION_GEN)
