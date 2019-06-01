#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jun  1 01:09:17 2019

@author: areyes
"""

from distutils.core import setup

setup(
    name = 'toolkit-common',
    packages = ['common'],
    version = '3.7.1',
    description = 'Clases comunes',
    author='Azel Reyes',
    author_email = "azael.devel@gmail.com",
    url = "https://github.com/azaeldevel/toolkit.git",
    download_url = "https://github.com/azaeldevel/toolkit.git",
    keywords = ["encoding", "i18n", "xml"],
    classifiers = [
        "Programming Language :: Python",
        "Programming Language :: Python :: 3",
        "Development Status :: 3 - Beta",
        "Environment :: Other Environment",
        "Intended Audience :: Developers",
        "License :: OSI Approved :: GNU Library or Lesser General Public License (LGPL)",
        "Operating System :: OS Independent",
        "Topic :: Software Development :: Libraries :: Python Modules",
        ],
    long_description = """\
Toolkit Common
-------------------------------------

Clases de proposito general

"""
)