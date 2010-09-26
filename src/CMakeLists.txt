Find_Package(SDL REQUIRED)
#Find_Package(SDL_image REQUIRED)

if (NOT SDL_FOUND)
   message (FATAL_ERROR "SDL not found!")
endif (NOT SDL_FOUND)

link_libraries (
   ${SDL_LIBRARY}
   SDLmain # Sadly not included in SDL_LIBRARY variable
)

set(project_SOURCES
        debug.cxx
        log.cxx
        utility.cxx
        pattern.cxx
        synchronization.cxx
        thread.cxx
        application.cxx
        main.cxx
)

#set(CMAKE_C_FLAGS   "-Wall -Werror")
#set(CMAKE_CXX_FLAGS "-Wall -Werror")

add_executable(project ${project_SOURCES})

#target_link_libraries(project ${SDL_LIBRARIES} ${GPHOTO2_LIBRARIES})
