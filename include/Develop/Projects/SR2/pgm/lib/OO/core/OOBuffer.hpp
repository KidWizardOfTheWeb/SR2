#ifndef OOBUFFER_HPP
#define OOBUFFER_HPP
#include "types.h"
#include "Develop/Projects/SR2/pgm/lib/OO/core/OOHeapFragment.hpp"

// total size: 0x2C
class clsOOBufferBase {
public:
    virtual ~clsOOBufferBase() {}
    virtual u8* read(s32& rs32ReadSize) = 0;
    virtual u8* read(s32& rs32ReadSize, s32& rs32ReadLimit) = 0;
    virtual s32 write(const u8* pu8Data, s32 s32Size) = 0;
    virtual s32 putData(u8 u8Data) = 0;
    virtual u8* getWriteBuffer(s32& rs32WriteSize) = 0;
    virtual void wroteBuffer(u32 u32Size) = 0;
    virtual void clear()
    {
        m_pu8WP = m_pu8Buf;
        m_pu8RP = m_pu8Buf;
        m_s32ReadDataSize = 0;
        m_s32WriteDataSize = 0;
        m_u32IsWriteClosed = 0;
    }

    u8 isReadComplete() { return m_u32IsWriteClosed && m_s32ReadDataSize >= m_s32WriteDataSize; }

    clsOOHeapFragment* m_pcHeap; // offset 0x4, size 0x4
    u8* m_pu8Buf;                // offset 0x8, size 0x4
    u8* m_pu8BufEndPos;          // offset 0xC, size 0x4
    u8* m_pu8RP;                 // offset 0x10, size 0x4
    u8* m_pu8WP;                 // offset 0x14, size 0x4
    s32 m_s32BufSize;            // offset 0x18, size 0x4
    s32 m_s32Align;              // offset 0x1C, size 0x4
    s32 m_s32ReadDataSize;       // offset 0x20, size 0x4
    s32 m_s32WriteDataSize;      // offset 0x24, size 0x4
    u32 m_u32IsWriteClosed;      // offset 0x28, size 0x4
};

// total size: 0x2C
class clsOOBuffer : public clsOOBufferBase {
public:
    virtual ~clsOOBuffer() {}

    virtual u8* read(s32& rs32ReadSize)
    {
        rs32ReadSize = m_s32WriteDataSize - m_s32ReadDataSize;
        u8* pu8Read = m_pu8RP;
        m_pu8RP += rs32ReadSize;
        m_s32ReadDataSize += rs32ReadSize;
        return pu8Read;
    }

    virtual u8* read(s32& rs32ReadSize, s32& rs32ReadLimit)
    {
        rs32ReadSize = m_s32WriteDataSize - m_s32ReadDataSize;
        if (m_s32ReadDataSize < rs32ReadLimit) {
            rs32ReadLimit = m_s32ReadDataSize;
        }
        u8* pu8Read = m_pu8RP;
        m_pu8RP += rs32ReadSize;
        m_s32ReadDataSize += rs32ReadSize;
        return pu8Read;
    }

    virtual s32 write(const u8* pu8Data, s32 s32Size)
    {
        m_pu8WP += s32Size;
        m_s32WriteDataSize += s32Size;
        return s32Size;
    }

    virtual s32 putData(u8 u8Data)
    {
        *m_pu8WP++ = u8Data;
        m_s32WriteDataSize++;
        return 1;
    }

    virtual u8* getWriteBuffer(s32& rs32WriteSize)
    {
        rs32WriteSize = m_s32BufSize - m_s32WriteDataSize;
        return m_pu8WP;
    }

    virtual void wroteBuffer(u32 u32Size)
    {
        m_pu8WP += u32Size;
        m_s32WriteDataSize += u32Size;
    }

    virtual void clear() { clsOOBufferBase::clear(); }
};

// total size: 0x3C
class clsOORingBuffer : public clsOOBufferBase {
public:
    virtual ~clsOORingBuffer() {}

    virtual u8* read(s32& rs32ReadSize)
    {
        rs32ReadSize = m_s32WriteDataSize - m_s32ReadDataSize;
        if (m_s32CopyBufSize < rs32ReadSize) {
            rs32ReadSize = m_s32CopyBufSize;
        }
        m_s32ReadDataSize += rs32ReadSize;
        return m_pu8CopyBuf;
    }

    virtual u8* read(s32& rs32ReadSize, s32& rs32ReadLimit)
    {
        rs32ReadSize = m_s32WriteDataSize - m_s32ReadDataSize;
        if (m_s32LockOffset < rs32ReadLimit) {
            rs32ReadLimit = m_s32LockOffset;
        }
        if (m_s32ReadDataSize < rs32ReadLimit) {
            rs32ReadLimit = m_s32ReadDataSize;
        }
        if (m_s32CopyBufSize < rs32ReadSize) {
            rs32ReadSize = m_s32CopyBufSize;
        }
        m_s32ReadDataSize += rs32ReadSize;
        return m_pu8CopyBuf;
    }

    virtual s32 write(const u8* pu8Data, s32 s32Size)
    {
        s32 s32Writable =
            m_s32BufSize - (m_s32WriteDataSize - (m_s32ReadDataSize - m_s32LockOffset));
        if (s32Writable <= 0) {
            return 0;
        }
        if (s32Writable < s32Size) {
            s32Size = s32Writable;
        }
        wroteBuffer(s32Size);
        return s32Size;
    }

    virtual s32 putData(u8 u8Data)
    {
        if (m_s32BufSize - (m_s32WriteDataSize - (m_s32ReadDataSize - m_s32LockOffset)) <= 0) {
            return 0;
        }
        *m_pu8WP++ = u8Data;
        if (m_pu8WP == m_pu8BufEndPos) {
            m_pu8WP = m_pu8Buf;
        }
        m_s32WriteDataSize++;
        return 1;
    }

    virtual u8* getWriteBuffer(s32& rs32WriteSize)
    {
        rs32WriteSize = m_s32BufSize - (m_s32WriteDataSize - m_s32ReadDataSize + m_s32LockOffset);
        if (rs32WriteSize <= 0) {
            return 0;
        }
        if (m_pu8BufEndPos < m_pu8WP + rs32WriteSize) {
            rs32WriteSize = m_pu8BufEndPos - m_pu8WP;
        }
        return m_pu8WP;
    }

    virtual void wroteBuffer(u32 u32Size)
    {
        m_pu8WP += u32Size;
        m_s32WriteDataSize += u32Size;
        if (m_pu8BufEndPos <= m_pu8WP) {
            m_pu8WP = m_pu8Buf;
        }
    }

    virtual void clear()
    {
        m_s32LockOffset = 0;
        clsOOBufferBase::clear();
    }

    s32 m_s32WriteAlign;  // offset 0x2C, size 0x4
    u8* m_pu8CopyBuf;     // offset 0x30, size 0x4
    s32 m_s32CopyBufSize; // offset 0x34, size 0x4
    s32 m_s32LockOffset;  // offset 0x38, size 0x4
};

#endif // OOBUFFER_HPP
