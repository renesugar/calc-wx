cmake_minimum_required(VERSION 3.8.2)
project(calc-wx CXX)

set(CMAKE_VERBOSE_MAKEFILE 1)
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)

set(APP_TARGET calc-wx)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Project include directory
set(PROJECT_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/../include")
include_directories(${PROJECT_INCLUDES})

# Mac OS Mojave changed #include directories
set(LLVM_INCLUDES " /usr/local/opt/llvm/include/c++/v1")
include_directories(${LLMV_INCLUDES})
set(MACSDK_INCLUDES "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/usr/include")
include_directories(${MACSDK_INCLUDES})

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

file(GLOB sources "*.cpp")

add_executable(${APP_TARGET} ${sources})

find_package(wxWidgets REQUIRED gl core base net)
include(${wxWidgets_USE_FILE})
# and for each of your dependent executable/library targets:
target_link_libraries(${APP_TARGET} ${wxWidgets_LIBRARIES})

#if (APPLE)
#    find_library(COCOA_LIBRARY Cocoa)
#    find_library(IOKIT_LIBRARY IOKit)
#    find_library(COREVIDEO_LIBRARY CoreVideo)
#    SET(EXTRA_LIBS ${COCOA_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY})
#endif (APPLE)

