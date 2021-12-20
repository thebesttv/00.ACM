/*
题目背景
こんなにも、たくさんの幸せをあの人に分けてもらった
だから、きっと
今の、私は
谁が何と言おうと
世界一、幸せな女の子だ

题目描述
——“假如……我是说假如喔。万一我再过五天就会死，你能不能对我温柔一点？”
巨大的六号兽五天后将袭击浮游大陆。
无数次计算得到的残酷数据表明，只有圣剑瑟尼欧尼斯的适格精灵——珂朵莉·诺塔·瑟尼欧尼斯(Chtholly Nota Seniorious)开启妖精乡之门，才可以以生命为代价守住浮游岛。
“至少，我也希望自己不用消失，也想让别人记住。我也想留下羁绊啊。”
留给妖精少女珂朵莉的时间似乎已经不多了。
年轻的二等技官，妖精仓库的管理员，世界上最后一个人类——威廉·克梅修，数百年前曾经是一名准勇者，掌握着成为一名勇者所需要的所有知识。
大战在即，调整圣剑的状态成为了一项重要的任务。
  瑟尼欧里斯（セニオリス）
  圣剑的其中之一，在现存的遗迹兵装中，拥有最强大的力量。
  拥有非常特殊的资质，只有极少一部分的人才能使用。
  由四十一个护符组成。能将所有事物包含不死者都回归「死亡」。
  威廉需要调整圣剑的状态，因此他将瑟尼欧尼斯拆分护符，组成了一个n行m列的矩阵。
每一个护符都有自己的魔力值。现在为了测试圣剑，你需要将这些护符分成 A,B两部分。
要求如下：
圣剑的所有护符，恰好都属于两部分中的一部分。
每个部分内部的方块之间，可以通过上下左右相互到达，而且每个内部的方块之间互相到达，最多允许拐一次弯。
例如

ＡＡＡＡＡ　　ＡＡＡＡＡ　　ＡＡＡＡＡ
ＡＡＢＡＡ　　ＢａＡＡＡ　　ＡＡＡＢＢ
ＡＢＢＢＡ　　ＢＢＡＡＡ　　ＡＡＡＢＢ
ＡＡＢＡＡ　　ＢａＡＡＡ　　ＡＢＢＢＢ
ＡＡＡＡＡ　　ＡＡＡＡＡ　　ＢＢＢＢＢ
　　(1)　　　　　(2)　　　　　(3)　　　　　　

其中(1)(2)是不允许的分法，(3)是允许的分法。在(2)中，a属于A区域，这两个a元素之间互相到达，没有办法最多只拐一次弯。
现在要问，所有合法的分法中，A区域的极差与B区域的极差 中间较大的一个的 最小值 是多少？
好心而可爱的在一旁默默观察奈芙莲悄悄地告诉你，极差就是区域内最大值减去最小值。
夜晚的风吹拂着，68号岛上的景色竟与地上的森林无异。转念又想，黄金妖精本身就是与森林之中出现，成长，消亡的神秘存在啊。
时间不早了，早上训练中落败的珂朵莉即将回来了。您要尽快和威廉一起调整好圣剑，千万不能迟哟。

输入输出格式
输入格式：
第一行两个自然数n,m
接下来n行，每行m个自然数A[i][j]表示权值

输出格式：
一个整数表示答案。

输入输出样例
输入样例#1：
4 4
1 12 6 11
11 4 2 14
10 1 9 20
4 17 13 10

输出样例#1：
11

说明
样例解释

  1  12 6        11
  11 4  2        14
  10 1  9        20
  4        17 13 10

分法不唯一，如图是一种合法的分法。左边部分极差12-1=11，右边一块极差20-10=10，所以答案取这两个中较大者11。没有别的分法，可以使答案更小。

数据范围与约定
1-2, n,m<=10
3-4, n=1,m<=2000
5-7, n,m<=200
8-10, n,m<=2000
所有a[i][j]满足1<=a[i][j]<=10^9

《末日时在做什么？有没有空？可以来拯救吗？》
*/

