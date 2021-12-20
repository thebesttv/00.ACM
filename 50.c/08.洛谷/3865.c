/*
题目背景
这是一道ST表经典题——静态区间最大值
请注意最大数据时限只有0.8s，数据强度不低，请务必保证你的每次查询复杂度为 O(1)

题目描述
给定一个长度为 N 的数列，和 M 次询问，求出每一次询问的区间内数字的最大值。

输入输出格式
输入格式：
第一行包含两个整数 N, M，分别表示数列的长度和询问的个数。
第二行包含 N 个整数ai，依次表示数列的第 i 项。
接下来 M 行，每行包含两个整数 li,ri ，表示查询的区间为 [li,ri]。

输出格式：
输出包含 M 行，每行一个整数，依次表示每一次询问的结果。

输入输出样例
输入样例#1：
8 8
9 3 1 7 5 6 0 8
1 6
1 5
2 7
2 6
1 8
4 8
3 7
1 8

输出样例#1：
9
9
7
7
9
8
7
9

说明
对于100%的数据，满足：1<=n<=10^5, 1<=m<=10^6, 0<=a<=10^9。
*/

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

const int MAX=100020;
int n,m,a[MAX];
int f[MAX][18],lg[MAX];

//f[i][j]: max{a[i : i+2^j-1]}
// f[i][j] = max( f[i][j-1], f[i+2^(j-1)][j-1] )

int query(int l, int r){
  int k=lg[r-l+1];
  return max(f[l][k],f[r-(1<<k)+1][k]); // x + 2^k -1 = r, x = r - 2^k + 1
}

int main(void){
  for(int i=2;i<MAX;i<<=1) lg[i]=1;
  FOR(i,3,MAX) lg[i]+=lg[i-1];

  scanf("%d%d",&n,&m);
  FORR(i,1,n) {scanf("%d",&a[i]); f[i][0]=a[i];}
  ROR(i,n,1) FOR(j,1,18)
    if(i+(1<<j)-1<=n) f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    else break;

  int l,r;
  FOR(i,0,m){
    scanf("%d%d",&l,&r);
    printf("%d\n",query(l,r));
  }

  return 0;
}

/*
const int MAX=100020;
int n,m,a[MAX],f[MAX][17];
int lg[MAX];

int s_max(int l, int r){
  int k=lg[r-l+1];
  return max( f[l][k], f[r+1-(1<<k)][k] );
}

int main(void){
  for(RE int i=2;i<MAX;i<<=1) lg[i]=1;
  int *p=&lg[3];
  FOR(i,3,MAX) {*p+=*(p-1); p++;}

  scanf("%d%d",&n,&m);
  FORR(i,1,n) {scanf("%d",&a[i]); f[i][0]=a[i];}
  ROR(i,n,1) for(RE int j=1;i+(1<<j)-1<=n;j++)
    f[i][j] = max(f[i][j-1],f[ i+(1<<(j-1)) ][j-1]);

  int l,r;
  FOR(i,0,m){
    scanf("%d%d",&l,&r);
    printf("%d\n",s_max(l,r));
  }

  return 0;
}
*/

/*
const int MAX=100020;
int n,m,a[MAX],f[MAX][17];

int s_max(int l, int r){
  int k = log(r-l+1)/log(2);
  return max( f[l][k], f[r+1-(1<<k)][k] );
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) {scanf("%d",&a[i]); f[i][0]=a[i];}
  ROR(i,n,1) for(RE int j=1;i+(1<<j)-1<=n;j++)
    f[i][j] = max(f[i][j-1],f[ i+(1<<(j-1)) ][j-1]);

  int l,r;
  FOR(i,0,m){
    scanf("%d%d",&l,&r);
    printf("%d\n",s_max(l,r));
  }

  return 0;
}
*/
