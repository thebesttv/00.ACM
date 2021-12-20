#include <stdio.h>

int factorsum( int number ){
  int s=1;
  for(int i=2;i<number;i++)
    if(number%i==0) s+=i;
  return s;
}

void PrintPN( int m, int n ){
  int done=0;
  for(int i=m;i<=n;i++) if(factorsum(i)==i){
    done=1; printf("%d = 1",i);
    for(int j=2;j<i;j++) if(i%j==0) printf(" + %d",j);
    putchar('\n');
  }
  if(!done) printf("No perfect number\n");
}

int main()
{
  int i, m, n;

  scanf("%d %d", &m, &n);
  if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
  if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
  PrintPN(m, n);

  return 0;
}
