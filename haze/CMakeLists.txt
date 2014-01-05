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

set(HAZE_LIBRARIES "")

find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
  set(HAVE_OPENGL ON)
  set(HAZE_LIBRARIES ${HAZE_LIBRARIES} ${OPENGL_LIBRARIES})
endif()

find_package(OpenAL REQUIRED)
if(OPENAL_FOUND)
  set(HAVE_OPENAL ON)
  set(HAZE_LIBRARIES ${HAZE_LIBRARIES} ${OPENAL_LIBRARY})
endif()

set(HAZE_INCLUDES "" PARENT_SCOPE)

set(SDL2_BUILDING_LIBRARY TRUE)
find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
  set(HAVE_SDL2 ON)
  set(HAZE_LIBRARIES ${HAZE_LIBRARIES} ${SDL2_LIBRARY})

  set(HAZE_INCLUDES ${HAZE_INCLUDES} ${SDL2_INCLUDE_DIR} PARENT_SCOPE)
  include_directories(${SDL2_INCLUDE_DIR})

  message(STATUS "Found SDL2: " ${SDL2_LIBRARY})
else()
  message(STATUS "SDL2 NOT found!")
endif()

find_package(SDL2_image)
if(SDL2IMAGE_FOUND)
  set(HAVE_SDL2_IMAGE ON)
  set(HAZE_LIBRARIES ${HAZE_LIBRARIES} ${SDL2IMAGE_LIBRARY})

  set(HAZE_INCLUDES ${HAZE_INCLUDES} ${SDL2IMAGE_INCLUDE_DIR} PARENT_SCOPE)
  include_directories(${SDL2IMAGE_INCLUDE_DIR})

  message(STATUS "Found SDL2_image: " ${SDL2IMAGE_LIBRARY})
else()
  message(STATUS "SDL2_image NOT found!")
endif()

find_package(SDL2_mixer)
if(SDL2MIXER_FOUND)
  set(HAVE_SDL2_MIXER ON)
  set(HAZE_LIBRARIES ${HAZE_LIBRARIES} ${SDL2MIXER_LIBRARY})

  set(HAZE_INCLUDES ${HAZE_INCLUDES} ${SDL2MIXER_INCLUDE_DIR} PARENT_SCOPE)
  include_directories(${SDL2MIXER_INCLUDE_DIR})

  message(STATUS "Found SDL2_mixer: " ${SDL2MIXER_LIBRARY})
else()
  message(STATUS "SDL2_mixer NOT found!")
endif()

include_directories(${HAZE_INCLUDES})

option(WANT_DEBUG    "Debugging"     ON)
option(WANT_LOGS     "Logs"          ON)
option(WANT_DEBUG_GL "Debug GL code" ON)

set(HAZE_VIEWPORT_WIDTH  "720"   CACHE STRING "Viewport width")
set(HAZE_VIEWPORT_HEIGHT "480"   CACHE STRING "Viewport height")
set(HAZE_VIEWPORT_BPP    "24"    CACHE STRING "Viewport depth (bit per pixel)")

set(HAZE_MIXER_FREQUENCY "44100" CACHE STRING "Frequency")
set(HAZE_MIXER_CHANNELS  "2"     CACHE STRING "Channels")

#configure_file("${CMAKE_CURRENT_SOURCE_DIR}/haze/version.hh.in" "${CMAKE_CURRENT_BINARY_DIR}/haze/version.hh")

configure_file(config.hh.in config.hh)

#if(CMAKE_COMPILER_IS_GNUCXX)
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
#endif()

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR})

add_library(haze SHARED
  utils/string.cc
  utils/regex.cc
  utils/debug.cc
  utils/log.cc
  utils/utils.cc

  core/exception.cc
  core/pattern.cc
  core/synchronization.cc
  core/thread.cc
  core/time.cc
  core/core.cc

  fs/filesystem.cc

  gfx/gl.cc
  gfx/math.cc
  gfx/view.cc
  gfx/camera.cc
  gfx/font.cc
  gfx/geometry.cc
  gfx/image.cc
  gfx/text.cc
  gfx/video.cc
  gfx/gfx.cc

  ui/ui.cc

  sfx/audio.cc
  sfx/sfx.cc

  io/io.cc

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

target_link_libraries(haze ${HAZE_LIBRARIES})
