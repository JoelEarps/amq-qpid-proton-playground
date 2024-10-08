cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(zenobe_sitecontroller-mock-amq-sender CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXE_NAME amq_tester)
set(LIBRARY_NAME "Sitecontroller_AMQ_Communications")

include(ExternalProject)

add_subdirectory(src)