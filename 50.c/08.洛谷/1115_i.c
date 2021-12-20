/*
题目描述
给出一段序列，选出其中连续且非空的一段使得这段和最大。

输入输出格式
输入格式：
输入文件maxsum1.in的第一行是一个正整数N，表示了序列的长度。
第2行包含N个绝对值不大于10000的整数A[i]，描述了这段序列。

输出格式：
输入文件maxsum1.out仅包括1个整数，为最大的子段和是多少。子段的最小长度为1。

输入输出样例
输入样例#1：
7
2 -4 3 -1 2 -4 3

输出样例#1：
4

数据规模与约定
对于40%的数据，有N ≤ 2000。
对于100%的数据，有N ≤ 200000。
*/

/*
  解题报告：
    这还是从哪年初赛里学到的，竟然是用DP。
    令 f[i] 表示以a[i]结尾的最大连续子段和，对每个f[i]共有两种决策：选a[i]和不选a[i]
    则 f[i] = max{ f[i-1]+a[i], a[i] }
    这样就可以O(n)求出最大连续子段和了。
    而且还可以使用滚动数组优化，这样就可以在O(n)时间和O(1)空间内求出答案。
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

//滚动数组优化
const int MAX=200020;
const int INF=0x3f3f3f3f;
int n,f;

int main(void){
  scanf("%d",&n);
  int ansMax=-INF,t;
  FORR(i,1,n){
    scanf("%d",&t); f=max(f+t,t);
    ansMax=max(ansMax,f);
  }
  printf("%d\n",ansMax);

  return 0;
}

/*
//DP
const int MAX=200020;
const int INF=0x3f3f3f3f;
int n,f[MAX];

int main(void){
  scanf("%d",&n);
  int ansMax=-INF,t;
  FORR(i,1,n){
    scanf("%d",&t);
    f[i]=max(f[i-1]+t,t);
    ansMax=max(ansMax,f[i]);
  }
  printf("%d\n",ansMax);

  return 0;
}
*/
