# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/Taschenrechner1/tmp/Taschenrechner1.Debug+ITSboard"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/Taschenrechner1/tmp/1"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/Taschenrechner1/tmp/Taschenrechner1.Debug+ITSboard"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/Taschenrechner1/tmp/Taschenrechner1.Debug+ITSboard/tmp"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/Taschenrechner1/tmp/Taschenrechner1.Debug+ITSboard/src/Taschenrechner1.Debug+ITSboard-stamp"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/Taschenrechner1/tmp/Taschenrechner1.Debug+ITSboard/src"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/Taschenrechner1/tmp/Taschenrechner1.Debug+ITSboard/src/Taschenrechner1.Debug+ITSboard-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/Taschenrechner1/tmp/Taschenrechner1.Debug+ITSboard/src/Taschenrechner1.Debug+ITSboard-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/Taschenrechner1/tmp/Taschenrechner1.Debug+ITSboard/src/Taschenrechner1.Debug+ITSboard-stamp${cfgdir}") # cfgdir has leading slash
endif()
