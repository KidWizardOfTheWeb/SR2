#include "Develop/Projects/SR2/pgm/src/Camera/CamIvs.hpp"

namespace nspCamIvs {
clsLandDownCamIv cLandDownCamIv;
} // namespace nspCamIvs

clsLandDownCamIv::~clsLandDownCamIv()
{
}

u32 clsLandDownCamIv::PreIv(clsPfCamera* pcCamera)
{
    return 0;
}

u32 clsLandDownCamIv::PostIv(clsPfCamera* pcCamera)
{
    return 0;
}

void clsLandDownCamIv::Init()
{
}
