// Tag: 暴力
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

const int MAX = 10;
int n,a[MAX],r[MAX],pos[26]; char s[100];
set<int> G[26];

void build(){
  int i = 0, len = strlen(s);
  while(i<len){
    int u = s[i] - 'A'; i += 2;
    while(isalpha(s[i]))
      G[u].insert(s[i]-'A'), ++i;
    ++i;
  }
  FOR(u,0,26) for(int v : G[u])
    G[v].insert(u);
#ifdef DEBUG
  FOR(u,0,26) if(G[u].size()){
    printf("%c:",u+'A');
    for(int v : G[u]) printf(" %c",v+'A');
    putchar('\n');
  }
#endif
}

int b(){
  FOR(i,0,n) pos[a[i]] = i;
  int tMax = 0;
  FOR(i,0,n) for(int v : G[a[i]])
    tMax = max(tMax, abs(pos[a[i]] - pos[v]));
  return tMax;
}

int main(void){
  while(scanf("%s",s)==1 && s[0]!='#'){
    n = 0; FOR(i,0,26) G[i].clear();
    build();
    FOR(i,0,26) if(G[i].size()) a[n++] = i;

    int ansMin = 0x3f3f3f3f;
    do{
      int x = b();
      if(x < ansMin) { ansMin = x; memcpy(r,a,sizeof(r)); }
    }while(next_permutation(a,a+n));

    FOR(i,0,n) printf("%c ",r[i]+'A');
    printf("-> %d\n",ansMin);
  }

  return 0;
}
