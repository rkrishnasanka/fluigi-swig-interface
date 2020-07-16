# Standard SWIG Templates


## How to use the template

### Step 1 - 

Change the Name of the Module in `router.i`.

```
%module example_name

```

### Step 2 - 

Implement complete interface for the `router.h`. Please note that you need to create implementation methods for all class constructors and methods or else you will have a `Segmentation Fault (core dumped)` error because the python runtime would not be able to figure out where the methods pointers lead to.


### Step 3 -

Run the one of the build options


### Step 3A - `makefile` + DistUtils compilation. 

This option will let you compile everything using distutils and take care of the python library hunting, all you need to do is change the follwowing variables in the script:

Make sure the extehnsion name is correct 
```
router_module = Extension('_example_router_lib_name', sources = ['router_wrap.cxx', 'router.cpp'])
```

Make sure the module description is correct
```
setup( name = 'example_router_lib_name',
        version = '0.1',
        author = 'whoever you are ',
        description = """Example Library Wrapper Wrapper""",
        ext_modules = [router_module],
        py_modules = ["example_router_lib_name"],
        )
```

### Step 3B - CMake compilation

This option will use CMake, its important that you understand how cmake works so that you can link all the correct libraries together. It will require you configure less files but you need to make sure that the 1 `CMakeLists.txt` is modified correctly.


