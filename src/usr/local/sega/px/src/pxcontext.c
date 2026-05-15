#include "usr/local/sega/px/src/pxcontext.h"

void PXInitContext(enum PXE_CTX context) {
    unsigned long * p;
	int i;

    p = (unsigned long *)&pxg_context[context & 0xFF];
    i = 0;
    do {
        p[0] = 0;
        i += 7;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        p[8] = 0;
        p[9] = 0;
        p[10] = 0;
        p[11] = 0;
        p[12] = 0;
        p[13] = 0;
        p += 14;
    } while (i < 15);
    p[0] = 0;
    p[1] = 0;
}
