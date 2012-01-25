include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/haze)

include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_BINARY_DIR}/haze)

configure_file(config.hxx.in config.hxx)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

link_directories(${CMAKE_BINARY_DIR}/haze)

add_library(common STATIC common.cxx)

add_executable(test
  test.cxx
  common.cxx)

target_link_libraries(test
  haze
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  ${OPENGL_gl_LIBRARY}
)
