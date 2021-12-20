//TODO: 改为递推

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

const int MAX=10020;
const int INF=1<<30;
VR<int> G[MAX],son[MAX];
bool vis[MAX];
int check[MAX][3],n;

void bfs(int u){
  queue<int> q;
  q.push(u); vis[u]=1;
  while(!q.empty()){
    u=q.front(); q.pop();
    FOR(i,0,G[u].size()){
      int v=G[u][i];
      if(!vis[v]) {son[u].push_back(v); vis[v]=1; q.push(v);}
    }
  }
}
int f(int u, int t){
  int & a=check[u][t];
  if(a!=-1) return a;
  if(!son[u].size()){
    a = !t ? 1 : (t==1 ? 0 : 1<<30);
  }else if(t==0){
    a=1;
    FOR(i,0,son[u].size()){
      a+=min(f(son[u][i],0),f(son[u][i],1));
    }
  }else if(t==1){
    a=0;
    FOR(i,0,son[u].size()){
      int t=f(son[u][i],2);
      if(t>=INF) return a=INF;
      a+=t;
    }
  }else{
    a=INF;
    //FOR(i,0,son[u].size()){
    //  int sum=f(son[u][i],0);
    //  FOR(j,0,son[u].size()) if(j!=i) sum+=f(son[u][j],2);
    //  a=min(a,sum);
    //}
    FOR(i,0,son[u].size()){
      int v=son[u][i];
      a=min(a,f(u,1)-f(v,2)+f(v,0));
    }
  }
  return a;
}

int main(void){
  while(scanf("%d",&n)==1){
    MST(check,-1); MST(vis,0); FORR(i,1,n) G[i].CE(),son[i].CE();
    int u,v;
    FOR(i,1,n){
      scanf("%d%d",&u,&v);
      G[u].push_back(v); G[v].push_back(u);
    }
    bfs(1);
    printf("%d\n",min(f(1,0),f(1,2)));  //f(1,1)错误
    scanf("%d",&n); if(n==-1) break;
  }

  return 0;
}
