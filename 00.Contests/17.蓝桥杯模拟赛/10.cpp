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

const int MAX = 100000 + 20;
int n,m,a[MAX];
VR<int> pos[MAX];

struct ST{
  int v[MAX<<2];
  void build(int u, int l, int r, int *a){
    if(l==r){
      v[u] = a[l];
      return;
    }
    int m = (l+r)>>1;
    build(u<<1,l,m,a);
    build(u<<1|1,m+1,r,a);
    v[u] = max(v[u<<1],v[u<<1|1]);
  }
  int qMax(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr){
      return v[u];
    }
    int m = (cl+cr)>>1, ansMax = 0;
    if(ql<=m) ansMax = qMax(u<<1,cl,m,ql,qr);
    if(qr>m)  ansMax = max(ansMax, qMax(u<<1|1,m+1,cr,ql,qr));
    return ansMax;
  }
}st;

int getPos(int x, int l){
  VR<int>::iterator it = lower_bound(ALL(pos[x]), l);
  return *it;
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n){
    scanf("%d",&a[i]);
    pos[a[i]].push_back(i);
  }

  st.build(1,1,n,a);
  int l = 1, r = n-m+1;
  FORR(i,1,m){
    r = n - m + i;
    int tMax = st.qMax(1,1,n,l,r);
    int p = getPos(tMax, l);
#ifdef DEBUG
    printf("  max(%d,%d): %d, pos: %d\n",l,r,tMax,p);
#endif
    printf("%d ",tMax);
    l = p+1;
  }
  putchar('\n');

  return 0;
}
