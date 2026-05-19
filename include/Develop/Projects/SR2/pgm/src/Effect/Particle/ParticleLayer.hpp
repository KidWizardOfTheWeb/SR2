#ifndef PARTICLELAYER_HPP
#define PARTICLELAYER_HPP

#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"

class clsPlayerTask;

// total size: 0xD0
struct stcParticleEditParam {
public:
    stcParticleData sDefData;   // offset 0x0, size 0x80
    NNS_VECTORFAST sPosVecFast; // offset 0x80, size 0x10
    NNS_VECTORFAST sVecFast;    // offset 0x90, size 0x10
    NNS_VECTOR sRotVec;         // offset 0xA0, size 0xC
    NNS_VECTOR sRangeVec;       // offset 0xAC, size 0xC
    NNS_VECTOR sCenterVec;      // offset 0xB8, size 0xC
    u16 u16LoopFrame;           // offset 0xC4, size 0x2
    u8 au8Pad[2];               // offset 0xC6, size 0x2
    f32 f32EndSizeY;            // offset 0xC8, size 0x4
    f32 f32EndSizeZ;            // offset 0xCC, size 0x4
};

// total size: 0x24
struct stcParticleLayerParam {
public:
    u8 u8CtrlFlg;                     // offset 0x0, size 0x1
    u8 u8Num;                         // offset 0x1, size 0x1
    u8 u8Pading[14];                  // offset 0x2, size 0xE
    u16 pu16StartFrame[4];            // offset 0x10, size 0x8
    u16 pu16EndFrame[4];              // offset 0x18, size 0x8
    stcParticleEditParam* psParamAdr; // offset 0x20, size 0x4
};

static stcParticleLayerParam sDebugLayerData;

extern u16 g_u16ParticleLayerStopCode;
extern u16 g_u16ParticleLayerCtrlStopCode;
extern u32 g_u32LayerAdrMask;

// total size: 0x100
class clsParticleLayer : public clsTask {
public:
    virtual ~clsParticleLayer() {}
    virtual void execute();
    virtual void draw();

    void pauseFlg(bool param_1) {}
    void initData(stcParticleLayerParam* param_1, u16* param_2) {}
    void checkFlg();

    stcParticleLayerParam m_sLayer;        // offset 0x54, size 0x24
    u8 m_u8ViewPort;                       // offset 0x78, size 0x1
    u8 m_u8LayerType;                      // offset 0x79, size 0x1
    u16 m_u16DataNo;                       // offset 0x7A, size 0x2
    u16 m_u16StopCode;                     // offset 0x7C, size 0x2
    f32 m_f32CurFrame;                     // offset 0x80, size 0x4
    u8 m_u8PlayFlg;                        // offset 0x84, size 0x1
    s32 m_s32SelectNo;                     // offset 0x88, size 0x4
    f32 m_sMatrix[4][4];                   // offset 0x90, size 0x40
    NNS_VECTORFAST m_sPosVecFast;          // offset 0xD0, size 0x10
    f32 m_SafetyWaitFrame;                 // offset 0xE0, size 0x4
    clsSe3DControl* m_pcSe3DControl;       // offset 0xE4, size 0x4
    NNS_VECTORFAST* m_opsVelocityVecFast;  // offset 0xE8, size 0x4
    NNS_VECTORFAST* m_opsFollowPosVecFast; // offset 0xEC, size 0x4
    NNS_VECTORFAST* m_opsRotVecFast;       // offset 0xF0, size 0x4
    f32 (*m_opsFollowMatrix)[4][4];        // offset 0xF4, size 0x4
    _NNS_TEXLIST* m_opsTexList;            // offset 0xF8, size 0x4
};

