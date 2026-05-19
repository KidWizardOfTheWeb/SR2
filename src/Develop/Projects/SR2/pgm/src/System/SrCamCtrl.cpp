#include "Develop/Projects/SR2/pgm/src/System/SrCamCtrl.hpp"
#include "Develop/Projects/SR2/pgm/src/Camera/CamIvs.hpp"
#include "Develop/Projects/SR2/pgm/src/Camera/CameraTbl.hpp"

class clsPlayerTask;

namespace nspCamFilter {
stcPlayerQuakeFilter asQuakeFilter[6];
void (*afFilterFuncs[3])(stcCamFilter*, const stcCamFilter*, u32, clsPlayerTask*);

void NullFF(stcCamFilter* psFilter,
            const stcCamFilter* opsFilter,
            u32 u32Param,
            clsPlayerTask* pcPlayer)
{
}

void QuakeFF(stcCamFilter* psFilter,
             const stcCamFilter* opsFilter,
             u32 u32FParamIdx,
             clsPlayerTask* pcPlayer)
{
}

void PlayerQuakeFF(stcCamFilter* psFilter,
                   const stcCamFilter* opsFilter,
                   u32 u32FParamIdx,
                   clsPlayerTask* pcPlayer)
{
}
} // namespace nspCamFilter

clsSrCamMixer::clsSrCamMixer()
{
}

void clsSrCamMixer::setCamFilter(const stcCamFilter* opsCamFilter, u32 u32Idx)
{
}

void clsSrCamMixer::clearCamFilter()
{
}

void clsSrCamMixer::nextMixData()
{
}

void clsSrCamMixer::setCamCtrlTbl(u32 u32JmpIdx, u32 u32Num, u8 u8NextFlg)
{
}

void clsSrCamMixer::setRegularFilter(stcCamFilter* psFilter)
{
}

void clsSrCamMixer::finishFilter()
{
}

void clsSrCamMixer::mixingFilter()
{
}

void clsSrCamMixer::mixing()
{
}

void clsSrCamMixer::finishMixing()
{
}
