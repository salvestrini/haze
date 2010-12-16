include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(test-core
  test-core.cxx)

target_link_libraries(test-core
   ${SDL_LIBRARY}
#   ${SDL_LIBRARIES}
   SDLmain

   core
)

add_executable(test-gfx
  test-gfx.cxx)

target_link_libraries(test-gfx
   ${SDL_LIBRARY}
#   ${SDL_LIBRARIES}
   SDLmain

   ${OPENGL_LIBRARY}

   gfx
   core
)

add_executable(test-sfx
  test-sfx.cxx)

target_link_libraries(test-sfx
   ${SDL_LIBRARY}
#   ${SDL_LIBRARIES}
   SDLmain

   ${OPENAL_LIBRARY}

   sfx
   core
)

add_executable(test-io
  test-sfx.cxx)

target_link_libraries(test-io
   ${SDL_LIBRARY}
#   ${SDL_LIBRARIES}
   SDLmain

   io
   core
)

add_executable(test-all
  test-all.cxx)

target_link_libraries(test-all
   ${SDL_LIBRARY}
#   ${SDL_LIBRARIES}
   SDLmain

   ${OPENGL_LIBRARY}
   ${OPENAL_LIBRARY}

   io
   gfx
   sfx
   core
)

#target_link_libraries(core LINK_INTERFACE_LIBRARIES ${SDL_LIBRARY})
#target_link_libraries(gfx  LINK_INTERFACE_LIBRARIES ${SDL_LIBRARY} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
#target_link_libraries(sfx  LINK_INTERFACE_LIBRARIES ${SDL_LIBRARY})
#target_link_libraries(io   LINK_INTERFACE_LIBRARIES ${SDL_LIBRARY})
