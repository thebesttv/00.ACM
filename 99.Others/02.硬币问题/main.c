/*
硬币问题：
  给定面值为 v1, v2, ..., vn 的 n 种硬币无限个，*恰好*凑成 S 元。
  求所需的硬币的最大、最小数量。
*/

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

// 递推
const int MAXN=5020;
const int MAXS=100020;
const int INF=0x3f3f3f3f;
int n,s,v[MAXN];
int fMin[MAXS],fMax[MAXS];
int rMin[MAXS],rMax[MAXS];
// f[i]: starting from state i (aka. having i coins),

int main(void){
  scanf("%d%d",&n,&s);
  FOR(i,0,n) scanf("%d",&v[i]);

  fMin[0]=fMax[0]=0;
  FORR(i,1,s) fMin[i]=INF, fMax[i]=-INF;
  FORR(i,1,s) FOR(j,0,n) if(i>=v[j]){
    if(fMin[i] > fMin[i-v[j]]+1){
      fMin[i] = fMin[i-v[j]]+1;
      rMin[i] = v[j];
    }
    if(fMax[i] < fMax[i-v[j]]+1){
      fMax[i] = fMax[i-v[j]]+1;
      rMax[i] = v[j];
    }
  }

  printf("min: %d\n  using coin:",fMin[s]);
  int p=s;
  while(p){
    printf(" %d",rMin[p]);
    p-=rMin[p];
  }
  printf("\n");

  printf("max: %d\n  using coin:",fMax[s]);
  p=s;
  while(p){
    printf(" %d",rMax[p]);
    p-=rMax[p];
  }
  printf("\n");

  return 0;
}
