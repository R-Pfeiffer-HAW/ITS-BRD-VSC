<<<<<<<< HEAD:Programs/Stack/tmp/1/cmake_install.cmake
# Install script for directory: /Users/esmatrabaki/ITS-BRD-VSC/Programs/Stack/tmp/Stack.Debug+ITSboard
========
# Install script for directory: /Users/esmatrabaki/ITS-BRD-VSC/Programs/Tasch/tmp/Tasch.Debug+ITSboard
>>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62:Programs/Tasch/tmp/1/cmake_install.cmake

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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<<< HEAD:Programs/Stack/tmp/1/cmake_install.cmake
file(WRITE "/Users/esmatrabaki/ITS-BRD-VSC/Programs/Stack/tmp/1/${CMAKE_INSTALL_MANIFEST}"
========
file(WRITE "/Users/esmatrabaki/ITS-BRD-VSC/Programs/Tasch/tmp/1/${CMAKE_INSTALL_MANIFEST}"
>>>>>>>> c9caa946ca8ba15f9ac02a091e43fe7176d1aa62:Programs/Tasch/tmp/1/cmake_install.cmake
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
