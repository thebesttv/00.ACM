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

const int MAX=106, MAXH=5060;
int n,a[MAX][MAX],s[MAX][MAX];  // a[i][0]: tot number of blocks in castle i
bool f[MAX][MAXH];

int main(void){
  scanf("%d",&n); int hMin=0x3f3f3f3f;
  FORR(i,1,n){
    int cnt=0, t; scanf("%d",&t);
    while(t!=-1){
      a[i][++cnt]=t; s[i][cnt] = s[i][cnt-1]+a[i][cnt];
      scanf("%d",&t);
    }
    a[i][0]=cnt; s[i][0]=s[i][cnt];
    hMin=min(hMin,s[i][0]);
  }

  FORR(i,1,n){
    f[i][s[i][0]]=1;
    FORR(j,1,a[i][0]) FORR(k,0,s[i][0])
      f[i][k] |= f[i][k+a[i][j]];
  }

  ROR(j,hMin,0){
    bool ok=1;
    FORR(i,1,n) ok&=f[i][j];
    if(ok) { printf("%d\n",j); break; }
  }

  return 0;
}
