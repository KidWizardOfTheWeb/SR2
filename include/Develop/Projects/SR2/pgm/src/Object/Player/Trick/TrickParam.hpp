#ifndef TRICKPARAM_HPP
#define TRICKPARAM_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Data/Path/PathPoint.hpp"

class clsPlayerTask;
struct stcInfo;

namespace nspTrick {
enum enmKicker {
    KICKER_FF = 0,
    KICKER_BF = 1,
    KICKER_SPIN = 2,
    KICKER_PIPE = 3,
    KICKER_FREE = 4,
    KICKER_WALL = 5,
    KICKER_TURB = 6,
    KICKER_VERTICAL = 7,
    KICKER_PARTS = 8,
    KICKER_TYPE_MAX = 9,
};
} // namespace nspTrick

enum enmStartType {
    START_TYPE__JUMP = 0,
    START_TYPE__FLIGHT = 1,
};

enum enmRank {
    RANK_FAILED = -1,
    RANK_AUTO = 0,
    RANK_C = 0,
    RANK_B = 1,
    RANK_A = 2,
    RANK_AA = 3,
    RANK_S = 4,
    RANK_SS = 5,
    RANK_X = 6,
    RANK_MAX = 7,
};

enum enmKickerRankZone {
    FAILURE__ZONE = 0,
    RANK_B__ZONE = 1,
    RANK_A__ZONE = 2,
    RANK_S__ZONE = 3,
    ZONE_MAX = 4,
};

// total size: 0x4
struct stcBingoControl {
    s8 as8Rank[3]; // offset 0x0, size 0x3
    s8 s8RankNo;   // offset 0x3, size 0x1
};

// total size: 0x20
struct stcFlipKicker {
    f32 f32UpSpeed;           // offset 0x0, size 0x4
    f32 f32UpAccele;          // offset 0x4, size 0x4
    f32 f32DownSpeed;         // offset 0x8, size 0x4
    f32 f32DownAccele;        // offset 0xC, size 0x4
    f32 f32VelocityY;         // offset 0x10, size 0x4
    f32 f32UpGravityAccele;   // offset 0x14, size 0x4
    f32 f32DownGravityAccele; // offset 0x18, size 0x4
    s32 s32Frame;             // offset 0x1C, size 0x4
};

// total size: 0x8
struct stcTrickMotionData {
    f32 f32MotionFrame; // offset 0x0, size 0x4
    s16 s16RotateDeg;   // offset 0x4, size 0x2
    s8 s8RotDir;        // offset 0x6, size 0x1
    s8 s8EffectFlag;    // offset 0x7, size 0x1
};

// total size: 0x18
struct stcTrickMotionDataDir {
    stcTrickMotionData asMotionData[3]; // offset 0x0, size 0x18
};

// total size: 0xD8
struct stcTrickMotionRankTable {
    stcTrickMotionDataDir asMotionDataDir[9]; // offset 0x0, size 0xD8
};

// total size: 0x510
struct stcTrickMotionTable {
    stcTrickMotionRankTable asMotionRankTable[6]; // offset 0x0, size 0x510
};

// total size: 0x10
struct stcTrickMotionDataDir2 {
    stcTrickMotionData asMotionData[2]; // offset 0x0, size 0x10
};

// total size: 0x90
struct stcTrickMotionRankTable2 {
    stcTrickMotionDataDir2 asMotionDataDir2[9]; // offset 0x0, size 0x90
};

// total size: 0x360
struct stcTrickMotionTable2 {
    stcTrickMotionRankTable2 asMotionRankTable2[6]; // offset 0x0, size 0x360
};

// total size: 0xD0
class clsTrickParam {
public:
    virtual ~clsTrickParam() {}

    void debugTrickKey();
    u8 debugTrickParam();
    void debugTrickRank();
    void reset();

    NNS_VECTORFAST m_sDirVecFast;           // offset 0x10, size 0x10
    stcBingoControl m_sBingoControl;        // offset 0x20, size 0x4
    clsPlayerTask* m_pcPlayer;              // offset 0x24, size 0x4
    void* m_pvTrickMotionData;              // offset 0x28, size 0x4
    stcInfo* m_psColInfo;                   // offset 0x2C, size 0x4
    clsRetPath m_cRetCoursePath;            // offset 0x30, size 0x20
    f32 m_f32UpAccele;                      // offset 0x50, size 0x4
    f32 m_f32Frame;                         // offset 0x54, size 0x4
    f32 m_f32RotRadRate;                    // offset 0x58, size 0x4
    f32 m_f32StepFrame;                     // offset 0x5C, size 0x4
    f32 m_f32QuickSlowRate;                 // offset 0x60, size 0x4
    nspTrick::enmKicker m_eKickerType;      // offset 0x64, size 0x4
    enmStartType m_eStartType;              // offset 0x68, size 0x4
    enmRank m_eBaseRank;                    // offset 0x6C, size 0x4
    enmRank m_eRank;                        // offset 0x70, size 0x4
    s8 m_s8MotionStep;                      // offset 0x74, size 0x1
    s8 m_s8RotDir;                          // offset 0x75, size 0x1
    s8 m_as8KeyDir[4];                      // offset 0x76, size 0x4
    s8 m_s8KeySaveCount;                    // offset 0x7A, size 0x1
    f32 m_f32BonusSpeed;                    // offset 0x7C, size 0x4
    u8 m_bEnableKickerDebug;                // offset 0x80, size 0x1
    f32 m_f32DebugSpeed;                    // offset 0x84, size 0x4
    f32 m_f32DebugGravity;                  // offset 0x88, size 0x4
    f32 m_f32DebugJump;                     // offset 0x8C, size 0x4
    s32 m_s32EnableAcceleKickerDebug;       // offset 0x90, size 0x4
    f32 m_f32DebugUpSpeed;                  // offset 0x94, size 0x4
    f32 m_f32DebugUpAccele;                 // offset 0x98, size 0x4
    f32 m_f32DebugDownSpeed;                // offset 0x9C, size 0x4
    f32 m_f32DebugDownAccele;               // offset 0xA0, size 0x4
    f32 m_f32DebugVelocityY;                // offset 0xA4, size 0x4
    f32 m_f32DebugUpGravityAccele;          // offset 0xA8, size 0x4
    f32 m_f32DebugDownGravityAccele;        // offset 0xAC, size 0x4
    f32 m_f32DebugFrame;                    // offset 0xB0, size 0x4
    u8 m_bEnableTrickDebug;                 // offset 0xB4, size 0x1
    u8 m_bTrickRecordDispDebug;             // offset 0xB5, size 0x1
    nspTrick::enmKicker m_eDebugKickerType; // offset 0xB8, size 0x4
    enmRank m_eDebugTrickRank;              // offset 0xBC, size 0x4
    s8 m_s8DebugKeyDir;                     // offset 0xC0, size 0x1
};

#endif // TRICKPARAM_HPP
