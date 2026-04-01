#ifndef TYPES_H
#define TYPES_H

typedef signed char      int8_t;
typedef short            int16_t;
typedef int              int32_t;
typedef long long        int64_t;

typedef unsigned char    uint8_t;
typedef unsigned short   uint16_t;
typedef unsigned int     uint32_t;
typedef unsigned long long uint64_t;

typedef uint8_t     uchar;
typedef uint16_t    ushort;
typedef uint32_t    uint;

typedef uchar   undefined1;
typedef ushort  undefined2;
typedef uint    undefined4;

#ifdef _WIN32
    typedef unsigned long ulong;
#else
    typedef unsigned int ulong;
#endif

typedef ulong   undefined8;

typedef int32_t s32;

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
typedef unsigned int size_t;
#endif

#endif // TYPES_H
