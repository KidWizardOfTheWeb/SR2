#ifndef PIPETRICKACTION_HPP
#define PIPETRICKACTION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/BaseTrickAction.hpp"

// total size: 0x4
class clsPipeTrickAction : public clsBaseTrickAction {
public:
    virtual ~clsPipeTrickAction() {}
    virtual void init(clsTrickParam& rcParam);
    virtual void execute(clsTrickParam& rcParam);
};

#endif // PIPETRICKACTION_HPP
