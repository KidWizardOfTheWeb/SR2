#ifndef ST07MAPPARTSGIMMICKWALLBIG_HPP
#define ST07MAPPARTSGIMMICKWALLBIG_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Control/Se3DControl.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/Stage/Stage07/St07MapPartsGimmickWallObject.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class hkTransformShape;

// total size: 0x170
class clsMapPartsGimmickWallBig_Object : public clsMapPartsGimmickWall_Object {
public:
    clsMapPartsGimmickWallBig_Object() {}
    virtual ~clsMapPartsGimmickWallBig_Object() {}

    virtual void createData();
    virtual void destroyData();
    virtual void reset();

    u8 checkData(u32 u32Num, u32 u32LapNum, u32 u32Ranking);

    static f32 tof32ClipSqDist;

    f32 m_sEffectMtx[4][4];          // offset 0x120, size 0x40
    clsSe3DControl* m_pcSe3DControl; // offset 0x160, size 0x4
};

// total size: 0xB0
class clsMapPartsGimmickWallBig_Task
    : public clsSingleModelGimmick_Task<clsMapPartsGimmickWallBig_Task,
                                        clsMapPartsGimmickWallBig_Object,
                                        clsModelType_OB_TX_MO_MA> {
public:
    clsMapPartsGimmickWallBig_Task(u32 u32ObjectAreaNum);
    virtual ~clsMapPartsGimmickWallBig_Task() {}

    virtual void reset();
    virtual void execute();
    virtual void draw();

    void checkMode(u8 u8Num, s16 s16LapNum, s8 s8Ranking);

    hkTransformShape* m_pcTransShape; // offset 0xAC, size 0x4
};

#endif // ST07MAPPARTSGIMMICKWALLBIG_HPP
