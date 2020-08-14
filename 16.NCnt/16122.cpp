// Tag: 状压DP
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 18;
const int INF = 0x3f3f3f3f;
int n,m,r,v[MAX],mp[220],G[MAX][MAX],f[1<<MAX][MAX];
int OG[220][220];

int main(void){
  scanf("%d%d%d",&n,&m,&r);
  FORR(i,1,r) scanf("%d",&v[i]), mp[v[i]]=i;
  MST(G,0x3f); MST(OG,0x3f);
  while(m--){
    int u,v,w; scanf("%d%d%d",&u,&v,&w);
    OG[u][v] = OG[v][u] = w;
  }
  FORR(k,1,n) FORR(i,1,n) FORR(j,1,n)
    OG[i][j] = min(OG[i][j], OG[i][k]+OG[k][j]);
  FORR(i,1,r) FORR(j,1,r) G[i][j] = OG[v[i]][v[j]];

  MST(f,0x3f); //f[0][0]=0;
  FOR(i,0,r) f[1<<i][i] = 0;
  FOR(st,1,1<<r) FOR(i,0,r) if(st&(1<<i)){
    int &a = f[st][i];
    FOR(j,0,r) if(i!=j && (st&(1<<j))){
#ifdef DEBUG
      printf("f[%d][%d] <- f[%d][%d]\n",st,i,st^(1<<i),j);
#endif
      a = min(a, f[st^(1<<i)][j] + G[i+1][j+1]);
    }
#ifdef DEBUG
    printf("f[%d][%d]: %d\n",st,i,a);
#endif
  }
  int ansMin = INF;
  FOR(i,0,r) ansMin = min(ansMin, f[(1<<r)-1][i]);
  printf("%d\n",ansMin);

  return 0;
}
