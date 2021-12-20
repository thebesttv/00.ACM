#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "base.h"

template <typename T>
class ListQueue {
private:
    struct Node{
        T v;
        Node *next;
        Node(T v): v(v){
            next = nullptr;
        }
    }*head, *tail;
    int _size;

public:
    ListQueue(){
        head = tail = nullptr;
        _size = 0;
    }
    ~ListQueue(){
        while(!empty())
            pop();
    }

    bool empty();
    int size();
    T front();
    T back();
    void push(T);
    void pop();
    void print(const char *s = nullptr);
};

template<typename T>
bool ListQueue<T>::empty()
{
    return !_size;
}

template<typename T>
int ListQueue<T>::size()
{
    return _size;
}

template<typename T>
T ListQueue<T>::front()
{
    if(empty()){
        throw "ListQueue: trying to access empty queue";
    }
    return head->v;
}

template<typename T>
T ListQueue<T>::back()
{
    if(empty()){
        throw "ListQueue: trying to access empty queue";
    }
    return tail->v;
}

template<typename T>
void ListQueue<T>::push(T x)
{
    Node *p = new Node(x);
    if(tail)
        tail->next = p;
    else
        head = p;
    tail = p;
    ++_size;
}

template<typename T>
void ListQueue<T>::pop()
{
    if(empty()){
        throw "ListQueue: trying to pop empty queue";
    }
    Node *p = head;
    head = head->next;
    delete p;
    --_size;
    if(!_size) tail = nullptr;
}

template<typename T>
void ListQueue<T>::print(const char *s)
{
    if(s) printf("%s: ",s);
    printf("ListQueue(%d):",_size);
    Node *p = head;
    while(p){
        std::cout << " " << p->v;
        p = p->next;
    }
    if(head) std::cout << ", head: " << head->v;
    if(tail) std::cout << ", tail: " << tail->v;
    std::cout << std::endl;
}

#endif // LISTQUEUE_H
