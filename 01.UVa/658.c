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

const int MAXM=120, MAXN=1<<21;
const int INF=0x3f3f3f3f;
int n,m,d[MAXN];
char sb[40],sf[40];
struct Patch{
  int t,ba,bp,fa,fp;
}patch[MAXM];

struct Node{
  int d,u;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

bool ok(int u, int i, int &st){
  Patch &p = patch[i];
  if(u & p.ba) return 0;
  if((u & p.bp) != p.bp) return 0;
  st = u;
  st &= (~p.fa); st |= p.fp;
  return 1;
}

void Dij(int s){
  MST(d,0x3f); d[s]=0;
  PQ<Node> q; q.push(Node{0,s});
  while(!q.empty()){
    Node t = q.top(); q.pop();
    int u = t.u;
    if(d[u]!=t.d) continue;
    int st;
    FOR(i,0,m) if(ok(u,i,st))
      if(d[st] > t.d + patch[i].t){
        d[st] = t.d + patch[i].t;
        q.push(Node{d[st],st});
      }
  }
}

int main(void){
  int kase=0;
  while(scanf("%d%d",&n,&m)==2 && n){
    MST(patch,0);
    FOR(i,0,m){
      Patch &p = patch[i];
      scanf("%d%s%s",&p.t,sb,sf);
      FOR(i,0,n){
        if(sb[i]=='-') p.ba |= 1<<i;
        else if(sb[i]=='+') p.bp |= 1<<i;

        if(sf[i]=='-') p.fa |= 1<<i;
        else if(sf[i]=='+') p.fp |= 1<<i;
      }
    }

    Dij((1<<n)-1);

    printf("Product %d\n",++kase);
    if(d[0]==INF) printf("Bugs cannot be fixed.\n");
    else printf("Fastest sequence takes %d seconds.\n",d[0]);
    putchar('\n');
  }
  return 0;
}
