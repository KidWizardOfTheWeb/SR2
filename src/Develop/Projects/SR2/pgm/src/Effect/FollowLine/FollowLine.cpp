#include "Develop/Projects/SR2/pgm/src/Effect/FollowLine/FollowLine.hpp"

static u8 chk__AdvantageS_SizeCheck_[1];
static u8 chk__AirShip_SizeCheck_[1];
static u8 chk__Billy_Default_SizeCheck_[1];
static u8 chk__BlackShot_SizeCheck_[1];
static u8 chk__Blaze_Default_SizeCheck_[1];
static u8 chk__BlueStar_SizeCheck_[1];
static u8 chk__CoverF_SizeCheck_[1];
static u8 chk__CoverP_SizeCheck_[1];
static u8 chk__DummyGear_SizeCheck_[1];
static u8 chk__E_Rider_SizeCheck_[1];
static u8 chk__Faster_SizeCheck_[1];
static u8 chk__Fastest_SizeCheck_[1];
static u8 chk__GearLineData_SizeCheck_[1];
static u8 chk__Infuential_SizeCheck_[1];
static u8 chk__Nights_Default_SizeCheck_[1];
static u8 chk__PinkRose_SizeCheck_[1];
static u8 chk__PlayeSkateLineNode_SizeCheck_[1];
static u8 chk__RailLinker_SizeCheck_[1];
static u8 chk__RedRock_SizeCheck_[1];
static u8 chk__Samba_Default_SizeCheck_[1];
static u8 chk__Silver_Default_SizeCheck_[1];
static u8 chk__Smile_SizeCheck_[1];
static u8 chk__Temptation_SizeCheck_[1];
static u8 chk__Thorttle_SizeCheck_[1];
static u8 chk__Type_J_SizeCheck_[1];
static u8 chk__Type_S_SizeCheck_[1];
static u8 chk__Type_W_SizeCheck_[1];
static u8 chk__Untouchable_SizeCheck_[1];
static u8 chk__WheelCustom_SizeCheck_[1];
static u8 chk__WindStar_SizeCheck_[1];
static u8 chk__YellowTail_SizeCheck_[1];

namespace {
static f32 tf32GcLineScale = 0.23f;
static f32 tf32GcLineVecScale = -0.1f;
static s32 PlayeSkateLineNode[2] = {31, 35};
} // namespace

namespace nspFollowLine {
_NNS_TEXLIST* psTexList_Union;
_NNS_TEXLIST* psTexList_Gimick;
} // namespace nspFollowLine

namespace nspFollowGearLine {
static u32 LineColorTbl[3] = {0x50A0FFFF, 0x96FF1EFF, 0xE01414FF};
static stcParameter DummySingleData;
static stcParameter DummyGear[7];
static stcParameter BlueStar[7];
static stcParameter YellowTail[7];
static stcParameter RedRock[7];
static stcParameter PinkRose[7];
static stcParameter Type_J[7];
static stcParameter Type_S[7];
static stcParameter Type_W[7];
static stcParameter E_Rider[7];
static stcParameter Smile[7];
static stcParameter Temptation[7];
static stcParameter BlackShot[7];
static stcParameter Blaze_Default[7];
static stcParameter Silver_Default[7];
static stcParameter Nights_Default[7];
static stcParameter Samba_Default[7];
static stcParameter Billy_Default[7];
static stcParameter Faster[7];
static stcParameter Fastest[7];
static stcParameter CoverF[7];
static stcParameter CoverP[7];
static stcParameter AdvantageS[7];
static stcParameter WindStar[7];
static stcParameter AirShip[7];
static stcParameter WheelCustom[7];
static stcParameter RailLinker[7];
static stcParameter Infuential[7];
static stcParameter Thorttle[7];
static stcParameter Untouchable[7];
stcParameter* GearLineData[63];
} // namespace nspFollowGearLine

static stcParam oasLineParamTest = {0,
                                    1,
                                    0xFF,
                                    0,
                                    19,
                                    16,
                                    0xFFFFFFFF,
                                    0.0f,
                                    1.0f,
                                    {0.0f, 0.5f, 0.0f, 0.0f},
                                    {0.0f, 0.0f, 0.0f, 0.0f}};

