/*
Description
现在小朋友们最喜欢的"喜羊羊与灰太狼",话说灰太狼抓羊不到，但抓兔子还是比较在行的，
而且现在的兔子还比较笨，它们只有两个窝，现在你做为狼王，面对下面这样一个网格的地形：

  S---+---+---+
  |\  |\  |\  |
  | \ | \ | \ |
  |  \|  \|  \|
  +---+---+---+
  |\  |\  |\  |
  | \ | \ | \ |
  |  \|  \|  \|
  +---+---+---T

左上角点为(1,1),右下角点为(N,M)(上图中N=3,M=4).有以下三种类型的道路 
1:(x,y)<==>(x+1,y) 
2:(x,y)<==>(x,y+1) 
3:(x,y)<==>(x+1,y+1) 
道路上的权值表示这条路上最多能够通过的兔子数，道路是无向的. 左上角和右下角为兔子的两个窝，
开始时所有的兔子都聚集在左上角(1,1)的窝里，现在它们要跑到右下解(N,M)的窝中去，狼王开始伏击
这些兔子.当然为了保险起见，如果一条道路上最多通过的兔子数为K，狼王需要安排同样数量的K只狼，
才能完全封锁这条道路，你需要帮助狼王安排一个伏击方案，使得在将兔子一网打尽的前提下，参与的
狼的数量要最小。因为狼还要去找喜羊羊麻烦.

Input
第一行为N,M.表示网格的大小，N,M均小于等于1000.
接下来分三部分
第一部分共N行，每行M-1个数，表示横向道路的权值. 
第二部分共N-1行，每行M个数，表示纵向道路的权值. 
第三部分共N-1行，每行M-1个数，表示斜向道路的权值. 
输入文件保证不超过10M

Output
输出一个整数，表示参与伏击的狼的最小数量.

Sample Input
3 4
5 6 4
4 3 1
7 5 3
5 6 7 8
8 7 6 5
5 5 5
6 6 6

Sample Output
14

HINT
2015.4.16新加数据一组，可能会卡掉从前可以过的程序。
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

/*
//网络
//平面图最小割转化最短路，所有内点直接相邻的边（边界除外）都要连边
//设S(2001,2001) E(2001,2002)
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
const int lq=4001000;
struct Q{
  int r,c;
  Q(){}
  Q(int _r,int _c){r=_r;c=_c;}
}q[lq+2];
int n,m,w[2010][2010],f[2010][2010],isq[2010][2010];
int h=0,t=0;

void ins(int rr,int cc,int r,int c){
  if((rr<1||rr>(n<<1)-1||cc<1||cc>(m<<1)-1)&&!(rr==2001&&cc==2001)&&!(rr==2001&&cc==2002))return;
  if(f[rr][cc]>f[r][c]+w[rr][cc]){
    f[rr][cc]=f[r][c]+w[rr][cc];
    if(!isq[rr][cc]){
      q[(++t)%lq]=Q(rr,cc);
      isq[rr][cc]=1;
    }
  }
}
void SPFA(){
  memset(f,0x3f,sizeof(f));
  f[2001][2001]=0;
  t++;
  q[t%lq]=Q(2001,2001);
  while(h<t){
    h++;
    int r=q[h%lq].r,c=q[h%lq].c;
    isq[r][c]=0;
    if(r==2001&&c==2001){
      for(int i=1;i<n;i++)
        ins(i<<1,1,r,c);
      for(int i=1;i<m;i++)
        ins((n<<1)-1,i<<1,r,c);
    }
    else if(r==2001&&c==2002){
      for(int i=1;i<n;i++) ins(i<<1,(m<<1)-1,r,c);
      for(int i=1;i<m;i++) ins(1,i<<1,r,c);
    }
    else{
      if(r==1) ins(2001,2002,r,c);
      if(r==(n<<1)-1) ins(2001,2001,r,c);
      if(c==1) ins(2001,2001,r,c);
      if(c==(m<<1)-1) ins(2001,2002,r,c);
      if(!(r&1)) {ins(r,c-1,r,c);ins(r,c+1,r,c);}
      if(!(c&1)) {ins(r-1,c,r,c);ins(r+1,c,r,c);}
      if((r+c)&1) {ins(r-1,c-1,r,c);ins(r+1,c+1,r,c);}
    }
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) for(int j=1;j<m;j++)
    scanf("%d",&w[2*i-1][2*j]);
  for(int i=1;i<n;i++) for(int j=1;j<=m;j++)
    scanf("%d",&w[2*i][2*j-1]);
  for(int i=1;i<n;i++) for(int j=1;j<m;j++)
    scanf("%d",&w[2*i][2*j]);
  SPFA();
  printf("%d",f[2001][2002]);
  return 0;
}
*/
