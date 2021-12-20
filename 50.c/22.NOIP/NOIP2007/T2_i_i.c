/*
描述
设T=(V, E, W) 是一个无圈且连通的无向图（也称为无根树），每条边到有正整数的权，我们称T为树网（treebetwork），其中V，E分别表示结点与边的集合，W表示各边长度的集合，并设T有n个结点。
路径：树网中任何两结点a，b都存在唯一的一条简单路径，用d(a, b)表示以a, b为端点的路径的长度，它是该路径上各边长度之和。我们称d(a, b)为a, b两结点间的距离。
  D(v, P)=min{d(v, u), u为路径P上的结点}。
树网的直径：树网中最长的路径成为树网的直径。对于给定的树网T，直径不一定是唯一的，但可以证明：各直径的中点（不一定恰好是某个结点，可能在某条边的内部）是唯一的，我们称该点为树网的中心。
偏心距ECC(F)：树网T中距路径F最远的结点到路径F的距离，即
  ECC(F)=max{d(v, F)，v∈ V}
任务：对于给定的树网T=(V, E, W)和非负整数s，求一个路径F，他是某直径上的一段路径（该路径两端均为树网中的结点），其长度不超过s（可以等于s），使偏心距ECC(F)最小。我们称这个路径为树网T=(V, E, W)的核（Core）。必要时，F可以退化为某个结点。一般来说，在上述定义下，核不一定只有一个，但最小偏心距是唯一的。
下面的图给出了树网的一个实例。图中，A-B与A-C是两条直径，长度均为20。点W是树网的中心，EF边的长度为5。如果指定s=11，则树网的核为路径DEFG（也可以取为路径DEF），偏心距为8。如果指定s=0（或s=1、s=2），则树网的核为结点F，偏心距为12。

                                         C 
                                        /  
                               +       /   
                                \     /  5 
                                 \3  /     
                                  \ /      
           1                       G-----+ 
          +-+                     /   3    
             \2                3 /         
              \       5         /          
               E--------W------F           
              /                |           
           3 /                 |4          
      4     /                  |           
 A---------D                   |           
           |                   +-----+     
           |                2 /   3        
           |3                /             
           |             1+-+-+1           
           +                |              
                            |2             
                            B              

格式
输入格式
包含n行：
第1行，两个正整数n和s，中间用一个空格隔开。其中n为树网结点的个数，s为树网的核的长度的上界。设结点编号以此为1，2，……，n。
从第2行到第n行，每行给出3个用空格隔开的正整数，依次表示每一条边的两个端点编号和长度。例如，“2 4 7”表示连接结点2与4的边的长度为7。
所给的数据都是正确的，不必检验。

输出格式
只有一个非负整数，为指定意义下的最小偏心距。

样例1
样例输入1
5 2
1 2 5
2 3 2
2 4 4
2 5 3

样例输出1
5

限制
1s

提示
40%的数据满足：5<=n<=15
70%的数据满足：5<=n<=80
100%的数据满足：5<=n<=300, 0<=s<=1000。边长度为不超过1000的正整数。
*/

//TODO: 写一个O(n)的算法

/*
  得分：90
  解题报告：
    说实话我也不知道为什么会这么高。。。
    一开始毫无头绪，思考了一会发现好像要求每个点的距离，于是启用最短路。一开始想到Floyd，但感觉太慢。后来想到Dijkstra，但准备实现的时候发现无法使用一次单源最短路求得每个点之间的距离，只能使用FLoyd（还是抄的）。
    然后想到使用动态规划，令 f(i,j) 表示由节点i到节点j组成的路径的ECC和相应的产生ECC的点u，得到：
      f(i,j) = min{f(x,j), d[i][u] | x,j直接相邻，u为造成f(x,j)ECC的点}
    但实现时发现转移方程时有误，因为：
      若u是路径(x,j)的最远点，u1为其次远点，而u1>d[i][u]，则真正的 f(i,j) 会大于求出的 f(i,j)
    因此又使用两个O(n)的循环，通过 i “左边”的点和 j “右边”的点对 f(i,j) 再次更新。
    但又感觉这么复杂不对，也不能证明其正确性，再加上考试时思维混乱，提交的时候感觉只能对几个点，但分数出奇地高，我也不知道为什么。。。
  正解：
  [1]O(n^3)
    先进行一次Floyd求点对点距离，然后枚举所有路径，对每条路径，再枚举所有点，用点到路径的距离更新ECC。
    在树中，由于其结构的特殊性，可以得到：
      点k到路径e=(i,j)的距离 D(k,e) = (d(k,i)+d(k,j)-d(i,j))/2
  [2]O(n)
*/

