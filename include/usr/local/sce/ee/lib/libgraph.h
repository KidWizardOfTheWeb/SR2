#ifndef LIBGRAPH_H
#define LIBGRAPH_H

#ifdef __cplusplus
extern "C" {
#endif

unsigned long sceGsPutIMR(unsigned long imr);
unsigned long sceGsGetIMR(void);
unsigned long isceGsPutIMR(unsigned long imr);
unsigned long isceGsGetIMR(void);
int sceGsSyncPath(int mode, unsigned short timeout);

#ifdef __cplusplus
}
#endif

#endif /* _LIBGRAPH_H_ */
