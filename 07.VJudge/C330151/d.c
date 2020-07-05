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

const int MAX=220;
int n,ans[MAX];
struct Node{
  int l,r,n;
  Node() { }
  Node(int l, int r, int n): l(l), r(r), n(n) { }
  bool operator < (const Node &b) const {
    return l < b.l;
  }
}node[MAX];
struct Stall{
  int s, n;
  Stall(int s, int n): s(s), n(n) { }
  bool operator < (const Stall &b) const {
    return s > b.s;
  }
};

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FOR(i,0,n){
      int l,r; scanf("%d%d",&l,&r);
      l = ceil(l/2.0); r = ceil(r/2.0);
      if(l>r) swap(l,r);
      node[i]=Node(l,r,i);
    }
    sort(node,node+n);

    PQ<Stall> stall;
    stall.push(Stall(node[0].r+1,1)); ans[node[0].n]=1;
    FOR(i,1,n){
      Stall t=stall.top();
      if(t.s<=node[i].l){
        stall.pop(); stall.push(Stall(node[i].r+1,t.n));
        ans[node[i].n]=t.n;
      }else{
        int c=stall.size()+1;
        stall.push(Stall(node[i].r+1,c));
        ans[node[i].n]=c;
      }
    }
    printf("%d\n",(int)stall.size()*10);
  }

  return 0;
}
