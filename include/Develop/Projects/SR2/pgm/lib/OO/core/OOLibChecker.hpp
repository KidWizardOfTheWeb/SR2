#ifndef OOLIBCHECKER_HPP
#define OOLIBCHECKER_HPP

#include "types.h"

// Debug hooks called from constructors/destructors with the class name.
// Both are empty in the release build but are still emitted (weak) and called.
namespace nspOOLibChecker {
inline void ClassC(const c8* opc8ClassNameI) {}
inline void ClassD(const c8* opc8ClassNameI) {}
} // namespace nspOOLibChecker

#endif // OOLIBCHECKER_HPP
