/*
题目描述
给定一个 n*m 个矩阵，矩阵中每个数都是 [1, 12] 内的整数。你可以执行下列两个操作任意多次:
• 指定一行，将该行所有数字+1.
• 指定一列，将该列所有数字+1.
如果执行完上述操作之后，矩阵中某个数变成了3,6,9,12 其中的某一个，我们认为这个数是稳的。
给定初始矩阵，求出任意执行操作之后稳数的最多个数。

输入输出格式
输入格式：
第一行包含两个正整数 n, m。
接下来 n 行，每行 m 个数，描述这个矩阵。

输出格式：
一个整数，表示答案。

输入输出样例
输入样例#1：
3 3 
1 2 3 
3 2 4 
1 2 1

输出样例#1：
7

输入样例#2：
5 5
2 4 6 8 10 
1 2 3 4 5 
3 4 5 6 7 
7 8 9 10 11 
5 10 12 3 7

输出样例#2：
20

说明
测试点编号    限制与约束
1             n,m<=2
2             n,m<=5
3~10          n,m<=10
*/

/*
  得分：10
  正解：
    天呐这道题原来这么简单，我难道是傻了吗！诶，无奈。
    可以发现，加4,7,10都不如加1更优，因为对于一个数n，如果n+4满足是稳的，那么n+1一定是稳的；但如果n+1是稳的，n+4不一定是稳的。
    那么就可以只加0,1,2，减少了很多枚举的工作量。
    枚举每一列加几，因为枚举后行与行之间是独立的（一行的加多少都不会影响令一行），可以对于每一行枚举枚举寻找最优解。
    总复杂度为 O((3^m)*3*n*m)。
<b>优化：</b>
    在对每一行计算时，可以利用cnt[i]数组记录加i符合题意的数的个数（类似于“篝火晚会”一题），那么就可以O(m)求出每一行的最优解。
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

const int MAX=20;
int n,m,a[MAX][MAX],c[MAX];
int ansMax=0;

int check(){
  int sum=0,cnt[3],t;
  FOR(i,0,n){
    cnt[0]=cnt[1]=cnt[2]=0;
    FOR(j,0,m) if((t=a[i][j]+c[j])<=12){
      cnt[(12-t)%3]++;
    }
    sum+=max(cnt[0],max(cnt[1],cnt[2]));
  }
  return sum;
}
void dfs(int cur){
  if(cur==m){
    ansMax=max(ansMax,check());
    return;
  }
  FOR(i,0,3){
    c[cur]=i; dfs(cur+1);
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) FOR(j,0,m) scanf("%d",&a[i][j]);

  dfs(0);
  printf("%d\n",ansMax);

  return 0;
}

/*
const int MAX=20;
int n,m,a[MAX][MAX],c[MAX];
int ansMax=0;

int check(){
  int cnt=0;
  FOR(i,0,n){ //对每一行
    int tMax=0;
    FOR(t,0,3){
      int tcnt=0;
      FOR(j,0,m){
        int tt=a[i][j]+t+c[j];
        if(tt==3 || tt==6 || tt==9 || tt==12) tcnt++;
      }
      tMax=max(tMax,tcnt);
    }
    cnt+=tMax;
  }
  return cnt;
}
void dfs(int cur){
  if(cur==m){
    ansMax=max(ansMax,check());
    return;
  }
  FOR(i,0,3){
    c[cur]=i; dfs(cur+1);
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) FOR(j,0,m) scanf("%d",&a[i][j]);

  dfs(0);
  printf("%d\n",ansMax);

  return 0;
}
*/

/*
const int MAX=20;
int n,m,ansMin=1<<30;;
int a[MAX][MAX];
int r[MAX],c[MAX],rmax[MAX],cmax[MAX];

inline void dfs(int i, int j, int cnt){  //i: r, j: c 搜索最小的 不稳的数 个数
  if(cnt>ansMin) return;
  if(i==n && j==m) {ansMin=cnt; return;}
  
  if(i<n && j<m){
    FORR(x,0,rmax[i]) FORR(y,0,cmax[j]){
      r[i]=x; c[j]=y;
      register int tcnt=0;
      FORR(ii,0,i){
        register int t=a[ii][j]+r[ii]+c[j];
        if(t!=3 && t!=6 && t!=9 && t!=12) tcnt++;
      }
      FOR(jj,0,j){
        register int t=a[i][jj]+r[i]+c[jj];
        if(t!=3 && t!=6 && t!=9 && t!=12) tcnt++;
      }
      dfs(i+1,j+1,cnt+tcnt);
    }
  }else if(i<n){
    FORR(x,0,rmax[i]){
      r[i]=x;
      register int tcnt=0;
      FOR(jj,0,j){
        register int t=a[i][jj]+r[i]+c[jj];
        if(t!=3 && t!=6 && t!=9 && t!=12) tcnt++;
      }
      dfs(i+1,m,cnt+tcnt);
    }
  }else{
    FOR(y,0,cmax[j]){
      c[j]=y;
      register int tcnt=0;
      FORR(ii,0,i){
        register int t=a[ii][j]+r[ii]+c[j];
        if(t!=3 && t!=6 && t!=9 && t!=12) tcnt++;
      }
      dfs(n,j+1,cnt+tcnt);
    }
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) FOR(j,0,m) scanf("%d",&a[i][j]);
  FOR(i,0,n){
    register int rMin=1<<30;
    FOR(j,0,m) rMin=min(rMin,a[i][j]);
    rmax[i]=12-rMin;
  }
  FOR(j,0,m){
    register int cMin=1<<30;
    FOR(i,0,n) cMin=min(cMin,a[i][j]);
    cmax[j]=12-cMin;
  }

  if(n<=5 && m<=5) dfs(0,0,0);
  else{
    int sum=0;
    FOR(i,0,n) FOR(j,0,m) sum+=a[i][j];
    srand(sum*sum%1000007*sum);
    int T=500000;
    while(T--){
      FOR(i,0,n) r[i]=rand()%5;
      FOR(j,0,m) c[j]=rand()%5;
      int cnt=0;
      FOR(i,0,n) FOR(j,0,m){
        int t=a[i][j]+r[i]+c[j];
        if(t!=3 && t!=6 && t!=9 && t!=12) cnt++;
      }
      ansMin=min(ansMin,cnt);
    }
  }
  printf("%d\n",n*m-ansMin);

  return 0;
}
*/
