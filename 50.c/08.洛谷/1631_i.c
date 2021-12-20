/*
题目描述
有两个长度都是N的序列A和B，在A和B中各取一个数相加可以得到N^2个和，求这N^2个和中最小的N个。

输入输出格式
输入格式：
第一行一个正整数N；
第二行N个整数Ai,满足Ai<=Ai+1且Ai<=10^9;
第三行N个整数Bi, 满足Bi<=Bi+1且Bi<=10^9.

数据规模
对于50%的数据中，满足1<=N<=1000；
对于100%的数据中，满足1<=N<=100000。

输出格式：
输出仅一行，包含N个整数，从小到大输出这N个最小的和，相邻数字之间用空格隔开。

输入输出样例
输入样例#1：
3
2 6 6
1 4 8

输出样例#1：
3 6 7
*/

/*
  解题报告： 
    想到了二分 yeah
    二分a[i]+b[j]的最大值，如果满足最大值的a[i]+b[j]个数>=n，则最大值可能要更小，如果不满足，则一定要更大。
    最大值是2*10^9，二分不会超过30次。 
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

const int MAX=100020;
int a[MAX],b[MAX],res[MAX],n;

bool ok(int tMax){
  int cnt=0;
  FOR(i,0,n){
    FOR(j,0,n)
      if(a[i]+b[j]<=tMax) cnt++;
      else break;
    if(cnt>=n) return true;
  }
  return cnt>=n;
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  FOR(i,0,n) scanf("%d",&b[i]);
  int l=a[0]+b[0],r=a[n-1]+b[n-1];
  while(l<r){
    int m=l+(r-l)/2;
    if(ok(m)) r=m;
    else l=m+1;
  }
  int tail=0;
  FOR(i,0,n){
    FOR(j,0,n)
      if(a[i]+b[j]<=l) res[tail++]=a[i]+b[j];
      else break;
    //if(tail>=n) break;
  }
  sort(res,res+tail);
  FOR(i,0,n) printf("%d ",res[i]); printf("\n");

  return 0;
}
