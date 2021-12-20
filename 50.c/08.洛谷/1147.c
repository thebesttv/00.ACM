/*
题目描述
对一个给定的自然数M，求出所有的连续的自然数段，这些连续的自然数段中的全部数之和为M。
例子：1998+1999+2000+2001+2002 = 10000，所以从1998到2002的一个自然数段为M=10000的一个解。

输入输出格式
输入格式：
包含一个整数的单独一行给出M的值（10 <= M <= 2,000,000）。

输出格式：
每行两个自然数，给出一个满足条件的连续自然数段中的第一个数和最后一个数，两数之间用一个空格隔开，所有输出行的第一个按从小到大的升序排列，对于给定的输入数据，保证至少有一个解。

输入输出样例
输入样例#1：
10000

输出样例#1：
18 142 
297 328 
388 412 
1998 2002
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

const int MAX=2000000;
int s[MAX+20];

int main(void){
  FORR(i,1,MAX) s[i]=s[i-1]+i;
  int n; scanf("%d",&n);
  int t;
  FOR(i,1,n) FOR(j,i+1,n){
    t=s[j]-s[i-1];
    if(t>n) break;
    else if(t==n) printf("%d %d\n",i,j);
  }


  return 0;
}
