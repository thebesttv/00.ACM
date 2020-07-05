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

const int MAX = 2e5 + 20;
int n, a[MAX];
struct Node{
  int l, r, len;
  bool operator < (const Node &b) const {
    return len != b.len ? len < b.len : l > b.l;
  }
};
PQ<Node> q;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    q.push({1,n,n});
    FORR(i,1,n){
      Node t = q.top(); q.pop();
      int l = t.l, r = t.r, m = (t.l + t.r) / 2;
      a[m] = i;
      if(m > l) q.push({l, m-1, m-1-l+1});
      if(m < r) q.push({m+1, r, r-m-1+1});
    }
    FORR(i,1,n) printf("%d ",a[i]); putchar('\n');
  }

  return 0;
}
