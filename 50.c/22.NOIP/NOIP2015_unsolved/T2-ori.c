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
const int INF=0x3f3f3f3f;
int G[MAX][MAX],n;

int main(void){
  MST(G,0x3f);
  scanf("%d",&n);
  int u,v;
  FORR(i,1,n) {scanf("%d",&v); G[i][v]=1;}
  FORR(i,1,n) G[i][i]=0;
  FORR(i,1,n) FORR(j,1,n) FORR(k,1,n)
    G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
  int ansMin=1<<30;
  FORR(i,1,n) FORR(j,1,n) if(i!=j && G[i][j]<INF && G[j][i]<INF){
    ansMin=min(ansMin,G[i][j]+G[j][i]);
  }
  printf("%d\n",ansMin);

  return 0;
}
