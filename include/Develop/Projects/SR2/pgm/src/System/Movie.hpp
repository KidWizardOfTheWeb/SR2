#ifndef MOVIE_HPP
#define MOVIE_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/PS2_nn/PS2NnCriMovie.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"

// total size: 0x178
class clsMovie_Task : public clsPfMovie, public clsTask {
public:
    enum enmDataNo {
        DATA_NO___TITLE = 0,
        DATA_NO___OPENING = 1,
        DATA_NO___INSERT = 2,
        DATA_NO___ENDING = 3,
        DATA_NO___BGM_1CH_ = 4,
        DATA_NO___HEROES_J = 4,
        DATA_NO___BABYLON_J = 5,
        DATA_NO___HEROES_E = 6,
        DATA_NO___BABYLON_E = 7,
        DATA_NO___OPENING_EXT = 8,
        DATA_NO___INSERT_EXT = 9,
        DATA_NO___ENDING_EXT = 10,
        DATA_NO___IGNORE_WIDE_ = 11,
        DATA_NO___SEGA_J = 11,
        DATA_NO___SEGA_E = 12,
        DATA_NO___TEST = 13,
        DATA_NO___MAX = 14,
    };

    enum enmDeleteType {
        DELETE_ALONE = 0,
        DELETE_ALL = 1,
    };

    // total size: 0xC
    struct stcSubTitleFontDetail {
        f32 f32AppearTime; // offset 0x0, size 0x4
        f32 f32EndTime;    // offset 0x4, size 0x4
        u32 u32FontTblNo;  // offset 0x8, size 0x4
    };

    clsMovie_Task(enmDataNo eDataNoI,
                  s32 s32DrawXI,
                  s32 s32DrawYI,
                  clsCriMovie::enmLoopFlag eLoopI,
                  clsCriMovie::enmSubTitle eSubTitleI,
                  u32 u32CancelActiveKeyI,
                  enmDeleteType eDeleteTypeI,
                  s32 s32PadNoI,
                  bool* pbOutSideFinishFlagI,
                  enmAllocate eAllocateI,
                  s32 s32DrawWI,
                  s32 s32DrawHI);
    virtual ~clsMovie_Task() {}

    virtual void execute();
    virtual void draw();
    f32 getEndTimeSubTitle(const stcSubTitleFontDetail* opsSubTitleFontDetail);

    static stcData m_otsData[14];

    u32 m_u32CancelActiveKey;    // offset 0x164, size 0x4
    bool* m_pbOutSideFinishFlag; // offset 0x168, size 0x4
    enmDeleteType m_eDeleteType; // offset 0x16C, size 0x4
    u8 m_bDolbyDigital_Old_PS2;  // offset 0x170, size 0x1
    s8 m_s8PadNo;                // offset 0x171, size 0x1
};

#endif // MOVIE_HPP
