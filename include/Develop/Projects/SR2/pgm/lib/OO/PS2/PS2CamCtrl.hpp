#ifndef PS2CAMCTRL_HPP
#define PS2CAMCTRL_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCamera.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"
#include "types.h"

// Forward declarations
class clsCamCtrl;
class clsCamMixer;

// total size: 0x1C
class clsCamCtrl {
public:
    virtual ~clsCamCtrl() {}
    virtual void startMixing() {}
    virtual u32 preIntervention(clsPfCamera* pcCamera)
    {
        return m_pfPreIntervention != 0 ? m_pfPreIntervention(pcCamera) : 0;
    }
    virtual u32 postIntervention(clsPfCamera* pcCamera)
    {
        return m_pfPostIntervention != 0 ? m_pfPostIntervention(pcCamera) : 0;
    }
    u32 countUpTime();

    u16 m_u16Priority;                         // offset 0x4, size 0x2
    f32 m_f32AliveTime;                        // offset 0x8, size 0x4
    u16 m_u16TblIdx;                           // offset 0xC, size 0x2
    u32 (*m_pfPreIntervention)(clsPfCamera*);  // offset 0x10
    u32 (*m_pfPostIntervention)(clsPfCamera*); // offset 0x14
    u32 m_u32UniqNo;                           // offset 0x18, size 0x4
};

// total size: 0x4
class clsCamIvBase {
public:
    virtual ~clsCamIvBase() {}
};

// total size: 0xC
struct stcCamCtrlStock {
    u32 u32CamCtrlType;        // offset 0x0, size 0x4
    clsCamCtrl* pacCamCtrl[2]; // offset 0x4, size 0x8
};

// total size: 0xF5D0
class clsCamMixer {
public:
    virtual ~clsCamMixer();
    virtual void mixing();
    virtual void setCamCtrlTbl(u32 u32JmpIdx, u32 u32Num, u8 u8NextFlg) = 0; // slot 4, null in base
    virtual void nextMixData() = 0;                                          // slot 5, null in base
    virtual void finishMixing();

    void setCamControl(clsCamCtrl* pcCamCtrl, u8 ou8MixMode, u32 ou32Time);
    void registStockCamCtrl(u32 u32CtrlType, clsCamCtrl* pcCamCtrl1, clsCamCtrl* pcCamCtrl2);
    clsCamCtrl* getStockCamCtrl(u32 u32CtrlType);
    clsCamMixer();

    clsPfCamera* m_pcBaseCamera; // offset 0x4, size 0x4
    vector m_vecsCamCtrlStock;   // offset 0x8, size 0xC
    clsCamCtrl* m_pacCamCtrl[2]; // offset 0x14, size 0x8
    clsPfCamera m_acCamera[2];   // offset 0x20, size 0xF5A0
    clsCamIvBase* m_pcCamIv;     // offset 0xF5C0, size 0x4
    u8 m_u8Mode;                 // offset 0xF5C4, size 0x1
    u8 m_u8IsLock;               // offset 0xF5C5, size 0x1
    u8 m_u8HasNum;               // offset 0xF5C6, size 0x1
    u32 m_u32Ratio;              // offset 0xF5C8, size 0x4
    u32 m_u32Time;               // offset 0xF5CC, size 0x4
};

#endif // PS2CAMCTRL_HPP
