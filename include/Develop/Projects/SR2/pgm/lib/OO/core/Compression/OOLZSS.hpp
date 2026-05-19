#ifndef OOLZSS_HPP
#define OOLZSS_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOBuffer.hpp"
#include "Develop/Projects/SR2/pgm/src/Script/ScriptShadow.hpp"
#include "types.h"

// total size: 0x58
class clsOOLZSS : public clsOOCompModelObj {
public:
    virtual ~clsOOLZSS() {}

    virtual s32 done(clsOOBuffer& rcDstBuf,
                     clsOOBuffer& rcSrcBuf,
                     bool bIsComp,
                     const volatile u32& rvu32IsAbort);
    virtual s32 done(clsOOBuffer& rcDstBuf,
                     clsOORingBuffer& rcSrcBuf,
                     bool bIsComp,
                     const volatile u32& rvu32IsAbort);
    virtual s32 done(clsOORingBuffer& rcDstBuf,
                     clsOOBuffer& rcSrcBuf,
                     bool bIsComp,
                     const volatile u32& rvu32IsAbort);
    virtual s32 done(clsOORingBuffer& rcDstBuf,
                     clsOORingBuffer& rcSrcBuf,
                     bool bIsComp,
                     const volatile u32& rvu32IsAbort);

    void calcEncodeData(u32 u32Param1, u32 u32Param2) {}
    void calcFalseEncodeData(u8 u8Param1) {}
    s32 readDecodeValue(const u8*& rpu8Param1, s32& rs32Param2, s32& rs32Param3, s32 s32Param4)
    {
        return 0;
    }

    template <class TDstBuf, class TSrcBuf>
    s32 encode(TDstBuf& rcDstBuf, TSrcBuf& rcSrcBuf, const volatile u32& rvu32IsAbort)
    {
        return 0;
    }

    template <class TDstBuf, class TSrcBuf>
    s32 decode(TDstBuf& rcDstBuf, TSrcBuf& rcSrcBuf, const volatile u32& rvu32IsAbort)
    {
        return 0;
    }

    u8 m_u8DictionaryWidthBit; // offset 0x4, size 0x1
    u8 m_u8SearchLengthBit;    // offset 0x5, size 0x1
    u8 m_u8DictionaryWidth;    // offset 0x6, size 0x1
    u8 m_u8SearchLength;       // offset 0x7, size 0x1
    u8 m_u8MinEncodeSize;      // offset 0x8, size 0x1
    u8 m_u8EncodeBitLength;    // offset 0x9, size 0x1
    u8 m_u8EncodeBuf[64];      // offset 0xA, size 0x40
    u32 m_u32EncodeDataBitNum; // offset 0x4C, size 0x4
    u8* m_pu8EncodePos;        // offset 0x50, size 0x4
    u8 m_bEncodeFraction;      // offset 0x54, size 0x1
};

#endif // OOLZSS_HPP
