#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/PutFixedBurnObj.hpp"

f32 clsPutFixedBurnObj_Obj::m_tof32CLIP_DISTx2 = 0.0f;

void clsPutFixedBurnObj_Obj::init()
{
}

void clsPutFixedBurnObj_Obj::setData()
{
}

u8 clsPutFixedBurnObj_Obj::drawObTx(clsModelType_OB_TX_MO_MA* pParam1,
                                    f32 (*pParam2)[4][4],
                                    u32* pParam3,
                                    f32 (*pParam4)[4][4])
{
    return 0;
}

u8 clsPutFixedBurnObj_Obj::drawObTxMo(clsModelType_OB_TX_MO_MA* pParam1,
                                      f32 (*psMtxPal)[4][4],
                                      u32* pParam3,
                                      f32 (*psMtxWork)[4][4])
{
    return 0;
}

u8 clsPutFixedBurnObj_Obj::drawObTxMa(clsModelType_OB_TX_MO_MA* pParam1,
                                      f32 (*psMtxPal)[4][4],
                                      u32* pParam3,
                                      f32 (*psMtxWork)[4][4])
{
    return 0;
}

u8 clsPutFixedBurnObj_Obj::drawObTxMoMa(clsModelType_OB_TX_MO_MA* pParam1,
                                        f32 (*psMtxPal)[4][4],
                                        u32* pParam3,
                                        f32 (*psMtxWork)[4][4])
{
    return 0;
}

u8 clsPutFixedBurnObj_Obj::draw(clsModelType_OB_TX_MO_MA* pParam1,
                                f32 (*psMtxPal)[4][4],
                                u32* pParam3,
                                const f32 (*opaNnViewMtx)[4][4],
                                f32 (*psMtxWork)[4][4],
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

clsPutFixedBurnObj_Obj::clsPutFixedBurnObj_Obj() : clsGimmickObj()
{
}

clsPutFixedBurnObj_Obj::~clsPutFixedBurnObj_Obj()
{
}

nspPackId::enm clsPutFixedBurnObj_Obj::getPackId() const
{
    return nspPackId::PUT_FIXEDBURNOBJ_2093;
}
