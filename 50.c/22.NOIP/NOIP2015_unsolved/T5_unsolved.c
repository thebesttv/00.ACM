/*
描述
有两个仅包含小写英文字母的字符串 A 和 B。现在要从字符串 A 中取出 k 个**互不重叠**的非空子串，然后把这 k 个子串按照其在字符串 A 中出现的顺序依次连接起来得到一 个新的字符串，请问有多少种方案可以使得这个新串与字符串 B 相等？注意：子串取出的位置不同也认为是不同的方案。

格式
输入格式
第一行是三个正整数 n，m，k，分别表示字符串 A 的长度，字符串 B 的长度，以及问 题描述中所提到的 k，每两个整数之间用一个空格隔开。第二行包含一个长度为 n 的字符串，表示字符串 A。 第三行包含一个长度为 m 的字符串，表示字符串 B。

输出格式
输出共一行，包含一个整数，表示所求方案数。由于答案可能很大，所以这里要求输 出答案对 1,000,000,007 取模的结果。

样例1
样例输入1
6 3 1
aabaab
aab

样例输出1
2

样例2
样例输入2
6 3 2
aabaab
aab

样例输出2
7

样例3
样例输入3
6 3 3
aabaab
aab

样例输出3
7

限制
对于第 1 组数据：1≤n≤500，1≤m≤50，k=1；
对于第 2 组至第 3 组数据：1≤n≤500，1≤m≤50，k=2；
对于第 4 组至第 5 组数据：1≤n≤500，1≤m≤50，k=m；
对于第 1 组至第 7 组数据：1≤n≤500，1≤m≤50，1≤k≤m；
对于第 1 组至第 9 组数据：1≤n≤1000，1≤m≤100，1≤k≤m；
对于所有 10 组数据：1≤n≤1000，1≤m≤200，1≤k≤m。

提示
样例1:
  aab,xxx
  xxx,aab
样例2:
  a,ab,xxx
  a,xxx,ab
  x,a,xx,ab
  xxx,a,ab
  aa,b,xxx
  aa,xxx,b
  xxx,aa,b
样例3:
  a,a,b,xxx
  a,a,xxx,b
  a,xxx,a,b
  a,xx,a,x,b
  xxx,a,a,b
  x,a,x,a,b
  x,a,xx,a,b

来源
NOIP 2015 提高组 Day 2 第二题
*/

/*
  得分：30
  解题报告：
    想到了动规，然而并没有写对。。。
  正解：
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

typedef long long unsigned LLU;
const int MAXN=1020;
const int MAXM=120; //
const int MOD=1000000007;
int check[MAXN][MAXM][MAXM];
  //f[i][j][k]: 在A的前i个中挑选，共选则k块，且最后一块一定包含A[i-1]，配到B中前j个，即 A[0:i-1]中k块 = B[0:j-1]
  //f[i][j][k] = sum{ f[a][j-b][k-1] | A[a:a+b-1]=B[j-b:j-1], j-b>=k-1, 0<a<i }
//O(n*m*m)
int n,m,K;
char A[MAXN],B[MAXM];
//bool ok[MAXN][MAXM];

int f(int i, int j, int k){
  if(i<=0 || j<=0 || k<=0 || j>i) return 0;
  int & a=check[i][j][k];
  /*
  if(a!=-1) return a;
  if(k==1){
    LLU cnt=0;
    int t=i-j;
    FORR(aa,0,t) if(!strncmp(A+aa,B,j)) cnt++;
    a=cnt%MOD;
  }else if(A[i-1]!=B[j-1]){
    a=0;
  }else{
    LLU ans=0; int t=j-k+1;
    FOR(aa,1,i) FORR(b,1,t) if(!strncmp(A+aa,B+j-b,b)){
      ans+=f(aa,j-b,k-1);
      printf("    f[%d][%d][%d] updated by f[%d][%d][%d]=%d, ans: %llu\n",i,j,k,aa,j-b,k-1,f(aa,j-b,k-1),ans);
    }
    a=ans%MOD;
  }
  */
  if(a!=-1) return a;
  if(k==1){
    LLU cnt=0;
    int t=i-j;
    FORR(aa,0,t) if(!strncmp(A+aa,B,j)) cnt++;
    a=cnt%MOD;
  }else{
    LLU ans=0; int t=j-k+1;
    FORR(aa,1,i) FORR(b,1,t) if(!strncmp(A+aa,B+j-b,b)){
      ans+=f(aa,j-b,k-1);
      //printf("    f[%d][%d][%d] updated by f[%d][%d][%d]=%d, ans: %llu\n",i,j,k,aa,j-b,k-1,f(aa,j-b,k-1),ans);
    }
    a=ans%MOD;
  }
#ifdef DEBUG
  printf("  f[%d][%d][%d]: %d\n",i,j,k,a);
#endif
  return a;
}

int main(void){
  scanf("%d%d%d",&n,&m,&K);
  scanf("%s%s",A,B);

  MST(check,-1);
  /*
  LLU ans=0;
  FORR(i,m,n) ans+=f(i,m,K);
  ans%=MOD;
  printf("%llu\n",ans);
  */
  if(K==1){
    int cnt=0;
    FOR(i,0,n) if(!strncmp(A+i,B,m)) cnt++;
    printf("%d\n",cnt%MOD);
  //}else if(K==2){
  //}else if(K==m){
  }else printf("%d\n",f(n,m,K));

  return 0;
}
