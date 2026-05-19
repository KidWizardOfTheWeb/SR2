#ifndef ST12GLINKBRIDGE_HPP
#define ST12GLINKBRIDGE_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsSe3DControl;

// total size: 0x130
class clsGLinkBridge_Object : public clsBaseGravityLinkObject {
public:
    // Note: enmMode name collision with Game.hpp — nested per scaffold rule
    // Values from DWARF for clsGLinkBridge_Object
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsGLinkBridge_Object() {}
    virtual ~clsGLinkBridge_Object() {}
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const
    {
        return nspPackId::ST02_KUKI_12020;
    } // likely: return 12020; [ASM-derived guess — verify]
    virtual void reset();
    virtual void main();

    void requestDrawContactEffect(const hkContactPoint* pcContact);
    void drawEffect(clsPlayerTask* pcPlayer);
    void callbackGravityEvent();
    void requestDrawBreakEffect();
    void draw(NNS_OBJECT* psObject,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              u32 u32ViewNo);

    NNS_VECTOR* getCollisionHalfSizeVecPtr() const { return &tosCollisionHalfSizeVec; } // [verify]

    enum enmMode m_eMode;            // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4
    u32 m_u32Attr;                   // offset 0xE8, size 0x4
    f32 m_sEffectMartix[4][4];       // offset 0xF0, size 0x40

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

// total size: 0x98
class clsGLinkBridge_Task : public clsSingleModelGimmick_Task<clsGLinkBridge_Task,
                                                              clsGLinkBridge_Object,
                                                              clsModelType_OB_TX> {
public:
    clsGLinkBridge_Task(u32 u32ObjectAreaNum);
    virtual ~clsGLinkBridge_Task() {}

    virtual void execute();
    virtual void draw();

    hkShape* m_pcPartsShape; // offset 0x94, size 0x4
};

#endif // ST12GLINKBRIDGE_HPP
