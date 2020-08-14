// Tag: 状压DP
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

int n,m,f[120][64][64],mp[1<<10],v[64],cnt[64];
int G[120]; char str[20];

inline bool ok(int st1, int st2){
  return (st1 & st2) == 0;
}

int main(void){
  scanf("%d%d",&n,&m);
  int tail = 0;
  FOR(st,0,1<<m) if((st & ((st<<1)|(st<<2))) == 0){
    int c = 0; FOR(j,0,m) c += (st>>j)&1;
    mp[st] = tail, v[tail] = st;
    cnt[tail++] = c;
  }
  FORR(i,1,n){
    scanf("%s",str);
    FOR(j,0,m) if(str[j]=='P') G[i] |= 1<<j;
  }

  int ansMax = 0;
  FORR(i,0,n) FOR(st3,0,tail) FOR(st2,0,tail) if(ok(v[st2],v[st3])
      && ((i==0 && !st2)   || (i>0 && (v[st2]|G[i])==G[i]))
      && ((i-1<=0 && !st3) || (i-1>0 && (v[st3]|G[i-1])==G[i-1]))){
    int a = f[i][st2][st3];
    FOR(st1,0,tail) if((v[st1] | G[i+1]) == G[i+1] && ok(v[st1],v[st2]) && ok(v[st1],v[st3])){
      f[i+1][st1][st2] = max(f[i+1][st1][st2], a + cnt[st1]);
    }
#ifdef DEBUG
    printf("f[%d][%d][%d]: %d\n",i,v[st2],v[st3],a);
#endif
    ansMax = max(ansMax, a);
  }
  printf("%d\n",ansMax);

  return 0;
}
