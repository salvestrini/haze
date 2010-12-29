project(haze)

set(PROJECT_MAJOR_VERSION "0")
set(PROJECT_MINOR_VERSION "0")
set(PROJECT_MICRO_VERSION "1")

cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if(CMAKE_COMPILER_IS_GNUC)
  set(CMAKE_C_FLAGS   "-Wall -Werror")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-Wall -Werror")
endif()

find_package(SDL       REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(OpenGL    REQUIRED)
find_package(OpenAL    REQUIRED)

add_subdirectory(tools)
add_subdirectory(haze)
add_subdirectory(tests)

include(FeatureSummary)
print_enabled_features()
