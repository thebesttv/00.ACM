/*
描述
在河上有一座独木桥，一只青蛙想沿着独木桥从河的一侧跳到另一侧。在桥上有一些石子，青蛙很讨厌踩在这些石子上。由于桥的长度和青蛙一次跳过的距离都是正整数，我们可以把独木桥上青蛙可能到达的点看成数轴上的一串整点：0，1，……，L（其中L是桥的长度）。坐标为0的点表示桥的起点，坐标为L的点表示桥的终点。青蛙从桥的起点开始，不停的向终点方向跳跃。一次跳跃的距离是S到T之间的任意正整数（包括S,T）。当青蛙跳到或跳过坐标为L的点时，就算青蛙已经跳出了独木桥。
题目给出独木桥的长度L，青蛙跳跃的距离范围S,T，桥上石子的位置。你的任务是确定青蛙要想过河，最少需要踩到的石子数。

对于30%的数据，L <= 10000；
对于全部的数据，L <= 10^9。

格式
输入格式
输入的第一行有一个正整数L（1 <= L <= 10^9），表示独木桥的长度。第二行有三个正整数S，T，M，分别表示青蛙一次跳跃的最小距离，最大距离，及桥上石子的个数，其中1 <= S <= T <= 10，1 <= M <= 100。第三行有M个不同的正整数分别表示这M个石子在数轴上的位置（数据保证桥的起点和终点处没有石子）。所有相邻的整数之间用一个空格隔开。

输出格式
输出只包括一个整数，表示青蛙过河最少需要踩到的石子数。

样例1
样例输入1
10
2 3 5
2 3 5 6 7

样例输出1
2

限制
1s

来源
NOIp2005 第二题
*/

/*
  得分：30
  解题报告：
    想到了动规，想到了离散化（其实是状压），但压错了。对于这种题目，考试的时候还是应该尽量对每个数据用不同的方法求解。
    状压：（未懂）
      对每个石子i，记t为i与i-1之间的距离，即t=pos[i]-pos[i-1]。
      若T|t，则令k=T
      否则，令k=t%T
      则i与i-1之间的等效距离为min{t,k+T}
*/

//why: 为什么可以这么状压？
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=10020;
int f[MAX],pos[120];
bool G[MAX];

int main(void){
  int L,S,T,n; scanf("%d%d%d%d",&L,&S,&T,&n);
  for(int i=1;i<=n;i++) scanf("%d",&pos[i]);  //从1开始，防止i-1出现负数
  sort(pos,pos+n+1);

  int p=0;
  for(int i=1;i<=n;i++){    //<???><b>
    int l=pos[i]-pos[i-1],k;
    if(l%T==0) k=T;
    else k=l%T;
    k=min(k+T,l);
    p+=k; G[p]=1;
  }                         //</b></???>
  memset(f,0x3f,sizeof(f)); f[0]=0;
  for(int i=0;i<=p;i++){
    for(int j=S;j<=T;j++) f[i+j]=min(f[i+j],f[i]+G[i+j]);
  }
  int ansMin=n;
  for(int i=p+1;i<=p+T+1;i++) ansMin=min(ansMin,f[i]);  //p为最后一个石子的位置，因此从p+1开始
  printf("%d\n",ansMin);

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX=100200;
struct Node{
  int pos;
  int L,R;

  bool operator < (const Node & b) const {
    return pos<b.pos;
  }
}node[120];
int f[MAX];
bool G[MAX];

int main(void){
  int n,S,T,L; scanf("%d%d%d%d",&L,&S,&T,&n);
  int tail=1;
  for(int i=1;i<=n;i++){
    int pos;
    scanf("%d",&pos);
    bool flag=0;
    for(int j=1;j<i;j++) if(node[j].pos==pos) {flag=1; break;}  //判重
    if(flag) continue;
    node[tail].pos=pos;
    node[tail].L=node[tail].pos-T;
    node[tail].R=node[tail].pos+T;
    tail++;
  }
  node[0].pos=0; node[0].L=-T,node[0].R=T;  //把起点和终点当作点，方便离散化
  node[tail].pos=L; node[tail].L=L-T,node[tail].R=L+T;
  sort(node,node+tail+1);

  if(S==T){ //特判，按照网络修改
    int ans=0;
    for(int i=1;i<tail;i++) if(node[i].pos%S==0) ans++;
    printf("%d\n",ans);
  }else{

//    for(int i=1;i<=tail;i++) { //离散化（考试时）
//      int k=max((node[i].L-node[i-1].R)/S,0);
//      k*=S;
//      node[i].pos-=k; node[i].L-=k,node[i].R-=k;
//    }

    for(int i=1;i<=tail;i++){ //离散化（网络）
      int dis=node[i].pos-node[i-1].pos-T;
      if(dis>0) for(int j=i;j<=tail;j++) node[j].pos-=dis;
    }

    for(int i=1;i<tail;i++) G[node[i].pos]=1;
    L=node[tail].pos;  //离散化后的终点

    f[0]=0; for(int i=1;i<=L+T;i++) f[i]=n;
    for(int i=0;i<=L;i++){
      for(int j=S;j<=T;j++) f[i+j]=min(f[i+j],f[i]+G[i+j]);
    }
    int ansMin=n;
    for(int i=L;i<=L+T;i++) ansMin=min(ansMin,f[i]);
    printf("%d\n",ansMin);
  }
    
  return 0;
}
*/
