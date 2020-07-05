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

const int MAX=120;
int n,v;
struct Node{
  int p,m;
  bool operator < (const Node &b) const {
    return p > b.p;
  }
}node[MAX];

int main(void){
  while(scanf("%d",&v)==1 && v){
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d%d",&node[i].p,&node[i].m);
    sort(node,node+n);
    int ans=0;
    FOR(i,0,n){
      if(v>=node[i].m){
        ans += node[i].m * node[i].p;
        v -= node[i].m;
      }else{
        ans += node[i].p * v; break;
      }
    }
    printf("%d\n",ans);
  }

  return 0;
}
