#ifndef PLAYERPHYSIC_HPP
#define PLAYERPHYSIC_HPP

#include "types.h"
#include "Develop/Projects/SR2/pgm/src/Havok/HavokHeap.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Collision/CollisionFilter.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Object.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerMotion.hpp"
#include "Develop/Projects/SR2/pgm/src/Object/Player/PlayerStartPointCollector.hpp"

class clsPlayerTask;
class clsSimpleShapePhantom;
class hkShape;

enum enmColUpdateType {
    COL_UPDATE_ALLFRAME = 0,
    COL_UPDATE_ONEFRAME = 1,
    COL_UPDATE_NOT_ONEFRAME = 2,
};

// total size: 0x2E0
class clsPlayerPhysic {
public:
    enum enmColCheckType {
        COL_CHECK_NULL = 0,
        COL_CHECK_NORMAL = 1,
        COL_CHECK_CHARA_UP = 2,
        COL_CHECK_UNDER = 3,
        COL_CHECK_VELOCITY = 4,
    };

    clsPlayerPhysic(clsPlayerTask* pcPlayer, f32 f32Radius);
    ~clsPlayerPhysic();

    void disableAttack();
    void reset();
    void update();
    void setAttackRadius(f32 f32Radius);

    stcInfo& getColInfoRef() { return m_sColInfo[m_u8ColInfoNo]; }
    void setOrColFilter(clsCollisionFilter::enmInfo eInfo) { m_cMaskColFilter |= (u32)eInfo; }
    void setClearColFilter(clsCollisionFilter::enmInfo eInfo) { m_cMaskColFilter &= ~(u32)eInfo; }
    stcInfo* getOldColInfoPtr() const
    {
        return const_cast<stcInfo*>(&m_sColInfo[m_u8ColInfoNo ^ 1]);
    }
    stcInfo* getColInfoPtr() const { return const_cast<stcInfo*>(&m_sColInfo[m_u8ColInfoNo]); }
    hkCharacterProxy* getProxyRef() { return m_pcProxy; }
    void setColInfo(const stcInfo* psInfo) { m_sColInfo[m_u8ColInfoNo] = *psInfo; }
    void switchCollisionInfo() { m_u8ColInfoNo ^= 1; }
    enmColCheckType getCollisionCheckType() const { return m_eCollisionCheckType; }
    clsPlayerTask* getPlayerTaskPtr() { return m_pcPlayer; }
    stcInfo* getPreviousColInfoPtr() const { return const_cast<stcInfo*>(&m_sPreviousColInfo); }
    void setCollisionCheckType(enmColCheckType eColCheckType)
    {
        m_eCollisionCheckType = eColCheckType;
    }
    void setColFilter(clsCollisionFilter::enmInfo eInfo) { m_cMaskColFilter = (u32)eInfo; }

    clsPlayerTask* m_pcPlayer;                         // offset 0x0, size 0x4
    hkCharacterProxy* m_pcProxy;                       // offset 0x4, size 0x4
    hkSimpleShapePhantom* m_pcPhantom;                 // offset 0x8, size 0x4
    hkShape* m_pcShape;                                // offset 0xC, size 0x4
    clsSimpleShapePhantom* m_pcAttackPhantom;          // offset 0x10, size 0x4
    clsPlayerStartPointCollector m_cStartPointCollect; // offset 0x20, size 0x260
    stcInfo m_sColInfo[2];                             // offset 0x280, size 0x20
    stcInfo m_sPreviousColInfo;                        // offset 0x2A0, size 0x10
    enmColCheckType m_eCollisionCheckType;             // offset 0x2B0, size 0x4
    f32 m_f32AttackRadius;                             // offset 0x2B4, size 0x4
    f32 m_f32Radius;                                   // offset 0x2B8, size 0x4
    u32 m_u32HitFlg;                                   // offset 0x2BC, size 0x4
    f32 m_f32InvalidFrame;                             // offset 0x2C0, size 0x4
    u8 m_bIsAttack;                                    // offset 0x2C4, size 0x1
    u8 m_u8ColInfoNo;                                  // offset 0x2C5, size 0x1
    u32 m_cMaskColFilter;                              // offset 0x2C8, size 0x4
    enmColUpdateType m_enColUpdateType;                // offset 0x2CC, size 0x4
    hkVector4 m_cBackupVelocity;                       // offset 0x2D0, size 0x10
};

#endif // PLAYERPHYSIC_HPP
