/*
描述
风景迷人的小城Y市，拥有n个美丽的景点。由于慕名而来的游客越来越多，Y市特意安排了一辆观光公交车，为游客提供更便捷的交通服务。观光公交车在第0分钟出现在1号景点，随后依次前往2、3、4……n号景点。从第i号景点开到第i+1号景点需要Di分钟。任意时刻，公交车只能往前开，或在景点处等待。
设共有m个游客，每位游客需要乘车1次从一个景点到达另一个景点，第i位游客在Ti分钟来到景点Ai，希望乘车前往景点Bi（Ai<Bi）。为了使所有乘客都能顺利到达目的地，公交车在每站都必须等待需要从该景点出发的所有乘客都上车后才能出发开往下一景点。假设乘客上下车不需要时间。
一个乘客的旅行时间，等于他到达目的地的时刻减去他来到出发地的时刻。因为只有一辆观光车，有时候还要停下来等其他乘客，乘客们纷纷抱怨旅行时间太长了。于是聪明的司机ZZ给公交车安装了k个氮气加速器，每使用一个加速器，可以使其中一个Di减1。对于同一个Di可以重复使用加速器，但是必须保证使用后Di大于等于0。
那么ZZ该如何安排使用加速器，才能使所有乘客的旅行时间总和最小？

格式
输入格式
第1行是3个整数n, m, k，每两个整数之间用一个空格隔开。分别表示景点数、乘客数和氮气加速器个数。
第2行是n-1个整数，每两个整数之间用一个空格隔开，第i个数表示从第i个景点开往第i+1个景点所需要的时间，即Di。
第3行至m+2行每行3个整数Ti, Ai, Bi，每两个整数之间用一个空格隔开。第i+2行表示第i位乘客来到出发景点的时刻，出发的景点编号和到达的景点编号。

输出格式
共一行，包含一个整数，表示最小的总旅行时间。

样例1
样例输入1
3 3 2
1 4
0 1 3
1 1 2
5 2 3

样例输出1
10

限制
1s

样例说明：
对D2使用2个加速器，从2号景点到3号景点时间变为2分钟。
公交车在第1分钟从1号景点出发，第2分钟到达2号景点，第5分钟从2号景点出发，第7分钟到达3号景点。
第1个旅客旅行时间7 - 0 = 7分钟；
第2个旅客旅行时间2 - 1 = 1分钟；
第3个旅客旅行时间7 - 5 = 2分钟。
总时间7 + 1 + 2 = 10分钟。

数据范围：
对于10%的数据，k = 0；
对于20%的数据，k = 1；
对于40%的数据，2 ≤ n ≤ 50，1 ≤ m ≤ 1,000，0 ≤ k ≤ 20，0 ≤ Di ≤ 10，0 ≤ Ti ≤ 500；
对于60%的数据，1 ≤ n ≤ 100，1 ≤ m ≤ 1,000，0 ≤ k ≤ 100，0 ≤ Di ≤ 100，0 ≤ Ti ≤ 10,000；
对于100%的数据，1 ≤ n ≤ 1,000，1 ≤ m ≤ 10,000，0 ≤ k ≤ 100,000，0 ≤ Di ≤ 100，0 ≤ Ti ≤ 100,000。

来源
NOIp2011提高组Day2第三题
*/

