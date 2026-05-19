#ifndef GRAVITYDIVE_HPP
#define GRAVITYDIVE_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/GravityActionManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/GravityDivePathRange.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"

class clsSimpleShapePhantom;
class clsBaseGravityLinkObject;
class clsTask;

// total size: 0x1D0
class clsGravityDive : public clsBaseGravityAction {
public:
    // Note: enmType — name collision possible with other enmType enums
    enum enmType {
        TYPE_FRONT = 0,
        TYPE_BACK = 1,
    };

    // Note: enmStatus — name collision with Motion.hpp enmStatus (different values)
    enum enmStatus {
        STATUS_NONE = 0,
        STATUS_EXECUTE = 1,
        STATUS_CRASH = 2,
        STATUS_BREAK = 3,
    };

    static f32 t_f32SystemReadyFrame;

    f32 m_sDirMtx[4][4];                      // offset 0x20, size 0x40
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

    clsGravityDive(clsGravityActionManager* p1);
    virtual ~clsGravityDive() {}
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

#endif // GRAVITYDIVE_HPP
