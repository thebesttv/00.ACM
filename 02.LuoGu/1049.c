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

const int MAXV=20020, MAXN=40;
int s,n,v[MAXN];
bool f[MAXV];

int main(void){
  scanf("%d%d",&s,&n);
  FORR(i,1,n) scanf("%d",&v[i]);

  f[0]=1;
  FORR(i,1,n) ROR(j,s,v[i]) f[j] |=  f[j-v[i]];
  ROR(i,s,0) if(f[i]){
    printf("%d\n",s-i); break;
  }

  return 0;
}
