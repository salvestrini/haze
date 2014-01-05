cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH      "${CMAKE_SOURCE_DIR}/cmake")
#set(CMAKE_VERBOSE_MAKEFILE ON)

project(Haze)

add_subdirectory(haze)
add_subdirectory(tests)

include(GitVersionGen)
GIT_VERSION_GEN("0.0.0")

message(STATUS "Package version is: ${PACKAGE_VERSION_MAJOR}.${PACKAGE_VERSION_MINOR}.${PACKAGE_VERSION_MICRO}")

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/haze/version.hh.in"
  "${CMAKE_CURRENT_BINARY_DIR}/haze/version.hh")

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The HAZE library")
set(CPACK_PACKAGE_VENDOR              "Francesco Salvestrini")
set(CPACK_PACKAGE_DESCRIPTION_FILE    "${CMAKE_CURRENT_SOURCE_DIR}/README")
set(CPACK_RESOURCE_FILE_LICENSE       "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR       ${PACKAGE_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR       ${PACKAGE_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH       ${PACKAGE_VERSION_MICRO})
set(CPACK_PACKAGE_INSTALL_DIRECTORY   "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
include(CPack)

include(MacroSetOption)
haze_set_option(
  HAZE_BUILD_SHARED_LIBS
  TRUE BOOL
  "TRUE to build shared libraries")

if(HAZE_BUILD_SHARED_LIBS)
  haze_set_option(
    HAZE_INSTALL_PKGCONFIG_FILES TRUE BOOL
    "TRUE to automatically install pkg-config files")
  if(HAZE_INSTALL_PKGCONFIG_FILES)
    foreach(haze_module IN ITEMS all core fs gfx io net sfx ui)
      configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/pkg-config/haze-${haze_module}.pc.in"
        "${CMAKE_CURRENT_BINARY_DIR}/pkg-config/haze-${haze_module}.pc"
        @ONLY)
      install(FILES "${CMAKE_CURRENT_BINARY_DIR}/pkg-config/haze-${haze_module}.pc"
        DESTINATION "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/pkgconfig")
    endforeach()
  endif()
else()
  if(HAZE_INSTALL_PKGCONFIG_FILES)
    message(WARNING "No pkg-config files are provided for the static libraries (HAZE_INSTALL_PKGCONFIG_FILES will be ignored).")
  endif()
endif()

#include(CMakePrintSystemInformation)

include(FeatureSummary)
print_enabled_features()
