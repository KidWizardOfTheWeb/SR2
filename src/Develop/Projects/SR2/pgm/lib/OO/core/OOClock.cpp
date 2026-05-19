#include "Develop/Projects/SR2/pgm/lib/OO/core/OOClock.hpp"

void clsOOClock::reinit(u32 oeCountTypeI,
                        s32 os32MinuteI,
                        s32 os32SecI,
                        s32 os32MSecI,
                        s32 os32MinuteUpLimitI,
                        s32 os32SecUpLimitI,
                        s32 os32MSecUpLimitI)
{
    m_eCountType = oeCountTypeI;
    m_s32Minute = os32MinuteI;
    m_s32Sec = os32SecI;
    m_f32MSec = os32MSecI;
    m_s32MinuteUpLimit = os32MinuteUpLimitI;
    m_s32SecUpLimit = os32SecUpLimitI;
    m_s32MSecUpLimit = os32MSecUpLimitI;
    m_bOverFlow = 0;
    m_bCountStop = 0;
}

void clsOOClock::update()
{
}
