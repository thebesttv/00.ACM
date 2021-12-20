/*
题目描述
一元 n 次多项式可用如下的表达式表示：
  f(x) = an*x^n + a(n-1)*x^(n-1) + ... + a1*x + a0
其中，ai*xi 称为 i 次项，ai 称为 i 次项的系数。给出一个一元多项式各项的次数和系数，请按照如下规定的格式要求输出该多项式：
  1. 多项式中自变量为 x，从左到右按照次数递减顺序给出多项式。
  2. 多项式中只包含系数不为 0 的项。
  3. 如果多项式 n 次项系数为正，则多项式开头不出现“+”号，如果多项式 n 次项系数为负，则多项式以“-”号开头。
  4. 对于不是最高次的项，以“+”号或者“-”号连接此项与前一项，分别表示此项系数为正或者系数为负。紧跟一个正整数，表示此项系数的绝对值（如果一个高于 0 次的项，其系数的绝对值为 1，则无需输出 1）。如果 x 的指数大于 1，则接下来紧跟的指数部分的形式为“x^b”，其中 b 为 x 的指数；如果 x 的指数为 1，则接下来紧跟的指数部分形式为“x”；如果 x 的指数为 0，则仅需输出系数即可。
  5. 多项式中，多项式的开头、结尾不含多余的空格。

输入输出格式
输入格式：
输入共有 2 行
第一行 1 个整数，n(0<=n<=100)，表示一元多项式的次数。
第二行有 n+1 个整数，其中第 i 个整数表示第 n-i+1 次项的系数，每两个整数之间用空
格隔开。

输出格式：
输出共 1 行，按题目所述格式输出多项式。

输入输出样例

输入样例#1：
5 
100 -1 1 -3 0 10

输出样例#1：
100x^5-x^4+x^3-3x^2+10

输入样例#2：
3 
-50 0 0 1 

输出样例#2：
-50x^3+1 

说明
NOIP 2009 普及组 第一题
对于100%数据，0<=n<=100,-100<=系数<=100
*/

#include<iostream>
#include<cstdio>
using namespace std;

int main(void){
  int n,temp; scanf("%d",&n);
  for(int i=0;i<=n;i++){
    scanf("%d",&temp);
    if(!temp) continue;
    if(i==n){
      if(temp>0 && i!=0) printf("+%d",temp);
      else printf("%d",temp);
    }else if(i==0){
      if((n-i)!=1){
        if(temp==1) printf("x^%d",n-i);
        else if(temp==-1) printf("-x^%d",n-i);
        else printf("%dx^%d",temp,n-i);
      }else{
        if(temp==1) printf("x");
        else if(temp==-1) printf("-x");
        else printf("%dx",temp);
      }
    }else{
      if((n-i)!=1){
        if(temp==1) printf("+x^%d",n-i);
        else if(temp>0) printf("+%dx^%d",temp,n-i);
        else if(temp==-1) printf("-x^%d",n-i);
        else printf("%dx^%d",temp,n-i);
      }else{
        if(temp==1) printf("+x");
        else if(temp>0) printf("+%dx",temp);
        else if(temp==-1) printf("-x");
        else printf("%dx",temp);
      }
    }
  }
  printf("\n");

  return 0;
}
