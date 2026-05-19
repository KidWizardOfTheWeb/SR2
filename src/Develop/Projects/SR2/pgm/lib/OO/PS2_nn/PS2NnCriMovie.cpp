#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCriMovie.hpp"

clsPfMovie::clsPfMovie(const stcData& orsDataI,
                       s32 s32DrawXI,
                       s32 s32DrawYI,
                       clsCriMovie::enmLoopFlag eLoopI,
                       clsCriMovie::enmSubTitle eSubTitleI,
                       enmAllocate eAllocateI,
                       s32 s32DrawWI,
                       s32 s32DrawHI)
    : clsCriMovie(
          orsDataI, s32DrawXI, s32DrawYI, eLoopI, eSubTitleI, eAllocateI, s32DrawWI, s32DrawHI)
{
}

clsPfMovie::~clsPfMovie()
{
}

void clsPfMovie::createTexture(void* pvLocalAddressI)
{
}

void clsPfMovie::updateTexture(MwsfdFrmObj* psPlayFrameI)
{
}

void clsPfMovie::beforeRender()
{
}
