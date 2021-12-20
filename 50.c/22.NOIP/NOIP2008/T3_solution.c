/*
   先用双线动规写一遍，下午再来写费用流解法= =

   解法1：双线动规

   首先我们不难看出，由于纸条回来时不能与去时的路径重叠，“一来一回”和“从左上角分两条路走向右下角”这两个模型是等价的。于是我们可以把两条路到达的端点同时作为状态保存下来(dp[x1][y1][x2][y2])。又因为矩阵图的特殊性，左上角到右下角的所有路径长度均为两点的曼哈顿距离，我们可以让两点”同时“移动，即任何时刻两点走过的路程相同。这样，我们可以记当前状态为dp[i, j, k]，其中 i 表示当前两点走到的横纵坐标之和，j表示第一条路径走到的横坐标，k表示第二条路径走到的横坐标。考虑到两条路径在途中不能重叠，我们约定j > k。其中每个位置最多都可以由两个点达到，那么每种状态最多要考虑2*2=4种前驱。这里要考虑一种特殊情况：当k == j-1时，两点都可以由(k, i-k-1)这一点走到，然而题目中规定路径中不能有重叠，那么这时我们应当排除”两点从同一点转移得到“的情况╮(╯▽╰)╭

   这样，这道题就完美解决了→_→时间复杂度为O((M+N)MN）

   p.s.截至发表前，这个解法在河南省实验中学COGS上排到了速度rank1→_→ (5ms)

 */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cmath>
#define maxn (52)
using namespace std;
#ifdef DEBUG
FILE *in = fopen("test","r");
#define out stdout
#else
FILE *in = fopen("message.in","r");
FILE *out = fopen("message.out","w");
#endif

inline void getint(int &k){
  char c = fgetc(in);
  while(!isdigit(c))c = fgetc(in);
  k = c - '0';
  while(isdigit(c = fgetc(in)))
    k = k * 10 + (c - '0');
}
int m, n;
int Mat[maxn][maxn];//坐标从1开始
int dp[maxn<<1][maxn][maxn] = {0};
int main(){
  int i, j, k, Max, t;
  getint(m),getint(n);
  for(i = 1;i <= m;++i) for(j = 1;j <= n;++j)getint(Mat[i][j]);
  dp[3][2][1] = Mat[2][1] + Mat[1][2];
  for(i = 4;i < m+n;++i)
    for(j = 2;j <= m;++j){
      if(j == i)break;
      for(k = max(1,i-n);k < j;++k){
        Max = dp[i-1][j][k];
        if((t=dp[i-1][j][k-1]) > Max)Max = t;
        if((t=dp[i-1][j-1][k-1]) > Max)Max = t;
        if(k!=j-1 && (t=dp[i-1][j-1][k])>Max)Max = t;
        dp[i][j][k] = Max + Mat[j][i-j] + Mat[k][i-k];
      }
    }
  i = m + n - 1;
  fprintf(out,"%d\n",dp[i][m][m-1]);
  return 0;
}

/*
   解法2：最大费用最大流

   好吧现在已经是第二天了……感觉费用流写起来很费时间啊QAQ……

   这道题的建模思路是这样的……将每个学生抽象成一条有向边，纸条抽象为流量，好心值抽象为费用，考虑以下两点限制条件：1.最多为2的流量流经(1,1)和(m,n)两学生；2.中间每个学生对应的容量为1(每个学生只会传一次纸条)；3.在相邻的两个学生中，从偏左、偏上的学生对应边的终点向另一学生对应边的起点连边，容量为1，费用为0；4.源点为(1,1）学生的起点，汇点为(m,n）学生的终点。

   对这样一个有向网络建图，求出最大费用最大流，即为原问题的解。由于问题的特殊性，spfa运行次数接近常数，因此这一算法的时间复杂度接近最短路。（然而，对于这样小的网格，费用流的解法其实有些浪费……）STL容器的时间常数似乎有点大，这个解法在COGS上花了9毫秒（而且是打开了-O2优化……醉了醉了）

 */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
#include <ctime>
#define Vect vector<edge*>
#define pb push_back
#define iter(v) v::iterator
#define bg begin()
#define maxn (52)
#define maxv (5002)
using namespace std;

#if defined DEBUG
FILE *in = fopen("test","r");
#define out stdout
#else
FILE *in = fopen("message.in","r");
FILE *out = fopen("message.out","w");
#endif

inline void getint(int &k){
  char c = fgetc(in);
  while(!isdigit(c))c = fgetc(in);
  k = c - '0';
  while(isdigit(c = fgetc(in)))
    k = k * 10 + (c - '0');
}

