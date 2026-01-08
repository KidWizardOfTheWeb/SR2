#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/GearCtrl.hpp"
// Range: 0x306950 -> 0x306B3C
// this: r20
void clsGear::draw(float (* psGearMtx)[4][4] /* r2 */, float f32Alpha /* r20 */, unsigned int u32AddDrawFlagI /* r19 */) {
/*
    anonymous block {
        // Range: 0x306950 -> 0x306B3C
        float sMtx[4][4]; // r29+0x70
        class NNS_OBJECT * psObject; // r18
        unsigned int * psNodeStat; // r17
        unsigned int u32DrawFlag; // r16
    }
*/
}


// Range: 0x306C00 -> 0x306C5C
// this: r16
void clsGear::clearChangeActionParam() {
    nnSetUpVectorFast(&this->m_sActionTrans, 0.0f,0.0f,0.0f);
    this->m_sActionRot.x = 0.0;
    this->m_sActionRot.y = 0.0;
    this->m_sActionRot.z = 0.0;
    this->m_sActionScale.x = 1.0;
    this->m_sActionScale.y = 1.0;
    this->m_sActionScale.z = 1.0;
    this->m_f32ActionAlpha = 255.0;
    this->m_u32ActionCnt = 0;
    return;
}