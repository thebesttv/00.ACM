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

const int MAX = 300020;
int n,m,ans[MAX]; pii a[MAX];
VR<int> Q[MAX], no[MAX], p[MAX];

struct ST{
  int v[MAX];
  void add(int x){
    while(x<=n) ++v[x], x += x&-x;
  }
  int sum(int x){
    int s = 0;
    while(x) s += v[x], x -= x&-x;
    return s;
  }
}sg;

inline void insert(int a, int b){
  p[min(a,b)].push_back(max(a,b));
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i].FI), a[i].SE = i;
  int l, r;
  FORR(i,1,m){
    scanf("%d%d",&l,&r);
    Q[l].push_back(r);
    no[l].push_back(i);
  }

  sort(a+1,a+1+n);
  int x1, x2;
  insert(a[1].SE, a[2].SE);
  insert(a[n-1].SE, a[n].SE);
  FOR(i,2,n){
    x1 = a[i].FI - a[i-1].FI, x2 = a[i+1].FI - a[i].FI;
    if(x1 <= x2) insert(a[i-1].SE, a[i].SE);
    if(x2 <= x1) insert(a[i].SE, a[i+1].SE);
  }

  ROR(i,n,1){
    for(int j : p[i]) sg.add(j);
    FOR(j,0,Q[i].size()) ans[no[i][j]] = sg.sum(Q[i][j]);
  }
  LL sum = 0;
  FORR(i,1,m) sum += 1ll*i*ans[i];
  printf("%lld\n",sum);

  return 0;
}
