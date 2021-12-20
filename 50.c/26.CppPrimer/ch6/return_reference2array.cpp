#include <iostream>

int a[5]={3,1,4,1,5};

int (&array())[5]{
  return a;
}

int main(void){
  for(int i=0;i<5;++i)
    printf("%d ",array()[i]);
  putchar('\n');
  array()[0] = 1;
  array()[1] = 2;
  array()[2] = 3;
  array()[3] = 4;
  array()[4] = 5;
  for(int i=0;i<5;++i)
    printf("%d ",array()[i]);
  putchar('\n');

  return 0;
}
