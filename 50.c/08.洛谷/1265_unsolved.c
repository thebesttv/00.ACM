/*
题目描述
某国有n个城市，它们互相之间没有公路相通，因此交通十分不便。为解决这一“行路难”的问题，政府决定修建公路。修建公路的任务由各城市共同完成。
修建工程分若干轮完成。在每一轮中，每个城市选择一个与它最近的城市，申请修建通往该城市的公路。政府负责审批这些申请以决定是否同意修建。
政府审批的规则如下：
  1.如果两个或以上城市申请修建同一条公路，则让它们共同修建；
  2.如果三个或以上的城市申请修建的公路成环。则政府将否决其中最短的一条公路的修建申请；
  3.其他情况的申请一律同意。
一轮修建结束后，可能会有若干城市可以通过公路直接或间接相连。这些可以互相：连通的城市即组成“城市联盟”。在下一轮修建中，每个“城市联盟”将被看作一个城市，发挥一个城市的作用。
当所有城市被组合成一个“城市联盟”时，修建工程也就完成了。
你的任务是根据城市的分布和前面讲到的规则，计算出将要修建的公路总长度。

输入输出格式
输入格式：
第一行一个整数n，表示城市的数量。(n≤5000)
以下n行，每行两个整数x和y，表示一个城市的坐标。(-1000000≤x，y≤1000000)

输出格式：
一个实数，保留两位小数，表示公路总长。（保证有惟一解）

输入输出样例
输入样例#1：
4
0 0
1 2
-1 2
0 4

输出样例#1：
6.47
*/

/*
  解题报告：
    本题其实就是求图的最小生成树。
    看三个规则：
      第一、三个其实没有意义，只需看第二个。
      对于第二个，设三点 A,B,C ，其对应申请修建的最短路分别为 AB,BC,CA，则可知：

              A
             / \
            B---C

        对于A，一定有 AB<=AC
        对于B，一定有 BC<=AB
        对于C，一定有 CA<=BC
        整理可得：AB>=AC && AB<=AC，那么AB=AC
        同理，最终得 AB=BC=CA
        那么无论删除的是哪条边，都依然是最小生成树。
    那么只需求最小生成树即可。
    但因为共有O(n^2)条边，为稠密图，Kruskal效果不好，要用Prim。
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

const int MAX=5020;
struct Edge{
  int u,v; double w;
  bool operator < (const Edge & b) const {return w<b.w;}
}edge[MAX*MAX];
int tail=0;
int n,p[MAX];
int pos[MAX][2];

int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d%d",&pos[i][0],&pos[i][1]);
  FOR(i,0,n) FOR(j,i+1,n){
    LL dx=pos[i][0]-pos[j][0];  //注意int溢出
    LL dy=pos[i][1]-pos[j][1];
    double dis=sqrt(dx*dx+dy*dy);
    edge[tail++]=(Edge){i,j,dis};
  }
  sort(edge,edge+tail);

  MST(p,-1);
  double ans=0; int cnt=0;
  FOR(i,0,tail){
    int px=find(edge[i].u),py=find(edge[i].v);
    if(px!=py) {ans+=edge[i].w; p[py]=px; cnt++;}
    if(cnt==n-1) break;
  }
  printf("%.2lf\n",ans);

  return 0;
}
