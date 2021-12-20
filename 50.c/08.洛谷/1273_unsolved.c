#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)














































/*
const int MAX=3020;
int n,m,pay[MAX];
struct Edge{
  int v,c;
};
VR<Edge> G[MAX];
int c[MAX],f[MAX][MAX];
struct Node{
  int u,c;
};

int main(void){
  scanf("%d%d",&n,&m);
  int t=n-m;
  FORR(i,1,t){
    int k,a,c; scanf("%d",&k);
    FOR(j,0,k){
      scanf("%d%d",&a,&c);
      G[i].push_back((Edge){a,c});
    }
  }
  FORR(i,1,m) scanf("%d",&pay[i]);

  queue<Node> q;
  q.push((Node){1,0});
  while(!q.empty()){
    Node tn=q.front(); q.pop();
    int u=tn.u;
    if(u>t) {c[u-t]=tn.c; continue;}
    FOR(i,0,G[u].size()){
      Edge & e=G[u][i];
      q.push((Node){e.v,e.c+tn.c});
    }
  }
#ifdef DEBUG
  printf("cost:");
  FORR(i,1,m) printf(" %d",c[i]); printf("\n");
  printf("pay:");
  FORR(i,1,m) printf(" %d",pay[i]); printf("\n");
#endif
  FORR(i,1,m) c[i]=pay[i]-c[i];
  
  FORR(i,1,m) ROR(j,i,1)
    f[i][j]=max(f[i-1][j],f[i-1][j-1]+c[i]);

  int ansMax=0;
  ROR(i,m,1) if(f[n][i]>=0) {ansMax=i; break;}
  printf("%d\n",ansMax);

  return 0;
}
*/
