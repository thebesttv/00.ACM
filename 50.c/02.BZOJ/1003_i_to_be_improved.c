/*
Description
物流公司要把一批货物从码头A运到码头B。由于货物量比较大，需要n天才能运完。货物运输过程中一般要转停好几个码头。物流公司通常会设计一条固定的运输路线，以便对整个运输过程实施严格的管理和跟踪。由于各种因素的存在，有的时候某个码头会无法装卸货物。这时候就必须修改运输路线，让货物能够按时到达目的地。但是修改路线是一件十分麻烦的事情，会带来额外的成本。因此物流公司希望能够订一个n天的运输计划，使得总成本尽可能地小。

Input
第一行是四个整数n（1<=n<=100）、m（1<=m<=20）、K和e。n表示货物运输所需天数，m表示码头总数，K表示每次修改运输路线所需成本。接下来e行每行是一条航线描述，包括了三个整数，依次表示航线连接的两个码头编号以及航线长度（>0）。其中码头A编号为1，码头B编号为m。单位长度的运输费用为1。航线是双向的。再接下来一行是一个整数d，后面的d行每行是三个整数P（ 1 < P < m）、a、b（1< = a < = b < = n）。表示编号为P的码头从第a天到第b天无法装卸货物（含头尾）。同一个码头有可能在多个时间段内不可用。但任何时间都存在至少一条从码头A到码头B的运输路线。

Output
包括了一个整数表示最小的总成本。总成本=n天运输路线长度之和+K*改变运输路线的次数。

Sample Input
5 5 10 8
1 2 1
1 3 3
1 4 2
2 3 2
2 4 4
3 4 1
3 5 2
4 5 2
4
2 2 3
3 1 1             
3 3 3
4 4 5

Sample Output
32

//前三天走1-4-5，后两天走1-3-5，这样总成本为(2+2)*3+(3+2)*2+10=32
*/

/*
  解题报告：
    一开始想到状压DP，令f(i,S)为前i天、当前使用码头集合为S时的最小花费，则
      f(i,S) = min{ f(i-1,T)+k, f(i-1,S) | T,S可行 }
    但最终还是T了。。。
  正解：（还是有点不懂）
    根据题目，一定有几段连续的时间会走一条相同的路。
    对于一段连续的时间[a,b]，走最短路、且不换航道一定是最优的，那么就令cost(i,J)为[i:j]的一直走最短路、不换航道的花费，如果不能从A到B，则cost(i,j)=INF。
    令 f(i) 为前i天的最小花费，则
      f(i) = min{ f(j) + cost(j+1,i) | cost(j+1,i)为[j+1:i]天的最小花费}
    即可得出答案。
TODO: 将Floyd改为Dijkstra或SPFA
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

const int MAXN=120;
const int MAXM=22;
const int INF=0x3f3f3f3f;
int n,m,k,e,d;
int ori[MAXM][MAXM],G[MAXM][MAXM],cost[MAXN][MAXN];
int f[MAXN];
bool ill[MAXN][MAXM],flag[MAXM];

void Floyd(){
  MST(cost,0x3f);
  FORR(a,1,n) FORR(b,a,n){  //from day a to day b
    MST(G,0x3f); MST(flag,0);
    FORR(j,1,m) FORR(i,a,b) if(ill[i][j]) {flag[j]=1; break;}
    FORR(i,1,m) if(!flag[i]) FORR(j,i,m) if(!flag[j])
      G[i][j]=G[j][i]=ori[i][j];

    FORR(k,1,m) FORR(i,1,m) if(G[i][k]<INF) FORR(j,1,m) if(G[k][j]<INF)
      G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

    if(G[1][m]<INF) cost[a][b]=G[1][m]*(b-a+1);
  }
}

int main(void){
  scanf("%d%d%d%d",&n,&m,&k,&e);
  MST(ori,0x3f); FORR(i,1,m) ori[i][i]=0;
  for(int i=0,u,v,w;i<e;i++){
    scanf("%d%d%d",&u,&v,&w);
    ori[u][v]=ori[v][u]=w;
  }
  scanf("%d",&d);
  for(int i=0,a,b,u;i<d;i++){
    scanf("%d%d%d",&u,&a,&b);
    FORR(j,a,b) ill[j][u]=1;
  }

  Floyd();

  MST(f,0x3f); f[0]=0;
  FORR(i,1,n){
    f[i]=cost[1][i];
    FOR(j,1,i){
      int t=cost[j+1][i];
      f[i]=min(f[i],f[j]+t+k);
    }
  }
  printf("%d\n",f[n]);

  return 0;
}

/*
const int MAX=22;
const int INF=0x3f3f3f3f;
int n,m,k,e,d;
int G[MAX][MAX],day,illS; //illS:对于每个day，不能使用的码头的集合
int f[1<<MAX],g[1<<MAX],mark[1<<MAX],ava[1<<MAX];
  //f[i][S]: 经过i天，当前使用码头集合为S，最小花费
  //-> f[S],g[S] 为滚动数组，g每次被f更新
bool ill[120][MAX];
struct Node{
  int S,w;
};
queue<Node> q;

void dfs(int cur, int w, int S){
  if(cur==m-1) {q.push((Node){S,w}); ava[S]=day; return;}

  FOR(i,1,m) if(!(S&(1<<i)) && G[cur][i] && !(illS&(1<<i))){
    dfs(i,w+G[cur][i],S|(1<<i));
  }
}

int main(void){
  scanf("%d%d%d%d",&n,&m,&k,&e);
  for(int i=0,u,v,t;i<e;i++){
    scanf("%d%d%d",&u,&v,&t);
    u--; v--;
    G[u][v]=G[v][u]=t;
  }
  scanf("%d",&d);
  for(int i=0,a,b,u;i<d;i++){
    scanf("%d%d%d",&u,&a,&b);
    u--;
    FORR(i,a,b) ill[i][u]=1;
  }
  for(day=1;day<=n;day++){
    illS=0;
    FOR(i,0,m) if(ill[day][i]) illS|=1<<i;

    dfs(0,0,1);
    while(!q.empty()){
      Node t=q.front(); q.pop();
      int S=t.S,w=t.w;;
      for(int i=1|(1<<(m-1));i<(1<<m);i+=2){
        if(mark[i]==day) g[i]=min(g[i],f[S] + w + (i!=S ? k : 0));
        else {g[i]=f[S] + w + (i!=S ? k : 0); mark[i]=day;}
      }
    }
    memcpy(f,g,SIZ(g));

#ifdef DEBUG
    printf("  day: %d\n",day);
    for(int i=1|(1<<(m-1));i<(1<<m);i+=2) if(f[i]<INF){
      printf("  f("); FOR(j,0,m) printf("%d",(i>>j)&1); printf("): %d\n",f[i]);
    }
#endif
  }

  int ansMin=1<<30;
  for(int i=1|(1<<(m-1));i<(1<<m);i+=2) if(mark[i]==m) ansMin=min(ansMin,f[i]);
  printf("%d\n",ansMin);

  return 0;
}
*/
