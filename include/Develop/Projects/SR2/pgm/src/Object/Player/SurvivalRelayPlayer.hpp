#ifndef SURVIVALRELAYPLAYER_HPP
#define SURVIVALRELAYPLAYER_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Player.hpp"
#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"

class clsSurvivalRelayPlayerTask : public clsPlayerTask {
public:
    // stub (header): clsSurvivalRelayPlayerTask(const stcSetDataDetail& rParam1) :
    // clsPlayerTask(rParam1) {}
    clsSurvivalRelayPlayerTask(const stcSetDataDetail& rParam1) : clsPlayerTask(rParam1) {}
    virtual ~clsSurvivalRelayPlayerTask();

    void setStartPosRot(const stcInitData* pParam1, bool bParam2);
};

#endif // SURVIVALRELAYPLAYER_HPP
