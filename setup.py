#!/usr/bin/env python

from distutils.core import setup, Extension

router_module = Extension('_aarf', sources = ['router_wrap.cxx', 'router.cpp'])

setup( name = 'aarf',
        version = '0.1',
        author = 'krishna',
        description = """AARF Wrapper""",
        ext_modules = [router_module],
        py_modules = ["aarf"],
        )