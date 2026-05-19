#ifndef WALLTRICKACTION_HPP
#define WALLTRICKACTION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/BaseTrickAction.hpp"

// total size: 0x4
class clsWallTrickAction : public clsBaseTrickAction {
public:
    virtual ~clsWallTrickAction() {}
    virtual void init(clsTrickParam& rcParam);
    virtual void execute(clsTrickParam& rcParam);
};

#endif // WALLTRICKACTION_HPP
