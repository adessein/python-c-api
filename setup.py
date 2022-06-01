from setuptools import setup, Extension

setup(
    name='python_c_api',
    version='1.0',
    description='This package tests the Python/C API',
    ext_modules=[
        Extension('python_c_api', ['return_types.c'])
    ]
)
