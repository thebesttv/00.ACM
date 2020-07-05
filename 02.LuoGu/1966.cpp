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
const int MOD = 1e8 - 3;
int n,v[MAX]; pii a[MAX],b[MAX];
map<int,int> pos;

struct ST{
  int n,v[MAX];
  void add(int x, int a){
    while(x<=n) v[x] += a, x += x&-x;
  }
  int sum(int x){
    int s = 0;
    while(x) s += v[x], x -= x&-x;
    return s;
  }
}sg;

int main(void){
  scanf("%d",&n); sg.n = n;
  FOR(i,0,n){
    scanf("%d",&a[i].FI), a[i].SE = i+1;
    pos[a[i].FI] = i+1; sg.add(i+1,1);
  }
  FOR(i,0,n){
    scanf("%d",&b[i].FI), b[i].SE = i+1;
  }
  sort(a,a+n); sort(b,b+n);
  FOR(i,0,n) v[b[i].SE] = a[i].FI;

  int ans = 0;
  FORR(i,1,n){
    int p = pos[v[i]];
    ans = (ans + sg.sum(p) - 1) % MOD;
#ifdef DEBUG
    printf(" %d\n",ans);
#endif
    sg.add(p,-1);
  }
  printf("%d\n",ans);
  
  return 0;
}
