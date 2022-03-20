// Tag: 
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
#include<numeric>
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

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

const int MAX = 120;
set<string> forbidden;
VR<string> v;
int n,m,p,cnt[MAX][2];
int f[MAX][MAX], g[MAX][MAX];

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T) {
    v.clear();
    forbidden.clear();
    scanf("%d%d%d",&n,&m,&p);
    while(n--) {
      string s; cin >> s;
      v.push_back(s);
    }
    while(m--) {
      string s; cin >> s;
      forbidden.insert(s);
    }
    FORR(i,1,p) {
      cnt[i][0] = cnt[i][1] = 0;
      for (const string &s : v) {
        cnt[i][0] += s[i-1] == '1';
        cnt[i][1] += s[i-1] == '0';
      }
    }

    int jMax = m+1;

    f[0][0] = 0;
    FORR(i,1,p) {
    }
  }

  return 0;
}
