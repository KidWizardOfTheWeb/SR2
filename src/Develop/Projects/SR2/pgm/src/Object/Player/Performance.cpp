#include "Develop/Projects/SR2/pgm/src/Object/Player/Performance.h"

stcData* clsPrfm::getDataPtr() {
    if (this->m_pcGearCtrl->m_eCtrlMode != CTRL_MODE_WALK) {
        return &this->m_sData;
    }
    return &this->m_sWalk;
}