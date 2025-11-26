# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/DrehgeberPolling/tmp/DrehgeberPolling.Debug+ITSboard"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/DrehgeberPolling/tmp/1"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/DrehgeberPolling/tmp/DrehgeberPolling.Debug+ITSboard"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/DrehgeberPolling/tmp/DrehgeberPolling.Debug+ITSboard/tmp"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/DrehgeberPolling/tmp/DrehgeberPolling.Debug+ITSboard/src/DrehgeberPolling.Debug+ITSboard-stamp"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/DrehgeberPolling/tmp/DrehgeberPolling.Debug+ITSboard/src"
  "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/DrehgeberPolling/tmp/DrehgeberPolling.Debug+ITSboard/src/DrehgeberPolling.Debug+ITSboard-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/DrehgeberPolling/tmp/DrehgeberPolling.Debug+ITSboard/src/DrehgeberPolling.Debug+ITSboard-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/raphaelpfeiffer/Documents/TI-Labor/gitProjekte/ITSBoard/ITS-BRD-VSC/Programs/DrehgeberPolling/tmp/DrehgeberPolling.Debug+ITSboard/src/DrehgeberPolling.Debug+ITSboard-stamp${cfgdir}") # cfgdir has leading slash
endif()
