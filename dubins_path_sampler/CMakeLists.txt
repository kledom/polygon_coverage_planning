cmake_minimum_required(VERSION 3.0.2)
project(dubins_path_sampler)

find_package(catkin REQUIRED)

catkin_python_setup()

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES dubins_path_creator
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
catkin_install_python(PROGRAMS
  scripts/my_python_script
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
