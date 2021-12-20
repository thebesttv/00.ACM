#ifndef JJALLOC_H
#define JJALLOC_H

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

namespace JJ {

template <class T>
inline T* _allocate(ptrdiff_t size, T*){
    std::set_new_handler(nullptr);
    T* tmp = (T*)(::operator new((size_t) (size * sizeof(T))));
    if(!tmp){
        std::cerr << "out of memory" << std::endl;
        exit(1);
    }
    return tmp;
}

template <class T>
inline void _deallocate(T* buffer){
    ::operator delete(buffer);
}

template <class T1, class T2>
inline void _construct(T1 *p, const T2 &value){
    new(p) T1(value);   // placement new, use value to construct T1
}

template <class T>
inline void _destroy(T *ptr){
    ptr->~T();
}

template <class T>
class allocator {
public:
    typedef T           value_type;
    typedef T*          pointer;
    typedef const T*    const_pointer;
    typedef T&          reference;
    typedef const T&    const_reference;
    typedef size_t      size_type;
    typedef ptrdiff_t   difference_type;

    // rebind allocator of type U
    // ???
    template <class U>
    struct rebind{
        typedef allocator<U> other;
    };

    pointer allocate(size_type n, const void *hint = 0){
        return _allocate((difference_type)n, (pointer)0);
    }

    void deallocate(pointer p, size_type n) { _deallocate(p); }

    void construct(pointer p, const T& value){
        _construct(p, value);
    }

    void destroy(pointer p){
        _destroy(p);
    }

    pointer address(reference x) { return (pointer)&x; }

    const_pointer const_address(const_reference x) {
        return (const_pointer)&x;
    }

    size_type max_size() const {
        return size_type(UINT_MAX/sizeof(T));
    }
};
}   // end of namespace JJ

#endif // JJALLOC_H
