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

  core/core.hxx
  )

set(io_SRCS
  io/io.cxx
  )
set(io_HDRS
  io/io.hxx
  )

set(math_SRCS
  math/math.cxx
  )
set(sfx_HDRS
  math/math.hxx
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

  gfx/gfx.hxx
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
  )
set(sfx_HDRS
  sfx/audio.hxx

  sfx/sfx.hxx
  )

set(all_SRCS haze.cxx ${core_SRCS} ${io_SRCS} ${gfx_SRCS} ${sfx_SRCS})
set(all_HDRS haze.hxx ${core_HDRS} ${io_HDRS} ${gfx_HDRS} ${sfx_HDRS})

add_library(haze ${all_SRCS} ${all_HDRS})

install(TARGETS haze
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib)
