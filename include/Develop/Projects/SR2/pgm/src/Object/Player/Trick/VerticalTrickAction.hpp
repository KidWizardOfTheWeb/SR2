#ifndef VERTICALTRICKACTION_HPP
#define VERTICALTRICKACTION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/BaseTrickAction.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0x30
class clsVerticalTrickAction : public clsBaseTrickAction {
public:
    virtual ~clsVerticalTrickAction() {}
    virtual void init(clsTrickParam& rcParam);
    virtual void execute(clsTrickParam& rcParam);

    NNS_VECTORFAST m_sUpVecFast; // offset 0x10, size 0x10
    f32 m_f32UpAccele;           // offset 0x20, size 0x4
};

#endif // VERTICALTRICKACTION_HPP
