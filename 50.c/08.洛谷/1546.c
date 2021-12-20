/*
题目背景
农民约翰被选为他们镇的镇长！他其中一个竞选承诺就是在镇上建立起互联网，并连接到所有的农场。当然，他需要你的帮助。

题目描述
约翰已经给他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。为了用最小的消费，他想铺设最短的光纤去连接所有的农场。
你将得到一份各农场之间连接费用的列表，你必须找出能连接所有农场并所用光纤最短的方案。每两个农场间的距离不会超过100000

输入输出格式
输入格式：
第一行： 农场的个数，N（3<=N<=100）。
第二行..结尾: 后来的行包含了一个N*N的矩阵,表示每个农场之间的距离。理论上，他们是N行，每行由N个用空格分隔的数组成，实际上，他们限制在80个字符，因此，某些行会紧接着另一些行。当然，对角线将会是0，因为不会有线路从第i个农场到它本身。

输出格式：
只有一个输出，其中包含连接到每个农场的光纤的最小长度。

输入输出样例
输入样例#1：
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0

输出样例#1：
28

说明
题目翻译来自NOCOW。
USACO Training Section 3.1
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

const int MAX=120;
int n;
struct Edge{
  int u,v,w;
  bool operator < (const Edge & b) const {return w<b.w;}
}edge[MAX*MAX];
int tail=0;
int p[MAX];

int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}

int main(void){
  MST(p,-1);
  scanf("%d",&n);
  FORR(i,1,n) FORR(j,1,n){
    int w; scanf("%d",&w);
    edge[tail++]=(Edge){i,j,w};
  }

  sort(edge,edge+tail);
  int cnt=0,ans=0;
  FOR(i,0,tail){
    Edge & e=edge[i];
    int px=find(e.u),py=find(e.v);
    if(px!=py) {ans+=e.w; p[px]=py; cnt++;}
    if(cnt==n-1) break;
  }
  printf("%d\n",ans);

  return 0;
}
