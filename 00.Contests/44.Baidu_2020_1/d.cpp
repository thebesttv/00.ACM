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

const int MAX = 520;
const int to[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,x,y,G[MAX][MAX],ansMin;
bool vis1[MAX][MAX],vis2[MAX][MAX];

struct Node{
  int x,y,d;
}q[MAX*MAX];

int cal(int x, int y, int ori){
  int head = 0, tail = 0, v[4];
  v[1] = v[2] = v[3] = 0;

  q[tail++] = {x,y,0}; vis2[x][y]=1;
  while(head < tail){
    Node t = q[head++];
    v[G[t.x][t.y]]++;
    if(t.d < 3) FOR(d,0,4){
      int tx = t.x + to[d][0];
      int ty = t.y + to[d][1];
      if(tx < 1 || tx > n || ty < 1 || ty > n || vis2[tx][ty])
        continue;
      q[tail++]={tx,ty,t.d+1};
      vis2[tx][ty] = 1;
    }
  }
  FOR(i,0,tail) vis2[q[i].x][q[i].y]=0;

  VR<int> s(v[1]+v[2]+v[3]);
  s[0] = G[x][y]; --v[G[x][y]];
  FOR(i,1,s.size()){
    if(v[3])      s[i] = s[i-1] + 3, --v[3];
    else if(v[2]) s[i] = s[i-1] + 2, --v[2];
    else          s[i] = s[i-1] + 1, --v[1];
  }
#ifdef DEBUG
  printf("s:");FOR(i,0,10) printf(" %d",s[i]); putchar('\n');
#endif

  int cnt = ori, cur = 1, sum = 0;
  while(cur < 9){
    ++cnt; sum += s[min(cur, (int)s.size()) - 1];
#ifdef DEBUG
    printf("cnt: %d, sum += %d: %d, cur %d -> ",cnt,s[min(cur, (int)s.size()) - 1],sum,cur);
#endif
    while(sum >= 8 * cur * cur) ++cur;
#ifdef DEBUG
    printf("%d\n",cur);
#endif
  }
#ifdef DEBUGG
  printf("cal(%d, %d): %d\n",x,y,cnt);
#endif
  return cnt;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&x,&y); ansMin = 0x3f3f3f3f;
    FORR(i,1,n) FORR(j,1,n) scanf("%d",&G[i][j]), vis1[i][j]=0;

    queue<Node> q; q.push({x,y,0}); vis1[x][y]=1;
    while(!q.empty()){
      Node t = q.front(); q.pop();
      ansMin = min(ansMin, cal(t.x,t.y, ceil(t.d/2.0)));

      FOR(d,0,4){
        int tx = t.x + to[d][0];
        int ty = t.y + to[d][1];
        if(tx < 1 || tx > n || ty < 1 || ty > n || vis1[tx][ty])
          continue;
        q.push({tx,ty,t.d+1});
        vis1[tx][ty] = 1;
      }
    }

    printf("%d\n",ansMin);
  }

  return 0;
}
