#ifndef PLAYERPHYSIC_HPP
#define PLAYERPHYSIC_HPP

class clsPlayerTask;
class hkCharacterProxy;
class hkSimpleShapePhantom;
class hkShape;
class clsSimpleShapePhantom;

// total size: 0x2E0
class clsPlayerPhysic {
public:
    class clsPlayerTask*           m_pcPlayer;              // offset 0x000, size 0x4
    class hkCharacterProxy*        m_pcProxy;               // offset 0x004, size 0x4
    class hkSimpleShapePhantom*    m_pcPhantom;             // offset 0x008, size 0x4
    class hkShape*                 m_pcShape;               // offset 0x00C, size 0x4
    class clsSimpleShapePhantom*   m_pcAttackPhantom;       // offset 0x010, size 0x4
    unsigned char                  pad_0x14[0x2A0];         // offset 0x014
    float                          m_f32AttackRadius;       // offset 0x2B4, size 0x4
    float                          m_f32Radius;             // offset 0x2B8, size 0x4
    unsigned int                   m_u32HitFlg;             // offset 0x2BC, size 0x4
    float                          m_f32InvalidFrame;       // offset 0x2C0, size 0x4
    unsigned char                  m_bIsAttack;             // offset 0x2C4, size 0x1
    unsigned char                  m_u8ColInfoNo;           // offset 0x2C5, size 0x1
    unsigned char                  pad_0x2C6[2];            // offset 0x2C6
    unsigned int                   m_cMaskColFilter;        // offset 0x2C8, size 0x4  (clsFlag)
    int                            m_enColUpdateType;       // offset 0x2CC, size 0x4
    unsigned char                  pad_0x2D0[0x10];         // offset 0x2D0  (hkVector4 m_cBackupVelocity)
};

#endif // PLAYERPHYSIC_HPP
