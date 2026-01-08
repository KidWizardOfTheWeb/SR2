#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearCtrl.hpp"
// Range: 0x30A090 -> 0x30A1E0
// this: r18
void clsGearCtrl::setUnuseGearLevel(enum enmLevel eLevel /* r2 */) {
    /* anonymous block */ {
        // Range: 0x30A090 -> 0x30A1E0
    }
}


// Range: 0x30A1E0 -> 0x30A238
// this: r2
void clsGearCtrl::changeInitGearModel(enum enmInitBoard eBoard /* r2 */) {
    /* anonymous block */ {
        // Range: 0x30A1E0 -> 0x30A238
    }
}


// Range: 0x30A240 -> 0x30A2B8
// this: r2
unsigned char clsGearCtrl::getEquipsGearFlags() {
    /* anonymous block  {
        // Range: 0x30A240 -> 0x30A2B8
        unsigned char u8Ret; // r2
        signed int s32i; // r11
    }
     */
    clsGear **ppcVar1;
    uint uVar2;
    int iVar3;
    clsGearCtrl *pcVar4;
    uint uVar5;

    uVar2 = 0;
    uVar5 = 0;
    iVar3 = 0;
    do {
        if (this->m_apcEquipsGears[0] != (clsGear *)0x0) {
            pcVar4 = this;
            do {
                if (*(clsGear **)((int)this->m_apcGear + iVar3) == pcVar4->m_apcEquipsGears[0]) {
                    uVar2 = uVar2 | 1 << (uVar5 & 0x1f) & 0xffU;
                    break;
                }
                ppcVar1 = pcVar4->m_apcEquipsGears;
                pcVar4 = (clsGearCtrl *)pcVar4->m_apcGear;
            } while (ppcVar1[1] != (clsGear *)0x0);
        }
        uVar5 = uVar5 + 1; // This changes, but like... the condition next checks this? And this updates? This is cursed.
        iVar3 = iVar3 + 4; // Moves down by 0x4 offset of some other element of apcGear (clsGear)
        if ((int)(uint)this->m_u8MaxGearNum <= (int)uVar5) {
            return (uchar)uVar2; // returns some flags... as uchar (wut)
        }
    } while( true ); // Please tell me this is a thread.
}


// Range: 0x30A2C0 -> 0x30A360
// this: r16
enum enmMotionType clsGearCtrl::getEquipsGearBaseMotionType() {
    ///* anonymous block */ {
        // Range: 0x30A2C0 -> 0x30A360
        //char __FUNCTION__[28]; // @ 0x0066B610
    //}
    enmMotionType eVar1;

    if (this->m_apcEquipsGears[0] == (clsGear *)0x0) {
        scePrintf(0x66b630);
        scePrintf(0x66b650,0x32652565,0x66b680,0x9b1,0x66b610);
        scePrintf(0x66b690,0x66b698);
        scePrintf(0x66b6b0);
        scePrintf(0x66b6d0);
        trap(1);
    }
    eVar1 = (**(code **)(*(int *)this->m_apcEquipsGears[0] + 0x54))();
    return eVar1;
}


// Range: 0x30A360 -> 0x30A484
// this: r16
enum enmGearType clsGearCtrl::getEquipsGearType() {
    /* anonymous block */ {
        // Range: 0x30A360 -> 0x30A484
        char __FUNCTION__[18]; // @ 0x0066B5F0
    }
}


// Range: 0x30A490 -> 0x30A4E0
// this: r2
void clsGearCtrl::behavior_NodeMtx() {
    /* anonymous block */ {
        // Range: 0x30A490 -> 0x30A4E0
    }
}


// Range: 0x30A4F0 -> 0x30A540
// this: r2
void clsGearCtrl::behavior() {
    /*
     anonymous block  {
        // Range: 0x30A4F0 -> 0x30A540
    }
    */
    clsGear *pcVar1;

    if (this->m_apcEquipsGears[0] != (clsGear *)0x0) {
        pcVar1 = this->m_apcEquipsGears[0];
        while( true ) {
            // pcVar1->m_sActionRot;
            (**(code **)(*(int *)pcVar1 + 0x30))();
            if (this->m_apcEquipsGears[1] == (clsGear *)0x0) break;
            pcVar1 = this->m_apcEquipsGears[1];
            this = (clsGearCtrl *)this->m_apcGear;
        }
    }
    return;
}


