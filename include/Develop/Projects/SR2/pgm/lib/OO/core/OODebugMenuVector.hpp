#ifndef OODEBUGMENUVECTOR_HPP
#define OODEBUGMENUVECTOR_HPP

#include "Develop/Projects/SR2/pgm/lib/OO/core/OOVector.hpp"

class clsOOSubMenu;
class clsOOMainMenu;

namespace std {

template <>
void __vector_imp<clsOOSubMenu, allocator<clsOOSubMenu>, 0>::insert(clsOOSubMenu* position,
                                                                    u32 count,
                                                                    const clsOOSubMenu& value);

template <>
void __vector_imp<clsOOMainMenu, allocator<clsOOMainMenu>, 0>::insert(clsOOMainMenu* position,
                                                                      u32 count,
                                                                      const clsOOMainMenu& value);

template <>
void __vector_imp<clsOOMainMenu, allocator<clsOOMainMenu>, 0>::reserve(u32 requestedCapacity);

template <>
void __vector_deleter<clsOOSubMenu, allocator<clsOOSubMenu> >::clear();

template <>
void __vector_deleter<clsOOMainMenu, allocator<clsOOMainMenu> >::clear();

template <>
__vector_deleter<clsOOSubMenu, allocator<clsOOSubMenu> >::~__vector_deleter();

template <>
__vector_deleter<clsOOMainMenu, allocator<clsOOMainMenu> >::~__vector_deleter();

template <>
template <>
void __vector_imp<clsOOSubMenu, allocator<clsOOSubMenu>, 0>::init<const clsOOSubMenu*>(
    const clsOOSubMenu* first, const clsOOSubMenu* last, forward_iterator_tag);

template <>
template <>
void __vector_imp<clsOOSubMenu, allocator<clsOOSubMenu>, 0>::do_assign<const clsOOSubMenu*>(
    const clsOOSubMenu* first, const clsOOSubMenu* last, forward_iterator_tag);

} // namespace std

#endif // OODEBUGMENUVECTOR_HPP
