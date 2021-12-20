/*
题目描述
我们可以用这样的方式来表示一个十进制数: 将每个阿拉伯数字乘以一个以该数字所处位置的(值减1)为指数,以10为底数的幂之和的形式。例如:123可表示为 1*10^2+2*10^1+3*10^0这样的形式。
与之相似的,对二进制数来说,也可表示成每个二进制数码乘以一个以该数字所处位置的(值-1)为指数,以2为底数的幂之和的形式。
一般说来,任何一个正整数R或一个负整数-R都可以被选来作为一个数制系统的基数。如果是以R或-R为基数,则需要用到的数码为 0,1,....R-1。例如,当R=7时,所需用到的数码是 0,1,2,3,4,5和6 ，这与其是R或-R无关。如果作为基数的数绝对值超过10,则为了表示这些数码,通常使用英文字母来表示那些大于9的数码。例如对16进制数来说,用A表示10,用B表示11,用C表示12,用D表示13,用E表示14,用F表示15。
在负进制数中是用-R 作为基数,例如-15(十进制)相当于110001(-2进制),并且它可以被表示为2的幂级数的和数：
  110001=1*(-2)^5+1*(-2)^4+0*(-2)^3+0*(-2)^2+0*(-2)^1 +1*(-2)^0
设计一个程序,读入一个十进制数和一个负进制数的基数, 并将此十进制数转换为此负进制下的数: -20<=-R<=-2

输入输出格式
输入格式：
输入的每行有两个输入数据。
第一个是十进制数n（－32768<=N<=32767）； 第二个是负进制数的基数-R。

输出格式：
结果显示在屏幕上，相对于输入，应输出此负进制数及其基数，若此基数超过10，则参照16进制的方式处理。

输入输出样例
输入样例#1：
30000 -2

输出样例#1：
30000=11011010101110000(base-2)

输入样例#2：
-20000 -2

输出样例#2：
-20000=1111011000100000(base-2)

输入样例#3：
28800 -16

输出样例#3：
28800=19180(base-16)

输入样例#4：
-25000 -16

输出样例#4：
-25000=7FB8(base-16)

说明
NOIP2000提高组第一题
*/


//枚举解法（效率较低）
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int check[24][40];  //check[i][j]: (-i)^j
int cur[40],save[40],len;
int R,n;
bool flag=0;
char out[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

void Generate(int R, int step); //对于-R进制，假设n(-R)的长为step
inline void Print();
inline int Sum();

int main(void){
  for(int i=2;i<=20;i++) check[i][0]=1;
  for(int i=2;i<=20;i++) for(int j=1;j<40;j++){
    check[i][j]=check[i][j-1]*(-i);
    if(abs(check[i][j]) > (1<<17)) break;
  }
  scanf("%d%d",&n,&R);
  for(len=1;len<40;len++){  //枚举n(-R)的长度
    Generate(-R,0);
    if(flag) break;
  }
  printf("%d=",n); Print(); printf("(base%d)\n",R);

  return 0;
}

void Generate(int R, int step){
  if(step==len){
    int sum=Sum();
#ifdef DEBUG
    printf("  "); Print(); printf(", sum: %d, %d\n",sum,(int)sum==n);
#endif
    if(sum==n){
      memcpy(save,cur,sizeof(save)); flag=1;
    }
    return;
  }
  for(int i=0;i<R;i++){
    cur[step]=i;
    Generate(R,step+1);
  }
}
inline void Print(){
  for(int i=len-1;i>=0;i--)
    printf("%c",out[save[i]]);
}
inline int Sum(){
  int r=-R;
  int sum=0;
  for(int i=0;i<len;i++)
    sum+=cur[i]*check[r][i];
  return sum;
}
