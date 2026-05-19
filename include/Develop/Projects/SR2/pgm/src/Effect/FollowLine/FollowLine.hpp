#ifndef FOLLOWLINE_HPP
#define FOLLOWLINE_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "usr/local/sega/nn/src/DrawPrim/nndrawprim.h"
#include "usr/local/sega/nn/src/Texture/nntexture.h"
#include "Develop/Projects/SR2/pgm/src/Effect/Weather.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

namespace nspFollowLine {
extern _NNS_TEXLIST* psTexList_Union;
extern _NNS_TEXLIST* psTexList_Gimick;
} // namespace nspFollowLine

// total size: 0x40
struct stcParam {
    s8 s8Interval;              // offset 0x0
    u8 u8TexNo;                 // offset 0x1
    u8 u8StAlpha;               // offset 0x2
    u8 u8EdAlpha;               // offset 0x3
    s16 s16NodeNo;              // offset 0x4
    s16 s16DataNum;             // offset 0x6
    u32 u32Color;               // offset 0x8
    f32 f32StTu;                // offset 0xC
    f32 f32EdTu;                // offset 0x10
    NNS_VECTORFAST sSizeFast;   // offset 0x20
    NNS_VECTORFAST sOffsetFast; // offset 0x30
};

// total size: 0xB0
struct stcParameter {
    s32 s32LineNum;                // offset 0x0, size 0x4
    NNS_VECTORFAST asSizeVec[2];   // offset 0x10, size 0x20
    NNS_VECTORFAST asOfsVec[4][2]; // offset 0x30, size 0x80
};

// total size: 0x14
struct stcGimickParam {
    NNS_OBJECT* opsObject;  // offset 0x0, size 0x4
    NNS_MOTION* opsMotion;  // offset 0x4, size 0x4
    f32 (*opsMatrix)[4][4]; // offset 0x8, size 0x4
    f32* opf32Frame;        // offset 0xC, size 0x4
    f32 f32Scale;           // offset 0x10, size 0x4
};

// total size: 0xC
struct stcTrickSubParam {
    s16 s16DataNum; // offset 0x0, size 0x2
    f32 f32Width;   // offset 0x4, size 0x4
    f32 f32Scale;   // offset 0x8, size 0x4
};

// total size: 0x20
struct stcGimickSubParam {
    NNS_VECTORFAST sStartFast; // offset 0x0, size 0x10
    NNS_VECTORFAST sPowerFast; // offset 0x10, size 0x10
};

class clsBackLineEffectTask : public clsTask {
public:
    virtual ~clsBackLineEffectTask();

    clsBackLineEffectTask(u8 u8Type, const stcParam* opsParam, s32 s32SubNo) : clsTask(0, 0) {}

    virtual void execute();
    virtual void draw();
    virtual void reset();

    void stepDrawNum(s16 s16MaxNum);
    void update();
    void calcDrawPoint_Trick(const NNS_VECTORFAST* psPosFast,
                             const NNS_VECTORFAST* psVecFast,
                             const NNS_VECTORFAST* psOffFast,
                             f32 f32AddScale);
    void calcDrawPoint_GCtrl(const NNS_VECTORFAST* psPosFast,
                             const NNS_VECTORFAST* pParam2,
                             const NNS_VECTORFAST* pParam3,
                             const NNS_VECTORFAST* pParam4);
    void calcDrawPoint_Diff(const NNS_VECTORFAST* psPosFast,
                            const NNS_VECTORFAST* psVecFast,
                            const NNS_VECTORFAST* psOffFast,
                            const NNS_VECTORFAST* psPowerFast);
    void calcDrawPoint_Power(const NNS_VECTORFAST* psPosFast,
                             const NNS_VECTORFAST* psVecFast,
                             const NNS_VECTORFAST* psOffFast,
                             const NNS_VECTORFAST* psPower0Fast,
                             const NNS_VECTORFAST* psPowerFast);
    void calcDrawPrim_Move(NNS_PRIM3D_PCT* psPrimData,
                           const NNS_VECTORFAST* psPosFast,
                           const NNS_VECTORFAST* psVecFast,
                           const NNS_VECTORFAST* psOfsFast,
                           const NNS_VECTORFAST* psGearVecFast,
                           const NNS_VECTORFAST* psGearOfsFast,
                           u32 u32Color);
    void calcDrawPrim_NoMove(NNS_PRIM3D_PCT* psPrimData,
                             const NNS_VECTORFAST* psPosFast,
                             const NNS_VECTORFAST* psVecFast,
                             const NNS_VECTORFAST* psOfsFast,
                             const NNS_VECTORFAST* pParam5,
                             u32 u32Color);
    void calcDrawPrim_GCtrl(NNS_PRIM3D_PCT* psPrimData,
                            const NNS_VECTORFAST* psPosFast,
                            const NNS_VECTORFAST* psVecFast,
                            const NNS_VECTORFAST* psOfsFast,
                            const NNS_VECTORFAST* pParam5,
                            u32 u32Color);
    void calcDrawPrim_Diff(NNS_PRIM3D_PCT* psPrimData,
                           const NNS_VECTORFAST* psPosFast,
                           const NNS_VECTORFAST* psVecFast,
                           const NNS_VECTORFAST* psOfsFast,
                           u32 u32Color);
    void calcDrawPrim_Skate(NNS_PRIM3D_PCT* psPrimData,
                            const NNS_VECTORFAST* psPosFast,
                            const NNS_VECTORFAST* psVecFast,
                            const NNS_VECTORFAST* psOfsFast,
                            u32 u32Color);
    void calcDrawPrim_Trick(NNS_PRIM3D_PCT* psPrimData,
                            const NNS_VECTORFAST* psPosFast,
                            const NNS_VECTORFAST* psVecFast,
                            const NNS_VECTORFAST* psGearVecFast,
                            const NNS_VECTORFAST* psGearOfsFast,
                            u32 u32Color);

