from python_c_api import *

def test_return_int():
    i = return_int()
    assert i == 2

def test_return_dict():
    assert return_dict() == {'a': 1, 'b': 2, 'c': 3, 'd': 4}

def test_return_mixed_dict():
    assert return_mixed_dict() == {
        'str': 'Hello world!', 
        'int': 123, 
        'double': 1.23, 
        'dict': {'a': 1, 'b': 2, 'c': 3, 'd': 4}
        }
