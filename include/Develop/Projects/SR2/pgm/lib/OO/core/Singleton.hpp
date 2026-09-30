#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include "types.h"

template <class T>
class clsSingleton {
public:
    clsSingleton()
    {
        // RECONSTRUCTED: integer adjustment preserves MWCC code generation.
        s32 s32Offset =
            1 - reinterpret_cast<s32>(static_cast<clsSingleton<T>*>(reinterpret_cast<T*>(1)));
        m_tpcSingleton = reinterpret_cast<T*>(reinterpret_cast<s32>(this) + s32Offset);
    }
    virtual ~clsSingleton() { m_tpcSingleton = NULL; }
    static T* GS() { return m_tpcSingleton; }
    static T& RS() { return *GS(); }
    static T* m_tpcSingleton;
};

template <class T>
T* clsSingleton<T>::m_tpcSingleton = NULL;

#endif // SINGLETON_HPP
