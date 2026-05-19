#ifndef PHANTOMCOLLECTORINFO_HPP
#define PHANTOMCOLLECTORINFO_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/Collecter/CollectorInfo.hpp"

// total size: 0x5C
class clsPhantomCollectorInfo : public clsCollectorInfo {
public:
    clsPhantomCollectorInfo() {}
    virtual ~clsPhantomCollectorInfo() {}

    virtual u8 isAddCollector(const hkCollidable* pcCollidable);
};

#endif // PHANTOMCOLLECTORINFO_HPP
