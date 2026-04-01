#ifndef GRAVITYACTIONMANAGER_HPP
#define GRAVITYACTIONMANAGER_HPP

class clsPlayerTask;
class hkSimpleShapePhantom;
class clsBaseGravityAction;
class clsAdjustGravityAction_Object;

// total size: 0x50
class clsGravityActionManager {
public:
    class clsPlayerTask*                   m_pcPlayer;                      // offset 0x00, size 0x4
    class hkSimpleShapePhantom*            m_pcPhantom;                     // offset 0x04, size 0x4
    class clsBaseGravityAction*            m_pcActions[3];                  // offset 0x08, size 0xC
    class clsAdjustGravityAction_Object*   m_pcAdjustGravityAction;         // offset 0x14, size 0x4
    int                                    m_eAction;                       // offset 0x18, size 0x4
    int                                    m_eType;                         // offset 0x1C, size 0x4
    int                                    m_eSoundStatus;                  // offset 0x20, size 0x4
    int                                    m_eActionStatus;                 // offset 0x24, size 0x4
    int                                    m_cFlag;                         // offset 0x28, size 0x4
    float                                  m_f32Point;                      // offset 0x2C, size 0x4
    float                                  m_f32LinkBonusPoint;             // offset 0x30, size 0x4
    float                                  m_f32DrawPoint;                  // offset 0x34, size 0x4
    signed int                             m_s32LinkNum;                    // offset 0x38, size 0x4
    signed int                             m_s32BreakNum;                   // offset 0x3C, size 0x4
    float                                  m_f32Radius;                     // offset 0x40, size 0x4
    float                                  m_f32CtrlFrame;                  // offset 0x44, size 0x4
    float                                  m_f32InvalidGCtrlFrame;          // offset 0x48, size 0x4
    float                                  m_f32DefaultInvalidGCtrlFrame;   // offset 0x4C, size 0x4

    void checkLimitPoint();
};

#endif // GRAVITYACTIONMANAGER_HPP
