/*
题目描述
在一个神奇的小镇上有着一个特别的电车网络，它由一些路口和轨道组成，每个路口都连接着若干个轨道，每个轨道都通向一个路口（不排除有的观光轨道转一圈后返回路口的可能）。在每个路口，都有一个开关决定着出去的轨道，每个开关都有一个默认的状态，每辆电车行驶到路口之后，只能从开关所指向的轨道出去，如果电车司机想走另一个轨道，他就必须下车切换开关的状态。
为了行驶向目标地点，电车司机不得不经常下车来切换开关，于是，他们想请你写一个程序，计算一辆从路口A到路口B最少需要下车切换几次开关。

输入输出格式
输入格式：
第一行有3个整数2<=N<=100，1<=A，B<=N，分别表示路口的数量，和电车的起点，终点。
接下来有N行，每行的开头有一个数字Ki(0<=Ki<=N-1)，表示这个路口与Ki条轨道相连，接下来有Ki个数字表示每条轨道所通向的路口，开关默认指向第一个数字表示的轨道。

输出格式：
输出文件只有一个数字，表示从A到B所需的最少的切换开关次数，若无法从A前往B，输出-1。

输入输出样例
输入样例#1：
3 2 1
2 2 3
2 3 1
2 1 2

输出样例#1：
0
*/

/*
  解题报告：
    就是一张图，每个路口i与其第一条轨道指向的路口j的G[i][j]为0，其余轨道指向的G[i][j']=1，（因为要改变一次开关），然后最短路即可。
    ps: 打错变量名实在伤不起。。。
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
const int INF=0x3f3f3f3f;
int n,s,t;
int G[MAX][MAX];

int main(void){
  scanf("%d%d%d",&n,&s,&t);
  MST(G,0x3f);
  FORR(i,1,n){
    int k,v; scanf("%d",&k);
    if(k) {scanf("%d",&v); G[i][v]=0;}
    //FOR(i,1,k) {scanf("%d",&v); G[i][v]=1;} //又是变量名弄错，无奈啊。。。
    FOR(j,1,k) {scanf("%d",&v); G[i][v]=1;}
  }
  FORR(i,1,n) G[i][i]=0;
  FORR(k,1,n) FORR(i,1,n) if(G[i][k]<INF) FORR(j,1,n) if(G[k][j]<INF)
    G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
  printf("%d\n",G[s][t]>=INF ? -1 : G[s][t]);

  return 0;
}
