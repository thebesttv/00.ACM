/*
题目描述
在 n*m 的网格上有一些点。在第 i 行第 j 列放置摄像头可以观察到所有满足 x=i,y≥j 或 x≥i,y=j 的点。求最少需要放多少个摄像头才能观察到所有给定的点，注意摄像头必须放在点上，且要保证任意一个摄像头均不能观察到另一个摄像头。保证输入中的点不会重复。

输入输出格式
输入格式：
第一行包含一个整数 T，表示数据组数。每组数据的格式如下：
第一行包含三个正整数 n,m,q，表示网格的大小和给定点的个数。
接下来 q 行，每行两个整数 xi,yi ，表示第 i 个点的坐标。

输出格式：
对每组数据输出一行，表示最少放置摄像头的点数，如果无解输出-1。

输入输出样例
输入样例#1：
1
2 4 4
1 1
2 1
2 3
2 4

输出样例#1：
2

说明
对于样例来说，只能在 (1,1) 点和 (2,3) 点上放置摄像头。
注意不能在 (2,1) 上放置摄像头，因为它不能观测到 (1,1) 点，而能观测到 (1,1) 点的摄像头必定同时观测到 (2,1) 点。
对于 20% 的数据，n,m≤10，q≤15；
对于 50% 的数据，n,m≤1000，q≤200；
对于 70% 的数据，n,m≤2000，q≤2000；
对于 100% 的数据，n,m≤10 
*/

/*
  得分：0
  解题报告：
    原来这么简单。。。
    首先，对于每个最左上角的点，一定要放置摄像头。而放置摄像头的，其能覆盖到的点一定不能再放置摄像头，那么答案也就是唯一的。
    也就可以推出，对于任意地图，都有一个合法的唯一解。
    那么，可以先将每个点按照<x,y>递增的顺序排列，然后遍历所有点，对每个点判断是否已被覆盖，如果没被覆盖则放置摄像头。
    判断点(x,y)是否被覆盖，<b>只需判断第x行和第y列是否被覆盖</b>，因为是按照点递增的顺序遍历的，而覆盖又是递增地覆盖的。
    复杂度：O(Tplogp)
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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register

const int MAX=100020;
int n,m,q;
struct Node{
  int x,y;
}node[MAX];
bool row[MAX],col[MAX];

bool com(Node & a, Node & b){
  return a.x==b.x ? a.y<b.y : a.x<b.x;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(row,0); MST(col,0);
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,0,q) scanf("%d%d",&node[i].x,&node[i].y);
    sort(node,node+q,com);

    int cnt=0;
    FOR(i,0,q){
      Node & t=node[i];
      if(row[t.x] || col[t.y]) continue;
      row[t.x]=col[t.y]=1; cnt++;
    }
    printf("%d\n",cnt);
  }

  return 0;
}
