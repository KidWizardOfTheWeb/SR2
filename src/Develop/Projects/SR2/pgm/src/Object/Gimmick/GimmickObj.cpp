#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"

void clsGimmickObj::setSetData(const stcSetDataDetail& orsSetDataDetailI)
{
    m_psSetDataDetail = &orsSetDataDetailI;
    setSetData();
    setData();
    createData();
}

void clsGimmickObj::setSetData()
{
    setPosition(
        m_psSetDataDetail->sPosVec.x, m_psSetDataDetail->sPosVec.y, m_psSetDataDetail->sPosVec.z);
    setRotate(
        m_psSetDataDetail->sRotVec.x, m_psSetDataDetail->sRotVec.y, m_psSetDataDetail->sRotVec.z);
    nnCopyVector(&m_sScaleVec, &m_psSetDataDetail->sScaleVec);
    m_u32Attr = m_psSetDataDetail->u32Attr;
    setPortalNo(m_psSetDataDetail->u8PortalType);
}

void clsGimmickObj::setAttribute(u32 ou32Attr)
{
    m_u32Attr = ou32Attr;
}

void clsGimmickObj::drawCollision()
{
}
