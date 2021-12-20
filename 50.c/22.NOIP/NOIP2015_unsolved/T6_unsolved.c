/*
描述
公元 2044 年，人类进入了宇宙纪元。L 国有 n 个星球，还有 n-1 条双向航道，每条航道建立在两个星球之间，这 n-1 条 航道连通了 L 国的所有星球。
小 P 掌管一家物流公司，该公司有很多个运输计划，每个运输计划形如：有一艘物 流飞船需要从 ui 号星球沿最快的宇航路径飞行到 vi 号星球去。显然，飞船驶过一条航道是需要时间的，对于航道 j，任意飞船驶过它所花费的时间为 tj，并且任意两艘飞船之间不会产生任何干扰。
为了鼓励科技创新，L 国国王同意小 P 的物流公司参与 L 国的航道建设，即允许小 P 把某一条航道改造成虫洞，飞船驶过虫洞不消耗时间。
在虫洞的建设完成前小 P 的物流公司就预接了 m 个运输计划。在虫洞建设完成后， 这 m 个运输计划会同时开始，所有飞船一起出发。当这 m 个运输计划都完成时，小 P 的物流公司的阶段性工作就完成了。
如果小 P 可以自由选择将哪一条航道改造成虫洞，试求出小 P 的物流公司完成阶段性工作所需要的最短时间是多少？

格式
输入格式
第一行包括两个正整数 n、m，表示 L 国中星球的数量及小 P 公司预接的运输计划的 数量，星球从 1 到 n 编号。
接下来 n-1 行描述航道的建设情况，其中第 i 行包含三个整数 ai, bi 和 ti ，表示第 i 条双向航道修建在 ai 与 bi 两个星球之间，任意飞船驶过它所花费的时间为 ti。
接下来 m 行描述运输计划的情况，其中第 j 行包含两个正整数 uj 和 vj，表示第 j 个 运输计划是从 uj 号星球飞往 vj 号星球。

输出格式
共 1 行，包含 1 个整数，表示小 P 的物流公司完成阶段性工作所需要的最短时间。

样例1
样例输入1
6 3
1 2 3
1 6 4
3 1 7
4 3 6
3 5 5
3 6
2 5
4 5

样例输出1
11

样例2（见最后）

限制
一共有20组数据。
其中n的取值依次为：
  100，100，100，2000，1000，2000，3000，1000，2000，3000，80000，100000，70000，80000，90000，100000，80000，90000，100000，300000。
其中m的取值依次为：
  1，100，100，1，1000，2000，3000，1000，2000，3000，1，1，70000，80000，90000，100000，80000，90000，100000，300000。
其中第2，5，6，7，13，14，15，16组数据满足：第 i 条航道连接 i 号星球与 i+1 号星球。

提示
输入输出样例 1 说明。
  将第 1 条航道改造成虫洞：则三个计划耗时分别为：11、12、11，故需要花费的时 间为 12。
  将第 2 条航道改造成虫洞：则三个计划耗时分别为：7、15、11，故需要花费的时 间为 15。
  将第 3 条航道改造成虫洞：则三个计划耗时分别为：4、8、11，故需要花费的时间 为 11。
  将第 4 条航道改造成虫洞：则三个计划耗时分别为：11、15、5，故需要花费的时 间为 15。
  将第 5 条航道改造成虫洞：则三个计划耗时分别为：11、10、6，故需要花费的时 间为 11。
  故将第 3 条或第 5 条航道改造成虫洞均可使得完成阶段性工作的耗时最短，需要花 费的时间为 11。

来源
NOIP 2015 提高组 Day 2 第三题
数据由AHdoc生成
*/

/*
  得分：10
  解题报告：
    完全不会树上的最短路。。
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

const int MAX=300020;
struct Node{
  int u,v;
  int tot;
  bool operator < (const Node & b) const {
    return tot>b.tot;
  }
}node[MAX];
int n,m,road[MAX],sum[MAX];

int get(){
  int tMax=0;
  FOR(i,0,m){
    int s = sum[node[i].v-1]-sum[node[i].u-1];
    tMax=max(tMax,s);
  }
  return tMax;
}

int main(void){
  scanf("%d%d",&n,&m);
  for(int i=1,u,v,t;i<n;i++){
    scanf("%d%d%d",&u,&v,&t);
    road[i]=t;
  }
  FOR(i,1,n) sum[i]=sum[i-1]+road[i];
#ifdef DEBUG
  printf("  sum:");
  FOR(i,1,n) printf(" %d",sum[i]);
  printf("\n");
#endif
  FOR(i,0,m){
    scanf("%d%d",&node[i].u,&node[i].v);
    node[i].tot = sum[node[i].v-1]-sum[node[i].u-1];
  }
  sort(node,node+m);
  int l=node[0].u,r=node[0].v;
  int ansMin=1<<30;
  FOR(i,l,r){
    int t=road[i]; road[i]=0;
    FOR(j,1,n) sum[j]=sum[j-1]+road[j];
    ansMin=min(ansMin,get());
    road[i]=t;
  }
  printf("%d\n",ansMin);

  return 0;
}

/*
样例输入2
50 100
1 2 784
2 3 311
2 4 781
1 5 499
5 6 511
2 7 355
4 8 534
8 9 418
4 10 806
6 11 710
5 12 382
9 13 144
2 14 774
8 15 674
3 16 827
10 17 440
8 18 357
6 19 183
9 20 930
1 21 600
10 22 727
2 23 496
11 24 263
2 25 932
9 26 799
2 27 115
2 28 402
3 29 777
29 30 653
5 31 160
7 32 910
28 33 698
8 34 665
12 35 342
4 36 509
9 37 38
24 38 501
1 39 873
16 40 406
5 41 83
9 42 248
33 43 651
19 44 834
5 45 567
15 46 200
45 47 981
10 48 813
47 49 423
49 50 404
31 37
41 17
8 22
19 11
35 37
1 49
18 41
22 37
10 41
32 23
4 4
48 35
31 36
30 50
27 29
41 39
42 24
42 46
37 28
41 42
50 7
38 49
21 43
49 50
29 29
19 37
29 10
27 40
16 9
12 38
42 38
28 1
27 45
17 46
9 6
23 3
47 35
39 5
50 49
7 13
16 28
50 37
18 44
27 35
29 11
49 36
28 48
33 41
37 28
16 30
18 50
45 10
24 22
31 15
48 2
18 46
26 42
36 6
8 28
50 30
38 19
28 21
1 42
16 41
25 45
48 36
25 26
33 47
34 1
8 49
34 8
42 48
29 40
40 40
41 7
34 15
33 29
1 45
34 14
12 35
22 25
9 5
11 16
50 18
16 24
29 19
9 10
27 20
49 9
33 42
7 5
6 15
43 17
2 9
45 10
26 37
27 3
39 36
18 15
44 17

样例输出2
4645
*/
