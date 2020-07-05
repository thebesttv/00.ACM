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

const int MAXN = 1e6+20, MAX = (1<<20)+20;
int n,f[MAX]; char s[MAXN];
bool vis[MAX];
VR<int> v[22];

int cnt(int st){
  int s=0;
  while(st){
    s+=(st&1); st>>=1;
  }
  return s;
}

int main(void){
  scanf("%s",s);
  n = strlen(s);
  FOR(i,0,n) s[i]-='a';

  FOR(i,0,n){
    int st = 1<<s[i];
    vis[st]=1;
    for(int j=1;i+j<n && j<20;++j)
      if(st&(1<<s[i+j])) break;
      else{
        st|=(1<<s[i+j]);
        vis[st]=1;
      }
  }
  FOR(i,0,1<<20) v[cnt(i)].push_back(i);
  FORR(len,1,20) for(int st : v[len]){
    int &a = f[st];
    if(vis[st]) a = len;
    else FOR(j,0,20) if(st&(1<<j))
      a = max(a,f[st&(~(1<<j))]);
  }
  int ans = 0;
  FOR(i,0,1<<20) ans = max(ans, f[i] + f[ ((1<<20)-1)&(~i) ]);
  printf("%d\n",ans);

  return 0;
}
