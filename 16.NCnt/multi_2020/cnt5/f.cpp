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
int n; LL d[MAX],dMax;

int s(int i){
  return (50ll * d[i] + dMax - 1) / dMax;
}
void draw(int s, LL d, char ch){
  auto rep = [](int n, char ch){
    FOR(i,0,n) putchar(ch);
  };

  putchar('+'); rep(s,'-'); printf("+\n");

  putchar('|');
  if(s > 0) { rep(s-1,' '); putchar(ch); }
  printf("|%lld\n",d);

  putchar('+'); rep(s,'-'); printf("+\n");
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%lld",&d[i]), dMax = max(dMax, d[i]);
  FORR(i,1,n){
    draw(s(i), d[i], d[i] == dMax ? '*' : ' ');
  }

  return 0;
}
