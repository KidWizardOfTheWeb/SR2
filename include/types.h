#ifndef TYPES_H
#define TYPES_H

typedef char               c8;

typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;
typedef signed long long   s64;

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

#ifndef SR2_SIZE_T_DEFINED
#define SR2_SIZE_T_DEFINED
#ifdef __MWERKS__
typedef u32 size_t;
#elif defined(__SIZE_TYPE__)
typedef __SIZE_TYPE__ size_t;
#else
typedef u64 size_t;
#endif
#endif

typedef float  f32;
typedef double f64;

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#endif // TYPES_H
