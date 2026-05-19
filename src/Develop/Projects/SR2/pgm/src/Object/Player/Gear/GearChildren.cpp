#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearChildren.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Data/GearControlData.hpp"

// void clsInitialBoard::drawNonAction(f32 (* psGearMtx)[4][4] /* r20 */, f32 f32Alpha /* r20 */,
// u32 u32AddDrawFlagI /* r19 */) {
//     /* anonymous block */ {
//         // Range: 0x350740 -> 0x35089C
//         class NNS_OBJECT * psObject; // r18
//         u32 * psNodeStat; // r17
//         u32 u32DrawFlag; // r16
//     }
// }

void clsInitialBoard::drawNonAction(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlagI)
{
}

// void clsGearMag::clearChangeActionParam() {
//     /* anonymous block */ {
//         // Range: 0x350710 -> 0x350740
//         class NNS_NODE * psNode; // r2
//     }
// }

void clsGearMag::clearChangeActionParam()
{
}

// void clsGearMag::setHideNodeStatus(u32 * psNodeStat /* r16 */) {
//     /* anonymous block */ {
//         // Range: 0x3506D0 -> 0x350708
//     }
// }

void clsGearMag::setHideNodeStatus(u32* psNodeStat)
{
}

// void clsGearMag::behavior() {
//     /* anonymous block */ {
//         // Range: 0x350630 -> 0x3506D0
//     }
// }

void clsGearMag::behavior()
{
}

// void clsGearMag::draw(f32 (* psGearMtx)[4][4] /* r2 */, f32 f32Alpha /* r20 */, u32
// u32AddDrawFlagI /* r20 */) {
//     /* anonymous block */ {
//         // Range: 0x350420 -> 0x350628
//         f32 sMtx[4][4]; // r29+0x80
//         class NNS_OBJECT * psObject; // r19
//         u32 * psNodeStat; // r18
//         f32 (* psMtxPal)[4][4]; // r17
//         u32 u32DrawFlag; // r16
//     }
// }

void clsGearMag::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlagI)
{
}

// void clsGearThrottle::clearChangeActionParam() {
//     /* anonymous block */ {
//         // Range: 0x3503C0 -> 0x350414
//         class clsGearCtrl * pcGearCtrl; // r2
//         u32 u32GearNum; // r7
//         class clsGearSpThrottle * pcGear; // r2
//     }
// }

void clsGearThrottle::clearChangeActionParam()
{
}

// void clsGearThrottle::behavior() {
//     /* anonymous block */ {
//         // Range: 0x350290 -> 0x3503B4
//         u32 u32GearNum; // r2
//         u32 u32RingNum; // r2
//         u32 u32Level; // r10
//         u32 u32i; // r9
//         class clsGearSpThrottle * pcGear; // r2
//     }
// }

void clsGearThrottle::behavior()
{
}

// void clsGearReserveTank::clearChangeActionParam() {
//     /* anonymous block */ {
//         // Range: 0x350250 -> 0x350288
//         u32 u32Num; // r6
//         u8 * pbUsed; // r2
//     }
// }

void clsGearReserveTank::clearChangeActionParam()
{
}

// void clsGearReserveTank::setHideNodeStatus(u32 * psNodeStat /* r2 */) {
//     /* anonymous block */ {
//         // Range: 0x350210 -> 0x35024C
//     }
// }

void clsGearReserveTank::setHideNodeStatus(u32* psNodeStat)
{
}

// void clsGearAngelOrDevil::clearChangeActionParam() {
//     /* anonymous block */ {
//         // Range: 0x3501D0 -> 0x350208
//         class clsGearAngelOrDevilChange * pcGear; // r2
//     }
// }

void clsGearAngelOrDevil::clearChangeActionParam()
{
}

// void clsGearAngelOrDevil::behavior() {
//     /* anonymous block */ {
//         // Range: 0x3500E0 -> 0x3501C8
//         class clsGearAngelOrDevilChange * pcGear; // r2
//     }
// }

void clsGearAngelOrDevil::behavior()
{
}

// void clsGearAngelOrDevilChange::behavior() {
//     /* anonymous block */ {
//         // Range: 0x34FFF0 -> 0x3500D4
//     }
// }

