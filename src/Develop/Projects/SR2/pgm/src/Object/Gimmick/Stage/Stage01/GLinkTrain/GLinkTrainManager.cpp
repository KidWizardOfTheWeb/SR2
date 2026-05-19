#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage01/GLinkTrain/GLinkTrainManager.hpp"

u32 clsGLinkTrainManager_Object::t_oau32MissionFlg[2] = {98, 162};

void clsGLinkTrainManager_Object::execute()
{
}

void clsGLinkTrainManager_Object::draw(NNS_OBJECT* psObject,
                                       f32 (*psMtxPal)[4][4],
                                       u32* psNodeStat,
                                       const f32 (*opaNnViewMtx)[4][4],
                                       f32 (*psMtxWork)[4][4],
                                       u32 u32ViewNo)
{
}

void clsGLinkTrainManager_Object::reset()
{
}

void clsGLinkTrainManager_Object::startGravityAction(clsPlayerTask* pcPlayer)
{
}

void clsGLinkTrainManager_Object::setData()
{
}

void clsGLinkTrainManager_Object::createData()
{
}

void clsGLinkTrainManager_Object::destroyData()
{
}

void clsGLinkTrainManager_Object::start()
{
}

void clsGLinkTrainManager_Object::drawCollision()
{
}

nspPackId::enm clsGLinkTrainManager_Object::getPackId() const
{
    return nspPackId::ST01_GLINK_TRAIN_11200;
}

u32 clsGLinkTrainManager_Object::getMultiDrawNum() const
{
    return m_s32TrainNum;
}
