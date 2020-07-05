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

const int MAX = 1e5 + 20;
const int INF = 0x3f3f3f3f;
int n,v[MAX],l[MAX],r[MAX],fa[MAX];

int p(int x){
  return fa[x]<0 ? x : fa[x]=p(fa[x]);
}

map<int,bool> isOk;

void dfs(int u, int vMin, int vMax){
  if(v[u]<vMin && v[u]>vMax){
    isOk[v[u]] = 1;
  }
  if(l[u]) dfs(l[u],min(v[u],vMin),vMax);
  if(r[u]) dfs(r[u],vMin,max(v[u],vMax));
}

int main(void){
  MST(fa,-1); scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d%d%d",&v[i],&l[i],&r[i]);
    if(l[i]==-1) l[i]=0;
    else fa[l[i]]=i;
    if(r[i]==-1) r[i]=0;
    else fa[r[i]]=i;
  }

  int root = p(1);
#ifdef DEBUG
  printf("  root: %d\n",root);
#endif

  dfs(root,INF,-1);

  int sum = 0;
  FORR(i,1,n) if(!isOk[v[i]])
    ++sum;

  printf("%d\n",sum);

  return 0;
}

/*
const int MAX = 1e5 + 20;
const int INF = 0x3f3f3f3f;
int n,v[MAX],l[MAX],r[MAX],fa[MAX];
bool isOk[MAX]; // node

int p(int x){
  return fa[x]<0 ? x : fa[x]=p(fa[x]);
}

map<int,int> mp;
void dfs(int u, int vMin, int vMax){
  if(!mp[v[u]]){  // no rep
    mp[v[u]] = u;
    isOk[u] = v[u]<vMin && v[u]>vMax;
    if(l[u]) dfs(l[u],min(v[u],vMin),vMax);
    if(r[u]) dfs(r[u],vMin,max(v[u],vMax));
    mp[v[u]] = 0;
  }else{
    isOk[u] = isOk[mp[v[u]]];
    if(l[u]) dfs(l[u],min(v[u],vMin),vMax);
    if(r[u]) dfs(r[u],vMin,max(v[u],vMax));
  }
}

int main(void){
  MST(fa,-1);
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d%d%d",&v[i],&l[i],&r[i]);
    if(l[i]==-1) l[i]=0;
    else fa[l[i]]=i;
    if(r[i]==-1) r[i]=0;
    else fa[r[i]]=i;
  }

  int root = p(1);
#ifdef DEBUG
  printf("  root: %d\n",root);
#endif

  dfs(root,INF,-1);

  int sum = 0;
  FORR(i,1,n) if(!isOk[i])
    ++sum;

  printf("%d\n",sum);

  return 0;
}
*/
