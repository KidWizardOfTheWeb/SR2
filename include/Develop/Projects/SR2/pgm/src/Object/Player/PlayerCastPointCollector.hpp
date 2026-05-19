#ifndef PLAYERCASTPOINTCOLLECTOR_HPP
#define PLAYERCASTPOINTCOLLECTOR_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerStartPointCollector.hpp"

class clsPlayerTask;

// total size: 0x1B0
class clsPlayerCastPointCollector : public hkAllCdPointCollector {
public:
    virtual ~clsPlayerCastPointCollector();

    virtual void addCdPoint(const hkCdPoint& event);

    void setPlayerTask(clsPlayerTask* pcPlayer);

    clsPlayerCastPointCollector();

    clsPlayerTask* m_pcPlayer; // offset 0x1A0, size 0x4
};

#endif // PLAYERCASTPOINTCOLLECTOR_HPP
