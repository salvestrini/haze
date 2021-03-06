find_path(SDL2IMAGE_INCLUDE_DIR SDL_image.h
  HINTS
  $ENV{SDL2IMAGEDIR}
  $ENV{SDL2DIR}
  PATH_SUFFIXES include/SDL2 include
  PATHS
  /usr/local/include/SDL2
  /usr/include/SDL2
)
#message("SDL2IMAGE_INCLUDE_DIR is ${SDL2IMAGE_INCLUDE_DIR}")

find_library(SDL2IMAGE_LIBRARY
  NAMES SDL2_image
  HINTS
  $ENV{SDL2IMAGEDIR}
  $ENV{SDL2DIR}
  PATH_SUFFIXES lib64 lib
  PATHS
  /usr/local
  /usr
)
#message("SDL2IMAGE_LIBRARY is ${SDL2IMAGE_LIBRARY}")

set(SDL2IMAGE_FOUND "NO")
if(SDL2IMAGE_LIBRARY AND SDL2IMAGE_INCLUDE_DIR)
  set(SDL2IMAGE_FOUND "YES")
endif(SDL2IMAGE_LIBRARY AND SDL2IMAGE_INCLUDE_DIR)
