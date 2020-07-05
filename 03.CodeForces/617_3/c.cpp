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
int n; char str[MAX];
LL s[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    map<LL, VR<int> >mp;
    scanf("%d%s",&n,str+1);
    mp[0].push_back(0);
    FORR(i,1,n){
      if(str[i] == 'L') s[i] = 1;
      else if(str[i]=='R') s[i] = -1;
      else if(str[i]=='U') s[i] = MAX;
      else if(str[i]=='D') s[i] = -MAX;
      s[i] += s[i-1];
      mp[s[i]].push_back(i);
    }
#ifdef DEBUG
    FORR(i,1,n){
      printf(" %lld",s[i]);
    }
    putchar('\n');
    for(auto p : mp) printf("  mp[%lld]: %d\n",
        p.first, p.second.size());
#endif
    int lMin = MAX, rl = -1, rr = -1;
    for(auto p : mp) if(p.second.size()>1){
      VR<int> &v = p.second;
      FOR(i,1,v.size()) if(v[i]-v[i-1] < lMin){
        lMin = v[i]-v[i-1];
        rl = v[i-1] + 1, rr = v[i];
      }
    }
    if(lMin==MAX) printf("-1\n");
    else printf("%d %d\n",rl,rr);
  }

  return 0;
}