/*
  得分：40
  解题报告：
    考试的时候感觉可以二分答案，但想不到怎么二分。又发现了A,B之间的分界线是单调的，然而只发现了这点，还是暴力。。。
  正解：
    可以发现，答案一定不大于max-min，那么完全可以将max和min放到A和B中。
    因为线的方向不容易确定也不容易枚举，可以只考虑一种方向，然后将矩阵旋转四次分别计算。
    二分答案k，对于max所在区间，max-a[i][j]<=k，对于min所在区间，a[i][j]-min<=k。
    可以贪心地求得区域A或B，然后验证另一个区域是否满足题意。
      即对于每行k，找到从左开始连续的一个区间，使得a[i][j]-min<=k，且区间尽量大。
      而对于之后的每个区间，其长度单调不递增。
      证明：若a[i][j]满足了当前区域，如果不取它，在另一个区域内它可能不合法，那么取了它一定比不取它好。
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

const int MAX=2020;
int n,m,a[MAX][MAX],tmp[MAX][MAX];
bool G[MAX][MAX];
int ansMin=1<<30;
int X1,Y1,X2,Y2;

void turn(){  //顺时针旋转90度
  MST(tmp,0);
  FOR(i,0,n) FOR(j,0,m){
    tmp[j][n-i-1]=a[i][j];
  }
  memcpy(a,tmp,SIZ(tmp));
  swap(n,m);  //<b> </b>
}
bool check(int k){
  MST(G,0);
  int last=m,tmin=a[X2][Y2],tmax=a[X1][Y1];
  FOR(i,0,n){
    int cnt=0;
    FOR(j,0,min(m,last))
      if(a[i][j]-tmin<=k) G[i][j]=1,cnt++;
      else break;
    last=cnt;
  }
  FOR(i,0,n) FOR(j,0,m) if(!G[i][j])
    if(tmax-a[i][j]>k) return false;
  return true;
}
void solve(){
  X1=0,Y1=0,X2=0,Y2=0;  //a[X1][Y1]: max, a[X2][Y2]: min
  FOR(i,0,n) FOR(j,0,m){
    if(a[i][j]>a[X1][Y1]) X1=i,Y1=j;
    else if(a[i][j]<a[X2][Y2]) X2=i,Y2=j;
  }
  int l=0,r=a[X1][Y1];
  while(l<r){
    int m=(l+r)>>1;
    if(check(m)) r=m;
    else l=m+1;
  }
  ansMin=min(ansMin,l);
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) FOR(j,0,m) scanf("%d",&a[i][j]);

  FOR(i,0,4){
    solve();
    turn();
  }
  printf("%d\n",ansMin);

  return 0;
}

/*
const int MAX=2020;
const int INF=0x7fffffff;
int n,m,a[MAX][MAX];
int lmin[MAX][MAX],lmax[MAX][MAX],rmin[MAX][MAX],rmax[MAX][MAX];
int rec[MAX],ansMin=INF;

int cal(){
  int lMin=INF,lMax=0,rMin=INF,rMax=0;
  FORR(i,1,n){
    lMin=min(lMin,lmin[i][rec[i]]);
    lMax=max(lMax,lmax[i][rec[i]]);
    rMin=min(rMin,rmin[i][rec[i]+1]);
    rMax=max(rMax,rmax[i][rec[i]+1]);
  }
  return max(0,max(lMax-lMin,rMax-rMin));
}

void dfsL(int x, int y){ //从(x,y)开始，走向其左下任意位置
  if(x==n+1){
    ansMin=min(ansMin,cal()); return;
  }
  rec[x]=y;
  FORR(i,0,m)
    if(y-i>=0) dfsL(x+1,y-i);
    else break;
  rec[x]=0;
}
void dfsR(int x, int y){ //从(x,y)开始，走向其右下任意位置
  if(x==n+1){
    ansMin=min(ansMin,cal()); return;
  }
  rec[x]=y;
  FORR(i,0,m)
    if(y+i<=m) dfsR(x+1,y+i);
    else break;
  rec[x]=0;
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) FORR(j,1,m) scanf("%d",&a[i][j]);
  
  //init
  FORR(i,1,n){
    lmin[i][0]=INF; lmax[i][0]=0;
    FORR(j,1,m){
      lmin[i][j]=min(lmin[i][j-1],a[i][j]);
      lmax[i][j]=max(lmax[i][j-1],a[i][j]);
    }
    lmin[i][m+1]=lmin[i][m]; lmax[i][m+1]=lmax[i][m+1];

    rmin[i][m+1]=INF; rmax[i][m+1]=0;
    ROR(j,m,1){
      rmin[i][j]=min(rmin[i][j+1],a[i][j]);
      rmax[i][j]=max(rmax[i][j+1],a[i][j]);
    }
    rmin[i][0]=rmin[i][1]; rmax[i][0]=rmax[i][1];
  }

  FORR(i,0,m) dfsL(1,i);
  FORR(i,2,n) dfsL(i,m);
  FORR(i,0,m) dfsL(n,i);

  FORR(i,0,m) dfsR(1,i);
  FORR(i,2,n) dfsR(i,0);
  FORR(i,0,m) dfsR(n,i);

  printf("%d\n",ansMin);
}
*/
