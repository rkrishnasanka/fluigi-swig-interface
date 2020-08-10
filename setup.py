#!/usr/bin/env python

from distutils.core import setup, Extension

router_module = Extension('_placer', sources = ['placer_wrap.cxx', 'placer.cpp'])

setup( name = 'placer',
        version = '0.1',
        author = 'krishna',
        description = """Placer Wrapper""",
        ext_modules = [router_module],
        py_modules = ["placer"],
        )