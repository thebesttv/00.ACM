/*
题目描述
国防部计划用无线网络连接若干个边防哨所。2 种不同的通讯技术用来搭建无线网络；
每个边防哨所都要配备无线电收发器；有一些哨所还可以增配卫星电话。
任意两个配备了一条卫星电话线路的哨所（两边都装有卫星电话）均可以通话，无论他们相距多远。而只通过无线电收发器通话的哨所之间的距离不能超过 D，这是受收发器的功率限制。收发器的功率越高，通话距离 D 会更远，但同时价格也会更贵。
收发器需要统一购买和安装，所以全部哨所只能选择安装一种型号的收发器。换句话说，每一对哨所之间的通话距离都是同一个 D。你的任务是确定收发器必须的最小通话距离 D，使得每一对哨所之间至少有一条通话路径（直接的或者间接的）。

输入输出格式
输入格式：
从 wireless.in 中输入数据第 1 行，2 个整数 S 和 P，S 表示可安装的卫星电话的哨所数，P 表示边防哨所的数量。接下里 P 行，每行两个整数 x，y 描述一个哨所的平面坐标(x, y)，以 km 为单位。

输出格式：
输出 wireless.out 中
第 1 行，1 个实数 D，表示无线电收发器的最小传输距离，精确到小数点后两位。

输入输出样例
输入样例#1：
2 4
0 100
0 300
0 600
150 750

输出样例#1：
212.13

数据范围
对于 20% 的数据：P = 2，S = 1
对于另外 20% 的数据：P = 4，S = 2
对于 100% 的数据保证：1 ≤ S ≤ 100，S < P ≤ 500，0 ≤ x，y ≤ 10000。
*/

/*
  解题报告：
  [1]Kruskal
    使用一次Kruskal，然后去除最长的s-1条生成树的边，剩下的最长边即为答案。
    因为共有s个卫星电话，那么就可以覆盖s个点，使得那s个点中任意两点减距离为0。
    那么贪心地覆盖边权最大的点即可。
    注意：不能降序扫描生成树中的边，然后贪心地覆盖并记录被覆盖的点，直到不能再覆盖为止。
    错误数据：
      4 5
      1 3
      1 4
      2 5
      4 2
      7 0
  [2]二分
    先将所有边排序，然后二分最大边。
 <b>使用类似Kruskal的方法</b>，每次从小到大遍历所有边，看是否要使用卫星电话，再将边连接的两点加入同一个连通分量里（添加到并查集中），直到建了n-1条边为止。如果使用卫星电话的边不小于m，则不可行。
    ps:我真的是要好好理解Kruskal的这种排序+连通分量（并查集）的算法。
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

//二分
const int MAX=520;
int n,m,p[MAX];
int pos[MAX][2];
struct Edge{
  int u,v; double w;
  bool used;
  bool operator < (const Edge & b) const {return w<b.w;}
}edge[MAX*MAX];
int tail=0;

int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}
bool check(double M){
  MST(p,-1);
  int cnt=0,use=0;
  FOR(i,0,tail){
    Edge & e=edge[i];
    int px=find(e.u),py=find(e.v);
    if(px==py) continue;
    if(e.w>M) use++;
    cnt++; p[px]=py;
    if(use>=m) return false;
    if(cnt==n-1) return true;
  }
  return false;
}

int main(void){
  scanf("%d%d",&m,&n);
  FOR(i,0,n) scanf("%d%d",&pos[i][0],&pos[i][1]);
  double L=0,R=0;
  FOR(i,0,n){ //算边
    int X1=pos[i][0],Y1=pos[i][1],X2,Y2;
    FOR(j,i+1,n){
      X2=pos[j][0],Y2=pos[j][1];
      double dis = sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2));
      edge[tail++] = (Edge){i,j,dis,0};
      R=max(R,dis);
    }
  }
  sort(edge,edge+tail);

  while(R-L>1e-3){
    double M=(L+R)/2;
    if(check(M)) R=M;
    else L=M;
  }
  printf("%.2lf\n",L);

  return 0;
}

/*
//Kruskal
const int MAX=520;
int n,m,p[MAX];
int pos[MAX][2];
struct Edge{
  int u,v; double w;
  bool used;
  bool operator < (const Edge & b) const {return w<b.w;}
}edge[MAX*MAX];
int tail=1;
//bool vis[MAX];  //判断点i是否安装卫星电话

int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}

int main(void){
  scanf("%d%d",&m,&n);
  FOR(i,0,n) scanf("%d%d",&pos[i][0],&pos[i][1]);
  FOR(i,0,n){ //算边
    int X1=pos[i][0],Y1=pos[i][1],X2,Y2;
    FOR(j,i+1,n){
      X2=pos[j][0],Y2=pos[j][1];
      double dis = sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2));
      edge[tail++] = (Edge){i,j,dis,0};
    }
  }
  sort(edge,edge+tail);

  int cnt=0,pos=1; MST(p,-1);
  while(pos<tail){
    Edge & e=edge[pos++];
    int px=find(e.u),py=find(e.v);
    if(px==py) continue;
    e.used=1; p[px]=py; cnt++;
    if(cnt==n-1) break;
  }

  double ansMin=1LL<<60;
  //ROR(i,pos,0) if(edge[i].used){  //错误
  //  Edge & e=edge[i]; ansMin=e.w; //<b> </b>
  //  int d = (vis[e.u]==0) + (vis[e.v]==0);
  //  m-=d; if(m<0) break;  //<b> </b>
  //  vis[e.u]=vis[e.v]=1;
  //}
  for(int i=pos,cnt=0;i && cnt<m;i--)
    if(edge[i].used) ansMin=edge[i].w,cnt++;

  printf("%.2lf\n",ansMin);

  return 0;
}
*/