//O(n^3)
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=304;
const int INF=0x3f3f3f3f;
int d[MAX][MAX];

int main(void){
  memset(d,0x3f,sizeof(d));
  int n,s; scanf("%d%d",&n,&s);
  for(int i=1;i<=n;i++) d[i][i]=0;
  int x,y,w;
  for(int i=1;i<n;i++){
    scanf("%d%d%d",&x,&y,&w); d[x][y]=d[y][x]=w;
  }

  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        if(d[i][k]<INF && d[k][j]<INF)
          d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

  int ansMin=INF;
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(d[i][j]<=s){
    int tMax=0;
    for(int k=1;k<=n;k++) tMax=max(tMax, (d[k][i]+d[k][j]-d[i][j])/2);
    ansMin=min(ansMin,tMax);
  }
  printf("%d\n",ansMin);

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=304;
const int INF=0x3f3f3f3f;
bool G[MAX][MAX]; //直接相连的两点
int d[MAX][MAX],n,s;
struct Node{
  int ecc,u;

  bool operator < (int b) const {
    return ecc<b;
  }
}check[MAX][MAX];

Node f(int i, int j){ //XXX
  Node & a=check[i][j];
  if(a.ecc!=-1) return a;
  if(d[i][j]>s) a.ecc=INF;
  else if(i==j){
    for(int k=1;k<=n;k++) if(k!=i){
      d[i][k]>a.ecc ? a.ecc=d[i][k],a.u=k : 0 ;
    }
  }else{
    Node temp; a.ecc=INF;
    for(int k=1;k<=n;k++) if(G[i][k] && d[i][k]+d[k][j]==d[i][j]){
#ifdef DEBUG
      printf("    in f(%d,%d), using f(%d,%d)\n",i,j,k,j);
#endif
      temp=f(k,j);
      temp.ecc<a.ecc ? a.ecc=temp.ecc,a.u=temp.u : 0 ;
      d[i][temp.u]<a.ecc ? a.ecc=d[i][temp.u],a.u=temp.u : 0 ;
    }

    for(int k=1;k<=n;k++) if(d[j][k]<d[i][k] && d[i][k]+d[j][k]>d[i][j]){
      if(d[j][k]>a.ecc) a.ecc=d[j][k],a.u=k;
    }
    for(int k=1;k<=n;k++) if(d[i][k]<d[j][k] && d[i][k]+d[j][k]>d[i][j]){
      if(d[i][k]>a.ecc) a.ecc=d[i][k],a.u=k;
    }
  }
#ifdef DEBUG
  printf("  f(%d,%d) = {%d, %d}\n",i,j,a.ecc,a.u);
#endif

  return a;
}

int main(void){
  memset(d,0x3f,sizeof(d)); memset(check,-1,sizeof(check));
  scanf("%d%d",&n,&s);
  for(int i=1;i<=n;i++) d[i][i]=0;
  int x,y,w;
  for(int i=1;i<n;i++){
    scanf("%d%d%d",&x,&y,&w); d[x][y]=d[y][x]=w; G[x][y]=G[y][x]=1;
  }

  int tMin=INF;
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        if(d[i][k]<INF && d[k][j]<INF){  //??
          d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
          d[i][j]<tMin ? tMin=d[i][j] : 0 ;
        }

  int ansMin=INF;
  if(s>=tMin){
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(d[i][j]<=s)
      ansMin=min(ansMin,f(i,j).ecc);
  }else{
    for(int i=1;i<=n;i++) ansMin=min(ansMin,f(i,i).ecc);
  }

  printf("%d\n",ansMin);

  return 0;
}
*/
