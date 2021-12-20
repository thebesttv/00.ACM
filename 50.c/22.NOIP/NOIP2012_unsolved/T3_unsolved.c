/*
描述
小A和小B决定利用假期外出旅行，他们将想去的城市从1到N编号，且编号较小的城市在编号较大的城市的西边，已知各个城市的海拔高度互不相同，记城市i 的海拔高度为Hi，城市i 和城市j 之间的距离d[i,j]恰好是这两个城市海拔高度之差的绝对值，即d[i,j] = |Hi - Hj|。
旅行过程中，小A和小B轮流开车，第一天小A开车，之后每天轮换一次。他们计划选择一个城市S作为起点，一直向东行驶，并且最多行驶X公里就结束旅行。小A和小B的驾驶风格不同，小B总是沿着前进方向选择一个最近的城市作为目的地，而小A总是沿着前进方向选择第二近的城市作为目的地（注意：本题中如果当前城市到两个城市的距离相同，则认为离海拔低的那个城市更近）。如果其中任何一人无法按照自己的原则选择目的城市，或者到达目的地会使行驶的总距离超出X公里，他们就会结束旅行。 
在启程之前，小A想知道两个问题： 
1．对于一个给定的X=X0，从哪一个城市出发，小A开车行驶的路程总数与小B行驶的路程总数的比值最小（如果小B的行驶路程为0，此时的比值可视为无穷大，且两个无穷大视为相等）。如果从多个城市出发，小A开车行驶的路程总数与小B行驶的路程总数的比值都最小，则输出海拔最高的那个城市。 
2. 对任意给定的X=Xi 和出发城市Si，小A开车行驶的路程总数以及小B行驶的路程总数。

格式
输入格式
第一行包含一个整数N，表示城市的数目。 
第二行有N个整数，每两个整数之间用一个空格隔开，依次表示城市1到城市N的海拔高度，即H1，H2，……，Hn，且每个Hi 都是不同的。 
第三行包含一个整数X0。 
第四行为一个整数M，表示给定M组Si和Xi。 
接下来的M行，每行包含2个整数Si 和Xi，表示从城市Si 出发，最多行驶Xi 公里。

输出格式
输出共M+1行。 
第一行包含一个整数S0，表示对于给定的X0，从编号为S0的城市出发，小A开车行驶
的路程总数与小B行驶的路程总数的比值最小。 
接下来的M行，每行包含2个整数，之间用一个空格隔开，依次表示在给定的Si 和Xi 下小A行驶的里程总数和小B行驶的里程总数。

样例1
样例输入1
4 
2 3 1 4 
3 
4 
1 3 
2 3 
3 3 
4 3

样例输出1
1 
1 1 
2 0 
0 0 
0 0

样例2
样例输入2
10 
4 5 6 1 2 3 7 8 9 10 
7 
10 
1 7 
2 7 
3 7 
4 7 
5 7 
6 7 
7 7 
8 7 
9 7 
10 7  

样例输出2
2 
3 2 
2 4 
2 1 
2 4 
5 1 
5 1 
2 1 
2 0 
0 0 
0 0 

样例说明
样例1
如果从城市 1 出发，可以到达的城市为 2,3,4，这几个城市与城市 1 的距离分别为 1,1,2，但是由于城市 3 的海拔高度低于城市 2，所以我们认为城市 3 离城市 1 最近，城市 2 离城市 1 第二近，所以小 A 会走到城市 2。到达城市 2 后，前面可以到达的城市为 3,4，这两个城市与城市 2 的距离分别为 2,1，所以城市 4 离城市 2 最近，因此小 B 会走到城市 4。到达城市 4 后，前面已没有可到达的城市，所以旅行结束。
如果从城市 2 出发，可以到达的城市为 3,4，这两个城市与城市 2 的距离分别为 2,1，由于城市 3 离城市 2 第二近，所以小 A 会走到城市 3。到达城市 3 后，前面尚未旅行的城市为 4，所以城市 4 离城市 3 最近，但是如果要到达城市 4，则总路程为 2+3=5>3，所以小 B 会直接在城市 3 结束旅行。
如果从城市 3 出发，可以到达的城市为 4，由于没有离城市 3 第二近的城市，因此旅行还未开始就结束了。
如果从城市 4 出发，没有可以到达的城市，因此旅行还未开始就结束了。

样例2
当 X=7 时，如果从城市 1 出发，则路线为 1 -> 2 -> 3 -> 8 -> 9，小 A 走的距离为 1+2=3，小 B 走的距离为 1+1=2。（在城市 1 时，距离小 A 最近的城市是 2 和 6，但是城市 2 的海拔更高，视为与城市 1 第二近的城市，所以小 A 最终选择城市 2；走到 9 后，小 A 只有城市 10 可以走，没有第 2 选择可以选，所以没法做出选择，结束旅行）
如果从城市 2 出发，则路线为 2 -> 6 -> 7 ，小 A 和小 B 走的距离分别为 2，4。
如果从城市 3 出发，则路线为 3 -> 8 -> 9，小 A 和小 B 走的距离分别为 2，1。
如果从城市 4 出发，则路线为 4 -> 6 -> 7，小 A 和小 B 走的距离分别为 2，4。
如果从城市 5 出发，则路线为 5 -> 7 -> 8 ，小 A 和小 B 走的距离分别为 5，1。
如果从城市 6 出发，则路线为 6 -> 8 -> 9，小 A 和小 B 走的距离分别为 5，1。
如果从城市 7 出发，则路线为 7 -> 9 -> 10，小 A 和小 B 走的距离分别为 2，1。
如果从城市 8 出发，则路线为 8 -> 10，小 A 和小 B 走的距离分别为 2，0。
如果从城市 9 出发，则路线为 9，小 A 和小 B 走的距离分别为 0，0（旅行一开始就结束了）。
如果从城市 10 出发，则路线为 10，小 A 和小 B 走的距离分别为 0，0。
从城市 2 或者城市 4 出发小 A 行驶的路程总数与小 B 行驶的路程总数的比值都最小，但是城市 2 的海拔更高，所以输出第一行为 2。

限制
每个测试点1s

数据范围
对于30%的数据，有1≤N≤20，1≤M≤20； 
对于40%的数据，有1≤N≤100，1≤M≤100； 
对于50%的数据，有1≤N≤100，1≤M≤1,000；
对于70%的数据，有1≤N≤1,000，1≤M≤10,000； 
对于100%的数据，有1≤N≤100,000，1≤M≤10,000，-1,000,000,000≤Hi≤1,000,000,000，0≤X0≤1,000,000,000，1≤Si≤N，0≤Xi≤1,000,000,000，数据保证Hi 互不相同。

来源
Noip2012提高组复赛Day1T3
*/

