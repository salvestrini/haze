cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

project(Haze)

find_package(OpenGL    REQUIRED)
find_package(SDL       REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_mixer REQUIRED)

add_subdirectory(haze)
add_subdirectory(tests)

include(FeatureSummary)
print_enabled_features()

#include(CMakePrintSystemInformation)

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Remote Operations On Files")
SET(CPACK_PACKAGE_VENDOR              "Francesco Salvestrini")
SET(CPACK_PACKAGE_DESCRIPTION_FILE    "${CMAKE_CURRENT_SOURCE_DIR}/README")
SET(CPACK_RESOURCE_FILE_LICENSE       "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
SET(CPACK_PACKAGE_VERSION_MAJOR       "1")
SET(CPACK_PACKAGE_VERSION_MINOR       "0")
SET(CPACK_PACKAGE_VERSION_PATCH       "0")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY   "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
INCLUDE(CPack)
