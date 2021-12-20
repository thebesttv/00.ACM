/*
题目背景
小a和uim来到雨林中探险。突然一阵北风吹来，一片乌云从北部天边急涌过来，还伴着一道道闪电，一阵阵雷声。刹那间，狂风大作，乌云布满了天空，紧接着豆大的雨点从天空中打落下来，只见前方出现了一个披头散发、青面獠牙的怪物，低沉着声音说：“呵呵，既然你们来到这，只能活下来一个！”。小a和他的小伙伴都惊呆了！

题目描述
瞬间，地面上出现了一个n*m的巨幅矩阵，矩阵的每个格子上有一坨0~k不等量的魔液。怪物各给了小a和uim一个魔瓶，说道，你们可以从矩阵的任一个格子开始，每次向右或向下走一步，从任一个格子结束。开始时小a用魔瓶吸收地面上的魔液，下一步由uim吸收，如此交替下去，并且要求最后一步必须由uim吸收。魔瓶只有k的容量，也就是说，如果装了k+1那么魔瓶会被清空成零，如果装了k+2就只剩下1，依次类推。怪物还说道，最后谁的魔瓶装的魔液多，谁就能活下来。小a和uim感情深厚，情同手足，怎能忍心让小伙伴离自己而去呢？沉默片刻，小a灵机一动，如果他俩的魔瓶中魔液一样多，不就都能活下来了吗？小a和他的小伙伴都笑呆了！
现在他想知道他们都能活下来有多少种方法。

输入输出格式
输入格式：
第一行，三个空格隔开的整数n,m,k
接下来n行，m列，表示矩阵每一个的魔液量。同一行的数字用空格隔开。

输出格式：
一个整数，表示方法数。由于可能很大，输出对 1000000007 取余后的结果。

输入输出样例
输入样例#1：
2 2 3
1 1
1 1

输出样例#1：
4

样例解释：
四种方案是：(1,1)->(1,2),(1,1)->(2,1),(1,2)->(2,2),(2,1)->(2,2)。

数据范围
对于20%的数据，n,m<=10,k<=2
对于50%的数据，n,m<=100,k<=5
对于100%的数据，n,m<=800,1<=k<=15
*/

