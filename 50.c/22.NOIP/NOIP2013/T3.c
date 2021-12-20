/*
描述
A 国有 n 座城市，编号从 1 到 n，城市之间有 m 条双向道路。每一条道路对车辆都有重量限制，简称限重。现在有 q 辆货车在运输货物，司机们想知道每辆车在不超过车辆限重的情况下，最多能运多重的货物。

格式
输入格式
第一行有两个用一个空格隔开的整数 n，m，表示 A 国有 n 座城市和 m 条道路。
接下来 m 行每行 3 个整数 x、y、z，每两个整数之间用一个空格隔开，表示从 x 号城市到 y 号城市有一条限重为 z 的道路。注意：x 不等于 y，两座城市之间可能有多条道路。
接下来一行有一个整数 q，表示有 q 辆货车需要运货。
接下来 q 行，每行两个整数 x、y，之间用一个空格隔开，表示一辆货车需要从 x 城市运输货物到 y 城市，注意：x 不等于 y。

输出格式
输出共有 q 行，每行一个整数，表示对于每一辆货车，它的最大载重是多少。如果货车不能到达目的地，输出-1。

样例1
样例输入1
4 3 
1 2 4 
2 3 3 
3 1 1 
3
1 3 
1 4 
1 3

样例输出1
3
-1
3

限制
每个测试点1s。

提示
对于 30%的数据，0 < n < 1,000，0 < m < 10,000，0 < q < 1,000； 
对于 60%的数据，0 < n < 1,000，0 < m < 50,000，0 < q < 1,000； 
对于 100%的数据，0 < n < 10,000，0 < m < 50,000，0 < q < 30,000，0 ≤ z ≤ 100,000。

来源
NOIP 2013 提高组 Day 1
*/

/*
  得分：5（很无奈）
  解题报告：（考后）
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

const int MAX=1020;
const int INF=0x7fffffff;
int G[MAX][MAX];
vector<int> to[MAX];
int f[MAX][MAX];

int main(void){
  memset(G,-1,sizeof(G));
  int n,m; scanf("%d%d",&n,&m);
  int u,v,w;
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&u,&v,&w);
    G[u][v]=G[v][u]=max(G[u][v],w);
    to[u].push_back(v); to[v].push_back(u);
  }
  vector<int>::iterator it;
  memset(f,-1,sizeof(f));
  for(int i=1;i<=n;i++){
    int tMax=-1,u=0;
    for(it=to[i].begin();it!=to[i].end();it++){
      if(G[(*it)][i]>tMax) tMax=G[u=(*it)][i];
    }
    f[i][u]=f[u][i]=tMax;
    f[i][i]=INF;
  }

  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j){
    int  tMax=-1;
    for(it=to[j].begin();it!=to[j].end();it++) if(f[i][*it]!=-1)
      tMax=max(tMax,min(f[i][*it],G[*it][j]));
    f[i][j]=tMax;
  }
  int p,a,b; scanf("%d",&p);
  for(int i=0;i<p;i++){
    scanf("%d%d",&a,&b);
    printf("%d\n",f[a][b]);
  }

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

const int MAX=1020;
const int INF=0x7fffffff;
int G[MAX][MAX];
vector<int> to[MAX];
vector<int>::iterator it;
int f[MAX][MAX];
int n,m;

void solution1();
void solution2();

int main(void){
  memset(G,-1,sizeof(G));
  scanf("%d%d",&n,&m);
  if(n<MAX) solution1();
  else solution2();

  return 0;
}

void solution1(){
  int u,v,w;
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&u,&v,&w);
    G[u][v]=G[v][u]=max(G[u][v],w);
    to[u].push_back(v); to[v].push_back(u);
  }
  memset(f,-1,sizeof(f));
  for(int i=1;i<=n;i++){
    int tMax=-1,u=0;
    for(it=to[i].begin();it!=to[i].end();it++){
      if(G[(*it)][i]>tMax) tMax=G[u=(*it)][i];
    }
    f[i][u]=f[u][i]=tMax;
    f[i][i]=INF;
  }

  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j){
    int  tMax=-1;
    for(it=to[j].begin();it!=to[j].end();it++) if(f[i][*it]!=-1)
      tMax=max(tMax,min(f[i][*it],G[*it][j]));
    f[i][j]=tMax;
  }
  int p,a,b; scanf("%d",&p);
  for(int i=0;i<p;i++){
    scanf("%d%d",&a,&b);
    printf("%d\n",f[a][b]);
  }
}
void solution2(){
  map<int, map<int,int> > f,G;
  int u,v,w;
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&u,&v,&w);
    if(G[u].count(v)==0) G[u][v]=G[v][u]=w;
    else G[u][v]=G[v][u]=max(G[u][v],w);
    to[u].push_back(v); to[v].push_back(u);
  }
  for(int i=1;i<=n;i++){
    int tMax=-1,u=0,t;
    for(it=to[i].begin();it!=to[i].end();it++){
      if((t=G[(*it)][i])>tMax) tMax=t,u=(*it);
    }
    f[i][u]=f[u][i]=tMax;
    f[i][i]=INF;
  }
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j){
    int  tMax=-1;
    for(it=to[j].begin();it!=to[j].end();it++) if(f[i].count(*it))
      tMax=max(tMax,min(f[i][*it],G[*it][j]));
    if(tMax!=-1) f[i][j]=tMax;
  }
  int p,a,b; scanf("%d",&p);
  for(int i=0;i<p;i++){
    scanf("%d%d",&a,&b);
    if(f[a].count(b)) printf("%d\n",f[a][b]);
    else printf("%d\n",-1);
  }
}
*/
