#ifndef MISSION2D_HPP
#define MISSION2D_HPP

#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Score/ScoreParts2D.hpp"
#include "Develop/Projects/SR2/pgm/src/2D/Screen2D.hpp"

struct _NNS_TEXLIST;

class clsMissionRace_Task;

namespace nspMission2D {
// total size: 0x40
struct stcEnergyLine {
    s32 s32BaseX;            // offset 0x0, size 0x4
    s32 s32BaseY;            // offset 0x4, size 0x4
    s32 s32Dir;              // offset 0x8, size 0x4
    f32 f32FrameMax;         // offset 0xC, size 0x4
    stcLinePoint asPoint[4]; // offset 0x10, size 0x30
};

// total size: 0x38
struct stcEnergyLineData {
    s16 s16MoveMax;        // offset 0x0, size 0x2
    f32 f32WaitFrame;      // offset 0x4, size 0x4
    f32 f32TextY;          // offset 0x8, size 0x4
    f32 f32LinkScale;      // offset 0xC, size 0x4
    f32 f32NumScale;       // offset 0x10, size 0x4
    f32 f32NumMaxScale;    // offset 0x14, size 0x4
    s16 s16LineStartX;     // offset 0x18, size 0x2
    s16 s16LineMiddleX;    // offset 0x1A, size 0x2
    s16 s16LineEndX;       // offset 0x1C, size 0x2
    s16 s16LineStartY;     // offset 0x1E, size 0x2
    s16 s16LineEndY;       // offset 0x20, size 0x2
    u8 u8ELineHeight;      // offset 0x22, size 0x1
    f32 f32LinePointFrame; // offset 0x24, size 0x4
    f32 f32MarginFrame;    // offset 0x28, size 0x4
    f32 f32HeadScale;      // offset 0x2C, size 0x4
    f32 f32HeadAddFrame;   // offset 0x30, size 0x4
    f32 f32HeadAddScale;   // offset 0x34, size 0x4
};

void setupEnergyPoint();

extern stcEnergyLineData osDrawData;
extern _NNS_TEXLIST* psTexList_Mission2D;
extern _NNS_TEXLIST* psTexList_MissionSta2D;
extern stcEnergyLine asEnergyLine;
extern f32 tf32EnergyFrameMax;
} // namespace nspMission2D

// Global enum (no Q2 mangling); may logically belong to MissionRace TU
enum enmMissionInfo {
    MISSION__TIMEATTACK_COUNTUP = 0,
    MISSION__TIMEATTACK_COUNTDOWN = 1,
    MISSION__RING = 2,
    MISSION__TRICK = 3,
    MISSION__SKILL = 4,
    MISSION__GD_TIME = 5,
    MISSION__GD_REMOVE = 6,
    MISSION__GRIND_RINK = 7,
    MISSION__GRIND_RINK_P = 8,
    MISSION__TAG_G = 9,
    MISSION__TAG_PT = 10,
    MISSION__DESTRUCTION = 11,
    MISSION__MARK_GD = 12,
    MISSION__MARK_GC = 13,
    MISSION__AGP = 14,
    MISSION__ATTACK = 15,
    MISSION__MARK = 16,
    MISSION__GEAR_CHANGE = 17,
    MISSION__START_DASH = 18,
    MISSION__TRICK_A = 19,
    MISSION__MAX = 20,
    MISSION__NONE = -1,
};

// Global struct used as pointer member
// total size: 0x4
struct stcPos2D {
    s16 s16X; // offset 0x0, size 0x2
    s16 s16Y; // offset 0x2, size 0x2
};

// total size: 0xE4
class clsMission2D_Task : public clsTask, public clsScreen2D {
public:
    // Note: enuDrawMode has 3 conflicting global bodies with same name; nested here to avoid
    // collision
    enum enuDrawMode {
        DRAW_MODE__MISSION_NUM = 0,
        DRAW_MODE__ADD_POINT = 1,
        DRAW_MODE__EXCELLENT = 2,
        DRAW_MODE__MISS = 3,
        DRAW_MODE__ADD_SEC = 4,
        DRAW_MODE__ADD_TIME = 5,
        DRAW_MODE__ADD_REMOVE = 6,
        DRAW_MODE__TIME = 7,
        SCORE_BOX_BG_X = 4,
        SCORE_BOX_BG_Y = 4,
    };

    virtual ~clsMission2D_Task() {}

    void init();
    void setAddNumAnime(s32 s32Frame);
    s32 nowMissionNum();
    void mainMissionNum();
    virtual void execute();
    virtual void draw();
    void drawMissionNum();
    void drawUpPoint();
    void drawAddSec();
    void drawPoint(s32 s32MsgTexNo, u32 u32DispType);
    void drawPoint(u32 u32DispType);
    void drawTrickPoint();
    void drawSkill();
    void drawMark();
    void drawGDive();
    void drawGDiveTime();
    void drawGauge();
    void drawAttack();
    void drawDestruction();

    stcPos2D* m_opsPosVec;                // offset 0x94, size 0x4
    enmMissionInfo m_eModoNo;             // offset 0x98, size 0x4
    enuDrawMode m_eDrawModeNo;            // offset 0x9C, size 0x4
    s32 m_s32DispNum;                     // offset 0xA0, size 0x4
    u32 m_u32Count;                       // offset 0xA4, size 0x4
    f32 m_f32MoveX;                       // offset 0xA8, size 0x4
    f32 m_f32Alpha;                       // offset 0xAC, size 0x4
    s32 m_s32ClrCondition;                // offset 0xB0, size 0x4
    u32 m_u32GaugeMAX;                    // offset 0xB4, size 0x4
    s32 m_s32AddNumAnime;                 // offset 0xB8, size 0x4
    f32 m_f32Scale;                       // offset 0xBC, size 0x4
    f32 m_f32PosX;                        // offset 0xC0, size 0x4
    f32 m_f32PosY;                        // offset 0xC4, size 0x4
    u8* m_pbEndFlag;                      // offset 0xC8, size 0x4
    clsEnergyFlow2D* m_pcBaseLine;        // offset 0xCC, size 0x4
    f32 m_f32EnergyFrame;                 // offset 0xD0, size 0x4
    f32 m_f32EnergyFrameMax;              // offset 0xD4, size 0x4
    s32 m_s32BaseLinePosX;                // offset 0xD8, size 0x4
    s32 m_s32BaseLinePosY;                // offset 0xDC, size 0x4
    clsMissionRace_Task* m_pcMissionRace; // offset 0xE0, size 0x4
};

#endif // MISSION2D_HPP
