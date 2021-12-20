#include <stdio.h>

int reverse( int number ){
  int s=0,n=number;
  int isMinus=0;
  if(n<0){ isMinus=1; n=-n; }
  while(n){
    s = s*10 + n%10;
    n/=10;
  }
  if(isMinus) s=-s;
  return s;
}

int main()
{
  int n;

  scanf("%d", &n);
  printf("%d\n", reverse(n));

  return 0;
}
