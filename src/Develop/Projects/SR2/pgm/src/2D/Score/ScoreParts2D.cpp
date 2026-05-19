#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/TexData2D/Score_GearParts2D_TexData.hpp"

namespace nspParts2D {
stcPartsData DrawData1v = {45,    36,  8,  6,     16,   14,    22.5f, 21.5f, 16, 22, 14,
                           18,    55,  58, 45,    1.0f, 1.15f, 128,   24,    -4, 32, 32,
                           0.75f, 15,  5,  3,     12,   0.5f,  1.15f, 2.3f,  10, 30, 160,
                           95,    105, 8,  20.0f, 5.0f, 1.0f,  12.0f, 0.1f};
stcPartsData DrawData2v = {45,    28, 4,  6,     16,   14,    15.5f, 16.5f, 16, 22, 14,
                           18,    40, 45, 32,    0.7f, 0.85f, 124,   22,    -6, 32, 28,
                           0.75f, 10, 5,  3,     10,   0.25f, 0.85f, 1.7f,  5,  15, 140,
                           70,    80, 10, 20.0f, 5.0f, 1.0f,  12.0f, 0.1f};
stcPartsData DrawData4v = {45,    28, 4,  6,     16,   14,    15.5f, 16.5f, 16, 22, 14,
                           18,    35, 42, 26,    0.6f, 0.8f,  116,   22,    -8, 32, 22,
                           0.75f, 10, 5,  3,     10,   0.25f, 0.8f,  1.6f,  0,  0,  150,
                           65,    75, 8,  20.0f, 5.0f, 1.0f,  12.0f, 0.1f};
} // namespace nspParts2D

clsScoreParts2D::clsScoreParts2D(clsScore2D_Task* pcParent)
{
}

clsScoreParts2D::~clsScoreParts2D()
{
}

void clsScoreParts2D::init()
{
}

void clsScoreParts2D::_exeEnergyLine(stcUserStatus* psUserSt)
{
}

void clsScoreParts2D::execute()
{
}

void clsScoreParts2D::_drawMaxUpInfo(
    stcTempParam* psParam, s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width)
{
}

void clsScoreParts2D::_initActEffect(stcUserStatus* psUserSt, s32 s32No)
{
}

void clsScoreParts2D::_setActEffect(stcUserStatus* psUserSt, s32 s32No, s32 s32x, s32 s32y)
{
}

void clsScoreParts2D::_drawActEffect(stcUserStatus* psUserSt)
{
}

void clsScoreParts2D::_drawRing(s32 s32PosX, s32 s32PosY, s32 s32Dir)
{
}

void clsScoreParts2D::_drawNumBack(s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width, u32 u32Color)
{
}

void clsScoreParts2D::_drawFrame(s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width, u32 u32Param5)
{
}

void clsScoreParts2D::_drawRingNum(
    s32 s32PosX, s32 s32PosY, s32 s32Dir, s32 s32Ring, s32 s32RingMax)
{
}

void clsScoreParts2D::_drawPartsIcon(
    s32 s32PosX, s32 s32PosY, s32 s32Dir, clsPlayerTask* pcPlayer, stcUserStatus* psUserSt)
{
}

void clsScoreParts2D::_drawPartsEtc(s32 s32PosX,
                                    s32 s32PosY,
                                    s32 s32Dir,
                                    clsPlayerTask* pcPlayer,
                                    stcUserStatus* psUserSt,
                                    bool bBotton)
{
}

void clsScoreParts2D::_drawPartsName(
    s32 s32PosX, s32 s32PosY, s32 s32Dir, clsPlayerTask* pcPlayer, stcUserStatus* psUserSt)
{
}

void clsScoreParts2D::_drawPartsLight(
    s32 s32PosX, s32 s32PosY, s32 s32Dir, clsPlayerTask* pcPlayer, u8 u8AddAlpha)
{
}

void clsScoreParts2D::_drawSelectLine(
    s32 s32PosX, s32 s32PosY, s32 s32Dir, clsPlayerTask* pcPlayer, stcUserStatus* psUserSt)
{
}

void clsScoreParts2D::draw()
{
}

void clsScoreParts2D::drawParts(u32 u32View, u32 u32PlayerNo)
{
}

void clsScoreParts2D::drawAddEffect(s32 s32PlayerNo,
                                    s32 s32View,
                                    stcUnionStatus* psUnionSt,
                                    s32 s32PosX,
                                    s32 s32PosY,
                                    s32 s32Dir,
                                    u32 u32Param7)
{
}

void clsScoreParts2D::drawGearWindow(s32 s32PlayerNo,
                                     s32 s32View,
                                     stcUnionStatus* psUnionSt,
                                     s32 s32PosX,
                                     s32 s32PosY,
                                     s32 s32Dir,
                                     u32 u32Param7)
{
}

void clsScoreParts2D::drawRingWindow(s32 s32PlayerNo,
                                     s32 s32View,
                                     stcUnionStatus* psUnionSt,
                                     s32 s32PosX,
                                     s32 s32PosY,
                                     s32 s32Dir,
                                     u32 ou32CharaColor)
{
}
