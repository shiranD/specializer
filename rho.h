#include <memory>
#include <fst/script/fstscript.h>
#include <fst/extensions/special/rho-fst.h>
#include <string.h>

using fst::script::FstClass;
using fst::internal::RhoFstMatcherData;
using fst::ConstFst;
using fst::StdArc;
using fst::AddOnPair;
using fst::StdRhoFst;

class Rho {

  public:

    Rho(fst::shared_ptr<FstClass> _fst, int rho_fst_sigma_label, string rho_fst_rewrite_mode);
    ~Rho();
    fst::shared_ptr<FstClass> someFst;
    fst::shared_ptr<FstClass> outFst;
    int label;
    fst::shared_ptr<FstClass> tofst();

};
