#ifndef LIBC_FPRINTF_H
#define LIBC_FPRINTF_H

#include "usr/local/sce/ee/gcc/ee/lib/libc/stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

signed int fprintf(FILE* stream, const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif // LIBC_FPRINTF_H
