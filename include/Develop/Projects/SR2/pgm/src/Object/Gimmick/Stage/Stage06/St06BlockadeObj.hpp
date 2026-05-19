#ifndef ST06BLOCKADEOBJ_HPP
#define ST06BLOCKADEOBJ_HPP

#include "types.h"
#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/RigidBodyGimmickObj.hpp"

enum enmBlockadeObjMode {
    BLOCK_MODE_INIT = 0,
    BLOCK_MODE_MAIN = 1,
    BLOCK_MODE_BREAK = 2,
};

// total size: 0xE0
class clsBlockadeObj_Obj : public clsRigidBodyGimmickObj {
public:
    clsBlockadeObj_Obj();
    virtual ~clsBlockadeObj_Obj();

    virtual inline void reset();
    virtual inline void main();
    virtual inline u8 checkRequestDrawDebris();
    virtual inline nspPackId::enm getPackId() const;

    void requestDrawBreakEffect();
    void setData();
    void createData();
    void destroyData();

    static f32 tof32ClipSqDist;

    enum enmBlockadeObjMode m_eBlockadeObjMode; // offset 0xD0, size 0x4
};

// total size: 0x98
class clsBlockadeObj_Task : public clsSingleModelGimmick_Task<clsBlockadeObj_Task,
                                                              clsBlockadeObj_Obj,
                                                              clsModelType_OB_TX> {
public:
    clsBlockadeObj_Task(u32 u32ObjectAreaNum);
    virtual ~clsBlockadeObj_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // ST06BLOCKADEOBJ_HPP