    void drawPlayerGear() {}
    void drawPlayerNode() {}
    void drawNoMovePos() {}
    void drawObject() {}
    void drawEvent() {}
    void drawGimick() {}
    void subFlg(u16 u16Param1) {}
    u8 getFlg() { return m_sStatus.u8Windy; }
    void addFlg(u16 u16Flg) { m_sStatus.u32Flg |= u16Flg; }
    void changeParam(const stcParam* opsParam) { m_opsParam = const_cast<stcParam*>(opsParam); }

    static NNS_VECTORFAST m_asLastViewPosFast[5];

    // Members
    clsWeather_Task::stcStatus m_sStatus;   // offset 0x60, size 0x20
    stcGimickParam m_sGimickParam;          // offset 0x80, size 0x14
    u32 m_u32LineColor;                     // offset 0x94, size 0x4
    f32 m_f32GctrlWaitFrame;                // offset 0x98, size 0x4
    NNS_VECTORFAST m_sNoMovePosFast;        // offset 0xA0, size 0x10
    NNS_VECTORFAST m_sLastBasePosFast;      // offset 0xB0, size 0x10
    NNS_VECTORFAST* m_opsNoMovePosFastAdr;  // offset 0xC0, size 0x4
    NNS_VECTORFAST* m_opsCompPosFastAdr;    // offset 0xC4, size 0x4
    f32 (*m_opsNoMoveMtx)[4][4];            // offset 0xC8, size 0x4
    stcParam* m_opsParam;                   // offset 0xCC, size 0x4
    stcTrickSubParam* m_opsTrickSubParam;   // offset 0xD0, size 0x4
    stcGimickSubParam* m_opsGimickSubParam; // offset 0xD4, size 0x4
    NNS_VECTOR m_asPoint[82];               // offset 0xD8, size 0x3D8
    _NNS_TEXLIST* m_psTexList;              // offset 0x4B0, size 0x4
};

class clsBackLineEffect_Begin_Task : public clsTask {
public:
    virtual ~clsBackLineEffect_Begin_Task();
    virtual void draw();
};

class clsBackLineEffect_End_Task : public clsTask {
public:
    virtual ~clsBackLineEffect_End_Task() {}
    virtual void draw();
};

// total size: 0x40
struct stcFollowLine {
    u32 u32Flg;        // offset 0x0, size 0x4
    s32 s32DataMax;    // offset 0x4, size 0x4
    s32 s32DrawBorn;   // offset 0x8, size 0x4
    f32 f32Width;      // offset 0xC, size 0x4
    f32 f32Height;     // offset 0x10, size 0x4
    f32 f32Depth;      // offset 0x14, size 0x4
    f32 f32OfsX;       // offset 0x18, size 0x4
    f32 f32OfsY;       // offset 0x1C, size 0x4
    f32 f32OfsZ;       // offset 0x20, size 0x4
    s16 s16LineInter;  // offset 0x24, size 0x2
    f32 f32StTu;       // offset 0x28, size 0x4
    f32 f32EdTu;       // offset 0x2C, size 0x4
    u8 u8StAlpha;      // offset 0x30, size 0x1
    u8 u8EdAlpha;      // offset 0x31, size 0x1
    f32 f32TrickWidth; // offset 0x34, size 0x4
    f32 f32TrickSize;  // offset 0x38, size 0x4
    u8 u8r;            // offset 0x3C, size 0x1
    u8 u8g;            // offset 0x3D, size 0x1
    u8 u8b;            // offset 0x3E, size 0x1
};

#endif // FOLLOWLINE_HPP
