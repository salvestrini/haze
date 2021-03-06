enable_language(CXX)

include(CheckIncludeFile)
include(CheckSymbolExists)
include(GNUInstallDirs)

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/version.hh.in"
  "${CMAKE_CURRENT_BINARY_DIR}/version.hh")

CHECK_INCLUDE_FILE(execinfo.h HAVE_EXECINFO_H)
if(HAVE_EXECINFO_H)
  CHECK_SYMBOL_EXISTS(backtrace         execinfo.h HAVE_BACKTRACE)
  CHECK_SYMBOL_EXISTS(backtrace_symbols execinfo.h HAVE_BACKTRACE_SYMBOLS)
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

include_directories(${HAZE_INCLUDES})

option(WANT_DEBUG    "Debugging"     ON)
option(WANT_LOGS     "Logs"          ON)
option(WANT_DEBUG_GL "Debug GL code" ON)

set(HAZE_VIEWPORT_WIDTH  "720"   CACHE STRING "Viewport width")
set(HAZE_VIEWPORT_HEIGHT "480"   CACHE STRING "Viewport height")
set(HAZE_VIEWPORT_BPP    "24"    CACHE STRING "Viewport depth (bit per pixel)")

#configure_file("${CMAKE_CURRENT_SOURCE_DIR}/haze/version.hh.in" "${CMAKE_CURRENT_BINARY_DIR}/haze/version.hh")

configure_file(config.hh.in config.hh)

#if(CMAKE_COMPILER_IS_GNUCXX)
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
#endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(haze SHARED
  utils/string.cc
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

  io/io.cc

  gfx/gl.cc
  gfx/math.cc
  gfx/view.cc
  gfx/camera.cc
  gfx/geometry.cc
  gfx/image.cc
  gfx/video.cc
  gfx/gfx.cc

  ui/font.cc
  ui/text.cc
  ui/ui.cc

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

#set(HAZE_LIBRARIES_PRIVATE "")
#foreach(LIB ${HAZE_LIBRARIES})
#  set(HAZE_LIBRARIES_PRIVATE "${HAZE_LIBRARIES_PRIVATE} -l${LIB}")
#endforeach()

install(TARGETS haze DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})

#
# pkg-config
#

include(MacroSetOption)
haze_set_option(
  HAZE_BUILD_SHARED_LIBS
  TRUE BOOL
  "TRUE to build shared libraries")

if(HAZE_BUILD_SHARED_LIBS)
  haze_set_option(
    HAZE_INSTALL_PKGCONFIG_FILES TRUE BOOL
    "TRUE to automatically install pkg-config files")
  if(HAZE_INSTALL_PKGCONFIG_FILES)
      configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/haze.pc.in"
        "${CMAKE_CURRENT_BINARY_DIR}/haze.pc"
        @ONLY)
      install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/haze.pc"
        DESTINATION "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/pkgconfig")
  endif()
else()
  if(HAZE_INSTALL_PKGCONFIG_FILES)
    message(WARNING "No pkg-config files are provided for static linking (HAZE_INSTALL_PKGCONFIG_FILES will be ignored).")
  endif()
endif()
