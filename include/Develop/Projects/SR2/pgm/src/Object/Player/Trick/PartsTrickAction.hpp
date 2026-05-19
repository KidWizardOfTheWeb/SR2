#ifndef PARTSTRICKACTION_HPP
#define PARTSTRICKACTION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/FreeTrickAction.hpp"

// total size: 0x4
class clsPartsTrickAction : public clsFreeTrickAction {
public:
    virtual ~clsPartsTrickAction() {}
    virtual void settingTrickParam(clsTrickParam& rcParam);
    virtual enmKickerRankZone checkTrickRankZone(clsTrickParam& rcParam);

    f32 calcRankPath(clsTrickParam& rcParam);
};

#endif // PARTSTRICKACTION_HPP
