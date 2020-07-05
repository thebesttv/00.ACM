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

const int to[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,dir,sx,sy,ex,ey,x,y;
char s[100];

void move(int dx, int dy){
  if(dx>0){
    switch(dir){
      case 0: break;
      case 1: printf("RIGHT\n"); break;
      case 2: printf("UTURN\n"); break;
      case 3: printf("LEFT\n"); break;
    }
    dir = 0;
    printf("MOVE %d\n",dx);
  }else if(dx<0){
    switch(dir){
      case 0: printf("UTURN\n"); break;
      case 1: printf("LEFT\n"); break;
      case 2: break;
      case 3: printf("RIGHT\n"); break;
    }
    dir = 2;
    printf("MOVE %d\n",-dx);
  }

  if(dy>0){
    switch(dir){
      case 0: printf("LEFT\n"); break;
      case 1: break;
      case 2: printf("RIGHT\n"); break;
      case 3: printf("UTURN\n"); break;
    }
    dir = 1;
    printf("MOVE %d\n",dy);
  }else if(dy<0){
    switch(dir){
      case 0: printf("RIGHT\n"); break;
      case 1: printf("UTURN\n"); break;
      case 2: printf("LEFT\n"); break;
      case 3: break;
    }
    dir = 3;
    printf("MOVE %d\n",-dy);
  }
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    dir = x = y =0;
    while(n--){
      scanf("%s",s);
      if(s[0]=='M'){ // MOVE
        int v; scanf("%d",&v);
        x += to[dir][0]*v;
        y += to[dir][1]*v;
      }else switch(s[0]){
        case 'L': dir = (dir+1)%4; break;
        case 'R': dir = (dir+3)%4; break;
        case 'U': dir = (dir+2)%4; break;
      }
    }
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);

    printf("Robot Program #%d:\nThe robot is at (%d,%d)\n",
        kase,x,y);

    // coffee
    int dx = sx - x, dy = sy - y;
    move(dx,dy);
    x = sx, y = sy;

    // Dr. S
    dx = ex - x, dy = ey - y;
    move(dx,dy);
    putchar('\n');
  }

  return 0;
}
