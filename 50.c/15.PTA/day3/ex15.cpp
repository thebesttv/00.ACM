#include <stdio.h>

int Count_Digit ( const int N, const int D ){
  int n=N, d=D, cnt=0;
  if(n==0) return D==0 ? 1 : 0;
  if(n<0) n=-n;
  while(n){
    if(n%10==d) cnt++;
    n/=10;
  }
  return cnt;
}

int main()
{
    int N, D;
	
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}
