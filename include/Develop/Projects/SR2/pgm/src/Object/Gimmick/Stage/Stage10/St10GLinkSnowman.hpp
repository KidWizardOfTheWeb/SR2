#ifndef ST10GLINKSNOWMAN_HPP
#define ST10GLINKSNOWMAN_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGravityLinkObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"

class clsSe3DControl;
class hkShape;

// total size: 0x130
class clsGLinkSnowman_Object : public clsBaseGravityLinkObject {
public:
    enum enmMode {
        MODE_START = 0,
        MODE_MAIN = 1,
        MODE_WAIT = 2,
    };

    static NNS_VECTOR tosCollisionHalfSizeVec;
    static f32 tof32ClipSqDist;
    static clsGravityGimmickParam t_ocGravityGimmickParam;

    clsGLinkSnowman_Object() {}
    virtual ~clsGLinkSnowman_Object() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::ST10_SNOWMAN_20030; }
    virtual NNS_VECTOR* getCollisionHalfSizeVecPtr() const;
    virtual void setData();
    virtual void createData();
    virtual void destroyData();
    virtual void reset();
    virtual void main();
    virtual void requestDrawContactEffect(const hkContactPoint* pParam1);
    virtual void requestDrawBreakEffect();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
    virtual void drawEffect(clsPlayerTask* pParam1);

    void drawShadow(clsModelType_OB& rParam1);
    void draw(NNS_OBJECT* pParam1,
              f32 (*)[4][4],
              u32* pParam3,
              const f32 (*)[4][4],
              f32 (*)[4][4],
              u32 u32Param6);

    enmMode m_eMode;                 // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0xE4, size 0x4
    u8 bDrawFlag;                    // offset 0xE8, size 0x1
    // gap 0xE9–0xEF (alignment padding)
    f32 m_sShadowMtx[4][4]; // offset 0xF0, size 0x40
};

// total size: 0xA0
class clsGLinkSnowman_Task : public clsSingleModelGimmick_Task<clsGLinkSnowman_Task,
                                                               clsGLinkSnowman_Object,
                                                               clsModelType_OB_TX> {
public:
    clsGLinkSnowman_Task(u32 u32ObjectAreaNum);
    virtual ~clsGLinkSnowman_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    void setShadowModel(const u8* rsBinInfoI);

    hkShape* m_pcPartsShape;  // offset 0x94, size 0x4
    u8 m_bFlag;               // offset 0x98, size 0x1
    clsModelType_OB m_cModel; // offset 0x9C, size 0x4
};

#endif // ST10GLINKSNOWMAN_HPP
