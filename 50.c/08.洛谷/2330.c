/*
题目描述
城市C是一个非常繁忙的大都市，城市中的道路十分的拥挤，于是市长决定对其中的道路进行改造。城市C的道路是这样分布的：城市中有n个交叉路口，有些交叉路口之间有道路相连，两个交叉路口之间最多有一条道路相连接。这些道路是双向的，且把所有的交叉路口直接或间接的连接起来了。每条道路都有一个分值，分值越小表示这个道路越繁忙，越需要进行改造。但是市政府的资金有限，市长希望进行改造的道路越少越好，于是他提出下面的要求：
1．改造的那些道路能够把所有的交叉路口直接或间接的连通起来。
2．在满足要求1的情况下，改造的道路尽量少。
3．在满足要求1、2的情况下，改造的那些道路中分值最大的道路分值尽量小。
任务：作为市规划局的你，应当作出最佳的决策，选择那些道路应当被修建。

输入输出格式
输入格式：
第一行有两个整数n,m表示城市有n个交叉路口，m条道路。接下来m行是对每条道路的描述，u, v, c表示交叉路口u和v之间有道路相连，分值为c。(1≤n≤300，1≤c≤10000，1≤m≤50000)

输出格式：
两个整数s, max，表示你选出了几条道路，分值最大的那条道路的分值是多少。

输入输出样例
输入样例#1：
4 5
1 2 3
1 4 5
2 4 7
2 3 6
3 4 8
输出样例#1：
3 60
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=50020;
int n,m,p[320];
struct Edge{
  int u,v,w;
  bool operator < (const Edge & b) const {return w<b.w;}
}edge[MAX];

int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,m) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
  sort(edge,edge+m);

  int cnt=0,ansMax=0; MST(p,-1);
  FOR(i,0,m){
    Edge & e=edge[i];
    int px=find(e.u),py=find(e.v);
    if(px==py) continue;
    ansMax=e.w; p[px]=py; cnt++;
    if(cnt==n-1) break;
  }
  printf("%d %d\n",n-1,ansMax);

  return 0;
}