NNS_VECTORFAST clsBackLineEffectTask::m_asLastViewPosFast[5];

void clsBackLineEffectTask::execute()
{
}

void clsBackLineEffectTask::stepDrawNum(s16 s16MaxNum)
{
}

void clsBackLineEffectTask::update()
{
}

void clsBackLineEffectTask::calcDrawPoint_Trick(const NNS_VECTORFAST* psPosFast,
                                                const NNS_VECTORFAST* psVecFast,
                                                const NNS_VECTORFAST* psOffFast,
                                                f32 f32AddScale)
{
}

void clsBackLineEffectTask::calcDrawPoint_GCtrl(const NNS_VECTORFAST* psPosFast,
                                                const NNS_VECTORFAST* pParam2,
                                                const NNS_VECTORFAST* pParam3,
                                                const NNS_VECTORFAST* pParam4)
{
}

void clsBackLineEffectTask::calcDrawPoint_Diff(const NNS_VECTORFAST* psPosFast,
                                               const NNS_VECTORFAST* psVecFast,
                                               const NNS_VECTORFAST* psOffFast,
                                               const NNS_VECTORFAST* psPowerFast)
{
}

void clsBackLineEffectTask::calcDrawPoint_Power(const NNS_VECTORFAST* psPosFast,
                                                const NNS_VECTORFAST* psVecFast,
                                                const NNS_VECTORFAST* psOffFast,
                                                const NNS_VECTORFAST* psPower0Fast,
                                                const NNS_VECTORFAST* psPowerFast)
{
}

void clsBackLineEffectTask::calcDrawPrim_Move(NNS_PRIM3D_PCT* psPrimData,
                                              const NNS_VECTORFAST* psPosFast,
                                              const NNS_VECTORFAST* psVecFast,
                                              const NNS_VECTORFAST* psOfsFast,
                                              const NNS_VECTORFAST* psGearVecFast,
                                              const NNS_VECTORFAST* psGearOfsFast,
                                              u32 u32Color)
{
}

void clsBackLineEffectTask::calcDrawPrim_NoMove(NNS_PRIM3D_PCT* psPrimData,
                                                const NNS_VECTORFAST* psPosFast,
                                                const NNS_VECTORFAST* psVecFast,
                                                const NNS_VECTORFAST* psOfsFast,
                                                const NNS_VECTORFAST* pParam5,
                                                u32 u32Color)
{
}

void clsBackLineEffectTask::calcDrawPrim_GCtrl(NNS_PRIM3D_PCT* psPrimData,
                                               const NNS_VECTORFAST* psPosFast,
                                               const NNS_VECTORFAST* psVecFast,
                                               const NNS_VECTORFAST* psOfsFast,
                                               const NNS_VECTORFAST* pParam5,
                                               u32 u32Color)
{
}

void clsBackLineEffectTask::calcDrawPrim_Diff(NNS_PRIM3D_PCT* psPrimData,
                                              const NNS_VECTORFAST* psPosFast,
                                              const NNS_VECTORFAST* psVecFast,
                                              const NNS_VECTORFAST* psOfsFast,
                                              u32 u32Color)
{
}

void clsBackLineEffectTask::calcDrawPrim_Skate(NNS_PRIM3D_PCT* psPrimData,
                                               const NNS_VECTORFAST* psPosFast,
                                               const NNS_VECTORFAST* psVecFast,
                                               const NNS_VECTORFAST* psOfsFast,
                                               u32 u32Color)
{
}

void clsBackLineEffectTask::calcDrawPrim_Trick(NNS_PRIM3D_PCT* psPrimData,
                                               const NNS_VECTORFAST* psPosFast,
                                               const NNS_VECTORFAST* psVecFast,
                                               const NNS_VECTORFAST* psGearVecFast,
                                               const NNS_VECTORFAST* psGearOfsFast,
                                               u32 u32Color)
{
}

void clsBackLineEffectTask::draw()
{
}

void clsBackLineEffect_Begin_Task::draw()
{
}

void clsBackLineEffect_End_Task::draw()
{
}

clsBackLineEffect_Begin_Task::~clsBackLineEffect_Begin_Task()
{
}
