#ifndef BASETRICKACTION_HPP
#define BASETRICKACTION_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Player/Trick/TrickParam.hpp"

// total size: 0x4
class clsBaseTrickAction {
public:
    virtual ~clsBaseTrickAction() {}

    void updateBingoConrol(clsTrickParam& rcParam);
    void applyGearAbility(clsTrickParam& rcParam);
    void actionRotateMotion(clsTrickParam& rcParam, f32 of32Frame, f32 of32TotalFrame);
    void setFallMotion(clsTrickParam& rcParam);
    void setTrickMotion(clsTrickParam& rcParam, f32 of32MotionFrame, f32 of32LinkFrame);
    void
    calcRotateRad(clsTrickParam& rcParam, f32 of32ActionFrame, s16 os16RotateDeg, s8 os8RotDir);
    void exitCommon(clsTrickParam& rcParam);
    void initCommon(clsTrickParam& rcParam);
    s32 setKeyRecord(clsTrickParam& rcParam);
    void calcTrickRank(clsTrickParam& rcParam, f32 of32LengthRate);
    u8 calcKickerType(clsTrickParam& rcParam);
    virtual enmKickerRankZone checkTrickRankZone(clsTrickParam& rcParam);
    virtual void settingTrickParam(clsTrickParam& rcParam);
};

#endif // BASETRICKACTION_HPP
