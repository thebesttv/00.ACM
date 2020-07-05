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

const int MAX=620;
const int MAXP=1000000*2;
int n,v[MAX];
bool vis[MAXP+20];

struct Edge{
  int u,v,w;
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
}edge[MAX*MAX];
int tail=0;
void addEdge(int u, int v, int w){
  edge[tail++] = Edge{u,v,w};
}

int p[MAX];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}

int main(void){
  vis[1]=1; int r=sqrt(MAXP+0.5);
  FORR(i,2,r) if(!vis[i])
    for(int j=i*i;j<=MAXP;j+=i) vis[j]=1;

  int T; scanf("%d",&T);
  while(T--){
    tail=0; MST(p,-1);
    scanf("%d",&n);
    FORR(i,1,n){
      scanf("%d",&v[i]);
      FOR(j,1,i) if(!vis[v[i]] || !vis[v[j]] || !vis[v[i]+v[j]]){
        addEdge(i,j, min( min(v[i], v[j]), abs(v[i]-v[j]) ));
      }
    }
    sort(edge,edge+tail);

    int ans=0, cnt=0;
    FOR(i,0,tail){
      Edge &e = edge[i];
      int p1 = fa(e.u), p2 = fa(e.v);
      if(p1!=p2){
        p[p1]=p2; ans+=e.w;
        if(++cnt==n-1) break;
      }
    }
    printf("%d\n", cnt==n-1 ? ans : -1);
  }

  return 0;
}
