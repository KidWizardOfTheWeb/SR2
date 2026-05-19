#include "Develop/Projects/SR2/pgm/src/System/Movie.hpp"

namespace {

clsMovie_Task::stcSubTitleFontDetail osSubTitleFontDetail_Opening_J[23];
clsMovie_Task::stcSubTitleFontDetail osSubTitleFontDetail_Insert_J[11];
clsMovie_Task::stcSubTitleFontDetail osSubTitleFontDetail_Ending_J[31];
clsMovie_Task::stcSubTitleFontDetail osSubTitleFontDetail_Opening_E[23];
clsMovie_Task::stcSubTitleFontDetail osSubTitleFontDetail_Insert_E[11];
clsMovie_Task::stcSubTitleFontDetail osSubTitleFontDetail_Ending_E[31];
clsMovie_Task::stcSubTitleFontDetail* oasSubTitleFontDetail_Opening[2];
clsMovie_Task::stcSubTitleFontDetail* oasSubTitleFontDetail_Insert[2];
clsMovie_Task::stcSubTitleFontDetail* oasSubTitleFontDetail_Ending[2];

} // namespace

stcData clsMovie_Task::m_otsData[14];
s32 SUB_TITLE_POS_Y_60;
s32 OFF_WII_Y;

clsMovie_Task::clsMovie_Task(enmDataNo eDataNoI,
                             s32 s32DrawXI,
                             s32 s32DrawYI,
                             clsCriMovie::enmLoopFlag eLoopI,
                             clsCriMovie::enmSubTitle eSubTitleI,
                             u32 u32CancelActiveKeyI,
                             enmDeleteType eDeleteTypeI,
                             s32 s32PadNoI,
                             bool* pbOutSideFinishFlagI,
                             enmAllocate eAllocateI,
                             s32 s32DrawWI,
                             s32 s32DrawHI)
    : clsPfMovie(m_otsData[eDataNoI],
                 s32DrawXI,
                 s32DrawYI,
                 eLoopI,
                 eSubTitleI,
                 eAllocateI,
                 s32DrawWI,
                 s32DrawHI),
      clsTask(0, 0), m_u32CancelActiveKey(u32CancelActiveKeyI),
      m_pbOutSideFinishFlag(pbOutSideFinishFlagI), m_eDeleteType(eDeleteTypeI),
      m_bDolbyDigital_Old_PS2(0), m_s8PadNo(s32PadNoI)
{
}

void clsMovie_Task::execute()
{
}

f32 clsMovie_Task::getEndTimeSubTitle(const stcSubTitleFontDetail* opsSubTitleFontDetail)
{
    return 0.0f;
}

void clsMovie_Task::draw()
{
}
