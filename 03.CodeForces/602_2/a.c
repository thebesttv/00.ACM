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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1e5+20;
int n;

struct Node{
  int pos, d;
  bool operator < (const Node &b) const {
    return pos != b.pos ? pos<b.pos : d < b.d;
  }
}node[MAX*2];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    int tail = 0;
    scanf("%d",&n);
    int l,r;
    FOR(i,0,n){
      scanf("%d%d",&l,&r);
      node[tail++] = {l,1};
      node[tail++] = {r+1,-1};
    }

    sort(node,node+tail);
    int cnt = 0; l = r = -1;
    bool noMinus = 1;
    FOR(i,0,tail){
      if(node[i].d>0){
        if(++cnt == n && r==-1){
          r = node[i].pos;
        }
      }else if(node[i].d<0 && noMinus){
        noMinus = 0; l = node[i].pos-1;
      }
    }
#ifdef DEBUG
    printf(" l: %d, r: %d\n",l,r);
#endif
    printf("%d\n",max(r-l,0));
  }

  return 0;
}
