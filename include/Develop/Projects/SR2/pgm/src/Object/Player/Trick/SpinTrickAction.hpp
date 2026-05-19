#ifndef SPINTRICKACTION_HPP
#define SPINTRICKACTION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/BaseTrickAction.hpp"

// total size: 0x4
class clsSpinTrickAction : public clsBaseTrickAction {
public:
    virtual ~clsSpinTrickAction() {}
    virtual void init(clsTrickParam& rcParam);
    virtual void execute(clsTrickParam& rcParam);
};

#endif // SPINTRICKACTION_HPP