/*
  解题报告：
    一开始想到令 f[i][j][k1][k2] 表示终点为(i,j)、a有k1、b有k2时的路径数。因为两人依次吸收，所有每次要走两步，则
      f[i][j][k1][k2] -> f[i+2][j][k1+w[i+1][j]][k2+w[i+2][j]]
                         f[i+1][j+1][k1+w[i+1][j]][k2+w[i+1][j+1]]
                         f[i+1][j+1][k1+w[i][j+1]][k2+w[i+1][j+1]]
                         f[i][j+2][k1+w[i][j+1]][k2+w[i][j+2]]
    答案为每个k1=k2的f之和。
    但即使使用滚动数组防止了MLE，还是逃不了TLE的命运。。。因为O(n*m*k*k)太大了。。。
  正解：
    因为答案要的是所有k1=k2的和，即k1,k2差为0的和，那么想到减少一个维度，令 f[i][j][d] 表示终点为 (i,j)，k1-k2为d的种数。
    但有两个问题：
      1.不能确定a最后走还是b最后走
      2.差会产生负数，正确性也不显然
    针对第一个问题，可以一次走两步，也可以再增加一维[0/1]，0表示a最后走，1表示b最后走
    对于第二个问题，可以使用剩余系解决。令 d=k1-d2（模(k+1)意义下），那么也就是说， d = (k1-k2+(k+1))%(k+1)，也就不会产生负数。
    而对于正确性，可以想：在模4+1意义下，如果a有1个、b有3个，和a有4个、b有1个（差都为2），只要a拿2个，它们的差就都为0。其实剩余系一上来，正确性要想就挺显然的了 XD
    [1]增加一个维度
      令 f[i][j][d][0/1] 表示终点为(i,j)，差为d，最后是a/b走的种数，则
        令d1,d2为更新f的变量
        f[i][j][d][0] = f[i-1][j][d1][1] + f[i][j-1][d1][1]
        f[i][j][d][1] = f[i-1][j][d2][0] + f[i][j-1][d2][0]
        再计算d1,d2
          观察f[i][j][d][1]，它是由之前 f[..][..][..][0]转移而来的，转移后（即b走后）k2变大了，那么d=k1-k2就变小了，也就是说d<d2，那么就得
            d2 = (d+w[i][j])%(k+1)
          再计算d1也就不难了
            d1 = (d-w[i][j]+(k+1))%(k+1)
        初始化：可以在读入时初始化，即令 f[i][j][w[i][j]][0]=1
    [2]每次走两步
      令 f[i][j][d] 表示终点为 (i,j)、差为d的种数，则可以使用刷表法：
        f[i][j][d] -> f[i+2][j][ d + G[i+1][j] - G[i+2][j] ] （省略模）
                      f[i+1][j+1][ d + G[i+1][j] - G[i+1][j+1] ]
                      f[i+1][j+1][ d + G[i][j+1] - G[i+1][j+1] ]
                      f[i][j+2][ d + G[i][j+1] - G[i][j+2 ]
        在每次进入(i,j)时初始化(i+2,j),(i,j+2)即可。（因为不能只走一个人，那么就不能采取之前的初始化方式，只能让两个人都走一步来完成初始化。而在每次进入(i,j)时初始化，也就省去了在计算f之前遍历的麻烦）

    做了这道题，我感觉一百个人有一百种状态转移方程。。。
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

//[1]
const int MAX=820;
const int MOD=1000000007;
int n,m,k,G[MAX][MAX];
int f[MAX][MAX][16][2];
//f[i][j][k][0] += f[i-1][j][ k-G[i][j] ][1] + f[i][j-1][   ][1]
//f[i][j][k][1] += f[i-1][j][ k+G[i][j]  ][0] + f[i][j-1][   ][0]

int main(void){
  scanf("%d%d%d",&n,&m,&k); k++;
  int t;
  FORR(i,1,n) FORR(j,1,m){
    scanf("%d",&t); G[i][j]=(t%=k);
    f[i][j][t][0]++;
  }
  int ans=0;
  FORR(i,1,n) FORR(j,1,m){
    t=G[i][j];
    FOR(kk,0,k){
      int d1=(kk-t+k)%k, d2=(kk+t)%k;
      (f[i][j][kk][0] += f[i-1][j][d1][1] + f[i][j-1][d1][1])%=MOD;
      (f[i][j][kk][1] += f[i-1][j][d2][0] + f[i][j-1][d2][0])%=MOD;
    }
    (ans+=f[i][j][0][1])%=MOD;
  }
  printf("%d\n",ans);

  return 0;
}

/*
//[2],常数优化
const int MAX=820;
const int MOD=1000000007;
int n,m,k,G[MAX][MAX];
int f[MAX][MAX][16];
//f[i][j][d]: 走到(i,j)，k1-k2=d时的种数
//  f[i][j][d] -> f[i][j+2][   ]
//                f[i+1][j+1][   ]
//                f[i+1][j+1][   ]
//                f[i+2][j][   ]

int main(void){
  scanf("%d%d%d",&n,&m,&k); k++;
  int t;
  FORR(i,1,n) FORR(j,1,m){
    scanf("%d",&t); G[i][j]=t%k;
  }

  int ans=0;
  FORR(i,0,n) FORR(j,0,m){
    int *p=&f[i][j][0], *p1=&f[i][j+2][0], *p2=&f[i+2][j][0], *p3=&f[i+1][j+1][0];
    int n1=G[i][j+1],n2=G[i][j+2],n3=G[i+1][j],n4=G[i+2][j],n5=G[i+1][j+1];
    if(i && j+2<=m) (*(p1+(n1-n2+k)%k))++; //注意应为++而非=1
    if(i+2<=n && j) (*(p2+(n3-n4+k)%k))++;
    int a;
    FOR(kk,0,k) if(a=*(p+kk)){
      if(i && j+2<=m) (*(p1+(kk+n1-n2+k)%k)+=a)%=MOD;
      if(i+1<=n && j+1<=m){
        (*(p3+(kk+n1-n5+k)%k)+=a)%=MOD;
        (*(p3+(kk+n3-n5+k)%k)+=a)%=MOD;
      }
      if(i+2<=n && j) (*(p2+(kk+n3-n4+k)%k)+=a)%=MOD;
    }
    if(i && j) (ans+=*p)%=MOD;
  }
  printf("%d\n",ans);

  return 0;
}
*/