// Range: 0x30A550 -> 0x30A6F8
// this: r17
void clsGearCtrl::registGearRideEffect(unsigned char bIsRide /* r16 */) {
    /* anonymous block */ {
        // Range: 0x30A550 -> 0x30A6F8
    }
}


// Range: 0x30A700 -> 0x30AA5C
// this: r21
void clsGearCtrl::registGearChangeEffect(enum enmLevel eLevel /* r20 */, enum enmGearType eOldType /* r22 */) {
    /* anonymous block */ {
        // Range: 0x30A700 -> 0x30AA5C
        enum enmLevel eLevelTemp; // r19
        enum enmGearType eGearType; // r2
    }
}


// Range: 0x30AA60 -> 0x30ACEC
// this: r20
enum enmLevel clsGearCtrl::searchGearFromGearParamType(enum enmComGearChangeType eType /* r22 */) {
    /* anonymous block */ {
        // Range: 0x30AA60 -> 0x30ACEC
        class clsGear * pcGear; // r19
        signed int s32GearLevel; // r18
        signed int s32HaveRingNum; // r2
        enum enmLevel eRetLevel; // r30
        unsigned int u32Ability; // r23
        class clsGear * * pacEquipsGears; // r3
        enum enmGear eGearType; // r2
        enum enmGear eGearType; // r2
        enum enmGear eGearType; // r2
        char __FUNCTION__[28]; // @ 0x0066B5D0
    }
}


// Range: 0x30AD00 -> 0x30AD3C
// this: r16
void clsGearCtrl::stopMonumentFlySe() {
    /* anonymous block */ {
        // Range: 0x30AD00 -> 0x30AD3C
    }
}


// Range: 0x30AD40 -> 0x30AD78
// this: r16
void clsGearCtrl::playMonumentFlySe() {
    /* anonymous block */ {
        // Range: 0x30AD40 -> 0x30AD78
    }
}


// Range: 0x30AD80 -> 0x30B56C
// this: r16
void clsGearCtrl::controlMotion() {
    /* anonymous block */ {
        // Range: 0x30AD80 -> 0x30B56C
        enum enPlayerCtrlType ePlayerCtrlType; // r2
        unsigned int ou32Se_WaterStep[2]; // r29+0xA8
        class stcData * psPrfm; // r2
        float f32MotionRate; // r29+0xB0
        signed int s32BlendMotionNo; // r23
        signed int s32MotionNo; // r22
    }
}


// Range: 0x30B570 -> 0x30BAF4
// this: r18
void clsGearCtrl::draw(float (* psGearMtx)[4][4] /* r17 */, unsigned int u32AddDrawFlagI /* r16 */) {
    /* anonymous block */ {
        // Range: 0x30B570 -> 0x30BAF4
        char __FUNCTION__[5]; // @ 0x0066B5C0
    }
}


// Range: 0x30BB00 -> 0x30C0A4
// this: r18
void clsGearCtrl::updateAction() {
    /* anonymous block */ {
        // Range: 0x30BB00 -> 0x30C0A4
        float f32SpeedRate; // r3
        unsigned char u8IcsCtrl; // r2
        char __FUNCTION__[13]; // @ 0x0066B5B0
    }
}


// Range: 0x30C0B0 -> 0x30C1D0
// this: r18
void clsGearCtrl::updateDraw2DData() {
    /* anonymous block */ {
        // Range: 0x30C0B0 -> 0x30C1D0
        enum enmLevel ePrevLv; // r2
        float f32FrameAdd; // r20
        signed int s32i; // r17
    }
}


