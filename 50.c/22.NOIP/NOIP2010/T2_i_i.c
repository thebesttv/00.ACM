/*
描述
在一个遥远的国度，一侧是风景秀美的湖泊，另一侧则是漫无边际的沙漠。该国的行政区划十分特殊，刚好构成一个N行M列的矩形，其中每个格子都代表一座城市，每座城市都有一个海拔高度。

  -------------------------------
                湖泊             
  -------------------------------
  |  |  |  |  |  |  |  |  |  |  |
  |-----------------------------|
  |  |  |  |  |  |  |  |  |  |  |
  |-----------------------------|
  |  |  |  |  |  |  |  |  |  |  |
  |-----------------------------|
  |  |  |  |  |  |  |  |  |  |  | 干旱区
  -------------------------------
                沙漠            

为了使居民们都尽可能饮用到清澈的湖水，现在要在某些城市建造水利设施。水利设施有两种，分别为蓄水厂和输水站。蓄水厂的功能是利用水泵将湖泊中的水抽取到所在城市的蓄水池中。因此，只有与湖泊毗邻的第1行的城市可以建造蓄水厂。而输水站的功能则是通过输水管线利用高度落差，将湖水从高处向低处输送。故一座城市能建造输水站的前提，是存在比它海拔更高且拥有公共边的相邻城市，已经建有水利设施。
由于第N行的城市靠近沙漠，是该国的干旱区，所以要求其中的每座城市都建有水利设施。那么，这个要求能否满足呢？如果能，请计算最少建造几个蓄水厂；如果不能，求干旱区中不可能建有水利设施的城市数目。

格式
输入格式
输入文件的每行中两个数之间用一个空格隔开。
输入的第一行是两个正整数N和M，表示矩形的规模。
接下来N行，每行M个正整数，依次代表每座城市的海拔高度。

输出格式
输出有两行。如果能满足要求，输出的第一行是整数1，第二行是一个整数，代表最少建造几个蓄水厂；如果不能满足要求，输出的第一行是整数0，第二行是一个整数，代表有几座干旱区中的城市不可能建有水利设施。

样例1
样例输入1
2 5
9 1 5 4 3
8 7 6 1 2

样例输出1
1
1

限制
每个测试点1s

数据范围
本题共有10个测试数据，每个数据的范围如下表所示：
测试数据编号 能否满足要求   N     M
1            不能           ≤10   ≤10
2            不能           ≤100  ≤100
3            不能           ≤500  ≤500
4            能             =1    ≤10
5            能             ≤10   ≤10
6            能             ≤100  ≤20
7            能             ≤100  ≤50
8            能             ≤100  ≤100
9            能             ≤200  ≤200
10           能             ≤500  ≤500
对于所有的10个数据，每座城市的海拔高度都不超过10^6。

来源
noip2010提高组复赛
*/

