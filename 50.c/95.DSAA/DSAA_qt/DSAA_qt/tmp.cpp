const int INIT_LEN=10;
const int ERR_CODE=-0x3f3f3f3f;

// always ordered
struct Array{
    int *v, n, len;
    Array(int l=INIT_LEN): len(l){
        v = new int [len];
        n = 0;
    }
    ~Array() { delete [] v; }

    void expand();

    void init(int n, int rang=1000);	// fill with n random numbers, stay sorted
    void show();
    void sort();
    void sort_bubble();
    int sort_bubble_timeComplex();
    int deleteElement(int m);
    void addElement(int m);
    void addElement(Array *b);
};


#include <cstdio>
#include <algorithm>

void Array::expand()
{
    len *= 2;
    printf("  expand len to %d\n",len);
    int *tv;
    tv=nullptr;
    tv= new int [len];
    for(int i=0;i<n;++i)
        tv[i] = v[i];
    delete [] v;
    v = tv;
}

void Array::init(int n, int rang)
{
    this->n = n;
    while(len < n){
        expand();
        printf("  expand to %d\n",len);
    }
    printf("  in init\n");

    for(int i=0;i<n;++i)
        v[i]=rand()%rang+1;
    this->sort();
}

void Array::show(){
    printf("Array[%d]:",n);
    for(int i=0;i<n;++i)
        printf(" %d",v[i]);
    putchar('\n');
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


#include <cstdlib>
#include <ctime>
#include <cstdio>

int main(){
    srand(time(NULL));
    Array a;
    printf(" len: %d\n",a.len);
    a.init(100,10);
    a.expand();
    a.expand();
    a.expand();
    a.show();

    return 0;
}