// Range: 0x30C1D0 -> 0x30C3B4
// this: r19
void clsGearCtrl::updateLockFlag() {
    /* anonymous block */ {
        // Range: 0x30C1D0 -> 0x30C3B4
        class stcCtrlData * psCtrlData; // r2
        unsigned int u32EquipsFlg; // r2
        unsigned char * pbIsLocked; // r9
        unsigned int u32i; // r8
        unsigned int u32Num; // r2
        signed int s32i; // r18
        unsigned char u8LockFlags; // r2
        char __FUNCTION__[15]; // @ 0x0066B530
    }
}


// Range: 0x30C3C0 -> 0x30C460
// this: r17
void clsGearCtrl::cancelGDive() {
    /* anonymous block */ {
        // Range: 0x30C3C0 -> 0x30C460
    }
}


// Range: 0x30C460 -> 0x30C5EC
// this: r18
unsigned char clsGearCtrl::requestGearRide_HideActiveGear(unsigned char u8IsRide /* r17 */, float f32LinkFrame /* r20 */, signed int eSuccessActionType /* r16 */) {
    /* anonymous block */ {
        // Range: 0x30C460 -> 0x30C5EC
        enum enmMotion toeMotion[2]; // @ 0x0066B5A8
        enum enmMotion toeMotion[2]; // @ 0x0066B598
    }
}


// Range: 0x30C5F0 -> 0x30C60C
// this: r2
unsigned char clsGearCtrl::requestGearRide_AttackAction(unsigned char u8IsRide /* r2 */, float f32LinkFrame /* r29 */, signed int eSuccessActionType /* r2 */) {
    /* anonymous block */ {
        // Range: 0x30C5F0 -> 0x30C60C
        enum enmMotion toeMotion[2]; // @ 0x0066B5A0
    }
}


// Range: 0x30C610 -> 0x30C6EC
// this: r18
unsigned char clsGearCtrl::requestGearRide(unsigned char u8IsRide /* r17 */, float f32LinkFrame /* r20 */, signed int eSuccessActionType /* r16 */) {
    /* anonymous block */ {
        // Range: 0x30C610 -> 0x30C6EC
    }
}


// Range: 0x30C6F0 -> 0x30C9F8
// this: r16
unsigned char clsGearCtrl::rideGear(unsigned char u8IsRide /* r21 */, float f32LinkFrame /* r20 */, signed int eSuccessActionType /* r20 */, enum enmMotion eMotion /* r19 */) {
    /* anonymous block */ {
        // Range: 0x30C6F0 -> 0x30C9F8
        enum enmChangeRes eRes; // r2
    }
}


// Range: 0x30CA00 -> 0x30CA50
// this: r2
void clsGearCtrl::requestGearChangeForGhost(unsigned char u8ChangeNo /* r2 */) {
    /* anonymous block */ {
        // Range: 0x30CA00 -> 0x30CA50
    }
}


// Range: 0x30CA50 -> 0x30CB14
// this: r17
unsigned char clsGearCtrl::requestGearChange() {
    /* anonymous block */ {
        // Range: 0x30CA50 -> 0x30CB14
        enum enmLevel eLevel; // r2
        char __FUNCTION__[18]; // @ 0x0066B580
    }
}


// Range: 0x30CB20 -> 0x30CCC0
// this: r2
enum enmLevel clsGearCtrl::calcChageGearLevel() {
    /* anonymous block */ {
        // Range: 0x30CB20 -> 0x30CCC0
        signed int s32i; // r7
        enum enmLevel eRet; // r16
        char __FUNCTION__[19]; // @ 0x0066B560
    }
}


// Range: 0x30CCC0 -> 0x30D064
// this: r21
void clsGearCtrl::equipsGear(unsigned char u8GearLevel /* r20 */) {
    /* anonymous block */ {
        // Range: 0x30CCC0 -> 0x30D064
        class clsGear * pcGear; // r19
        enum enmCtrlMode eChangeMode; // r2
        enum enmGearType eOldType; // r22
        char __FUNCTION__[11]; // @ 0x0066B550
    }
}


