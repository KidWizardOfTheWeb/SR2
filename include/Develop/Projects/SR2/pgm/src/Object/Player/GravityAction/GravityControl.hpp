#ifndef GRAVITYCONTROL_HPP
#define GRAVITYCONTROL_HPP
#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/BaseGravityAction.hpp"

class clsGravityActionManager;
class clsPlayerTask;
class clsSimpleShapePhantom;
class clsTask;

// total size: 0x98
struct stcCommonSetting {
    f32 f32RebootFrame;                 // offset 0x0, size 0x4
    f32 f32BonusAccele;                 // offset 0x4, size 0x4
    f32 f32BonusMinSpeed;               // offset 0x8, size 0x4
    f32 f32TrackingRadRate;             // offset 0xC, size 0x4
    f32 f32MinSpeed;                    // offset 0x10, size 0x4
    f32 f32MaxSpeed;                    // offset 0x14, size 0x4
    f32 f32SlideReadyFrame;             // offset 0x18, size 0x4
    f32 f32SlideCancelFrame;            // offset 0x1C, size 0x4
    f32 f32SlideLimitFrame;             // offset 0x20, size 0x4
    f32 f32SlideChargeFrame;            // offset 0x24, size 0x4
    f32 f32SlideSlowDownFrame;          // offset 0x28, size 0x4
    f32 f32SlideCurveDecayRate;         // offset 0x2C, size 0x4
    f32 f32SlideReadyJumpSpeed;         // offset 0x30, size 0x4
    s32 s32SlideRotateAcceleFrameX;     // offset 0x34, size 0x4
    s32 s32SlideRotateAcceleFrameY;     // offset 0x38, size 0x4
    f32 f32SlideRotateAcceleRadX;       // offset 0x3C, size 0x4
    f32 f32SlideRotateAcceleRadY;       // offset 0x40, size 0x4
    f32 f32SlideMaxRotateX;             // offset 0x44, size 0x4
    f32 f32SlideMaxRotateY;             // offset 0x48, size 0x4
    f32 f32SlideMoveFrame;              // offset 0x4C, size 0x4
    f32 f32TrickReadyFrame;             // offset 0x50, size 0x4
    f32 f32TrickCancelFrame;            // offset 0x54, size 0x4
    f32 f32TrickLimitFrame;             // offset 0x58, size 0x4
    f32 f32TrickChargeFrame;            // offset 0x5C, size 0x4
    f32 f32TrickSlowDownFrame;          // offset 0x60, size 0x4
    s32 s32TrickRotateAcceleFrameX;     // offset 0x64, size 0x4
    s32 s32TrickRotateAcceleFrameY;     // offset 0x68, size 0x4
    f32 f32TrickRotateAcceleRadX;       // offset 0x6C, size 0x4
    f32 f32TrickRotateAcceleRadY;       // offset 0x70, size 0x4
    f32 f32TrickMaxRotateX;             // offset 0x74, size 0x4
    f32 f32TrickMaxRotateY;             // offset 0x78, size 0x4
    f32 f32TrickMoveFrame;              // offset 0x7C, size 0x4
    f32 f32TrickLandStiffFrame;         // offset 0x80, size 0x4
    f32 f32SlowdownSpeed;               // offset 0x84, size 0x4
    f32 f32SlideGpZeroLimitFrame;       // offset 0x88, size 0x4
    f32 f32SlideGpZeroRotateAcceleRadX; // offset 0x8C, size 0x4
    f32 f32TrickGpZeroLimitFrame;       // offset 0x90, size 0x4
    f32 f32GCtrlWheelDischargeRate;     // offset 0x94, size 0x4
};

class clsGravityControl : public clsBaseGravityAction {
public:
    enum enmType {
        TYPE_SLIDE = 0,
        TYPE_TRICK = 1,
        TYPE_FLIGHT = 2,
    };

    enum enmKeyTable {
        KEY_TABLE__FIRST = 0,
        KEY_TABLE__MIDDLE_00 = 1,
        KEY_TABLE__MIDDLE_01 = 2,
        KEY_TABLE__LAST = 3,
        MAX_KEY_TABLE_NUM = 4,
    };

