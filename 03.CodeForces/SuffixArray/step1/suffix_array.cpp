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
int n,a[MAX],b[MAX]; char s[MAX];
struct Node{
  int idx, a, b;
  bool operator < (const Node &c) const {
    return a != c.a ? a < c.a : b < c.b;
  }
  bool operator == (const Node &c) const {
    return a == c.a && b == c.b;
  }
  bool operator != (const Node &c) const {
    return ! ((*this) == c);
  }
}node[MAX];

int main(void){
  scanf("%s",s); n = strlen(s);
  s[n++] = '$'; s[n] = 0;
  printf("sorting s(%d): %s\n",n,s);

  int rnd = 0;
  while((1<<rnd) < n) ++rnd;
  printf("total rounds: %d\n",rnd);

  FOR(i,0,n) a[i] = s[i];
  FORR(k,0,rnd){
    printf("in round %d\n",k);
    int j = k==0 ? 0 : (1 << (k-1))%n;
    FOR(i,0,n){
      node[i] = {i, a[i], a[j]};
      printf("node[%d] from a[%d]: %d, a[%d]: %d\n",i,i,a[i],j,a[j]);
      j = (j + 1) % n;
    }
    sort(node,node+n);
    int c = 0; a[node[0].idx] = 0;
    FOR(i,1,n){
      if(node[i] != node[i-1]) ++c;
      a[node[i].idx] = c;
    }
    printf("a:"); FOR(i,0,n) printf(" %d",a[i]); putchar('\n');
  }
  FOR(i,0,n) b[a[i]] = i;
  FOR(i,0,n) printf("p[%d]: %d, %s\n",i,b[i],s+b[i]);

  return 0;
}
