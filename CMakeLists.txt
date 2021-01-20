cmake_minimum_required(VERSION 3.1)

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" VERSION_GREATER 2.6)
  if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}" VERSION_GREATER 2.8.3)
    cmake_policy(VERSION 3.2)
  else()
    cmake_policy(VERSION 3.0)
  endif()
endif()

set( CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true )
 
if ( COMMAND cmake_policy )

  cmake_policy( SET CMP0003 NEW )  

endif()


project(place_and_route VERSION 1.0
                  DESCRIPTION "SWIG Cmake Router"
                  LANGUAGES CXX)


#Adding the current folder into the includes so that the compiled binary will find 
#the corresponding headers when I run it through the swig section

include_directories(".")

#Workgin compilation of the shared library

add_library(place_and_route_corelib placer.cpp placer.hpp router.cpp router.hpp)

target_compile_features(place_and_route_corelib PUBLIC cxx_std_11)

target_compile_options(place_and_route_corelib PUBLIC "-fPIC")

#SWIG stuff:
#load the cmake SWIG package
find_package(SWIG 4.0 REQUIRED)

# message(WARNING ${SWIG_VERSION})
# message(WARNING ${SWIG_DIR})

include(${SWIG_USE_FILE})

#Set the swig language
set_property(SOURCE place_and_route.i PROPERTY CPLUSPLUS ON)
set_property(TARGET place_and_route_corelib PROPERTY SWIG_COMPILE_OPTIONS -doxygen)

#load the package that SWIG uses to generate Python
find_package(PythonLibs)

#point to python headers
include_directories(${PYTHON_INCLUDE_DIRS} LANGUAGE python)

#tell SWIG to create a new module, called aarf, 
#in Python and point to the SWIG interface file (the .i file)
swig_add_library(place_and_route LANGUAGE python SOURCES place_and_route.i)

swig_link_libraries(place_and_route place_and_route_corelib)

swig_link_libraries(place_and_route ${PYTHON_INCLUDE_DIRS})