/*
  得分：25
  解题报告：
    很无奈，第一问没有用double判断，直接丢了55分，诶。。。

  正解：
*/

//TODO: 修改init函数，改为链表或平衡树
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;
const int MAX=100020;
const int INF=0x7fffffff;
const double EPS=1e-6;
struct Node{
  int h,num;
  
  bool operator < (const Node & b) const {
    return h<b.h;
  }
}node[MAX];
int h[MAX],n;
int check_f[MAX][17]; LL check_la[MAX][17],check_lb[MAX][17];
int to[MAX][2];

void init();
void go(int s, int x, LL & a, LL & b);
int f(int i, int j);
LL la(int i, int j);
LL lb(int i, int j);

int main(void){
  memset(check_f,-1,sizeof(check_f)); memset(check_la,-1,sizeof(check_la)); memset(check_lb,-1,sizeof(check_lb));
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {scanf("%d",&h[i]); node[i].h=h[i],node[i].num=i;}
  sort(node+1,node+1+n);
  init();
#ifdef DEBUG
  //for(int i=1;i<=n;i++) printf("  to[%d]={%d,%d}\n",i,to[i][0],to[i][1]);
  printf("  init successfully\n");
#endif

  int s,x; LL a,b;
  scanf("%d",&x);
  double ansMin=INF; int u=0; h[0]=-INF;
  for(int i=1;i<n;i++){
    go(i,x,a,b);
    if(b==0) {if(fabs(ansMin-INF)<EPS && h[i]>h[u]) u=i;}
    else{
      double t=(double)a/b;
      if(fabs(ansMin-t)<EPS && h[i]>h[u]) u=i;
      else if(t<ansMin) {ansMin=t; u=i;}
    }
  }
  printf("%d\n",u);

  int m; scanf("%d",&m);
  for(int i=0;i<m;i++){
    scanf("%d%d",&s,&x);
    go(s,x,a,b);
    printf("%lld %lld\n",a,b);
  }

  return 0;
}

