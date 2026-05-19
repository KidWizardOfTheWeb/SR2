#include "Develop/Projects/SR2/pgm/lib/OO/PS2/PS2CamCtrl.hpp"

u32 clsCamCtrl::countUpTime()
{
    return 0;
}

clsCamMixer::clsCamMixer()
{
}

clsCamMixer::~clsCamMixer()
{
}

clsCamCtrl* clsCamMixer::getStockCamCtrl(u32 u32CtrlType)
{
    return 0;
}

void clsCamMixer::registStockCamCtrl(u32 u32CtrlType,
                                     clsCamCtrl* pcCamCtrl1,
                                     clsCamCtrl* pcCamCtrl2)
{
}

void clsCamMixer::setCamControl(clsCamCtrl* pcCamCtrl, u8 ou8MixMode, u32 ou32Time)
{
}

void clsCamMixer::mixing()
{
}

void clsCamMixer::finishMixing()
{
}
