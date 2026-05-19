#ifndef FLIPTRICKACTION_HPP
#define FLIPTRICKACTION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/BaseTrickAction.hpp"

// total size: 0x4
class clsFlipTrickAction : public clsBaseTrickAction {
public:
    virtual ~clsFlipTrickAction() {}
    virtual void init(clsTrickParam& rcParam);
    virtual void execute(clsTrickParam& rcParam);
};

#endif // FLIPTRICKACTION_HPP
