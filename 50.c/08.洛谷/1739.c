/*
题目描述
假设一个表达式有英文字母（小写）、运算符（+，—，*，/）和左右小（圆）括号构成，以“@”作为表达式的结束符。请编写一个程序检查表达式中的左右圆括号是否匹配，若匹配，则返回“YES”；否则返回“NO”。表达式长度小于255，左圆括号少于20个。

输入输出格式

输入格式：
一行：表达式

输出格式：
一行：“YES” 或“NO”

输入输出样例
输入样例#1：
2*(x+y)/(1-x)@

输出样例#1：
YES

输入样例#2：
(25+x)*(a*(a+b+b)@

输出样例#2：
NO

说明
表达式长度小于255，左圆括号少于20个
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout);
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=300;
int st[MAX],top=0;

int main(void){
  int ch; bool flag=1;
  while((ch=getchar())!='@'){
    if(ch=='(') st[top++]=ch;
    else if(ch==')'){
      if(!top) {flag=0; break;}
      else top--;
    }
  }
  if(top) flag=0;
  printf("%s\n",flag ? "YES" : "NO");

  return 0;
}
