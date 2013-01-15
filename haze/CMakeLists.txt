enable_language(CXX)

include(CheckIncludeFile)
include(CheckSymbolExists)

CHECK_INCLUDE_FILE(execinfo.h HAVE_EXECINFO_H)
if(HAVE_EXECINFO_H)
  CHECK_SYMBOL_EXISTS(backtrace         execinfo.h HAVE_BACKTRACE)
  CHECK_SYMBOL_EXISTS(backtrace_symbols execinfo.h HAVE_BACKTRACE_SYMBOLS)
endif()

CHECK_INCLUDE_FILE(regex.h HAVE_REGEX_H)
if(HAVE_REGEX_H)
  CHECK_SYMBOL_EXISTS(regexec  regex.h HAVE_REGEXEC)
  CHECK_SYMBOL_EXISTS(regcomp  regex.h HAVE_REGCOMP)
  CHECK_SYMBOL_EXISTS(regerror regex.h HAVE_REGERROR)
  CHECK_SYMBOL_EXISTS(regfree  regex.h HAVE_REGFREE)
endif()

find_package(OpenGL    REQUIRED)
find_package(OpenAL    REQUIRED)

find_package(SDL       REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_mixer REQUIRED)

configure_file(config.hh.in config.hh)

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
  core/regex.cc
  core/utils.cc
  core/pattern.cc
  core/synchronization.cc
  core/thread.cc
  core/time.cc
  core/core.cc

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
  gfx/gfx.cc

  sfx/audio.cc
  sfx/sfx.cc

  io/io.cc

  version.cc
  haze.cc
)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-Wall"   CXX_SUPPORTS_WALL)
CHECK_CXX_COMPILER_FLAG("-Werror" CXX_SUPPORTS_WERROR)
CHECK_CXX_COMPILER_FLAG("-Wundef" CXX_SUPPORTS_WUNDEF)

include(MacroAddCompileFlags)
if("${CXX_SUPPORTS_WALL}")
  MACRO_ADD_COMPILE_FLAGS(haze "-Wall")
endif()
if("${CXX_SUPPORTS_WERROR}")
  MACRO_ADD_COMPILE_FLAGS(haze "-Werror")
endif()
if("${CXX_SUPPORTS_WUNDEF}")
  MACRO_ADD_COMPILE_FLAGS(haze "-Wundef")
endif()
