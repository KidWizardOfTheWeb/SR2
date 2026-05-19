#ifndef WALLGIMMICK_HPP
#define WALLGIMMICK_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "types.h"

class hkShape;

// total size: 0x140
class clsWallGimmick_Obj : public clsRigidBodyGimmickObj {
    // Members
public:
    NNS_VECTORFAST m_sUpVecFast; // offset 0xD0, size 0x10
    hkShape* m_pcShape;          // offset 0xE0, size 0x4
    u32 m_u32Num;                // offset 0xE4, size 0x4
    f32 m_f32FrameScale;         // offset 0xE8, size 0x4
    f32 m_sDrawClipMtx[4][4];    // offset 0xF0, size 0x40
    u32 m_u32NotDrawFlag;        // offset 0x130, size 0x4

    // Static members
public:
    static f32 atof32ClipSqDist[17];

    // Weak/inline functions
public:
    inline clsWallGimmick_Obj() {}
    virtual ~clsWallGimmick_Obj() {}
    u32 getMultiDrawNum() const { return m_u32Num; }
    nspPackId::enm getPackId() const { return nspPackId::WALL_GIMMICK_2170; }

    // Non-weak functions
public:
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void draw(clsModelType_OB_TX& rcObj,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32ViewNo);
    virtual void contactInterraction(clsRigidBodyGimmickObj* pParam1);
};

// total size: 0xA8
class clsWallGimmick_Task : public clsSingleModelGimmick_Task<clsWallGimmick_Task,
                                                              clsWallGimmick_Obj,
                                                              clsModelType_OB_TX> {
public:
    clsWallGimmick_Task(u32 u32ObjectAreaNum);
    virtual ~clsWallGimmick_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // WALLGIMMICK_HPP
