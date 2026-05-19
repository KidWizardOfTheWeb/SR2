#ifndef GEARBURNLIGHT_HPP
#define GEARBURNLIGHT_HPP

#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Gear/Gear.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0xB0
class clsGearBurnLight_Task : public clsTask {
public:
    virtual ~clsGearBurnLight_Task() {}

    virtual void execute();

    virtual void draw();

    f32 m_sMtxWork[4][4];          // offset 0x60, size 0x40
    clsModelType_OB_TX& m_rcModel; // offset 0xA0, size 0x4
    clsGear* m_pcGear;             // offset 0xA4, size 0x4
    s16 m_s16DrawNum;              // offset 0xA8, size 0x2
    s8 m_s8DrawNodeNo;             // offset 0xAA, size 0x1
};

// total size: 0x5C
class clsSkateBurnLight_Task : public clsTask {
public:
    virtual ~clsSkateBurnLight_Task() {}

    virtual void execute();
    virtual void draw();

    clsGearCtrl& m_rcGearCtrl; // offset 0x54, size 0x4
    s16 m_s16DrawNum;          // offset 0x58, size 0x2
    s8 m_s8DrawNodeNo;         // offset 0x5A, size 0x1
};

#endif // GEARBURNLIGHT_HPP