// Range: 0x30D080 -> 0x30D498
// this: r17
enum enmCtrlMode clsGearCtrl::_equipsGear(unsigned char u8GearLevel /* r16 */) {
    /* anonymous block */ {
        // Range: 0x30D080 -> 0x30D498
        signed int s32i; // r20
        enum enmCtrlMode eRes; // r21
        enum enmSelectType eSelectType; // r2
        unsigned int u32i; // r6
        unsigned int u32Num; // r2
        char __FUNCTION__[12]; // @ 0x0066B540
    }
}


// Range: 0x30D4A0 -> 0x30D4A8
// this: r2
class clsGearBasePrototype * clsGearCtrl::getEquipsPrototypeGear() {
    /* anonymous block */ {
        // Range: 0x30D4A0 -> 0x30D4A8
    }
}


// Range: 0x30D4B0 -> 0x30D6E4
// this: r18
void clsGearCtrl::updatePrfm() {
    /* anonymous block */ {
        // Range: 0x30D4B0 -> 0x30D6E4
        signed int s32i; // r6
        class clsGear * * ppcEquipsGears; // r17
        class stcAddPrfm & rsGearPrfm; // r16
        unsigned int u32Ability; // r2
    }
}


// Range: 0x30D700 -> 0x30DA58
// this: r18
void clsGearCtrl::copyGearLv(class clsGearCtrl * pcPlayerGearCtrl /* r17 */) {
    /* anonymous block */ {
        // Range: 0x30D700 -> 0x30DA58
        class clsGear * * ppcEquipsGears; // r16
        class clsGear * * ppGear; // r2
        signed int s32MaxGear; // r2
        signed int s32i; // r2
        class clsGearAngelOrDevilChange * pcNextPlayerGear; // r2
        unsigned int u32Num; // r2
        unsigned int u32i; // r19
        char __FUNCTION__[11]; // @ 0x0066B520
    }
}


// Range: 0x30DA60 -> 0x30DD60
// this: r18
void clsGearCtrl::init() {
    /* anonymous block */ {
        // Range: 0x30DA60 -> 0x30DD60
        signed int s32MaxGear; // r2
        signed int s32i; // r2
        unsigned int u32n; // r16
        char __FUNCTION__[5]; // @ 0x0066B518
    }
}


// Range: 0x30DD60 -> 0x30E29C
// this: r21
void clsGearCtrl::setGearModels() {
    /* anonymous block */ {
        // Range: 0x30DD60 -> 0x30E29C
        unsigned int u32i; // r19
        class _GearModelInfo & rsModelInfo; // r18
        unsigned short u16CtrlNoTmp; // r2
        unsigned int u32SetCnt; // r29+0xB0
        unsigned int u32ShadowOffset; // r30
        unsigned int u32i; // r6
        enum enmGearType eGearType; // r2
        class clsGearAngelOrDevilChange * pcGear; // r2
        enum enmGearType eBaseType; // r2
        char __FUNCTION__[14]; // @ 0x0066B508
    }
}


// Range: 0x30E2A0 -> 0x3108D8
// this: r18
void clsGearCtrl::createGear() {
    /* anonymous block */ {
        // Range: 0x30E2A0 -> 0x3108D8
        signed int s32i; // r21
        char __FUNCTION__[11]; // @ 0x0066B4F8
    }
}


// Range: 0x3117C0 -> 0x311888
// this: r16
clsGearCtrl::~clsGearCtrl() {
    /* anonymous block */ {
        // Range: 0x3117C0 -> 0x311888
        signed int i; // r18
    }
}


// Range: 0x311930 -> 0x311B3C
// this: r17
clsGearCtrl::clsGearCtrl(class clsPlayerTask * pcPlayer /* r2 */, enum enmGearCtrl eCtrlNo /* r16 */, unsigned int u32EquipsGears /* r2 */) {
    /* anonymous block */ {
        // Range: 0x311930 -> 0x311B3C
        enum enmGear * peGear; // r6
        unsigned int u32i; // r5
        char __FUNCTION__[5]; // @ 0x0066B4F0
    }
}
