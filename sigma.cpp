/* specializer.pyx for special fsts
 Shiran Dudy <dudy@ohsu.edu> and Steven Bedrick <bedricks@ohsu.edu>
 July 2017 */

#include "sigma.h"

DEFINE_int64(sigma_fst_sigma_label, 0,
             "Label of transitions to be interpreted as sigma ('any') "
              "transitions");
DEFINE_string(sigma_fst_rewrite_mode, "auto",
              "Rewrite both sides when matching? One of:"
              " \"auto\" (rewrite iff acceptor), \"always\", \"never\"");
const char fst::sigma_fst_type[] = "sigma";

Sigma::Sigma(fst::shared_ptr<FstClass> _fst, int sigma_fst_sigma_label, string sigma_fst_rewrite_mode) {
  someFst = _fst;
  outFst = _fst;
  label = sigma_fst_sigma_label;

  auto data = std::make_shared<SigmaFstMatcherData<int>>(label);
  const ConstFst<StdArc> ifst2(*someFst->GetFst<StdArc>());
  auto add_on = std::make_shared<AddOnPair<SigmaFstMatcherData<int>,SigmaFstMatcherData<int>>>(data, data);
  StdSigmaFst sigma_match = StdSigmaFst(ifst2, add_on);
  FstClass *ifst3 = new FstClass(sigma_match);
  fst::shared_ptr<FstClass> converted_to_sigma(std::move(ifst3));
  outFst = converted_to_sigma;
}

fst::shared_ptr<FstClass> Sigma::tofst() {
  return outFst;
}

