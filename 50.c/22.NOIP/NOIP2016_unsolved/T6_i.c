/*
描述
Kiana最近沉迷于一款神奇的游戏无法自拔。
简单来说，这款游戏是在一个平面上进行的。
有一架弹弓位于(0, 0)处，每次Kiana可以用它向第一象限发射一只红色的小鸟，小鸟们的飞行轨迹均为形如y = ax^2+ bx的曲线，其中a, b是Kiana指定的参数，且必须满足a < 0。
当小鸟落回地面（即x轴）时，它就会瞬间消失。
在游戏的某个关卡里，平面的第一象限中有n只绿色的小猪，其中第i只小猪所在的坐标为(xi, yi)。
如果某只小鸟的飞行轨迹经过了(xi, yi)，那么第i只小猪就会被消灭掉，同时小鸟将会沿着原先的轨迹继续飞行；
如果一只小鸟的飞行轨迹没有经过(xi, yi)，那么这只小鸟飞行的全过程就不会对第i只小猪产生任何影响。
例如，若两只小猪分别位于(1,3)和(3,3)，Kiana可以选择发射一只飞行轨迹为 y = -x^2 + 4x的小鸟，这样两只小猪就会被这只小鸟一起消灭。
而这个游戏的目的，就是通过发射小鸟消灭所有的小猪。
这款神奇游戏的每个关卡对Kiana来说都很难，所以Kiana还输入了一些神秘的指令，使得自己能更轻松地完成这个游戏。这些指令将在【输入格式】中详述。
假设这款游戏一共有T个关卡，现在Kiana想知道，对于每一个关卡，至少需要发射多少只小鸟才能消灭所有的小猪。由于她不会算，所以希望由你告诉她。

格式
输入格式
第一行包含一个正整数T，表示游戏的关卡总数。
下面依次输入这T个关卡的信息。每个关卡第一行包含两个非负整数n,m，分别 表示该关卡中的小猪数量和Kiana输入的神秘指令类型。接下来的n行中，第i行包含 两个正实数xi, yi，表示第i只小猪坐标为(xi, yi)。数据保证同一个关卡中不存在两只坐标完全相同的小猪。
如果m = 0，表示Kiana输入了一个没有任何作用的指令。
如果m = 1，则这个关卡将会满足：至多用⌈n/3 + 1⌉只小鸟即可消灭所有小猪。 
如果m = 2，则这个关卡将会满足：一定存在一种最优解，其中有一只小鸟消灭了至少⌊n/3⌋只小猪。
保证1<=n<=18，0<=m<=2，0<xi, yi<10，输入中的实数均保留到小数点后两位。
上文中，符号⌈c⌉和⌊c⌋分别表示对c向上取整和向下取整，例如：⌈2.1⌉ = ⌈2.9⌉ = ⌈3.0⌉ = ⌊3.0⌋ = ⌊3.1⌋ = ⌊3.9⌋ = 3。

输出格式
对每个关卡依次输出一行答案。
输出的每一行包含一个正整数，表示相应的关卡中，消灭所有小猪最少需要的小鸟数量。

样例1
样例输入1
2
2 0
1.00 3.00
3.00 3.00
5 2
1.00 5.00
2.00 8.00
3.00 9.00
4.00 8.00
5.00 5.00

样例输出1
1
1

样例2
样例输入2
3
2 0
1.41 2.00
1.73 3.00
3 0
1.11 1.41
2.34 1.79
2.98 1.49
5 0
2.72 2.72
2.72 3.14
3.14 2.72
3.14 3.14
5.00 5.00

样例输出2
2
2
3

样例3
样例输入3
1
10 0
7.16 6.28
2.02 0.38
8.33 7.78
7.68 2.09
7.46 7.86
5.77 7.44
8.24 6.72
4.42 5.11
5.42 7.79
8.15 4.99

样例输出3
6

限制
每个测试点时限2秒。

子任务
数据的一些特殊规定如下表：

  测试点   n   m   T
     1     2   0  10
     2     2   0  30
     3     3   0  10
     4     3   0  30
     5     4   0  10
     6     4   0  30
     7     5   0  10
     8     6   0  10
     9     7   0  10
    10     8   0  10
    11     9   0  30
    12    10   0  30
    13    12   1  30
    14    12   2  30
    15    15   0  15
    16    15   1  15
    17    15   2  15
    18    18   0   5
    19    18   1   5
    20    18   2   5

提示
样例1说明
这组数据中一共有两个关卡。
第一个关卡与【问题描述】中的情形相同，2只小猪分别位于(1.00, 3.00)和 (3.00, 3.00)，只需发射一只飞行轨迹为y = -x^2 + 4x的小鸟即可消灭它们。
第二个关卡中有5只小猪，但经过观察我们可以发现它们的坐标都在抛物线 y = -x^2 + 6x上，故Kiana只需要发射一只小鸟即可消灭所有小猪。

来源
NOIP 2016 提高组 Day 2 第三题
*/

