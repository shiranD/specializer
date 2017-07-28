import pywrapfst as fst
import sys

sys.path.insert(0, "../")
import specializer

one = fst.Fst.read("one.fst")
sigfst = fst.Fst.read("sigma.fst")
sigout = fst.Fst.read("sigout.fst")
rhofst = fst.Fst.read("rho.fst")
rhoout = fst.Fst.read("rhoout.fst")
phifst = fst.Fst.read("phi.fst")
phiout = fst.Fst.read("phiout.fst")


sigma_label = 5
rho_label = 6
phi_label = 7

rewrite_mode ="always"

phi_self_loop = True

sigfst = specializer.sigma(sigfst, sigma_label, rewrite_mode).get()
rhofst = specializer.rho(rhofst, rho_label, rewrite_mode).get()
phifst = specializer.phi(phifst, phi_label, rewrite_mode, phi_self_loop).get()

print "Orignial Fst"
print one
print "intersection with the sigma machine"
print fst.intersect(sigfst, one)
print fst.equal(fst.intersect(sigfst, one), sigout)
print "intersection with the rho machine"
print fst.intersect(rhofst, one)
print fst.equal(fst.intersect(rhofst, one), rhoout)
print "intersection with the phi machine"
print fst.intersect(phifst, one)
print fst.equal(fst.intersect(phifst, one), phiout)
