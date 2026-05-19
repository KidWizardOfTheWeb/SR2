#ifndef ST16GLINKSIGNBOARD_HPP
#define ST16GLINKSIGNBOARD_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage16/St16BreakSignBoard.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSe3DControl;
class clsPlayerTask;

// total size: 0xF0
class clsGLinkSignBoard_Obj : public clsBaseGravityLinkObject {
public:
    inline clsGLinkSignBoard_Obj() : clsBaseGravityLinkObject() {}
    virtual ~clsGLinkSignBoard_Obj() {}

    enum enmMode {
        MODE_INIT = 0,
        MODE_WAIT = 1,
        MODE_RISE = 2,
        MODE_FLOAT = 3,
        MODE_MOVE_INIT = 4,
        MODE_MOVE = 5,
        MODE_END = 6,
    }; // Note: name collision with Game.hpp enmMode

    enmMode m_eMode;                 // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4
    u8 m_bUra;                       // offset 0xE8, size 0x1

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    virtual void reset();
    virtual void requestDrawBreakEffect();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
    virtual void drawEffect(clsPlayerTask* pcPlayer);
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void main();
    virtual void draw(clsModelType_OB_TX* apcModel,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32ViewNo);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const;
    inline nspPackId::enm getPackId() const { return nspPackId::ST16_GLINK_SIGNBOARD_26010; }
};

// total size: 0x98
class clsGLinkSignBoard_Task : public clsMultiModelGimmick_Task<clsGLinkSignBoard_Task,
                                                                clsGLinkSignBoard_Obj,
                                                                clsSignBoardModel> {
public:
    clsGLinkSignBoard_Task(u32 u32ObjectAreaNum);
    virtual ~clsGLinkSignBoard_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST16GLINKSIGNBOARD_HPP
