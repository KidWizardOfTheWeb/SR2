#include "Develop/Projects/SR2/pgm/src/Object/Player/Character/CharaNodeBase.hpp"

s8 clsCharaNodeBase::as8ConvertTable[52] = {0,  1,  2,  3,  4,  5,  6,  7,  14, 15, 16, 17, -1,
                                            18, 19, -1, 20, 21, 22, 23, 24, -1, 25, 26, -1, 27,
                                            -1, -1, -1, 29, 30, 31, 32, 33, 34, 35, 36, 44, 8,
                                            9,  10, 11, 12, 13, 28, 37, 38, 39, 40, 41, 42, 43};

s8 clsCharaNodeBase::getNodeIndex(clsCharacter::enmCharaBornNo bornNo) const
{
    return 0;
}

clsCharaNodeBase::clsCharaNodeBase(clsPlayerTask* pTask, u8 a, u8 b) : clsCharacter(pTask, a, b)
{
}
