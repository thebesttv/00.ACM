#include <stdio.h>

int func()
{
  int a = 1;
  int b = a + 1;
  int c = a + b;
  return a + b + c;
}

int main()
{
  int a = func();
  printf("%d\n", a);
}
