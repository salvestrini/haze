include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(core STATIC
  debug.cxx
  log.cxx
  utility.cxx
  pattern.cxx
  synchronization.cxx
  thread.cxx
  application.cxx
)
