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

const int MAX = 520;
int n,k;
set<int> st;
int pos[MAX];

struct Node{
  int p, v;
  bool operator < (const Node &b) const {
    return v < b.v;
  }
};
VR<Node> v;

int main(void){
  scanf("%d%d",&n,&k);
  FORR(i,1,n) st.insert(i);

  FOR(i,0,n-k+1){
    auto it = st.begin();
    printf("?");
    FOR(j,0,k) printf(" %d",*it++);
    putchar('\n'); fflush(stdout);

    int p,a; scanf("%d%d",&p,&a);
    v.push_back({p,a});
    st.erase(p);
  }
  sort(ALL(v));
  FOR(i,0,v.size())
    pos[v[i].p] = i+1;

  if(n-k+1 >= k){
    printf("?");
    FOR(i,0,k) printf(" %d",v[i].p);
    putchar('\n'); fflush(stdout);

    int p,a; scanf("%d%d",&p,&a);
    printf("! %d\n",pos[p]);
    fflush(stdout); return 0;
  }

  VR<int> left(ALL(st));
  int pMax = 0;
  FOR(i,0,k-1){
    printf("?");
    for(auto p : v) printf(" %d",p.p);
    FOR(j,0,2*k-n-1) printf(" %d",left[(i+j)%(k-1)]);
    putchar('\n'); fflush(stdout);

    int p,a; scanf("%d%d",&p,&a);
    pMax = max(pMax, pos[p]);
  }

  printf("! %d\n",pMax);
  fflush(stdout);

  return 0;
}
