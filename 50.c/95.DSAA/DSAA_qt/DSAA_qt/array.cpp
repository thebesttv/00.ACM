#include "array.h"
#include <cstdio>
#include <algorithm>

void Array::expand()
{
    len *= 2;
    int *tv = new int [len];
    for(int i=0;i<n;++i)
        tv[i] = v[i];
    delete [] v;
    v = tv;
}

void Array::init(int n, int rang)
{
    while(len < n) expand();
    this->n = n;

    for(int i=0;i<n;++i)
        v[i]=rand()%rang+1;
    this->sort();
}

void Array::show(const char *pre){
    if(pre) printf("%s: ",pre);
    printf("Array[%d]:",n);
    for(int i=0;i<n;++i)
        printf(" %d",v[i]);
    putchar('\n');
}

void Array::push_back(int x)
{
    if(n == len) expand();
    v[n++] = x;
}

void Array::sort()
{
    std::sort(v,v+n);
}

void Array::sort_bubble()
{
    for(int i=1;i<n;++i) for(int j=0;j<n-i;++j)
        if(v[j] > v[j+1]) std::swap(v[j], v[j+1]);
}

int Array::sort_bubble_timeComplex()
{
    int cnt = 0;
    for(int i=1;i<n;++i){
        for(int j=0;j<n-i;++j){
            if(v[j] > v[j+1])
                std::swap(v[j], v[j+1]);
            ++cnt;
        }
    }
    return cnt;
}

int Array::deleteElement(int m)
{
    int tail = 0;
    for(int i=0;i<n;++i) if(v[i]!=m)
        v[tail++] = v[i];
    return n = tail;
}

void Array::addElement(int m)
{
    if(n==len) expand();

    int i=0;
    while(i<n && v[i]<m) ++i;
    for(int j=n-1;j>=i;--j)
        v[j+1] = v[j];
    v[i]=m;
    ++n;
}

void Array::addElement(Array *b)
{
    int *tv = new int [n+b->n];
    int tail=0,i=0,j=0;
    while(i<n || j<b->n){
        if(j>=b->n || (i<n && v[i]<b->v[j]))
            tv[tail++] = v[i];
        else
            tv[tail++] = b->v[j];
    }
    len = n = n+b->n;
    delete [] v;
    v = tv;
}
