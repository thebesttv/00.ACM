#include <stdio.h>

int is( int number ){
  int s=0, n=number;
  while(n) s+=n%10, n/=10;
  return s==5 ? 1 : 0;
}
void count_sum( int a, int b ){
  int sum=0,cnt=0;
  for(int i=a;i<=b;i++) if(is(i)){
    cnt++, sum+=i;
  }
  printf("count = %d, sum = %d\n",cnt,sum);
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    if (is(a)) printf("%d is counted.\n", a);
    if (is(b)) printf("%d is counted.\n", b);
    count_sum(a, b);

    return 0;
}
