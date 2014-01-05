find_path(SDL2_INCLUDE_DIR SDL.h
  HINTS
  $ENV{SDL2DIR}
  PATH_SUFFIXES include/SDL2 include
  PATHS
  /usr/local/include/SDL2
  /usr/include/SDL2
)
#message("SDL2_INCLUDE_DIR is ${SDL2_INCLUDE_DIR}")

find_library(SDL2_LIBRARY 
  NAMES SDL2
  HINTS
  $ENV{SDL2DIR}
  PATH_SUFFIXES lib64 lib
  PATHS
  /usr/local
  /usr
)
#message("SDL2_LIBRARY is ${SDL2_LIBRARY}")

set(SDL2_FOUND "NO")
if(SDL2_LIBRARY AND SDL2_INCLUDE_DIR)
  set(SDL2_FOUND "YES")
endif(SDL2_LIBRARY AND SDL2_INCLUDE_DIR)

