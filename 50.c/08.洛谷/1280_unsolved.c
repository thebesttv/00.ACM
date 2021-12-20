/*
题目描述
尼克每天上班之前都连接上英特网，接收他的上司发来的邮件，这些邮件包含了尼克主管的部门当天要完成的全部任务，每个任务由一个开始时刻与一个持续时间构成。
尼克的一个工作日为N分钟，从第一分钟开始到第N分钟结束。当尼克到达单位后他就开始干活。如果在同一时刻有多个任务需要完戍，尼克可以任选其中的一个来做，而其余的则由他的同事完成，反之如果只有一个任务，则该任务必需由尼克去完成，假如某些任务开始时刻尼克正在工作，则这些任务也由尼克的同事完成。如果某任务于第P分钟开始，持续时间为T分钟，则该任务将在第P+T-1分钟结束。
写一个程序计算尼克应该如何选取任务，才能获得最大的空暇时间。

输入输出格式
输入格式：
输入数据第一行含两个用空格隔开的整数N和K(1≤N≤10000，1≤K≤10000)，N表示尼克的工作时间，单位为分钟，K表示任务总数。
接下来共有K行，每一行有两个用空格隔开的整数P和T，表示该任务从第P分钟开始，持续时间为T分钟，其中1≤P≤N，1≤P+T-1≤N。

输出格式：
输出文件仅一行，包含一个整数，表示尼克可能获得的最大空暇时间。

输入输出样例
输入样例#1：
15 6
1 2
1 6
4 11
8 5
8 1
11 5

输出样例#1：
4
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

const int MAX=10020;
struct Node{
  int l,r;
  bool operator < (const Node & b) const {
    return l!=b.l ? l<b.l : r<b.r;
  }
}node[MAX];
int n,k;
int f[MAX];

int main(void){
  scanf("%d%d",&n,&k);
  FOR(i,0,k){ scanf("%d%d",&node[i].l,&node[i].r); node[i].r+=node[i].l-1; }  //输入并初始化
  sort(node,node+k);  //按照l为先，r为后升序排列

  int minR=1<<30,maxL=node[k-1].l;  //计算最大的l和最小的r
  for(int i=0;i<k && node[i].l<=minR;i++){
    minR=min(minR,node[i].r);
  }
  //FOR(i,0,k) minR=min(minR,node[i].r);
#ifdef DEBUG
  printf("  minR: %d, maxL: %d\n",minR,maxL);
  FOR(i,0,k) if(node[i].r<=minR) printf("  node[%d].r: %d\n",i,node[i].r);
#endif
  for(int i=0;i<k && node[i].l<=minR;i++){  //对每个其自身之前不可能再有任务的任务直接计算出答案
    f[node[i].r]=max(f[node[i].r],node[i].l-1);
  }
  FOR(i,0,k){
    Node t; t.l=node[i].r+1; t.r=0;
    int j=lower_bound(node,node+k,t)-node;
    if(node[j].l<t.l) continue; //如果没有，则跳过
#ifdef DEBUG
    printf("  with l: %d, lower_bound: node[%d]: [%d,%d]\n",t.l,j,node[j].l,node[j].r);
#endif
    for(int jj=j;jj<k && node[jj].l==node[j].l;jj++)
      f[node[jj].r]=max(f[node[jj].r],f[node[i].r]+(node[jj].l-node[i].r-1));

    //int j=i+1; while(j<k && node[j].l<=node[i].r) j++;
    //for(int jj=j;jj<k && node[jj].l==node[j].l;jj++){
    //  f[node[jj].r]=max(f[node[jj].r],f[node[i].r]+(node[jj].l-node[i].r-1));
    //}
  }
  int ansMax=0;
  for(int i=n;i>=maxL;i--) if(f[i]){
    ansMax=max(ansMax,f[i]+n-i);
  }
  printf("%d\n",ansMax);

  return 0;
}
