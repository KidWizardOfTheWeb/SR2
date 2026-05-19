#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/SurvivalRelay/SurvivalWalkRunLine.hpp"

namespace {
static s32 tos32SpeedDownFrame;
static s32 tos32SpeedDownFrameDiv = 10;
} // namespace

f32 clsSurvivalRelayWalkRunLine_Obj::m_tof32CLIP_DISTx2 = 0.0f;

void clsSurvivalRelayWalkRunLine_Obj::reset()
{
}

void clsSurvivalRelayWalkRunLine_Obj::execute()
{
}

void clsSurvivalRelayWalkRunLine_Obj::draw(clsModelType_OB_TX_MO_MA* pcModelAT,
                                           _NNS_TEXLIST* psTexAT,
                                           clsModelType_OB_TX_MO* pcModelLine,
                                           _NNS_TEXLIST* psTexLine,
                                           f32 (*pParam5)[4][4],
                                           u32* psNodeStat,
                                           const f32 (*pParam7)[4][4],
                                           f32 (*pParam8)[4][4],
                                           u32 u32Param9)
{
}

clsSurvivalRelayWalkRunLine_Obj::~clsSurvivalRelayWalkRunLine_Obj()
{
}
