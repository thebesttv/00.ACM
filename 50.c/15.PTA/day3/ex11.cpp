#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N ){
  int n=N,i=sqrt(N);
  if(i*i!=n) return 0;
  int vis[10]; for(int i=0;i<10;i++) vis[i]=0;
  while(n){
    if(vis[n%10]) return 1;
    vis[n%10]=1; n/=10;
  }
  return 0;
}

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}
