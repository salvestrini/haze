find_package(OpenGL    REQUIRED)
find_package(SDL       REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_mixer REQUIRED)

configure_file(config.h.in config.h)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR})

add_library(haze SHARED
  core/debug.cxx
  core/exception.cxx
  core/filesystem.cxx
  core/log.cxx
  core/pattern.cxx
  core/synchronization.cxx
  core/thread.cxx
  core/time.cxx

  gfx/backends/gl.cxx

  gfx/math.cxx
  gfx/view.cxx
  gfx/camera.cxx
  gfx/font.cxx
  gfx/fps.cxx
  gfx/geometry.cxx
  gfx/image.cxx
  gfx/text.cxx
  gfx/video.cxx

  sfx/audio.cxx

  io/io.cxx
)
