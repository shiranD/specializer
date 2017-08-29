# specializer.pyx for special fsts
# Shiran Dudy <dudy@ohsu.edu> and Steven Bedrick <bedricks@ohsu.edu>
# July 2017

from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize


extensions = [
        Extension("specializer",
            include_dirs = ["usr/local/include/fst"],
            sources=["specializer.pyx", "sigma.cpp", "rho.cpp", "phi.cpp"],
            libraries = ["fst","fstscript"],
            library_dirs = ["/usr/local/lib", "/usr/local/lib/fst"],
            language="c++",
            extra_compile_args=["-std=c++11"], # this is non-optional...
            extra_link_args=["-std=c++11"]
        )
]

setup(
    name = "CythonTest",
    ext_modules = cythonize(extensions)
)
