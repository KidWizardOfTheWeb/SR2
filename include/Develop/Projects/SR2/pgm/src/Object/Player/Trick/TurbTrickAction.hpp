#ifndef TURBTRICKACTION_HPP
#define TURBTRICKACTION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/BaseTrickAction.hpp"

class clsPlayerTask;

// total size: 0x4
class clsTurbTrickAction : public clsBaseTrickAction {
public:
    virtual ~clsTurbTrickAction() {}
    virtual void init(clsTrickParam& rcParam);
    virtual void execute(clsTrickParam& rcParam);
    virtual void settingTrickParam(clsTrickParam& rcParam);

    enmRank calcTrickRank(clsPlayerTask* pcPlayer);
};

#endif // TURBTRICKACTION_HPP
