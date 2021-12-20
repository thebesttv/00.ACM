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

const int MAXT = 10020; // max round
const int MAXN = 10;    // max user
const int MAXR = 100;  // max reward
const int RANGE = 20;

int n, T; double fuel;
int ansMax = 0, ansT = 0, recMax[MAXT], rec[MAXT];
double G[MAXN][MAXN]; // 距离
double averageDis = 0;

struct Node{
  int x, y;
  VR<int> r;

  Node(int x, int y): x(x), y(y) { }

  void generate(int t){ // randomly generate rewards of t rounds
    r.clear();
    while(t--) r.push_back(rand()%1000);
  }
};
VR<Node> node;

double dis(int i, int j){
  int dx = node[i].x - node[j].x;
  int dy = node[i].y - node[j].y;
  return sqrt(dx*dx + dy*dy);
}

double fCal(int r){ // 计算消耗 = reward * 0.1
  return r * 0.1;
}

double fHover(){  // 盘旋消耗 = 1.5 * 平均距离
  return averageDis * 1.5;
}

double fTravel(int u, int v){
  if(u==v) return fHover();
  else return G[u][v];  // 飞行消耗 = 距离
}

void dfs(int u, int dep, double fuel, int reward){
  if(fuel < dis(u,0)) return;
#ifdef DEBUG
  FOR(i,0,dep) printf("  ");
  printf("dfs(%d,%d,%.1lf,%d)\n",u,dep,fuel,reward);
#endif

  if(reward > ansMax){
    ansMax = reward, ansT = dep;
    memcpy(recMax, rec, SIZ(rec));
  }

  FORR(i,1,n){
    double cost = fTravel(u,i) + fCal(node[i].r[dep]);

    if(fuel > cost){
#ifdef DEBUG
      FORR(i,0,dep) printf("  ");
      printf("%d -> %d, cost: %.1lf\n",u,i,cost);
#endif
      rec[dep] = i;
      dfs(i, dep+1, fuel - cost, reward + node[i].r[dep]);
    }
  }
}

int main(void){
  srand(time(NULL));

  node.push_back(Node(0,0));

  n = 4; fuel = 200; T = 100;

  FORR(i,1,n){
    int x = rand()%RANGE;
    int y = rand()%RANGE;

    node.push_back(Node(x,y));
    node[i].generate(T);

    FOR(j,1,i){
      G[i][j]=G[j][i]=dis(i,j);
      averageDis += G[i][j]*2;
    }
  }
  averageDis /= (n*n);

#ifdef DEBUG
  printf("%d users in total:\n",n);
  FORR(i,1,n){
    printf("  (%d,%d):",node[i].x,node[i].y);
    FOR(j,0,10) printf(" %d",node[i].r[j]);
    putchar('\n');
  }
#endif
  dfs(0,0,fuel,0);
  printf("max reward: %d, total rounds: %d, route:\n",ansMax,ansT);
  FOR(i,0,ansT) printf("%d ",recMax[i]);
  putchar('\n');

  return 0;
}