namespace nspParticleSet {
extern _NNS_TEXLIST* psTexList_UnionParticle;
extern u8 bParticleConfigBlend[2];
extern s16 as16ParticleConfigTaskMatrix[2][2];
extern s16 as16ParticleConfigTaskTex[2][2][40];
extern u16 au16ParticleConfigTaskCheck[2][2][43][5];

void stopAllLayer();
u32 getModoEffectNo(u32 u32Param1);
void setParticleColision();
clsParticleLayer* registTaskForEvent(u8 u8Param1,
                                     u32 u32Param2,
                                     const NNS_VECTORFAST* psParam3,
                                     const f32 (*psParam4)[4][4]);
void setRemoveThroughColisionParticle(clsPlayerTask* pcParam1, u8 u8Param2);
void setThroughColisionParticle(clsPlayerTask* pcParam1, u8 u8Param2);
void setWaterWalkParticle(clsPlayerTask* pcParam1, bool bParam2);
void setWaterLandingParticle(clsPlayerTask& rcParam1);
void setWaterRunParticle(clsPlayerTask& rcParam1);
void setWallParticle(clsPlayerTask& rcParam1);
void setGrindLinkParticle(clsPlayerTask& rcParam1, u8* pu8Param2, u32 u32Param3);
void setBreakLargeObjectParticle(const NNS_VECTORFAST* psParam1, u32 u32Param2);
void setBreakSmallObjectParticle(const NNS_VECTORFAST* psParam1, u32 u32Param2);
void setBadTrackHi(u8 u8Param1, const f32 (*psParam2)[4][4], const NNS_VECTORFAST* psParam3);
void setBadTrackLow(u8 u8Param1, const f32 (*psParam2)[4][4], const NNS_VECTORFAST* psParam3);
clsParticleLayer* registTask(u8 u8Param1,
                             u32 u32Param2,
                             f32 f32Param3,
                             f32 f32Param4,
                             f32 f32Param5,
                             f32 f32Param6,
                             f32 f32Param7,
                             f32 f32Param8,
                             u8 u8Param9);
clsParticleLayer* registTaskAdr(u8 u8Param1,
                                u32 u32Param2,
                                const f32 (*psParam3)[4][4],
                                const NNS_VECTORFAST* psParam4,
                                const _NNS_TEXLIST* psParam5,
                                u8 u8Param6,
                                u8 u8Param7);
clsParticleLayer* registTaskAdr(u8 u8Param1,
                                u32 u32Param2,
                                const NNS_VECTORFAST* psParam3,
                                u8 u8Param4);
clsParticleLayer* registTask(u8 u8Param1,
                             u32 u32Param2,
                             const NNS_VECTORFAST* psParam3,
                             u8 u8Param4);
clsParticleLayer* registTaskObjData(u8 u8Param1,
                                    u32 u32Param2,
                                    const NNS_VECTORFAST* psParam3,
                                    const NNS_VECTORFAST* psParam4,
                                    const _NNS_TEXLIST* psParam5,
                                    u8 u8Param6,
                                    s32 s32Param7);
clsParticleLayer* registTask(u8 u8Param1,
                             u32 u32Param2,
                             const f32 (*psParam3)[4][4],
                             const NNS_VECTORFAST* psParam4,
                             const _NNS_TEXLIST* psParam5,
                             u8 u8Param6,
                             u8 u8Param7);
clsParticleLayer* registTaskParticleData(u8 u8Param1,
                                         const u16* pu16Param2,
                                         u16 u16Param3,
                                         stcParticleEditParam* psParam4,
                                         const f32 (*psParam5)[4][4],
                                         const NNS_VECTORFAST* psParam6,
                                         const _NNS_TEXLIST* psParam7,
                                         u8 u8Param8,
                                         s32 s32Param9);
void initSetTask();
bool checkDeleateParticleTextureTask(
    bool bParam1, u8 u8Param2, u8 u8Param3, u8 u8Param4, u8 u8Param5);
void subtractParticleTextureTask(stcParticleData* psParam1);
void setParticleTextureTask(bool bParam1, stcParticleData* psParam2);
} // namespace nspParticleSet

#endif // PARTICLELAYER_HPP
