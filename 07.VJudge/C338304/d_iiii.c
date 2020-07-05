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
int n,m,s; double val;

struct Edge{
  int v; double r,c;
  Edge *next;
}edge[MAX*2];
Edge *head[MAX];
int tail=0;

double d[MAX];
int cnt[MAX];
bool inq[MAX];
bool spfa(int s, double val){
  queue<int> q; q.push(s);
  d[s]=val; inq[s]=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    inq[u]=0;
    if(++cnt[u]>n) return false;
    for(Edge *e=head[u];e;e=e->next){
      double t = (d[u] - e->c)*(e->r);
      if(d[e->v]<t){
        d[e->v]=t;
        if(!inq[e->v]){
          q.push(e->v); inq[e->v]=1;
        }
      }
    }
  }
  return true;
}

int main(void){
  scanf("%d%d%d%lf",&n,&m,&s,&val);
  int a,b; double r1,c1,r2,c2;
  while(m--){
    scanf("%d%d%lf%lf%lf%lf",&a,&b,&r1,&c1,&r2,&c2);
    edge[tail] = Edge{b,r1,c1,head[a]}; head[a] = edge + (tail++);
    edge[tail] = Edge{a,r2,c2,head[b]}; head[b] = edge + (tail++);
  }

  printf("%s\n", spfa(s,val) ? "NO" : "YES");

  return 0;
}
