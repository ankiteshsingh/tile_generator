# ctypes_test.py
import ctypes
import pathlib
from ctypes import *
import numpy as np
from numpy.ctypeslib import ndpointer
import matplotlib.pyplot as plt

if __name__ == "__main__":
    # Load the shared library into ctypes
    libname = pathlib.Path().absolute() / "liboffset.so"
    c_lib = ctypes.CDLL(libname)
    c_lib.get_offset.restype = ndpointer(dtype=ctypes.c_int, shape=(100,100))

    out = c_lib.get_offset(c_int(100),c_int(100),c_int(50),c_int(50),c_int(30));
    plt.imshow(out)
    plt.show()