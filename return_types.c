#define PY_SSIZE_T_CLEAN
#include <Python.h>

int return_int(){
   int i = 2;
   return i;
}

int* return_list_int(){
   int list[3] = {1,2,3};
   return &list;
}

static PyObject* return_int_py(PyObject* self, PyObject* args){
    PyObject* result = NULL;
    result = Py_BuildValue("i", return_int());
    return result;
}

static PyObject* return_list_int_py(PyObject* self, PyObject* args){
    int* list = return_list_int();
    int size = sizeof(list) / sizeof(list[0]);
    printf("Size of the array: %d\n", size);
    PyObject* result = PyList_New(size); 
    for (int i = 0; i < size; i++)
    {
        PyObject* val = Py_BuildValue("i", list[i]);
        PyList_SetItem(result, i, val);
    }
    return result;
}

static PyObject* return_dict_py(PyObject* self, PyObject* args){
    PyObject* result = Py_BuildValue(
        "{s:i,s:i,s:i,s:i}", 
        "a", 1,
        "b", 2,
        "c", 3,
        "d", 4);
    return result;
}

static PyObject* return_mixed_dict_py(PyObject* self, PyObject* args){
    PyObject* dict = Py_BuildValue(
        "{s:i,s:i,s:i,s:i}", 
        "a", 1,
        "b", 2,
        "c", 3,
        "d", 4);
    PyObject* result = Py_BuildValue(
        "{s:s,s:i,s:d,s:O}", 
        "str", "Hello world!",
        "int", 123,
        "double", 1.23,
        "dict", dict);
    return result;
}

static char return_int_docs[] = "return_int: Returns an int";
static char return_list_int_docs[] = "return_list_int_py: Returns a list of ints";
static char return_dict_docs[] = "return_dict_py: Returns a dict";
static char return_mixed_dict_docs[] = "return_mixed_dict_py_: Returns a mixed dict";

static PyMethodDef module_methods[] = {
    {"return_int", (PyCFunction)return_int_py, METH_VARARGS, return_int_docs},
    {"return_list_int", (PyCFunction)return_list_int_py, METH_VARARGS, return_list_int_docs},
    {"return_dict", (PyCFunction)return_dict_py, METH_VARARGS, return_dict_docs},
    {"return_mixed_dict", (PyCFunction)return_mixed_dict_py, METH_VARARGS, return_mixed_dict_docs},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module_definition = {
    PyModuleDef_HEAD_INIT,
    "python_c_api: Test module for C/Python API",
    "Tests different types of return types",
    -1,
    module_methods
};

PyMODINIT_FUNC PyInit_python_c_api(void){
    Py_Initialize();
    return PyModule_Create(&module_definition);
}
