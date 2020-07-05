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

const int MAX=100;
int on,n;
struct Node{
  int a,b,h;
  Node() { }
  Node(int a, int b, int h): a(a), b(b), h(h) { }
}node[MAX];
int G[MAX][MAX],f[MAX]; // starting from i, the hightest height

bool fit(int i, int j){ // if j can be on top of i
  return (node[i].a < node[j].a && node[i].b < node[j].b )
      || (node[i].a < node[j].b && node[i].b < node[j].a );
}

int dp(int u){
  int &a=f[u];
  if(a!=-1) return a;
  a = node[u].h;
  FOR(v,0,n) if(G[u][v]){
    a = max(a, dp(v) + node[u].h);
  }
  return a;
}

int main(void){
  int kase=0;
  while(scanf("%d",&on)==1 && on){
    n = 0; MST(G,0);
    FOR(i,0,on){
      int x,y,z; scanf("%d%d%d",&x,&y,&z);
      node[n++] = Node(x,y,z);
      node[n++] = Node(y,z,x);
      node[n++] = Node(z,x,y);
    }
    FOR(i,0,n) FOR(j,0,n)
      if(fit(i,j)) G[i][j]=1;

    MST(f,-1);
    int ans=0;
    FOR(i,0,n){
      ans=max(ans,dp(i));
#ifdef DEBUG
      printf("dp(%d): %d\n",i,dp(i));
#endif
    }
    printf("Case %d: maximum height = %d\n",++kase,ans);
  }

  return 0;
}
