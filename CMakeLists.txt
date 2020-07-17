cmake_minimum_required(VERSION 3.1)

project(aarf VERSION 1.0
                  DESCRIPTION "SWIG Cmake Router"
                  LANGUAGES CXX)


#Adding the current folder into the includes so that the compiled binary will find 
#the corresponding headers when I run it through the swig section

include_directories(".")

#Workgin compilation of the shared library

add_library(router_corelib SHARED router.cpp router.hpp)

target_compile_features(router_corelib PUBLIC cxx_std_11)

#SWIG stuff:
#load the cmake SWIG package
find_package(SWIG 4.0 REQUIRED)

# message(WARNING ${SWIG_VERSION})
# message(WARNING ${SWIG_DIR})

include(${SWIG_USE_FILE})

#Set the swig language
set_property(SOURCE router.i PROPERTY CPLUSPLUS ON)

#load the package that SWIG uses to generate Python
find_package(PythonLibs)

#point to python headers
include_directories(${PYTHON_INCLUDE_DIRS} LANGUAGE python)

#tell SWIG to create a new module, called aarf, 
#in Python and point to the SWIG interface file (the .i file)
swig_add_library(aarf LANGUAGE python SOURCES router.i)

swig_link_libraries(aarf router_corelib)

swig_link_libraries(aarf ${PYTHON_INCLUDE_DIRS})