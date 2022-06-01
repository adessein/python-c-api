# Writing C extensions for Python
This module is an example of C extension in Python. It is for education purposes (of myself).


## How to use

 - `return_types.c` has different functions returning different Python data types: int, list, dict, dict containing another dict.
 - `test_return_types.py` is contains unit tests that checks the data received when these C functions are called.
 - `setup.py` defines how the package `python_c_api` should be built, compiling the file `return_types.c`

Execute the following code to compile the C code and execute the unit tests:
```bash
pip install pytest
pip install -e .
pytest -v
```

## Miscellaneous

The file `python-c-boilerplate.code-snippets` is a code snippet for Visual Studio Code that provides the template for C/Python API interface boilerplate code.
