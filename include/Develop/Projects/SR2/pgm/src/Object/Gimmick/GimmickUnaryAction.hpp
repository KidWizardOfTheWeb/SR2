#ifndef GIMMICKUNARYACTION_HPP
#define GIMMICKUNARYACTION_HPP

#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"

// total size: 0x1C
class clsGimmickUnaryAction : public hkUnaryAction {
public:
    clsGimmickUnaryAction(hkEntity* pcEntity) : hkUnaryAction(pcEntity, 0) {}
    virtual ~clsGimmickUnaryAction() {}

    virtual void applyAction(const hkStepInfo& stepInfo);

    virtual hkAction* clone(const hkArray<hkEntity*>& rParam1,
                            const hkArray<hkPhantom*>& rParam2) const;
};

#endif // GIMMICKUNARYACTION_HPP
