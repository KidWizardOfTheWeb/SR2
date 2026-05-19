#ifndef MAPBURNLIGHT_HPP
#define MAPBURNLIGHT_HPP

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

class clsMapBurnLight_Task : public clsTask {
public:
    clsMapBurnLight_Task(stcBinInfo& rParam1);

    virtual ~clsMapBurnLight_Task();
    virtual void execute();
    virtual void draw();

    clsModelType_OB_TX_MO_MA m_cModel; // offset 0x54, size 0x20
    f32 m_sTrsMtx[4][4];               // offset 0x80, size 0x40
};

#endif // MAPBURNLIGHT_HPP
