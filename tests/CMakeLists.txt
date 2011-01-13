include_directories(${haze_SOURCE_DIR})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(LIBRARIES
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  SDLmain

  ${OPENGL_LIBRARIES}
  ${OPENAL_LIBRARY}

  ${PROJECT_NAME}
)

add_executable(test-core        test-core.cxx)
target_link_libraries(test-core ${LIBRARIES})

add_executable(test-gfx         test-gfx.cxx)
target_link_libraries(test-gfx  ${LIBRARIES})

add_executable(test-sfx         test-sfx.cxx)
target_link_libraries(test-sfx  ${LIBRARIES})

add_executable(test-io          test-io.cxx)
target_link_libraries(test-io   ${LIBRARIES})

add_executable(test-all         test-all.cxx)
target_link_libraries(test-all  ${LIBRARIES})
