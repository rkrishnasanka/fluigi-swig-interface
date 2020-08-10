#!/usr/bin/env python

from distutils.core import setup, Extension

place_and_route_module = Extension('_place_and_route', sources = ['place_and_route_wrap.cxx', 'placer.cpp', 'router.cpp'])

setup( name = 'place_and_route',
        version = '0.1',
        author = 'krishna',
        description = """Place and Route Wrapper""",
        ext_modules = [place_and_route_module],
        py_modules = ["place_and_route"],
        )