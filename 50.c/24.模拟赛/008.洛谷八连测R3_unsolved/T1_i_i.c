/*
题目背景
浮游大陆的68号岛，位于浮游大陆的边境地带。平时很少有人造访。
岛上被浓厚的森林覆盖。
在这座边境地区不起眼的浮游岛上，建立着神秘的”兵器“管理仓库——妖精仓库。

题目描述
妖精仓库里生活着黄金妖精们，她们过着快乐，却随时准备着迎接死亡的生活。
换用更高尚的说法，是随时准备着为这个无药可救的世界献身。
然而孩子们的生活却总是无忧无虑的，幼体的黄金妖精们过着天真烂漫的生活，自然也无暇考虑什么拯救世界之类的重任。
有一天小妖精们又在做游戏。这个游戏是这样的。
妖精仓库的储物点可以看做在一个数轴上。每一个储物点会有一些东西，同时他们之间存在距离。
每次他们会选出一个小妖精，然后剩下的人找到区间[l,r]储物点的所有东西，清点完毕之后问她，把这个区间内所有储物点的东西运到另外一个仓库的代价是多少？
比如储物点i有x个东西，要运到储物点j，代价为 x * dist(i,j)， dist就是仓库间的距离。
当然啦，由于小妖精们不会算很大的数字，因此您的答案需要对19260817取模。

输入输出格式
输入格式：
第一行两个数表示n,m
第二行n-1个数，第i个数ai表示第i个储物点与第i+1个储物点的距离
第三行n个数，表示每个储物点的东西个数
之后m行每行三个数 x l r, 表示查询要把区间[l,r]储物点的物品全部运到储物点x的花费

输出格式：
对于每个询问输出一个数表示答案

输入输出样例
输入样例#1：
5 5
2 3 4 5
1 2 3 4 5
1 1 5
3 1 5
2 3 3
3 3 3
1 5 5

输出样例#1：
125
72
9
0
70

说明
对于30%的数据，n,m<=1000
对于另外20%的数据，所有储物点间的距离都为1
对于另外20%的数据，所有储物点的物品数都为1
对于100%的数据, n,m<=200000, ai,x<=2*10^9
*/

/*
  得分：100
  解题报告：
    ans = sum{ dis(i,x) * ai | l<=i<=r }
        = sum{ |pos[i]-pos[x]| * ai | l<=i<=r }
    可以根据x与l,r的关系分三种情况讨论：
    1. x<l，即 pi>px
      ans = sum{pi*ai} - px*sum{ai}
    2. x>r，即 pi<px
      ans = px*sum{ai} - sum{pi*ai}
    3. l<=x<=r，即 p[i:x-1]<px<p[x+1:r]
      ans = ( px*sum{ai} - sum{pi*ai} | l<=i<x ) + ( sum{pi*ai}-px*sum{ai} | x<i<=r )
    然后只需使用两个前缀和即可。
    但一定要注意溢出问题（就因为溢出，花了一个小时才把这道题写完）。
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

typedef long long LL;
const int MOD=19260817;
const int MAX=200020;

int n,m;
LL a[MAX],p[MAX];
LL s1[MAX],s2[MAX];  //s1: sum{ai*pi}, s2: sum{ai}

int main(void){
  scanf("%d%d",&n,&m);
  p[1]=1;
  for(int i=2,t;i<=n;i++){
    scanf("%d",&t); p[i]=(p[i-1]+t)%MOD;  //<b></b>
  }
  FORR(i,1,n) scanf("%lld",&a[i]);
  FORR(i,1,n){
    s1[i]=(s1[i-1]+p[i]*a[i])%MOD;
    s2[i]=(s2[i-1]+a[i])%MOD;
  }

  int x,l,r,ans;
  FOR(i,0,m){
    scanf("%d%d%d",&x,&l,&r);
    if(x<l){
      //ans = ((s1[r]-s1[l-1]+MOD)%MOD - p[x]*(s2[r]-s2[l-1]))%MOD;
      int t1 = (s1[r]-s1[l-1]+MOD)%MOD;
      int t2 = (s2[r]-s2[l-1]+MOD)%MOD; t2 = (p[x]*t2)%MOD;
      ans = (t1-t2+MOD)%MOD;
    }else if(x>r){
      //ans = (p[x]*(s2[r]-s2[l-1]) - (s1[r]-s1[l-1]))%MOD;
      int t1 = (s2[r]-s2[l-1]+MOD)%MOD; t1 = (p[x]*t1)%MOD;
      int t2 = (s1[r]-s1[l-1]+MOD)%MOD;
      ans = (t1-t2+MOD)%MOD;
    }else{
      //ans = (p[x]*(s2[x-1]-s2[l-1])%MOD - (s1[x-1]-s1[l-1]) + s1[r]-s1[x] - p[x]*(s2[r]-s2[x])%MOD)%MOD;
      int t1 = (s2[x-1]-s2[l-1]+MOD)%MOD; t1 = (p[x]*t1)%MOD;
      int t2 = (s1[x-1]-s1[l-1]+MOD)%MOD;
      int t3 = (s1[r]-s1[x]+MOD)%MOD;
      int t4 = (s2[r]-s2[x]+MOD)%MOD; t4 = (p[x]*t4)%MOD;
      ans = ((t1-t2+MOD)%MOD + (t3-t4+MOD)%MOD)%MOD;
    }
    printf("%d\n",ans);
  }

  return 0;
}
