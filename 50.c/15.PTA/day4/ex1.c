#include <stdio.h>
#define MAXN 20

void CountOff( int n, int m, int out[] );

int main()
{
    int out[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    CountOff( n, m, out );   
    for ( i = 0; i < n; i++ )
        printf("%d ", out[i]);
    printf("\n");

    return 0;
}

void CountOff( int n, int m, int out[] ){
  int cur=0; for(int i=0;i<n;++i) out[i]=0;
  for(int i=1;i<n;++i){
    for(int j=0;j<m;++j){
      while(out[cur]) cur = (cur+1)%n;
      cur = (cur+1)%n;
    }
    cur = (cur-1+n)%n;
    out[cur]=i;
  }
  for(int i=0;i<n;++i) if(!out[i]){
    out[i] = n; break;
  }
}
