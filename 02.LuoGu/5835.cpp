// Tag: 二分
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

const int MAX = 5e4 + 20;
int n,len,s[MAX];

struct Node{
  int w,x,d;
  void read() { scanf("%d%d%d",&w,&x,&d); }
  bool operator < (const Node &b) const {
    return x < b.x;
  }
}node[MAX];

int weight(int t){
  int l = 0, r = 0;
  FORR(i,1,n){
    if(node[i].d > 0)
      r += node[i].x + t >= len;
    else
      l += node[i].x - t <= 0;
  }
#ifdef DEBUG
  printf("weight(%d): l: %d, r: %d, sum: %d\n",t,l,r,s[l] + (s[n] - s[n-r]));
#endif
  return s[l] + (s[n] - s[n-r]);
}

int cal(int t){
  VR<int> v;
  FORR(i,1,n) if(node[i].d < 0) v.pb(node[i].x);
  sort(ALL(v));
  int sum = 0;
  FORR(i,1,n) if(node[i].d > 0){
    auto il = lower_bound(ALL(v), node[i].x);
    auto ir = upper_bound(ALL(v), min((LL)len, node[i].x + t*2ll));
#ifdef DEBUG
    printf("  i: %d, += %d\n",i,ir-il);
#endif
    sum += ir - il;
  }
#ifdef DEBUG
  printf("cal(%d): %d\n",t,sum);
#endif
  return sum;
}

int main(void){
  scanf("%d%d",&n,&len);
  FORR(i,1,n) node[i].read();
  sort(node+1,node+1+n);
  FORR(i,1,n) s[i] = s[i-1] + node[i].w;

  int l = 1, r = len;
  while(l < r){
    int m = (l+r)/2;
    if(weight(m) * 2 < s[n]) l = m+1;
    else r = m;
  }

  printf("%d\n",cal(l));

  return 0;
}

