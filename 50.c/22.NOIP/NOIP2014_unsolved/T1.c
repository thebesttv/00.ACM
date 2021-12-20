/*
描述
石头剪刀布是常见的猜拳游戏：石头胜剪刀，剪刀胜布，布胜石头。如果两个人出拳一样，则不分胜负。在《生活大爆炸》第二季第 8 集中出现了一种石头剪刀布的升级版游戏。升级版游戏在传统的石头剪刀布游戏的基础上，增加了两个新手势：
斯波克：《星际迷航》主角之一。 蜥蜴人：《星际迷航》中的反面角色。
这五种手势的胜负关系如表一所示，表中列出的是甲对乙的游戏结果。

     B  剪刀  石头   布   蜥蜴人 斯波克
   A （图为A对B的结果，即A是赢、输还是平）
 剪刀    平    输    赢     赢     输 
 石头          平    输     赢     输
  布                 平     输     赢
蜥蜴人                      平     赢
斯波克                             平

现在，小 A 和小 B 尝试玩这种升级版的猜拳游戏。已知他们的出拳都是有周期性规律的，但周期长度不一定相等。例如：如果小 A 以“石头-布-石头-剪刀-蜥蜴人-斯波克”长度 为 6 的周期出拳，那么他的出拳序列就是“石头-布-石头-剪刀-蜥蜴人-斯波克-石头-布-石头-剪刀-蜥蜴人-斯波克-……”，而如果小 B 以“剪刀-石头-布-斯波克-蜥蜴人”长度为 5 的周 期出拳，那么他出拳的序列就是“剪刀-石头-布-斯波克-蜥蜴人-剪刀-石头-布-斯波克-蜥蜴人-……”
已知小 A 和小 B 一共进行 N 次猜拳。每一次赢的人得 1 分，输的得 0 分；平局两人都 得 0 分。现请你统计 N 次猜拳结束之后两人的得分。

格式
输入格式
第一行包含三个整数：N，NA，NB，分别表示共进行 N 次猜拳、小 A 出拳的周期长度， 小 B 出拳的周期长度。数与数之间以一个空格分隔。
第二行包含 NA 个整数，表示小 A 出拳的规律，第三行包含 NB 个整数，表示小 B 出拳 的规律。其中，0 表示“剪刀”，1 表示“石头”，2 表示“布”，3 表示“蜥蜴人”， 4 表示 “斯波克”。数与数之间以一个空格分隔。

输出格式
输出一行， 包含两个整数，以一个空格分隔，分别表示小 A、小 B 的得分。

样例1
样例输入1
10 5 6
0 1 2 3 4
0 3 4 2 1 0

样例输出1
6 2

样例2
样例输入2
9 5 5
0 1 2 3 4
1 0 3 2 4

样例输出2
4 4

限制
对于 100%的数据，0 < N ≤ 200，0 < NA ≤ 200， 0 < NB ≤ 200。

来源
NOIP2014 提高组 Day1
*/

/*
  得分：0(100)
  解题报告：
    只要搞懂图表，再枚举每次猜拳并分别对A、B计数即可。

    很无奈，虽然是道水题吧，然而我写了个get函数，然后就CE了。。。
    惨痛的教训啊。。。
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

const int MAX=220;
int a[MAX],b[MAX],ma,mb,n;
bool gget[5][5]={
  0,0,1,1,0,
  1,0,0,1,0,
  0,1,0,0,1,
  0,0,1,0,1,
  1,1,0,0,0
};

int main(void){
#ifdef DEBUG
  FOR(i,0,5){
    FOR(j,0,5) printf("%d ",gget[i][j]);
    printf("\n");
  }
#endif
  scanf("%d%d%d",&n,&ma,&mb);
  FOR(i,0,ma) scanf("%d",&a[i]);
  FOR(i,0,mb) scanf("%d",&b[i]);
  int sa=0,sb=0;
  FOR(i,0,n){
    int ta=a[i%ma],tb=b[i%mb];
    sa+=gget[ta][tb];
    sb+=gget[tb][ta];
  }
  printf("%d %d\n",sa,sb);

  return 0;
}
