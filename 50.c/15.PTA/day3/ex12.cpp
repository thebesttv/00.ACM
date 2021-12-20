#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
  int N;

  scanf("%d", &N);
  Print_Factorial(N);
  return 0;
}

#include <string.h>
int v[10000],v2[10000];
void Print_Factorial ( const int N ){
  if(N<0){
    printf("Invalid input\n"); return;
  }
  v[0]=1;
  for(int n=1;n<=N;++n){
    memset(v2,0,sizeof(v2));
    for(int i=0;i<10000;++i) if(v[i]){
      int t = v[i] * n, tail2=0;
      while(t){
        v2[i + (tail2++)] += t%10;
        t/=10;
      }
    }
    memcpy(v,v2,sizeof(v));
    for(int i=0;i<10000;++i) if(v[i]>=10){
      v[i+1]+=v[i]/10;
      v[i]%=10;
    }
#ifdef DEBUG
    printf("%d: ",n);for(int i=0;i<5;i++) printf("%d ",v[i]); printf("\n");
#endif
  }
  int tail = 10000;
  while(!v[tail-1]) --tail;

  for(int i=tail-1;i>=0;--i)
    printf("%d",v[i]);
  printf("\n");
}
