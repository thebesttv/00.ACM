#include "array.h"
#include <cstdlib>
#include <ctime>
#include <cstdio>

int main(){
    srand(time(NULL));
    Array a(0);
    a.addElement(-1024);
    a.show();

    for(int i=-2;i<=6;++i){
        a.init(5,5);
        a.show("before");
        a.addElement(i);
        a.show("after");
        putchar('\n');
    }

    return 0;
}
