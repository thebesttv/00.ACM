// Tag: 数位DP
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

const LL MOD = 1e9 + 7;
const int MAX = 1020;

int n; char v[MAX];
LL f[MAX][10][11][2];

void sub(){
  int carry = 0, n = strlen(v+1);
  ROR(i,n,1){
    if(--v[i] >= '0') break;
    v[i] += 10;
  }
  if(v[1] == '0' && n>1){
    FORR(i,2,n) v[i-1] = v[i];
    v[n] = 0;
  }
}

LL dfs(int cur, int last1, int last2, bool st, bool limited, bool lead){
  if(cur == n+1) return st;
#ifdef DEBUG
  printf("  dfs(%d, %d, %d, %d, %d, %d)\n",cur,last1,last2,st,limited,lead);
#endif
  LL sum = 0;
  if(lead){
    int r = limited ? v[cur] - '0' : 9;
    sum = dfs(cur+1, -1, -1, 0, limited && r==0, true);
    FORR(i,1,r) sum = (sum + dfs(cur+1, i, -1, 0, limited && i==r, false))%MOD;
  }else{
    LL &a = f[cur][last1][last2+1][st];
    if(!limited && a != -1) return a;
    int r = limited ? v[cur] - '0' : 9;
    FORR(i,0,r){
      sum = (sum + dfs(cur+1, i, last1, st || (i==last1 || i==last2), limited && i==r, false))%MOD;
    }
    if(!limited) a = sum;
  }
  return sum;
}

LL solve(){
  n = strlen(v+1); MST(f,-1);
#ifdef DEBUG
  printf("len: %d\n",n);
#endif
  return dfs(1,-1,-1,false,true,true);
}

int main(void){
  scanf("%s",v+1); sub(); LL cl = solve();
#ifdef DEBUG
  printf("solve %s: %lld\n",v+1,cl);
#endif
  scanf("%s",v+1); LL cr = solve();
#ifdef DEBUG
  printf("solve %s: %lld\n",v+1,cr);
#endif
  printf("%lld\n",(cr-cl+MOD)%MOD);

  return 0;
}
