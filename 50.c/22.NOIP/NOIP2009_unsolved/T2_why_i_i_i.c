/*
描述
Hanks 博士是 BT (Bio-Tech，生物技术) 领域的知名专家，他的儿子名叫 Hankson。现在，刚刚放学回家的 Hankson 正在思考一个有趣的问题。
今天在课堂上，老师讲解了如何求两个正整数 c1和 c2 的最大公约数和最小公倍数。现在 Hankson 认为自己已经熟练地掌握了这些知识，他开始思考一个“求公约数”和“求公倍数”之类问题的“逆问题” ，这个问题是这样的：已知正整数 a0,a1,b0,b1，设某未知正整数 x 满足：
  1. x 和 a0 的最大公约数是 a1；
  2. x 和b0 的最小公倍数是 b1。
Hankson 的“逆问题”就是求出满足条件的正整数 x。但稍加思索之后，他发现这样的 x 并不唯一，甚至可能不存在。因此他转而开始考虑如何求解满足条件的 x 的个数。请你帮助他编程求解这个问题。

格式
输入格式
第一行为一个正整数 n，表示有 n 组输入数据。接下来的 n 行每
行一组输入数据，为四个正整数 a0，a1，b0，b1，每两个整数之间用一个空格隔开。输入数据保证 a0能被 a1 整除，b1 能被 b0整除。

输出格式
共n 行。每组输入数据的输出结果占一行，为一个整数。
对于每组数据：若不存在这样的 x，请输出 0；
若存在这样的 x，请输出满足条件的 x 的个数；

样例1
样例输入1
2 
41 1 96 288 
95 1 37 1776 

样例输出1
6 
2 

限制
对于50%的数据，保证有 1≤a0,a1,b0,b1≤10000 且 n≤100。
对于100%的数据，保证有 1≤a0,a1,b0,b1≤2*10^9 且 n≤2000。
每个测试点1s。

来源
NOIP 2009
*/

