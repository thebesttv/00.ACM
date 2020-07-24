// Tag: 自然溢出 Fibonacci
// 自然溢出即可做到两两不同模
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
#include<unordered_map>
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
typedef pair<LLU,int> pii;

const int MAX = 2000000, MAX_ = MAX + 20;
LLU f[MAX_]; pii v[MAX_];

void read(LLU &x){
  int n,op; x = 0;
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d",&op);
    x += op * f[i];
  }
}

int main(void){
  f[1] = 1, f[2] = 2;
  v[1] = {1,1}, v[2] = {2,2};
  FORR(i,3,MAX) f[i] = f[i-1] + f[i-2], v[i] = {f[i],i};
  sort(v+1,v+1+MAX);

  int T; scanf("%d",&T);
  while(T--){
    LLU a,b,c; read(a), read(b), read(c);
    LLU d = a * b - c;
    int idx = lower_bound(v+1,v+1+MAX,pii{d,0}) - v;
    printf("%d\n",v[idx].SE);
  }

  return 0;
}

/*
const int SIZ = 3;
const int MOD[3] = {int(1e9+7), 963816179, 776531401};
const int MAX = 2000000, MAX_ = MAX + 20;
int f[SIZ][MAX_];

void read(int *v){
  int n,op; v[0] = v[1] = v[2] = 0;
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d",&op);
    v[0] = (v[0] + op * f[0][i])%MOD[0];
    v[1] = (v[1] + op * f[1][i])%MOD[1];
    v[2] = (v[2] + op * f[2][i])%MOD[2];
  }
#ifdef DEBUG
  printf("get:"); FOR(j,0,SIZ) printf(" %lld",v[j]); putchar('\n');
#endif
}

int cnt[MAX_], col[MAX_];

int main(void){
  FOR(j,0,SIZ) f[j][1] = 1, f[j][2] = 2;
  FORR(i,3,MAX){
    f[0][i] = (f[0][i-1] + f[0][i-2])%MOD[0];
    f[1][i] = (f[1][i-1] + f[1][i-2])%MOD[1];
    f[2][i] = (f[2][i-1] + f[2][i-2])%MOD[2];
  }

  int T; scanf("%d",&T);
  FORR(kase,1,T){
    int a[SIZ],b[SIZ],c[SIZ],d[SIZ];
    read(a), read(b), read(c);
    FOR(j,0,SIZ) d[j] = (1ll*a[j]*b[j] - c[j] + MOD[j])%MOD[j];
    FORR(i,1,MAX) if(f[0][i] == d[0]){
      if(f[1][i] == d[1] && f[2][i] == d[2]){
        printf("%d\n",i); break;
      }
    }
  }

  return 0;
}
*/
