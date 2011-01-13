include_directories(${haze_SOURCE_DIR})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test-core
  test-core.cxx)

target_link_libraries(test-core
  ${SDL_LIBRARY}
  SDLmain

  ${PROJECT_NAME}
  )

add_executable(test-gfx
  test-gfx.cxx)

target_link_libraries(test-gfx
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  SDLmain

  ${OPENGL_LIBRARIES}

  ${PROJECT_NAME}
  )

add_executable(test-sfx
  test-sfx.cxx)

target_link_libraries(test-sfx
  ${SDL_LIBRARY}
  ${SDLMIXER_LIBRARY}
  SDLmain

  ${OPENAL_LIBRARY}

  ${PROJECT_NAME}
  )

add_executable(test-io
  test-io.cxx)

target_link_libraries(test-io
  ${SDL_LIBRARY}
  SDLmain

  ${PROJECT_NAME}
  )

add_executable(test-all
  test-all.cxx)

target_link_libraries(test-all
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  SDLmain

  ${OPENGL_LIBRARIES}
  ${OPENAL_LIBRARY}

  ${PROJECT_NAME}
  )
