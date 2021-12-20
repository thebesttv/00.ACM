#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x ){
  double ans=0;
  for(int i=n;i>=0;i--){
    ans = ans * x + a[i];
  }
  return ans;
}

int main()
{
  int n, i;
  double a[MAXN], x;

  scanf("%d %lf", &n, &x);
  for ( i=0; i<=n; i++ )
    scanf("%lf", &a[i]);
  printf("%.1f\n", f(n, a, x));
  return 0;
}
