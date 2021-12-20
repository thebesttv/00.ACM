/*
描述
一个最简单的计算器，支持+, -, *, / 四种运算。仅需考虑输入输出为整数的情况，数据和运算结果不会超过int表示的范围。

输入
输入只有一行，共有三个参数，其中第1、2个参数为整数，第3个参数为操作符（+,-,*,/）。

输出
输出只有一行，一个整数，为运算结果。然而：
1. 如果出现除数为0的情况，则输出：Divided by zero!
2. 如果出现无效的操作符(即不为 +, -, *, / 之一），则输出：Invalid operator!
*/

#include<iostream>
#include<cstdio>

int main(){
	int a,b;
	char k;

	scanf("%d %d %c",&a,&b,&k);	//"%d %d %c"中，%d与%c要有空格，否则输入时k为' '
	switch(k){
		case '+':
			printf("%d\n",a+b);
			break;
		case '-':
			printf("%d\n",a-b);
			break;
		case '*':
			printf("%d\n",a*b);
			break;
		case '/':
			if(b==0)	printf("Divided by zero!\n");
			else	printf("%d\n",a/b);
			break;
		default:
			printf("Invalid operator!\n");
	}

	return 0;
}
