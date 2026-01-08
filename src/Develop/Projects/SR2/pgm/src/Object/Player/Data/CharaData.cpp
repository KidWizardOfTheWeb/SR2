#include "Develop/Projects/SR2/pgm/src/Object/Player/CharaData.hpp"
enum enmModelType getCharaModelType(unsigned short u16GearCtrlNo) {
        enmModelType eVar1;
        if (u16GearCtrlNo == 0x38) {
            eVar1 = enm_model_type::MODEL_TYPE_SKATE_END;
        }
        else if (u16GearCtrlNo == 0x26) {
            eVar1 = MODEL_TYPE_SNB;
        }
        else if (u16GearCtrlNo == 0x28) {
            eVar1 = MODEL_TYPE_RLL;
        }
        else if (u16GearCtrlNo == 0x17) {
            eVar1 = MODEL_TYPE_CVS;
        }
        else if (u16GearCtrlNo == 0x1a) {
            eVar1 = MODEL_TYPE_ADS;
        }
        else {
            eVar1 = MODEL_TYPE_DEF;
        }
        return eVar1;

}


