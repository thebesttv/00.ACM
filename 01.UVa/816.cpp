// Tag: iii BFS 大模拟
// 所用方向都使用绝对方向（东南西北）
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

const int to[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // N E S W, to dir -> from (dir+2)%4
int n,m,sx,sy,sdir,ex,ey;
char name[40],s[10];
struct Vec { bool from[4][3], ok; } G[20][20];
struct Node {
  int x,y,dir;  // travel dir (approach from travelling in dir)
  int r;  // from which node in queue
}q[10 * 10 * 4 + 20];
bool vis[20][20][4];  // vis[x][y][d]: approach (x,y) from travelling in dir d

int fromDir(char ch){
  switch(ch){
    case 'N': return 0;
    case 'E': return 1;
    case 'S': return 2;
    case 'W': return 3;
    default: return -1;
  }
}

int fromFacing(char ch){
  switch(ch){
    case 'L': return 0;
    case 'F': return 1;
    case 'R': return 2;
    default: return -1;
  }
}

int main(void){
  while(scanf("%s",name)==1 && strcmp(name,"END")){
    MST(G,0); MST(vis,0);
    scanf("%d%d%s%d%d",&sx,&sy,s,&ex,&ey);
    G[sx][sy].ok = G[ex][ey].ok = 1;
    sdir = fromDir(s[0]);

#ifdef DEBUG
    printf("        N   E   S   W\n");
#endif
    int x, y;
    while(scanf("%d",&x)==1 && x && scanf("%d",&y)){
      G[x][y].ok = 1;
      while(scanf("%s",s) && s[0]!='*'){
        int len = strlen(s), dir;
        FOR(i,1,len)
          G[x][y].from[fromDir(s[0])][fromFacing(s[i])] = 1;
      }
#ifdef DEBUG
      printf("(%d,%d):",x,y);
      FOR(d,0,4){
        putchar(' ');
        FOR(f,0,3) putchar(G[x][y].from[d][f] ? '1' : '.');
      }
      putchar('\n');
#endif
    }

    int head = 1, tail = 0, ansR = -1;
    q[tail++] = { sx, sy, -1, -1 };
    q[tail++] = { sx + to[sdir][0], sy + to[sdir][1], sdir, 0 };
    if(G[sx + to[sdir][0]][sy + to[sdir][1]].ok) while(head < tail){
      Node &t = q[head];
#ifdef DEBUG
      printf("%2d: approach (%d, %d) from travelling in dir %d, rec: %2d\n",head,t.x,t.y,t.dir,t.r);
#endif
      if(t.x == ex && t.y == ey){
        ansR = head; break;
      }

      FOR(f,0,3) if(G[t.x][t.y].from[t.dir][f]){
#ifdef DEBUG
        printf("    trying facing %d\n",f-1);
#endif
        int toDir = (t.dir + f - 1 + 4)%4;
        int tx = t.x + to[toDir][0],
            ty = t.y + to[toDir][1];
        if(vis[tx][ty][toDir] || !G[tx][ty].ok)
          continue;
        q[tail++] = {tx, ty, toDir, head};
        vis[tx][ty][toDir] = 1;
      }
      head++;
    }

    printf("%s\n",name);
    if(ansR == -1) { printf("  No Solution Possible\n"); continue; }

    stack<pii> st; int r = ansR;
    while(r != -1){
      st.push({q[r].x, q[r].y});
      r = q[r].r;
    }

    int cnt = -1;
    while(!st.empty()){
      cnt = (cnt + 1)%10;
      if(cnt == 0) putchar(' ');
      printf(" (%d,%d)",st.top().FI,st.top().SE);
      if(cnt == 9 || st.size()==1) putchar('\n');
      st.pop();
    }
  }

  return 0;
}
