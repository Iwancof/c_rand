#include <Python.h>
#include "random.h"

static PyObject *c_rand_srand(PyObject *self, PyObject *args) {
  int seed;
  if (!PyArg_ParseTuple(args, "I", &seed)) {
    return NULL;
  }

  my_srandom(seed); 
  
  Py_RETURN_NONE;
}

static PyObject* c_rand_rand(PyObject *self, PyObject *args) {
  return Py_BuildValue("I", my_random());
}

static PyMethodDef c_rand_methdos[] = {
    {"srand", c_rand_srand, METH_VARARGS, "Set seed for random number generator"},
    {"rand", c_rand_rand, METH_NOARGS, "Get random number"},
    {NULL, NULL, 0, NULL}, /* Sentinel */
};

static struct PyModuleDef c_rand = {
  PyModuleDef_HEAD_INIT,
  "c_rand",
  NULL,
  -1,
  c_rand_methdos,
};

PyMODINIT_FUNC PyInit_c_rand(void) {
  return PyModule_Create(&c_rand);
}


