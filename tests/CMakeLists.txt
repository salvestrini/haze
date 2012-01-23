include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/haze)

include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_BINARY_DIR}/haze)

configure_file(config.hxx.in config.hxx)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

link_directories(${CMAKE_BINARY_DIR}/haze)

add_library(common STATIC common.cxx)

add_executable(test-all test-all.cxx)
target_link_libraries(test-all common
  haze
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  ${OPENGL_gl_LIBRARY}
)

add_executable(test-core test-core.cxx)
target_link_libraries(test-core common
  haze
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  ${OPENGL_gl_LIBRARY}
)  

add_executable(test-gfx test-gfx.cxx)
target_link_libraries(test-gfx common
  haze
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  ${OPENGL_gl_LIBRARY}
)

add_executable(test-sfx test-sfx.cxx)
target_link_libraries(test-sfx common
  haze
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  ${OPENGL_gl_LIBRARY}
)

add_executable(test-io test-io.cxx)
target_link_libraries(test-io common
  haze
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  ${OPENGL_gl_LIBRARY}
)
