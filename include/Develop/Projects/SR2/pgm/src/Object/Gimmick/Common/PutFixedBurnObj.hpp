#ifndef PUTFIXEDBURNOBJ_HPP
#define PUTFIXEDBURNOBJ_HPP

#include "usr/local/sega/nn/src/System/nnsystem.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPutFixedBurnObj_Obj : public clsGimmickObj {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    };

    enum enmMode m_eMode; // offset 0x50, size 0x4
    void* m_pfDrawFunc;   // offset 0x54, size 0x4

    clsPutFixedBurnObj_Obj() : m_eMode(MODE_INIT) {}
    virtual ~clsPutFixedBurnObj_Obj() { destroyData(); }

    void init();
    virtual void setData();
    virtual nspPackId::enm getPackId() const;

    u8 drawObTxMa(clsModelType_OB_TX_MO_MA* pParam1,
                  NNS_MATRIX* psMtxPal,
                  u32* pParam3,
                  NNS_MATRIX* psMtxWork);
    u8 drawObTxMo(clsModelType_OB_TX_MO_MA* pParam1,
                  NNS_MATRIX* psMtxPal,
                  u32* pParam3,
                  NNS_MATRIX* psMtxWork);
    u8 drawObTxMoMa(clsModelType_OB_TX_MO_MA* pParam1,
                    NNS_MATRIX* psMtxPal,
                    u32* pParam3,
                    NNS_MATRIX* psMtxWork);
    u8 drawObTx(clsModelType_OB_TX_MO_MA* pParam1,
                NNS_MATRIX* pParam2,
                u32* pParam3,
                NNS_MATRIX* pParam4);
    u8 draw(clsModelType_OB_TX_MO_MA* pParam1,
            NNS_MATRIX* psMtxPal,
            u32* pParam3,
            const NNS_MATRIX* opaNnViewMtx,
            NNS_MATRIX* psMtxWork,
            u32 u32Param6);

    static f32 m_tof32CLIP_DISTx2;
};

class clsPutFixedBurnObj_Task : public clsMultiModelGimmick_Task<clsPutFixedBurnObj_Task,
                                                                 clsPutFixedBurnObj_Obj,
                                                                 clsMultiModels> {
public:
    clsPutFixedBurnObj_Task(u32 u32ObjectAreaNum)
        : clsMultiModelGimmick_Task(u32ObjectAreaNum, 490010)
    {
    }
    virtual ~clsPutFixedBurnObj_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PUTFIXEDBURNOBJ_HPP
