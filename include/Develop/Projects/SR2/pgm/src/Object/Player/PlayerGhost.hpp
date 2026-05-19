#ifndef PLAYERGHOST_HPP
#define PLAYERGHOST_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Ghost.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"

class clsPlayerGhost : public clsPlayerTask {
public:
    virtual ~clsPlayerGhost() {}

    virtual void setActionType(enmActionType p0) {}
    virtual void setRingNum(s32 p0) {}
    virtual enmPlayerType getPlayerType() const { return PLAYER_TYPE__GHOST; }

    virtual void initGhost(const stcSendAdv& p0);
    virtual void reset();
    virtual void execute();
    virtual void draw();
    virtual void setEnableExecFlag(bool p0);
    virtual void setStartFlag(bool p0);

    u8 m_bIsEnableExec; // offset 0x12F0, size 0x1
    u8 m_bStartFlag;    // offset 0x12F1, size 0x1
};

#endif // PLAYERGHOST_HPP
