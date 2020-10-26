// Tag: 
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

int nread(){
  int s = 0, ch, neg = 0;
  do ch = getchar(), neg |= (ch == '-'); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return neg ? -s : s;
}

const int MAX = 1e5 + 20;
int n,to[MAX]; VR<int> G[MAX];
int d[MAX];

int main(void){
  n = read();
  FORR(u,1,n){
    int c = read();
    while(c--){
      int v = read();
      G[u].pb(v);
      ++to[v];
    }
  }
  queue<int> q;
  FORR(i,1,n) if(!to[i]) q.push(i), d[i] = 1;
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int v : G[u]) if(!d[v]){
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
  int ansMax = 0, r = -1;
  FORR(i,1,n) if(ansMax < d[i])
    ansMax = d[r = i];
  printf("%d\n",r);

  return 0;
}

