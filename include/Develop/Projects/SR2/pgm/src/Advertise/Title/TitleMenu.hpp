#ifndef TITLEMENU_HPP
#define TITLEMENU_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Lap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickAutoRunObj.hpp"

class clsAdvertiseMgr_Task;

// total size: 0x1C
struct stcDrawUnlock {
    s32 s32Rot; // offset 0x0, size 0x4

    f32 f32Frame; // offset 0x4, size 0x4

    s16 s16HalfSize; // offset 0x8, size 0x2

    f32 f32PosX; // offset 0xC, size 0x4

    f32 f32PosY; // offset 0x10, size 0x4

    u8 u8Sr; // offset 0x14, size 0x1

    u8 u8Sg; // offset 0x15, size 0x1

    u8 u8Sb; // offset 0x16, size 0x1

    u8 u8Sa; // offset 0x17, size 0x1

    u8 u8Er; // offset 0x18, size 0x1

    u8 u8Eg; // offset 0x19, size 0x1

    u8 u8Eb; // offset 0x1A, size 0x1

    u8 u8Ea; // offset 0x1B, size 0x1

    // total size: 0x1C
};

// total size: 0x94
class clsTitleMenu_Task : public clsTask {
public:
    clsTitleMenu_Task(clsAdvertiseMgr_Task* pcAdvertiseMgr) : clsTask(0, 0) {}
    virtual ~clsTitleMenu_Task();
    virtual void execute();
    virtual void draw();
    virtual void reset();

    void initUnlockDraw();
    void drawAllCourseUnlock();
    void drawGearChaos();

    clsAdvertiseMgr_Task* m_pcAdvertiseMgr_Task; // offset 0x54, size 0x4

    u32 m_u32BeginCommandFlg; // offset 0x58, size 0x4

    stcDrawUnlock m_sCourse; // offset 0x5C, size 0x1C

    stcDrawUnlock m_sGear; // offset 0x78, size 0x1C

    // total size: 0x94
};

#endif // TITLEMENU_HPP
