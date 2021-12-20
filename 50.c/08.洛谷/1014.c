/*
题目描述
现代数学的著名证明之一是Georg Cantor证明了有理数是可枚举的。他是用下面这一张表来证明这一命题的：
1/1 1/2 1/3 1/4 1/5 …
2/1 2/2 2/3 2/4 …
3/1 3/2 3/3 …
4/1 4/2 …
5/1 …
…
我们以Z字形给上表的每一项编号。第一项是1/1，然后是1/2，2/1，3/1，2/2，…

输入输出格式
输入格式：
整数N（1≤N≤10000000）

输出格式：
表中的第N项

输入输出样例
输入样例#1：
7

输出样例#1：
1/4
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int MAX_SUM=4500;
int sum[MAX_SUM];

int Get(int n, int line, bool reversed){
  if(!reversed) return n-sum[line-1];
  else return (sum[line]-n+1);
}

int main(void){
  for(int i=1;i<MAX_SUM;i++){
    sum[i]=sum[i-1]+i;
    if(sum[i]>10000000) break;
  }
  int n,line; scanf("%d",&n);
  for(line=1;line<MAX_SUM;line++){
    if(sum[line]>=n) break;
  }
  if(line%2){
    printf("%d/%d\n",Get(n,line,1),Get(n,line,0));
  }else{
    printf("%d/%d\n",Get(n,line,0),Get(n,line,1));
  }

  return 0;
}
