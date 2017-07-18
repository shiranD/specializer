#include <memory>
#include <fst/script/fstscript.h>
#include <fst/extensions/special/phi-fst.h>
#include <string.h>

using fst::script::FstClass;
using fst::internal::PhiFstMatcherData;
using fst::ConstFst;
using fst::StdArc;
using fst::AddOnPair;
using fst::StdPhiFst;

class Phi {

  public:

    Phi(fst::shared_ptr<FstClass> _fst, int phi_fst_phi_label, string phi_fst_rewrite_mode, bool phi_fst_phi_loop);
    ~Phi();
    fst::shared_ptr<FstClass> someFst;
    fst::shared_ptr<FstClass> outFst;
    int label;
    fst::shared_ptr<FstClass> tofst();

};
