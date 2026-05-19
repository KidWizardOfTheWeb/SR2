#ifndef THROUGHCOLLISION_HPP
#define THROUGHCOLLISION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/BaseThroughCollision.hpp"

struct stcInfo;

// total size: 0x14
class clsThroughCollision : public clsBaseThroughCollision {
public:
    virtual ~clsThroughCollision() {}
    virtual enmType getObjectType() const { return TYPE_THROUGH; }

    void setData(const void* pvData);

    stcInfo* m_psInfo;   // offset 0x8, size 0x4
    u8 m_au8BackUpNo[8]; // offset 0xC, size 0x8
};

#endif // THROUGHCOLLISION_HPP
