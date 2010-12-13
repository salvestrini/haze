Find_Package(SDL REQUIRED)
#Find_Package(SDL_image REQUIRED)

if (NOT SDL_FOUND)
  message (FATAL_ERROR "SDL not found!")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(core STATIC
  core/core.cxx
  core/debug.cxx
  core/log.cxx
  core/pattern.cxx
  core/synchronization.cxx
  core/thread.cxx
  core/application.cxx

  core/application.cxx
  core/exception.cxx
  core/factory.cxx
  #log.c++                   log.cxx
  core/pattern.cxx
  core/singleton.cxx
  core/synchronization.cxx
  core/thread.cxx
  )

add_library(gfx STATIC
  gfx/gfx.cxx
)

add_library(sfx STATIC
  sfx/sfx.cxx
)

add_library(io STATIC
  io/io.cxx
)

link_libraries (
  ${SDL_LIBRARY}
)
