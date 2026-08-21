#ifndef MEMSET_H
#define MEMSET_H

#ifdef __cplusplus
extern "C" {
#endif

void* memset(void* ptr,
             int value,
             unsigned int num); // TODO: change "unsigned int num" to "size_t num"

#ifdef __cplusplus
}
#endif

#endif // MEMSET_H
