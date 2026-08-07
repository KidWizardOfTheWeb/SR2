#ifndef OODEBUGMENUVECTOR_INL
#define OODEBUGMENUVECTOR_INL

struct stcOOReent {
    u32 pad0;
    u32 pad4;
    u32 pad8;
    void* stderr_file;
};
extern stcOOReent* _impure_ptr;
extern "C" s32 fprintf(void*, const c8*, ...);
extern "C" void abort(void);

template <class T>
inline void OODebugSwap(T& lhs, T& rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

inline u32 OODebugCapacity(
    const std::__vector_imp<clsOOSubMenu, std::allocator<clsOOSubMenu>, 0>& v)
{
    return v._capacity;
}

template <>
void std::__vector_imp<clsOOSubMenu, std::allocator<clsOOSubMenu>, 0>::insert(
    clsOOSubMenu* position, u32 count, const clsOOSubMenu& value)
{
    if (count == 0) {
        return;
    }

    u32 maximum = 0x1fffffff;
    if (count > maximum || this->_size > maximum - count) {
        fprintf(_impure_ptr->stderr_file, "vector length error\n");
        abort();
    }

    if (this->_size + count <= this->_capacity) {
        clsOOSubMenu* oldEnd = this->_data + this->_size;
        u32 elementsAfter = oldEnd - position;
        const clsOOSubMenu* valuePtr = &value;

        if (elementsAfter < count) {
            clsOOSubMenu* out = oldEnd;
            while (elementsAfter < count) {
                if (out != 0) {
                    out->m_opc8Name = valuePtr->m_opc8Name;
                    out->m_oFunc = valuePtr->m_oFunc;
                }
                --count;
                ++out;
                ++this->_size;
            }

            clsOOSubMenu* src = position;
            while (src < oldEnd) {
                if (out != 0) {
                    out->m_opc8Name = src->m_opc8Name;
                    out->m_oFunc = src->m_oFunc;
                }
                ++src;
                ++out;
                ++this->_size;
            }
        } else {
            clsOOSubMenu* src = oldEnd - count;
            clsOOSubMenu* out = oldEnd;
            while (src < oldEnd) {
                if (out != 0) {
                    out->m_opc8Name = src->m_opc8Name;
                    out->m_oFunc = src->m_oFunc;
                }
                ++src;
                ++out;
                ++this->_size;
            }

            u32 remaining = elementsAfter - count;
            clsOOSubMenu* insertedEnd = oldEnd - remaining;
            if (insertedEnd <= valuePtr && valuePtr < oldEnd) {
                valuePtr += count;
            }
            clsOOSubMenu* sourceEnd = position + remaining;

            while (position < sourceEnd) {
                --sourceEnd;
                --oldEnd;
                oldEnd->m_opc8Name = sourceEnd->m_opc8Name;
                oldEnd->m_oFunc = sourceEnd->m_oFunc;
            }
        }

        while (count != 0) {
            position->m_opc8Name = valuePtr->m_opc8Name;
            position->m_oFunc = valuePtr->m_oFunc;
            --count;
            ++position;
        }
    } else {
        std::__vector_deleter<clsOOSubMenu, std::allocator<clsOOSubMenu> > temp;

        u32 requiredSize = this->_size + count;
        u32 newCapacity = OODebugCapacity(*this);
        newCapacity = newCapacity ? newCapacity : 1;
        while (requiredSize > newCapacity) {
            if (newCapacity < 0x0fffffff) {
                newCapacity *= 2;
            } else {
                newCapacity = 0x1fffffff;
            }
        }

        clsOOSubMenu* allocated =
            static_cast<clsOOSubMenu*>(::operator new(newCapacity * sizeof(clsOOSubMenu)));
        if (allocated == 0) {
            fprintf(_impure_ptr->stderr_file, "Memory allocation failure");
            abort();
        }
        temp._capacity = newCapacity;
        temp._data = allocated;

        clsOOSubMenu* src = this->_data;
        clsOOSubMenu* oldEnd = this->_data + this->_size;
        clsOOSubMenu* out = temp._data;
        while (src < position) {
            if (out != 0) {
                out->m_opc8Name = src->m_opc8Name;
                out->m_oFunc = src->m_oFunc;
            }
            ++src;
            ++out;
            ++temp._size;
        }

        while (count != 0) {
            if (out != 0) {
                out->m_opc8Name = value.m_opc8Name;
                out->m_oFunc = value.m_oFunc;
            }
            --count;
            ++out;
            ++temp._size;
        }

        while (src < oldEnd) {
            if (out != 0) {
                out->m_opc8Name = src->m_opc8Name;
                out->m_oFunc = src->m_oFunc;
            }
            ++src;
            ++out;
            ++temp._size;
        }

        if (&temp !=
            static_cast<std::__vector_deleter<clsOOSubMenu, std::allocator<clsOOSubMenu> >*>(this))
        {
            OODebugSwap(temp._capacity, this->_capacity);
            OODebugSwap(temp._data, this->_data);
            OODebugSwap(temp._size, this->_size);
        }
    }
}

struct stcDoAssignAllocator {
    u32 max_size() const { return 0x1fffffff; }

    clsOOSubMenu* allocate(u32 count, const void* = 0)
    {
        s64 signedCount = (s32)count;
        clsOOSubMenu* data =
            static_cast<clsOOSubMenu*>(::operator new((u32)signedCount * sizeof(clsOOSubMenu)));
        if (data == 0) {
            fprintf(_impure_ptr->stderr_file, "Memory allocation failure");
            abort();
        }
        return data;
    }

    void construct(clsOOSubMenu* out, const clsOOSubMenu& value)
    {
        if (out != 0) {
            out->m_opc8Name = value.m_opc8Name;
            out->m_oFunc = value.m_oFunc;
        }
    }
};

inline u32 OODebugCapacity(
    const std::__vector_imp<clsOOMainMenu, std::allocator<clsOOMainMenu>, 0>& v)
{
    return v._capacity;
}

inline void OODebugConstructMain(clsOOMainMenu* out,
                                 const clsOOMainMenu& value,
                                 std::forward_iterator_tag tag)
{
    if (out != 0) {
        out->m_opc8Name = value.m_opc8Name;
        out->m_s8SubMenuNum = value.m_s8SubMenuNum;
        out->m_cSubMenu._capacity = 0;
        out->m_cSubMenu._size = 0;
        out->m_cSubMenu._data = 0;
        out->m_cSubMenu.init(
            value.m_cSubMenu._data, value.m_cSubMenu._data + value.m_cSubMenu._size, tag);
    }
}

inline void OODebugAssignMain(clsOOMainMenu* out,
                              const clsOOMainMenu& value,
                              std::forward_iterator_tag tag)
{
    out->m_opc8Name = value.m_opc8Name;
    out->m_s8SubMenuNum = value.m_s8SubMenuNum;
    if (&out->m_cSubMenu != &value.m_cSubMenu) {
        u32 subSize = value.m_cSubMenu._size;
        clsOOSubMenu* subData = value.m_cSubMenu._data;
        out->m_cSubMenu.do_assign(subData, subData + subSize, tag);
    }
}

template <>
void std::__vector_imp<clsOOMainMenu, std::allocator<clsOOMainMenu>, 0>::insert(
    clsOOMainMenu* position, u32 count, const clsOOMainMenu& value)
{
    std::forward_iterator_tag tagConstruct1;
    std::forward_iterator_tag tagConstruct2;
    std::forward_iterator_tag tagConstruct3;
    std::forward_iterator_tag tagConstruct4;
    std::forward_iterator_tag tagConstruct5;
    std::forward_iterator_tag tagConstruct6;
    std::forward_iterator_tag tagAssign1;
    std::forward_iterator_tag tagAssign2;

    if (count == 0) {
        return;
    }

    u32 maximum = 0x0ccccccc;
    if (count > maximum || this->_size > maximum - count) {
        fprintf(_impure_ptr->stderr_file, "vector length error\n");
        abort();
    }

    clsOOMainMenu* out;

    if (this->_size + count <= this->_capacity) {
        clsOOMainMenu* oldEnd = this->_data + this->_size;
        u32 elementsAfter = oldEnd - position;
        const clsOOMainMenu* valuePtr = &value;

        if (elementsAfter < count) {
            out = oldEnd;
            while (elementsAfter < count) {
                OODebugConstructMain(out, *valuePtr, tagConstruct1);
                --count;
                ++out;
                ++this->_size;
            }

            clsOOMainMenu* src = position;
            while (src < oldEnd) {
                OODebugConstructMain(out, *src, tagConstruct2);
                ++src;
                ++out;
                ++this->_size;
            }
        } else {
            clsOOMainMenu* src = oldEnd - count;
            out = oldEnd;
            while (src < oldEnd) {
                OODebugConstructMain(out, *src, tagConstruct3);
                ++src;
                ++out;
                ++this->_size;
            }

            u32 remaining = elementsAfter - count;
            clsOOMainMenu* insertedEnd = oldEnd - remaining;
            if (insertedEnd <= valuePtr && valuePtr < oldEnd) {
                valuePtr += count;
            }

            clsOOMainMenu* sourceEnd = position + remaining;
            while (position < sourceEnd) {
                --sourceEnd;
                --oldEnd;
                OODebugAssignMain(oldEnd, *sourceEnd, tagAssign1);
            }
        }

        while (count != 0) {
            OODebugAssignMain(position, *valuePtr, tagAssign2);
            --count;
            ++position;
        }
    } else {
        struct stcTempVector {
            u32 capacity;
            u32 size;
            clsOOMainMenu* data;
        } temp;
        temp.capacity = 0;
        temp.size = 0;
        temp.data = 0;

        u32 requiredSize = this->_size + count;
        u32 newCapacity = OODebugCapacity(*this);
        newCapacity = newCapacity ? newCapacity : 1;
        while (requiredSize > newCapacity) {
            if (newCapacity < 0x06666666) {
                newCapacity *= 2;
            } else {
                newCapacity = 0x0ccccccc;
            }
        }

        clsOOMainMenu* allocated =
            static_cast<clsOOMainMenu*>(::operator new(newCapacity * sizeof(clsOOMainMenu)));
        if (allocated == 0) {
            fprintf(_impure_ptr->stderr_file, "Memory allocation failure");
            abort();
        }
        temp.capacity = newCapacity;
        temp.data = allocated;

        clsOOMainMenu* src = this->_data;
        clsOOMainMenu* oldEnd = this->_data + this->_size;
        out = temp.data;
        while (src < position) {
            OODebugConstructMain(out, *src, tagConstruct4);
            ++src;
            ++out;
            ++temp.size;
        }

        while (count != 0) {
            OODebugConstructMain(out, value, tagConstruct5);
            --count;
            ++out;
            ++temp.size;
        }

        while (src < oldEnd) {
            OODebugConstructMain(out, *src, tagConstruct6);
            ++src;
            ++out;
            ++temp.size;
        }

        if ((void*)&temp != (void*)this) {
            OODebugSwap(temp.capacity, this->_capacity);
            OODebugSwap(temp.data, this->_data);
            OODebugSwap(temp.size, this->_size);
        }

        clsOOMainMenu* destroyBegin = temp.data;
        clsOOMainMenu* destroyEnd = destroyBegin + temp.size;
        while (destroyBegin < destroyEnd) {
            --destroyEnd;
            if (destroyEnd != 0) {
                destroyEnd->m_cSubMenu.~vector();
            }
        }
        temp.size = 0;
        if (temp.data != 0) {
            ::operator delete(temp.data);
        }
    }
}

template <>
void std::__vector_imp<clsOOMainMenu, std::allocator<clsOOMainMenu>, 0>::reserve(
    u32 requestedCapacity)
{
    if (this->_capacity < requestedCapacity) {
        if (0x0ccccccc < requestedCapacity) {
            fprintf(_impure_ptr->stderr_file, "vector length error\n");
            abort();
        }

        struct stcTempVector {
            u32 capacity;
            u32 size;
            clsOOMainMenu* data;
        } temp;
        temp.capacity = 0;
        temp.size = 0;
        temp.data = 0;

        clsOOMainMenu* allocated =
            static_cast<clsOOMainMenu*>(::operator new(requestedCapacity * sizeof(clsOOMainMenu)));
        if (allocated == 0) {
            fprintf(_impure_ptr->stderr_file, "Memory allocation failure");
            abort();
        }
        temp.capacity = requestedCapacity;
        temp.data = allocated;

        clsOOMainMenu* src = this->_data;
        clsOOMainMenu* oldEnd = src + this->_size;
        clsOOMainMenu* out = temp.data;
        std::forward_iterator_tag tag;
        while (src < oldEnd) {
            OODebugConstructMain(out, *src, tag);
            ++src;
            ++out;
            ++temp.size;
        }

        if ((void*)&temp != (void*)this) {
            OODebugSwap(temp.capacity, this->_capacity);
            OODebugSwap(temp.data, this->_data);
            OODebugSwap(temp.size, this->_size);
        }

        clsOOMainMenu* destroyBegin = temp.data;
        clsOOMainMenu* destroyEnd = destroyBegin + temp.size;
        while (destroyBegin < destroyEnd) {
            --destroyEnd;
            if (destroyEnd != 0) {
                destroyEnd->m_cSubMenu.~vector();
            }
        }
        temp.size = 0;
        if (temp.data != 0) {
            ::operator delete(temp.data);
        }
    }
}

template <class T, class A>
void std::__vector_deleter<T, A>::clear()
{
    T* destroyBegin = this->_data;
    T* destroyEnd = destroyBegin + this->_size;
    while (destroyBegin < destroyEnd) {
        --destroyEnd;
        destroyEnd->~T();
    }
    this->_size = 0;
}

template <class T, class A>
std::__vector_deleter<T, A>::~__vector_deleter()
{
    clear();
    if (this->_data != 0) {
        ::operator delete(this->_data);
    }
}

template <>
template <>
void std::__vector_imp<clsOOSubMenu, std::allocator<clsOOSubMenu>, 0>::init<const clsOOSubMenu*>(
    const clsOOSubMenu* first, const clsOOSubMenu* last, std::forward_iterator_tag)
{
    s32 count = last - first;
    if (0x1fffffff < this->_size) {
        fprintf(_impure_ptr->stderr_file, "vector length error\n");
        abort();
    }

    if (count != 0) {
        clsOOSubMenu** dataField = &this->_data;
        clsOOSubMenu* allocated =
            static_cast<clsOOSubMenu*>(::operator new((u32)count * sizeof(clsOOSubMenu)));
        if (allocated == 0) {
            fprintf(_impure_ptr->stderr_file, "Memory allocation failure");
            abort();
        }
        *dataField = allocated;
        this->_capacity = count;

        clsOOSubMenu* out = this->_data;
        while (first != last) {
            if (out != 0) {
                out->m_opc8Name = first->m_opc8Name;
                out->m_oFunc = first->m_oFunc;
            }
            ++first;
            ++out;
            ++this->_size;
        }
    }
}

template <>
template <>
void std::__vector_imp<clsOOSubMenu, std::allocator<clsOOSubMenu>, 0>::do_assign<
    const clsOOSubMenu*>(const clsOOSubMenu* first,
                         const clsOOSubMenu* last,
                         std::forward_iterator_tag)
{
    stcDoAssignAllocator alloc;
    s32 count = last - first;

    if ((u32)count <= this->_capacity) {
        u32 countTemp;
        const u32* commonCount = this->_size < (u32)count ? &this->_size : &countTemp;
        clsOOSubMenu* outBegin = this->_data;
        clsOOSubMenu* out = outBegin;
        clsOOSubMenu* copyLast = outBegin + *commonCount;
        while (out < copyLast) {
            *out = *first;
            ++out;
            ++first;
        }

        u32 oldSize = this->_size;
        s64 signedCount = count;
        if ((u32)signedCount < oldSize) {
            this->_size = (u32)signedCount;
        } else if (oldSize < (u32)signedCount) {
            while (first != last) {
                alloc.construct(out, *first);
                ++first;
                ++out;
                ++this->_size;
            }
        }
    } else {
        if (alloc.max_size() < (u32)count) {
            fprintf(_impure_ptr->stderr_file, "vector length error\n");
            abort();
        }

        this->_size = 0;
        if (this->_data != 0) {
            ::operator delete(this->_data);
            this->_data = 0;
            this->_capacity = 0;
        }

        clsOOSubMenu** dataField = &this->_data;
        clsOOSubMenu* allocated = alloc.allocate((u32)count, 0);
        *dataField = allocated;
        this->_capacity = (s64)count;

        clsOOSubMenu* out = this->_data;
        while (first != last) {
            alloc.construct(out, *first);
            ++first;
            ++out;
            ++this->_size;
        }
    }
}

#endif // OODEBUGMENUVECTOR_INL
