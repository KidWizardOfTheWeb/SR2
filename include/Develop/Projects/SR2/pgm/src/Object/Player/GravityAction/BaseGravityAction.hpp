#ifndef BASEGRAVITYACTION_HPP
#define BASEGRAVITYACTION_HPP

#include "types.h"

class clsGravityActionManager;

// total size: 0x18
class clsBaseGravityAction {
public:
    clsBaseGravityAction(clsGravityActionManager* pcManager)
        : m_pcManager(pcManager), m_f32Range(t_of32DefaultRange),
          m_f32UsedRate(t_of32DefaultUsedRate), m_f32DefaultRange(t_of32DefaultRange),
          m_f32DefaultUsedRate(t_of32DefaultUsedRate)
    {
    }

    clsGravityActionManager* m_pcManager; // offset 0x0, size 0x4
    f32 m_f32Range;                       // offset 0x4, size 0x4
    f32 m_f32UsedRate;                    // offset 0x8, size 0x4
    f32 m_f32DefaultRange;                // offset 0xC, size 0x4
    f32 m_f32DefaultUsedRate;             // offset 0x10, size 0x4

    virtual ~clsBaseGravityAction() {}
    virtual void reset();

    f32 getUsedRate() const { return m_f32UsedRate; }
    f32 getRange() const { return m_f32Range; }

    static f32 t_of32DefaultRange;
    static f32 t_of32DefaultUsedRate;
};

#endif // BASEGRAVITYACTION_HPP
