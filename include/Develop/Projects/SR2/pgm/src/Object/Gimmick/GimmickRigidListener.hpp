#ifndef GIMMICKRIGIDLISTENER_HPP
#define GIMMICKRIGIDLISTENER_HPP

#include "Develop/Projects/SR2/pgm/src/Havok/Havok.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

// total size: 0x4
class clsGimmickRigidListener : public hkCollisionListener {
public:
    virtual ~clsGimmickRigidListener() {}
    virtual void contactProcessCallback(hkContactProcessEvent& event);
    virtual void contactPointRemovedCallback(hkContactPointRemovedEvent& event);
    virtual void contactPointConfirmedCallback(hkContactPointConfirmedEvent& event);
    virtual void contactPointAddedCallback(hkContactPointAddedEvent& rParam1);
};

#endif // GIMMICKRIGIDLISTENER_HPP
