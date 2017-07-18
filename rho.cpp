/* specializer.pyx for special fsts
 Shiran Dudy <dudy@ohsu.edu> and Steven Bedrick <bedricks@ohsu.edu>
 July 2017 */

#include "rho.h"


DEFINE_int64(rho_fst_rho_label, 0,
             "Label of transitions to be interpreted as rho ('rest') "
              "transitions");
DEFINE_string(rho_fst_rewrite_mode, "auto",
              "Rewrite both sides when matching? One of:"
              " \"auto\" (rewrite iff acceptor), \"always\", \"never\"");
const char fst::rho_fst_type[] = "rho";

Rho::Rho(fst::shared_ptr<FstClass> _fst, int rho_fst_rho_label, string rho_fst_rewrite_mode) {
  someFst = _fst;
  outFst = _fst;
  label = rho_fst_rho_label;

  auto data = std::make_shared<RhoFstMatcherData<int>>(label);
  const ConstFst<StdArc> ifst2(*someFst->GetFst<StdArc>());
  auto add_on = std::make_shared<AddOnPair<RhoFstMatcherData<int>,RhoFstMatcherData<int>>>(data, data);
  StdRhoFst rho_match = StdRhoFst(ifst2, add_on);
  FstClass *ifst3 = new FstClass(rho_match);
  fst::shared_ptr<FstClass> converted_to_rho(std::move(ifst3));
  outFst = converted_to_rho;
}

fst::shared_ptr<FstClass> Rho::tofst() {
  return outFst;
}

