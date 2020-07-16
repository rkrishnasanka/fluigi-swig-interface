#!/usr/bin/env python

from distutils.core import setup, Extension

aarf_module = Extension('_aarf', sources = ['aarf_wrap.cxx', 'route.cpp', 'router.cpp'])

setup( name = 'aarf',
        version = '0.1',
        author = 'krishna',
        description = """AARF Wrapper""",
        ext_modules = [aarf_module],
        py_modules = ["aarf"],
        )