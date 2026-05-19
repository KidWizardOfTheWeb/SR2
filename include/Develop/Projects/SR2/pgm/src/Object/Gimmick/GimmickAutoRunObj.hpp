#ifndef GIMMICKAUTORUNOBJ_HPP
#define GIMMICKAUTORUNOBJ_HPP

#include "types.h"
#include "usr/local/sega/nn/src/Matrix/nnvector.h"
#include "Develop/Projects/SR2/pgm/src/Object/Gimmick/GimmickPath.hpp"

class clsPlayerTask;

// total size: 0xC
class clsGimmickAutoRunBufferBase {
public:
    u32 m_u32ExecuteNum; // offset 0x0, size 0x4
    u32 m_u32SleepNum;   // offset 0x4, size 0x4
    u32 m_u32ObjectNum;  // offset 0x8, size 0x4

    u32 getExecuteNum() const { return m_u32ExecuteNum; }
};

template <class T>
class clsGimmickAutoRunBuffer : public clsGimmickAutoRunBufferBase {
public:
    void create(u32 u32Num)
    {
        m_apcObj = new T[u32Num];
        m_ppcExecuteWork = new T*[u32Num * 3];
        for (u32 i = 0; i < u32Num * 3; i++) {
            m_ppcExecuteWork[i] = 0;
        }
        m_ppcExecute = m_ppcExecuteWork + u32Num;
        m_ppcSleep = m_ppcExecute + u32Num;
        m_u32ObjectNum = u32Num;
        m_u32ExecuteNum = 0;
        m_u32SleepNum = 0;
        initSleep();
    }

    void destroy()
    {
        delete[] m_ppcExecuteWork;
        m_ppcExecuteWork = 0;
        delete[] m_apcObj;
        m_apcObj = 0;
        m_u32ExecuteNum = 0;
        m_u32SleepNum = 0;
        m_u32ObjectNum = 0;
    }

    void initSleep()
    {
        m_u32SleepNum = 0;
        for (u32 i = 0; i < m_u32ObjectNum; i++) {
            setSleep(&m_apcObj[i]);
        }
    }

    void reset()
    {
        m_u32ExecuteNum = 0;
        initSleep();
    }

    void execute()
    {
        for (u32 i = 0; i < m_u32ExecuteNum; i++) {
            m_ppcExecuteWork[i] = m_ppcExecute[i];
        }
        for (u32 i = 0; i < m_u32ExecuteNum; i++) {
            m_ppcExecuteWork[i]->execute();
        }
    }

    T** getExecute(u32 u32Num) { return m_ppcExecute + u32Num; }

    T* getSleep()
    {
        if (m_u32SleepNum == 0) {
            return 0;
        }
        m_u32SleepNum--;
        return m_ppcSleep[m_u32SleepNum];
    }

    void setExecute(T* pcObj)
    {
        m_ppcExecute[m_u32ExecuteNum] = pcObj;
        m_u32ExecuteNum++;
    }

    void setSleep(T* pcObj)
    {
        pcObj->destroy();
        m_ppcSleep[m_u32SleepNum] = pcObj;
        m_u32SleepNum++;
    }

    void elaseExexute(T* pcObj)
    {
        for (u32 i = 0; i < m_u32ExecuteNum; i++) {
            if (m_ppcExecute[i] == pcObj) {
                for (u32 j = i; j + 1 < m_u32ExecuteNum; j++) {
                    m_ppcExecute[j] = m_ppcExecute[j + 1];
                }
                m_u32ExecuteNum--;
                break;
            }
        }
        setSleep(pcObj);
    }

    T* m_apcObj;          // offset 0xC, size 0x4
    T** m_ppcExecute;     // offset 0x10, size 0x4
    T** m_ppcSleep;       // offset 0x14, size 0x4
    T** m_ppcExecuteWork; // offset 0x18, size 0x4
};

// total size: 0x1C0
class clsGimmickAutoRunObj {
public:
    // Note: enmRet name collision with nspOOFileMgr::enmRet ? nested per scaffold rule
    enum enmRet {
        VISIBLE_CLIP = 0,
        VISIBLE = 1,
        OUT_VISIBLE = 2,
        OUT_PORTAL = 3,
        OUT_FAR = 4,
    };

    virtual ~clsGimmickAutoRunObj() {}
    virtual void destroy() {}

    void setPathPosition(u32 u32PathNo, f32 f32Speed, f32 f32TotalFrame, f32 f32OffsetY);
    void setPathMove(const NNS_VECTORFAST& rsNextPosVecFast,
                     const NNS_QUATERNION& rsQuat,
                     f32 f32InterpoRate,
                     const NNS_VECTORFAST& rsOffsetVecFast);
    void setPathPostural(const NNS_QUATERNION& rsRotQuat, f32 f32InterpoRate);
    void setPathVelocity(const NNS_VECTORFAST& rsNextPosVecFast,
                         const NNS_QUATERNION& rsQuat,
                         const NNS_VECTORFAST& rsOffsetVecFast);

    void setPlayerTaskPtr(clsPlayerTask* pcPlayer) { m_pcPlayerTask = pcPlayer; }
    NNS_QUATERNION& getRotQuatRef() { return m_sRotQuat; }
    NNS_VECTORFAST& getPosVecFastRef() { return m_sPosVecFast; }
    clsGimmickPath& getGimmickPathRef() { return m_cGimmickPath; }

    enmRet m_eClipRet;             // offset 0x4, size 0x4
    clsPlayerTask* m_pcPlayerTask; // offset 0x8, size 0x4
    NNS_VECTORFAST m_sPosVecFast;  // offset 0x10, size 0x10
    NNS_QUATERNION m_sRotQuat;     // offset 0x20, size 0x10
    clsGimmickPath m_cGimmickPath; // offset 0x30, size 0x190
};

#endif // GIMMICKAUTORUNOBJ_HPP
