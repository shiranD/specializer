# specializer.pyx for special fsts
# Shiran Dudy <dudy@ohsu.edu> and Steven Bedrick <bedricks@ohsu.edu>
# July 2017

cimport pywrapfst # this and the next cimport require that the .pxd files from pywrapfst be present
cimport fst as fst
cimport memory as memory # so we can have shared_ptr
from libcpp.string cimport string

cdef extern from "sigma.h":
  cdef cppclass Sigma:
    Sigma(memory.shared_ptr[fst.FstClass], int, string) except +
    memory.shared_ptr[fst.FstClass] tofst() 
    
cdef extern from "rho.h":
  cdef cppclass Rho:
    Rho(memory.shared_ptr[fst.FstClass], int, string) except +
    memory.shared_ptr[fst.FstClass] tofst() 

cdef extern from "phi.h":
  cdef cppclass Phi:
    Phi(memory.shared_ptr[fst.FstClass], int, string, bool) except +
    memory.shared_ptr[fst.FstClass] tofst() 

cdef class sigma:

  cdef pywrapfst._Fst myLocalFst

  def __init__(self, someFst, label, rewrite_mode):
    
    ptrFst = (<pywrapfst._Fst>someFst)._fst
    converted = new Sigma(ptrFst, label, rewrite_mode)
    output = converted.tofst()
    cdef pywrapfst._MutableFst outFst = pywrapfst._MutableFst.__new__(pywrapfst._MutableFst)
    outFst._fst.reset(output.get())
    self.myLocalFst = outFst
 
  def get(self):
    return self.myLocalFst


cdef class rho:

  cdef pywrapfst._Fst myLocalFst

  def __init__(self, someFst, label, rewrite_mode):
    
    ptrFst = (<pywrapfst._Fst>someFst)._fst
    converted = new Rho(ptrFst, label, rewrite_mode)
    output = converted.tofst()
    cdef pywrapfst._MutableFst outFst = pywrapfst._MutableFst.__new__(pywrapfst._MutableFst)
    outFst._fst.reset(output.get())
    self.myLocalFst = outFst 

  def get(self):
    return self.myLocalFst


cdef class phi:

  cdef pywrapfst._Fst myLocalFst

  def __init__(self, someFst, label, rewrite_mode, self_loop):
    
    ptrFst = (<pywrapfst._Fst>someFst)._fst
    converted = new Phi(ptrFst, label, rewrite_mode, self_loop)
    output = converted.tofst()
    cdef pywrapfst._MutableFst outFst = pywrapfst._MutableFst.__new__(pywrapfst._MutableFst)
    outFst._fst.reset(output.get())
    self.myLocalFst = outFst 

  def get(self):
    return self.myLocalFst
