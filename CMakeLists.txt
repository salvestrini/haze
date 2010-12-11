project(haze)

set(PROJECT_MAJOR_VERSION "0")
set(PROJECT_MINOR_VERSION "0")
set(PROJECT_MICRO_VERSION "1")

cmake_minimum_required(VERSION 2.6.0)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(src)

include(FeatureSummary)
print_enabled_features()
