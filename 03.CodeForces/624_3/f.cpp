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

const int MAX = 2e5 + 20;
int n,pos[MAX];
struct Node{
  int p,v,no;
  bool operator < (const Node &b){
    return v != b.v ? v < b.v : p < b.p;
  }
}node[MAX],v[MAX];

struct ST{  // n-1
  LL v[MAX];
  LL sum(int x){
    LL s = 0;
    while(x){
      s += v[x]; x -= x&-x;
    }
    return s;
  }
  void add(int x, LL val){
    while(x<=n){
      v[x]+=val; x += x&-x;
    }
  }
  LL operator [] (int idx){
    return sum(idx);
  }
}s,c;

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&node[i].p);
  FOR(i,0,n) scanf("%d",&node[i].v);
  sort(node,node+n,[](Node &a, Node &b){
        return a.p < b.p;
      });
  FOR(i,0,n) node[i].no=i;
  memcpy(v,node,sizeof(node));
  v[0]={0,0,0};
  sort(v+1,v+n);
  FOR(i,1,n){
    pos[v[i].no]=i;
    s.add(i,v[i].p);
    c.add(i,1);
  }
#ifdef DEBUG
  FOR(i,0,n) printf(" (%d, %d)",node[i].p,node[i].v); putchar('\n');
  FOR(i,0,n) printf(" (%d, %d)",v[i].p,v[i].v); putchar('\n');
#endif

  LL ans = 0;
  FOR(i,0,n-1){
    // int j = lower_bound(v+1,v+n,Node{0,node[i].v,0}) - v;
    int j=1;
    if(i!=0){
      j = pos[i];
      while(j>1 && v[j].v==v[j-1].v) --j;
    }else while(j<n && v[j].v < node[i].v) ++j;

    //if(j>=n) continue;
    if(j<n){
#ifdef DEBUG
      FOR(j,1,n) printf("  s[%d]: %lld, c[%d]: %lld\n",j,s[j],j,c[j]);
      printf("  for i: %d (v %d), j: %d\n",i,node[i].v,j);
      printf("    s[n]:%lld, s[j-1]: %lld, c[n]: %lld, c[j-1]: %lld\n",s[n],s[j-1],c[n],c[j-1]);
      printf("    ans += %lld\n",s[n]-s[j-1] - (c[n] - c[j-1])*node[i].p);
      printf("  delete %d\n",pos[i+1]);
#endif
      ans += s[n]-s[j-1] - (c[n] - c[j-1])*node[i].p;
    }
    int t = pos[i+1];
    s.add(t,-v[t].p);
    c.add(t,-1);
  }
  printf("%lld\n",ans);

  return 0;
}
