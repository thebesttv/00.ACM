// Tag: 啥玩意 差分 二阶差分 找规律 iii
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
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 1e5;
LL s[MAX*3+20];

int main(void){
  FORR(i,1,MAX) for(int m=3;i*m+3 <= MAX;++m){
    s[i*m+3]++;
    s[(i+1)*m+2]--;
    s[(i+1)*m+1]--;
    s[(i+2)*m-3+3]++;
  }
  FORR(i,2,MAX) s[i] += s[i-2];
  FORR(i,1,MAX) s[i] += s[i-1];
  FORR(i,1,MAX) s[i] += s[i-1];

  int T; scanf("%d",&T);
  FORR(kase,1,T){
    int l,r; scanf("%d%d",&l,&r);
    printf("Case #%d: %lld\n",kase,s[r]-s[l-1]);
  }

  return 0;
}
