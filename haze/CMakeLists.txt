find_package(OpenGL    REQUIRED)
find_package(OpenAL    REQUIRED)

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
  core/debug.cc
  core/exception.cc
  core/filesystem.cc
  core/log.cc
  core/pattern.cc
  core/synchronization.cc
  core/thread.cc
  core/time.cc

  gfx/backends/gl.cc

  gfx/math.cc
  gfx/view.cc
  gfx/camera.cc
  gfx/font.cc
  gfx/fps.cc
  gfx/geometry.cc
  gfx/image.cc
  gfx/text.cc
  gfx/video.cc

  sfx/audio.cc

  io/io.cc

  haze.cc
)
