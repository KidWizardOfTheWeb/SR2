#ifndef PUTFIXEDBURNOBJ_HPP
#define PUTFIXEDBURNOBJ_HPP

#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/BaseGimmick.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickBody.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickObj.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/ModelTypes.hpp"

class clsPutFixedBurnObj_Obj : public clsGimmickObj {
public:
    enum enmMode {
        MODE_INIT = 0,
        MODE_MAIN = 1,
    }; // Note: name collision with global enmMode in Game.hpp

    enum enmMode m_eMode; // offset 0x50, size 0x4
    void* m_pfDrawFunc;   // offset 0x54, size 0x4

    // stub (header): clsPutFixedBurnObj_Obj() : clsGimmickObj() {}
    clsPutFixedBurnObj_Obj();
    virtual ~clsPutFixedBurnObj_Obj();

    virtual void init();
    virtual void setData();
    virtual nspPackId::enm getPackId() const;

    u8 drawObTxMa(clsModelType_OB_TX_MO_MA* pParam1,
                  f32 (*psMtxPal)[4][4],
                  u32* pParam3,
                  f32 (*psMtxWork)[4][4]);
    u8 drawObTxMo(clsModelType_OB_TX_MO_MA* pParam1,
                  f32 (*psMtxPal)[4][4],
                  u32* pParam3,
                  f32 (*psMtxWork)[4][4]);
    u8 drawObTxMoMa(clsModelType_OB_TX_MO_MA* pParam1,
                    f32 (*psMtxPal)[4][4],
                    u32* pParam3,
                    f32 (*psMtxWork)[4][4]);
    u8 drawObTx(clsModelType_OB_TX_MO_MA* pParam1,
                f32 (*pParam2)[4][4],
                u32* pParam3,
                f32 (*pParam4)[4][4]);
    u8 draw(clsModelType_OB_TX_MO_MA* pParam1,
            f32 (*psMtxPal)[4][4],
            u32* pParam3,
            const f32 (*opaNnViewMtx)[4][4],
            f32 (*psMtxWork)[4][4],
            u32 u32Param6);

    static f32 m_tof32CLIP_DISTx2;
};

class clsPutFixedBurnObj_Task : public clsMultiModelGimmick_Task<clsPutFixedBurnObj_Task,
                                                                 clsPutFixedBurnObj_Obj,
                                                                 clsMultiModels> {
public:
    clsPutFixedBurnObj_Task(u32 u32ObjectAreaNum) : clsMultiModelGimmick_Task(0, u32ObjectAreaNum)
    {
    }
    virtual ~clsPutFixedBurnObj_Task() {}

    virtual void execute();
    virtual void draw();
    virtual void reset();
};

#endif // PUTFIXEDBURNOBJ_HPP
