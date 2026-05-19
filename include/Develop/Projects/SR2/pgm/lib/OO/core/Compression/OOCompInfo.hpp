#ifndef OOCOMPINFO_HPP
#define OOCOMPINFO_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/Compression/OOCompression.hpp"

namespace nspComp {
struct _CompHeader;

bool isCompData(const _CompHeader& rsParam1);
void setupDecodeObject(const _CompHeader& rsParam1, clsOOCompression& rcParam2);
} // namespace nspComp

#endif // OOCOMPINFO_HPP
