#ifndef SINGLETON_HPP
#define SINGLETON_HPP

// Singleton base class — provides a global instance pointer per type (header-only template)
template <class T>
class clsSingleton {
public:
    clsSingleton() { m_tpcSingleton = static_cast<T*>(this); }
    virtual ~clsSingleton() {}
    static T* GS() { return m_tpcSingleton; }
    static T& RS() { return *m_tpcSingleton; }
    static T* m_tpcSingleton;
};

template <class T>
T* clsSingleton<T>::m_tpcSingleton = 0;

#endif // SINGLETON_HPP
