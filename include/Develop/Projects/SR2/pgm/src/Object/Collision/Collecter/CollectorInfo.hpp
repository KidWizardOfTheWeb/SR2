#ifndef COLLECTORINFO_HPP
#define COLLECTORINFO_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/hkArray.hpp"

class hkCollidable;
struct hkContactPoint;

// total size: 0x5C
class clsCollectorInfo {
public:
    clsCollectorInfo();
    virtual ~clsCollectorInfo();

    virtual void set(const hkCollidable* pcCollidable, const hkContactPoint& rParam2);
    virtual void updateBegin();
    virtual void updateEnd();
    virtual void clearTriggerData();
    virtual void clear();
    virtual u8 isAddCollector(const hkCollidable* pcCollidable);

    hkArray<void*>* m_apcCollidable[2];  // offset 0x0, size 0x18
    hkArray<void*>* m_cCollidableTrig;   // offset 0x18, size 0xC
    hkArray<void*>* m_cContactTrig;      // offset 0x24, size 0xC
    hkArray<void*>* m_cCollidableAlways; // offset 0x30, size 0xC
    hkArray<void*>* m_cContactAlways;    // offset 0x3C, size 0xC
    hkArray<void*>* m_cCollidableRemove; // offset 0x48, size 0xC
    s32 m_s32CurrentNo;                  // offset 0x54, size 0x4
};

#endif // COLLECTORINFO_HPP
