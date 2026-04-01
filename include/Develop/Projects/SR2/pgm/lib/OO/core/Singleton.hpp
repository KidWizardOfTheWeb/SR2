#ifndef SINGLETON_HPP
#define SINGLETON_HPP

// Singleton base class — provides a global instance pointer per type (header-only template)
template<class T>
class clsSingleton {
public:
    static T* m_tpcSingleton;
};

#endif // SINGLETON_HPP
