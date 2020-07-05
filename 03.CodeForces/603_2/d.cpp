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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 2e5 + 20;
int n, sum[MAX]; char s[100];
int cnt[26], color[MAX];
VR<int> G[MAX], hasC[26];

int dfsSum=0;
void dfs(int u, int c){
  ++dfsSum;
  color[u] = c;
  for(int v : G[u]) if(!color[v]){
    dfs(v, c);
  }
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%s",s);

    int len = strlen(s);
    FOR(j,0,len){
      cnt[s[j]-'a'] = i;
    }

    FOR(j,0,26) if(cnt[j]==i)
      hasC[j].push_back(i);
  }

  FOR(i,0,26) if(hasC[i].size()>1){
    int u = hasC[i][0], v;
    FOR(j,1,hasC[i].size()){
      v = hasC[i][j];
      G[u].push_back(v);
      G[v].push_back(u);
    }
  }
  int c = 0; int tot = 0;
  FORR(i,1,n) if(!color[i]){
    dfsSum = 0;
    dfs(i, ++c);
    sum[c] = dfsSum;
    tot += dfsSum;
  }
  /*
  int ansMin = 0x3f3f3f3f;
  FORR(i,1,c){
#ifdef DEBUG
    printf("  sum[%d]: %d\n",i,sum[i]);
#endif
    ansMin = min(ansMin, tot - sum[i] + 1);
  }
  printf("%d\n",ansMin);
  */
  printf("%d\n",c);

  return 0;
}
