/*
题目描述
设有n个正整数（n≤20），将它们联接成一排，组成一个最大的多位整数。
例如：n=3时，3个整数13，312，343联接成的最大整数为：34331213
又如：n=4时，4个整数7，13，4，246联接成的最大整数为：7424613

输入输出格式
输入格式：
第一行，一个正整数n。
第二行，n个正整数。

输出格式：
一个正整数，表示最大的整数

输入输出样例
输入样例#1：
3
13 312 343

输出样例#1：
34331213
*/

/*
  注意：不能依照字典序排列，应该两两比较，即对于两个字符串s1,s2，应比较s1+s2和s2+s1的大小。
    例子：1.对于 321,32，如果按降序字典序，则是 32132 ，但最大应该是 32321
          2. 321 32 407 135 13 217
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

struct Node{
  char s[100];
  bool operator < (const Node & b) const {  //<b>
    char t1[200],t2[200];
    strcpy(t1,s); strcpy(t2,b.s);
    strcat(t1,b.s); strcat(t2,b.s);
    return strcmp(t1,t2)>0;
  }                                         //</b>
}a[24];

int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%s",a[i].s);
  sort(a,a+n);
  for(int i=0;i<n;i++) printf("%s",a[i].s); printf("\n");

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node{
  char str[200];

  bool operator < (const Node & b) const {
    return strcmp(str,b.str)>0;
  }
}ori[24];

int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%s",ori[i].str);
  sort(ori,ori+n);
  for(int i=0;i<n;i++) printf("%s",ori[i].str);
  printf("\n");

  return 0;
}
*/
