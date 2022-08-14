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

const int MAX = 100020;
int n,a[MAX],p[MAX]; char s[MAX];
struct Node{
  int idx, a, b;
  bool operator < (const Node &c) const {
    return a != c.a ? a < c.a : b < c.b;
  }
  bool operator != (const Node &c) const {
    return a != c.a || b != c.b;
  }
}node[MAX];

int main(void){
  scanf("%s",s); n = strlen(s);
  s[n++] = '$'; s[n] = 0;
  int rnd = 0;
  while((1<<rnd) < n) ++rnd;

  FOR(i,0,n) a[i] = s[i];
  FORR(k,0,rnd){
    int j = k==0 ? 0 : 1 << (k-1);
    FOR(i,0,n){
      node[i] = {i, a[i], a[j]};
      j = (j+1)%n;
    }
    sort(node,node+n);

    int c = 0; a[node[0].idx] = 0;
    FOR(i,1,n){
      if(node[i] != node[i-1]) ++c;
      a[node[i].idx] = c;
    }
  }
  FOR(i,0,n) p[a[i]] = i;
  FOR(i,0,n) printf("%d ",p[i]); putchar('\n');

  return 0;
}
