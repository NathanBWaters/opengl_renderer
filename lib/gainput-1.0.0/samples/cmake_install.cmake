# Install script for directory: /Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/basic/cmake_install.cmake")
  include("/Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/dynamic/cmake_install.cmake")
  include("/Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/gesture/cmake_install.cmake")
  include("/Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/listener/cmake_install.cmake")
  include("/Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/recording/cmake_install.cmake")
  include("/Users/nwaters/code/go_stop/lib/gainput-1.0.0/samples/sync/cmake_install.cmake")

endif()

