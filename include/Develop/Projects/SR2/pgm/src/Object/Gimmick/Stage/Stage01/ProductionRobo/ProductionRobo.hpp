#ifndef PRODUCTIONROBO_HPP
#define PRODUCTIONROBO_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"

class clsPlayerTask;
class clsSe3DControl;
class clsBackLineEffectTask;
class clsSecurityRoboModels;

// Note: enmMotionMode — name collision with st11SecurityRobo.hpp enmMotionMode (different number of
// values) total size: 0x300
class clsProductionRobo_Obj : public clsRigidBodyGimmickObj {
public:
    enum enmProductionRoboMode {
        MODE_INIT = 0,
        MODE_SLEEP = 1,
        MODE_STARTWAIT = 2,
        MODE_MAIN = 3,
        MODE_WAIT = 4,
    };

    // Note: enmAiMode — name collision with st11SecurityRobo.hpp enmAiMode (different values)
    enum enmAiMode {
        AIMODE_MOVE = 0,
        AIMODE_CONVERT = 1,
        AIMODE_TURN = 2,
        AIMODE_GOES = 3,
        AIMODE_RETURN_PATH = 4,
        AIMODE_RETURN = 5,
        AIMODE_SLEEP = 6,
    };

    enum enmMotionMode {
        MOTIONMDOE_NORMAL = 0,
        MOTIONMODE_CONVERT = 1,
        MOTIONMDOE_BALL = 2,
    };

    static u32 otau32Se_AirCarL[2];
    static u32 otau32Se_SirenL[2];

    enmProductionRoboMode m_eProductionRoboMode; // offset 0xD0, size 0x4
    enmAiMode m_eAiMode;                         // offset 0xD4, size 0x4
    enmMotionMode m_eMotionMode;                 // offset 0xD8, size 0x4
    clsGimmickPath m_cGimmickPath;               // offset 0xE0, size 0x190
    NNS_VECTORFAST m_sStopPosVecFast;            // offset 0x270, size 0x10
    NNS_VECTORFAST m_sVelocityFast;              // offset 0x280, size 0x10
    clsPlayerTask* m_pcPlayerTask;               // offset 0x290, size 0x4
    f32 m_f32AddFrame;                           // offset 0x294, size 0x4
    f32 m_f32MotionFrame;                        // offset 0x298, size 0x4
    clsSe3DControl* m_pcSe3DControl;             // offset 0x29C, size 0x4
    f32 m_f32WaitFrame;                          // offset 0x2A0, size 0x4
    f32 m_f32RotCounter;                         // offset 0x2A4, size 0x4
    f32 m_f32RotZ;                               // offset 0x2A8, size 0x4
    f32 m_f32EffectFrame;                        // offset 0x2AC, size 0x4
    f32 m_sDrawMtx[4][4];                        // offset 0x2B0, size 0x40
    clsBackLineEffectTask* m_apcLineTask[2];     // offset 0x2F0, size 0x8

    clsProductionRobo_Obj();
    virtual ~clsProductionRobo_Obj();
    virtual void contactTriggerEvent(hkContactPoint* p1, clsObject* p2);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST01_PRODUCTION_ROBO_11050; }
    virtual void reset();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();

    void draw(clsSecurityRoboModels* p1,
              f32 (*p2)[4][4],
              u32* p3,
              const f32 (*p4)[4][4],
              f32 (*p5)[4][4],
              f32 p6);
    void checkPlayerRestart();
    void setSurfaceDir(NNS_VECTORFAST& p1, NNS_VECTORFAST& p2);
    void setReturnPath();
    void setPosturalCtrl(const NNS_VECTORFAST& p1, f32 p2, f32 p3);
    void stepMotionFrame();
    void start(clsPlayerTask* p1);
    void setLineParam(NNS_OBJECT* p1, NNS_MOTION* p2, f32* p3);

    void init() {}
    void setMode(enmProductionRoboMode param_1) { m_eProductionRoboMode = param_1; }
    void clearVelocity() {}
    void rotationAxisZ() {}
    void setLinearVelocity(const NNS_VECTORFAST& p1, f32 p2) {}
    void getDirPlayerStart(NNS_VECTORFAST& p1) {}
    void updatePostural() {}
    void getDirPlayer(NNS_VECTORFAST& p1) {}
    void setAiMode(enmAiMode param_1) { m_eAiMode = param_1; }
    enmAiMode getAiMode() const { return m_eAiMode; }
};

#endif // PRODUCTIONROBO_HPP
