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
int n,cnt;
// 0 为 super root
bool g[MAX][2]; // f[i][j] 是否唯一
map<string,int> mp;
VR<int> G[MAX];

int id(string &s){
  if(mp.count(s)) return mp[s];
  return mp[s] = ++cnt;
}

int dp(int u, bool choose){
  if(G[u].empty()){
    g[u][choose]=1;
    return choose;
  }

  bool isUnique = 1;
  int sum=0;
  if(choose){
    sum = 1;
    for(int v : G[u]){
      sum += dp(v,0);
      if(!g[v][0]) isUnique=0;
    }
  }else{
    for(int v : G[u]){
      int x1 = dp(v,0), x2 = dp(v,1);
      if(x1==x2){
        sum+=x1;  // -_-
        isUnique=0;
      }else if(x1>x2){
        sum+=x1;
        if(!g[v][0]) isUnique=0;
      }else{
        sum+=x2;
        if(!g[v][1]) isUnique=0;
      }
    }
  }
  g[u][choose] = isUnique;
  return sum;
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    mp.clear(); cnt=0;
    FORR(i,0,n) G[i].clear();

    string u,v; cin >> u;
    int root = id(u);
    G[0].push_back(root); // super root

    FOR(i,1,n){
      cin >> v >> u;
      G[id(u)].push_back(id(v));
    }

    int ans = dp(0,0); // super root 不能选
    printf("%d %s\n",ans, g[0][0] ? "Yes" : "No");
  }

  return 0;
}

/*
const int MAX=220;
int n,cnt;
bool g[MAX][2]; // f[i][j] 是否唯一
map<string,int> mp;
VR<int> G[MAX];

int id(string &s){
  if(mp.count(s)) return mp[s];
  return mp[s] = ++cnt;
}

int dp(int u, bool choose){
  if(G[u].empty()){
    g[u][choose]=1;
    return choose;
  }

  bool isUnique = 1;
  int sum=0;
  if(choose){
    sum = 1;
    for(int v : G[u]){
      sum += dp(v,0);
      if(!g[v][0]) isUnique=0;
    }
  }else{
    for(int v : G[u]){
      int x1 = dp(v,0), x2 = dp(v,1);
      if(x1==x2){
        sum+=x1;  // -_-
        isUnique=0;
      }else if(x1>x2){
        sum+=x1;
        if(!g[v][0]) isUnique=0;
      }else{
        sum+=x2;
        if(!g[v][1]) isUnique=0;
      }
    }
  }
  g[u][choose] = isUnique;
  return sum;
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    mp.clear(); cnt=0;
    FORR(i,1,n) G[i].clear();

    string u,v; cin >> u;
    int root = id(u);

    FOR(i,1,n){
      cin >> v >> u;
      G[id(u)].push_back(id(v));
    }

    int x1 = dp(root,0), x2 = dp(root,1);
    int ans; bool isUnique;
    if(x1==x2){
      ans=x1, isUnique=0;
    }else if(x1>x2){
      ans=x1, isUnique=g[root][0];
    }else{
      ans=x2, isUnique=g[root][1];
    }
    printf("%d %s\n",ans, isUnique ? "Yes" : "No");
  }

  return 0;
}
*/
