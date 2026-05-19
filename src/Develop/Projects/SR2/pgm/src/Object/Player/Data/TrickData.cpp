#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/TrickData.hpp"
#include "Develop/Projects/SR2/pgm/src/Game/BonusParam.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Common/KickerParam.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/TrickParam.hpp"

f32 f32TrickFailSpeedRate;

namespace nspTrick {

f32 f32CompensationAnglePipe = 0.3490658402442932f;
f32 af32RankUpSpeedRate[9] = {
    0.9375f, 0.875f, 0.875f, 0.75f, 0.8125f, 0.875f, 999.0f, 0.875f, 0.8125f};
f32 af32RankMaxSpeedRate[9] = {
    0.96875f, 0.90625f, 0.90625f, 0.78125f, 0.84375f, 0.90625f, 999.0f, 0.90625f, 0.84375f};
f32 oaf32DistanceTable_Trick[17][7];
f32 oaf32KickerRateTable[9][3] = {{0.0f, 0.6000000238418579f, 0.8500000238418579f},
                                  {0.0f, 0.6000000238418579f, 0.8500000238418579f},
                                  {0.0f, 0.10000000149011612f, 0.20000000298023224f},
                                  {0.0f, 0.75f, 0.8500000238418579f},
                                  {0.0f, 0.44999998807907104f, 0.75f},
                                  {0.0f, 0.44999998807907104f, 0.75f},
                                  {0.0f, 0.75f, 0.8500000238418579f},
                                  {0.0f, 0.6000000238418579f, 0.8500000238418579f},
                                  {0.0f, 0.44999998807907104f, 0.75f}};
f32 oaf32DistanceTable_Spin[7] = {25.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f};
f32 oaf32DistanceTable_Pipe[7] = {25.0f, 25.0f, 25.0f, 25.0f, 25.0f, 25.0f, 25.0f};
stcKickerParam oasKickerParamTable_Ext[10][7];
stcKickerParam oasKickerParamTable[9][7] = {
    {{0.8461538553237915f, 0.00699300691485405f, 0.4615384638309479f},
     {0.9230769276618958f, 0.009324009530246258f, 0.6153846383094788f},
     {0.9230769276618958f, 0.011655011214315891f, 0.7692307829856873f},
     {0.9230769276618958f, 0.011655011214315891f, 0.7692307829856873f},
     {1.076923131942749f, 0.018648019060492516f, 1.2307692766189575f},
     {1.076923131942749f, 0.018648019060492516f, 1.2307692766189575f},
     {1.076923131942749f, 0.02097902074456215f, 1.384615421295166f}},
    {{0.1538461595773697f, 0.02097902074456215f, 1.384615421295166f},
     {0.23076923191547394f, 0.023310022428631783f, 1.5384615659713745f},
     {0.23076923191547394f, 0.023310022428631783f, 1.5384615659713745f},
     {0.23076923191547394f, 0.023310022428631783f, 1.5384615659713745f},
     {0.38461539149284363f, 0.023310022428631783f, 1.5384615659713745f},
     {0.38461539149284363f, 0.023310022428631783f, 1.5384615659713745f},
     {0.38461539149284363f, 0.023310022428631783f, 1.5384615659713745f}},
    {{0.0f, 0.012560386210680008f, 0.5777778029441833f},
     {0.0f, 0.012560386210680008f, 0.5777778029441833f},
     {0.0f, 0.012560386210680008f, 0.5777778029441833f},
     {0.0f, 0.013526570051908493f, 0.6222222447395325f},
     {0.0f, 0.013526570051908493f, 0.6222222447395325f},
     {0.0f, 0.013526570051908493f, 0.6222222447395325f},
     {0.0f, 0.013526570051908493f, 0.6222222447395325f}},
    {{0.0f, 0.012560386210680008f, 0.5777778029441833f},
     {0.0f, 0.012560386210680008f, 0.5777778029441833f},
     {0.0f, 0.012560386210680008f, 0.5777778029441833f},
     {0.0f, 0.012560386210680008f, 0.5777778029441833f},
     {0.0f, 0.013526570051908493f, 0.6222222447395325f},
     {0.0f, 0.013526570051908493f, 0.6222222447395325f},
     {0.0f, 0.013526570051908493f, 0.6222222447395325f}},
    {{0.375f, 0.013414634391665459f, 0.550000011920929f},
     {0.375f, 0.013414634391665459f, 0.550000011920929f},
     {0.5f, 0.015853658318519592f, 0.6499999761581421f},
     {0.5f, 0.015853658318519592f, 0.6499999761581421f},
     {0.625f, 0.017073171213269234f, 0.699999988079071f},
     {0.625f, 0.017073171213269234f, 0.699999988079071f},
     {0.625f, 0.017073171213269234f, 0.699999988079071f}},
    {{0.1875f, 0.004878048785030842f, 0.20000000298023224f},
     {0.1875f, 0.004878048785030842f, 0.20000000298023224f},
     {0.1875f, 0.004878048785030842f, 0.20000000298023224f},
     {0.1875f, 0.004878048785030842f, 0.20000000298023224f},
     {0.1875f, 0.004878048785030842f, 0.20000000298023224f},
     {0.1875f, 0.004878048785030842f, 0.20000000298023224f},
     {0.1875f, 0.004878048785030842f, 0.20000000298023224f}},
    {{0.0f, 0.012560386210680008f, 0.5777778029441833f},
     {0.0f, 0.012560386210680008f, 0.5777778029441833f},
     {0.0f, 0.012560386210680008f, 0.5777778029441833f},
     {0.0f, 0.012560386210680008f, 0.5777778029441833f},
     {0.0f, 0.013526570051908493f, 0.6222222447395325f},
     {0.0f, 0.013526570051908493f, 0.6222222447395325f},
     {0.0f, 0.013526570051908493f, 0.6222222447395325f}},
    {{0.1538461595773697f, 0.02097902074456215f, 1.384615421295166f},
     {0.23076923191547394f, 0.023310022428631783f, 1.5384615659713745f},
     {0.23076923191547394f, 0.023310022428631783f, 1.5384615659713745f},
     {0.23076923191547394f, 0.023310022428631783f, 1.5384615659713745f},
     {0.38461539149284363f, 0.023310022428631783f, 1.5384615659713745f},
     {0.38461539149284363f, 0.023310022428631783f, 1.5384615659713745f},
     {0.38461539149284363f, 0.023310022428631783f, 1.5384615659713745f}},
    {{0.1666666716337204f, 0.02150537632405758f, 0.6666666865348816f},
     {0.20000000298023224f, 0.017391303554177284f, 0.800000011920929f},
     {0.20000000298023224f, 0.017391303554177284f, 0.800000011920929f},
     {0.20000000298023224f, 0.017391303554177284f, 0.800000011920929f},
     {0.20000000298023224f, 0.017391303554177284f, 0.800000011920929f},
     {0.20000000298023224f, 0.017391303554177284f, 0.800000011920929f},
     {0.20000000298023224f, 0.017391303554177284f, 0.800000011920929f}}};

stcFlipKicker oasKickerParam_BF_Default[5];
stcFlipKicker oasKickerParam_BF_Param0[5];
stcFlipKicker oasKickerParam_BF_Param1[5];
stcFlipKicker oasKickerParam_BF_Param2[5];
stcFlipKicker oasKickerParam_BF_Param3[5];
stcFlipKicker oasKickerParam_BF_Param4[5];
stcFlipKicker oasKickerParam_BF_Param5[5];
stcFlipKicker oasKickerParam_BF_Param6[5];
stcFlipKicker oasKickerParam_BF_Param7[5];
stcFlipKicker oasKickerParam_BF_Param8[5];
stcFlipKicker oasKickerParam_BF_Param9[5];
stcFlipKicker oasKickerParam_BF_Param10[5];
stcFlipKicker oasKickerParam_BF_Param11[5];
stcFlipKicker oasKickerParam_BF_Param12[5];
stcFlipKicker oasKickerParam_BF_Param13[5];
stcFlipKicker oasKickerParam_BF_Param14[5];
stcFlipKicker oasKickerParam_BF_Param15[5];
stcFlipKicker oasKickerParam_BF_Param16[5];
stcFlipKicker oasKickerParam_BF_Param17[5];
stcFlipKicker oasKickerParam_BF_Param18[5];
stcFlipKicker oasKickerParam_BF_Param19[5];

stcFlipKicker oasKickerParam_FF_Default[5];
stcFlipKicker oasKickerParam_FF_Param0[5];
stcFlipKicker oasKickerParam_FF_Param1[5];
stcFlipKicker oasKickerParam_FF_Param2[5];
stcFlipKicker oasKickerParam_FF_Param3[5];
stcFlipKicker oasKickerParam_FF_Param4[5];
stcFlipKicker oasKickerParam_FF_Param5[5];
stcFlipKicker oasKickerParam_FF_Param6[5];
stcFlipKicker oasKickerParam_FF_Param7[5];
stcFlipKicker oasKickerParam_FF_Param8[5];
stcFlipKicker oasKickerParam_FF_Param9[5];
stcFlipKicker oasKickerParam_FF_Param10[5];
stcFlipKicker oasKickerParam_FF_Param11[5];
stcFlipKicker oasKickerParam_FF_Param12[5];
stcFlipKicker oasKickerParam_FF_Param13[5];
stcFlipKicker oasKickerParam_FF_Param14[5];

stcFlipKicker* opsKickerParam_FF[16] = {oasKickerParam_FF_Default,
                                        oasKickerParam_FF_Param0,
                                        oasKickerParam_FF_Param1,
                                        oasKickerParam_FF_Param2,
                                        oasKickerParam_FF_Param3,
                                        oasKickerParam_FF_Param4,
                                        oasKickerParam_FF_Param5,
                                        oasKickerParam_FF_Param6,
                                        oasKickerParam_FF_Param7,
                                        oasKickerParam_FF_Param8,
                                        oasKickerParam_FF_Param9,
                                        oasKickerParam_FF_Param10,
                                        oasKickerParam_FF_Param11,
                                        oasKickerParam_FF_Param12,
                                        oasKickerParam_FF_Param13,
                                        oasKickerParam_FF_Param14};

stcFlipKicker* opsKickerParam_BF[21] = {
    oasKickerParam_BF_Default, oasKickerParam_BF_Param0,  oasKickerParam_BF_Param1,
    oasKickerParam_BF_Param2,  oasKickerParam_BF_Param3,  oasKickerParam_BF_Param4,
    oasKickerParam_BF_Param5,  oasKickerParam_BF_Param6,  oasKickerParam_BF_Param7,
    oasKickerParam_BF_Param8,  oasKickerParam_BF_Param9,  oasKickerParam_BF_Param10,
    oasKickerParam_BF_Param11, oasKickerParam_BF_Param12, oasKickerParam_BF_Param13,
    oasKickerParam_BF_Param14, oasKickerParam_BF_Param15, oasKickerParam_BF_Param16,
    oasKickerParam_BF_Param17, oasKickerParam_BF_Param18, oasKickerParam_BF_Param19};

stcBonusParam oasBonusParamTable[9][7] = {{{0.4166666567325592f},
                                           {0.46296295523643494f},
                                           {0.6944444179534912f},
                                           {0.6944444179534912f},
                                           {0.8333333134651184f},
                                           {0.8333333134651184f},
                                           {0.9259259104728699f}},
                                          {{0.4166666567325592f},
                                           {0.46296295523643494f},
                                           {0.6944444179534912f},
                                           {0.6944444179534912f},
                                           {0.8333333134651184f},
                                           {0.8333333134651184f},
                                           {0.9259259104728699f}},
                                          {{0.23148147761821747f},
                                           {0.6944444179534912f},
                                           {0.7407407164573669f},
                                           {0.7407407164573669f},
                                           {0.8333333134651184f},
                                           {0.8333333134651184f},
                                           {0.9259259104728699f}},
                                          {{0.2777777910232544f},
                                           {0.6018518805503845f},
                                           {0.6944444179534912f},
                                           {0.6944444179534912f},
                                           {0.8333333134651184f},
                                           {0.8333333134651184f},
                                           {0.8333333134651184f}},
                                          {{0.46296295523643494f},
                                           {0.5092592835426331f},
                                           {0.5555555820465088f},
                                           {0.6018518805503845f},
                                           {0.6481481194496155f},
                                           {0.6944444179534912f},
                                           {0.7407407164573669f}},
                                          {{0.46296295523643494f},
                                           {0.5092592835426331f},
                                           {0.5555555820465088f},
                                           {0.6018518805503845f},
                                           {0.6481481194496155f},
                                           {0.6944444179534912f},
                                           {0.7407407164573669f}},
                                          {{0.9027777910232544f},
                                           {0.9722222089767456f},
                                           {1.064814805984497f},
                                           {1.064814805984497f},
                                           {1.1574074029922485f},
                                           {1.1574074029922485f},
                                           {1.1574074029922485f}},
                                          {{0.4166666567325592f},
                                           {0.46296295523643494f},
                                           {0.6944444179534912f},
                                           {0.6944444179534912f},
                                           {0.8333333134651184f},
                                           {0.8333333134651184f},
                                           {0.9259259104728699f}},
                                          {{0.46296295523643494f},
                                           {0.5092592835426331f},
                                           {0.5555555820465088f},
                                           {0.6018518805503845f},
                                           {0.6481481194496155f},
                                           {0.6944444179534912f},
                                           {0.7407407164573669f}}};

s32 oas32BingoRingTable[9] = {0, 30, 30, 30, 40, 40, 50, 0, 0};
f32 of32VerticalTrickUpFrame = 60.0f;

stcBonusParam oasTurbBonusParam[17][7];
stcKickerParam oasTurbParamTable[17][7];

} // namespace nspTrick
