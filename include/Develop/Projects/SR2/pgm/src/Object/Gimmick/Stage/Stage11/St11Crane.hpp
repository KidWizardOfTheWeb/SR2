#ifndef ST11CRANE_HPP
#define ST11CRANE_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/PhantomGimmickObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "types.h"

class clsCrane;
class clsPendulumControl;
class clsPlaySe_2D;
class clsPlayerTask;
class hkContactPoint;
class clsObject;

// total size: 0x80
class clsCrane_Obj : public clsPhantomGimmickObject {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    clsCrane_Obj() {}
    virtual ~clsCrane_Obj() {}
    virtual void contactTriggerEvent(hkContactPoint* pcObject, clsObject* pParam2);
    virtual void createData();
    virtual void destroyData();
    virtual nspPackId::enm getPackId() const { return nspPackId::ST11_CRANE_21040; }

    enmMode m_eMode;                                  // offset 0x60, size 0x4
    clsGimmickAutoRunBuffer<clsCrane> m_cCraneBuffer; // offset 0x64, size 0x1C
};

class clsCrane : public clsGimmickAutoRunObj {
public:
    enum enmMoveMode {
        MOVEMODE_FOLLOW = 0,
        MOVEMODE_MAIN = 1,
        MOVEMODE_END = 2,
    };

    clsCrane();
    virtual ~clsCrane();
    inline void setMoveMode(enmMoveMode param) { m_eMoveMode = param; }
    inline enmMoveMode getMoveMode() const { return m_eMoveMode; }
    inline void destroy() {}
    static void start(clsPlayerTask* pcPlayerTask, clsCrane_Obj* pcObj);
    virtual void execute();
    virtual u8 draw(clsModelType_OB_TX& rcModel,
                    f32 (*psMtxPal)[4][4],
                    u32* psNodeStat,
                    const f32 (*opaNnViewMtx)[4][4],
                    f32 (*psMtxWork)[4][4],
                    u32 u32ViewNo,
                    u32 NodeStatus);

    static f32 m_tof32CLIP_DISTx2;

private:
    enum enmMode m_eMode;                    // offset 0x1C0, size 0x4
    enum enmMoveMode m_eMoveMode;            // offset 0x1C4, size 0x4
    clsCrane_Obj* m_pcCraneObj;              // offset 0x1C8, size 0x4
    f32 m_f32InterpolateFrame;               // offset 0x1CC, size 0x4
    f32 m_f32EffectFrame;                    // offset 0x1D0, size 0x4
    clsPendulumControl* m_pcPendulumControl; // offset 0x1D4, size 0x4
    u8 m_bIsCatch;                           // offset 0x1D8, size 0x1
    clsPlaySe_2D* m_pcPlaySe2D;              // offset 0x1DC, size 0x4
};

// total size: 0x98
class clsCrane_Task
    : public clsSingleModelGimmick_Task<clsCrane_Task, clsCrane_Obj, clsModelType_OB_TX> {
public:
    clsCrane_Task(u32 u32ObjectAreaNum)
        : clsSingleModelGimmick_Task<clsCrane_Task, clsCrane_Obj, clsModelType_OB_TX>(
              u32ObjectAreaNum, 0x18703)
    {
    }
    virtual ~clsCrane_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif
