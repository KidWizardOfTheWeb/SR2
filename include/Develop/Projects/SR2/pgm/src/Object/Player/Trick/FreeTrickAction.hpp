#ifndef FREETRICKACTION_HPP
#define FREETRICKACTION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/BaseTrickAction.hpp"

// total size: 0x4
class clsFreeTrickAction : public clsBaseTrickAction {
public:
    virtual ~clsFreeTrickAction() {}
    virtual void init(clsTrickParam& rcParam);
    virtual void execute(clsTrickParam& rcParam);
};

#endif // FREETRICKACTION_HPP
