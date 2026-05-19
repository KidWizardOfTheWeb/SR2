#ifndef CHARASONIC_HPP
#define CHARASONIC_HPP

#include "Develop/Projects/SR2/pgm/src/Data/Pack.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/Character.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"
#include "Develop/Projects/SR2/pgm/src/Task/TaskManager.hpp"
#include "types.h"

class clsCharacter;
class clsPlayerTask;

// total size: 0x58
class clsDrawAttackEffect_Task : public clsTask {
public:
    virtual ~clsDrawAttackEffect_Task();

    void draw();

    // Members
    clsCharacter* m_pcChara; // offset 0x54, size 0x4
};

// total size: 0x70
class clsCharaSonic : public clsCharaNodeBase {
public:
    clsCharaSonic(clsPlayerTask* pcPlayer, u8 u8ModelType);
    virtual ~clsCharaSonic() {}

    virtual f32 getCollisionRadius() const { return tof32CollisionRadius; }
    virtual f32 getDrawOffset() const { return 0.0f; }
    virtual void drawAttackEffect();

    void behavior();
    void initAttack00();
    void initAttack01();
    void actionAttack00();
    void actionAttack01();
    void loadAdditionalData(stcBinInfo& rsBinInfo);

    static f32 tof32CollisionRadius;

    clsDrawAttackEffect_Task* m_pcDrawEffTsk; // offset 0x60, size 0x4
};

#endif // CHARASONIC_HPP
