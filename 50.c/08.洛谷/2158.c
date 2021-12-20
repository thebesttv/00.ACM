/*
题目描述
作为体育委员，C君负责这次运动会仪仗队的训练。仪仗队是由学生组成的 N*N 的方阵，为了保证队伍在行进中整齐划一，C君会跟在仪仗队的左后方，根据其视线所及的学生人数来判断队伍是否整齐(如下图)。 现在，C君希望你告诉他队伍整齐时能看到的学生人数。

输入输出格式
输入格式：
共一个数N

输出格式：
共一个数，即C君应看到的学生人数。

输入输出样例
输入样例#1：
4

输出样例#1：
9

数据规模
对于 100% 的数据，1 ≤ N ≤ 40000
*/

/*
  解题报告：
    将左下角作为原点O(0,0)，那么每个点P的坐标也为斜边为PO的三角形的两条直角边长度。 
    对于每个点(i,j)，当且仅当i,j互质时才能被看见。 
    那么题目求的即为满足 1<=i,j<n,gcd(i,j)=1 的所有有序对<i,j>的个数再加2（点(0,1)和点(1,0)）。 
    想要优化，就可以求 sum=gcd(i,j),1<=i<n,i<j ，答案即为 sum*2+3 。
    但这样O(n^2)的复杂度依然太大。
    想到对n=5,求cnt的每个gcd分别为：
      (1,2)
      (1,3) (2,3)
      (1,4) (2,4) (3,4)
    对每行，从右往左看，那么组成sum的其实就是phi(2:n-1)。
    然后就可以 O(nloglogn) 地求出 phi table，然后累加即可算出sum，进而算出答案。 
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

const int MAX=40020;
int phi[MAX];

void phi_table(int n){
  phi[1]=1;
  FORR(i,2,n) if(!phi[i])
    for(int j=i;j<=n;j+=i){
      if(!phi[j]) phi[j]=j;
      phi[j]=phi[j]/i*(i-1);
    }
}

//ans = 2*sum{ phi(i) | 1<i<n } + 3

int main(void){
  int n; scanf("%d",&n);
  phi_table(n);
  int sum=0;
  FOR(i,2,n) sum+=phi[i];
  printf("%d\n",(sum<<1)+3);

  return 0;
}

/*
//ans = 2*sum{ phi(i) | 1<i<n } + 3
int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}

int main(void){
  int n; scanf("%d",&n);
  int cnt=0;
  FOR(i,1,n) FOR(j,i+1,n)
    if(gcd(i,j)==1) cnt++;
  printf("%d\n",(cnt<<1)+3);

  return 0;
}
*/
