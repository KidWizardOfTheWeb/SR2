#include "Develop/Projects/SR2/pgm/lib/OO/CRI/CriMovie.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/PS2_CRI/PS2Cri.hpp"

extern "C" MwsfdStat mwPlyGetStat(void* pcAllocator);

clsCriMovie::clsCriMovie(const stcData& orsDataI,
                         s32 s32DrawXI,
                         s32 s32DrawYI,
                         enmLoopFlag eLoopI,
                         enmSubTitle eSubTitleI,
                         enmAllocate eAllocateI,
                         s32 s32DrawWI,
                         s32 s32DrawHI)
    : m_orsData(orsDataI), m_eAllocate(eAllocateI), m_eLoop(eLoopI), m_eSubTitle(eSubTitleI)
{
}

void clsCriMovie::restart()
{
}

void clsCriMovie::render()
{
}

void clsCriMovie::stop()
{
}

void clsCriMovie::pause(u32 bSetI)
{
}

MwsfdStat clsCriMovie::getStatus() const
{
    if (clsPfCri::GS()->m_pcAllocator_Movie == 0) {
        return MWSFD_STAT_STOP;
    }
    return mwPlyGetStat(clsPfCri::GS()->m_pcAllocator_Movie);
}

f32 clsCriMovie::getTime_Sec() const
{
    return 0.0f;
}
