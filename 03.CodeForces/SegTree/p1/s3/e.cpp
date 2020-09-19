// Tag: notag
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

const int MAX = 2e5 + 20;
int n,m;

struct ST{
  int n; LL v[MAX];
  void add(int x, int val){
    while(x <= n) v[x] += val, x += x&-x;
  }
  LL sum(int x){
    LL s = 0;
    while(x) s += v[x], x -= x&-x;
    return s;
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m); sg.n = n;
  int op;
  while(m--){
    scanf("%d",&op);
    if(op == 1){
      int l,r,v; scanf("%d%d%d",&l,&r,&v);
      sg.add(l+1, v); sg.add(r+1, -v);
    }else{
      int x; scanf("%d",&x);
      printf("%lld\n",sg.sum(x+1));
    }
  }

  return 0;
}
