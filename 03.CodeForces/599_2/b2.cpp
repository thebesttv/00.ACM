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

const int MAX = 100;
int n, cnt[26];
char s[MAX], t[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(cnt,0);
    scanf("%d",&n);
    scanf("%s%s",s,t);
    FOR(i,0,n){
      ++cnt[s[i]-'a'];
      ++cnt[t[i]-'a'];
    }

    bool bad = 0;
    FOR(i,0,26) if(cnt[i]&1){
      bad = 1; break;
    }
    if(bad){
      printf("No\n"); continue;
    }

    VR<pair<int,int>> v;
    FOR(i,0,n) if(s[i] != t[i]){
      FOR(j,i+1,n)
        if(t[j] == s[i]){
          swap(s[i+1], t[j]);
          swap(s[i+1], t[i]);
          v.push_back({i+1,j});
          v.push_back({i+1,i});
          break;
        }else if(s[j] == s[i]){
          swap(s[j], t[i]);
          v.push_back({j,i});
          break;
        }
    }

    if(strcmp(s,t)) printf("No\n");
    else{
      printf("Yes\n");
      printf("%d\n",v.size());
      for(auto p : v)
        printf("%d %d\n",p.FI + 1,p.SE + 1);
    }
  }

  return 0;
}
