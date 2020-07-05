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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 100020;
int n,m;
VR<int> G[MAX];
int dis[MAX];
queue<pii> q;

int main(void){
  scanf("%d%d",&n,&m);
  int u,v;
  while(m--){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dis[1] = 1;
  q.push({1,1});
  while(!q.empty()){
    pii t = q.front(); q.pop();
    for(int v : G[t.FI]) if(!dis[v]){
      dis[v] = t.SE + 1;
      q.push({v, dis[v]});
    }
  }
  printf("%d\n",dis[n]-2);

  return 0;
}
