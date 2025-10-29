# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/esmatrabaki/ITS-BRD-VSC/Programs/Tasch/tmp/Tasch.Debug+ITSboard"
  "/Users/esmatrabaki/ITS-BRD-VSC/Programs/Tasch/tmp/1"
  "/Users/esmatrabaki/ITS-BRD-VSC/Programs/Tasch/tmp/Tasch.Debug+ITSboard"
  "/Users/esmatrabaki/ITS-BRD-VSC/Programs/Tasch/tmp/Tasch.Debug+ITSboard/tmp"
  "/Users/esmatrabaki/ITS-BRD-VSC/Programs/Tasch/tmp/Tasch.Debug+ITSboard/src/Tasch.Debug+ITSboard-stamp"
  "/Users/esmatrabaki/ITS-BRD-VSC/Programs/Tasch/tmp/Tasch.Debug+ITSboard/src"
  "/Users/esmatrabaki/ITS-BRD-VSC/Programs/Tasch/tmp/Tasch.Debug+ITSboard/src/Tasch.Debug+ITSboard-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/esmatrabaki/ITS-BRD-VSC/Programs/Tasch/tmp/Tasch.Debug+ITSboard/src/Tasch.Debug+ITSboard-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/esmatrabaki/ITS-BRD-VSC/Programs/Tasch/tmp/Tasch.Debug+ITSboard/src/Tasch.Debug+ITSboard-stamp${cfgdir}") # cfgdir has leading slash
endif()
