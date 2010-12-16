include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(core_SOURCES
  core/debug.cxx
  core/exception.cxx
  core/filesystem.cxx
  core/log.cxx
  core/pattern.cxx
  core/synchronization.cxx
  core/thread.cxx
  core/timer.cxx
  )

set(gfx_SOURCES
  gfx/video.cxx
  gfx/geometry.cxx
  gfx/camera.cxx
  gfx/texture.cxx
  gfx/image.cxx
  gfx/font.cxx
  gfx/text.cxx
  )

set(sfx_SOURCES
  sfx/mixer.cxx
  sfx/sample.cxx
  )

set(io_SOURCES
  io/keyboard.cxx
  io/mouse.cxx
  )

add_library(core STATIC ${core_SOURCES})
add_library(gfx  STATIC ${gfx_SOURCES})
add_library(sfx  STATIC ${sfx_SOURCES})
add_library(io   STATIC ${io_SOURCES})

#target_link_libraries(core LINK_INTERFACE_LIBRARIES ${SDL_LIBRARY})
#target_link_libraries(gfx  LINK_INTERFACE_LIBRARIES ${SDL_LIBRARY} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
#target_link_libraries(sfx  LINK_INTERFACE_LIBRARIES ${SDL_LIBRARY})
#target_link_libraries(io   LINK_INTERFACE_LIBRARIES ${SDL_LIBRARY})
