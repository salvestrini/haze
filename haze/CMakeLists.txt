include_directories(${haze_SOURCE_DIR})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(core_SRCS
  core/debug.cxx
  core/exception.cxx
  core/filesystem.cxx
  core/log.cxx
  core/pattern.cxx
  core/synchronization.cxx
  core/thread.cxx
  core/time.cxx
  core/event.cxx
  )
set(core_HDRS
  core/debug.hxx
  core/exception.hxx
  core/filesystem.hxx
  core/log.hxx
  core/pattern.hxx
  core/synchronization.hxx
  core/thread.hxx
  core/time.hxx
  core/event.hxx
  )

set(gfx_SRCS
  gfx/video.cxx
  gfx/fps.cxx
  gfx/image.cxx
  gfx/geometry.cxx
  gfx/primitive.cxx
  gfx/camera.cxx
  gfx/font.cxx
  gfx/text.cxx
  )
set(gfx_HDRS
  gfx/video.hxx
  gfx/fps.hxx
  gfx/image.hxx
  gfx/geometry.hxx
  gfx/primitive.hxx
  gfx/camera.hxx
  gfx/font.hxx
  gfx/text.hxx
  )

set(sfx_SRCS
  sfx/audio.cxx
  sfx/mixer.cxx
  sfx/sample.cxx
  )
set(sfx_HDRS
  sfx/audio.hxx
  sfx/mixer.hxx
  sfx/sample.hxx
  )

set(all_SRCS ${core_SRCS} ${gfx_SRCS} ${sfx_SRCS})
set(all_HDRS ${core_HDRS} ${gfx_HDRS} ${sfx_HDRS})

add_library(haze STATIC ${all_SRCS} ${all_HDRS})