/*
  得分：5
  解题报告：
    一开始只想到搜索，还在dfs的参数上放了个S集合，愣是没想到动规。
    然而不知道dfs哪里写炸了，一堆WA，最后就对了一个点5分。。。
  正解：
    状压DP，令 f(S) 表示还剩下的猪为集合S时所需的最小的鸟的个数，则
      f(S) = min{ f(Ti)+1 | Ti为考虑到抛物线i时S中还剩下的猪的集合 }, cnt(S)>=2
             1, cnt(S)=1
    抛物线可以使用结构体存储，在DP前先初始化所有的抛物线，方法是：
      枚举枚举两只猪i,j(i<j)的位置，计算a,b
      并且在计算完成后令S表示该抛物线能消灭的猪的集合，方便以后计算
      最后将抛物线存放在set中，防止重复
    这样一来，转移方程即可写为：
      f(S)=cnt(S);
      if(cnt(S)>=2) FOR(i,0,v.size()) if(S&v[i].S{
        f(S) = min( f(S), f(S^(S&v[i].S))+1 );
      }
    这样即可得到答案，不过好像题目里的m对于DP并没有什么用。。。
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

const int MAX=1<<20;
const double EPS=1e-6;
const int INF=0x3f3f3f3f;
int n,m,siz;
int check[MAX];
struct Pig{
  double x,y;
}pig[20];
struct Node{
  double a,b;
  int S;
  bool operator < (const Node & b) const {
    return fabs(a-b.a)<EPS ? this->b<b.b : a<b.a;
  }
};
set<Node> st;//VR<Node> v;
set<Node>::iterator it;
Node v[18*18];

int f(int S){
  int & a=check[S];
  if(a!=-1) return a;
  int cnt=0; FOR(i,0,n) if((S>>i)&1) cnt++;
  a=cnt;
  if(cnt>=2){
    FOR(i,0,siz) if(v[i].S&S){
      a=min(a,f(S^(S&v[i].S))+1);
    }
  }
#ifdef DEBUG
  printf("  f("); FOR(i,0,n) printf("%d",(S>>i)&1); printf("): %d\n",a);
#endif
  return a;
}
void get_ab(int n0, int n1, double & a, double & b);
int cal(double a, double b);

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    st.clear(); MST(check,-1); check[0]=0; MST(v,0);
    scanf("%d%d",&n,&m);
    FOR(i,0,n) scanf("%lf%lf",&pig[i].x,&pig[i].y);
    FOR(i,0,n) FOR(j,i+1,n){
      double a,b; get_ab(i,j,a,b);
      if(a>=0) continue;
      Node t; t.a=a; t.b=b; t.S=cal(a,b);
#ifdef DEBUG
      printf("  a: %lf, b: %lf, S:",a,b); FOR(i,0,n) printf("%d",(t.S>>i)&1); printf("\n");
#endif
      st.insert(t);
    }
    //for(it=st.begin();it!=st.end();it++) v.push_back(*it);
    //siz=v.size();
    siz=0;
    for(it=st.begin();it!=st.end();it++) v[siz++]=*it;

    printf("%d\n",f((1<<n)-1));
  }

  return 0;
}

void get_ab(int n0, int n1, double & a, double & b){
  double x0=pig[n0].x,y0=pig[n0].y;
  double x1=pig[n1].x,y1=pig[n1].y;
  a = (x0*y1-x1*y0)/(x1*x0*(x1-x0));
  b = y0/x0 - a*x0;
}
int cal(double a, double b){
  int S=0;
  FOR(i,0,n){
    double x=pig[i].x, y=pig[i].y;
    if(fabs(x*(a*x+b)-y)<EPS) S|=1<<i;
  }
  return S;
}

/*
const int MAX=20;
const double EPS=1e-8;
struct Node{
  double x,y;
}node[MAX];
struct Node2{
  double a,b;
  int cnt,S;
  bool operator < (const Node2 & b) const{
    return cnt>b.cnt;
  }
}node2[MAX][MAX];
int n,m;
int ansMin;

void get_ab(int n0, int n1, double & a, double & b);
int cal(double a, double b);
void dfs(int step, int S);

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    if(m==1) ansMin=ceil(n/3.0+1);
    else ansMin=n;
    FOR(i,0,n) scanf("%lf%lf",&node[i].x,&node[i].y);
    FOR(i,0,n) FOR(j,i+1,n){
    //FOR(i,0,n) FOR(j,0,n){
      double a,b; get_ab(i,j,a,b);
      if(a>=0) continue;
      Node2 & tn=node2[i][j];
      tn.a=a; tn.b=b; tn.S=cal(a,b);
      memcpy(&node2[j][i],&node2[i][j],SIZ(Node2));
#ifdef DEBUG
      printf("  for (%.2lf,%.2lf) (%.2lf,%.2lf), get a: %lf, b: %lf, S:",node[i].x,node[i].y,node[j].x,node[j].y,a,b);
      FOR(i,0,n) printf("%d",(tn.S>>i)&1);
      printf("\n");
#endif
    }

    dfs(0,(1<<n)-1);
    printf("%d\n",ansMin);
  }

  return 0;
}

void dfs(int step, int S){
#ifdef DEBUG
  printf("  dfs(%d,%d)\n",step,S);
#endif
  if(step>=ansMin) return;
  if(!S) {ansMin=step; return;}

  int cnt=0; FOR(i,0,n) if((S>>i)&1) cnt++;
  ansMin=min(ansMin,step+cnt);
  if(cnt<2) return;

  VR<Node2> v;
  FOR(i,0,n) if((S>>i)&1) FOR(j,i+1,n) if((S>>j)&1 && node2[i][j].S){
    Node2 & tn=node2[i][j];
    int tS=S&tn.S;
    int cnt=0; FOR(k,0,n) if((tS>>k)&1) cnt++;
    v.push_back((Node2){tn.a,tn.b,cnt,tS});
  }
  sort(v.begin(),v.end());
  int siz=v.size();
  if(!siz) return;
  FOR(k,0,siz){
    int tS=S&(~v[k].S);
    dfs(step+1,tS);
  }
}
void get_ab(int n0, int n1, double & a, double & b){
  double x0=node[n0].x,y0=node[n0].y;
  double x1=node[n1].x,y1=node[n1].y;
  a = (x0*y1-x1*y0)/(x1*x0*(x1-x0));
  b = y0/x0 - a*x0;
}
int cal(double a, double b){
  int S=0;
  FOR(i,0,n){
    double x=node[i].x,y=node[i].y;
    if(fabs(x*(a*x+b)-y)<EPS) S|=1<<i;
  }
  return S;
}
*/
