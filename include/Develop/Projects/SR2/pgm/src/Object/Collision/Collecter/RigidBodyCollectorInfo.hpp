#ifndef RIGIDBODYCOLLECTORINFO_HPP
#define RIGIDBODYCOLLECTORINFO_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Collision/Collecter/CollectorInfo.hpp"

// total size: 0x5C
class clsRigidBodyCollectorInfo : public clsCollectorInfo {
public:
    clsRigidBodyCollectorInfo() {}
    virtual ~clsRigidBodyCollectorInfo() {}

    virtual u8 isAddCollector(const hkCollidable* pcCollidable);
};

#endif // RIGIDBODYCOLLECTORINFO_HPP
