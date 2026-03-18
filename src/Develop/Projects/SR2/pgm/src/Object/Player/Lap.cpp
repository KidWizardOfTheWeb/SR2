#include "Develop/Projects/SR2/pgm/src/Object/Player/Lap.hpp"

// Range: 0x33ED10 -> 0x33EDA4
// this: r20
void clsLap::copyPlayerLapTime(class clsPlayerTask * pcPlayer /* r2 */) {

}


// Range: 0x33EDB0 -> 0x33EEC0
// this: r17
void clsLap::copyLapNum(class clsLap & rcSrcLap /* r16 */) {
    /* anonymous block */ {
        // Range: 0x33EDB0 -> 0x33EEC0
        signed int s32Lap; // r2
    }
}


// Range: 0x33EEC0 -> 0x33F05C
// this: r17
void clsLap::setRecordTime(unsigned char u8LapNo /* r2 */, unsigned int u32PenaltyCount /* r2 */) {
    /* anonymous block */ {
        // Range: 0x33EEC0 -> 0x33F05C
        class stcRecord * psRecord; // r16
        unsigned int u32NowMSec; // r2
        unsigned int u32RecordMSec; // r2
    }
}


// Range: 0x33F060 -> 0x33F10C
// this: r2
void clsLap::getTotalTime(class stcRecord & rsRecord /* r2 */) {
    /* anonymous block */ {
        // Range: 0x33F060 -> 0x33F10C
    }
}


// Range: 0x33F110 -> 0x33F170
// this: r2
unsigned int clsLap::getTotalMsecTime() {
    /* anonymous block */ {
        // Range: 0x33F110 -> 0x33F170
        signed int s32i; // r11
        unsigned int u32TimeMSec; // r2
    }
}


// Range: 0x33F170 -> 0x33F204
// this: r17
void clsLap::setComGoal() {
    /* anonymous block */ {
        // Range: 0x33F170 -> 0x33F204
        class clsBaseRace_Task * pcBaseRace; // r2
    }
}


// Range: 0x33F210 -> 0x33F3A4
// this: r18
void clsLap::updateMaxLap() {
    /* anonymous block */ {
        // Range: 0x33F210 -> 0x33F3A4
        class clsBaseRace_Task * pcBaseRace; // r2
    }
}


// Range: 0x33F3B0 -> 0x33F444
// this: r16
void clsLap::update() {
    /* anonymous block */ {
        // Range: 0x33F3B0 -> 0x33F444
        signed int s32Num; // r2
    }
}


// Range: 0x33F450 -> 0x33F4A8
// this: r16
void clsLap::startLap() {
    /* anonymous block */ {
        // Range: 0x33F450 -> 0x33F4A8
    }
}


// Range: 0x33F4B0 -> 0x33F5DC
// this: r17
void clsLap::reset() {
    /* anonymous block */ {
        // Range: 0x33F4B0 -> 0x33F5DC
        class clsBaseRace_Task * pcBaseRace; // r2
        unsigned int u32i; // r5
    }
}


// Range: 0x33F5E0 -> 0x33F644
// this: r16
void clsLap::initFirstAllocate(unsigned int u32GoalNum /* r2 */) {
    /* anonymous block */ {
        // Range: 0x33F5E0 -> 0x33F644
    }
}


