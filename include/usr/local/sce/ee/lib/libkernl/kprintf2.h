#ifndef KPRINTF2_H
#define KPRINTF2_H

#ifdef __cplusplus
extern "C" {
#endif

int scePrintf(const char* format, ...);
int sceSnprintf(char* buffer, int size, const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif // KPRINTF2_H
