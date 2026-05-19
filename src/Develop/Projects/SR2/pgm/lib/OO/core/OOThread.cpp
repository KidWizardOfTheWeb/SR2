#include "Develop/Projects/SR2/pgm/lib/OO/core/OOThread.hpp"

clsOOThread* (*clsOOThread::s_pfCreateFunc)();
void (*clsOOThread::s_pfDelayFunc)(u32);
void (*clsOOThread::s_pfSleepFunc)();

clsOOThread::clsOOThread()
{
}
