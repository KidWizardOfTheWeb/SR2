#ifndef ST07MAPPARTSFLOORGLINK_HPP
#define ST07MAPPARTSFLOORGLINK_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPlayerTask;
class clsSe3DControl;
class hkShape;

// total size: 0x170
class clsMapPartsFloorGLink_Object : public clsBaseGravityLinkObject {
public:
    clsMapPartsFloorGLink_Object() {}
    virtual ~clsMapPartsFloorGLink_Object() {}

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void requestDrawContactEffect(const hkContactPoint* pcContact);
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void drawEffect(clsPlayerTask* pcPlayer);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const { return &tosCollisionHalfSizeVec; }

    void draw(NNS_OBJECT* psObject,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    stcInfo m_sColInfo;              // offset 0xE0, size 0x10
    u8 m_StateChangeFlag;            // offset 0xF0, size 0x1
    f32 m_sEffectMtx[4][4];          // offset 0x100, size 0x40
    f32 m_f32EffectCount;            // offset 0x140, size 0x4
    NNS_VECTORFAST m_sPosVec;        // offset 0x150, size 0x10
    clsSe3DControl* m_pcSe3DControl; // offset 0x160, size 0x4
    f32 m_f32SeDelayFrame;           // offset 0x164, size 0x4

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

// total size: 0x98
class clsMapPartsFloorGLink_Task : public clsSingleModelGimmick_Task<clsMapPartsFloorGLink_Task,
                                                                     clsMapPartsFloorGLink_Object,
                                                                     clsModelType_OB_TX> {
public:
    clsMapPartsFloorGLink_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsFloorGLink_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    hkShape* m_pcPartsShape; // offset 0x94, size 0x4
};

#endif // ST07MAPPARTSFLOORGLINK_HPP
