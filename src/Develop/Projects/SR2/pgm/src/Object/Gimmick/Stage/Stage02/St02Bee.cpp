#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage02/St02Bee.hpp"

namespace {
static NNS_VECTORFAST toasPointVecFast_0[4] = {{-111.8f, -237.2f, 581.7f, 1.0f},
                                               {-119.6f, -244.7f, 567.0f, 1.0f},
                                               {-127.9f, -239.4f, 600.1f, 1.0f},
                                               {-112.1f, -251.5f, 602.5f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_1[5] = {{-142.3f, -243.5f, 545.8f, 1.0f},
                                               {-139.1f, -237.1f, 530.6f, 1.0f},
                                               {-134.8f, -244.6f, 520.6f, 1.0f},
                                               {-130.0f, -250.1f, 511.6f, 1.0f},
                                               {-128.6f, -237.0f, 511.6f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_2[4] = {{134.0f, -0.2f, -470.3f, 1.0f},
                                               {123.6f, -8.0f, -482.5f, 1.0f},
                                               {131.1f, -4.6f, -453.3f, 1.0f},
                                               {111.7f, -7.7f, -503.9f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_3[5] = {{109.8f, -37.2f, -504.1f, 1.0f},
                                               {103.9f, -41.4f, -508.1f, 1.0f},
                                               {112.5f, -38.8f, -503.8f, 1.0f},
                                               {120.1f, -37.7f, -502.1f, 1.0f},
                                               {125.5f, -36.6f, -502.8f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_4[4] = {{56.3f, -38.1f, -409.9f, 1.0f},
                                               {51.6f, -27.9f, -417.5f, 1.0f},
                                               {65.1f, -28.0f, -405.5f, 1.0f},
                                               {56.4f, -32.4f, -432.9f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_5[5] = {{52.1f, -6.0f, -741.0f, 1.0f},
                                               {45.9f, -6.8f, -757.5f, 1.0f},
                                               {60.6f, 9.3f, -731.0f, 1.0f},
                                               {40.1f, 6.6f, -740.3f, 1.0f},
                                               {90.7f, -12.4f, -730.1f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_6[4] = {{86.2f, -32.6f, -648.8f, 1.0f},
                                               {95.9f, -12.1f, -666.2f, 1.0f},
                                               {108.6f, -12.6f, -666.2f, 1.0f},
                                               {90.1f, -24.0f, -642.9f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_7[5] = {{41.1f, -0.5f, -741.0f, 1.0f},
                                               {65.9f, -6.8f, -757.5f, 1.0f},
                                               {74.6f, 9.3f, -761.0f, 1.0f},
                                               {89.1f, 6.6f, -760.3f, 1.0f},
                                               {107.7f, -12.4f, -719.1f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_8[5] = {{-131.3f, -7.6f, -100.0f, 1.0f},
                                               {-113.3f, 4.4f, -100.3f, 1.0f},
                                               {-139.1f, 4.0f, -100.4f, 1.0f},
                                               {-110.7f, -8.9f, -100.9f, 1.0f},
                                               {-124.8f, 14.9f, -100.2f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_9[5] = {{-72.8f, -12.8f, -80.0f, 1.0f},
                                               {-66.5f, 3.5f, -78.2f, 1.0f},
                                               {-98.5f, -0.7f, -90.5f, 1.0f},
                                               {-111.4f, -7.3f, -85.8f, 1.0f},
                                               {-71.3f, 9.3f, -92.6f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_10[5] = {{-98.9f, 34.2f, -412.2f, 1.0f},
                                                {-111.0f, 35.0f, -422.5f, 1.0f},
                                                {-127.3f, 31.4f, -433.1f, 1.0f},
                                                {-110.1f, 31.9f, -448.5f, 1.0f},
                                                {-121.8f, 29.6f, -446.6f, 1.0f}};
static NNS_VECTORFAST toasPointVecFast_11[5] = {{-137.7f, 29.1f, -493.4f, 1.0f},
                                                {-130.8f, 36.1f, -501.5f, 1.0f},
                                                {-125.2f, 31.5f, -499.5f, 1.0f},
                                                {-107.3f, 26.6f, -513.9f, 1.0f},
                                                {-88.5f, 22.5f, -509.7f, 1.0f}};
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
static u32 toau32PointNumTable[12] = {4, 5, 4, 5, 4, 5, 4, 5, 5, 5, 5, 5};
} // namespace

clsBeeRobo_Task::clsBeeRobo_Task(u32 u32ObjectAreaNum)
    : clsSingleModelGimmick_Task(u32ObjectAreaNum, 0)
{
}

void clsBeeRobo_Task::reset()
{
}

void clsBeeRobo_Task::execute()
{
}

void clsBeeRobo_Task::draw()
{
}
