/*
描述
在初赛普及组的“阅读程序写结果”的问题中，我们曾给出一个字符串展开的例子：如果在输入的字符串中，含有类似于“d-h”或者“4-8”的字串，我们就把它当作一种简写，输出时，用连续递增的字母获数字串替代其中的减号，即，将上面两个子串分别输出为“defgh”和“45678”。在本题中，我们通过增加一些参数的设置，使字符串的展开更为灵活。具体约定如下：
  遇到下面的情况需要做字符串的展开：在输入的字符串中，出现了减号“-”，减号两侧同为小写字母或同为数字，且按照ASCII码的顺序，减号右边的字符严格大于左边的字符。
  参数p1：展开方式。p1=1时，对于字母子串，填充小写字母；p1=2时，对于字母子串，填充大写字母。这两种情况下数字子串的填充方式相同。p1=3时，不论是字母子串还是数字字串，都用与要填充的字母个数相同的星号“*”来填充。
  参数p2：填充字符的重复个数。p2=k表示同一个字符要连续填充k个。例如，当p2=3时，子串“d-h”应扩展为“deeefffgggh”。减号两边的字符不变。
  参数p3：是否改为逆序：p3=1表示维持原来顺序，p3=2表示采用逆序输出，注意这时候仍然不包括减号两端的字符。例如当p1=1、p2=2、p3=2时，子串“d-h”应扩展为“dggffeeh”。
如果减号右边的字符恰好是左边字符的后继，只删除中间的减号，例如：“d-e”应输出为“de ”，“3-4”应输出为“34”。如果减号右边的字符按照ASCII码的顺序小于或等于左边字符，输出 时，要保留中间的减号，例如：“d-d”应输出为“d-d”，“3-1”应输出为“3-1”。

格式
输入格式
包括两行：
第1行为用空格隔开的3个正整数，一次表示参数p1，p2，p3。
第2行为一行字符串，仅由数字、小写字母和减号“-”组成。行首和行末均无空格。

输出格式
只有一行，为展开后的字符串。

样例
样例输入1
1 2 1
abcs-w1234-9s-4zz

样例输出1
abcsttuuvvw1234556677889s-4zz

样例输入2（自行添加）
1 1 1
a-b-c

样例输出2
abc

限制
1s
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

int p1,p2,p3;
char temp[1000];

void spread(char x, char y){
  if(isdigit(x) && isdigit(y)){
    if(x>=y) printf("%c-",x);
    else if(x+1==y) printf("%c",x);
    else{
      printf("%c",x);
      if(p3==1){
        for(char i=x+1;i<y;i++) for(int j=0;j<p2;j++) printf("%c",(p1==3 ? '*' : i));
      }else{
        for(char i=y-1;i>x;i--) for(int j=0;j<p2;j++) printf("%c",(p1==3 ? '*' : i));
      }
    }
  }else if(islower(x) && islower(y)){
    if(x>=y) printf("%c-",x);
    else if(x+1==y) printf("%c",x);
    else{
      printf("%c",x);
      if(p3==1){
        for(char i=x+1;i<y;i++) for(int j=0;j<p2;j++) printf("%c",(p1==3 ? '*' : (p1==2 ? toupper(i) : tolower(i))));
      }else{
        for(char i=y-1;i>x;i--) for(int j=0;j<p2;j++) printf("%c",(p1==3 ? '*' : (p1==2 ? toupper(i) : tolower(i))));
      }
    }
  }else{
    printf("%c-",x);
  }
}

int main(void){
  scanf("%d%d%d",&p1,&p2,&p3);
  scanf("%s",temp);
  int len=strlen(temp);
  int pos=0;
  while(pos<len){
    if(pos+2<len && isalnum(temp[pos]) && temp[pos+1]=='-' && isalnum(temp[pos+2])){
      spread(temp[pos],temp[pos+2]); pos+=2;
    }else{
      printf("%c",temp[pos++]);
    }
  }
  printf("\n");

  return 0;
}

/*
  得分：70
  解题报告：
    模拟。
    考试时没想清楚，没有想到两个展开连在一起的情况：
      1 1 1
      a-b-c
    输出应该为：
      abc
    但我写的程序输出为：
      ab-c
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

int p1,p2,p3;
char temp[1000];

void spread(char x, char y){
  if(isdigit(x) && isdigit(y)){
    if(x>=y) printf("%c-%c",x,y);
    else if(x+1==y) printf("%c%c",x,y);
    else{
      printf("%c",x);
      if(p3==1){
        for(char i=x+1;i<y;i++) for(int j=0;j<p2;j++) printf("%c",(p1==3 ? '*' : i));
      }else{
        for(char i=y-1;i>x;i--) for(int j=0;j<p2;j++) printf("%c",(p1==3 ? '*' : i));
      }
      printf("%c",y);
    }
  }else if(islower(x) && islower(y)){
    if(x>=y) printf("%c-%c",x,y);
    else if(x+1==y) printf("%c%c",x,y);
    else{
      printf("%c",x);
      if(p3==1){
        for(char i=x+1;i<y;i++) for(int j=0;j<p2;j++) printf("%c",(p1==3 ? '*' : (p1==2 ? toupper(i) : tolower(i))));
      }else{
        for(char i=y-1;i>x;i--) for(int j=0;j<p2;j++) printf("%c",(p1==3 ? '*' : (p1==2 ? toupper(i) : tolower(i))));
      }
      printf("%c",y);
    }
  }else{
    printf("%c-%c",x,y);
  }
}

int main(void){
  scanf("%d%d%d",&p1,&p2,&p3);
  scanf("%s",temp);
  int len=strlen(temp);
  int pos=0;
  while(pos<len){
    if(pos+2<len && isalnum(temp[pos]) && temp[pos+1]=='-' && isalnum(temp[pos+2])){
      spread(temp[pos],temp[pos+2]); pos+=3;
    }else{
      printf("%c",temp[pos++]);
    }
  }
  printf("\n");

  return 0;
}
*/
