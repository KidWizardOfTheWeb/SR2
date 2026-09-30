#ifndef GRAVITYDIVE_HPP
#define GRAVITYDIVE_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/nn/NNUtil.hpp"
#include "usr/local/sega/nn/src/Matrix/nnmakematrix.h"
#include "Develop/Projects/SR2/pgm/src/Config/nspGDive.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/BaseGravityAction.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/GravityDivePathRange.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Path.hpp"

class clsSimpleShapePhantom;
class clsBaseGravityLinkObject;
class clsTask;

// total size: 0x1D0
class clsGravityDive : public clsBaseGravityAction {
public:
    enum enmType {
        TYPE_RISE = 0,
        TYPE_MOVE = 1,
        TYPE_LINK = 2,
        TYPE_RING = 3,
        TYPE_DASH = 4,
        TYPE_AUTO_RISE = 5,
        TYPE_AUTO_RISE_MOVE = 6,
        TYPE_AUTO_FALL = 7,
        TYPE_AUTO_CANCEL = 8,
    };

    enum enmStatus {
        STATUS_NORMAL = 0,
        STATUS_AUTO = 1,
        STATUS_FALL = 2,
    };

    static f32 t_f32SystemReadyFrame;

    NNS_MATRIX m_sDirMtx;                     // offset 0x20, size 0x40
    NNS_VECTORFAST m_sLocalVecFast;           // offset 0x60, size 0x10
    clsPath m_cPath;                          // offset 0x70, size 0x60
    clsGravityDivePathRange m_cPathRange;     // offset 0xD0, size 0xD0
    clsSimpleShapePhantom* m_pcPhantom;       // offset 0x1A0, size 0x4
    clsBaseGravityLinkObject* m_pcLinkObject; // offset 0x1A4, size 0x4
    clsTask* m_pcDiveHole;                    // offset 0x1A8, size 0x4
    enmType m_eType;                          // offset 0x1AC, size 0x4
    enmStatus m_eStatus;                      // offset 0x1B0, size 0x4
    f32 m_f32Frame;                           // offset 0x1B4, size 0x4
    f32 m_f32AutoDirRate;                     // offset 0x1B8, size 0x4
    u32 m_eControlFlag;                       // offset 0x1BC, size 0x4
    u8 m_bAutoDiveCancel;                     // offset 0x1C0, size 0x1
    f32 m_f32MaxSpeed;                        // offset 0x1C4, size 0x4
    f32 m_f32GDiveTrigConsumption;            // offset 0x1C8, size 0x4
    f32 m_f32GDiveBetaConsumption;            // offset 0x1CC, size 0x4

    clsGravityDive(clsGravityActionManager* pcManager)
        : clsBaseGravityAction(pcManager), m_pcPhantom(NULL), m_pcLinkObject(NULL),
          m_pcDiveHole(NULL), m_eType(TYPE_RISE), m_f32Frame(0.0f), m_eControlFlag(0),
          m_bAutoDiveCancel(0), m_f32MaxSpeed(nspGDive::tof32_3rdSpeed),
          m_f32GDiveTrigConsumption(5.0f), m_f32GDiveBetaConsumption(0.26666668f)
    {
        nnMakeUnitMatrix(&m_sDirMtx);
        nnCopyVectorFast(&m_sLocalVecFast, &nspNnUtil::tosZeroVecFast);
    }
    virtual ~clsGravityDive();
    virtual void cancel();
    virtual void reset();
    virtual void init();
    virtual void execute();
    virtual f32 calcUsePoint(f32 f32Point);

    void refrectionWall();
    void setType(enmType eType);

    void controlDirection();
    void contorlRadian(f32& param_1, f32& param_2, u32 param_3);
    void updateSpeed();
    void requestEffectTaskDash();
    void controlAutoDirection();
    void updatePathRange();
    void initCommon();
    void cancelAutoDive();
};

inline clsGravityDive::~clsGravityDive()
{
}

#endif // GRAVITYDIVE_HPP
