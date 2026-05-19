#ifndef SCRIPTEFFECT_HPP
#define SCRIPTEFFECT_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsScript_Task;

// total size: 0xE0
class clsScriptEffect_Task : public clsTask {
public:
    clsScriptEffect_Task(u32 u32View,
                         u32 u32Effect,
                         u32 u32Tp,
                         u32 u32Flg,
                         f32 f32OfsX,
                         f32 f32OfsY,
                         f32 f32OfsZ,
                         u32 u32ModelNo,
                         u32 u32NodeNo,
                         f32 f32StartFrame,
                         f32 f32EndFrame,
                         f32 f32WaitFrame);
    virtual ~clsScriptEffect_Task() {}
    virtual void execute();
    virtual void draw();

    void codeEffect(u8* pu8Ptr, clsScript_Task* pParam2);

    f32 m_sTrsMtx[4][4];                    // offset 0x60, size 0x40
    u32 m_eFlag;                            // offset 0xA0, size 0x4
    u32 m_u32View;                          // offset 0xA4, size 0x4
    u32 m_u32EffectNo;                      // offset 0xA8, size 0x4
    u32 m_u32ModelNo;                       // offset 0xAC, size 0x4
    u32 m_u32NodeNo;                        // offset 0xB0, size 0x4
    NNS_VECTOR m_sOfsVec;                   // offset 0xB4, size 0xC
    f32 m_f32Frame;                         // offset 0xC0, size 0x4
    f32 m_f32StartFrame;                    // offset 0xC4, size 0x4
    f32 m_f32EndFrame;                      // offset 0xC8, size 0x4
    f32 m_f32WaitFrame;                     // offset 0xCC, size 0x4
    f32 m_f32MotFrame;                      // offset 0xD0, size 0x4
    f32 m_f32MatFrame;                      // offset 0xD4, size 0x4
    f32 m_f32MofFrame;                      // offset 0xD8, size 0x4
    clsModelType_OB_TX_MO_MA_MF* m_pcModel; // offset 0xDC, size 0x4

    static clsModelType_OB_TX_MO_MA_MF m_tacEffect[32]; // 0xB166E0
    static s32 m_ts32DataNum;                           // 0xB16D60
};

#endif // SCRIPTEFFECT_HPP
