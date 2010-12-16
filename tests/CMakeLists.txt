include_directories(${CMAKE_SOURCE_DIR}/src)

enable_testing()

add_executable(test-core
  test-core.cxx)

target_link_libraries(test-core
  ${SDL_LIBRARY}
  SDLmain

  core
  )
add_test(NAME test-core CONFIGURATIONS Debug COMMAND test-core ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test-gfx
  test-gfx.cxx)

target_link_libraries(test-gfx
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  SDLmain

  ${OPENGL_LIBRARIES}

  gfx
  core
  )

add_test(NAME test-gfx CONFIGURATIONS Debug COMMAND test-gfx ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test-sfx
  test-sfx.cxx)

target_link_libraries(test-sfx
  ${SDL_LIBRARY}
  ${SDLMIXER_LIBRARY}
  SDLmain

  ${OPENAL_LIBRARY}

  sfx
  core
  )

add_test(NAME test-sfx CONFIGURATIONS Debug COMMAND test-sfx ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test-io
  test-sfx.cxx)

target_link_libraries(test-io
  ${SDL_LIBRARY}
  SDLmain

  io
  core
  )

add_test(NAME test-io CONFIGURATIONS Debug COMMAND test-io ${CMAKE_CURRENT_BINARY_DIR})

add_executable(test-all
  test-all.cxx)

target_link_libraries(test-all
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  SDLmain

  ${OPENGL_LIBRARIES}
  ${OPENAL_LIBRARY}

  io
  gfx
  sfx
  core
  )

add_test(NAME test-all CONFIGURATIONS Debug COMMAND test-all ${CMAKE_CURRENT_BINARY_DIR})
