#ifndef LIBC_VSPRINTFR_H
#define LIBC_VSPRINTFR_H

#ifdef __cplusplus
extern "C" {
#endif

signed int vsprintf(char* pc8Dst, const char* pc8Fmt, char* sVlist);

#ifdef __cplusplus
}
#endif

#endif // LIBC_VSPRINTFR_H
