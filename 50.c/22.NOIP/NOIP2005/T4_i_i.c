/*
描述
明明进了中学之后，学到了代数表达式。有一天，他碰到一个很麻烦的选择题。这个题目的题干中首先给出了一个代数表达式，然后列出了若干选项，每个选项也是一个代数表达式，题目的要求是判断选项中哪些代数表达式是和题干中的表达式等价的。
这个题目手算很麻烦，因为明明对计算机编程很感兴趣，所以他想是不是可以用计算机来解决这个问题。假设你是明明，能完成这个任务吗？
这个选择题中的每个表达式都满足下面的性质：
  1.表达式只可能包含一个变量‘a’。
  2.表达式中出现的数都是正整数，而且都小于10000。
  3.表达式中可以包括四种运算‘+’（加），‘-’（减），‘*’（乘），‘^’（乘幂），以及小括号‘(’，‘)’。小括号的优先级最高，其次是‘^’，然后是‘*’，最后是‘+’和‘-’。‘+’和‘-’的优先级是相同的。相同优先级的运算从左到右进行。（注意：运算符‘+’，‘-’，‘*’，‘^’以及小括号‘(’，‘)’都是英文字符）
  4.幂指数只可能是1到10之间的正整数（包括1和10）。
  5.表达式内部，头部或者尾部都可能有一些多余的空格。
下面是一些合理的表达式的例子：

((a^1) ^ 2)^3，a*a+a-a，((a+a))，9999+(a-a)*a，1 + (a -1)^3，1^10^9……

对于30%的数据，表达式中只可能出现两种运算符‘+’和‘-’；
对于其它的数据，四种运算符‘+’，‘-’，‘*’，‘^’在表达式中都可能出现。
对于全部的数据，表达式中都可能出现小括号‘(’和‘)’。

格式
输入格式
输入的第一行给出的是题干中的表达式。第二行是一个整数n（2 <= n <= 26），表示选项的个数。后面n行，每行包括一个选项中的表达式。这n个选项的标号分别是A，B，C，D……
输入中的表达式的长度都不超过50个字符，而且保证选项中总有表达式和题干中的表达式是等价的。

输出格式
输出包括一行，这一行包括一系列选项的标号，表示哪些选项是和题干中的表达式等价的。选项的标号按照字母顺序排列，而且之间没有空格。

样例1
样例输入1
( a + 1) ^2
3
(a-1)^2+4*a
a  + 1+ a
a^2 + 2 * a * 1 + 1^2 + 10 -10 +a -a

样例输出1
AC

限制
1s

来源
NOIp2005 第四题
*/

