#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Butterfly.hpp"

namespace {
static NNS_VECTORFAST toasPointVecFast_0[4] = {{-7.1f, 15.6f, 28.6f, 1.0f},
                                               {-13.2f, 10.9f, 36.4f, 1.0f},
                                               {-13.4f, 14.6f, 40.3f, 1.0f},
                                               {-16.8f, 16.6f, 33.2f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_1[4] = {{7.8f, 18.1f, 39.7f, 1.0f},
                                               {17.0f, 16.6f, 34.4f, 1.0f},
                                               {10.5f, 13.0f, 37.3f, 1.0f},
                                               {11.1f, 14.6f, 29.9f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_2[4] = {{-13.7f, 11.0f, 100.1f, 1.0f},
                                               {-10.6f, 13.4f, 106.6f, 1.0f},
                                               {-11.7f, 12.2f, 121.2f, 1.0f},
                                               {-8.7f, 15.0f, 106.1f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_3[4] = {{10.3f, 14.7f, 53.9f, 1.0f},
                                               {13.9f, 11.8f, 61.2f, 1.0f},
                                               {14.6f, 13.8f, 47.7f, 1.0f},
                                               {14.0f, 11.7f, 65.7f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_4[4] = {{-4.4f, 14.9f, 38.2f, 1.0f},
                                               {-12.7f, 9.1f, 37.6f, 1.0f},
                                               {-14.7f, 13.3f, 44.0f, 1.0f},
                                               {-14.7f, 14.1f, 43.6f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_5[4] = {{-10.3f, 15.7f, 101.4f, 1.0f},
                                               {-16.0f, 11.8f, 98.3f, 1.0f},
                                               {-11.3f, 17.2f, 99.9f, 1.0f},
                                               {-8.5f, 10.8f, 100.8f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_6[4] = {{-27.0f, -242.6f, 583.1f, 1.0f},
                                               {-11.5f, -248.5f, 575.3f, 1.0f},
                                               {-35.5f, -241.6f, 582.0f, 1.0f},
                                               {-50.4f, -248.7f, 579.6f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_7[4] = {{-91.6f, -251.4f, 540.2f, 1.0f},
                                               {-94.6f, -255.1f, 546.6f, 1.0f},
                                               {-93.3f, -255.8f, 538.3f, 1.0f},
                                               {-94.1f, -248.1f, 537.3f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_8[4] = {{-222.2f, -237.7f, 569.3f, 1.0f},
                                               {-222.6f, -236.9f, 556.7f, 1.0f},
                                               {-226.5f, -250.6f, 573.9f, 1.0f},
                                               {-226.5f, -254.2f, 527.3f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_9[4] = {{-161.6f, -221.9f, 522.0f, 1.0f},
                                               {-149.2f, -220.6f, 528.9f, 1.0f},
                                               {-168.4f, -220.3f, 530.8f, 1.0f},
                                               {-163.2f, -228.8f, 525.1f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_10[4] = {{-47.2f, -239.7f, 578.9f, 1.0f},
                                                {-52.5f, -244.7f, 585.8f, 1.0f},
                                                {-39.3f, -251.1f, 579.4f, 1.0f},
                                                {-24.4f, -253.8f, 580.8f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_11[4] = {{-229.1f, -244.2f, 536.7f, 1.0f},
                                                {-228.2f, -241.0f, 554.2f, 1.0f},
                                                {-231.5f, -252.1f, 552.8f, 1.0f},
                                                {-230.1f, -245.0f, 549.3f, 1.0f}};
static NNS_VECTORFAST* toapsPointTable[12] = {toasPointVecFast_0,
                                              toasPointVecFast_1,
                                              toasPointVecFast_2,
                                              toasPointVecFast_3,
                                              toasPointVecFast_4,
                                              toasPointVecFast_5,
                                              toasPointVecFast_6,
                                              toasPointVecFast_7,
                                              toasPointVecFast_8,
                                              toasPointVecFast_9,
                                              toasPointVecFast_10,
                                              toasPointVecFast_11};
static u32 toau32PointNumTable[12] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
} // namespace

clsButterfly_Task::clsButterfly_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task<clsButterfly_Task, clsButterfly_Obj, clsModelType_OB_TX_MO>(
          u32ObjectAreaNum, 0)
{
}

void clsButterfly_Task::reset()
{
}

void clsButterfly_Task::execute()
{
}

void clsButterfly_Task::draw()
{
}
