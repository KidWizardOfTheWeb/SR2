#include "Develop/Projects/SR2/pgm/src/Object/Collision/Collecter/PhantomCollectorInfo.hpp"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

u8 clsPhantomCollectorInfo::isAddCollector(const hkCollidable* pcCollidable)
{
    const s8* p = pcCollidable->m_broadPhaseHandle.m_type == 2 ? pcCollidable->getOwner() : 0;
    return p != 0;
}