    static stcCommonSetting t_sCommonSetting;

    clsGravityControl(clsGravityActionManager* pcManager) : clsBaseGravityAction(pcManager) {}
    virtual ~clsGravityControl() {}

    NNS_VECTORFAST m_sUpVecFast;        // offset 0x20, size 0x10
    NNS_QUATERNION m_sBaseQuat;         // offset 0x30, size 0x10
    clsSimpleShapePhantom* m_pcPhantom; // offset 0x40, size 0x4
    clsTask* m_pcEffectCharge_Task;     // offset 0x44, size 0x4
    clsTask* m_pcEffectWrist_Task;      // offset 0x48, size 0x4
    clsTask* m_pcEffectLine_Task;       // offset 0x4C, size 0x4
    enmType m_eType;                    // offset 0x50, size 0x4
    s32 m_cStatus;                      // offset 0x54, size 0x4
    s32 m_cBonus;                       // offset 0x58, size 0x4
    u8 m_eFlag;                         // offset 0x5C, size 0x1
    u8 m_bChangeGravity;                // offset 0x5D, size 0x1
    f32 m_f32LeverRateX;                // offset 0x60, size 0x4
    f32 m_f32LeverRateY;                // offset 0x64, size 0x4
    f32 m_f32LeverTimeX;                // offset 0x68, size 0x4
    f32 m_f32LeverTimeY;                // offset 0x6C, size 0x4
    f32 m_f32VelocityRadX;              // offset 0x70, size 0x4
    f32 m_f32VelocityRadY;              // offset 0x74, size 0x4
    f32 m_f32PosturalRadX;              // offset 0x78, size 0x4
    f32 m_f32PosturalRadY;              // offset 0x7C, size 0x4
    f32 m_f32Frame;                     // offset 0x80, size 0x4
    f32 m_f32FaceRate;                  // offset 0x84, size 0x4
    f32 m_f32ChargeFrame;               // offset 0x88, size 0x4
    f32 m_f32RotateAcceleRate;          // offset 0x8C, size 0x4
    f32 m_f32WeightMinSpeed;            // offset 0x90, size 0x4
    f32 m_f32WeightReadyFrame;          // offset 0x94, size 0x4
    f32 m_f32LimitFrame;                // offset 0x98, size 0x4
    f32 m_f32RotateAcceleRadX;          // offset 0x9C, size 0x4
    f32 m_f32TrickFrameRate;            // offset 0xA0, size 0x4
    f32 m_f32TrickDecceleFrame;         // offset 0xA4, size 0x4
    s8 m_as8AdjustKeyTable[4];          // offset 0xA8, size 0x4

    void setCommonSetting();
    virtual void cancel();
    virtual void reset();
    virtual void init();
    virtual void execute();
    virtual f32 calcUsePoint(f32 f32Point);
    void calcWeightParam();
    void initCommon();
    void initMoveCommon();
    void initFallCommon();
    void endCommon();
    void stopEffect();
    void selectAngle();
    void settingAngle();
    void setDashParam(f32 f32BaseSpeed, f32 f32MaxSpeed, f32 f32DashFrame);
    void checkChangeGravity();
    void adjustVelocity();
    void calcRotateMatrix(f32 (*psDstMtx)[4][4]);
    void calcRotateQuaternion(NNS_QUATERNION* psDstQuat);
    void setKeyTable(enmKeyTable eKeyTable, clsPlayerTask* pcPlayer);
    void destroyEffectTaskCharge() {}
    void destroyEffectTaskWrist() {}
    void destroyEffectTaskLine() {}
    f32 getChargeRate() { return 0.0f; }
    u8 setupBaseQuat_SpecialAdjust() { return 0; }
    u8 selectAngle_SpecialAdjust() { return 0; }
    u8 initMove_SpecialAdjust() { return 0; }
};

#endif // GRAVITYCONTROL_HPP
