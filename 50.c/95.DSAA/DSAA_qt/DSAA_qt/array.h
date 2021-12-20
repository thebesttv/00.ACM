#ifndef ARRAY_H
#define ARRAY_H

const int INIT_LEN=10;
const int ERR_CODE=-0x3f3f3f3f;

// always ordered
struct Array{
    int *v, n, len;
    Array(int l=INIT_LEN){
        len = l>INIT_LEN ? l : INIT_LEN;
        v = new int [len];
        n = 0;
    }
    ~Array() { delete [] v; }

    void expand();

    void init(int n, int rang=1000);	// fill with n random numbers, stay sorted
    void show(const char *pre=nullptr);
    void push_back(int x);
    void sort();
    void sort_bubble();
    int sort_bubble_timeComplex();
    int deleteElement(int m);
    void addElement(int m);
    void addElement(Array *b);
};

#endif // ARRAY_H
