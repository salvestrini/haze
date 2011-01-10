include_directories(${haze_SOURCE_DIR})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(core_SOURCES
  core/debug.cxx
  core/exception.cxx
  core/filesystem.cxx
  core/log.cxx
  core/pattern.cxx
  core/synchronization.cxx
  core/thread.cxx
  core/time.cxx
  )

set(gfx_SOURCES
  gfx/video.cxx
  gfx/image.cxx
  gfx/geometry.cxx
  gfx/primitive.cxx
  gfx/camera.cxx
  gfx/font.cxx
  gfx/text.cxx
  )

set(sfx_SOURCES
  sfx/audio.cxx
  sfx/mixer.cxx
  sfx/sample.cxx
  )

set(io_SOURCES
  io/keyboard.cxx
  io/mouse.cxx
  )

add_library(haze-core STATIC ${core_SOURCES})
add_library(haze-gfx  STATIC ${gfx_SOURCES})
add_library(haze-sfx  STATIC ${sfx_SOURCES})
add_library(haze-io   STATIC ${io_SOURCES})

set(all_SOURCES
  ${core_SOURCES}
  ${gfx_SOURCES}
  ${sfx_SOURCES}
  ${io_SOURCES}
  )

add_library(haze STATIC ${all_SOURCES})
