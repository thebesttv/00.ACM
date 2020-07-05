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

const int MAX=25020;
int n,t; bool vis[MAX];
struct Node{
  int l,r;
  Node() { }
  Node(int l, int r): l(l), r(r) { }
  bool operator < (const Node &b) const {
    return r > b.r;
  }
}node[MAX];

int main(void){
  scanf("%d%d",&n,&t);
  FOR(i,0,n) scanf("%d%d",&node[i].l,&node[i].r);
  sort(node,node+n);
  int cur=1,cnt=0;  // where to start, cur=t: not finished, still one interval left
  while(cur<=t){
    cnt++; bool done=0;
    FOR(i,0,n) if(!vis[i])
      if(node[i].l<=cur && cur<=node[i].r){
        cur = node[i].r+1; vis[i]=1; done=1;
        break;
      }
    if(!done) break;
  }
  printf("%d\n", cur>t ? cnt : -1);

  return 0;
}
