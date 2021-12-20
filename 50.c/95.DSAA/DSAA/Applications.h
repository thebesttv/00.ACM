#ifndef __APPLICATIONS_H__
#define __APPLICATIONS_H__

//多项式计算1，返回结果
//a[]: 存放多项式的各项系数a[0]最高位，如4x4+6x3-2.3x2+0x+2x0    对应4 6 -2.3  0  2    n值为5
//len：数组长度   n:有效元素个数
//x：变量
//return:返回多项式计算结果
double  PolynomialFunc(double * a, int len, int n, double x);

//多项式计算2，返回结果
//n: 多项式个数， 如n=4  最高位就是x的三次方
//x：最高位系数，后面可变参数，一次为多项式的各阶系数
//return:返回多项式计算结果
double  PolynomialFunc(int n, double x, ...);

//作业2: 完成四则混合运算 ，含（）括号。
//输入str: 字符串  如： 1+2*3*(1+2)-4/(4/2)
//输出 double型计算结果
double  FourMixedOperations(const char * str);

//作业2：完成进制转换 使用栈的结构。
//输入int 17
//输出 "0x11"
char * DecToHexByRecursion(int n);  //递归的方式
char * DecToHexByStack1(int n);     //普通整除16 压栈的方式 线性数组栈
char * DecToHexByStack2(int n);     //移位操作 压栈 链栈

#endif
