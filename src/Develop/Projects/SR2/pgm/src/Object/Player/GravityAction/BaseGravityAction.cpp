#include "Develop/Projects/SR2/pgm/src/Object/Player/GravityAction/BaseGravityAction.hpp"

f32 clsBaseGravityAction::t_of32DefaultRange = 30.0f;
f32 clsBaseGravityAction::t_of32DefaultUsedRate = 1.0f;

void clsBaseGravityAction::reset()
{
    m_f32Range = m_f32DefaultRange;
    m_f32UsedRate = m_f32DefaultUsedRate;
}
