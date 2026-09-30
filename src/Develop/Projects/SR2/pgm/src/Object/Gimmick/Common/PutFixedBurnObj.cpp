#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutFixedBurnObj.hpp"

f32 clsPutFixedBurnObj_Obj::m_tof32CLIP_DISTx2 = 0.0f;

void clsPutFixedBurnObj_Obj::init()
{
}

void clsPutFixedBurnObj_Obj::setData()
{
}

u8 clsPutFixedBurnObj_Obj::drawObTx(clsModelType_OB_TX_MO_MA* pParam1,
                                    NNS_MATRIX* pParam2,
                                    u32* pParam3,
                                    NNS_MATRIX* pParam4)
{
    return 0;
}

u8 clsPutFixedBurnObj_Obj::drawObTxMo(clsModelType_OB_TX_MO_MA* pParam1,
                                      NNS_MATRIX* psMtxPal,
                                      u32* pParam3,
                                      NNS_MATRIX* psMtxWork)
{
    return 0;
}

u8 clsPutFixedBurnObj_Obj::drawObTxMa(clsModelType_OB_TX_MO_MA* pParam1,
                                      NNS_MATRIX* psMtxPal,
                                      u32* pParam3,
                                      NNS_MATRIX* psMtxWork)
{
    return 0;
}

u8 clsPutFixedBurnObj_Obj::drawObTxMoMa(clsModelType_OB_TX_MO_MA* pParam1,
                                        NNS_MATRIX* psMtxPal,
                                        u32* pParam3,
                                        NNS_MATRIX* psMtxWork)
{
    return 0;
}

u8 clsPutFixedBurnObj_Obj::draw(clsModelType_OB_TX_MO_MA* pParam1,
                                NNS_MATRIX* psMtxPal,
                                u32* pParam3,
                                const NNS_MATRIX* opaNnViewMtx,
                                NNS_MATRIX* psMtxWork,
                                u32 u32Param6)
{
    return 0;
}

void clsPutFixedBurnObj_Task::reset()
{
}

void clsPutFixedBurnObj_Task::execute()
{
}

void clsPutFixedBurnObj_Task::draw()
{
}

nspPackId::enm clsPutFixedBurnObj_Obj::getPackId() const
{
    return nspPackId::PUT_FIXEDBURNOBJ_2093;
}
