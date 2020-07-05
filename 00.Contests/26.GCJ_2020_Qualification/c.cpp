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

const int MAX = 1020;
int n,r[MAX];
struct Node{
  int l, r, no;
  bool operator < (const Node &b) const {
    return r != b.r ? r < b.r : l < b.l;
  }
}node[MAX];

bool ok(){
  int t1=0, t2=0;
  FOR(i,0,n){
    if(min(t1,t2) > node[i].l)
      return false;
    if(t1 <= node[i].l && (t2>node[i].l || (t2<=node[i].l && t1>=t2)))
      t1 = node[i].r, r[node[i].no] = 'C';
    else
      t2 = node[i].r, r[node[i].no] = 'J';
  }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    FOR(i,0,n){
      scanf("%d%d",&node[i].l,&node[i].r);
      node[i].no = i;
    }
    sort(node,node+n);
    printf("Case #%d: ",kase);
    if(!ok()) printf("IMPOSSIBLE");
    else FOR(i,0,n) putchar(r[i]);
    putchar('\n');
  }

  return 0;
}
