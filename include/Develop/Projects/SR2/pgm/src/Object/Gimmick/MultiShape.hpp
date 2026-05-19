#ifndef MULTISHAPE_HPP
#define MULTISHAPE_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class hkShape;

// total size: 0xC
class clsMultiShape {
public:
    // total size: 0x10
    struct stcShapeInfo {
        NNS_VECTOR sScaleVec; // offset 0x0, size 0xC
        hkShape* pcShape;     // offset 0xC, size 0x4
    };

    stcShapeInfo* findMultiShape(const NNS_VECTOR& rsScaleVec);

    vector m_vecShpeInfo; // offset 0x0, size 0xC
};

#endif // MULTISHAPE_HPP
