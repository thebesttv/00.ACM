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

const int MAX=1020;
struct Node{
  char s[30];
  int l,r;
  bool operator < (const Node & b) const {
    return strcmp(s,b.s)<0;
  }
}edge[MAX];
bool vis[MAX],G2[30][30];
VR<int> G[30];
int in[30],out[30],n;
bool first=1;
int ans[MAX],save[MAX];

bool dfs(int cur, int u){
  if(cur==n) {memcpy(save,ans,sizeof(ans)); return true;}
  FOR(i,0,G[u].size()) if(!vis[G[u][i]]){
    vis[G[u][i]]=1; ans[cur]=G[u][i];
    if(dfs(cur+1,edge[G[u][i]].r)) return true;
  }
  return false;
}
bool allconnected(){
  FOR(i,0,n) vis[edge[i].l]=vis[edge[i].r]=1;
  int ori=0; FOR(i,0,26) if(vis[i]) ori++;
  MST(vis,0);
  int cnt=1; queue<int> q; q.push(edge[0].l); vis[edge[0].l]=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    FOR(i,0,26) if((G2[u][i] || G2[i][u]) && !vis[i]){
      vis[i]=1; q.push(i); cnt++;
    }
  }
  return cnt==ori;
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) {scanf("%s",edge[i].s); edge[i].l=edge[i].s[0]-'a'; edge[i].r=edge[i].s[strlen(edge[i].s)-1]-'a';}
  sort(edge,edge+n);
  FOR(i,0,n){
    G[edge[i].l].push_back(i); G2[edge[i].l][edge[i].r]=1;
    out[edge[i].l]++; in[edge[i].r]++;
  }

  bool flag=1;
  int cnt=0,s=-1;
  FOR(i,0,26) if(in[i]!=out[i]){
    if(in[i]+1==out[i]) s=i,cnt++;
    else if(out[i]+1==in[i]) cnt++;
    else {flag=0; break;}
  }
  if(flag==0 || (cnt!=0 && cnt!=2) || !allconnected()) printf("***\n");
  else{
    MST(vis,0);
    if(s==-1) FOR(i,0,26) {MST(vis,0); if(G[i].size() && dfs(0,i)) break;}
    else dfs(0,s);
    printf("%s",edge[save[0]].s); FOR(i,1,n) printf(".%s",edge[save[i]].s);
    printf("\n");
  }

  return 0;
}
