/*
题目描述
对于任何正整数x，其约数的个数记作g(x)。例如g(1)=1, g(6)=4。
如果某个正整数x满足：g(x)>g(i),0<i<x，则称x为反质数。例如，整数1，2，4，6等都是反质数。
现在给定一个数N，你能求出不超过N的最大的反质数么？

输入输出格式
输入格式：
一个数N（1<=N<=2,000,000,000）。

输出格式：
不超过N的最大的反质数。

输入输出样例
输入样例#1：
1000

输出样例#1：
840
*/

/*
  解题报告：
    题目求的是不超过n的最大的反质数，可以转化为：求1:N中，约数最大的数，如果有多个，则取最小的一个（因为只有最小的一个，其前面的数的约数才都比它小）。
    那么就需要在1:N中，构造一个约数个数最多的数，且数字本身最小。
    考虑对于x，先对其进行质因数分解，得
      x = p1^k1 * p2^k2 * p3^k3 ... * pn^kn
    那么任意y|x，其分解而成的质因数p'1:p'n'都在p1:pn中
    因此，由乘法原理得：x的因子个数即为 (k1+1)*(k2+1)*...*(kn+1)
    
    通过这些，我们得到：x的因子个数g(x)只与k1:kn有关，与p1:pn无关。
    那么想要使g(x)最大且x尽量小，那么只会用到小的质数（2, 3, 5, 7）

    对于两个数：
      648 = 2^3 * 3^4
      432 = 2^4 * 3^3
    它们的g(x)相同，但显然432更小。
    因此，想要构造出尽量小的x，须满足k1:kn单调不递增
*/

//dfs搜索版
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int MAX=10;
int prime[MAX]={2,3,5,7,11,13,17,19,23,29};
int pr[MAX][34];
int maxExp[MAX];
int ansMin,piMax,n;

void dfs(int cur, int exp, int pi, int ans){  //当前要枚举的为cur
  if(cur==MAX){
    if(pi>piMax) piMax=pi,ansMin=ans;
    else if(pi==piMax) ans<ansMin ? ansMin=ans : 0 ;
    return;
  }
  for(int i=min(exp,maxExp[cur]);i>=0;i--) if(1LL*ans*pr[cur][i]<=n)
    dfs(cur+1,i,pi*(i+1),ans*pr[cur][i]);
}

int main(void){
  for(int i=0;i<MAX;i++) pr[i][0]=1,maxExp[i]=floor(log(2000000000)/log(prime[i]));
  for(int i=0;i<MAX;i++) for(int j=1;j<=maxExp[i];j++) pr[i][j]=pr[i][j-1]*prime[i];
  scanf("%d",&n);
  for(int i=0;i<MAX;i++) maxExp[i]=floor(log(n)/log(prime[i]));
  ansMin=n; piMax=0;
  dfs(0,maxExp[0],1,1);
  printf("%d\n",ansMin);

  return 0;
}

/*
//循环版
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long LL;
const int MAX=8;
int pr[MAX][40]={{1,2},{1,3},{1,5},{1,7},{1,11},{1,13},{1,17},{1,19}};
int t[MAX],a[MAX];

int main(void){
  for(int i=0;i<MAX;i++) t[i]=floor(log(2000000000)/log(pr[i][1]));
  for(int i=0;i<MAX;i++) for(int j=2;j<=t[i];j++) pr[i][j]=pr[i][j-1]*pr[i][1];

  int n; scanf("%d",&n);
  for(int i=0;i<MAX;i++) t[i] = floor(log(n)/log(pr[i][1]));
  int ansMin=n+1,pikMax=0;
  for(a[0]=0;a[0]<=t[0];a[0]++)
  for(a[1]=0;a[1]<=t[1] && a[1]<=a[0];a[1]++)
  for(a[2]=0;a[2]<=t[2] && a[2]<=a[1];a[2]++)
  for(a[3]=0;a[3]<=t[3] && a[3]<=a[2];a[3]++)
  for(a[4]=0;a[4]<=t[4] && a[4]<=a[3];a[4]++)
  for(a[5]=0;a[5]<=t[5] && a[5]<=a[4];a[5]++)
  for(a[6]=0;a[6]<=t[6] && a[6]<=a[5];a[6]++)
  for(a[7]=0;a[7]<=t[7] && a[7]<=a[6];a[7]++)
  for(a[8]=0;a[8]<=t[8] && a[8]<=a[7];a[8]++){
    bool ok=1;
    int tpi=1; for(int i=0;i<MAX;i++) tpi*=(a[i]+1);  //计算 g(x)
    LL ans=1;
    for(int i=0;i<MAX;i++){ //计算x
      ans*=pr[i][a[i]];
      if(ans>n) {ok=0; break;}
    }
    if(!ok) continue;
    if(tpi>pikMax) pikMax=tpi,ansMin=ans;
    else if(tpi==pikMax) ans<ansMin ? ansMin=ans : 0 ;
  }
  printf("%d\n",ansMin);

  return 0;
}
*/
