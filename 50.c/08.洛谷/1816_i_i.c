/*
题目描述
老管家是一个聪明能干的人。他为财主工作了整整10年，财主为了让自已账目更加清楚。要求管家每天记k次账，由于管家聪明能干，因而管家总是让财主十分满意。但是由于一些人的挑拨，财主还是对管家产生了怀疑。于是他决定用一种特别的方法来判断管家的忠诚，他把每次的账目按1，2，3…编号，然后不定时的问管家问题，问题是这样的：在a到b号账中最少的一笔是多少？为了让管家没时间作假他总是一次问多个问题。

输入输出格式
输入格式：
输入中第一行有两个数m,n表示有m(m<=100000)笔账,n表示有n个问题，n<=100000。
第二行为m个数,分别是账目的钱数
后面n行分别是n个问题,每行有2个数字说明开始结束的账目编号。

输出格式：
输出文件中为每个问题的答案。具体查看样例。

输入输出样例
输入样例#1：
10 3
1 2 3 4 5 6 7 8 9 10
2 7
3 9
1 10

输出样例#1：
2 3 1
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

//ST
const int MAX=100020;
int n,m,a[MAX];
int f[MAX][18];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) {scanf("%d",&a[i]); f[i][0]=a[i];}

  ROR(i,n,1) FORR(j,1,17) if(i+(1<<(j-1))<=n)
    f[i][j] = min( f[i][j-1], f[i+(1<<(j-1))][j-1] );

  int l,r;
  FOR(i,0,m){
    scanf("%d%d",&l,&r);
    int t=1,k=0;
    while(t<r-l+1) t<<=1,k++;
    if(k) k--;  //<b></b>
    t = min( f[l][k], f[r-(1<<k)+1][k]);
    printf("%d ",t);
    //int k=floor(log(r-l+1)/log(2));
    //printf("%d ",min(f[l][k],f[r-(1<<k)+1][k]));
  }
  putchar('\n');

  return 0;
}

/*
//线段树
//对于RMQ比ST慢
const int MAX=100020;
int a[MAX],st[MAX<<2];

void build(int root, int l, int r){
  if(l==r) {st[root]=a[l]; return;}
  int m=l+r>>1;
  build(root<<1,l,m);
  build(root<<1|1,m+1,r);
  st[root]=min(st[root<<1],st[root<<1|1]);
}
int qmin(int root, int cl, int cr, int ql, int qr){
  if(ql<=cl && qr>=cr) return st[root];
  int m=cl+cr>>1;
  if(qr<=m) return qmin(root<<1,cl,m,ql,qr);
  else if(ql>m) return qmin(root<<1|1,m+1,cr,ql,qr);
  else return min(qmin(root<<1,cl,m,ql,qr),qmin(root<<1|1,m+1,cr,ql,qr));
}

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  build(1,1,n);
  int l,r;
  for(int i=0;i<m;i++){
    scanf("%d%d",&l,&r);
    printf("%d ",qmin(1,1,n,l,r));
  }
  printf("\n");

  return 0;
}
*/

/*
//ST
int n,m;
int a[100020];
int f[100020][17];

void rmq_init(){
  for(int i=1;i<=n;i++) f[i][0]=a[i];
  int k=floor(log(n)/log(2));
  for(int j=1;j<=k;j++){
    for(int i=n;i>=1;i--) if(i+(1<<(j-1))<=n)  //f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1])
      f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
  }
}
int qmin(int l, int r){
  int k=floor(log(r-l+1)/log(2));
  return min(f[l][k],f[r-(1<<k)+1][k]);
}

int main(void){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  rmq_init();
  int l,r;
  for(int i=0;i<m;i++){
    scanf("%d%d",&l,&r);
    printf("%d ",qmin(l,r));
  }
  printf("\n");

  return 0;
}
*/
