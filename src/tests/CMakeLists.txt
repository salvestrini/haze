include_directories(${CMAKE_SOURCE_DIR}/src/libs)

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

   gfx
   core
)
