#include "vector.h"

template<typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi){
    _elem = new T [_capacity = (hi - lo) * 2];
    _size = 0;
    while(lo < hi)
        _elem[_size++] = A[lo++];
}

template<typename T> Vector<T>& Vector<T>::operator= (Vector<T> const &V){
}