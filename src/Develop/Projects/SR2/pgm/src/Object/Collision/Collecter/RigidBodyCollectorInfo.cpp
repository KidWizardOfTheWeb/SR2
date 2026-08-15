#include "Develop/Projects/SR2/pgm/src/Object/Collision/Collecter/RigidBodyCollectorInfo.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

u8 clsRigidBodyCollectorInfo::isAddCollector(const hkCollidable* pcCollidable)
{
    const hkWorldObject* p =
        pcCollidable->m_broadPhaseHandle.m_type == 1 ? pcCollidable->getOwner() : 0;
    return p != 0;
}