/*
  得分：50
  解题报告：
    暴力方法：
      已知 gcd(x,a0)==a1 && lcm(x,b0)==b1
      那么 a0%a1==0, b1%b0==0 ，可作判断有解的条件
      也得到 x=m*a1(m>=1), b1=n*x(n>=1)
      将x=m*a1带入b1，得
              b1=nm*a1
              mn=b1/a1
        若 b1%a1!=0 则无解，这是第三个判断条件
      若有解，就可以
      [1] 枚举 x (a1<=x<=b1)，使得题目条件成立。
      [2] 枚举 x=m*a1 中的m，再判断x是否令条件成立。因为这样x的跳跃一定不小于[1]，也就更快。
      但b1最大为2*10^9，又有最多2000组数据，因此要优化枚举方法。
      优化：
        考虑到当x为b1的因数时，b1/x也为b1的因数，那么就可以只枚举[1:sqrt(n)]，判断 x 和 b1/x (b1/x!=x) 是否成立。
        这样就可以在 O(sqrt(n)) 的复杂度下完成枚举。
        注：优化时一定要从1开始枚举，不能从a1开始。
            因为每次枚举事实上是判断两个x，而如果从a1开始，那么 x={b1,b1/2, ..., b1/(a1-1)} 就不会被枚举到，也就少解了。
        这种枚举约数的方法能降低不少时间复杂度，很值得学习。
    正解：（好像不是很正。。。）
      首先推理一些性质：
        将 a 分解质因数，可得 a = ... * p^k * ...，记k为an
        1.令 gcd(a,b)=c，将a,b,c分解质因数，得 an,bn,cn。对每个素数p：
          若 an>cn ，则 bn=cn
          若 an=cn ，则 bn>=cn
          若 an<cn ，则无解
        2.令 lcm(a,b)=c，同样将a,b,c分解质因数得 an,bn,cn。对每个素数p：
          若 an<cn ，则 bn=cn
          若 an=cn ，则 bn<=cn
          若 an>cn ，则无解
        那么，对于题目中的两个条件，我们可以先将 a0,a1,b0,b1 分解质因数，并且在每次分解时根据条件计算可行解个数（乘法原理），x即为推理时的b
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

const int MAX=4000; //素数个数
vector<int> prime;
int res;
int a0,a1,b0,b1;

void div(int p);
inline bool isprime(int n);

int main(void){
  prime.push_back(2); prime.push_back(3); prime.push_back(5);
  int cnt=3;
  for(int i=7;cnt<iMAX;i+=2){
    if(isprime(i)) prime.push_back(i),cnt++;
  }

  int n; scanf("%d",&n);
  while(n--){
    scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
    res=1;
    for(int i=0;i<MAX;i++) div(prime[i]);

    //网络  ???
    //if(a0>1) div(a0);
    //else if(b1>1 && b1!=a0) div(b1);
    if(a0>1) div(a0);       //如果a0不等于1的话，说明a0没被分解完，也就是说a0的因子中有大素数
    if(a1>1) div(a1);
    if(b0>1) div(b0);
    if(b1>1) div(b1);

    printf("%d\n",res);
  }

  return 0;
}

void div(int p){
  int a0n=0,a1n=0,b0n=0,b1n=0;
  while(a0%p==0) a0/=p,a0n++;
  while(a1%p==0) a1/=p,a1n++; //gcd(x,a0)=a1
  while(b0%p==0) b0/=p,b0n++;
  while(b1%p==0) b1/=p,b1n++; //lcm(x,b0)=b1

  //若 a0n>a1n ，xn=a1n
  //若 a0n=a1n ，xn>=a1n
  //若 a0n<a1n ，无解

  //若 b0n<b1n ，xn=b1n
  //若 b0n=b1n ，xn<=b1n
  //若 b0n>b1n ，无解

  if(a0n<a1n || b0n>b1n)  //无解 && 无解
    res=0;
  else if(a0n>a1n && b0n<b1n) //xn==a1n && xn==b1n
    if(a1n==b1n) res*=1;
    else res=0;
  else if(a0n>a1n && b0n==b1n)  //xn==a1n && xn<=b1n
    if(a1n<=b1n) res*=1;
    else res=0;
  else if(a0n==a1n && b0n<b1n)  //xn>=a1n && xn==b1n
    if(b1n>=a1n) res*=1;
    else res=0;
  else
    if(a1n<=b1n) res*=(b1n-a1n+1);  //xn>=a1n && xn<=b1n
    else res=0;
}
inline bool isprime(int n){ //不判断偶数
  int sq=sqrt(n)+0.5;
  for(int i=3;i<=sq;i+=2) if(n%i==0) return false;
  return true;
}




































/*
//暴力+优化版
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long unsigned LLU;
const int MAX=5000;
int check[MAX+1][MAX+1];

inline int gcd(int a, int b){
  if(a<=MAX && b<=MAX) return check[a][b] ? check[a][b] : (check[a][b] = b==0 ? a : gcd(b,a%b));
  else return b==0 ? a : gcd(b,a%b);
}
inline LLU lcm(int a, int b){
  return 1LL*a*b/gcd(a,b);
}

int main(void){
  int n; scanf("%d",&n);
  int a0,a1,b0,b1;
  while(n--){
    scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
    if(b1%b0 || b1%a1 || a0%a1) printf("0\n");
    else{
      //[1]枚举b1的约数
      //int cnt=0,sq=sqrt(b1)+0.5;
      //for(int i=1;i<=sq;i++) if(b1%i==0){ //<b>从1开始枚举，不能从a1开始</b>，因为在每一次枚举时，事实上枚举了两个数：i和b1/i
      //  if(gcd(i,a0)==a1 && lcm(i,b0)==b1) cnt++;
      //  if(i*i!=b1 && gcd(b1/i,a0)==a1 && lcm(b1/i,b0)==b1) cnt++;
      //}

      //[2]枚举 x=m*a1 中的m
      int mn=b1/a1,cnt=0;
      int sq=sqrt(mn)+0.5;
      for(int m=1;m<=sq;m++) if(mn%m==0){
        int x=m*a1;
        if(gcd(x,a0)==a1 && lcm(x,b0)==b1) cnt++;
        if(m*m!=mn){
          x=mn/m*a1;
          if(gcd(x,a0)==a1 && lcm(x,b0)==b1) cnt++;
        }
      }
      printf("%d\n",cnt);
    }
  }

  return 0;
}
*/
