#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "Applications.h"
#include "Array.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "ArrayStack.h"
#include "ListLinkedStack.h"
#include "ArrayQueue.h"
#include "ListLinkedQueue.h"

void testPoly();
void testArray();
template<typename T> void testList();
template<typename T> void testStack();  // use int
template<typename T> void testQueue();  // use int
void testDec2Hex();
void testExpression();

int main(void)
{
    testPoly();
    testArray();
    testList<PigNode>();
    testList<DPigNode>();
    testStack<ArrayStack<int>>();
    testStack<ListStack<double>>();
    testQueue<ArrayQueue<double>>();
    testQueue<ListQueue<int>>();
    testDec2Hex();
    testExpression();

    return 0;
}

void testExpression(){
    const int n = 4;
    const char *s[n] = {
        "1+2+3+4",
        "1*2-3/4",
        "(1+2)*3/4+1",
        "((((2+2)))-3)*4"
    };
    for(int i=0;i<n;++i){
        printf("Expression: %s\n",s[i]);
        printf("  ans: %lf\n",FourMixedOperations(s[i]));
    }
}

void testDec2Hex(){
    for(int n=-1020;n<=1020;n+=100){
        char *s1 = DecToHexByStack1(n),
             *s2 = DecToHexByStack2(n),
             *s3 = DecToHexByRecursion(n);
        if(strcmp(s1,s2) || strcmp(s2,s3)){
            throw "error in Dec2Hex";
            exit(1);
        }
        printf("Dec2Hec(%d): %s\n",n,s1);
        delete [] s1;
        delete [] s2;
    }
}

template<typename T> void testQueue(){
    T q;
    q.push(1),
    q.push(2),
    q.push(3),
    q.push(4),
    q.push(5);

    q.print();
    std::cout << "front: " << q.front() << std::endl;
    std::cout << "back: " << q.back() << std::endl;

    while(!q.empty()){
        std::cout << "front & pop: " << q.front() << std::endl;
        q.pop();
        q.print();
    }

    q.push(6),
    q.push(7),
    q.push(8),
    q.push(9),
    q.push(10);
    q.print("refill");
}

template <typename T> void testStack(){
    T st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.print();
    while(!st.empty()){
        std::cout << "top & pop: " << st.top() << std::endl;
        st.pop();
        st.print();
    }
}

void testPoly(){
    // f[x] = 1x^4 + 5x^2 + -8x - 12
    double a[] = {1,0,5,-8,-12};
    for(int x = -4;x<=4;++x){
        double f1 = PolynomialFunc(a,5,5,x);
        double f2 = PolynomialFunc(5,x,a[0],a[1],a[2],a[3],a[4]);
        if(fabs(f1 - f2)>1e-6){
            printf("  wrong at Application.cpp\n");
            exit(1);
        }
        printf("f[%d]: %lf\n",x,f1);
    }
}

template<typename T> void testList(){
    auto print = [](T *head, const char *s=nullptr){
        if(s) printf("%s ",s);
        ShowAllPigs(head);
    };
    T v[] = { {"a", 5}, {"b", 4}, {"c", 10}, {"d", 12}, {"e", 2} };
    auto head = CreatePigs(5,v);
    print(head);

    head = InsertPig(head, {"pigga", 2});
    head = InsertPig(head, {"###", 1024});
    print(head, "insert 2 pig");

    head = SortPigsByName(head);
    print(head, "sort by name");

    head = SortPigsByWeight(head);
    print(head, "sort by weight");

    head = KillPigByWeight(head, 1024);
    print(head, "kill weight 1024");

    head = KillPigByName(head, "pigga");
    print(head, "kill name pigga");
}

void testArray(){
    int *a = new int [1020];
    auto print = [](int *a, int n, const char *s=nullptr){
        if(s) printf("%s ",s);
        printf("a[%d]:",n);
        for(int i=0;i<n;++i)
            printf(" %d",a[i]);
        putchar('\n');
    };

    a[0] = 1,
    a[1] = 2,
    a[2] = 2,
    a[3] = 2,
    a[4] = 4,
    a[5] = 8;

    int n = 6;
    print(a,n,"before delete");
    n = cyf_DeleteElement(a,1020,n,0);
    print(a,n,"delete 0");

    n = cyf_DeleteElement(a,1020,n,2);
    print(a,n,"delete 2");

    n = cyf_DeleteElement(a,1020,n,1);
    print(a,n,"delete 1");

    n = cyf_DeleteElement(a,1020,n,4);
    print(a,n,"delete 4");

    n = cyf_DeleteElement(a,1020,n,8);
    print(a,n,"delete 8");


    a[0] = 1,
    a[1] = 2,
    a[2] = 2,
    a[3] = 2,
    a[4] = 4,
    a[5] = 8;

    n = 6;
    print(a,n,"before add one");
    n = cyf_AddElement(a,1020,n,0);
    print(a,n,"add 0");

    n = cyf_AddElement(a,1020,n,1024);
    print(a,n,"add 1024");

    n = cyf_AddElement(a,1020,n,4);
    print(a,n,"add 4");

    int *b = new int [8];
    b[0] = -256,
    b[1] = 0,
    b[2] = 1,
    b[3] = 1,
    b[4] = 5,
    b[5] = 2048;

    int lena=1020;
    cyf_AddElement(a,lena,n,b,8,6);
    print(b,6);
    print(a,n,"add b");
}
