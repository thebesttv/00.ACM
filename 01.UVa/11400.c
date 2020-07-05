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

const int MAX=1020;
int n,f[MAX],s[MAX];
struct Node{
  int v,k,c,l;
  bool operator < (const Node &b) const {
    return v < b.v;
  }
  void read() { scanf("%d%d%d%d",&v,&k,&c,&l); }
}node[MAX];

int main(void){
  while(scanf("%d",&n)==1 && n){
    FORR(i,1,n) node[i].read();
    sort(node+1,node+1+n);  // 先排序，再求前缀和
    FORR(i,1,n) s[i]=s[i-1]+node[i].l;
    MST(f,0x3f); f[0]=0;
    FORR(i,1,n) FOR(j,0,i){
      f[i] = min(f[i], f[j] + (s[i]-s[j])*node[i].c + node[i].k);
    }
    printf("%d\n",f[n]);
  }

  return 0;
}
