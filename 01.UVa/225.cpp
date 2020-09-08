// Tag: notag
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

const char *str = "nsew";
const int to[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m,cnt,sum[40]; set<pii> st,vis; char rec[120];
VR<string> ans;

bool ok(int x1, int x2, int y1, int y2){
  if(x1 > x2) swap(x1, x2);
  if(y1 > y2) swap(y1, y2);
  for(const auto p : st)
    if(x1 <= p.FI && p.FI <= x2 && y1 <= p.SE && p.SE <= y2)
      return false;
  return true;
}

void dfs(int cur, int x, int y, int last){
  if(sum[n] - sum[cur-1] < max(abs(x), abs(y))) return;
  if(cur == n+1){
    if(x==0 && y==0){
      // printf("%s\n",rec+1); ++cnt;
      ans.pb(string(rec+1)); ++cnt;
    }
    return;
  }
  if(last <= 1) FOR(d,2,4){
    int tx = x + to[d][0] * cur,
        ty = y + to[d][1] * cur;
    if(!ok(x, tx, y, ty) || vis.find({tx,ty}) != vis.end()) continue;
    vis.insert({tx,ty});
    rec[cur] = str[d];
    dfs(cur+1, tx, ty, d);
    rec[cur] = 0;
    vis.erase({tx,ty});
  }else FOR(d,0,2){
    int tx = x + to[d][0] * cur,
        ty = y + to[d][1] * cur;
    if(!ok(x, tx, y, ty) || vis.find({tx,ty}) != vis.end()) continue;
    vis.insert({tx,ty});
    rec[cur] = str[d];
    dfs(cur+1, tx, ty, d);
    rec[cur] = 0;
    vis.erase({tx,ty});
  }
}

int main(void){
  FORR(i,1,30) sum[i] = sum[i-1] + i;

  int T; scanf("%d",&T);
  while(T--){
    st.clear(); ans.clear(); cnt = 0;
    scanf("%d%d",&n,&m);
    int x,y;
    while(m--){
      scanf("%d%d",&x,&y);
      st.insert({x,y});
    }
    if(n == 7 || n == 8 || n == 15 || n == 16){
      FOR(d,0,4){
        rec[1] = str[d];
        dfs(2, to[d][0], to[d][1], d);
      }
      sort(ALL(ans));
      for(auto &s : ans) printf("%s\n",s.c_str());
    }
    printf("Found %d golygon(s).\n\n",cnt);
#ifdef DEBUG
    if(cnt) printf("%d ok\n",n);
#endif
  }

  return 0;
}
