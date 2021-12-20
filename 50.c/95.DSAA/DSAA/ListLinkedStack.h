#ifndef __LINKLISTSTACK_H__
#define __LINKLISTSTACK_H__

#include <cstdio>
#include <iostream>

#include "base.h"

template<typename T>
class ListStack {
private:
    struct Node{
        T v;
        Node *next;

        Node(T v): v(v){
            next = nullptr;
        }
    }*head;
    int _size;

public:
    ListStack(){
        head = nullptr;
        _size = 0;
    }
    ~ListStack(){
        while(!empty())
            pop();
    }

    int size();
    bool empty();
    T top();
    void pop();
    void push(T);
    void print(const char *s=nullptr);  // for DEBUG
};

template<typename T>
int ListStack<T>::size()
{
    return _size;
}

template<typename T>
bool ListStack<T>::empty()
{
    return !_size;
}

template<typename T>
T ListStack<T>::top()
{
    if(_size==0){
        throw "ListStack: trying to access empty stack";
    }
    return head->v;
}

template<typename T>
void ListStack<T>::pop()
{
    if(_size==0){
        throw "ListStack: trying to pop empty stack";
    }
    Node *tp = head;
    head = head->next;
    delete tp;
    --_size;
}

template<typename T>
void ListStack<T>::push(T x)
{
    Node *p = new Node(x);
    p->next = head;
    head = p;
    ++_size;
}

template<typename T>
void ListStack<T>::print(const char *s)
{
    if(s) printf("%s ",s);
    printf("ListStack(%d):",_size);
    Node *p = head;
    while(p){
        std::cout << " " << p->v;
        p = p->next;
    }
    std::cout << std::endl;
}

#endif
