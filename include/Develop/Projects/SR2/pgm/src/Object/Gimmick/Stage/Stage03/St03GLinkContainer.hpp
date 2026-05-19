#ifndef ST03GLINKCONTAINER_HPP
#define ST03GLINKCONTAINER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsSe3DControl;
class clsPlayerTask;

// total size: 0xF0
class clsGLinkContainer_Object : public clsBaseGravityLinkObject {
public:
    inline clsGLinkContainer_Object() : clsBaseGravityLinkObject() {}
    virtual ~clsGLinkContainer_Object() {}

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

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void draw(NNS_OBJECT* psObject,
                      f32 (*psMtxPal)[4][4],
                      u32* psNodeStat,
                      const f32 (*opaNnViewMtx)[4][4],
                      f32 (*psMtxWork)[4][4],
                      u32 u32ViewNo);
    virtual void requestDrawBreakEffect();
    virtual void drawEffect(clsPlayerTask* pcPlayer);
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const;
};

// total size: 0x98
class clsGLinkContainer_Task : public clsSingleModelGimmick_Task<clsGLinkContainer_Task,
                                                                 clsGLinkContainer_Object,
                                                                 clsModelType_OB_TX> {
public:
    clsGLinkContainer_Task(u32 u32ObjectAreaNum);
    virtual ~clsGLinkContainer_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    hkShape* m_pcPartsShape; // offset 0x94, size 0x4
};

#endif // ST03GLINKCONTAINER_HPP
