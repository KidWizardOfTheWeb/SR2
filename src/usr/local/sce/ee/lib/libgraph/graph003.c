#include "include\usr\local\sce\ee\lib\libgraph\graph003.h"

extern void syscall(int);

void _GetGsDxDyOffset(void) {
    syscall(0x80);
}