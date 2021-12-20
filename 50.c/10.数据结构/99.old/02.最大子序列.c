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

// 在线 O(n)
const int MAXN=100020;
int n, a[MAXN];

int main(void){
  scanf("%d",&n); FOR(i,0,n) scanf("%d",&a[i]);
  int ansMax=-1, l=0, r=n-1, tl=0, tr=0, s=0;
  FOR(i,0,n){
    s += a[i]; tr=i;
    if(s>ansMax){
      ansMax=s; l=tl, r=tr;
    }else if(s<0){
      s=0; tl=i+1;
    }
  }
  printf("%d %d %d\n",max(ansMax,0),a[l],a[r]);

  return 0;
}
