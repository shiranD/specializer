#include <memory>
#include <fst/script/fstscript.h>
#include <fst/extensions/special/sigma-fst.h>
#include <string.h>

using fst::script::FstClass;
using fst::internal::SigmaFstMatcherData;
using fst::ConstFst;
using fst::StdArc;
using fst::AddOnPair;
using fst::StdSigmaFst;

class Sigma {

  public:

    Sigma(fst::shared_ptr<FstClass> _fst, int sigma_fst_sigma_label, string sigma_fst_rewrite_mode);
    ~Sigma();
    fst::shared_ptr<FstClass> someFst;
    fst::shared_ptr<FstClass> outFst;
    int label;
    fst::shared_ptr<FstClass> tofst();

};
