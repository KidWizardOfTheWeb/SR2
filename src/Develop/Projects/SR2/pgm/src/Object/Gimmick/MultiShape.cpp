#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MultiShape.hpp"

const NNS_VECTOR* clsMultiShape::isShapeInfoComp::t_psCompScale;

clsMultiShape::stcShapeInfo* clsMultiShape::findMultiShape(const NNS_VECTOR& rsScaleVec)
{
    isShapeInfoComp::t_psCompScale = &rsScaleVec;
    isShapeInfoComp comp;
    ShapeInfoVector::iterator it = std::find_if(m_vecShpeInfo.begin(), m_vecShpeInfo.end(), comp);
    stcShapeInfo* shapeInfo = &*it;
    if (it == m_vecShpeInfo.end()) {
        shapeInfo = 0;
    }
    return shapeInfo;
}
