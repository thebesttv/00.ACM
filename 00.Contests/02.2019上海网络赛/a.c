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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=100020;
int n,q;
struct Edge{
  int v,num;
  Edge(int v, int num): v(v), num(num) { }
};
VR<Edge> to[MAX];
int weight[MAX];

int ansMax;
bool vis[MAX];

void dfs(int u, int val){
  vis[u]=1; ansMax=max(ansMax,val);
  for(Edge e : to[u]) if(!vis[e.v]){
    dfs(e.v,val+weight[e.num]);
  }
}

int main(void){
  scanf("%d",&n);
  int u,v,w;
  FOR(i,1,n){
    scanf("%d%d%d",&u,&v,&w);
    to[u].push_back(Edge(v,i));
    to[v].push_back(Edge(u,i));
    weight[i]=w;
  }
  scanf("%d",&q);
  while(q--){
    int a,b,ch;
    do ch=getchar(); while(ch!='Q' && ch!='C');
    if(ch=='C'){
      scanf("%d%d",&a,&b);
      weight[a]=b;
    }else{
      scanf("%d",&a);
      ansMax=0; MST(vis,0);
      dfs(a,0);
      printf("%d\n",ansMax);
    }
  }

  return 0;
}
