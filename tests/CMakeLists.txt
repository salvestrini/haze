include_directories(${haze_SOURCE_DIR})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(LIBRARIES
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  SDLmain

  ${OPENGL_LIBRARIES}
  ${OPENAL_LIBRARY}

  ${PROJECT_NAME}
)

set(COMMON_SOURCES
  common.cxx
)

add_executable(test-core        ${COMMON_SOURCES} test-core.cxx)
target_link_libraries(test-core ${LIBRARIES})

add_executable(test-gfx         ${COMMON_SOURCES} test-gfx.cxx)
target_link_libraries(test-gfx  ${LIBRARIES})

add_executable(test-sfx         ${COMMON_SOURCES} test-sfx.cxx)
target_link_libraries(test-sfx  ${LIBRARIES})

add_executable(test-io          ${COMMON_SOURCES} test-io.cxx)
target_link_libraries(test-io   ${LIBRARIES})

add_executable(test-all         ${COMMON_SOURCES} test-all.cxx)
target_link_libraries(test-all  ${LIBRARIES})
