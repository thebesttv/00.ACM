/*
题目描述
金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间金明自己专用的很宽敞的房间。更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过N元钱就行”。今天一早，金明就开始做预算了，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：

  主件 附件
  电脑 打印机，扫描仪
  书柜 图书
  书桌 台灯，文具
  工作椅 无

如果要买归类为附件的物品，必须先买该附件所属的主件。每个主件可以有0个、1个或2个附件。附件不再有从属于自己的附件。金明想买的东西很多，肯定会超过妈妈限定的N元。于是，他把每件物品规定了一个重要度，分为5等：用整数1~5表示，第5等最重要。他还从因特网上查到了每件物品的价格（都是10元的整数倍）。他希望在不超过N元（可以等于N元）的前提下，使每件物品的价格与重要度的乘积的总和最大。
设第j件物品的价格为v[j]，重要度为w[j]，共选中了k件物品，编号依次为j1，j2，……，jk，则所求的总和为：
v[j1]*w[j1]+v[j2]*w[j2]+ …+v[jk]*w[jk]。（其中*为乘号）
请你帮助金明设计一个满足要求的购物单。

输入输出格式
输入格式：
输入的第1行，为两个正整数，用一个空格隔开：
N m （其中N（<32000）表示总钱数，m（<60）为希望购买物品的个数。）
从第2行到第m+1行，第j行给出了编号为j-1的物品的基本数据，每行有3个非负整数
v p q （其中v表示该物品的价格（v<10000），p表示该物品的重要度（1~5），q表示该物品是主件还是附件。如果q=0，表示该物品为主件，如果q>0，表示该物品为附件，q是所属主件的编号）

输出格式：
输出只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（<200000）。

输入输出样例
输入样例#1：
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0

输出样例#1：
2200

说明
NOIP 2006 提高组 第二题
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct Node{
  int v,tot;
  Node(): v(0), tot(0) { }
  Node(int v_, int tot_): v(v_), tot(tot_) { }
};
struct Group{
  Node ind[4];  //由主件和附件组成的新物品
  int n;
};
vector<Node> obj[80];
vector<Group> group;
int f[32020];

void make_group(int m);

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  int v,p,q;
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&v,&p,&q);
    Node t(v,p*v);
    if(!q) obj[i].push_back(t);
    else obj[q-1].push_back(t);
  }
  make_group(m);
#ifdef DEBUG
  for(int i=0;i<m;i++){
    if(obj[i].size()){
      printf("obj %d:",i);
      for(int j=0;j<obj[i].size();j++) printf(" %d %d,",obj[i][j].v,obj[i][j].tot);
      printf("\n");
    }
  }
  for(int i=0;i<group.size();i++){
    printf("  Group %d:\n",i);
    for(int j=0;j<group[i].n;j++)
      printf("  %d %d\n",group[i].ind[j].v,group[i].ind[j].tot);
  }
#endif

  for(int i=0;i<group.size();i++){
    for(int j=n;j>=0;j--){
      Group & g=group[i]; //组
      for(int k=0;k<g.n;k++){
        Node & a = g.ind[k];  //组中的物品
        if(j>=a.v) f[j]=max(f[j],f[j-a.v]+a.tot);
      }
    }
  }
  printf("%d\n",f[n]);

  return 0;
}

void make_group(int m){
  for(int i=0;i<m;i++){
    int size=obj[i].size();
    if(!size) continue;
    Group tg; Node t;
    vector<Node> & v=obj[i];
    if(size==1){  //只有一个主件
      tg.ind[0]=v[0];
      tg.n=1;
    }else if(size==2){  //一个主件 + 一个附件
      tg.ind[0]=v[0];

      t.v=v[0].v+v[1].v;
      t.tot=v[0].tot + v[1].tot;
      tg.ind[1]=t;

      tg.n=2;
    }else if(size==3){  //一个主件 + 两个附件
      tg.ind[0]=v[0];

      t.v=v[0].v+v[1].v;
      t.tot=v[0].tot + v[1].tot;
      tg.ind[1]=t;

      t.v=v[0].v+v[2].v;
      t.tot=v[0].tot + v[2].tot;
      tg.ind[2]=t;

      t.v=v[0].v + v[1].v + v[2].v;
      t.tot=v[0].tot + v[1].tot + v[2].tot;
      tg.ind[3]=t;
      tg.n=4;
    }
    group.push_back(tg);
  }
}
