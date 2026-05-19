#ifndef GOALANNOUNCE2D_HPP
#define GOALANNOUNCE2D_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/2D/Score/Temporary2D.hpp"

class clsGoalAnnounce2D_Task;

namespace nspGoalAnnounce2D {
extern clsGoalAnnounce2D_Task* pcCurrentTask;

void initCurrent();
} // namespace nspGoalAnnounce2D

// total size: 0x6C
class clsGoalAnnounce2D_Task : public clsTemporary2D_Task {
public:
    clsGoalAnnounce2D_Task(s32 s32Rank, u32 u32CharaId);
    ~clsGoalAnnounce2D_Task();

    virtual void execute();
    virtual void draw();

    // Members
    s32 m_s32Rank;      // offset 0x58, size 0x4
    u32 m_u32CharaId;   // offset 0x5C, size 0x4
    s16 m_s16DrawX;     // offset 0x60, size 0x2
    s16 m_s16BaseX;     // offset 0x62, size 0x2
    s16 m_s16BaseY;     // offset 0x64, size 0x2
    s16 m_s16OutX;      // offset 0x66, size 0x2
    f32 m_f32MoveFrame; // offset 0x68, size 0x4
};

#endif // GOALANNOUNCE2D_HPP
