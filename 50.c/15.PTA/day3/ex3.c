#include <stdio.h>

float  fun(int n){
  double a[1004]; a[1]=1; a[2]=2;
  for(int i=3;i<=1000;i++) a[i]=a[i-1]+a[i-2];
  double s=0;
  for(int i=1;i<=n;i++) s += a[i+1]/a[i];
  return s;
}

int main()
{
int n;
scanf("%d", &n);
printf("%.4f", fun(n));
return 0;
}