struct edge{
  int w, vol, to;
  edge(){}
  edge(int W, int V, int T):w(W),vol(V),to(T){}
}E[maxv*6];
int preE[maxv];
int Ecnt = 0;
Vect adj[maxv];
int m, n, Vnum = 2, preV[maxv], ans = 0;
inline void addE(int &Ecnt, int f, int t, int w, int v){
  E[Ecnt] = edge(w,v,t);
  adj[f].pb(E + Ecnt++);
  E[Ecnt] = edge(-w,0,f);
  adj[t].pb(E + Ecnt++);
}

inline void init(){
  int i, j, w;
  getint(w);
  addE(Ecnt, 0, 1, w, 2);
  for(i = 1;i < n; ++i){
    getint(w);
    addE(Ecnt, Vnum-1, Vnum, 0, 1);
    addE(Ecnt, Vnum, Vnum+1, w, 1);
    Vnum += 2;
  }
  for(i = 1;i < m-1; ++i){
    getint(w);
    addE(Ecnt, Vnum-(n<<1)+1, Vnum, 0, 1);
    addE(Ecnt, Vnum, Vnum+1, w, 1);
    Vnum += 2;
    for(j = 1;j < n; ++j){
      getint(w);
      addE(Ecnt, Vnum-1, Vnum, 0, 1);
      addE(Ecnt, Vnum-(n<<1)+1, Vnum, 0, 1);
      addE(Ecnt, Vnum, Vnum+1, w, 1);
      Vnum += 2;
    }
  }
  getint(w);
  addE(Ecnt, Vnum-(n<<1)+1, Vnum, 0, 1);
  addE(Ecnt, Vnum, Vnum+1, w, 1);
  Vnum += 2;
  for(j = 1;j < n; ++j){
    getint(w);
    addE(Ecnt, Vnum-1, Vnum, 0, 1);
    addE(Ecnt, Vnum-(n<<1)+1, Vnum, 0, 1);
    if(j < n-1)addE(Ecnt, Vnum, Vnum+1, w, 1);
    else addE(Ecnt, Vnum, Vnum+1, 0, 2);
    Vnum += 2;
  }
}
bool spfa(int &d){
  int dis[maxv] = {0}, tmp, t;
  bool inq[maxv] = {0}, known[maxv] = {1};
  queue<int> Q;
  iter(Vect) it;
  inq[0] = 1, Q.push(0);
  while(!Q.empty()){
    tmp = Q.front(), Q.pop(), inq[tmp] = 0;
    it = adj[tmp].begin();
    for(;it != adj[tmp].end();++it){
      if((*it)->vol <= 0)continue;
      t = dis[tmp] + (*it)->w;
      if(t < 0)continue;
      if(!known[(*it)->to] || t > dis[(*it)->to]){
        dis[(*it)->to] = t;
        known[(*it)->to] = 1;
        preE[(*it)->to] = *it - E;
        preV[(*it)->to] = tmp;
        if(!inq[(*it)->to])inq[(*it)->to] = 1, Q.push((*it)->to);
      }
    }
  }
  d = dis[Vnum-1];
  if(known[Vnum-1])return 1;
  else return 0;
}
inline void aug(int &dis){
  int k = Vnum - 1;
  ans += dis;
  while(k != 0){
    E[preE[k]].vol -= 1;        
    E[preE[k]^1].vol += 1;
    k = preV[k];
  }
  dis = 0;
}
int main(){
  getint(m),getint(n);
  init();
  int dis = 0;
  while(spfa(dis))
    aug(dis);
  fprintf(out,"%d\n",ans);
#if defined DEBUG
  cout << (double)clock() / CLOCKS_PER_SEC;
#endif
  return 0;
}









//--------------------------------------------------------------
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=150;
int a[maxn][maxn],f[maxn][maxn][maxn];
int Main();
int Max(int,int,int,int);
int start=Main();
int Main(){
  freopen("message.in","r",stdin);
  freopen("message.out","w",stdout);
  int m,n;scanf("%d%d",&m,&n);
  for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
  for(int k=1;k<m+n-2;k++){
    for(int i=1;i<=m;i++){
      for(int j=1;j<=m;j++){
        if(i==j)continue;
        f[k][i][j]=Max(f[k-1][i][j],f[k-1][i-1][j],f[k-1][i-1][j-1],f[k-1][i][j-1])+a[i][k+2-i]+a[j][k+2-j];
      }
    }
  }
  int ans=0;
  ans=max(f[m+n-3][m-1][m],f[m+n-3][m][m-1]);
  printf("%d",ans);
  return 0;
}
int Max(int a,int b,int c,int d){
  int x=max(a,b);
  int y=max(x,c);
  int z=max(y,d);
  return z;
}
int main(){;}


