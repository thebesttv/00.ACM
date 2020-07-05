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
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=120;
int n,m,G[MAX][MAX];
bool vis[MAX];

int count(int s, int c){
  MST(vis,0);
  queue<int> q; q.push(s);
  int cnt=0; vis[s]=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    FORR(v,1,n) if(G[u][v]==c && !vis[v]){
      q.push(v); vis[v]=1; ++cnt;
    }
  }
  return cnt;
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v;
  while(m--){
    scanf("%d%d",&u,&v);
    G[u][v]=1;  // better
    G[v][u]=-1; // worse
  }
  int cnt=0;
  FORR(i,1,n){
    //printf("  %d: %d, %d\n",i,count(i,1),count(i,-1));
    if(count(i,1) + count(i,-1) == n-1)
      cnt++;
  }
  printf("%d\n",cnt);

  return 0;
}
