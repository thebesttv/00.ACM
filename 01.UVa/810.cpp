// Tag: 立方体姿态 3D BFS iii
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

const int to[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int die[7][7][4][2];  // die[a][b][d] 从上看为a，从前看为b，向方向d转动，得到新的 a,b

namespace init{ // init die
  int a[6] = {2, 5, 3, 4, 1, 6};
  const int p[5][6] ={{5, 4, 2, 3, 0, 1},  // up
                      {3, 2, 0, 1, 4, 5},  // right
                      {4, 5, 2, 3, 1, 0},  // down
                      {2, 3, 1, 0, 4, 5},  // left
                      {0, 1, 5, 4, 2, 3}}; // rotate

  void move(int d){
    int b[6];
    FOR(i,0,6) b[p[d][i]] = a[i];
    FOR(i,0,6) a[i] = b[i];
  }
  void up()     {move(0);}
  void right()  {move(1);}
  void down()   {move(2);}
  void left()   {move(3);}
  void rotate() {move(4);}

  void cal(){
    FOR(k,0,4){
      int x = a[0], y = a[4];
      FOR(i,0,4){
        move(i);
        die[x][y][i][0] = a[0];
        die[x][y][i][1] = a[4];
        move((i+2)%4);
      }
      rotate();
    }
  }

  void init(){
    FOR(i,0,4) { cal(); up(); }
    left(); cal();
    left(); left(); cal();

#ifdef DEBUG
    FORR(i,1,6) FORR(j,1,6) FOR(d,0,4) if(die[i][j][d][0])
      printf("die(%d, %d, %d): (%d, %d)\n",i,j,d,die[i][j][d][0],die[i][j][d][1]);
#endif
  }
}

const int MAX = 12;
int n,m,sx,sy,sa,sb; char s[40];
int G[MAX][MAX]; bool vis[MAX][MAX][7][7];
struct Node{
  int x,y,a,b,r;
}q[10*10*6*6+20];

int main(void){
  init::init();
  while(scanf("%s",s)==1 && strcmp(s,"END")){
    MST(vis,0);
    scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&sa,&sb);
    FORR(i,1,n) FORR(j,1,m) scanf("%d",&G[i][j]);

    int head = 0, tail = 0, p = -1;
    q[tail++] = {sx, sy, sa, sb, -1};
    while(head < tail){
      Node &t = q[head];
      if(t.x == sx && t.y == sy && t.r != -1){
        p = head; break;
      }

      FOR(d,0,4){
        int tx = t.x + to[d][0],
            ty = t.y + to[d][1];
        if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if(G[tx][ty] != -1 && t.a != G[tx][ty]) continue;
        int ta = die[t.a][t.b][d][0],
            tb = die[t.a][t.b][d][1];
        if(vis[tx][ty][ta][tb]) continue;
        q[tail++] = {tx, ty, ta, tb, head};
        vis[tx][ty][ta][tb] = 1;
      }
      head++;
    }
    printf("%s\n",s);
    if(p == -1) { printf("  No Solution Possible\n"); continue; }
    VR<pii> ans;
    while(p != -1){
      ans.push_back({q[p].x,q[p].y});
      p = q[p].r;
    }
    reverse(ALL(ans));
    FOR(i,0,ans.size()){
      if(i%9 == 0) printf("  ");
      printf("(%d,%d)",ans[i].FI,ans[i].SE);
      if(i != ans.size()-1) putchar(',');
      if(i%9 == 8 || i == ans.size()-1) putchar('\n');
    }
  }

  return 0;
}
