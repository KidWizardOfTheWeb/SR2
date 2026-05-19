#include "Develop/Projects/SR2/pgm/lib/OO/core/OOSemaphore.hpp"

clsOOSemaphore* (*clsOOSemaphore::s_pfCreateFunc)(s32, s32);
void (*clsOOSemaphore::s_pfDeleteFunc)(clsOOSemaphore*);
