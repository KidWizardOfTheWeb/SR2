#ifndef ST07MAPPARTSFLOORGRAVITY_HPP
#define ST07MAPPARTSFLOORGRAVITY_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/MapPartsObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsTask;
class clsSe3DControl;

// total size: 0x170
class clsMapPartsFloorGravity_Object : public clsMapPartsObject {
public:
    inline clsMapPartsFloorGravity_Object() : clsMapPartsObject() {}
    virtual ~clsMapPartsFloorGravity_Object() {}

    u8 m_StateChangeFlag;            // offset 0xE0, size 0x1
    f32 m_sEffectMtx[4][4];          // offset 0xF0, size 0x40
    f32 m_f32EffectCount;            // offset 0x130, size 0x4
    NNS_VECTORFAST m_sPosVec;        // offset 0x140, size 0x10
    NNS_QUATERNION m_sInitRotQuat;   // offset 0x150, size 0x10
    clsTask* m_pcEffectTask;         // offset 0x160, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0x164, size 0x4
    clsTask* m_psParticle;           // offset 0x168, size 0x4
    f32 m_f32SeDelayFrame;           // offset 0x16C, size 0x4

    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual u8 draw(clsModelType_OB_TX& rcObj,
                    f32 (*psMtxPal)[4][4],
                    u32* psNodeStat,
                    const f32 (*opaNnViewMtx)[4][4],
                    f32 (*psMtxWork)[4][4]);
    virtual void countEffect();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
};

// total size: 0x98
class clsMapPartsFloorGravity_Task
    : public clsSingleModelGimmick_Task<clsMapPartsFloorGravity_Task,
                                        clsMapPartsFloorGravity_Object,
                                        clsModelType_OB_TX> {
public:
    clsMapPartsFloorGravity_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsFloorGravity_Task() {}

    static NNS_VECTOR tosCollisionHalfSizeVec;

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST07MAPPARTSFLOORGRAVITY_HPP
