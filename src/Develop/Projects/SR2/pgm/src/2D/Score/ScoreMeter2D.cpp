#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreMeter2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/TexData2D/Score_GearParts2D_TexData.hpp"

namespace nspMeter2D {
stcMeterData DrawData1v = {22, 5,  0,     -23, 2,  -16, 14, 26.0f, -27.0f, 1.0f, 1.5f,
                           34, 31, 0.75f, 20,  16, 3,   15, 255,   255,    2.0f, 3.0f};
stcMeterData DrawData2v = {13, 5,  12,    -12, 2,  -16, 14, 16.0f, -15.0f, 1.0f, 1.5f,
                           22, 21, 0.75f, 10,  16, 3,   15, 255,   255,    1.0f, 1.5f};
stcMeterData DrawData4v = {13, 5,  12,    -12, 2,  -16, 14, 16.0f, -15.0f, 1.0f, 1.5f,
                           22, 21, 0.75f, 10,  16, 3,   15, 255,   255,    1.0f, 1.5f};
} // namespace nspMeter2D

clsScoreMeter2D::clsScoreMeter2D(clsScore2D_Task* pcParent)
{
}

clsScoreMeter2D::~clsScoreMeter2D()
{
}

void clsScoreMeter2D::init()
{
}

void clsScoreMeter2D::execute()
{
}

void clsScoreMeter2D::executeMeter(u32 u32View, u32 u32PlayerNo)
{
}

void clsScoreMeter2D::_drawGauge(
    s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width, f32 f32Gauge, f32 f32Back, f32 f32Max)
{
}

void clsScoreMeter2D::_drawGaugeLight(s32 s32PosX,
                                      s32 s32PosY,
                                      s32 s32Dir,
                                      f32 f32Width,
                                      f32 f32Gauge,
                                      f32 f32Back,
                                      f32 f32Max,
                                      u8 u8AddAlpha)
{
}

void clsScoreMeter2D::_drawFrame(s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width, u32 u32Color)
{
}

void clsScoreMeter2D::_drawSpeed(s32 s32PosX, s32 s32PosY, s32 s32Dir, s32 s32Speed, f32 f32Scale)
{
}

void clsScoreMeter2D::_drawMaxUpInfo(
    clsScoreMeter2D::stcTempParam* psParam, s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width)
{
}

void clsScoreMeter2D::_drawLight(s32 s32PosX, s32 s32PosY, s32 s32Dir, f32 f32Width, u8 u8Alpha)
{
}

void clsScoreMeter2D::_drawCircleEffect(s32 s32PosX,
                                        s32 s32PosY,
                                        s32 s32Dir,
                                        clsScoreMeter2D::stcUserStatus* psUserSt)
{
}

void clsScoreMeter2D::_drawDiveEffect(s32 s32PosX,
                                      s32 s32PosY,
                                      s32 s32Dir,
                                      clsScoreMeter2D::stcUserStatus* psUserSt)
{
}

void clsScoreMeter2D::_drawCloseEffect(s32 s32PosX,
                                       s32 s32PosY,
                                       s32 s32Dir,
                                       clsScoreMeter2D::stcUserStatus* psUserSt)
{
}

void clsScoreMeter2D::draw()
{
}

void clsScoreMeter2D::drawMeter(u32 u32View, u32 u32PlayerNo)
{
}
