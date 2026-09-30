#ifndef STARTGATE_HPP
#define STARTGATE_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "usr/local/sce/ee/gcc/ee/lib/libc/memset.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/SeIDControl.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_CRI/PS2Cri.hpp"

class clsStartGate_Obj;
class clsPlayerTask;

// total size: 0x48
class clsStartGateModels {
public:
    clsStartGateModels() {}
    ~clsStartGateModels() {}

    clsModelType_OB_TX_MO_MA m_cGate;  // offset 0x0, size 0x20
    clsModelType_OB_TX_MO_MA m_cBlitz; // offset 0x20, size 0x20
    clsModelType_OB_TX m_cLine;        // offset 0x40, size 0x8
};

struct stcStGateFrame {
    f32 f32CEnd;     // offset 0x0, size 0x4
    f32 f32Wait;     // offset 0x4, size 0x4
    f32 f32Start;    // offset 0x8, size 0x4
    f32 f32End;      // offset 0xC, size 0x4
    f32 f32Loop;     // offset 0x10, size 0x4
    f32 f32EStart;   // offset 0x14, size 0x4
    u32 u32Stop;     // offset 0x18, size 0x4
    f32 f32EndFrame; // offset 0x1C, size 0x4
};

struct stcStGateSeFrame {
    f32 f32PlayFrame; // offset 0x0, size 0x4
    u32 u32SndId;     // offset 0x4, size 0x4
};

// total size: 0xA0
class clsStartGate_Obj : public clsGimmickObj {
public:
    clsStartGate_Obj() : m_f32MatMFrame(0.0f), m_u8ExecMode(0), m_pcSe3DControl(NULL)
    {
        memset(m_af32MtnFrame, 0, sizeof(m_af32MtnFrame));

        clsPfCri* pcCri = clsPfCri::GS();
        u32 u32UserNum = nspGlobal::sTask.pcBaseRace->m_s32UserNum;
        s16* ps16SfID = m_SeIdControl.m_as16SfID;
        u32 u32i = 0;
        do {
            *ps16SfID = pcCri->getSfFreeId(0x2701A9);
            ++u32i;
            ++ps16SfID;
        } while (u32i < u32UserNum);
    }
    virtual ~clsStartGate_Obj() { destroyData(); }
    virtual nspPackId::enm getPackId() const { return nspPackId::START_GATE_2050; }
    virtual void createData();
    virtual void destroyData();
    void setBonus(clsPlayerTask* pcPlayer, u32 u32RaceMSec);

    f32 m_f32RocketStartRate;        // offset 0x50, size 0x4
    u32 m_s32EndCnt;                 // offset 0x54, size 0x4
    f32 m_f32Scale;                  // offset 0x58, size 0x4
    f32 m_f32ScaleOffset;            // offset 0x5C, size 0x4
    f32 m_af32MtnFrame[3];           // offset 0x60, size 0xC
    f32 m_f32MatMFrame;              // offset 0x6C, size 0x4
    f32 m_f32FrameCounter;           // offset 0x70, size 0x4
    u16 m_u16StartChk;               // offset 0x74, size 0x2
    u8 m_u8Hit;                      // offset 0x76, size 0x1
    u8 m_u8MatMLoopFlag;             // offset 0x77, size 0x1
    u8 m_u8ExecMode;                 // offset 0x78, size 0x1
    f32 m_f32ScaleBlitzX;            // offset 0x7C, size 0x4
    f32 m_f32ScaleLineX;             // offset 0x80, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0x84, size 0x4
    clsSeIDControl m_SeIdControl;    // offset 0x88, size 0x10
    u8 m_bPlayFlg;                   // offset 0x98, size 0x1

    static stcStGateFrame t_sStGateFrame[17];
    static f32 tof32DenkiScaleX[17];
    static f32 tof32LineScaleX[17];
    static stcStGateSeFrame t_sStGateSeFrame[17];
};

// total size: 0xD4
class clsStartGate_Task
    : public clsBaseGimmickBody<clsStartGate_Task, clsStartGate_Obj, clsStartGateModels> {
public:
    clsStartGate_Task()
        : clsBaseGimmickBody<clsStartGate_Task, clsStartGate_Obj, clsStartGateModels>(1, 101010)
    {
    }
    virtual ~clsStartGate_Task() {}
    virtual void execute();
    virtual void draw();
    virtual void reset() {}
    virtual void createModel(stcBinInfo& rParam1);
};

#endif // STARTGATE_HPP
