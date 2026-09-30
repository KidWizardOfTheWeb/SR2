#ifndef MULTISHAPE_HPP
#define MULTISHAPE_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

#include "usr/local/sce/ee/gcc/ee/lib/libc/memcmp.h"

class hkShape;

// total size: 0xC
class clsMultiShape {
public:
    // total size: 0x10
    struct stcShapeInfo {
        NNS_VECTOR sScaleVec; // offset 0x0, size 0xC
        hkShape* pcShape;     // offset 0xC, size 0x4
    };

    struct isShapeInfoComp {
        static const NNS_VECTOR* t_psCompScale;

        isShapeInfoComp() {}
        ~isShapeInfoComp() {}

        bool operator()(const stcShapeInfo& shapeInfo) const
        {
            return !memcmp(&shapeInfo.sScaleVec, t_psCompScale, sizeof(NNS_VECTOR));
        }
    };

    typedef std::vector<stcShapeInfo, std::allocator<stcShapeInfo> > ShapeInfoVector;

    clsMultiShape() {}
    explicit clsMultiShape(u32 u32Num) { m_vecShpeInfo.reserve(u32Num); }
    ~clsMultiShape()
    {
        ShapeInfoVector::iterator first = m_vecShpeInfo.begin();
        ShapeInfoVector::iterator last = m_vecShpeInfo.end();
        while (first != last) {
            delete first->pcShape;
            ++first;
        }
    }

    stcShapeInfo* findMultiShape(const NNS_VECTOR& rsScaleVec);

    ShapeInfoVector m_vecShpeInfo; // offset 0x0, size 0xC
};

#endif // MULTISHAPE_HPP