/*
//[2]
const int MAX=820;
const int MOD=1000000007;
int n,m,k,G[MAX][MAX];
int f[MAX][MAX][16];

int main(void){
  scanf("%d%d%d",&n,&m,&k); k++;
  FORR(i,1,n) FORR(j,1,m) scanf("%d",&G[i][j]);

  int ans=0;
  FORR(i,0,n) FORR(j,0,m){
    int n1=G[i][j+1],n2=G[i][j+2],n3=G[i+1][j],n4=G[i+2][j],n5=G[i+1][j+1];
    if(i && j+2<=m) f[i][j+2][(n1-n2+k)%k]++;
    if(i+2<=n && j) f[i+2][j][(n3-n4+k)%k]++;
    if(i && j) FOR(d,0,k){
      int a=f[i][j][d]; if(!a) continue;
      if(j+2<=m){
        (f[i][j+2][(d+n1-n2+k)%k]+=a)%=MOD;
      }
      if(i+1<=n && j+1<=m){
        (f[i+1][j+1][(d+n1-n5+k)%k]+=a)%=MOD;
        (f[i+1][j+1][(d+n3-n5+k)%k]+=a)%=MOD;
      }
      if(i+2<=n){
        (f[i+2][j][(d+n3-n4+k)%k]+=a)%=MOD;
      }
    }
    if(i && j) (ans+=f[i][j][0])%=MOD;
  }
  printf("%d\n",ans);

  return 0;
}
*/

/*
//[1]
const int MAX=820;
const int MOD=1000000007;
int n,m,k,G[MAX][MAX];
int f[MAX][MAX][16][2];

int main(void){
  scanf("%d%d%d",&n,&m,&k); k++;
  FORR(i,1,n) FORR(j,1,m) {scanf("%d",&G[i][j]); f[i][j][G[i][j]][0]=1;}

  int ans=0;
  FORR(i,1,n) FORR(j,1,m){
    FOR(d,0,k){
      int d1=(d-G[i][j]+k)%k;
      int d2=(d+G[i][j])%k;
      (f[i][j][d][0]+=f[i-1][j][d1][1]+f[i][j-1][d1][1])%=MOD;
      (f[i][j][d][1]+=f[i-1][j][d2][0]+f[i][j-1][d2][0])%=MOD;
    }
    (ans+=f[i][j][0][1])%=MOD;
  }
  printf("%d\n",ans);

  return 0;
}
*/

/*
//O(n*m*k*k)
const int MAX=820;
const int MOD=1000000007;
int n,m,k,G[MAX][MAX];
int f0[MAX][16][16],f1[MAX][16][16],f2[MAX][16][16];
const int siz=SIZ(f0);

int main(void){
  scanf("%d%d%d",&n,&m,&k);
  FORR(i,1,n) FORR(j,1,m) scanf("%d",&G[i][j]);

  int ans=0;
  FORR(i,0,n){
    memcpy(f0,f1,siz); memcpy(f1,f2,siz); MST(f2,0);
    FORR(j,0,m){
      int n1=G[i][j+1],n2=G[i][j+2],n3=G[i+1][j],n4=G[i+2][j],n5=G[i+1][j+1];
      if(i && j+2<=m) f0[j+2][n1][n2]++;
      if(i+2<=n && j) f2[j][n3][n4]++;
      if(i && j) FORR(k1,0,k) FORR(k2,0,k){
        int a=f0[j][k1][k2]; if(!a) continue;
        if(j+2<=m){
          (f0[j+2][(k1+n1)%(k+1)][(k2+n2)%(k+1)]+=a)%=MOD;
        }
        if(i+1<=n && j+1<=m){
          (f1[j+1][(k1+n1)%(k+1)][(k2+n5)%(k+1)]+=a)%=MOD;
          (f1[j+1][(k1+n3)%(k+1)][(k2+n5)%(k+1)]+=a)%=MOD;
        }
        if(i+2<=n){
          (f2[j][(k1+n3)%(k+1)][(k2+n4)%(k+1)]+=a)%=MOD;
        }
        if(i && j && k1==k2){
          (ans+=a)%=MOD;
        }
      }
    }
  }
  printf("%d\n",ans);

  return 0;
}
*/
