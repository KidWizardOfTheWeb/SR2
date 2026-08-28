#include "Develop/Projects/SR2/pgm/src/Object/Collision/Collecter/PhantomCollectorInfo.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

u8 clsPhantomCollectorInfo::isAddCollector(const hkCollidable* pcCollidable)
{
    const hkWorldObject* pcWorldObject =
        pcCollidable->m_broadPhaseHandle.m_type == 2 ? pcCollidable->getOwner() : NULL;
    return pcWorldObject != NULL;
}
