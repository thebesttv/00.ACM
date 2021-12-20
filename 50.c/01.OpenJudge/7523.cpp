/*
描述
读入三个整数，按每个整数占8个字符的宽度，右对齐输出它们。

输入
只有一行，包含三个整数，整数之间以一个空格分开。

输出
只有一行，按照格式要求依次输出三个整数，之间以一个空格分开。
*/

#include<iostream>
#include<cstdio>

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%8d %8d %8d\n",a,b,c);

	return 0;
}
