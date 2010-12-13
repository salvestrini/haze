include_directories(${CMAKE_SOURCE_DIR}/src/libs)

add_executable(test
  main.cxx)

target_link_libraries(test
   ${SDL_LIBRARY}
   ${SDL_LIBRARIES}
   SDLmain

   core
   sfx
   gfx
   io
)
