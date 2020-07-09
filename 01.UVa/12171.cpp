// Tag: 3D BFS floodfill 正难则反 离散化 iii
// 类似 [UVa1103 象形文字]，对空气bfs，求出体积&表面积
// 离散化后区间左闭右开
// Link: [UVa 1103]
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

const int MAX = 120;
const int to[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
int n; bool G[MAX][MAX][MAX],vis[MAX][MAX][MAX];
VR<int> v[3];
struct Node{
  int x1,y1,z1,x2,y2,z2;
}node[MAX];

int ID(int x, int i){
  return lower_bound(ALL(v[i]),x) - v[i].begin();
}

void fill(int x1, int y1, int z1, int x2, int y2, int z2){
  x1 = ID(x1,0), y1 = ID(y1,1), z1 = ID(z1,2);
  x2 = ID(x2,0), y2 = ID(y2,1), z2 = ID(z2,2);
#ifdef DEBUG
  printf("fill [%d,%d) [%d,%d) [%d,%d), ori:  [%d,%d) [%d,%d) [%d,%d)\n",x1,x2,y1,y2,z1,z2,
      v[0][x1],v[0][x2],v[1][y1],v[1][y2],v[2][z1],v[2][z2]);
#endif
  FOR(i,x1,x2) FOR(j,y1,y2) FOR(k,z1,z2)
    G[i][j][k] = 1;
}

int vol(int x, int y, int z){
  //if(x == v[0].size()-1 || y == v[1].size()-1 || z == v[2].size()-1) return 0;
  int dx = v[0][x+1] - v[0][x],
      dy = v[1][y+1] - v[1][y],
      dz = v[2][z+1] - v[2][z];
  return dx * dy * dz;
}

int area(int x, int y, int z, int d){
  //if(x == v[0].size()-1 || y == v[1].size()-1 || z == v[2].size()-1) return 0;
  int dx = v[0][x+1] - v[0][x],
      dy = v[1][y+1] - v[1][y],
      dz = v[2][z+1] - v[2][z];
  switch(d){
    case 0: case 1:
      return dy * dz;
    case 2: case 3:
      return dx * dz;
    case 4: case 5:
      return dx * dy;
    default:
      return 0;
  }
}

struct Q { int x,y,z; };
void bfs(int &v, int &a){
  v = a = 0;
  queue<Q> q; q.push({0,0,0});
  vis[0][0][0] = 1;
  while(!q.empty()){
    auto t = q.front(); q.pop();
#ifdef DEBUG
    printf("  node(%d,%d,%d) [%d,%d) [%d,%d) [%d,%d)\n",t.x,t.y,t.z,
        ::v[0][t.x], ::v[0][t.x+1], ::v[1][t.y], ::v[1][t.y+1], ::v[2][t.z], ::v[2][t.z+1]);
    printf("  vol(%d,%d,%d): %d\n",t.x,t.y,t.z,vol(t.x,t.y,t.z));
#endif
    v += vol(t.x,t.y,t.z);
    FOR(d,0,6){
      int tx = t.x + to[d][0],
          ty = t.y + to[d][1],
          tz = t.z + to[d][2];
      if(tx < 0 || ty < 0 || tz < 0 ||
         tx >= ::v[0].size()-1 || ty >= ::v[1].size()-1 || tz >= ::v[2].size()-1)
        continue;
      if(G[tx][ty][tz]){
#ifdef DEBUG
        //printf("  area(%d,%d,%d,%d): %d\n",t.x,t.y,t.z,d,area(t.x,t.y,t.z,d));
        printf("inside vol(%d,%d,%d): %d\n",tx,ty,tz,vol(tx,ty,tz));
#endif
        a += area(t.x,t.y,t.z,d);
        continue;
      }
      if(vis[tx][ty][tz]) continue;
      q.push({tx,ty,tz});
      vis[tx][ty][tz] = 1;
    }
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(G,0); MST(vis,0);
    FOR(i,0,3) v[i].clear(), v[i].push_back(0), v[i].push_back(1020);

    scanf("%d",&n);
    FOR(i,0,n){
      Node &t = node[i];
      scanf("%d%d%d%d%d%d",&t.x1,&t.y1,&t.z1,&t.x2,&t.y2,&t.z2);
      t.x2 += t.x1, t.y2 += t.y1, t.z2 += t.z1;
      v[0].push_back(t.x1); v[0].push_back(t.x2);
      v[1].push_back(t.y1); v[1].push_back(t.y2);
      v[2].push_back(t.z1); v[2].push_back(t.z2);
    }
    FOR(i,0,3) sort(ALL(v[i])), v[i].erase(unique(ALL(v[i])), v[i].end());
#ifdef DEBUG
    FOR(i,0,3){
      printf("%c:",'x'+i);
      for(int x : v[i]) printf(" %d",x);
      putchar('\n');
    }
#endif
    FOR(i,0,n) fill(node[i].x1,node[i].y1,node[i].z1, node[i].x2,node[i].y2,node[i].z2);

    int v, a; bfs(v,a);
    v = 1020 * 1020 * 1020 - v;
    printf("%d %d\n",a,v);
  }

  return 0;
}
