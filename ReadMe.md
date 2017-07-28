# specializer

This repo provides an easy interface for the **Special** OpenFst operations through Python.

In addition to using Pywrapfst library that allows interacting with OpenFst, once compiled **specializer** library allows converting Vector type Fsts to *sigma*, *rho*, or *phi* fst types (as described in the [OpenFST documentation](http://www.openfst.org/twiki/bin/view/FST/FstAdvancedUsage#Matchers)).

The library is written in Cython for speedup and direct API of the C++ code of OpenFst.
In order to compile it, the following files are required to be present in the directory:

* `ios.pxd`
* `memory.pxd`
* `basictypes.pxd`
* `pywrapfst.pxd`
* `pywrapfst.pyx`
* `fst.pxd`
* `fst_util.pxd`

These files can be found in the `src/extensions/python/` directory of the OpenFST source distribution.

Additionally, the following files must be on your `LD_LIBRARY_PATH` both when you _compile_ this library and also when you attempt to _use_ it:

* `sigma-fst.so`, `rho-fst.so`, `phi-fst.so`

These files will likely be in `/usr/local/lib/fst` on Linux or OSX. If they are not present on your installation of OpenFST, you may need to recompile OpenFST with the `--enable-special` option.

To compile:

Ensure that setup.py has the required fields.

Run `python setup.py build_ext --inplace`

To unittest:

Go to unitTest folder and Ensure pywrapfst is installed

Run `./test_specializer.sh`
