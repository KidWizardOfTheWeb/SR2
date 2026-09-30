#ifndef ALGORITHM_H
#define ALGORITHM_H

namespace std {
template <class T>
inline const T& min(const T& lhs, const T& rhs)
{
    return rhs < lhs ? rhs : lhs;
}
} // namespace std

#endif // ALGORITHM_H
