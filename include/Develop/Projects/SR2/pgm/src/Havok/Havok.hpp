#ifndef HAVOK_HPP
#define HAVOK_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"

// total size: 0x4
class hkPadSpu {
public:
    void* m_storage; // offset 0x0, size 0x4
};

// total size: 0x0
class hkCollisionListener {};

// total size: 0x10
class hkStepInfo {
public:
    hkPadSpu m_startTime;      // offset 0x0, size 0x4
    hkPadSpu m_endTime;        // offset 0x4, size 0x4
    hkPadSpu m_deltaTime;      // offset 0x8, size 0x4
    hkPadSpu m_invDeltaTime;   // offset 0xC, size 0x4
};

// total size: 0x20
class clsStepInfo : public hkStepInfo {
public:
    hkPadSpu m_invDeltaTimeCaret2; // offset 0x10, size 0x4
};

// Used by hkWorld::updateCollisionFilterOnPhantom
enum hkUpdateCollectionFilterMode {
    HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS = 0,
    HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS = 1,
};

class hkWorldObject {};
class hkPhantom : public hkWorldObject {};
class hkShapePhantom : public hkPhantom {};
class hkSimpleShapePhantom : public hkShapePhantom {};

class hkCharacterProxy {
public:
    hkPhantom* getShapePhantom();
};

class hkWorld {
public:
    void updateCollisionFilterOnPhantom(hkPhantom* phantom, hkUpdateCollectionFilterMode mode);
};

// total size: 0x40
class clsHavok : public clsSingleton<clsHavok> {
public:
    virtual ~clsHavok();                     // vtable at 0x0
    hkWorld*             m_pcWorld;          // offset 0x4, size 0x4
    char*                m_pu8StackBuff;     // offset 0x8, size 0x4
    hkCollisionListener* m_pcRigidListener;  // offset 0xC, size 0x4
    clsStepInfo          m_cStepInfo;        // offset 0x10, size 0x20
    signed int           m_s32ProcNum;       // offset 0x30, size 0x4
};

#endif // HAVOK_HPP
