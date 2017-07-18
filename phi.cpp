/* specializer.pyx for special fsts
 Shiran Dudy <dudy@ohsu.edu> and Steven Bedrick <bedricks@ohsu.edu>
 July 2017 */

#include "phi.h"

DEFINE_int64(phi_fst_phi_label, 0,
             "Label of transitions to be interpreted as phi ('any') "
              "transitions");
DEFINE_string(phi_fst_rewrite_mode, "auto",
              "Rewrite both sides when matching? One of:"
              " \"auto\" (rewrite iff acceptor), \"always\", \"never\"");
DEFINE_bool(phi_fst_phi_loop, true,
            "When true, a phi self loop consumes a symbol");
const char fst::phi_fst_type[] = "phi";

Phi::Phi(fst::shared_ptr<FstClass> _fst, int phi_fst_phi_label, string phi_fst_rewrite_mode, bool phi_fst_phi_loop) {
  someFst = _fst;
  outFst = _fst;
  label = phi_fst_phi_label;

  auto data = std::make_shared<PhiFstMatcherData<int>>(label);
  const ConstFst<StdArc> ifst2(*someFst->GetFst<StdArc>());
  auto add_on = std::make_shared<AddOnPair<PhiFstMatcherData<int>,PhiFstMatcherData<int>>>(data, data);
  StdPhiFst phi_match = StdPhiFst(ifst2, add_on);
  FstClass *ifst3 = new FstClass(phi_match);
  fst::shared_ptr<FstClass> converted_to_phi(std::move(ifst3));
  outFst = converted_to_phi;
}

fst::shared_ptr<FstClass> Phi::tofst() {
  return outFst;
}

