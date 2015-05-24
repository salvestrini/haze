include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/haze)

include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_BINARY_DIR}/haze)

configure_file(data.hh.in data.hh)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${HAZE_INCLUDES})

link_directories(${CMAKE_BINARY_DIR}/haze)

add_executable(test-01 test-01.cc)

target_link_libraries(test-01 haze)

add_executable(test-slideshow slideshow.cc)

target_link_libraries(test-slideshow haze)
