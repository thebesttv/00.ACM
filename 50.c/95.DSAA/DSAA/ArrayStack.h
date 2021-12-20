#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#include "base.h"

template<typename T>
class ArrayStack {
private:
    T *v;
    int head,_size;
  
public:
    ArrayStack(){
        head = 0;
        v = new T [_size = STACK_SIZE];
    }
    ~ArrayStack(){
        delete [] v;
    }

    int size();
    bool empty();
    T top();
    void pop();
    void push(T);
    void expand();
    void print(const char *s=nullptr);  // for DEBUG
};


template<typename T>
int ArrayStack<T>::size()
{
    return head;
}

template<typename T>
bool ArrayStack<T>::empty()
{
    return !head;
}

template<typename T>
T ArrayStack<T>::top()
{
    if(head==0){
        throw "ArrayStack: trying to access empty stack";
    }
    return v[head-1];
}

template<typename T>
void ArrayStack<T>::pop()
{
    if(head==0){
        throw "ArrayStack: trying to pop empty stack";
    }
    --head;
}

template<typename T>
void ArrayStack<T>::push(T x)
{
    if(head==_size)
        expand();
    v[head++] = x;
}

template<typename T>
void ArrayStack<T>::expand()
{
#ifdef DEBUG
    printf("  stack expand to %d\n",_size*2);
#endif
    T *tv = new T [_size*2];
    for(int i=0;i<head;++i)
        tv[i] = v[i];
    delete [] v;
    v = tv;
    _size *= 2;
}

template<typename T>
void ArrayStack<T>::print(const char *s)
{
    if(s) printf("%s ",s);
    printf("ArrayStack(%d,%d):",head,_size);
    for(int i=head-1;i>=0;--i)
        std::cout << " " << v[i];
    std::cout << std::endl;
}

#endif
