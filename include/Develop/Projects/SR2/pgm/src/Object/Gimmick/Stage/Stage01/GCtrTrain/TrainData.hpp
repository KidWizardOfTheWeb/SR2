#ifndef TRAINDATA_HPP
#define TRAINDATA_HPP

#include "types.h"

class clsGCtrlTrain_Obj;
class clsSe3DControl;

// total size: 0x14
struct stcTrainData {
    clsGCtrlTrain_Obj* m_pcTrainObj; // offset 0x0, size 0x4
    clsSe3DControl* m_pcSe3DControl; // offset 0x4, size 0x4
    f32 m_f32Speed;                  // offset 0x8, size 0x4
    f32 m_f32SpeedUpFrame;           // offset 0xC, size 0x4
    u8 bExecute;                     // offset 0x10, size 0x1
};

#endif // TRAINDATA_HPP
