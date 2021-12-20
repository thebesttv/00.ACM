/*
描述
金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间金明自己专用的很宽敞的房间。更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过N元钱就行”。今天一早，金明就开始做预算了，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：
  主件    附件
  电脑    打印机，扫描仪
  书柜    图书
  书桌    台灯，文具
  工作椅  无
如果要买归类为附件的物品，必须先买该附件所属的主件。每个主件可以有0个、1个或2个附件。附件不再有从属于自己的附件。金明想买的东西很多，肯定会超过妈妈限定的N元。于是，他把每件物品规定了一个重要度，分为5等：用整数1~5表示，第5等最重要。他还从因特网上查到了每件物品的价格（都是10元的整数倍）。他希望在不超过N元（可以等于N元）的前提下，使每件物品的价格与重要度的乘积的总和最大。
设第j件物品的价格为v[j]，重要度为w[j]，共选中了k件物品，编号依次为j1，j2，……，jk，则所求的总和为：v[j1]*w[j1]+v[j2]*w[j2]+ …+v[jk]*w[jk]。（其中*为乘号）请你帮助金明设计一个满足要求的购物单。

格式
输入格式
输入文件的第1行，为两个正整数，用一个空格隔开：
N m
其中N（<32000）表示总钱数，m（<60）为希望购买物品的个数。）
从第2行到第m+1行，第j行给出了编号为j-1的物品的基本数据，每行有3个非负整数
v p q
（其中v表示该物品的价格（v<10000），p表示该物品的重要度（1~5），q表示该物品是主件还是附件。如果q=0，表示该物品为主件，如果q>0，表示该物品为附件，q是所属主件的编号）

输出格式
输出文件只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（<200000）。

样例1
样例输入1
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0

样例输出1
2200

限制
1s

来源
NOIP2006第二题
*/

/*
  得分：70
  解题报告：
    分组背包。将每个主件和其附件分为一个物品组，每个选择了一个主件和若干个附件的策略对应其中一个物品。
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX=60;
//int f[MAX][32000];
int f[32020];
int n,m;
bool isSub[MAX];
int sub[MAX][2];
struct Ind{
  int v,w;
}ori[MAX];
struct Group{
  int num;
  Ind ind[4];
}group[MAX];

void init_group(int & tail);

int main(void){
  scanf("%d%d",&n,&m);
  int q;
  for(int i=1;i<=m;i++){
    scanf("%d%d%d",&ori[i].v,&ori[i].w,&q);
    if(q){
      isSub[i]=1; sub[q][ !sub[q][0] ? 0 : 1 ]=i;
    }
  }
  int tail=1;
  init_group(tail);

  for(int i=1;i<tail;i++){
    for(int j=n;j>=0;j--){
      for(int k=0;k<group[i].num;k++) if(j>=group[i].ind[k].v){
        f[j]=max(f[j], f[j-group[i].ind[k].v]+group[i].ind[k].w);
      }
    }
  }

  /*
  for(int i=1;i<tail;i++){
    for(int j=n;j>=0;j--){
      for(int k=0;k<=group[i].num;k++) if(j>=group[i].ind[k].v){
        f[i][j]=max(f[i][j], f[i-1][j-group[i].ind[k].v]+group[i].ind[k].w);
      }
    }
  }
  */

  int ansMax=0;
  //for(int i=0;i<n;i++) ansMax=max(ansMax,f[tail-1][i]);
  for(int i=0;i<=n;i++) ansMax=max(ansMax,f[i]);  //少了个等于，错了3个点
  printf("%d\n",ansMax);

  return 0;
}

void init_group(int & tail){
  for(int i=1;i<=m;i++) if(!isSub[i]){
    int num = (sub[i][0]!=0) + (sub[i][1]!=0);
    if(num==0){
      group[tail].num=1;
      group[tail].ind[0].v=ori[i].v;
      group[tail].ind[0].w=ori[i].v*ori[i].w;
    }else if(num==1){
      int s1=sub[i][0];
      group[tail].num=2;
      group[tail].ind[0].v=ori[i].v;
      group[tail].ind[0].w=ori[i].v*ori[i].w;
      group[tail].ind[1].v=ori[i].v+ori[s1].v;
      group[tail].ind[1].w=ori[i].v*ori[i].w + ori[s1].v*ori[s1].w;
    }else if(num==2){
      int s1=sub[i][0],s2=sub[i][1];
      group[tail].num=4;
      group[tail].ind[0].v=ori[i].v;
      group[tail].ind[0].w=ori[i].v*ori[i].w;
      group[tail].ind[1].v=ori[i].v+ori[s1].v;
      group[tail].ind[1].w=ori[i].v*ori[i].w + ori[s1].v*ori[s1].w;
      group[tail].ind[2].v=ori[i].v+ori[s2].v;
      group[tail].ind[2].w=ori[i].v*ori[i].w + ori[s2].v*ori[s2].w;
      group[tail].ind[3].v=ori[i].v+ori[s1].v+ori[s2].v;
      group[tail].ind[3].w=ori[i].v*ori[i].w + ori[s1].v*ori[s1].w + ori[s2].v*ori[s2].w;
    }
    tail++;
  }
}
