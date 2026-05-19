#ifndef SCRIPTMODEL_HPP
#define SCRIPTMODEL_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickRigidListener.hpp"

// total size: 0x1F0
class clsScriptModel_Task : public clsTask {
public:
    clsScriptModel_Task(s32 s32No,
                        u32 u32Arg0,
                        u32 u32Arg1,
                        u32 u32Arg2,
                        u32 u32Arg3,
                        clsTask* pcTask,
                        u8 u8Arg4,
                        u8 u8Arg5);
    virtual ~clsScriptModel_Task();
    virtual void execute();
    virtual void draw();

    void drawModel(f32 (*ppfMtx)[4][4]);
    void calcMtx(bool bFlag);
    void executeModel();
    void update();
    void releaseOldMorpf();
    void getNodeMtx(f32 (*ppfMtx0)[4][4], u32 u32NodeNo, f32 (*ppfMtx1)[4][4]);
    void getNodePos(NNS_VECTOR* psVec, u32 u32NodeNo, f32 (*ppfMtx)[4][4]);
    void setWaitFrame(f32 f32Frame);
    void setNodeOffset(u32 u32Arg0, u32 u32Arg1, u32 u32Arg2);
    void setBackLineEffect(s32 s32No,
                           u32 u32NodeNo,
                           s32 s32DataNum,
                           f32 f32Width,
                           f32 f32Height,
                           f32 f32OfsX,
                           f32 f32OfsY,
                           f32 f32OfsZ);
    void clearBackLineEffect(s32 s32No);
    void dispBackLineEffect(u32 u32Show, s32 s32No);

    u32 m_u32Flg;                            // offset 0x54, size 0x4
    s32 m_s32DataNo;                         // offset 0x58, size 0x4
    u32 m_u32TexModelNo;                     // offset 0x5C, size 0x4
    f32 m_f32PosAddFrame;                    // offset 0x60, size 0x4
    NNS_VECTOR m_sPosVec;                    // offset 0x64, size 0xC
    NNS_VECTOR m_sAddPosVec;                 // offset 0x70, size 0xC
    f32 m_f32RotAddFrame;                    // offset 0x7C, size 0x4
    NNS_VECTOR m_sRotVec;                    // offset 0x80, size 0xC
    NNS_VECTOR m_sAddRotVec;                 // offset 0x8C, size 0xC
    f32 m_f32ScaleAddFrame;                  // offset 0x98, size 0x4
    NNS_VECTOR m_sScaleVec;                  // offset 0x9C, size 0xC
    NNS_VECTOR m_sAddScaleVec;               // offset 0xA8, size 0xC
    f32 m_f32WaitFrame;                      // offset 0xB4, size 0x4
    f32 m_f32NextWaitFrame;                  // offset 0xB8, size 0x4
    f32 m_sDrawMtx[4][4];                    // offset 0xC0, size 0x40
    clsTask* m_pcScriptTask;                 // offset 0x100, size 0x4
    clsModelType_OB_TX_MO_MA_MF* m_pcModel;  // offset 0x104, size 0x4
    clsBackLineEffectTask* m_apcBackLine[2]; // offset 0x108, size 0x8
    stcParam m_asBackLineParam[2];           // offset 0x110, size 0x80
    _NNS_TEXLIST* m_psChengeTexList;         // offset 0x190, size 0x4
    NNS_MOTION* m_psMotion;                  // offset 0x194, size 0x4
    NNS_MOTION* m_psMatMotion;               // offset 0x198, size 0x4
    NNS_MOTION* m_psMorphMotion;             // offset 0x19C, size 0x4
    NNS_OBJECT* m_psMatMotObj;               // offset 0x1A0, size 0x4
    u32* m_psMatStatus;                      // offset 0x1A4, size 0x4
    NNS_OBJECT* m_psMatMotObjOld;            // offset 0x1A8, size 0x4
    u32* m_psMatStatusOld;                   // offset 0x1AC, size 0x4
    NNS_OBJECT* m_psMorphObj;                // offset 0x1B0, size 0x4
    f32* m_pf32MorphWaitPallet;              // offset 0x1B4, size 0x4
    NNS_OBJECT* m_psMorphObjOld;             // offset 0x1B8, size 0x4
    f32* m_pf32MorphWaitPalletOld;           // offset 0x1BC, size 0x4
    s16 m_s16MotNo;                          // offset 0x1C0, size 0x2
    s16 m_s16MatMotNo;                       // offset 0x1C2, size 0x2
    s16 m_s16MofMotNo;                       // offset 0x1C4, size 0x2
    s16 m_s16ChaMotNo;                       // offset 0x1C6, size 0x2
    s16 m_s16ChaMatMotNo;                    // offset 0x1C8, size 0x2
    s16 m_s16ChaMofMotNo;                    // offset 0x1CA, size 0x2
    f32 m_f32MotionFrame;                    // offset 0x1CC, size 0x4
    f32 m_f32MatMotionFrame;                 // offset 0x1D0, size 0x4
    f32 m_f32MofMotionFrame;                 // offset 0x1D4, size 0x4
    u8 m_u8FrameTexNo;                       // offset 0x1D8, size 0x1
    u8 m_u8FrameTexModel;                    // offset 0x1D9, size 0x1
    u16 m_u16NodeModelNo;                    // offset 0x1DA, size 0x2
    s16 m_s16NodeNo;                         // offset 0x1DC, size 0x2
    u16 m_u16NextNodeModelNo;                // offset 0x1DE, size 0x2
    s16 m_s16NextNodeNo;                     // offset 0x1E0, size 0x2
};

#endif // SCRIPTMODEL_HPP
