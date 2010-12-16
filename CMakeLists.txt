project(haze)

set(PROJECT_MAJOR_VERSION "0")
set(PROJECT_MINOR_VERSION "0")
set(PROJECT_MICRO_VERSION "1")

cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_C_FLAGS   "-Wall -Werror")
set(CMAKE_CXX_FLAGS "-Wall -Werror")

Find_Package(SDL REQUIRED)
#Find_Package(SDL_image REQUIRED)
if (NOT SDL_FOUND)
  message (FATAL_ERROR "SDL not found!")
endif()

Find_Package(OpenGL REQUIRED)
if (NOT OPENGL_FOUND)
  message (FATAL_ERROR "OpenGL not found!")
endif()

Find_Package(OpenAL REQUIRED)
if (NOT OPENAL_FOUND)
  message (FATAL_ERROR "OpenAL not found!")
endif()

add_subdirectory(src)
add_subdirectory(tests)

include(FeatureSummary)
print_enabled_features()
