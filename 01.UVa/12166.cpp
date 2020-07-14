// Tag: ii
// 枚举不变节点，节点以上每层*2，一下每层/2
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
typedef pair<int,int> pii;

const int MAX = 1e6;
int n,dMax; char s[MAX];
unordered_map<int,int> mp[20];

int read(int &i){
  int sum = 0;
  while(isdigit(s[i]))
    sum = sum * 10 + s[i]-'0', ++i;
  return sum;
}

int cnt(int v, int d){
  int sum = 0; LL x = v;
  ROR(i,d,0){
    if(x < INT_MAX) sum += mp[i][x];
    else break;
    x <<= 1;
  }

  x = v;
  FORR(i,d+1,dMax){
    if(x&1) break;
    x >>= 1;
    sum += mp[i][x];
  }
#ifdef DEBUG
  printf("  cnt(%d, %d): %d\n",v,d,sum);
#endif
  return sum;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FOR(i,0,20) mp[i].clear(); dMax = 0;
    scanf("%s",s); n = strlen(s);
    int i = 0, d = 0, sum = 0;
    while(i < n){
      if(s[i] == '[') ++d;
      else if(s[i] == ']') --d;
      else if(s[i] != ','){
        mp[d][read(i)]++, i--, sum++;
        dMax = max(d, dMax);
      }
      i++;
    }
#ifdef DEBUG
    FOR(i,0,20) if(mp[i].size()){
      printf("%3d:",i);
      for(auto p : mp[i]) printf(" %d",p.FI);
      putchar('\n');
    }
#endif
    int ansMin = sum;
    FOR(i,0,20) for(auto p : mp[i])
      ansMin = min(ansMin, sum - cnt(p.FI, i));
    printf("%d\n",ansMin);
  }

  return 0;
}
