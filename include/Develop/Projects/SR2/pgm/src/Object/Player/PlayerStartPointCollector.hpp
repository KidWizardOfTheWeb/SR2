#ifndef PLAYERSTARTPOINTCOLLECTOR_HPP
#define PLAYERSTARTPOINTCOLLECTOR_HPP

#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/Collecter/RigidBodyCollectorInfo.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/Collecter/PhantomCollectorInfo.hpp"

class clsPlayerTask;

// total size: 0x260
class clsPlayerStartPointCollector : public hkAllCdPointCollector {
public:
    ~clsPlayerStartPointCollector();

    virtual void addCdPoint(const hkCdPoint& event);

    void updateBegin();

    void updateEnd();

    void clearTriggerData();

    clsRigidBodyCollectorInfo m_cRigidBodyInfo; // offset 0x1A0, size 0x5C
    clsPhantomCollectorInfo m_cPhantomInfo;     // offset 0x1FC, size 0x5C
    clsPlayerTask* m_pcPlayer;                  // offset 0x258, size 0x4
};

#endif // PLAYERSTARTPOINTCOLLECTOR_HPP
