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
#include<sstream>
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

const int MAX = 2048;
const int INF = 0x3f3f3f3f;
int n,G[MAX][MAX],su,eu;
char line[2020];

int IDCnt = 0;
map<string, int> mp;
VR<string> fromID;
int ID(const string &s){
  if(mp.count(s)) return mp[s];
  fromID[++IDCnt] = s;
#ifdef DEBUG
  printf("  %s: %d\n",s.c_str(),IDCnt);
#endif
  return mp[s] = IDCnt;
}

bool dfs(int u, VR<int> &res){
  res.push_back(u);
  if(u == eu) return true;
  FORR(k,1,n) if(G[u][k] == 1 && G[u][eu] == 1 + G[k][eu]){
    if(dfs(k, res)) return true;
  }
  res.pop_back();
  return false;
}

int main(void){
  MST(G,0x3f); fromID.resize(MAX);
  scanf("%d",&n); FGETS(line);

  FOR(i,0,n){
    do FGETS(line); while(strlen(line)==0);
    stringstream ss(line);
    string s; ss >> s;
    int u = ID(s), v;
    while(ss >> s){
      v = ID(s);
      G[u][v] = G[v][u] = 1;
#ifdef DEBUG
      printf("  %d <-> %d\n",u,v);
#endif
    }
  }

  n = IDCnt;
  FORR(i,1,n) G[i][i] = 0;

  FORR(k,1,n) FORR(i,1,n) FORR(j,1,n){
    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
  }

  scanf("%s",line); su = ID(line);
  scanf("%s",line); eu = ID(line);
#ifdef DEBUG
  printf("  from %d, to %d\n",su,eu);
#endif

  if(G[su][eu] == INF){
    printf("no route found\n");
  }else{
    /*
    VR<int> res;
    dfs(u,res);
    for(int u : res){
      printf("%s ",fromID[u].c_str());
    }
    */

    int u = su, v = eu;
    printf("%s",fromID[u].c_str());
    while(u != v){
      FORR(k,1,n) if(G[u][k] == 1 && G[u][v] == 1 + G[k][v]){
        printf(" %s",fromID[k].c_str());
        u = k; break;
      }
    }
    putchar('\n');
  }

  return 0;
}
