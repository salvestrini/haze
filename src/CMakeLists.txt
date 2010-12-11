add_subdirectory(libs)

set(project_SOURCES
        main.cxx
)

set(CMAKE_C_FLAGS   "-Wall -Werror")
set(CMAKE_CXX_FLAGS "-Wall -Werror")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs)

add_executable(project ${project_SOURCES})

target_link_libraries(project
   ${SDL_LIBRARY}
   ${SDL_LIBRARIES}
   SDLmain

   core
   sfx
   gfx
   io
)