/*
  得分：0
  解题报告：（考后）
    表示考试时完全看错题意了。。。而且又写错一行，就暴零了。。。
    因为关注的是最后一行能不能被完全覆盖，中间的n-2行只在搜索染色时有用。
    首先可以想到枚举+搜索，但枚举复杂度太大，无法承受。
    再想到（虽然我不知道是怎么想到的），可以对每个点(0,i)搜索，得到其对干旱区的贡献（即能使多少块干旱区有水）。
    可以证明，如果有解，那么每一个(0,i)对干旱区的贡献都为一段连续的区间。
      证明：（反证法）
        假设(0,i)贡献的一段区间是不连续的，不妨假设隔开这一段区间的只有一块干旱区A，那么A的高度一定大于A的左右两块的高度。
        又因为有解，则一定有一条从(0,j)到A的高度递减的路径a使得A有水。
        无论(0,j)在(0,i)左边还是右边，为了到达A，路径a一定与(0,i)所扩展出的路径相交。
        而一旦相交，则(0,i)一定能将水输送到A，那么这段区间就应该是连续的，与假设矛盾，因此假设不成立。
    那么就可以对每个(0,i)，记录其贡献区间[l,r]的左右端点。因为每个(0,i)是独立的，一个(0,i)选与不选对其他已经选择的点的贡献不造成影响，而题目又只关注最少的(0,i)的个数，因此现在只需关心贡献的区间即可，不必再关心(0,i)。
    于是整个问题转化为“使用尽量少的区间覆盖[1,m]，并求出使用区间的个数”。
    那么就可以贪心地解决了。
      首先对所有区间按照左端点升序排列，令一个焦点focus（初始值为1）表示当前需要覆盖的区间为[focus,m]。
      每次循环中，遍历l<=focus的区间，找到其中[focus,r]最长的，然后使用该区间，令focus=r+1，继续循环。
      最终等到focus=m+1，使用区间个数即为答案。
    （贪心待证明）
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

struct Node{
  int x,y;

  Node() { }
  Node(int x_, int y_): x(x_), y(y_) { }
};
struct Node2{ //记录区间
  int l,r;

  bool operator < (const Node2 & b) const {
    return l<b.l;
  }
}a[520];  //a[i]表示若(0,i)建立蓄水厂，其能到达干旱区的区间（若有解，则每个区间一定是连续的）
int G[520][520],n,m;
bool vis[520][520];
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void bfs(queue<Node> & q);

int main(void){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&G[i][j]);
  
  int cnt=0;
  {
    queue<Node> q; for(int i=0;i<m;i++) {q.push(Node(0,i)); vis[0][i]=1;}
    bfs(q);
    for(int i=0;i<m;i++) if(!vis[n-1][i]) cnt++;
  }
  if(cnt){  //无解
    printf("%d\n%d\n",0,cnt);
  }else{  //有解
    for(int i=0;i<m;i++){ //通过m次bfs建立区间
      memset(vis,0,sizeof(vis));
      queue<Node> q; q.push(Node(0,i)); vis[0][i]=1;
      bfs(q);
      for(int j=0;j<m;j++) if(vis[n-1][j]) {a[i].l=j; break;}
      for(int j=m-1;j>=0;j--) if(vis[n-1][j]) {a[i].r=j; break;}
    }

    //贪心地覆盖区间
    sort(a,a+m);
    int focus=0,pos=0,cnt=0;
    while(pos<m && focus<m){
      int tMax=0,u=0;
      while(pos<m && a[pos].l<=focus){
        if(a[pos].r-focus+1>tMax) tMax=(a[u=pos].r-focus+1);
        pos++;
      }
      cnt++;
      focus=a[u].r+1;
    }
    printf("%d\n%d\n",1,cnt);
  }
  return 0;
}

void bfs(queue<Node> & q){
  while(!q.empty()){
    Node t=q.front(); q.pop();
    for(int i=0;i<4;i++){
      int tx=t.x+to[i][0];
      int ty=t.y+to[i][1];
      if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
      if(vis[tx][ty] || G[tx][ty]>=G[t.x][t.y]) continue;
      vis[tx][ty]=1; q.push(Node(tx,ty));
    }
  }
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int G[520][520];
struct Node{
  int x,y;

  Node() { }
  Node(int x_, int y_): x(x_), y(y_) { }
};
struct Node2{
  int h,num;

  bool operator < (const Node2 & b) const {
    return h>b.h;
  }
}a[520];
bool vis[520][520];
int n,m;
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void bfs(int x, int y);

int main(void){
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++) {scanf("%d",&G[0][i]); a[i].h=G[0][i]; a[i].num=i;}
  for(int i=1;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&G[i][j]);
  sort(a,a+m);

  int cnt=0;
  for(int i=0;i<m;i++) if(!vis[0][a[i].num]){
#ifdef DEBUG
    printf("  (%d,%d)\n",0,a[i].num);
#endif
    bool flag=1;
    for(int j=0;j<m;j++) if(!vis[n-1][j]) {flag=0; break;}
    if(flag) break;
    cnt++; vis[0][a[i].num]=1;
    bfs(0,a[i].num);
  }
  int left=0;
  //for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!vis[i][j]) left++;
  for(int j=0;j<m;j++) if(!vis[n-1][j]) left++;
  if(!left) printf("%d\n%d\n",1,cnt);
  else printf("%d\n%d\n",0,left);

  return 0;
}

void bfs(int x, int y){
  queue<Node> q; q.push(Node(x,y));
  vis[x][y]=1;
  while(!q.empty()){
    Node t=q.front(); q.pop();
    for(int i=0;i<4;i++){
      int tx=t.x+to[i][0];
      int ty=t.y+to[i][1];
      //if(x<0 || x>=n || y<0 || y>=m) continue;
      if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
      if(vis[tx][ty] || G[tx][ty]>=G[t.x][t.y]) continue;
      vis[tx][ty]=1; q.push(Node(tx,ty));
    }
  }
}
*/
