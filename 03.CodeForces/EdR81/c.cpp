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

const int MAX = 1e5 + 20;
int n, m;
char s[MAX], t[MAX];
VR<int> pos[26];

int getPos(int ch, int p){
  ch -= 'a';
  auto it = lower_bound(ALL(pos[ch]), p);
  if(it != pos[ch].end()) return *it;
  if(pos[ch].empty()) return -1;
  return pos[ch][0];
}

int cal(){
  int p = 0, ans = 1;
  FOR(i,0,m){
    int tmp = getPos(t[i], p);
    if(tmp == -1) return -1;
    if(tmp < p) ++ans;
    p = tmp + 1;
  }
  return ans;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FOR(i,0,26) pos[i].clear();
    scanf("%s%s",s,t);
    n = strlen(s), m = strlen(t);
    FOR(i,0,n) pos[s[i]-'a'].push_back(i);
    printf("%d\n",cal());
  }

  return 0;
}
