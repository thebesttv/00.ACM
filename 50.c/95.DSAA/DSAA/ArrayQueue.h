#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include "base.h"

template <typename T>
class ArrayQueue {
private:
    T *v;
    int _size, head, tail;

public:
    ArrayQueue(){
        head = tail = 0;
        v = new T [_size = QUEUE_SIZE];
    }
    ~ArrayQueue(){
        delete [] v;
    }

    bool empty();
    int size();
    T front();
    T back();
    void push(T);
    void pop();
    void expand();
    void print(const char *s = nullptr);
};

template<typename T>
bool ArrayQueue<T>::empty()
{
    return head==tail;
}

template<typename T>
int ArrayQueue<T>::size()
{
    return tail-head;
}

template<typename T>
T ArrayQueue<T>::front()
{
    if(empty()){
        throw "ArrayQueue: trying to access empty queue";
    }
    return v[head];
}

template<typename T>
T ArrayQueue<T>::back()
{
    if(empty()){
        throw "ArrayQueue: trying to access empty queue";
    }
    return v[tail-1];
}

template<typename T>
void ArrayQueue<T>::push(T x)
{
    if(tail == _size)
        expand();
    v[tail++] = x;
}

template<typename T>
void ArrayQueue<T>::pop()
{
    if(empty()){
        throw "ArrayQueue: trying to pop empty queue";
    }
    ++head;
}

template<typename T>
void ArrayQueue<T>::expand()
{
#ifdef DEBUG
    printf("  ArrayQueue: expand to %d\n",_size*2);
#endif
    T *tv = new T [_size*2];
    int i=0;
    while(head<tail){
        tv[i++] = v[head++];
    }
    delete [] v;
    v = tv;
    head = 0, tail = i;
    _size *= 2;
}

template<typename T>
void ArrayQueue<T>::print(const char *s)
{
    if(s) printf("%s: ",s);
    printf("ArrayQueue(%d,%d):",size(),_size);
    for(int i=head;i<tail;++i)
        std::cout << " " << v[i];
    std::cout << std::endl;
}


#endif
