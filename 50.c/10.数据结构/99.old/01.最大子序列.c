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
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

/*
// 分治
const int MAXN=100020;
int n,a[MAXN];

int subSumMax(int l, int r){
  if(l+1==r) return a[l];
  int m = (l+r)>>1;
  int ansMax = subSumMax(l,m);
  ansMax = max(ansMax,subSumMax(m,r));
  int lm=0, rm=0, ts=0;
  ROR(i,m-1,l){
    ts += a[i];
    lm = max(lm, ts);
  }
  ts=0;
  FOR(i,m,r){
    ts += a[i];
    rm = max(rm, ts);
  }
  return max(ansMax, lm+rm);
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  printf("%d\n",subSumMax(0,n));

  return 0;
}
*/

// 在线 O(n)
const int MAXN=200020;
int n, a, ansMax=0, s=0;
int l,r;

int main(void){
  scanf("%d",&n);
  while(n--){
    scanf("%d",&a);
    s += a;
    ansMax=max(ansMax,s);
    if(s<0) s=0;
  }
  printf("%d\n",ansMax);

  return 0;
}
