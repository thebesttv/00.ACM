#include <stdio.h>

int fib( int n ){
  if(n<=2) return 1;
  int l=1, r=1;
  for(int i=3;i<=n;i++){
    int t=r; r+=l; l=t;
  }
  return r;
}
void PrintFN( int m, int n ){
  int done=0, first=1;
  int i=1;
  while(fib(i)<=n){
    if(fib(i)>=m){
      if(first) first=0;
      else putchar(' ');
      printf("%d",fib(i)); done=1;
    }
    i++;
  }
  if(!done) printf("No Fibonacci number\n");
  else putchar('\n');
}
	
int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}