/*
  得分：10
  解题报告：（考后）
    没想到是贪心。。。可是动规也不至于就对10分吧。。。
    想到：要使某个加速器获得当前状态下最大的效益，就要在能影响人最多的路段使用。
    如果在第i条路使用的加速器，那么到下一站的每个人的旅行时间一定减小了1。但汽车可能要在下一站等待上车的人，而他们上车的时间是固定的。也就是说车上其余的人的旅行时间实质上没有缩短。而如果汽车不要等待，那么到第i+2站的人的旅行时间一定减小了1，其余不定……
    因此，如果第i条路上使用加速器，其贡献取决于汽车到达第i+1个车站的时间和最晚的上车时间。
    用g(i)表示第i条路上使用加速器，其能贡献到的最远的车站号，得：
      g(i) = g(i+1), 汽车无需等待，即t[i+1]>maxUp[i+1]
             i+1, 汽车需要等待，即t[i+1]<=maxUp[i+1]
      边界条件为 g(n-1)=n
    这样，就可以得到每次贡献最大的路段。
    然后，只需将使用了i-1个加速器得到的时间减去 第i+1个车站到第g(i)个车站上下车的所有人之和*1（可使用前缀和求出），即为使用了第i个加速器所得到的最优时间。
    当然，使用了一个加速器后，有可能对之后的汽车到达时间产生影响，因此要更新t数组，而t数组又会影响g，因此也要更新g。
    至此，就可以解答了。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int maxUp[1020];  //maxUp[i]: 在第i个站点最晚上车的时间
int t[1020];      //t[i]: 到达第i个站点的时间
int road[1020];   //road[i]: 在第i条路上行驶时间
int sum[1020];    //sum[i]: 在[1:i]个站点下车的总人数
int g[1020];      //g[i]: 若在第i条路使用加速器，其能影响到的站点号
int n,m,k;
vector<int> down[1020];  //up[i], down[i]: 在第i个站点上下的人
int uptime[10020]; //uptime[i]: 每个人的上车时刻

int main(void){
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<n;i++) scanf("%d",&road[i]);
  int tup,tdown,ttime;
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&ttime,&tup,&tdown);
    sum[tdown]++; uptime[i]=ttime;
    maxUp[tup]=max(maxUp[tup],ttime);
    down[tdown].push_back(i);
  }
  for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
  for(int i=1;i<=n;i++) t[i]=max(maxUp[i],t[i-1]+road[i-1]);

  int ans=0;
  vector<int>::iterator it;
  for(int i=1;i<=n;i++) for(it=down[i].begin();it!=down[i].end();it++)  //计算原始时间
    ans+=t[i-1]+road[i-1]-uptime[*it];  //<b></b>
  for(int i=0;i<k;i++){
    for(int j=1;j<=n;j++) t[j]=max(maxUp[j],t[j-1]+road[j-1]);  //更新t数组
    int tMax=sum[n]-sum[n-1],u=n-1;
    g[n-1]=n;
    for(int j=n-2;j>0;j--){  //更新g数组
      g[j]=(t[j+1]<=maxUp[j+1] ? j+1 : g[j+1]);
      if(sum[g[j]]-sum[j]>tMax && road[j]>0){ //<b></b>
        tMax=sum[g[j]]-sum[j]; u=j;
      }
    }
    ans-=tMax;
    road[u]--;
  }
  printf("%d\n",ans);

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int INF=0x7fffffff;
int f[100020];  //f[i][j]: 在第1到第i条路上，共使用j个加速器，得到的最小等待时间
int road[1020]; //road[i]: 第i条路上要开多少分钟
int t[1020];    //t[i]: 在第i条路上车内有多少人（通过差分得到）
int n,m,k;
vector<int> up[1020],down[1020];  //up[i], down[i]: 第i个景点上车和下车的人
int maxUp[1020];  //第i个景点最晚上车的人的上车时刻
int uptime[10020];  //每个人开始等待上车的时刻

void init();  //计算f[0][0]

int main(void){
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<n;i++) scanf("%d",&road[i]);
  int tup,tdown;
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&uptime[i],&tup,&tdown);
    maxUp[tup]=max(maxUp[tup],uptime[i]);
    up[tup].push_back(i); down[tdown].push_back(i);
    t[tup]++; t[tdown]--;
  }
  int delta=0;
  for(int i=1;i<n;i++){
    delta+=t[i]; t[i]=delta;
  }

  for(int i=0;i<100020;i++) f[i]=INF;
  init();
#ifdef DEBUG
  printf("  t:"); for(int i=1;i<n;i++) printf(" %d",t[i]); printf("\n");
  printf("  f[0]: %d\n",f[0]);
#endif
  for(int i=1;i<n;i++){
    for(int j=k;j>0;j--){
      for(int tk=min(road[i],j);tk>0;tk--)
        f[j]=min(f[j],f[j-tk]-tk*t[i]);
#ifdef DEBUG
      printf("  f(%d,%d): %d\n",i,j,f[j]);
#endif
    }
  }
  int ansMin=INF;
  for(int i=0;i<=k;i++) ansMin=min(ansMin,f[i]);
  printf("%d\n",ansMin);

  return 0;
}

void init(){  //计算f[0][0]
  int sum=0,cur=0;
  vector<int>::iterator it;
  for(int i=1;i<=n;i++){
    for(it=down[i].begin();it!=down[i].end();it++) sum+=cur-uptime[*it];
    cur=max(cur,maxUp[i]);
    cur+=road[i];
  }
  f[0]=sum;
}
*/
