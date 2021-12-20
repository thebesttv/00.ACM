/*
题目描述
请注意本题的空间限制为2333-2500KB！（前三个测试点的空间限制为2500KB）
给定两个长度相同的序列，这两个序列至多有 1 处不同。你的任务是找出这处不同。

输入输出格式
输入格式：
第一行包含一个数据组数 T。每组数据的格式如下：
第一行一个整数 n 表示序列的长度。
接下来两行表示两个长度均为 n 的序列 A 和 B，保证所有数字均为小于 2^32 的非负整数，这些数字可以看做是随机的。

输出格式：
输出共 T 行，每行第一个数 m≤1 表示不同的数目。接下来 m 个数表示两个序列中不同的位置。

输入输出样例
输入样例#1：
2
4
2 3 3 3
2 3 6 3
8
9 1 6 2 8 0 
9 1 6 2 0 0 

输出样例#1：
1 3
1 5

数据范围
对于100%的数据，n<=10^6, T<=5, sum{n}<=2*10^6。
*/

/*
  得分：20
  解题报告：
    仿佛第一次做到真正的数论题。。。
    一开始我看到随机，想只记录每个数的几个比特位，结果又WA又MLE了。。。
  正解：
    好吧这不是第一次了。。。但我开始不会。。。
    令 s1 = sum{ i*ai }, s2 = sum{ i*bi }，因为最多只有一个数不一样，则
      d1 = s1 - s2 = j*(aj-bj), aj!=bj
    但因为要求出j，则又令 ps1 = sum{ i*i*ai }, ps2 = sum{ i*i*bi }，那么
      d2 = ps1 - ps2 = j*j*(aj-bj), aj!=bj
    那么 d2/d1 即为 j 。
    但累加的和会很大，因此要使用高精度或在模意义下计算。
    高精是没什么好说的，又比较low XD，就说模意义下的计算吧。
    首先，MOD一定要大于n且为素数，如果小于n则不能判断j的唯一位置，如果非素数则不能用exgcd求逆元。令MOD为一个大素数即可。
    因为在模意义下，除n等于乘n的逆元，那么 d2/d1 = d2 * d1^(-1)
    调用 gcd(d2,MOD,d,x,y)，求出的x即为d1的逆元。
    然后答案即为 d1*((x+MOD)%MOD)%MOD 。
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

const int MOD=10000007;
int n;
LL s1,s2,ps1,ps2;

void gcd(int a, int b, int & d, int & x, int & y){
  if(!b) {d=a; x=1; y=0;}
  else {gcd(b,a%b,d,y,x); y-=x*(a/b);}
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    s1=s2=ps1=ps2=0;
    scanf("%d",&n);
    int t;
    for(LL i=1;i<=n;i++){
      scanf("%d",&t); t%=MOD;
      (s1+=i*t)%=MOD;
      (ps1+=i*i%MOD*t%MOD)%=MOD;
    }
    for(LL i=1;i<=n;i++){
      scanf("%d",&t); t%=MOD;
      (s2+=i*t)%=MOD;
      (ps2+=i*i%MOD*t%MOD)%=MOD;
    }
    int d1=(s1-s2+MOD)%MOD,d2=(ps1-ps2+MOD)%MOD;
    if(d1==0) {printf("0\n"); continue;}
    int d,x,y;
    //d2/d1 = d2 * d1^(-1) mod m
    gcd(d1,MOD,d,x,y); x=(x+MOD)%MOD;
    printf("1 %d\n",(int)(1LL*d2*x%MOD));
  }

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
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

typedef int unsigned IU;
const int MAX=100000;
int n;
IU rec[MAX+20];

inline IU cal(IU n){ //取四位
  int ans=0;
  ans|=(n&1);
  ans|=((n>>10)&1)<<1;
  ans|=((n>>20)&1)<<2;
  ans|=((n>>30)&1)<<3;
  return ans;
}
void solve1();
void solve2();

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(rec,0);
    scanf("%d",&n);

    if(n<=MAX) solve1();
    else solve2();
  }

  return 0;
}

void solve1(){
  IU t; bool flag=0;
  FORR(i,1,n) scanf("%u",&rec[i]);
  FORR(i,1,n){
    scanf("%u",&t);
    if(t!=rec[i]) flag=1,printf("%d %d\n",1,i);
  }
  if(!flag) printf("%d\n",0);
}
void solve2(){
  IU t;
  RE int cnt=0;
  FOR(i,0,n){
    scanf("%u",&t);
    rec[i>>3]|=cal(t)<<(cnt<<2);
    cnt = cnt+1==8 ? 0 : cnt+1;
  }
  RE int a,com; cnt=0;
  bool flag=0;
  FOR(i,0,n){
    scanf("%u",&t);
    a=cal(t);
    com = ( rec[i>>3]>>(cnt<<2) ) & 15;
    if(a!=com){
      if(flag) continue;
      flag=1; printf("%d %d\n",1,i+1);
    }
    cnt = cnt+1==8 ? 0 : cnt+1;
  }
  if(!flag) printf("%d\n",0);
}
*/
