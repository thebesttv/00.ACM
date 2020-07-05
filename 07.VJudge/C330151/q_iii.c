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

const int MAX=50020;
int n,ans[MAX];
struct Node{
  int l,r,n;
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
PQ<Stall> stall;

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d%d",&node[i].l,&node[i].r), node[i].n=i;
  sort(node,node+n);
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
  printf("%d\n",(int)stall.size());
  FOR(i,0,n) printf("%d\n",ans[i]);

  return 0;
}

/*
const int MAX=50020;
int n,ans[MAX];
struct Node{
  int l,r,n;
  bool operator < (const Node &b) const {
    return r!=b.r ? r<b.r : l<b.l;
  }
}node[MAX];
struct Stall{
  int s, n;
  Stall(int s, int n): s(s), n(n) { }
  bool operator < (const Stall &b) const {
    return s > b.s;
  }
};
set<Stall> stall;

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d%d",&node[i].l,&node[i].r), node[i].n=i;
  sort(node,node+n);

  stall.insert(Stall(node[0].r+1,1)); ans[node[0].n]=1;

  FOR(i,1,n){
#ifdef DEBUG
    printf("  cow %d [%d,%d]\n",node[i].n,node[i].l,node[i].r);
    printf("   "); for(Stall t : stall) printf(" %d",t.s); putchar('\n');
#endif
    set<Stall>::iterator it = stall.lower_bound(Stall(node[i].l,0));
    if(it==stall.end()){
      int c=stall.size();
      stall.insert(Stall(node[i].r+1,c+1));
      ans[node[i].n]=c+1;
    }else{
      Stall t = *it; stall.erase(it);
      stall.insert(Stall(node[i].r+1,t.n));
      ans[node[i].n]=t.n;
    }
  }
  printf("%d\n",(int)stall.size());
  FOR(i,0,n) printf("%d\n",ans[i]);
  return 0;
}
*/
