#ifndef PHANTOMGIMMICKOBJECT_HPP
#define PHANTOMGIMMICKOBJECT_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/HaveGimmickPhantom.hpp"

// total size: 0x60
// Inherits clsGimmickObj (0x50) + clsHaveGimmickPhantom (0x8); trailing 8 bytes are alignment
// padding.
class clsPhantomGimmickObject : public clsGimmickObj, public clsHaveGimmickPhantom {
public:
    virtual ~clsPhantomGimmickObject() {}
    virtual void destroyCollision();
    virtual void updateSetEditorCollision();
    virtual void drawCollision();
};

#endif // PHANTOMGIMMICKOBJECT_HPP
