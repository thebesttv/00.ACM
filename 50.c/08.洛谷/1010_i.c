/*
题目描述
任何一个正整数都可以用2的幂次方表示。例如
  137=2^7+2^3+2^0         
同时约定方次用括号来表示，即 a^b 表示为a(b)。那么137可表示为：
  2(7)+2(3)+2(0)
进一步，7=2^2+2+2^0 (2^1用2表示), 3=2+2^0   
所以最后137可表示为：
  2(2(2)+2+2(0))+2(2+2(0))+2(0)
又如：
  1315 = 2^10 +2^8 +2^5 +2+1
所以1315最后可表示为：
  2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

输入输出格式
输入格式：
一个正整数n(n≤20000)。

输出格式：
符合约定的n的0，2表示(在表示中不能有空格)

输入输出样例
输入样例#1：
1315

输出样例#1：
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
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

void print(int n){
  bool first=0;
  ROR(i,30,2) if((n>>i)&1){
    if(!first) first=1;
    else putchar('+');
    printf("2("); print(i); printf(")");
  }
  if(n&2){
    if(!first) first=1;
    else putchar('+');
    printf("2");
  }
  if(n&1){
    if(!first) first=1;
    else putchar('+');
    printf("2(0)");
  }
}

int main(void){
  int n; scanf("%d",&n);
  print(n); putchar('\n');

  return 0;
}

/*
int Break(bool * a, int n){
  int cou=0;  //(n)2中“1”的个数
  for(int i=0;i<20;i++){
    a[i] = (n>>i)&1;
    if(a[i]) cou++;
  }
  return cou;
}
void Print(int n){
	bool check[20]; //check[i]=1: n含有2^i
  int cou=Break(check,n);
  int t=0;
  for(int i=19;i>=3;i--) if(check[i]){
    printf("2(");
    Print(i); t++;
    printf(")");
    if(t<cou) printf("+");
  }
  if(check[2]){
    printf("2(2)"); t++;
    if(t<cou) printf("+");
  }
  if(check[1]){
    printf("2"); t++;
    if(t<cou) printf("+");
  }
  if(check[0]){
    printf("2(0)"); t++;
  }
}

int main(void){
  int n; scanf("%d",&n);
  Print(n); printf("\n");

  return 0;
}
*/
