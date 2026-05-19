#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/AttrInfo.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/GroundCollision.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/ThroughCollision.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsObject;
class hkCollidable;
struct stcInfo;

// total size: 0x10
struct stcBinHeader {
    enum enmType {
        OBJECT = 0,
        TEXTURE = 1,
        MOTION = 2,
        MATMOTOBJ = 3,
        MORPHOBJ = 4,
        MORPHTARGETLIST = 5,
        MAX = 6,
    };

    u32 u32Version; // offset 0x0, size 0x4
    u32 u32Num;     // offset 0x4, size 0x4
    enmType eType;  // offset 0x8, size 0x4
    u32 u32Padding; // offset 0xC, size 0x4
};

// total size: 0xC4
class clsCollisionManager : public clsSingleton<clsCollisionManager> {
public:
    // total size: 0x30
    struct stcRetRayCast {
    public:
        NNS_VECTORFAST sCrossVecFast;  // offset 0x0, size 0x10
        NNS_VECTORFAST sNormalVecFast; // offset 0x10, size 0x10
        stcInfo* psInfo;               // offset 0x20, size 0x4
        clsObject* pcObject;           // offset 0x24, size 0x4
    };

    clsCollisionManager() {}
    virtual ~clsCollisionManager() {}

    clsGroundCollision* m_pcGroundCollisionList;     // offset 0x4, size 0x4
    clsThroughCollision** m_ppcThroughCollisionList; // offset 0x8, size 0x4
    s32 m_s32GroundNum;                              // offset 0xC, size 0x4
    s32 m_s32ThroughNum;                             // offset 0x10, size 0x4
    stcAttrInfo m_sGroundAttrInfo[21];               // offset 0x14, size 0xA8
    s32 m_s32GroundVertexNum;                        // offset 0xBC, size 0x4
    s32 m_s32GroundPartsNum;                         // offset 0xC0, size 0x4

    inline clsObject* getCollidableObject(const hkCollidable* pcCollidable) const { return 0; }
    void setupBinData(void* pvBuff);
    void registData(const void* pvBuff);
    s8 checkRayCast(stcRetRayCast& rsRetRayCast,
                    NNS_VECTORFAST& rsStartVecFast,
                    NNS_VECTORFAST& rsEndVecFast,
                    u32 u32ColliFilter);
    void destroy();
    void DrawThrough();
};

#endif // COLLISIONMANAGER_HPP
