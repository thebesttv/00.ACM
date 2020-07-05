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

const int MAX = 120;
int n;
struct Node{
  LL v;
  int pow2, pow3;
  void cal(){
    LL t = v;
    while(t%2==0) t/=2, ++pow2;
    while(t%3==0) t/=3, ++pow3;
  }
  bool operator < (const Node &b) const {
    return pow3 != b.pow3 ? pow3 > b.pow3 : pow2 < b.pow2;
  }
}node[MAX];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%lld",&node[i].v), node[i].cal();
  sort(node, node+n);
  FOR(i,0,n) printf("%lld ",node[i].v); putchar('\n');

  return 0;
}

/*
const int MAX = 120;
int n,dp[MAX],r[MAX];
LL a[MAX];
VR<int> G[MAX];
bool vis[MAX];

int f(int u){
  int &a = dp[u];
  if(a) return a;

  a = 1;
  for(int v : G[u]) if(f(v)+1>a){
    a = f(v)+1; r[u] = v;
  }
  return a;
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%lld",&a[i]);
  FORR(i,1,n) FORR(j,1,n){
    if(a[i]%3==0 && a[i]/3==a[j]){
      G[i].push_back(j);
    }else if(a[i]*2==a[j]){
      G[i].push_back(j);
    }
  }

  int rec = 0;
  FORR(i,1,n) if(f(i)==n)
    rec = i;
  FOR(i,0,n){
    printf("%lld ",a[rec]);
    rec = r[rec];
  }
  putchar('\n');

  return 0;
}
*/
