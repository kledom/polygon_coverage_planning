cmake_minimum_required(VERSION 2.8.4)
project(polygon_coverage_solvers)

find_package(catkin_simple REQUIRED)
catkin_simple(ALL_DEPS_REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Download glkh
include(ExternalProject)
ExternalProject_Add(
  glkh
  URL http://webhotel4.ruc.dk/~keld/research/GLKH/GLKH-1.0.tgz
  DOWNLOAD_NAME glkh_source_codes.tgz
  URL_MD5 9b0ba92053dac798f550c5c8a9524120
  BUILD_IN_SOURCE 1
  UPDATE_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND $(MAKE)
  INSTALL_COMMAND ""
)

# Download GTSP test instances.
include(ExternalProject)
ExternalProject_Add(
  gtsp_instances
  URL http://www.cs.nott.ac.uk/~dxk/gtsplib/InstancesBinary.zip
  URL https://polybox.ethz.ch/index.php/s/51iqurpOOQ5cVaJ/download
  DOWNLOAD_NAME InstancesBinary.zip
  URL_MD5 255831bd47de71df8419a54741f0a6be
  UPDATE_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
)

#############
# LIBRARIES #
#############
cs_add_library(${PROJECT_NAME}
  src/glkh.cc
  src/combinatorics.cc
  src/boolean_lattice.cc
)

#########
# TESTS #
#########
catkin_add_gtest(test_combinatorics
  test/combinatorics-test.cpp
)
target_link_libraries(test_combinatorics ${PROJECT_NAME})

catkin_add_gtest(test_glkh
  test/glkh-test.cpp
)
target_link_libraries(test_glkh ${PROJECT_NAME})


##########
# EXPORT #
##########
cs_install()
cs_export()
