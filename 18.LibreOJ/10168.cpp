// Tag: 数位DP iii TODO
// 维护平方和真尼玛烦 :(
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

const int MAX = 20;
const LL MOD = 1e9+7;
int v[MAX]; LL l,r,p10s[MAX],p10[MAX];

// 两种方式维护前缀和皆可
struct Node{
  LL cnt, sum, sqsum;
  Node() { cnt = sum = sqsum = 0; }
  Node(LL cnt) : cnt(cnt) { sum = sqsum = 0; }
  void add(const Node &b, int i, int cur){
    cnt = (cnt + b.cnt) % MOD;
    sum = (sum + b.sum + i*p10[cur-1] %MOD * b.cnt %MOD)%MOD;
    sqsum = (sqsum + b.sqsum + 2*i*p10[cur-1] %MOD * b.sum %MOD + b.cnt * i*i %MOD * p10s[cur-1] %MOD)%MOD;
  }
  LL ans(){
    return sqsum;
  }
}f[MAX][7][7];

/*
struct Node{
  LL cnt, lsum, lsum2, sqsum;
  Node() { cnt = lsum = lsum2 = sqsum = 0; }
  Node(LL cnt) : cnt(cnt) { lsum = lsum2 = sqsum = 0; }
  void add(const Node &b, int i, int cur){
    cnt = (cnt + b.cnt)%MOD;
    lsum = (lsum + b.lsum + b.cnt * i %MOD * p10[cur-1] %MOD)%MOD;
    lsum2 = (lsum2 + b.lsum2 + 2ll*i*p10[cur-1]%MOD*b.lsum%MOD)%MOD;
    sqsum = (sqsum + b.sqsum + b.cnt * i*i %MOD * p10s[cur-1]%MOD)%MOD;
  }
  LL ans(){
    return (lsum2 + sqsum)%MOD;
  }
}f[MAX][7][7];
*/

Node dfs(int cur, int dmod, int mod, bool limited){
  if(!cur) return Node(dmod && mod);

  Node &a = f[cur][dmod][mod];
  if(!limited && a.cnt!=-1) return a;
  int r = limited ? v[cur] : 9; Node p;

  FORR(i,0,r) if(i!=7){
    Node t = dfs(cur-1, (dmod+i)%7, (mod*10+i)%7, limited && i==r);
    p.add(t, i, cur);
  }
#ifdef DEBUG
  printf("  dfs(%d, %d, %d, %d): cnt: %lld, lsum: %lld, lsum2: %lld, sqsum: %lld\n",
      cur,dmod,mod,limited,p.cnt,p.lsum,p.lsum2,p.sqsum);
#endif

  if(!limited) a = p;
  return p;
}

LL solve(LL x){
  int len = 0;
  while(x) v[++len]=x%10,x/=10;
  MST(f,-1);
  Node p = dfs(len,0,0,true);
  return p.ans();
}

int main(void){
  p10[0] = p10s[0] = 1;
  FOR(i,1,MAX){
    p10[i] = p10[i-1]*10%MOD;
    p10s[i] = p10s[i-1]*100%MOD;
  }

  int T; scanf("%d",&T);
  while(T--){
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",(solve(r)-solve(l-1)+MOD)%MOD);
  }

  return 0;
}
