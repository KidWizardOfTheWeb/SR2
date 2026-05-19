#ifndef SURVIVALWALKRUNLINE_HPP
#define SURVIVALWALKRUNLINE_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "usr/local/sega/nn/src/Object/nnobject.h"
#include "types.h"

enum enmSurvivalRaceWalkRunLineMode {
    MODE_INIT = 0,
    MODE_MAIN = 1,
    MODE_FLYING = 2,
};

// total size: 0x150
class clsSurvivalRelayWalkRunLine_Obj : public clsGimmickObj {
    // Members
public:
    enmSurvivalRaceWalkRunLineMode m_eSurvivalRaceWalkRunLineMode; // offset 0x50, size 0x4
    f32 m_asDrawMtx[3][4][4];                                      // offset 0x60, size 0xC0
    s32 m_s32PlayerNo;                                             // offset 0x120, size 0x4
    s32 m_s32NextPlayerNo;                                         // offset 0x124, size 0x4
    u8 m_bGravityFlag;                                             // offset 0x128, size 0x1
    u32 m_u32LoopNum;                                              // offset 0x12C, size 0x4
    u32 m_u32PlayerNo;                                             // offset 0x130, size 0x4
    s32 m_s32TeamNo;                                               // offset 0x134, size 0x4
    s32 m_s32SeCount;                                              // offset 0x138, size 0x4
    s32 m_s32SpeedCount;                                           // offset 0x13C, size 0x4
    u8 m_bSpeedDownFlag;                                           // offset 0x140, size 0x1

    // Static members
public:
    static f32 m_tof32CLIP_DISTx2;

    // Virtual functions
public:
    inline clsSurvivalRelayWalkRunLine_Obj(int s32TeamNo) : clsGimmickObj() {}
    virtual ~clsSurvivalRelayWalkRunLine_Obj();

    void reset();
    void execute();

    void draw(clsModelType_OB_TX_MO_MA* pcModelAT,
              _NNS_TEXLIST* psTexAT,
              clsModelType_OB_TX_MO* pcModelLine,
              _NNS_TEXLIST* psTexLine,
              f32 (*pParam5)[4][4],
              u32* psNodeStat,
              const f32 (*pParam7)[4][4],
              f32 (*pParam8)[4][4],
              u32 u32Param9);
};

#endif // SURVIVALWALKRUNLINE_HPP
