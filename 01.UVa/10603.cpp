// Tag: 优先队列 i
// 求最少倒水量，而非最少步数，因此将队列改为优先队列
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
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 220;
const int INF = 0x3f3f3f3f;
int v[3],d,dis[MAX]; bool vis[MAX][MAX];
struct Node{
  int v[3],dis;
  Node(int a, int b, int c, int d) : dis(d){
    v[0]=a, v[1]=b, v[2]=c;
  }
  bool operator < (const Node &b) const {
    return dis > b.dis;
  }
};

void bfs(){
  MST(dis,0x3f); MST(vis,0);
  PQ<Node> q; vis[0][0]=1;
  q.push(Node(0,0,v[2],0));

  while(!q.empty()){
    Node t = q.top(); q.pop();
#ifdef DEBUG
    printf("(%d, %d, %d): %d\n",t.v[0],t.v[1],t.v[2],t.dis);
#endif
    FOR(i,0,3) dis[t.v[i]]=min(dis[t.v[i]], t.dis);
    FOR(i,0,3) if(t.v[i]) FOR(j,0,3) if(j!=i){  // pour i into j
      Node nt = t; int d = min(t.v[i], v[j] - t.v[j]);
      nt.v[i] -= d, nt.v[j] += d, nt.dis += d;
      if(vis[nt.v[0]][nt.v[1]]) continue;
      q.push(nt); vis[nt.v[0]][nt.v[1]] = 1;
    }
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d",&v[0],&v[1],&v[2],&d);
    bfs();
    int ansMin = INF, r=-1;
    ROR(i,d,0) if(dis[i]!=INF){
      r = i, ansMin = dis[i]; break;
    }
    printf("%d %d\n",ansMin,r);
  }

  return 0;
}
