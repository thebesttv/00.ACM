#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=220;
int a[MAX][MAX],n,m;

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,m) scanf("%d",&a[0][i]);
  FOR(i,1,n) FOR(j,0,m){
    scanf("%d",&a[i][j]);
    int t=a[i-1][j];
    if(j) t=max(t,a[i-1][j-1]);
    if(j<m-1) t=max(t,a[i-1][j+1]);
    a[i][j]+=t;
  }
#ifdef DEBUG
  FOR(i,0,n){
    FOR(j,0,m) printf("%d ",a[i][j]);
    printf("\n");
  }
#endif
  int mid=m/2;
  int ansMax=a[n-1][mid];
  if(mid) ansMax=max(ansMax,a[n-1][mid-1]);
  if(mid+1<m) ansMax=max(ansMax,a[n-1][mid+1]);
  printf("%d\n",ansMax);

  return 0;
}
