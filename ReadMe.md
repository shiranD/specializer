# specializer

This repo provides an easy interface for the **Special** OpenFst operations through Python.

In addition to using Pywrapfst library that allows interacting with OpenFst, once compiled **specializer** library allows converting Vector type Fsts to *sigma*, *rho*, or *phi* fst types. 

The library is written in Cython for speedup and direct API of the C++ code of OpenFst.
In order to compile it, the following files are required:
* ios.pxd
* memory.pxd
* basictypes.pxd
* pywrapfst.pxd
* pywrapfst.pyx
* fst.pxd
* fst_util.pxd
* sigma-fst.so, rho-fst.so, phi-fst.so

To complie:

Ensure that setup.py has the required fields.

Run `python setup.py build_ext --inplace`

To unittest:

Go to unitTest folder and Ensure pywrapfst is installed

Run `./test_specializer.sh`
