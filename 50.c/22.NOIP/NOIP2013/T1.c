/*
描述
n 个小伙伴（编号从 0 到 n-1）围坐一圈玩游戏。按照顺时针方向给 n 个位置编号，从0 到 n-1。最初，第 0 号小伙伴在第 0 号位置，第 1 号小伙伴在第 1 号位置，……，依此类推。
游戏规则如下：每一轮第 0 号位置上的小伙伴顺时针走到第 m 号位置，第 1 号位置小伙伴走到第 m+1 号位置，……，依此类推，第n − m号位置上的小伙伴走到第 0 号位置，第n-m+1 号位置上的小伙伴走到第 1 号位置，……，第 n-1 号位置上的小伙伴顺时针走到第m-1 号位置。
现在，一共进行了 10^k 轮，请问 x 号小伙伴最后走到了第几号位置。

格式
输入格式
输入共 1 行，包含 4 个整数 n、m、k、x，每两个整数之间用一个空格隔开。

输出格式
输出共 1 行，包含 1 个整数，表示 10^k 轮后 x 号小伙伴所在的位置编号。

样例1
样例输入1
10 3 4 5

样例输出1
5

限制
每个测试点1s。

提示
对于 30%的数据，0 < k < 7； 
对于 80%的数据，0 < k < 10^7； 
对于 100%的数据，1 < n < 1,000,000，0 < m < n，1 <= x <=n，0 < k < 10^9。

来源
NOIP 2013 提高组 Day 1
*/

/*
  得分：100
  解题报告：
    这D1T1还挺难的。
    稍作模拟，可以发现：当k较大时，x走的路线是有规律的，并且这个规律的周期最大只有n。
    因为x要么走遍所有的点，要么在其中一些点上循环。而如果这个规律大于n，那么说明其中至少有两个点是重复的，而只要有重复，就不是一个周期了，因此最大周期为n，只要开一个大小为n的数组，模拟第一个周期，再配上快速幂并取模，就可以了。
*/

#include<iostream>
#include<cstdio>
using namespace std;

int a[1000020];
bool vis[1000020];

int pow_mod(int a, int n, int m){
  if(n==0) return 1;
  if(n==1) return a%m;
  int ans=pow_mod(a,n/2,m);
  ans=1LL*ans*ans%m;
  if(n&1) ans=1LL*ans*a%m;
  return ans;
}

int main(void){
  int n,m,k,x; scanf("%d%d%d%d",&n,&m,&k,&x);
  int mod=n;
  for(int i=0;i<n;i++){
    if(vis[x]) {mod=i; break;}
    else vis[x]=1;
    a[i]=x; x=(x+m)%n;
#ifdef DEBUG
    printf("  a[%d]=%d\n",i,a[i]);
#endif
  }
#ifdef DEBUG
  printf("  mod: %d\n",mod);
#endif
  int t=pow_mod(10,k,mod);
  printf("%d\n",a[t]);

  return 0;
}
