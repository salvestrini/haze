configure_file(config.hxx.in config.hxx)

include_directories(${haze_SOURCE_DIR})
include_directories(${haze_BINARY_DIR}/tests)

set(LIBRARIES
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  SDLmain

  ${OPENGL_LIBRARIES}
  ${OPENAL_LIBRARY}

  ${PROJECT_NAME}
)

set(COMMON_SOURCES
  config.hxx
  common.cxx
)

add_library(common ${COMMON_SOURCES})

add_executable(test-core        test-core.cxx)
target_link_libraries(test-core common ${LIBRARIES})

add_executable(test-gfx         test-gfx.cxx)
target_link_libraries(test-gfx  common ${LIBRARIES})

add_executable(test-sfx         test-sfx.cxx)
target_link_libraries(test-sfx  common ${LIBRARIES})

add_executable(test-io          test-io.cxx)
target_link_libraries(test-io   common ${LIBRARIES})

add_executable(test-all         test-all.cxx)
target_link_libraries(test-all  common ${LIBRARIES})
