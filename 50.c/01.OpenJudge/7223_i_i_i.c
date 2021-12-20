/*
描述
有一种大青蛙会跳越稻田，从而踩踏稻子。农民在早上看到被踩踏的稻子，希望知道晚上有多少青蛙穿越自家的稻田。每只青蛙总是沿着一条直线跳跃稻田，而且每次跳跃的距离都相同。
如图1和图2所示，稻田里的稻子组成一个栅格，每棵稻子位于一个格点上。而青蛙总是从稻田的一侧跳进稻田，然后沿着某条直线穿越稻田，从另一侧跳出去。
如图3所示，可能会有多只青蛙从稻田穿越。青蛙的每一跳都恰好踩在一棵水稻上，将这棵水稻踩坏。有些水稻可能被多只青蛙踩踏。当然，农民所见到的是图4中的情形，并看不到图3中的直线，也见不到别人家田里被踩踏的水稻。需要注意的是，农民可以根据水稻踩坏的程度来精确计算出一共几只青蛙踩踏过这一棵水稻，所以聪明的农民就能得到图4的水稻毁坏程度图。
我们可以认为每条青蛙跳跃路径上至少包括3棵被踩踏的水稻。而在一条青蛙跳跃路径的直线上，也可能会有些被踩踏的水稻不属于该行走路径，例如青蛙跳跃路径(2,3)(4,5)(6,7)经过(3,4)，而(3,4)不属于跳跃路径。
注意：同一只青蛙不会第二次跳入同一片稻田，可能存在不同的两只青蛙的跳跃路径完全一样。
现在给定水稻破坏程度图，请你写一个程序，确定：最少有多少只青蛙穿越了稻田。例如，图4的答案是4，图3所示的跳跃路径数量就是答案。输入数据保证有解且最多14只青蛙穿越稻田。

输入
从标准输入设备上读入数据。第一行为测试数据数目。每组测试数据第一行上两个整数R、C，分别表示稻田中水稻的行数和列数，1≤R、C≤50。第二行是一个整数N，表示被踩踏的水稻数量， 3≤N≤700。在剩下的N行中，每行有三个整数，分别是一颗被踩踏水稻的行号(1~R)、列号(1~C)和被踩踏次数，三个整数之间用空格隔开。每棵被踩踏水稻只被列出

输出
对于每一组测试数据从标准输出设备上输出一个整数，表示最少有几只青蛙穿越了稻田。

样例输入
1
6 7
14
2 1 1
2 2 1
2 3 2
2 4 1
2 5 1
2 6 2
2 7 1
3 4 1
4 2 1
4 5 1
6 1 1
6 3 1
6 5 1
6 7 2

样例输出
4
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Point{
  int x,y;
  int num;

  bool operator < (const Point & b) const {
    return x!=b.x ? x<b.x : y<b.y;
  }
}ori[720];
struct Line{
  int x,y;
  int dx,dy;
  int cnt;

  void init(int x_, int y_, int dx_, int dy_, int cnt_){
    x=x_; y=y_; dx=dx_; dy=dy_; cnt=cnt_;
  }
  bool operator < (const Line & b) const {
    return cnt>b.cnt;
  }
}line[700*700];
char G[700][700];
int tot_lines,maxDepth;
int r,c,n,sum;
char vis[700*700];

void init();  //生成所有可能的路线
inline bool inside(int x, int y);
bool dfs(int cur, int last);

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    memset(G,0,sizeof(G)); tot_lines=0; sum=0;
    scanf("%d%d%d",&r,&c,&n);
    int x,y,num;
    for(register int i=0;i<n;++i){
      scanf("%d%d%d",&x,&y,&num);
      ori[i].x=x; ori[i].y=y; ori[i].num=num;
      G[x][y]+=num; sum+=num;
    }
    init();
#ifdef DEBUG
    printf("graph:\n");
    for(int i=1;i<=r;i++){
      for(int j=1;j<=c;j++) printf("%3d",(int)G[i][j]);
      printf("\n");
    }
    printf("line: %d\n",tot_lines);
    for(int i=0;i<tot_lines;i++) printf("  (%d,%d), %d, %d, %d\n",line[i].x,line[i].y,line[i].dx,line[i].dy,line[i].cnt);
#endif
    for(maxDepth=1;maxDepth<=14;++maxDepth){
      //printf("depth: %d\n",maxDepth);
      if(dfs(0,0)){
        printf("%d\n",maxDepth);
        break;
      }
    }
  }

  return 0;
}

void init(){
  sort(ori,ori+n);
  register int x,y,dx,dy,cnt,flag;
  for(register int i=0;i<n;++i) for(register int j=i+1;j<n;++j){
    flag=true;
    x=ori[i].x,y=ori[i].y,cnt=0;
    dx=ori[j].x-ori[i].x, dy=ori[j].y-ori[i].y;
    if(inside(x-dx,y-dy)) continue;
    for(;inside(x,y);x+=dx,y+=dy)
      if(!G[x][y]) {flag=false; break;}
      else cnt++;
    if(!flag || cnt<3) continue;
    line[tot_lines].init(ori[i].x,ori[i].y,dx,dy,cnt); tot_lines++;
  }
  sort(line,line+tot_lines);
}
bool dfs(int cur, int last){
  if(cur==maxDepth) return sum==0;
  if(line[last].cnt*(maxDepth-cur)<sum) return false;
  register int x,y,dx,dy,cnt,flag;
  for(register int i=0;i<tot_lines;++i) if(G[line[i].x][line[i].y]){
    x=line[i].x,y=line[i].y,dx=line[i].dx,dy=line[i].dy; cnt=0;
    flag=true;
    for(;inside(x,y);x+=dx,y+=dy)
      if(!G[x][y]) {flag=false; break;}
      else cnt++;
    if(!flag || cnt<3) continue;
    for(x=line[i].x,y=line[i].y;inside(x,y);x+=dx,y+=dy) --G[x][y];
    sum-=cnt;
    if(dfs(cur+1,i)) return true;
    for(x=line[i].x,y=line[i].y;inside(x,y);x+=dx,y+=dy) ++G[x][y];
    sum+=cnt;
  }
  return false;
}
inline bool inside(int x, int y){
  return x>=1 && x<=r && y>=1 && y<=c;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Point{
  int x,y;
  int num;

  bool operator < (const Point & b) const {
    return x!=b.x ? x<b.x : y<b.y;
  }
}ori[720];
struct Line{
  int x,y;
  int dx,dy;
  int cnt;

  void init(int x_, int y_, int dx_, int dy_, int cnt_){
    x=x_; y=y_; dx=dx_; dy=dy_; cnt=cnt_;
  }
  bool operator < (const Line & b) const {
    return cnt>b.cnt;
  }
}line[700*700];
char G[700][700];
int tot_lines,maxDepth;
int r,c,n,sum;

void init();  //生成所有可能的路线
inline bool inside(int x, int y);
bool dfs(int cur);

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    memset(ori,0,sizeof(ori)); memset(line,0,sizeof(line)); tot_lines=0; sum=0;
    scanf("%d%d%d",&r,&c,&n);
    int x,y,num;
    for(int i=0;i<n;i++){
      scanf("%d%d%d",&x,&y,&num);
      ori[i].x=x; ori[i].y=y; ori[i].num=num;
      G[x][y]+=num; sum+=num;
    }
    init();
#ifdef DEBUG
    printf("graph:\n");
    for(int i=1;i<=r;i++){
      for(int j=1;j<=c;j++) printf("%3d",(int)G[i][j]);
      printf("\n");
    }
    printf("line: %d\n",tot_lines);
    for(int i=0;i<tot_lines;i++) printf("  (%d,%d), %d, %d, %d\n",line[i].x,line[i].y,line[i].dx,line[i].dy,line[i].cnt);
#endif
    for(maxDepth=1;maxDepth<=14;maxDepth++)if(dfs(0)){
      printf("%d\n",maxDepth);
      break;
    }
  }

  return 0;
}

void init(){
  sort(ori,ori+n);
  for(int i=0;i<n;i++) for(int j=i+1;j<n;j++){
    bool flag=true;
    int x=ori[i].x,y=ori[i].y,cnt=0;
    int dx=ori[j].x-ori[i].x, dy=ori[j].y-ori[i].y;
    if(inside(x-dx,y-dy)) continue;
    for(;inside(x,y);x+=dx,y+=dy)
      if(!G[x][y]) {flag=false; break;}
      else cnt++;
    if(!flag || cnt<3) continue;
    line[tot_lines].init(ori[i].x,ori[i].y,dx,dy,cnt); tot_lines++;
  }
  sort(line,line+tot_lines);
}
bool dfs(int cur){
  if(cur==maxDepth) return sum==0;
  for(int i=0;i<tot_lines;i++) if(G[line[i].x][line[i].y]){
    int x=line[i].x,y=line[i].y,dx=line[i].dx,dy=line[i].dy;
    bool flag=true; int cnt=0;
    for(;inside(x,y);x+=dx,y+=dy)
      if(!G[x][y]) {flag=false; break;}
      else cnt++;
    if(!flag) continue;
    for(x=line[i].x,y=line[i].y;inside(x,y);x+=dx,y+=dy) G[x][y]--;
    sum-=cnt;
    if(dfs(cur+1)) return true;
    for(x=line[i].x,y=line[i].y;inside(x,y);x+=dx,y+=dy) G[x][y]++;
    sum+=cnt;
  }
  return false;
}
inline bool inside(int x, int y){
  return x>=1 && x<=r && y>=1 && y<=c;
}
*/