void init(){
  Node a[4];
  for(int i=1;i<=n;i++){
    memset(a,0,sizeof(a));
    int num=node[i].num;
    int cnt=0;
    for(int j=i+1;j<=n && cnt<2;j++) if(node[j].num>num) a[cnt++]=node[j];
    for(int j=i-1;j>=1 && cnt<4;j--) if(node[j].num>num) a[cnt++]=node[j];
    sort(a,a+cnt);
    //for(int j=0;j<cnt;j++) a[j].h=abs(a[j].h-a[i].h);
    for(int j=0;j<cnt;j++) a[j].h=abs(a[j].h-node[i].h);  //<b></b>
    stable_sort(a,a+cnt);
    to[num][0]=a[0].num; to[num][1]=a[1].num;
  }
}
void go(int s, int x, LL & a, LL & b){
  a=b=0;
  int pos=s; LL sum=0,ta,tb;
  for(int i=16;i>=0;i--){
    if(f(pos,i) && sum+(ta=la(pos,i))+(tb=lb(pos,i))<=x){
      sum+=ta+tb;
      a+=ta; b+=tb;
      pos=f(pos,i);
    }
  }
  if(to[pos][1] && sum+(ta=abs(h[to[pos][1]]-h[pos]))<=x){
    sum+=ta; a+=ta;
  }
}
int f(int i, int j){
  int & a=check_f[i][j];
  if(a!=-1) return a;
  if(j==0)  a=to[to[i][1]][0];
  else a=f(f(i,j-1),j-1);
  return a;
}
LL la(int i, int j){
  LL & a=check_la[i][j];
  if(a!=-1) return a;
  if(j==0) a=abs(h[to[i][1]]-h[i]);
  else a=la(i,j-1)+la(f(i,j-1),j-1);
  return a;
}
LL lb(int i, int j){
  LL & a=check_lb[i][j];
  if(a!=-1) return a;
  //if(j==0) a=abs(h[to[to[i][1]][0]]-h[i]);
  if(j==0) a=abs(h[to[to[i][1]][0]]-h[to[i][1]]); //<b></b>
  else a=lb(i,j-1)+lb(f(i,j-1),j-1);
  return a;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long unsigned LLU;
const int MAX=100020;
const int INF=0x7fffffff;
const double EPS=1e-6;
int h[MAX],n;
struct Node{  //存储序号，使得其代表城市的海拔升序排列
  int num;
  bool operator < (const Node & b) const {
    return h[num]<h[b.num];
  }
}node[MAX];
struct Node2{
  int num,h;
  bool operator < (const Node2 & b) const {
    return h<b.h;
  }
};
int to[MAX][2]; //to[i][0], to[i][1]: 分别表示从i城市出发，其右边的第一、第二近的城市序号

void init_to();
void cal(int s, int x, int & a, int & b);

int main(void){
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {scanf("%d",&h[i]); node[i].num=i;}
  sort(node+1,node+1+n);
  init_to();
#ifdef DEBUG
  for(int i=1;i<=n;i++) printf("  to[%d]={%d,%d}\n",i,to[i][0],to[i][1]);
#endif

  int s,x,a,b;
  scanf("%d",&x);
  double ansMin=INF; int u=0;
  for(int i=1;i<=n;i++){
    cal(i,x,a,b);
#ifdef DEBUG
    printf("  start from %d, a: %d, b: %d\n",i,a,b);
#endif
    if(b==0) {if(fabs(ansMin-INF)<EPS && h[u]<h[i]) u=i;}
    else{
      double t=1.0*a/b;
      if(fabs(t-ansMin)<EPS && h[u]<h[i]) u=i;
      else if(t<ansMin) ansMin=t,u=i;
    }
  }
  printf("%d\n",u);

  int m; scanf("%d",&m);
  for(int i=0;i<m;i++){
    scanf("%d%d",&s,&x);
    cal(s,x,a,b);
    printf("%d %d\n",a,b);
  }

  return 0;
}

void init_to(){
  Node t; Node2 a[4];
  for(int i=1;i<n;i++){
    a[0].num=a[1].num=a[2].num=a[3].num=0;
    a[0].h=a[1].h=a[2].h=a[3].h=0;
    t.num=i;
    int pos=lower_bound(node+1,node+1+n,t)-node;
    int cnt=0;
    for(int j=pos+1;j<=n && cnt<2;j++) if(node[j].num>i) {a[cnt].num=node[j].num; a[cnt].h=h[node[j].num]; cnt++;}
    for(int j=pos-1;j>=1 && cnt<4;j--) if(node[j].num>i) {a[cnt].num=node[j].num; a[cnt].h=h[node[j].num]; cnt++;}
    sort(a,a+cnt);  //海拔高度升序排列
    for(int j=0;j<cnt;j++) a[j].h=abs(h[i]-a[j].h);
    stable_sort(a,a+cnt);
    to[i][0]=a[0].num; to[i][1]=a[1].num;
  }
}
void cal(int s, int x, int & a, int & b){
  a=b=0;
  int sum=0,cur=s;
  bool type=0;  //0: A, 1: B
  while(1){
    if(type==0){
      if(to[cur][1]==0) return;
      LLU t=llabs(1LL*h[cur]-h[to[cur][1]]);
      if(sum+t>x) return;
      sum+=t; a+=t; cur=to[cur][1];
    }else{
      if(to[cur][0]==0) return;
      LLU t=llabs(1LL*h[cur]-h[to[cur][0]]);
      if(sum+t>x) return;
      sum+=t; b+=t; cur=to[cur][0];
    }
    type=!type;
  }
}
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=100020;
const int INF=0x7fffffff;
struct Node{
  int h,num;

  bool operator < (const Node & b) const {
    return h<b.h;
  }
}node[MAX];
int h[MAX],n,m;
int to[MAX][2];

void init();
void cal(int s, int x, int & a, int & b);

int main(void){
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {scanf("%d",&h[i]); node[i-1].h=h[i]; node[i-1].num=i;}
  sort(node,node+n);
  init();
#ifdef DEBUG
  for(int i=1;i<=n;i++) printf("  to[%d]={%d,%d}\n",i,to[i][0],to[i][1]);
#endif
  
  int x,s,a,b;
  scanf("%d",&x);
  int ansMin=INF,u=n;
  for(int i=n-1;i>0;i--){
    cal(i,x,a,b);
#ifdef DEBUG
    printf("  start from %d, a: %d, b: %d\n",i,a,b);
#endif
    if(b==0) {if(ansMin==INF && u==n) u=i;}
    else if(a/b==ansMin && h[u]<h[i]) u=i;
    else if(a/b<ansMin) {ansMin=a/b; u=i;}
  }
  printf("%d\n",u);

  scanf("%d",&m);
  for(int i=0;i<m;i++){
    scanf("%d%d",&s,&x);
    cal(s,x,a,b);
    printf("%d %d\n",a,b);
  }

  return 0;
}

void init(){
  Node t,a[4];
  for(int i=1;i<n;i++){
    memset(a,0,sizeof(a));
    t.h=h[i];
    int pos=lower_bound(node,node+n,t)-node;
    int cnt=0;
    for(int j=pos-1;j>=0 && cnt<2;j--) if(node[j].num>node[pos].num) a[cnt++]=node[j];
    for(int j=pos+1;j<n && cnt<4;j++) if(node[j].num>node[pos].num) a[cnt++]=node[j];
    sort(a,a+cnt);
    for(int j=0;j<cnt;j++) a[j].h=abs(a[j].h-h[i]);
    stable_sort(a,a+cnt);
    to[i][0]=a[0].num; to[i][1]=a[1].num;
  }
}
void cal(int s, int x, int & a, int & b){
  a=b=0;
  bool type=0;  //0: A, 1: B
  int sum=0,cur=s;
  while(1){
    if(type==0){
      if(to[cur][1]==0) return;
      int t=(int)abs(h[to[cur][1]]-h[cur]);
      if(sum+t>x) return;
      cur=to[cur][1]; sum+=t; a+=t;
    }else{
      if(to[cur][0]==0) return;
      int t=(int)abs(h[to[cur][0]]-h[cur]);
      if(sum+t>x) return;
      cur=to[cur][0]; sum+=t; b+=t;
    }
    type=!type;
  }
}
*/
