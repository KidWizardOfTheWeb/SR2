#ifndef LIBC_FPRINTF_H
#define LIBC_FPRINTF_H

#ifdef __cplusplus
extern "C" {
#endif

signed int fprintf(void* stream, const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif // LIBC_FPRINTF_H
