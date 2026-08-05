#ifndef MULTISHAPE_HPP
#define MULTISHAPE_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

extern "C" int memcmp(const void*, const void*, unsigned int);

class hkShape;

class clsMultiShape {
public:
    struct stcShapeInfo {
        NNS_VECTOR sScaleVec;
        hkShape* pcShape;
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

    stcShapeInfo* findMultiShape(const NNS_VECTOR& rsScaleVec);

    ShapeInfoVector m_vecShpeInfo;
};

#endif // MULTISHAPE_HPP
