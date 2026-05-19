#ifndef SCRIPTWAITSTRING_HPP
#define SCRIPTWAITSTRING_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsScript_Task;

// total size: 0x74
class clsScriptWaitString_Task : public clsTask {
public:
    virtual ~clsScriptWaitString_Task() {}

    virtual void execute();
    virtual void draw();

    void initData();
    void releaseData();
    void codeWaitString(u8* pu8Ptr, clsScript_Task* pcTask);

    u32 m_u32DrawFlg;               // offset 0x54, size 0x4
    u32 m_u32Id;                    // offset 0x58, size 0x4
    u32 m_u32DataNo;                // offset 0x5C, size 0x4
    f32 m_f32LifeFrame;             // offset 0x60, size 0x4
    f32 m_f32PosX;                  // offset 0x64, size 0x4
    f32 m_f32PosY;                  // offset 0x68, size 0x4
    f32 m_f32WaitFrame;             // offset 0x6C, size 0x4
    clsScript_Task* m_pcScriptTask; // offset 0x70, size 0x4

    static clsScriptWaitString_Task* m_tapcWaitStringTask[2];
};

#endif // SCRIPTWAITSTRING_HPP
