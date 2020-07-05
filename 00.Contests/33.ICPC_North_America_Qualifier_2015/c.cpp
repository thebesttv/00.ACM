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

const int MAX = 120;
int n;
struct Node{
  int speak;
  set<int> st;
}node[MAX];
VR<int> G[MAX];

map<string,int> namemp, langmp;
int nameCnt, langCnt;
int nameID(const string &s){
  if(namemp.count(s)) return namemp[s];
  return namemp[s] = ++nameCnt;
}
int langID(const string &s){
  if(langmp.count(s)) return langmp[s];
  return langmp[s] = ++langCnt;
}

int dfn[MAX],dfnCnt,low[MAX],sccnt,belong[MAX];
stack<int> st;
bool inst[MAX];
void tarjan(int u){
  dfn[u] = low[u] = ++dfnCnt;
  st.push(u); inst[u] = 1;
  for(int v : G[u]){
    if(!dfn[v]){
      tarjan(v);
      if(low[v] < low[u]){
        low[u] = low[v];
      }
    }else if(inst[v] && dfn[v] < low[u]){
      low[u] = dfn[v];
    }
  }

  if(dfn[u] != low[u]) return;
  int v; ++sccnt;
  do{
    v = st.top(); st.pop();
    belong[v] = sccnt; inst[v] = 0;
  }while(u != v);
}

int cnt[MAX];

int main(void){
  scanf("%d",&n); getchar();
  FORR(i,1,n){
    string line,s; getline(cin, line);
    stringstream ss(line);
    ss >> s;
    int u = nameID(s), v;
    ss >> s;
    node[u].speak = langID(s);
    node[u].st.insert(node[u].speak);
    while(ss >> s){
      v = langID(s);
      node[u].st.insert(v);
    }
#ifdef DEBUG
    printf("  ind %d speaks %d, understands:",u,node[u].speak);
    for(int x : node[u].st) printf(" %d",x);
    putchar('\n');
#endif
  }

  FORR(i,1,n) FORR(j,1,n) if(i!=j)
    if(node[j].st.count(node[i].speak)){
#ifdef DEBUG
      printf("  %d -> %d\n",i,j);
#endif
      G[i].push_back(j);
    }

  FORR(i,1,n) if(!dfn[i])
    tarjan(i);

  FORR(i,1,n) ++cnt[belong[i]];
#ifdef DEBUG
  FORR(i,1,n) printf("  belong[%d]: %d\n",i,belong[i]);
#endif
  int tMax = 0;
  FORR(i,1,sccnt) tMax = max(tMax, cnt[i]);
  printf("%d\n",n-tMax);

  return 0;
}
