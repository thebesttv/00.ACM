#include "Applications.h"
#include <cstddef>
#include <cstdarg>

#include "ArrayStack.h"
#include "ListLinkedStack.h"
#include "base.h"

#include <vector>
#include <stack>

//多项式计算1，返回结果
//a[]: 存放多项式的各项系数a[0]最高位，如4x4+6x3-2.3x2+0x+2x0    对应4 6 -2.3  0  2    n值为5
//len：数组长度   n:有效元素个数
//x：变量
//return:返回多项式计算结果
double  PolynomialFunc(double * a, int len, int n, double x)
{
  double sum = 0;
  if(a==NULL || n<=0) return 0.0;
  n = n<=len ? n : len;

  for(int i=0;i<n;++i){
    sum = sum*x + a[i];
  }

  return sum;
}

//多项式计算2，返回结果
//n: 多项式个数， 如n=4  最高位就是x的三次方
//x：最高位系数，后面可变参数，一次为多项式的各阶系数
//return:返回多项式计算结果
double  PolynomialFunc(int n, double x, ...)
{
  double sum = 0;
  va_list args;
  va_start(args,n);
  for(int i=0;i<n;++i){
    sum = sum*x + va_arg(args,double);
  }
  va_end(args);
  
  return sum;
}

// *********************************************************************************

//作业2：完成四则混合运算 ，含（）括号。
//输入str： 字符串  如： 1+2*3*(1+2)-4/(4/2)
//输出 double型计算结果
struct Token{
    int type;   // 0: number, 1: operator
    double v;
    Token(int type, double v):
        type(type), v(v) { }
};

double FourMixedOperations(const char *str) {
    std::vector<Token> token;
    int i = 0;
    while(str[i]){
        if(isdigit(str[i]) || str[i]=='.'){
            double v=0;
            while(isdigit(str[i])){
                v = v*10 + str[i]-'0';
                ++i;
            }
            if(str[i]=='.'){
                ++i; double t = 10;
                while(isdigit(str[i])){
                    v += (str[i]-'0')/t;
                    t*=10, ++i;
                }
            }
            token.push_back(Token(0,v));
        }else if(str[i]!=' '){
            token.push_back(Token(1,str[i]));
            ++i;
        }else{
            ++i;
        }
    }

    std::stack<double> nst;
    std::stack<char> ost;
    auto eval = [&nst,&ost](){
        double x1,x2,x;
        x2=nst.top(); nst.pop();
        x1=nst.top(); nst.pop();
        char op = ost.top(); ost.pop();
        switch(op){
        case '+': x = x1+x2; break;
        case '-': x = x1-x2; break;
        case '*': x = x1*x2; break;
        case '/': x = x1/x2; break;
        }
        nst.push(x);
    };

    for(Token p : token){
#ifdef DEBUG
        if(p.type==0) printf("  %lf\n",p.v);
        else printf("  %c\n",char(int(p.v)));
#endif
        if(p.type==0){
            nst.push(p.v);
        }else{
            char op=char(int(p.v));
            if(op=='(' || op=='*' || op=='/'){
                ost.push(op);
            }else if(op==')'){
                while(ost.top()!='(') eval();
                ost.pop();
            }else{  // +, -
                while(!ost.empty() && (ost.top()=='*' || ost.top()=='/'))
                    eval();
                ost.push(op);
            }
        }
    }
    while(!ost.empty()) eval();
    return nst.top();
}

char _decToHex[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

//作业2：完成进制转换 使用栈的结构。
//输入int  17
//输出 "0x11"
char * DecToHexByRecursion(int n)  //递归的方式
{
    char * s = new char[100], *p = s;
    if(n<0) *p++='-', n=-n;

    auto f = [&p](auto && self, int n){
        if(!n) return;
        self(self, n/16);
        *p++ = _decToHex[n%16];
    };
    f(f,n);
    *p++ = 0;

    return s;
}

char * DecToHexByStack1(int n)     //普通整除16 压栈的方式 线性数组栈
{
    char * s = new char[100], *p = s;
    if(n<0) *p++='-', n=-n;

    ArrayStack<char> st;
    while(n){
        st.push(_decToHex[n%16]);
        n/=16;
    }
    while(!st.empty()){
        *p++ = st.top();
        st.pop();
    }
    *p++ = 0;

    return s;
}

char * DecToHexByStack2(int n)     //移位操作 压栈 链栈
{
    char * s = new char[100], *p = s;
    if(n<0) *p++='-', n=-n;

    ListStack<char> st;
    while(n){
        st.push(_decToHex[n%16]);
        n>>=4;
    }
    while(!st.empty()){
        *p++ = st.top();
        st.pop();
    }
    *p++ = 0;

    return s;
}
