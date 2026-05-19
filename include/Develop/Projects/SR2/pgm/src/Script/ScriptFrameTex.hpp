#ifndef SCRIPTFRAMETEX_HPP
#define SCRIPTFRAMETEX_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "usr/local/sega/nn/src/Texture/nntexture.h"

class clsScript_Task;

// total size: 0x68
class clsScriptCreateFrameTex_Task : public clsTask {
public:
    clsScriptCreateFrameTex_Task(u8 u8TexNo, clsScript_Task* pcParrent);
    virtual ~clsScriptCreateFrameTex_Task();

    virtual void execute();
    virtual void draw();

    void update();
    void createTexture();

    u8 m_u8Type;                     // offset 0x54, size 0x1
    u8 m_u8TexNo;                    // offset 0x55, size 0x1
    _NNS_TEXLIST* m_psTexList;       // offset 0x58, size 0x4
    void* m_pvTexHeap;               // offset 0x5C, size 0x4
    void* m_pvTexMem;                // offset 0x60, size 0x4
    clsScript_Task* m_pcParrentTask; // offset 0x64, size 0x4
};

#endif // SCRIPTFRAMETEX_HPP
