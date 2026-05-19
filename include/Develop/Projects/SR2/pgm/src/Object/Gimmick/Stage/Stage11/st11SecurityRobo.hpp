#ifndef ST11SECURITYROBO_HPP
#define ST11SECURITYROBO_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"

class clsSt11SecurityRoboModels;
class clsModelType_OB_TX_MO;

enum enmMotionMode {
    MOTIONMDOE_NORMAL = 0,
    MOTIONMODE_CONVERT = 1,
    MOTIONMDOE_BALL = 2,
    MOTIONMDOE_END = 3,
};

enum enmPathSide {
    RIGHT_PATH = 0,
    LEFT_PATH = 1,
};

// total size: 0x310
class clsPathSecurityRobo_Obj : public clsRigidBodyGimmickObj {
public:
    enum enmPathSecurityRoboMode {
        MODE_INIT = 0,
        MODE_SLEEP = 1,
        MODE_STARTWAIT = 2,
        MODE_MAIN = 3,
        MODE_WAIT = 4,
    };

    enum enmAiMode {
        AIMODE_MOVE = 0,
        AIMODE_TURN = 1,
        AIMODE_GOES = 2,
        AIMODE_RETURN_PATH = 3,
        AIMODE_RETURN = 4,
        AIMODE_SLEEP = 5,
    };

    enmPathSecurityRoboMode m_eProductionRoboMode; // offset 0xD0, size 0x4
    enmAiMode m_eAiMode;                           // offset 0xD4, size 0x4
    enmMotionMode m_eMotionMode;                   // offset 0xD8, size 0x4
    clsGimmickPath m_cGimmickPath;                 // offset 0xE0, size 0x190
    NNS_VECTORFAST m_sStopPosVecFast;              // offset 0x270, size 0x10
    NNS_VECTORFAST m_sVelocityFast;                // offset 0x280, size 0x10
    clsPlayerTask* m_pcPlayerTask;                 // offset 0x290, size 0x4
    f32 m_f32AddFrame;                             // offset 0x294, size 0x4
    f32 m_f32MotionFrame;                          // offset 0x298, size 0x4
    clsSe3DControl* m_pcSe3DControl;               // offset 0x29C, size 0x4
    f32 m_f32WaitFrame;                            // offset 0x2A0, size 0x4
    f32 m_f32RotCounter;                           // offset 0x2A4, size 0x4
    f32 m_f32RotZ;                                 // offset 0x2A8, size 0x4
    u32 m_u32FrameCounter;                         // offset 0x2AC, size 0x4
    f32 m_sDrawMtx[4][4];                          // offset 0x2B0, size 0x40
    clsBackLineEffectTask* m_apcLineTask[2];       // offset 0x2F0, size 0x8
    u8 m_bIsBackLine;                              // offset 0x2F8, size 0x1
    enmPathSide m_ePathSide;                       // offset 0x2FC, size 0x4
    u8 m_bPlayerLock;                              // offset 0x300, size 0x1
    u8 m_u8ContactSeCount;                         // offset 0x301, size 0x1

    clsPathSecurityRobo_Obj() {}
    virtual ~clsPathSecurityRobo_Obj() {}
    virtual void init() {}
    virtual nspPackId::enm getPackId() const { return nspPackId::ST01_PRODUCTION_ROBO_11050; }
    virtual void contactTriggerEvent(hkContactPoint* pcContact, clsObject* pcObject);
    virtual void callbackGravityEvent();
    virtual void requestDrawBreakEffect();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& cEvent);

    void setAiMode(enmAiMode param_1) { m_eAiMode = param_1; }
    void setMode(enmPathSecurityRoboMode param_1) { m_eProductionRoboMode = param_1; }
    enmAiMode getAiMode() const { return m_eAiMode; }
    void clearVelocity();
    void rotationAxisZ();
    void setLineParam(struct NNS_OBJECT* param_1, struct NNS_MOTION* param_2, f32* param_3);
    void setLinearVelocity(const struct NNS_VECTORFAST& param_1, f32 param_2);
    void updatePostural();
    void chageLineParam(clsModelType_OB_TX_MO& param_1);
    void getDirPlayerStart(struct NNS_VECTORFAST& param_1);
    void resetLine();

    void draw(clsSt11SecurityRoboModels* pcModels,
              f32 (*psMtxPal)[4][4],
              u32* psNodeStat,
              const f32 (*opaNnViewMtx)[4][4],
              f32 (*psMtxWork)[4][4],
              f32 f32Param);
    void main();
    void callbackContactTriggerRigidBody_helper(const hkContactPointConfirmedEvent& param_1);
    void checkPlayerRestart();
    void setSurfaceDir(struct NNS_VECTORFAST& rsVerocityFast, struct NNS_VECTORFAST& rsDirVecFast);
    void setReturnPath();
    void
    setPosturalCtrl(const struct NNS_VECTORFAST& rsDirVecFast, f32 f32InterpolateRate, f32 f32RotZ);
    void stepMotionFrame();
    void destroyData();
    void createData();
    void setData();
    void start(clsPlayerTask* pcPlayer);
    void reset();

    static clsGravityGimmickParam t_ocGravityGimmickParam;
};

#endif // ST11SECURITYROBO_HPP