void clsGearAngelOrDevilChange::behavior()
{
}

// void clsGearAngelOrDevilChange::eventGearChange() {
//     /* anonymous block */ {
//         // Range: 0x34FF60 -> 0x34FFEC
//     }
// }

void clsGearAngelOrDevilChange::eventGearChange()
{
}

// f32 clsGearAngelOrDevilChange::getDraw2DRate() {
//     /* anonymous block */ {
//         // Range: 0x34FF30 -> 0x34FF58
//     }
// }

f32 clsGearAngelOrDevilChange::getDraw2DRate() const
{
    return 0.0f;
}

// void clsGearSpTank::eventGearChange() {
//     /* anonymous block */ {
//         // Range: 0x34FED0 -> 0x34FF30
//     }
// }

void clsGearSpTank::eventGearChange()
{
}

// void clsGearSpMagBarrier::eventGearChange() {
//     /* anonymous block */ {
//         // Range: 0x34FEB0 -> 0x34FEC8
//     }
// }

void clsGearSpMagBarrier::eventGearChange()
{
}

// void clsGearSpViewTrap::eventGearChange() {
//     /* anonymous block */ {
//         // Range: 0x34FB40 -> 0x34FEA4
//         class clsPlayerTask * * apcPlayer; // r18
//         u32 u32i; // r17
//         class clsPlayerTask * pcPlayer; // r2
//     }
// }

void clsGearSpViewTrap::eventGearChange()
{
}

void clsGearSpCtrlTrap::eventGearChange()
{
}

// void clsGearSpCtrlTrap::eventGearChange() {
//     /* anonymous block */ {
//         // Range: 0x34F7D0 -> 0x34FB34
//         class clsPlayerTask * * apcPlayer; // r18
//         u32 u32i; // r17
//         class clsPlayerTask * pcPlayer; // r2
//     }
// }

void clsGearSpSpeedTrap::eventGearChange()
{
}

// void clsGearSpSpeedTrap::eventGearChange() {
//     /* anonymous block */ {
//         // Range: 0x34F460 -> 0x34F7C4
//         class clsPlayerTask * * apcPlayer; // r18
//         u32 u32i; // r17
//         class clsPlayerTask * pcPlayer; // r2
//     }
// }

// void clsGearSpThrottle::eventGearChange() {
//     /* anonymous block */ {
//         // Range: 0x34F410 -> 0x34F454
//     }
// }

void clsGearSpThrottle::eventGearChange()
{
}

// class stcAddPrfm & clsGearSpThrottle::getPrfm() {
//     /* anonymous block */ {
//         // Range: 0x34F3D0 -> 0x34F410
//         class stcAddPrfm * oasPrfm[3]; // r29
//     }
// }

stcAddPrfm& clsGearSpThrottle::getPrfm() const
{
    return m_rsGearPrfm;
}

// f32 clsGearSpThrottle::getDraw2DRate() {
//     /* anonymous block */ {
//         // Range: 0x34F3A0 -> 0x34F3C8
//     }
// }

f32 clsGearSpThrottle::getDraw2DRate() const
{
    return 0.0f;
}

// void clsGearSpThrottle::copy(class clsGearSpThrottle * pcGear /* r2 */) {
//     /* anonymous block */ {
//         // Range: 0x34F370 -> 0x34F394
//     }
// }

void clsGearSpThrottle::copy(const clsGearSpThrottle* pcGear)
{
}

// void clsGearSpGpInfinity::draw(f32 (* psGearMtx)[4][4] /* r2 */, f32 f32Alpha /* r20 */, u32
// u32AddDrawFlagI /* r20 */) {
//     /* anonymous block */ {
//         // Range: 0x34F0D0 -> 0x34F364
//         f32 sMtx[4][4]; // r29+0xC0
//         f32 sTrsMtx[4][4]; // r29+0x80
//         class NNS_OBJECT * psObject; // r19
//         u32 * psNodeStat; // r18
//         u32 u32DrawFlag; // r17
//     }
// }

void clsGearSpGpInfinity::draw(const f32 (*psGearMtx)[4][4], f32 f32Alpha, u32 u32AddDrawFlagI)
{
}
