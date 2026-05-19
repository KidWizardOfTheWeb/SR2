#ifndef ST02PATHBEE_HPP
#define ST02PATHBEE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/ItemBomb.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Bee.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

// total size: 0xB4
class clsPathBee_Obj : public clsRigidBodyGimmickObj, private clsBeeRoboBase_Obj {
public:
    inline clsPathBee_Obj() : clsRigidBodyGimmickObj() {}
    virtual ~clsPathBee_Obj() {}

    enum enmPathBeeMode {
        MODE_INIT = 0,
        MODE_STARTWAIT = 1,
        MODE_MAIN = 2,
        MODE_WAIT = 3,
    };

    enum enmAiMode {
        AIMODE_MOVE = 0,
        AIMODE_APPROACH = 1,
        AIMODE_STOP = 2,
        AIMODE_RETURN_PATH = 3,
        AIMODE_RETURN = 4,
        AIMODE_SLEEP = 5,
    };

    enmPathBeeMode m_ePathBeeMode;    // offset 0xDC, size 0x4
    enmAiMode m_eAiMode;              // offset 0xE0, size 0x4
    clsGimmickPath m_cGimmickPath;    // offset 0xF0, size 0x190
    f32 m_f32SearchFrame;             // offset 0x280, size 0x4
    f32 m_f32SearchIntervalFrame;     // offset 0x284, size 0x4
    clsPlayerTask* m_pcPlayerTask;    // offset 0x288, size 0x4
    NNS_VECTORFAST m_sVelocityFast;   // offset 0x290, size 0x10
    NNS_VECTORFAST m_sStopPosVecFast; // offset 0x2A0, size 0x10
    f32 m_f32TotalFrame;              // offset 0x2B0, size 0x4
    f32 m_f32EventFrame;              // offset 0x2B4, size 0x4
    f32 m_f32StartWaitFrame;          // offset 0x2B8, size 0x4
    clsSe3DControl* m_pcSe3DControl;  // offset 0x2BC, size 0x4

    static f32 m_tof32CLIP_DISTx2;

    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST02_PATH_BEE_12050; }

    virtual void reset();
    virtual void init();
    virtual void main();
    virtual void requestDrawBreakEffect();
    virtual void callbackGravityEvent();
    virtual void callbackContactTriggerRigidBody(const hkContactPointConfirmedEvent& rParam1);
    inline void setMode(enmPathBeeMode) {}
    inline void setAiMode(enmAiMode) {}
    inline enmAiMode getAiMode() const { return AIMODE_MOVE; }
    inline clsPlayerTask* searchPlayer() { return 0; }
    inline void setLinearVelocity(const NNS_VECTORFAST& rParam1, f32 f32Param2) {}
    inline void getDirPlayer(NNS_VECTORFAST& rParam1) {}
    inline void clearVelocity() {}
    inline void updatePostural() {}
    inline void setDescentVelocity(f32 f32Param1) {}
    inline void clearDescentVelocity() {}
    void setPosturalCtrl(const NNS_VECTORFAST& rsDirVecFast, f32 f32InterpolateRate, f32 f32RotZ);
    void setSurfaceDir(NNS_VECTORFAST& rsVerocityFast, NNS_VECTORFAST& rsDirVecFast);
    void setReturnPath();
};

// total size: 0x94
class clsPathBee_Task
    : public clsMultiModelGimmick_Task<clsPathBee_Task, clsPathBee_Obj, clsModelType_OB_TX> {
public:
    clsPathBee_Task(u32 u32Param1);
    virtual ~clsPathBee_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset();

    virtual void createModel(stcBinInfo& rsBinInfo);
};

#endif // ST02PATHBEE_HPP
