#include <stdio.h>
int fun( int n ){
  int s=0;
  while(n){
    int t=n%10; n/=10;
    s += t*t;
  }
  return s%5==0;
}

int main()
{
      int m;
      scanf("%d", &m);
      printf("The result is %d\n", fun(m));
      return 0;
}
