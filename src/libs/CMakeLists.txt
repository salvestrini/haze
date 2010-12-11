Find_Package(SDL REQUIRED)
#Find_Package(SDL_image REQUIRED)

if (NOT SDL_FOUND)
   message (FATAL_ERROR "SDL not found!")
endif (NOT SDL_FOUND)

link_libraries (
   ${SDL_LIBRARY}
   SDLmain # Sadly not included in SDL_LIBRARY variable
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/core)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gfx)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sfx)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/io)