/*
  得分：70
  解题报告：
    将原表达式转化为后缀表达式，求枚举a的值，判断两个表达式的值是否相同。
  
  中缀表达式转换为后缀表达式方法：
    维护一个操作符栈和一个数组
    依次扫描中缀表达式，对每个扫描到的token：
      若token为数字或变量，直接放入数组末尾
      若token为操作符
        若token为左括号，则直接入操作符栈
        若token为右括号，则一直将操作符栈出栈到数组，直到将第一个左括号出栈（右括号永远不入栈）
        若token为其他操作符
          若栈顶操作符优先级大于等于token优先级，一直出栈到数组，直到栈顶操作符的优先级小于token的优先级，再将token入栈
          否则直接将token入栈
  注意：
    因为数据过大，所以每次运算取模，但要注意减法取模前要加上MOD，否则可能出现负数。（第7、第9个点）
    若题目中还有除法，则要使用逆元。（并不会。。。）
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

const int  A =100000000;
const int TAG=100000000+1;  //操作符的tag
const int LET=100000000+10; //'(' 
const int ADD=100000000+20; //'+'
const int SUB=100000000+21; //'-'
const int MUL=100000000+30; //'*'
const int POW=100000000+40; //'^'
const int RIT=100000000+50; //')'
  //使用大数作为操作符的tag，顺便可以方便地判断优先级
  //按优先级递增（<b>左括号LET为栈内优先级</b>）
vector<int> ori,test[26];
char temp[200];

void convert(char * str, vector<int> & v);
int cal(vector<int> & v, int a);
int token(char * str, int & pos);
int pri(int a, int b);
int pow_mod(int a, int n, int m);
void correct(char * str); //将括号不配对的输入更正

int main(void){
  fgets(temp,sizeof(temp),stdin); correct(temp); convert(temp,ori);
  fgets(temp,sizeof(temp),stdin); int n=atoi(temp);
  for(int i=0;i<n;i++){
    fgets(temp,sizeof(temp),stdin); correct(temp); convert(temp,test[i]);
  }
  for(int i=0;i<n;i++){
    bool flag=1;
    for(int a=10;a<=20;a++) if(cal(ori,a)!=cal(test[i],a)) {flag=0; break;}
    if(flag) printf("%c",'A'+i);
  }
  printf("\n");

  return 0;
}

void convert(char * str, vector<int> & v){
  stack<int> st;
  int len=strlen(str);
  int pos=0;
  while(pos<len){
    int t=token(str,pos);
    if(t==-1 || pos>=len) break;
    if(t<=A) v.push_back(t);
    else if(t==LET) st.push(t);
    else if(t==RIT){
      while(!st.empty() && st.top()!=LET) {v.push_back(st.top()); st.pop();}
      if(!st.empty()) st.pop();
    }else{
      while(!st.empty() && pri(st.top(),t)>=0) {v.push_back(st.top()); st.pop();}
      st.push(t);
    }
  }
  while(!st.empty()) {v.push_back(st.top()); st.pop();}
}
int cal(vector<int> & v, int a){
  stack<int> st;
  int siz=v.size();
  for(int i=0;i<siz;i++){
    if(v[i]<A) st.push(v[i]);
    else if(v[i]==A) st.push(a);
    else{
      int x2=st.top(); st.pop();  //注意顺序
      int x1=st.top(); st.pop();
      int ans;
      switch(v[i]){
        case ADD: ans=(1LL*x1+x2)%A; break;
        case SUB: ans=(1LL*x1-x2+A)%A; break; //<b>减法取模时加上MOD防止负数</b>
        case MUL: ans=(1LL*x1*x2)%A; break;
        case POW: ans=pow_mod(x1,x2,A); break;
      }
      st.push(ans);
    }
  }
  return st.top();
}
int token(char * str, int & pos){
  while(str[pos]==' ' || str[pos]=='\n' || str[pos]=='\r') pos++;
  if(!str[pos]) return -1;
  if(isdigit(str[pos])){
    int last=pos; char temp[10]; memset(temp,0,sizeof(temp));
    while(isdigit(str[pos])) {temp[pos-last]=str[pos]; pos++;}
    return atoi(temp);
  }else{
    int ans;
    switch(str[pos]){
      case 'a': ans= A ; break;
      case '(': ans=LET; break;
      case ')': ans=RIT; break;
      case '+': ans=ADD; break;
      case '-': ans=SUB; break;
      case '*': ans=MUL; break;
      case '^': ans=POW; break;
    }
    pos++; return ans;
  }
}
int pri(int a, int b){
  return (a-A)/10 - (b-A)/10;
}
int pow_mod(int a, int n, int m){
  if(n==0) return 1;
  else if(n==1) return a;
  int ans=pow_mod(a,n/2,m);
  ans=1LL*ans*ans%m;
  if(n&1) ans=1LL*ans*a%m;
  return ans;
}
void correct(char * str){
  int left=0,right=0; for(int i=0;temp[i];i++) if(temp[i]=='(') left++; else if(temp[i]==')') right++;
  if(left>right) for(int i=0;temp[i];i++) if(temp[i]=='(') {temp[i]=' '; break;}
  else if(left<right) for(int i=0;temp[i];i++) if(temp[i]==')') {temp[i]=' '; break;}
}
