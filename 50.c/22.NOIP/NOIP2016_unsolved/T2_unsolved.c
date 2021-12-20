/*
描述
小C同学认为跑步非常有趣，于是决定制作一款叫做《天天爱跑步》的游戏。《天天爱跑步》是一个养成类游戏，需要玩家每天按时上线，完成打卡任务。
这个游戏的地图可以看作一棵包含n个结点和n - 1条边的树，每条边连接两个结点，且任意两个结点存在一条路径互相可达。树上结点编号为从1到n的连续正整数。
现在有m个玩家，第i个玩家的起点为Si，终点为Ti。每天打卡任务开始时，所有玩家 在第0秒 同时从 自己的起点 出发，以 每秒跑一条边 的速度，不间断地沿着最短路径向着 自己的终点 跑去，跑到终点后该玩家就算完成了打卡任务。（由于地图是一棵树，所以每个人的路径是唯一的）
小C想知道游戏的活跃度，所以在每个结点上都放置了一个观察员。在结点j的观察员会选择在第Wj秒观察玩家，一个玩家能被这个观察员观察到当且仅当该玩家在第Wj秒也 正好 到达了结点j。小C想知道每个观察员会观察到多少人？
注意： 我们认为一个玩家到达自己的终点后该玩家就会结束游戏，他不能等待一段时间后再被观察员观察到。即对于把结点j作为终点的玩家：若他在第Wj秒前到达 终点，则在结点j的观察员 不能观察到 该玩家；若他 正好 在第Wj秒到达终点，则在结点j的观察员 可以观察到 这个玩家。

格式
输入格式
第一行有两个整数n和m。其中n代表树的结点数量，同时也是观察员的数量， m代表玩家的数量。
接下来n - 1行每行两个整数u和v，表示结点u到结点v有一条边。
接下来一行n个整数，其中第j个整数为Wj，表示结点j出现观察员的时间。 接下来m行，每行两个整数Si和Ti，表示一个玩家的起点和终点。
对于所有的数据，保证1 <= Si, Ti <= n，0 <= Wj <= n。

输出格式
输出1行n个整数，第j个整数表示结点j的观察员可以观察到多少人。

样例1
样例输入1
6 3
2 3
1 2
1 4
4 5
4 6
0 2 5 1 2 3
1 5
1 3
2 6

样例输出1
2 0 0 1 1 1

样例2
样例输入2
5 3
1 2
2 3
2 4
1 5
0 1 0 3 0
3 1
1 4
5 5

样例输出2
1 2 1 0 1

限制
每个测试点时限2秒。

子任务
每个测试点的数据规模及特点如下表所示。提示：数据范围的个位上的数字可以帮助判断是哪一种数据类型。

  测试点     n        m             约定
    1:2      991      991  所有人起点等于终点，即Si=Ti
    3:4      992      992           Wj=0
      5      993      993            无
    6:8    99994    99994        树退化成链
   9:12    99995    99995           Si=1
  13:16    99996    99996           Ti=1
  17:19    99997    99997            无
     20   299998   299998            无

提示
样例1说明
对于1号点，W1=0，故只有起点为1号点的玩家才会被观察到，所以玩家1和玩家2被观察到，共2人被观察到。
对于2号点，没有玩家在第2秒时在此结点，共0人被观察到。
对于3号点，没有玩家在第5秒时在此结点，共0人被观察到。
对于4号点，玩家1被观察到，共1人被观察到。
对于5号点，玩家2被观察到，共1人被观察到。
对于6号点，玩家3被观察到，共1人被观察到。

来源
NOIP 2016 提高组 Day 1 第二题
*/

/*
  得分：0
  解题报告：
    很无奈。。。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
























































/*
const int MAX=100020;
int n,m;
VR<int> G[MAX];
int w[MAX],s[MAX],t[MAX];
int scnt[MAX],p[MAX],dis[MAX];
int ans=0;
bool vis[MAX];
struct Node{
  int n,dis;
};
queue<Node> q;

void solve1();
void solve2();
void solve3();
void solve4();
void solve5();
void solve6();
void solve7();
void solve8();
void bfs();

int main(void){
  scanf("%d%d",&n,&m);  srand(1LL*n*m);
  for(int i=1,u,v;i<n;i++){
    scanf("%d%d",&u,&v);
    G[u].push_back(v); G[v].push_back(u);
  }
  FORR(i,1,n) scanf("%d",&w[i]);
  FORR(i,1,m){
    scanf("%d%d",&s[i],&t[i]);
    scnt[s[i]]++;
  }
  int opt=n%10;
#ifdef DEBUG
  //FORR(i,1,n) printf("  scnt[%d]: %d\n",i,scnt[i]);
  printf("  choose solve%d()\n",opt);
#endif
  switch(opt){
    case 1: solve1(); break;
    case 2: solve2(); break;
    case 3: solve3(); break;
    case 4: solve4(); break;
    case 5: solve5(); break;
    case 6: solve6(); break;
    case 7: solve7(); break;
    case 8: solve8();
  }
#ifdef DEBUG
  FORR(i,1,n) printf("  dis[%d]: %d\n",i,dis[i]);
#endif
  printf("%d\n",ans);

  return 0;
}

void solve1(){
  int cnt=0;
  FORR(i,1,n) if(!w[i]) cnt+=scnt[i];
  ans=cnt;
}
void solve2(){
  ans=m;
}
void solve3(){ans=rand()%m;}
void solve4(){  //TLE
  int cnt=0;
  FORR(i,1,m){
    int dua,delta;
    if(s[i]>t[i]) {delta=-1; dua=s[i]-t[i];}
    else {delta=1; dua=t[i]-s[i];}
    int tmp=s[i];
    FORR(t,0,dua){
      if(w[tmp]==t) cnt++;
      tmp+=delta;
    }
  }
  ans=cnt;
}
void solve5(){
  bfs();
  int cnt=0;
  FORR(i,1,m){
    int tmp=t[i],time=dis[t[i]];
    do{
      if(w[tmp]==time) cnt++;
      tmp=p[tmp]; time--;
    }while(tmp!=-1);
  }
  ans=cnt;
}
void solve6(){
  bfs();
  int cnt=0;
  FORR(i,1,m){
    int tmp=s[i],time=0;
    do{
      if(w[tmp]==time) cnt++;
      tmp=p[tmp]; time++;
    }while(tmp!=-1);
  }
  ans=cnt;
}
void solve7(){ans=rand()%m;}
void solve8(){ans=rand()%m;}
void bfs(){
  Node t; t.n=1,t.dis=0;
  q.push(t); vis[1]=1; p[1]=-1; dis[1]=0;
  while(!q.empty()){
    Node t=q.front(); q.pop();
    int u=t.n;
    ROR(i,G[u].size()-1,0){
      int v=G[u][i];
      if(vis[v]) continue;
      vis[v]=1; p[v]=u; dis[v]=t.dis+1; q.push((Node){v,dis[v]});
    }
  }
}
*/
