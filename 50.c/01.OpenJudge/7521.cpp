/*
描述
读入一个字符，一个整数，一个单精度浮点数，一个双精度浮点数，然后按顺序输出它们，并且要求在他们之间用一个空格分隔。输出浮点数时保留6位小数。

输入
共有四行：
第一行是一个字符；
第二行是一个整数；
第三行是一个单精度浮点数；
第四行是一个双精度浮点数。

输出
输出字符、整数、单精度浮点数和双精度浮点数，之间用空格分隔。
*/

#include<iostream>
#include<cstdio>

int main(){
	char a; int b; float c; double d;
	scanf("%c\n%d\n%f\n%lf",&a,&b,&c,&d);
	printf("%c %d %f %lf\n",a,b,c,d);

	return 0;
}
