#ifndef GIMMICKMANAGER_HPP
#define GIMMICKMANAGER_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Singleton.hpp"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOStl.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"

// total size: 0x18
class clsGmkManager : public clsSingleton<clsGmkManager> {
public:
    virtual ~clsGmkManager() {}

    // RECONSTRUCTED: member name.
    void registGimmick(clsTask* pcTask) { m_tdpcGimmick.insert(m_tdpcGimmick.end(), pcTask); }

    oostd::clsOOList<clsTask*, oostd::clsOOStlAllocator<clsTask*> >
        m_tdpcGimmick; // offset 0x4, size 0x14
};

#endif // GIMMICKMANAGER_HPP
