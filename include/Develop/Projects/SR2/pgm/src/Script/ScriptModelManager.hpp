#ifndef SCRIPTMODELMANAGER_HPP
#define SCRIPTMODELMANAGER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsScript_Task;
class clsScriptModel_Task;

// total size: 0x4
class clsScriptModelManager {
public:
    virtual ~clsScriptModelManager() {}

    static s32 m_ts32DebugModelNo;
    static s32 m_ts32DebugDataNo;
    static f32 m_tf32DebugSphereSize;
    static s32 m_ts32DebugNodeNo;
    static s32 m_ts32DataNum;
    static s16 m_tas16LineID[32];
    static u8* m_tapu8DataBuf[64];
    static clsScriptModel_Task* m_tapcModelTask[32];
    static clsModelType_OB_TX_MO_MA_MF m_tacModel[64];

    void codeMdlNodeOfs(u8* puc, clsScript_Task* pcTask);
    void codeMdlAllClear(u8* puc, clsScript_Task* pcTask);
    void codeMdlAllWait(u8* puc, clsScript_Task* pcTask);
    void codeMdlMofMove(u8* puc, clsScript_Task* pcTask);
    void codeMdlClear(u8* puc, clsScript_Task* pcTask);
    void codeMdlWait(u8* puc, clsScript_Task* pcTask);
    void codeMdlAddScale(u8* puc, clsScript_Task* pcTask);
    void codeMdlAddRot(u8* puc, clsScript_Task* pcTask);
    void codeMdlAddPos(u8* puc, clsScript_Task* pcTask);
    void codeMdlScale(u8* puc, clsScript_Task* pcTask);
    void codeMdlRot(u8* puc, clsScript_Task* pcTask);
    void codeMdlPos(u8* puc, clsScript_Task* pcTask);
    void codeMdlPlay(u8* puc, clsScript_Task* pcTask);
    void codeMdl_FrameTex(u8* puc, clsScript_Task* pcTask);
    void codeMdl_Back(u8* puc, clsScript_Task* pcTask);
    void codeFrameTexMdl(u8* puc, clsScript_Task* pcTask);
    void codeDelLineEffect(u8* puc, clsScript_Task* pcTask);
    void codeBackLineEffectDisp(u8* puc, clsScript_Task* pcTask);
    void codeBackLineEffect(u8* puc, clsScript_Task* pcTask);
    void codeDisp(u8* puc, clsScript_Task* pcTask);
    void codeChangeMorfMotion(u8* puc, clsScript_Task* pcTask);
    void codeChangeMatMotion(u8* puc, clsScript_Task* pcTask);
    void codeChangeMotion(u8* puc, clsScript_Task* pcTask);
    void codeModel(u8* puc, clsScript_Task* pcTask);
    void playAllModel(u8* puc, clsScript_Task* pcTask);
    void addData_Ob_Tx_Mo_Ma_Mfo(u8* puc, u32* pui, u16 us, u32 ui);
    void addData_Ob_Tx_Ma_Mfo(u8* puc, u32* pui, u16 us, u32 ui);
    void addData_Ob_Tx_Mo_Ma(u8* puc, u32* pui, u16 us, u32 ui);
    void addData_Ob_Tx_Mfo(u8* puc, u32* pui, u16 us, u32 ui);
    void addData_Ob_Tx_Ma(u8* puc, u32* pui, u16 us, u32 ui);
    void addData_Ob_Tx_Mo(u8* puc, u32* pui, u16 us, u32 ui);
    void addData_Ob_Tx(u8* puc, u32* pui, u16 us, u32 ui);
    void addData_Ob_Mo_Ma(u8* puc, u32* pui, u16 us, u32 ui);
    void addData_Ob_Ma(u8* puc, u32* pui, u16 us, u32 ui);
    void addData_Ob_Mo(u8* puc, u32* pui, u16 us, u32 ui);
    void addData_Ob(u8* puc, u32* pui, u16 us, u32 ui);
    s32 getDataNum();
    void releaseData();
    void initData();
};

#endif // SCRIPTMODELMANAGER_HPP
