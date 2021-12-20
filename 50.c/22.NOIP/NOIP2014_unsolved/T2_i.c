/*
描述
无向连通图 G 有 n 个点，n-1 条边。点从 1 到 n 依次编号，编号为 i 的点的权值为 Wi， 每条边的长度均为 1。图上两点(u, v)的距离定义为 u 点到 v 点的最短距离。对于图 G 上的点对(u, v)，若它们的距离为 2，则它们之间会产生 Wu*Wv 的联合权值。
请问图 G 上所有可产生联合权值的__有序点对__中，联合权值最大的是多少？所有联合权值之和是多少？

格式
输入格式
第一行包含 1 个整数 n。
接下来 n-1 行，每行包含 2 个用空格隔开的正整数 u、v，表示编号为 u 和编号为 v 的点 之间有边相连。
最后 1 行，包含 n 个正整数，每两个正整数之间用一个空格隔开，其中第 i 个整数表示 图 G 上编号为 i 的点的权值为Wi。

输出格式
输出共 1 行，包含 2 个整数，之间用一个空格隔开，依次为图 G 上联合权值的最大值 和所有联合权值之和。由于所有联合权值之和可能很大，输出它时要对10007取余。

样例1
样例输入1
5
1 2
2 3
3 4
4 5
1 5 2 3 10

样例输出1
20 74

限制
对于30%的数据，1 < n ≤ 100；
对于60%的数据，1 < n ≤ 2000；
对于100%的数据，1 < n ≤ 200,000，0 < Wi ≤ 10,000。

提示

  1---2---3---4---5
  1   5   2   3   10

本例输入的图如上所示，距离为 2 的有序点对有(1,3)、(2,4)、(3,1)、(3,5)、(4,2)、(5,3)。 其联合权值分别为 2、15、2、20、15、20。其中最大的是 20，总和为 74。

来源
NOIP2014 提高组 Day1
*/

/*
  得分：70
  解题报告：
    一开始发现n个点、n-1条边，感觉是树，但也不敢确定，最后是分两种输入解题的，得分还算高吧。
    对于n<=100的数据，直接Floyd暴力即可。
    对于其他数据，直接假设是树，然后对每个节点，枚举距离它2的节点并计算。
    可以做一些小优化，即只统计(i,j),i<j的节点，然后答案乘2即可。
  正解：
    因为共有n个节点、n-1条边，G又是连通图（任意两点相互连通），那么G一定是树。
    就可直接枚举每个节点的子节点u,v，计算每组u,v的联合权值。
    但这样的复杂度为O(n^3)，太慢。
    考虑到对每个节点u，其所有子节点的联合权值sumu为
      sumu = w1*w2 + w1*w3 + w1*w4 + ... + w1*wn +
             w2*w1 + w2*w3 + w2*w4 + ... + w2*wn +
             w3*w1 + w3*w2 + w3*w4 + ... + w3*wn +
                             ...                 +
             wn*w1 + wn*w2 + wn*w3 + ... + wn*w(n-1)
           = sum{ wi*wj | i,j为子节点，且i!=j }
           = sum{ wi }^2 - w1^2 - w2^2 - w3^2 - ... - wn^2
    那么就只要用一层循环枚举节点u的子节点再进行计算即可。
    在此同时可以计算最大的联合权值，只需令max1为节点中最大的权值,max2为第二大的权值，那么节点u的子节点的最大权值即为max1*max2。
    因此复杂度即为O(n^2)
    注：不需要特判叶子节点，因为如果u为叶子节点，那么其只有一个“子节点”（父节点），那么sumu最终为0，max1=wv,max2=0，也为0。
        也无需担心重复计算。
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

const int MAX=200020;
const int MOD=10007;
VR<int> G[MAX];
int w[MAX];
int ansMax=0,sum=0,n;

int main(void){
  scanf("%d",&n);
  for(int i=1,u,v;i<n;i++){
    scanf("%d%d",&u,&v);
    G[u].push_back(v); G[v].push_back(u);
  }
  FORR(i,1,n) scanf("%d",&w[i]);

  FORR(i,1,n){
    int suma=0,sumb=0;
    int max1=0,max2=0;
    int siz=G[i].size();
    FOR(j,0,siz){
      int v=G[i][j];
      suma=(suma+w[v])%MOD;
      sumb=(sumb+(w[v]*w[v])%MOD)%MOD;
      if(w[v]>max1) {max2=max1; max1=w[v];}
      else if(w[v]>max2) max2=w[v];
    }
    sum=(sum+(suma*suma)%MOD-sumb+MOD)%MOD;
    ansMax=max(ansMax,max1*max2);
  }
  printf("%d %d\n",ansMax,sum);

  return 0;
}

/*
const int MAX=200020;
const int MOD=10007;
VR<int> edge[MAX];
int w[MAX];
int ansMax=0,sum=0,n;
int f[220][220];

void vio();
void imperfect(); //for tree  //terrible

int main(void){
  scanf("%d",&n);
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    edge[u].push_back(v); edge[v].push_back(u);
  }
  FORR(i,1,n) scanf("%d",&w[i]);
  //if(n<=200) vio();
  //else imperfect();
  imperfect();

  printf("%d %d\n",ansMax,sum);

  return 0;
}

void vio(){
  MST(f,0x3f);
  FORR(i,1,n) f[i][i]=0;
  FORR(i,1,n) ROR(j,edge[i].size()-1,0) f[i][edge[i][j]]=f[edge[i][j]][i]=1;
  FORR(i,1,n) FORR(j,1,n) FORR(k,1,n) //Floyd XXX
    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
#ifdef DEBUG
  FORR(i,1,n){
    printf(" ");
    FORR(j,1,n) printf(" %d",f[i][j]);
    printf("\n");
  }
#endif
  //FORR(i,1,n) FORR(j,1,n) if(f[i][j]==2){
  FORR(i,1,n) FOR(j,1,i) if(f[i][j]==2){
    int t=w[i]*w[j];
    sum=(sum+t)%MOD;
    ansMax=max(ansMax,t);
  }
  sum=(sum<<1)%MOD;
}
void imperfect(){ //for tree
  FORR(i,1,n) sort(edge[i].begin(),edge[i].end());
  FORR(i,1,n) ROR(j,edge[i].size()-1,0){  //for each i's child
    int u=i,tu=edge[i][j];
    int siz=edge[tu].size();
    FOR(k,0,siz){
    //ROR(k,edge[tu].size()-1,0){ //for it's child's child
      int v=edge[tu][k];
      if(v>i) break;
      if(u==v) continue;
      int t=w[u]*w[v];
      sum=(sum+t)%MOD;
      ansMax=max(ansMax,t);
    }
  }
  sum=(sum<<1)%MOD;
}
*/
