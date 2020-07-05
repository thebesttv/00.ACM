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

const int MAXN=1020, MAXM=100020;
const int INF=0x3f3f3f3f;
int n,m,s;

struct Edge{
  int v,w; Edge *next;
}edge[MAXM*2], *head[MAXN];
int tail=0;
inline void addEdge(int u, int v, int w){
  edge[tail] = Edge{v,w,head[u]};
  head[u] = edge + tail++;
}

int d[MAXN], cnt[MAXN];
bool inq[MAXN];

bool spfa(int s){
  MST(d,0x3f); d[s]=0;
  MST(inq,0); inq[s]=1;
  MST(cnt,0);
  queue<int> q; q.push(s);
  while(!q.empty()){
    int u=q.front(); q.pop();
    inq[u]=0;
    if(++cnt[u]>n) return 0;
    for(Edge *e=head[u];e;e=e->next){
      if(d[e->v] > d[u] + e->w){
        d[e->v] = d[u] + e->w;
        if(!inq[e->v]){
          q.push(e->v); inq[e->v]=1;
        }
      }
    }
  }
  return true;
}

int main(void){
  scanf("%d%d%d",&n,&m,&s);
  int u,v,w;
  FORR(i,1,n) addEdge(0,i,0);
  while(m--){
    scanf("%d%d%d",&u,&v,&w);
    if(u==v && w<0){  // 自环且负
      printf("-1\n"); return 0;
    }
    if(u!=v) addEdge(u,v,w);
  }

  if(!spfa(0)){
    printf("-1\n");
  }else{
    spfa(s);
    FORR(i,1,n)
      if(d[i]==INF) printf("NoPath\n");
      else printf("%d\n",d[i]);
  }

  return 0;
}
