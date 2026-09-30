#ifndef LIBSCF_H
#define LIBSCF_H

#include "usr/local/sce/ee/lib/libcdvd/cdvd000.h"

// RECONSTRUCTED: language constant names.
#define SCE_JAPANESE_LANGUAGE 0
#define SCE_ENGLISH_LANGUAGE 1
#define SCE_FRENCH_LANGUAGE 2
#define SCE_SPANISH_LANGUAGE 3
#define SCE_GERMAN_LANGUAGE 4
#define SCE_ITALIAN_LANGUAGE 5
#define SCE_DUTCH_LANGUAGE 6
#define SCE_PORTUGUESE_LANGUAGE 7

#ifdef __cplusplus
extern "C" {
#endif

int sceScfGetLanguage(void);
void sceScfGetLocalTimefromRTC(struct sceCdCLOCK* rtc);

#ifdef __cplusplus
}
#endif

#endif // LIBSCF_H
