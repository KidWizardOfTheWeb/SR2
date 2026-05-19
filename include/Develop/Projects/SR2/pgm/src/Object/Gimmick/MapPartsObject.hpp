#ifndef MAPPARTSOBJECT_HPP
#define MAPPARTSOBJECT_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"

class hkShape;

// total size: 0xE0
class clsMapPartsObject : public clsRigidBodyGimmickObj {
public:
    stcInfo m_sColInfo; // offset 0xD0, size 0x10

    clsMapPartsObject();
    virtual ~clsMapPartsObject();

    void setData();
    void createBaseMapParts(hkShape* pcShape, f32 f32Weight);
};

#endif // MAPPARTSOBJECT_HPP
