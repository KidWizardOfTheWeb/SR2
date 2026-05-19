#ifndef PRESSSTART_HPP
#define PRESSSTART_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/Particle/ParticleTexture.hpp"
#include "Develop/Projects/SR2/pgm/src/Effect/IonMist/IonMist.hpp"

enum enmArgPauseUnDraw {
    PAUSE_UN_DRAW___OFF = 0,
    PAUSE_UN_DRAW___ON = 1,
};

// total size: 0x8C
class clsPressStart_Task : public clsTask {
public:
    enum enmArgOwnDeleteIsAll {
        OWN_DELETE_IS___NOTHIN = 0,
        OWN_DELETE_IS___OWN = 1,
        OWN_DELETE_IS___ALL = 2,
    };

    ~clsPressStart_Task();

    clsPressStart_Task(s32 s32DrawX,
                       s32 s32DrawY,
                       u32 u32EndKey,
                       enmArgOwnDeleteIsAll eOwnDeleteIsAll,
                       s32 s32PadNo,
                       enmArgPauseUnDraw ePauseUnDraw,
                       f32 f32LifeFrame,
                       _NNS_TEXLIST* psTexList,
                       const stcTexUV* psTexUV,
                       s32 s32DrawW,
                       s32 s32DrawH,
                       s32 s32SeId);

    virtual void execute();

    virtual void draw();

    s32 m_s32DrawX;                         // offset 0x54, size 0x4
    s32 m_s32DrawY;                         // offset 0x58, size 0x4
    s32 m_s32DrawW;                         // offset 0x5C, size 0x4
    s32 m_s32DrawH;                         // offset 0x60, size 0x4
    f32 m_f32LifeFrame;                     // offset 0x64, size 0x4
    s32 m_u32EndKey;                        // offset 0x68, size 0x4
    _NNS_TEXLIST* m_psTexList;              // offset 0x6C, size 0x4
    stcTexUV m_sTexUv;                      // offset 0x70, size 0x10
    s8 m_s8PadNo;                           // offset 0x80, size 0x1
    s8 m_s8TexNo;                           // offset 0x81, size 0x1
    enmArgPauseUnDraw m_ePauseUnDraw;       // offset 0x84, size 0x4
    enmArgOwnDeleteIsAll m_eOwnDeleteIsAll; // offset 0x88, size 0x4
};

#endif // PRESSSTART_HPP
